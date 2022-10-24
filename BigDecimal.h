# pragma once
#include <bits/stdc++.h>
using namespace std ;

class BigDecimalInt{
private :
    string decStr ;
    int flag ;
    int len;
    bool checkInput(string num) ;
public:
    string getNum();
    BigDecimalInt();
    BigDecimalInt(string num) ;
    BigDecimalInt(int num) ;
    BigDecimalInt operator + (BigDecimalInt num2) ;
    BigDecimalInt operator - (BigDecimalInt num2) ;
    bool operator > (BigDecimalInt num3) ;
    bool operator == (BigDecimalInt num3) ;
    BigDecimalInt operator = (BigDecimalInt num3) ;
    int size();
    int sign();
    friend ostream &operator <<(ostream &out , BigDecimalInt b);
    };
    ostream &operator <<(ostream &out , BigDecimalInt b){
    out<<b.decStr;
    return out;
    }

