#include <iostream>
#include <map>
#include <thread>

std::map<int, int> global_map;

void read_map(){
     for (int i = 0; i < 1000000; ++i){
          if(global_map.find(i) == global_map.end()) continue;
          int val = global_map.at(i);
          if(val != i){
               std::cout << "Wrong pair: (" << i << "," << val << ")" << std::endl;
          }
     }
}

void erase_map(){
     for (int i = 20000; i < 80000; ++i){
          global_map.erase(i);
     }
}

int main(){
     for (int i = 0; i < 1000000; ++i){
          global_map[i] = i;
     }
     std::thread read_map_thread(read_map);
     std::thread erase_map_thread(erase_map);

     read_map_thread.join();
     erase_map_thread.join();
     return 0;
}