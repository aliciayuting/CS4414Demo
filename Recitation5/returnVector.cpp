/**
 * @file functionExample.cpp
 * @author example Sagar provided
 * @version 0.1
 * @date 2021-09-24
 */
#include <iostream>
#include <string>
#include <vector>

class Student{
private:
    std::string name;
public: 
    Student(const std::string& name) : name(name){}
    std::string get_name() {
        return name;
    }
};

class CS4414{
private:
    std::vector<Student> students;
public:
    std::vector<Student>& get_students(){
        return students;
    }
};

int main(){
    CS4414 fa21;
    fa21.get_students().push_back(Student("Sagar"));
    fa21.get_students().push_back(Student("Alicia"));

    for (Student s: fa21.get_students()){
        std::cout << s.get_name() << std::endl;
    }
}