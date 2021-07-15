#include <iostream>
using namespace std;

void hanoi(int n,char source,char helper,char dest)
{
    if(n==0)    return;
    
    hanoi(n-1,source,dest,helper);
    cout<<source<<"->"<<dest<<endl;
    hanoi(n-1,helper,source,dest);
}

int main()
{
    hanoi(3,'A','B','C');
    return 0;
}


