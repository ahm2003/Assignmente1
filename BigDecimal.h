//# pragma once 
# include <iostream>
# include <regex>
# include<algorithm>
# include <cmath>
# include<string>
# include<cstring>
# include <vector>
# include <fstream>
#include <bits/stdc++.h>
using namespace std ;

class BigDecimalInt{
private :
    string decStr ;
    bool checkInput(string num) ;
public:
    int flag ;
    int size();
    int sign();
    int len;
    BigDecimalInt();
    BigDecimalInt(string num) ; 
    BigDecimalInt(int num) ;
    BigDecimalInt operator + (BigDecimalInt num2) ;
    BigDecimalInt operator = (BigDecimalInt num3) ;
    bool operator > (BigDecimalInt num3) ;
    bool operator == (BigDecimalInt num3) ;
    string getNum();
    friend ostream &operator <<(ostream &out , BigDecimalInt b);
    };
    ostream &operator <<(ostream &out , BigDecimalInt b){
    out<<b.decStr;
    return out;
    }

