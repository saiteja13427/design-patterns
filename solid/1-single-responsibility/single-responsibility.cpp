#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

/*Single responsibility by spearating journal and persistenceManager*/

class Journal {
    public:
        string name;
        vector<string> entries;
        int count = 1;

        Journal(const string &name): name(name){}

        int add_entry(string entry){
            entries.push_back(lexical_cast<string>(count++) + ": " + entry);
            return 0;
        }
};

/* We could have put a save method in Journal itself but then that would be against
single responsibility. Adding a PersistenceManager we have separated concers and now we 
can use pm anywhere.
*/
class PersistenceManager {
    public:
        int save(const Journal j, const string &filename){
            ofstream ofs(filename);
            ofs<< j.name<< endl;
            for(auto entry :j.entries){
                ofs << entry<< endl;
            }
            return 0;
        }
}; 

int main(){
    Journal j("My Journel");
    j.add_entry("Today I learnt about single resposibility principle");

    PersistenceManager pm;
    pm.save(j, "saved.txt");

            return 0;

}