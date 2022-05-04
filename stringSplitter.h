#ifndef STRINGSPLITTER_H_INCLUDED
#define STRINGSPLITTER_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;

int RegNametoint(string x){
    int temp;
    if(x[0]=='a') temp = 8;
    else if(x[0]=='x') temp = 0;
    else return -1;

    int f = x[1]-'0';

    return temp+f;

}

vector <string> getRegs(string s,int temp2){
    int i,temp1=0;
    for(i=temp2;s[i]==' ';i++){;}
    vector <string> v;
    temp2 = i;

    for(int j=temp2;j<s.size();j++){
        if(s[j]==','){
            string tempS = s.substr(temp2,temp1);
            v.push_back(tempS);
            //cout << tempS << endl;

            for(i=j+1;s[i]==' ';i++){;}

            temp2 = i;
            j = i-1;
            temp1 = 0;
        }
        else if(j==s.size()-1){
            string tempS = s.substr(temp2,temp1+1);
            v.push_back(tempS);
        }
        else temp1++;

       // cout << temp2 << " " << temp1 << endl;
    }
    return v;

}

tuple <string,int> strsplit(string s){
    int temp1 = 0,temp2,k;
    bool flag = false;

    for(int i=0;i<s.size();i++){
        if(s[i]=='#'){
            cout << "This is a comment line\n";
            return make_tuple("Comment Line",-1);
        }
        if(s[i]==' ' && flag==false){
            temp2 = i;
            flag = true;
            string tempS = s.substr(temp1,temp2);
            return make_tuple(tempS,temp2);
            //cout << "The Instruction is " << tempS  << endl;
            //cout  << "The Registers are ->\n";
            //getRegs(s,temp2);
        }



        if(i==s.size()-1 && flag==false){
            temp2 = i+1;
            string tempS = s.substr(temp1,temp2);
            return make_tuple(tempS,temp2);
            //cout << "The Instruction is " << tempS  << endl;
        }

    }

}

#endif // STRINGSPLITTER_H_INCLUDED
