#include<bits/stdc++.h>
using namespace std;
#define fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
typedef vector<int>		vi;

void printArray(int a[],int size)
{
    cout<<"[ ";
   for(int i=0;i<size;i++){cout<<a[i]<<",";}
   cout<<"]"<<endl;
}
void selectionSort(int a[],int size)
{ 
    int mn=a[0];
    for(int counter=0;counter<size;counter++)//outerloop
    for(int i=counter;i<size;i++)//innerloop
    {   if(a[i]<a[counter])//swap
        {
            int temp=a[i];
            a[i]=a[counter];
            a[counter]=temp;
        }
    }
}
int main(){
int a[]={3,2,69,4,1,42,};
cout<<"UNsorted";
printArray(a,6);
selectionSort(a,6);
cout<<"sorted";
printArray(a,6);

return 0;
}