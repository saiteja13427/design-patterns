#pragma once
#include<iostream>
#include<memory>
using namespace std;

// const means that function is a readonly function and doesn't write anything
class HotDrink {
    public:
    
    virtual void prepare() const = 0;
};

class Tea: public HotDrink {
    public:
    void prepare () const {
        cout<<"Creating Tea out of magic"<<endl;
    }
};

class Coffee: public HotDrink {
    public:
    
    void prepare () const {
        cout<<"Creating Coffee out of magic"<<endl;
    }
};