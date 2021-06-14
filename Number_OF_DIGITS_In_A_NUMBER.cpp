//Number  OF DIGITS In A NUMBER
#include <iostream>
using namespace std;
int digit(int a)
{
    if(a/10==0){return 1;}  //    Base case

    int prev=digit(a/10);     //    Chote bhai ka kaam

    return 1+prev;   //    my work
   
}
int main()
{
    cout<<digit(696969)<<endl;
    return 0;
}

//output 6
