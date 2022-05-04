#ifndef REGISTER_H
#define REGISTER_H

#include<bits/stdc++.h>
using namespace std;


class Register
{
private:
    string name;
    string value;
    public:
        Register();
        void storeInitial(int i);
        void setVal(string s);
        friend int adder(Register a,Register b);
        friend int adderi(Register a,int b);
        friend int subtracteri(Register a,int b);
        friend int subtracter(Register a,Register b);
        void showVal();
        virtual ~Register();

    protected:

    private:
};

#endif // REGISTER_H
