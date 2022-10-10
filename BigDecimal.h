//# pragma once 
# include <iostream>
# include <regex>
# include<algorithm>
# include <cmath>
# include<string>
# include<cstring>
# include <vector>

using namespace std ;

class BigDecimalInt{
private :
    string decStr ;
    
   
    bool checkInput(string num) ;
public:
    int flag ;
    int size();
    int sign();
    int length;
    BigDecimalInt();
    BigDecimalInt(string num) ; 
    BigDecimalInt(int num) ;
    BigDecimalInt operator + (BigDecimalInt num2) ;
    BigDecimalInt operator = (BigDecimalInt num3) ;
    bool operator > (BigDecimalInt num3) ;
<<<<<<< Updated upstream
    bool operator == (BigDecimalInt num3) ;
    string getNum();
    
=======
    string getNum() ; 
>>>>>>> Stashed changes
};
