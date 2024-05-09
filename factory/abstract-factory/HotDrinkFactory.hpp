#pragma once
#include "HotDrink.hpp"

class HotDrinkFactory{
    public:

    virtual unique_ptr<HotDrink> make() = 0;
};

class TeaFactory: public HotDrinkFactory{
    public:
    unique_ptr<HotDrink> make(){
        return make_unique<Tea>();
    }
};

class CoffeeFactory: public HotDrinkFactory{
    public:
    unique_ptr<HotDrink> make(){
        return make_unique<Coffee>();
    }
};