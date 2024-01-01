#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

/*
Declaring a interface like below will be problematic as if someone wants to implement a printer
and if he inherits from IMachine, then he/she will have to have scan and fac unnecessarily
*/
// struct IMachine {
//     virtual void print() = 0;
//     virtual void scan() = 0;
//     virtual void fax() = 0;
// }

/*
Declaring the interfaces like this makes sense because then someone can implement
printer, scanner and fax individually without having unncessary APIs and they can also have a 
machine which can do all of it using IMachine interface which is created by combining all three
*/

struct IPrinter {
    virtual void print() = 0;
};

struct IScanner {
    virtual void scan() = 0;
};

struct IFax {
    virtual void fax() = 0;
};

struct IMachine: IPrinter, IScanner, IFax {};

int main(){

}