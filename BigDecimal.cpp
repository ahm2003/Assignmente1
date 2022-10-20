# include "BigDecimal.h"
using namespace std ;
    BigDecimalInt BigDecimalInt :: operator = (BigDecimalInt num3){
        decStr=num3.decStr;
        return decStr;
    }

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
int BigDecimalInt :: sign(){
    if (decStr[0]!='-')
        return '+';
    else 
        return '-';
}
int BigDecimalInt :: size(){
    len= decStr.size();
    return len;
}
BigDecimalInt :: BigDecimalInt(): decStr("0"){} ;

//BigDecimalInt :: BigDecimalInt(): decStr("0"){} 

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
   
 
BigDecimalInt BigDecimalInt :: operator + (BigDecimalInt num2)
{
    string  result = "";
    if(decStr.size()> num2.decStr.size())
    {
        swap(decStr,num2.decStr) ;
    }
    int end =0 ; 

    if ((decStr[0]=='-' && num2.decStr[0]=='-')||(decStr[0] == '+' && num2.decStr[0] =='+'))
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

    if (end == 1 && decStr[0]=='-') {
        result +='-' ;
    }
    else
    {
        result += '+' ;
    }
    reverse(result.begin() , result.end()) ;
    decStr = result ;
    return BigDecimalInt(decStr) ;
}


string BigDecimalInt :: getNum()
{
    return decStr ;
}
bool BigDecimalInt::operator == (BigDecimalInt num3)
{
    int temp1 ,temp2;
    temp1= decStr.size();
    temp2= num3.decStr.size();
    if (temp1== temp2 && decStr[0]==num3.decStr[0] ){
        for(int i = 0 ; i<=temp1 ; i++){
            if(decStr[i]==num3.decStr[i]){
                continue;
                flag = 1;
            }
        else{ 
            flag = 0 ;
        }
        }
    }
    else{
        flag = 0 ;
}
    return flag;
}
int main()
{ 
    BigDecimalInt b("-999999999999999999999999998999999999999999999999999999999999999999999999999") ;
    cout<<b;

/*    cout<<b1.sign();
    /*BigDecimalInt b1("+999999999999999999999999998999999999999999999999999999999999999999999999999") ;
    cout<<b1.size();
    
    BigDecimalInt b1("+999999999999999999999999998999999999999999999999999999999999999999999999999") ,b2("+99999999999999999999999999999999999999999999999999999999999999999999999999");
    if (b1 > b2)
        cout<<"1";
    else
        cout<<"0";
        
    BigDecimalInt b1("+999999999999999999999999998999999999999999999999999999999999999999999999999") ,b2("+99999999999999999999999999999999999999999999999999999999999999999999999999");
    if (b1 == b2)
        cout<<"1";
    else
        cout<<"0";
        
    BigDecimalInt b1("+99999999999999999999999999999999999999999999999999999999999999999999999999") ,b2("+99999999999999");
    b1 = b2 ;
    cout<<b1.getNum();*/
return 0;
}

