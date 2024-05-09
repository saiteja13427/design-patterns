#pragma once
#include<unordered_map>
#include "HotDrinkFactory.hpp"
using namespace std;

struct DrinkFactory {
    private:
    unordered_map<string, unique_ptr<HotDrinkFactory>> hot_factories;
    
    public:
    DrinkFactory(){
        hot_factories["tea"] = make_unique<TeaFactory>();
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
    }  

    void make(const string &drink){
        hot_factories[drink]->make()->prepare();
    }
};