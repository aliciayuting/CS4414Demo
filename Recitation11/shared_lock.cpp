#include <unordered_map>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <string>
#include <iostream>

class PhoneBook
{
public:
     string getPhoneNo(const std::string &name)
     {
          shared_lock<shared_timed_mutex> r(_protect);
          auto it = _phonebook.find(name);
          if (it == _phonebook.end())
               return (*it).second;
          return "";
     }
     void addPhoneNo(const std::string &name, const std::string &phone)
     {
          unique_lock<shared_timed_mutex> w(_protect);
          _phonebook[name] = phone;
     }

     shared_timed_mutex _protect;
     unordered_map<string, string> _phonebook;
};

int main()
{
     PhoneBook pb();
     std::thread t0(&PhoneBook::addPhoneNo, &pb, "alicia", "12345");
     std::thread t1(&PhoneBook::getPhoneNo, &pb, "alicia");
     std::thread t2(&PhoneBook::getPhoneNo, &pb, "sagar");
     t0.join();
     t1.join();
     t2.join();
     return 0;
}