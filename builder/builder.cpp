#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

/*
By having a html element class and a builder, it looks so elegant
and clean to build html tags and elements
*/

struct HtmlElement {
    string tag, text;
    vector<HtmlElement> elements;
    const size_t indentation_size = 4;
    // HtmlElement(string &tag, string &text):tag(tag), text(text){}

    // A const function specifies that its just a read only function
    string str(size_t indentation = 0) const {
        ostringstream oss;
        string ind(indentation*indentation_size, ' ');
        oss << ind << "<" << tag << ">" <<endl;
        if(text.size() > 0) 
            oss << string((indentation+1)*indentation_size, ' ') << text << endl;
        
        for(auto &element: elements){
            oss << element.str(indentation + 1);
        }

        oss <<ind<< "</" << tag << ">" <<endl;
        return oss.str();
    }
};

struct HtmlBuilder {
    HtmlElement root;
    HtmlBuilder(string tag){
        root.tag  = tag;
    }
    void add_child(string tag, string text){
        root.elements.push_back({tag, text});
    }

    string str(){return root.str();}
};

int main(){
    HtmlBuilder builder("ul");
    builder.add_child("li", "hello");
    builder.add_child("li", "hi");
    cout<<builder.str()<<endl;

}