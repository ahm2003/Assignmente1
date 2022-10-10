//# pragma once 
# include <iostream>
# include <fstream>
# include <regex>
# include<algorithm>
# include <cmath>
# include <vector>
using namespace std ;

class BigDecimalInt{
private :
    ostream out;
    string decStr ;
    bool checkInput(string num) ;
public:
    
    void add_new_text(BigDecimalInt b);
    friend ostream& operator << ( ostream& out , BigDecimalInt b);
    int flag ;
    int size();
    int sign();
    int length;
    BigDecimalInt();
    BigDecimalInt(string num) ; 
    BigDecimalInt operator + (BigDecimalInt num2) ;
    BigDecimalInt operator = (BigDecimalInt num3) ;
    bool operator > (BigDecimalInt num3) ;
    bool operator == (BigDecimalInt num3) ;
    string getNum();
    
};
