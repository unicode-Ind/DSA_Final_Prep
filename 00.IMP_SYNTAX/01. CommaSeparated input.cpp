#include <iostream>
#include <sstream>
#include<vector>
#include<string>

#include <iomanip>
#include <cmath>
#include <limits>

typedef std::numeric_limits< double > dbl;

using namespace std;
int main() {
    
    string str;
    cin>>str;

    vector<string> v;
 
    stringstream ss(str);
 
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }

    cout.precision(dbl::max_digits10);
    long double sal = stold(v[2])+20;
    cout<<"Name :"<<v[0] <<endl;
    cout<<"Acc :"<<v[1]<<endl;
    cout<<sal<<endl;

    //or
    // cout<<"Sal :"
    //         << "default precision (6): " << sal << '\n'
    //           << "std::setprecision(10): " << std::setprecision(10) << sal << '\n'
    //           << "max precision:         "
    //           << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
    //           << sal << '\n';
    cout<<"Gender :"<<v[3]<<endl;

    // for (size_t i = 0; i < v.size(); i++)
    //     cout << v[i] << endl;
    // stoi, stof, stold =>long double
    cout<<"Hello World!";
}

/*
ip : xyz,amex007,0.876876,male

op:
xyz,amex007,0.876876,male
*/
