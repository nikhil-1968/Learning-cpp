//Finding max of a numbers at right of given index
#include <iostream>
using namespace std;

int max(int a[],int n)
{
    if(n==1)
        return a[0];
    
    int prev=max(a+1,n-1);
    cout<<prev<<"\t:";
    
    if(a[0]>=prev)  return a[0];
    else            return prev;
    
}
int main()
{
    int a[]={121,2,54,5,3};
    cout<<max(a,5)<<endl;
    
    return 0;
}

//Output    3    :5    :54    :54    :121
