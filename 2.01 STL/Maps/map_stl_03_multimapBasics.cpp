#include <iostream>
#include<map>
#include<cstring>
using namespace std;

/*
    map : unique keys
    multi-map : same keys allowed

    complexity is logarithmic for methods as keys are in sorted order (self balancing BST structure)
*/

int main() {
    multimap<char,string> m;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        char ch;
        string s;
        cin>>ch>>s;
        m.insert(make_pair(ch,s));
    }

    /*
        input:
        7
        b batman
        a apple
        b boat
        c cat
        d dog
        d donut
        e egg
    */

    auto it = m.begin();
    m.erase(it); // will delete apple as it appers at begin()

    auto it2 = m.lower_bound('b'); //batman
    auto it3 = m.upper_bound('d'); //egg
    for(auto it4=it2;it4!=it3;it4++){
        cout<<it4->second<<" ,"<<endl;
    }


    //search for cat 
    auto f = m.find('c');

    //if there are multiple values mapped with 'c', we can iterate over them
    if(f->second=="cat"){
        m.erase(f);
    }
    
    //Try to print the entire map
    for(auto p:m){
        cout<<p.first<<" -> "<<p.second<<endl;
    }

}
