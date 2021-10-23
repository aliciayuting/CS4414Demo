#include <iostream>
#include <vector>
#include <string>
#include <random>

class Entity{
public:
    std::string name;
    uint64_t value;
    
    Entity(std::string name, uint64_t value)
        :   name(name), 
            value(value){
    }

    // operator to compare entity
    bool operator<(const Entity& other) const{
        return other.value < value;
    }

    uint64_t get_value(){
        return value;
    }

    std::string to_string(){
        return  "Entity: name=" + name + ", value=" + std::to_string(value);
    }
};

Entity find_largest(std::vector<Entity> entities) {
    int i;
    int max = 0;
    for (i = 1; i < entities.size(); i++)
        if (entities[i].get_value() > entities[max].get_value()) 
            max = i;
    return entities[max]; 
}

int main(){
    /* Initialise the random number generator*/
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis;


    std::vector<Entity> testEntities;
    for(int i=0; i<100; ++i){
        
        uint64_t cur_value = dis(gen);
        Entity cur_entity(std::to_string(cur_value), cur_value);
        testEntities.push_back(cur_entity);

        Entity largest_sofar = find_largest(testEntities);
        // std::cout << largest_sofar.to_string() << std::endl;
        //  .....   further oprations
    }
    
    return 0;
}