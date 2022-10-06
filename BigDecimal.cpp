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
