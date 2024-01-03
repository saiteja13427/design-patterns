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

class HtmlElement {
    // By making the constructors private and htmlbuilder a friend class
    // We are forcing users to use builders only to create htmlelements and not
    // direct constructors.
    friend class HtmlBuilder;
    string tag, text;
    vector<HtmlElement> elements;
    const size_t indentation_size = 4;
    HtmlElement(){}
    HtmlElement(string &tag, string &text):tag(tag), text(text){}
public:
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

class HtmlBuilder {
    HtmlElement root;
public:
    HtmlBuilder(string tag){
        root.tag  = tag;
    }

    /* By returning HtmlBuilder we are allowing chaining */
    HtmlBuilder& add_child(string tag, string text = ""){
        root.elements.push_back({tag, text});
        return *this;
    }

    string str(){return root.str();}
    static HtmlBuilder create(string root){return {root};}
    HtmlElement& build(){ return root; }
};

int main(){
    HtmlBuilder builder("ul");
    builder.add_child("li", "hello");
    builder.add_child("li", "hi");

    /* 
    By making a few more changes in classes like adding builder method and
    by returning htmlBuilder on add child we can have a **fluent builder** 
    which allows chaining and all like below.
    */

    /*
    Fluent builder pattern is a style of coding which force the developer to create the object 
    in sequence by calling each setter method one after the another until all required attributes are set.
    */

    /*
    Note: We can also return pointers and build a chain of calls instead like this but as we have
    references here, this is much cleaner.
    */
   
    string html = HtmlBuilder::create("body").add_child("p", "Hi").add_child("p", "Hello").build().str();
    cout<< html <<endl;
    cout<<builder.str()<<endl;

}