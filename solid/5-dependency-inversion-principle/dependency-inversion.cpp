#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

// Says that we need to depend on abstraction and not on low level modules/classes directlyt.

// Implementing the relationshipBrowser and passing that to research here is an example to dependency inversion principle.
// Low level and high level things both depend on abstraction and not on each other.

enum class Relation {parent, child};

struct Person {
    string name;
    Person(string name): name(name){}
};

struct RelationshipBrowser{
    virtual vector<Person> find_children_of(const string &parent) = 0;
};

struct Relationship: RelationshipBrowser { // Low Level
    vector<tuple<Person, Relation, Person>> relations;
    void add_parent_and_child(Person parent, Person child){
        relations.push_back({parent, Relation::parent, child});
        relations.push_back({child, Relation::child, parent});
    }

    vector<Person> find_children_of(const string &parent) override {
        vector<Person> res;
        for(auto [p1, r, p2]: relations){
            if(p1.name == parent and r == Relation::parent){
                res.push_back(p2);
            }
        }
        return res;
    }

};

struct ResearchRelations { // High level
    // Observe we are not directly passing a Relationship, instead we are passing an abstract class
    // RelationshipBrowser so that if there is any change in Relationship, we need not change ResearchRelations.

    // Also we implement Relationship browser methods in Relationship so that all the relationship processing
    //happens in relationship only -> Single responsibility principle
    ResearchRelations(RelationshipBrowser& rb){
        for(auto& child: rb.find_children_of("John")){
            cout<<"Johns child is : "<< child.name<<endl;
        }
    }
     
};

int main(){
    Person parent("John");
    Person child("Kathy");
    Person child2("Mary");

    Relationship rel;
    rel.add_parent_and_child(parent, child);
    rel.add_parent_and_child(parent, child2);

    ResearchRelations rr(rel);
}