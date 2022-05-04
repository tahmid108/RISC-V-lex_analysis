#include "Register.h"
constexpr int CHAR_LEN = 1;

Register::Register()
{
    this->name = "";
    this->value = "";
}

void Register::setVal(string s){
    this->value = s;
}

void Register::storeInitial(int i){
    if(i<=7){
        char c = i + '0';
        string str_temp(CHAR_LEN,c);
        string temp = "x" + str_temp;
        this->name = temp; // register naming done for x registers

        int val;
        if(i==0) val = 0;
        else{
            val = rand()%64;
        }
        this->value = to_string(val);

    }
    else{
        char c = (i%8) + '0';
        string str_temp(CHAR_LEN,c);
        string temp = "a" + str_temp;
        this->name = temp; // register naming done for a registers

        int val;
        val = rand()%64;
        this->value = to_string(val); // register random value set
    }
}

void Register::showVal(){
    cout << "Register Name :" << this->name << " Register Value : " << this->value << endl;
}

int adder(Register a,Register b){
    int x = stoi(a.value);
    int y = stoi(b.value);

    return x+y;
}

int adderi(Register a,int b){
    int x = stoi(a.value);

    return x+b;
}

int subtracteri(Register a,int b){
    int x = stoi(a.value);

    return x-b;
}

int subtracter(Register a,Register b){
    int x = stoi(a.value);
    int y = stoi(b.value);

    return x-y;
}

Register::~Register()
{

}
