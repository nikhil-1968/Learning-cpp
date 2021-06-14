//SUM OF DIGITS OF A NUMBER
#include <iostream>
using namespace std;
int sum(int a)
{
    if(a/10==0){return a;}  //    Base case

    int prev=sum(a/10);     //    Chote bhai ka kaam

    return (a%10)+prev;     //    my work
   
}
int main()
{
    cout<<sum(121)<<endl;
    return 0;
}
