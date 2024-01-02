#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

/*
Without builder pattern, we build the html tags
by concatenating wherein we can miss a lot of html
structuring and all.

So, its better to have builder pattern which will internally
take care of html and we won't miss anything
*/

int main(){
    string text = "Hello", output;
    output =  "<p>";
    output += text;
    output += "</p>";

    cout<<output<<endl;

    string texts[2] = {"Hi", "Bye"};
    ostringstream oss;
    oss << "<ul>" <<endl;
    for(auto & t: texts)
        oss << "    <li>" << t << "</li>"<<endl;
    oss<<"</ul>"<<endl;

    cout<<oss.str()<<endl;
}