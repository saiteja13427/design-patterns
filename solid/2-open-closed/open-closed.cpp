#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

//By writing a specification and filter class, we can extend the number of specifications and use the filter class to filter with multiple conditions.
// This way we can extend by writing new specifications but we don't need to modify the existing logic which would have been tested!


// Uses specification pattern which is an enterprise pattern

enum class Color {green, red, orange}; //Access like Color::green
enum class Size {small, medium, large};

struct Product {
    string name;
    Color color;
    Size size;
    Product(string name, Color color, Size size): 
        name(name), color(color), size(size){}
};

template <typename T> 
struct Specification {
    // Pure virtual function, atleast one of it makes the class abstract!
    virtual bool is_satisfied (T* item) = 0;
};

template <typename T>
struct AndSpecification : Specification<T> {
    Specification<T> &s1, &s2;
    AndSpecification(Specification<T> &s1, Specification<T> &s2): s1(s1), s2(s2) {}

    bool is_satisfied(T* item) override {
        return s1.is_satisfied(item) && s2.is_satisfied(item);
    }
};

template <typename T>
struct Filter {
    virtual vector<T*> filter(vector<T*> t, Specification<T> &s) = 0;
};

struct ColorSpecification: Specification<Product> {
    Color color;
    ColorSpecification(Color color): color(color) {}
    bool is_satisfied(Product * product) override{
        return product->color == color;
    }
};

struct SizeSpecification: Specification<Product> {
    Size size;
    SizeSpecification(Size size): size(size) {}
    bool is_satisfied(Product * product) override {
        return product->size == size;
    }
};


struct BetterFilter: Filter<Product> {
    vector<Product*> filter(vector<Product*> products, Specification<Product> &s) override {
        vector<Product*> res;
        for(auto &product: products){
            if(s.is_satisfied(product)) res.push_back(product);
        }
        return res;
    }

};

int main(){
     Product shirt{"Shirt", Color::green, Size::small};
     Product top{"Top", Color::red, Size::medium};
     Product hat{"Hat", Color::green, Size::small};
    vector<Product*> products = {&shirt, &top, &hat};

    ColorSpecification green(Color::green);
    SizeSpecification small(Size::small);
    AndSpecification<Product> spec(green, small);
    BetterFilter filter;
    for(auto& product: filter.filter(products, spec)) cout<<product->name<<endl;
}