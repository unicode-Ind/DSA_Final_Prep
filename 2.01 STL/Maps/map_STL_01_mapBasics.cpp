#include <iostream>
#include<map>
#include<string>
using namespace std;

//maps are ordered containers - ordered lexiographically (appera in sorted order)
// implemented by seft- balancing BST's

int main() {
  
    map<string,int> m;

    //1. Insert (3 ways)
    m.insert(make_pair("Mango",100));

    pair<string,int> p;
    p.first = "Apple";
    p.second = 120;

    m.insert(p);

    m["Banana"] = 20;

    //2. Search
    string fruit;
    cin>>fruit;

    //update the price
    m[fruit] += 22;

    auto it = m.find(fruit);
    // or 
    //map<string,int> :: iterator it=m.find(fruit);

    if(it!=m.end()){
        cout<<"price of "<<fruit<<" is"<<m[fruit]<<endl;
    }
    else{
        cout<<"fruit is not present "<<endl;
    }

    


    //3. Erase
    m.erase(fruit);


    //another way to find a particular map
    // it stores unique keys only once
    if(m.count(fruit)){ //count returns integer
        cout<<"Price is "<<m[fruit]<<endl;
    }
    else{
        cout<<"Couldnt find "<<endl;
    }

    m["Litchi"] = 60;
    m["Pineapple"] = 80;

    //Iterate over all the key value pairs
    for(auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<" and "<<it->second<<endl;
        // or (*it).first and (*it).first
    }

    //for each loop 
    for(auto p:m){
        cout<<p.first<<" : "<<p.second<<endl;
    }

    return 0;
}