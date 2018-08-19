//
// Created by root on 18-8-19.
//

#include "CommandArgs.h"
#include <istream>
#include <cstdlib>
#include <cstring>
using namespace std;
namespace lmars{
    istream& operator >> (istream & is,vector<int> & v);
    ostream& operator <<(ostream& os,vector<int> & v);
    istream& operator >>(istream& is,vector<double> & v);
    ostream& operator <<(ostream& os,vector<double>& v);
    std::ios_base::iostate
    istream& operator >> (istream & is,vector<int> & v){
        string s;
        if(!(istream>>s)){
            return istream;
        }
        const char* c=s.c_str();
        char* caux= const_cast<char*>(c);
        v.clear();
        bool hasNextValue=true;
        while(hasNextValue){
            int i= static_cast<int>(strtol(c,&caux,10));
            if(c!=caux){
                c=caux;
                c++;
                v.push(i);
            }else{
                hasNextValue= false;
            }
        }

    }
    ostream& <<(ostream& os,vector<int>& v){
        if(v.size()){
            os<<v[0];
        }
        for(size_t i=1;i<v.size();i++){
            os<<","<<v[i];
        }
        return os;
    }

    template <typename T>
    bool convertString(const string& s,T& v){
        istringstream is(s);
        if(!(is>>v)){
            return true;
        }
        return false;
    }

}
