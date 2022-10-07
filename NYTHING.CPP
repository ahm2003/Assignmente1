# include "BigDecimal.h"

#include <bits/stdc++.h>
using namespace std;
bool operator>(){
        string dec , anotherdec;
    int temp1 ,temp2, temp3 ,temp4,temp5; 
    cout<<"enter num : "<<endl;
    cin>>dec;
    cout<<"enter num : "<<endl;
    cin>>anotherdec;
    temp1= dec.size();
    temp2= anotherdec.size();
    //cout<<temp1<<" "<<temp2;
    if (temp1==temp2 ){
        for (int i =0 ; i<=temp1-1;i++)
        {
        stringstream s1 , s2;
        s1<<dec[i];
        s1>>temp3;
        s2<<anotherdec[i];
        s2>>temp4;
        if(temp3>temp4){
            cout<<"dec bigger";
        }
        else if (temp4>temp3){
            cout<<"anotherdec is bigger";
            break;
        }
        /*else{
            cout<<"=";
            break;
            
        }*/
    }
    }

}
int main()
{
return 0;
}
