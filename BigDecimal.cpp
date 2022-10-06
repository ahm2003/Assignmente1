# include <iostream>
# include <regex>
# include<algorithm>
# include <cmath>
# include <vector>
# include "BigDecimal.h"


BigDecimalInt :: BigDecimalInt(): decStr("0"){} ;

bool BigDecimalInt :: checkInput(string num)
{
    regex x ("(\\+|\\-)[0-9]*");
    if(regex_match(num,x))
    {
        return true ;
    }
    return false ;
}

BigDecimalInt :: BigDecimalInt(string num )
{
    if(checkInput(num))
    {
        decStr = num ;  
    }
    else{
        cout <<"Invalid num\n" ;
        cout << "program will Abort\n" ;
        exit(1) ;
        
    }
}

BigDecimalInt  BigDecimalInt :: operator + (BigDecimalInt num2)
{
    string  result = "";
    if(decStr> num2.decStr)
    {
        swap(decStr,num2.decStr) ;
    }
    int end =0 ; 

    if (decStr[0]=='-' && num2.decStr[0]=='-')
    {
        end = 1 ;
    }

    // if num is negative
    if (end == 1)
    {
        reverse(decStr.begin()+1, decStr.end()) ;
        reverse(num2.decStr.begin()+1, num2.decStr.end()) ;
    }
    
    // if num is positive
   else
   {
        reverse(decStr.begin(), decStr.end()) ;
        reverse(num2.decStr.begin(), num2.decStr.end()) ;
   }
    

    int carry = 0 , sum = 0 ;
    int l1 =decStr.length() , l2 = num2.decStr.length() ;

// adding smallest number with biggest one;
    for (int i = end ; i < l1 ; i ++)
    {
        sum = (decStr[i] -'0')+ (num2.decStr[i] -'0') + carry ;
        carry = sum / 10 ;
        result.push_back(sum % 10 +'0') ;
    }
// adding the remainder digit of biggest num ;
    for (int i = l1 ; i < l2 ; i ++)
    {
        sum = (num2.decStr[i]-'0') + carry ;
        carry = sum /10 ;
        result.push_back(sum % 10 + '0') ;
    }

    if (end == 1 ) {
        result +='-' ;
    }
    reverse(result.begin() , result.end()) ;
    decStr = result ;
    return BigDecimalInt(decStr) ;
}

string BigDecimalInt :: getNum()
{
    return decStr ;
}