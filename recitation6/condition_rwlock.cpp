/** Reader/writer lock implementation 2
 *  Writer prioritized RW lock
 *  better implementation than version1, since it prevents writer starvation
*/

#include <atomic>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <vector>


class write_priority_lock{
     std::mutex m_mutex;
     std::condition_variable m_write_cv;
     std::condition_variable m_read_cv;
     int m_read_count;
     int m_write_count;

public:
     void read_lock(){
          std::unique_lock<std::mutex> lock(m_mutex);
          m_read_cv.wait(lock, [this](){ return this->m_write_count == 0; });
          m_read_count ++;
     }

     void write_lock(){
          std::unique_lock<std::mutex> lock(m_mutex);
          m_write_count ++;
          m_write_cv.wait(lock, [this](){return this->m_write_count <=1 && this->m_read_count == 0;});
     }

     void read_unlock(){
          std::unique_lock<std::mutex> lock(m_mutex);
          m_read_count --;
          if(m_read_count == 0 && m_write_count > 0){
               m_write_cv.notify_one();
          }
     }

     void write_unlock(){
          std::unique_lock<std::mutex> lock(m_mutex);
          m_write_count --;
          if(m_write_count >= 1){
               m_write_cv.notify_one();
          }else{
               m_read_cv.notify_all();
          }
     }
};


std::vector<int> global_vect{ 10, 20, 30 };
write_priority_lock global_wp_lock;


/** Reader function
  * @param v: external vector to read to
  */
void read_vector(std::vector<int>& v){
     global_wp_lock.read_lock();
     // Simulate some latency
     std::this_thread::sleep_for(std::chrono::seconds(1));     
     for(int i = 0; i < global_vect.size(); ++i){
          v[i] = global_vect[i];
     }
     global_wp_lock.read_unlock();
}

/** Writer function
  * Want the the write behaviour to be atomic, such that external observers to observe 
  *   either the whole global_vect as changed to new_val,
  *   or no element in global_vect is changed.
  * @param new_val: new value to write to the entire global_vect
  */
void write_vector(int new_val){
     global_wp_lock.write_lock();
     for(size_t i = 0; i < global_vect.size(); ++i){
          global_vect[i] = new_val;
          std::this_thread::sleep_for(std::chrono::seconds(1)); 
     }
     global_wp_lock.write_unlock();
}

void print_vector(const std::vector<int>& vect){
     std::cout << "[";
     for(const int& val: vect){
          std::cout << val << ",";
     }
     std::cout << "]" << std::endl;
}

int main(){
     std::vector<int> read_vect0(3);
     std::vector<int> read_vect1(3);
     std::vector<int> read_vect2(3);

     std::thread t0(read_vector, std::ref(read_vect0));
     std::thread t3(write_vector, 0);
     std::thread t1(read_vector, std::ref(read_vect1));
     std::thread t2(read_vector, std::ref(read_vect2));
     
     t0.join();
     t1.join();
     t2.join();
     t3.join();

     std::cout << "read_vect0:";
     print_vector(read_vect0);
     std::cout << "read_vect1:";
     print_vector(read_vect1);
     std::cout << "read_vect2:";
     print_vector(read_vect2);
     std::cout << "global_vect:";
     print_vector(global_vect);
}