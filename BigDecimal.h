# pragma once 
# include <iostream>
# include <regex>
# include<algorithm>
# include <cmath>
# include <vector>

using namespace std ;

class BigDecimalInt{
private :
    string decStr ;
   
    bool checkInput(string num) ;

public:
    int flag ;
    BigDecimalInt();
    BigDecimalInt(string num) ; 
    BigDecimalInt operator + (BigDecimalInt num2) ;
    bool operator > (BigDecimalInt num3) ;
    string getNum()
    {
        return decStr ;
    }
};
