#include<bits/stdc++.h>
using namespace std;

#include "stringSplitter.h"
#include "Register.h"

int main()
{
    string s; // start
    string tempS;
    int temp2;
    freopen("input.txt","r",stdin);
    Register r[16];
    for(int i=0;i<16;i++){
        r[i].storeInitial(i); // store initial naming and value of Registers
    }
    cout << "INITIAL REGISTER STATE\n";
    for(int i=0;i<16;i++){
        r[i].showVal(); // initial Value
    }
    while(getline(cin,s)){
        tie(tempS,temp2) = strsplit(s);
        cout << "The Instruction is " << tempS << endl;
        //cout << "The Registers are -> \n";
        if(tempS=="add" || tempS=="addi" || tempS=="sub" || tempS=="subi" || tempS=="la" || tempS=="li"){
            vector <string> v = getRegs(s,temp2);
            if(tempS=="add"){
                int v0 = RegNametoint(v[0]);
                int v1 = RegNametoint(v[1]);
                int v2 = RegNametoint(v[2]);

                if(v0==-1 || v1==-1 || v2==-1) {cout << "Register Naming Error\n"; continue;}

                int regAddedRes = adder(r[v1],r[v2]);
                r[v0].setVal(to_string(regAddedRes));

                r[v0].showVal();
            }
            else if(tempS=="sub"){
                int v0 = RegNametoint(v[0]);
                int v1 = RegNametoint(v[1]);
                int v2 = RegNametoint(v[2]);

                if(v0==-1 || v1==-1 || v2==-1) {cout << "Register Naming Error\n"; continue;}

                int regAddedRes = subtracter(r[v1],r[v2]);
                r[v0].setVal(to_string(regAddedRes));

                r[v0].showVal();
            }
            else if(tempS=="addi"){
                int v0 = RegNametoint(v[0]);
                int v1 = RegNametoint(v[1]);
                int v2 = stoi(v[2]);

                if(v0==-1 || v1==-1) {cout << "Register Naming Error\n"; continue;}

                int regAddedRes = adderi(r[v1],v2);
                r[v0].setVal(to_string(regAddedRes));

                r[v0].showVal();
            }
            else if(tempS=="subi"){
                int v0 = RegNametoint(v[0]);
                int v1 = RegNametoint(v[1]);
                int v2 = stoi(v[2]);

                if(v0==-1 || v1==-1) {cout << "Register Naming Error\n"; continue;}

                int regAddedRes = subtracteri(r[v1],v2);
                r[v0].setVal(to_string(regAddedRes));

                r[v0].showVal();
            }
            else if(tempS=="la"){
                int v0 = RegNametoint(v[0]);

                r[v0].setVal(v[1]);
                r[v0].showVal();
            }
            else if(tempS=="li"){
                int v0 = RegNametoint(v[0]);

                r[v0].setVal(v[1]);
                r[v0].showVal();
            }
        }
        else if(tempS=="ecall"){
            for(int i=0;i<16;i++){
                r[i].showVal(); // Value after operation
            }
        }
        else cout << "Invalid Instrunction\n";
    }

    return 0;
}
