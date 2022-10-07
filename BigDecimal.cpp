# include <iostream>
# include <regex>
# include<algorithm>
# include <cmath>
# include <vector>
# include "BigDecimal.h"

bool BigDecimalInt::operator > (BigDecimalInt num3 )
{
    int temp1 ,temp2, temp3 ,temp4,temp5;
    temp1= decStr.size();
    temp2= num3.decStr.size();
    if (decStr[0]=='+'&&num3.decStr[0]=='-'){
        flag=1;    
    }
    else if (decStr[0]=='-'&&num3.decStr[0]=='+'){
        flag=0;
    }
    else if (decStr[0]=='+'&&num3.decStr[0]=='+'&& temp1>temp2){
        flag=1;
    }
    else if (decStr[0]=='+'&&num3.decStr[0]=='+'&& temp1<temp2){
        flag=0;
        
    }    
    else if (decStr[0]=='-'&&num3.decStr[0]=='-'&& temp1>temp2){
        flag=0;
    }
    else if (decStr[0]=='-'&&num3.decStr[0]=='-'&& temp1<temp2){
        flag=1;
    }
    else if (decStr[0]=='-'&&num3.decStr[0]=='+'){
        flag=0;
    }
    else if (temp1 ==temp2 && decStr[0]=='+'&&num3.decStr[0]=='+'){
        for (int i =0 ; i<=temp1-1;i++)
        {
        stringstream s1 , s2;
        s1<<decStr[i];
        s1>>temp3;
        s2<<num3.decStr[i];
        s2>>temp4;
        if(temp3>temp4){
            temp5=temp3;
            break;
        }
        else if (temp4>temp3){
            temp5=temp4;
            break;
        }
        }    
    if (temp5==temp3)
        return true;    
    else if (temp5==temp4)
        flag=0;    
       }
    else if (temp1 ==temp2 && decStr[0]=='-'&&num3.decStr[0]=='-'){
        for (int i = 1  ; i<=temp1-1;i++)
        {
        stringstream s1 , s2;
        s1<<decStr[i];
        s1>>temp3;
        s2<<num3.decStr[i];
        s2>>temp4;
        if(temp3>temp4){
            temp5=temp3;
            break;
        }
        else if (temp4>temp3){
            temp5=temp4;
            break;
            
        }
        }    
    if (temp5==temp3)
        flag=0;
    else if (temp5==temp4)
        flag=1;

        
    }
    if(flag==1){
        return true;
    }
    return false ;
}

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
    if(checkInput(num))//3
    {
        decStr = num ;  
    }
    else{
        cout <<"Invalid num\n" ;
        cout << "program will Abort\n" ;
        exit(1) ;
        
    }
}
int main()
{
    BigDecimalInt b1("+99999999999999999999999999999999999999999999999999999999999999999999999999") ,b2("+99999988888888888888888888888888888899999999999999999999999");
    if (b1 > b2)
        cout<<"1";
    else
        cout<<"0";
return 0;
}