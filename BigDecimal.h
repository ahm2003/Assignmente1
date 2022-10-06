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
    BigDecimalInt() ;
    BigDecimalInt(string num) ; 

};