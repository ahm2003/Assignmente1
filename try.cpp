# include <bits/stdc++.h>
using namespace std ;
int main()
{
    vector<int> numbers = {1,2,3,4,5} ;
    vector<int> :: iterator ptr   ;
    for (ptr = numbers.begin() ; ptr != numbers.end() ; ptr ++)
    {
        cout << ptr << " " ;
    }
    cout << endl ;

    
}
