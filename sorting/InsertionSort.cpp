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
void insertionSort(int a[],int size)
{
    for(int current=1;current<size;current++)
    {
        int temp=a[current];
        int i=current-1;
        while((i>=0)&&(temp<a[i]))
        {
            a[i+1]=a[i];
                i--;
        }
        a[i+1]=temp;
    }
}
int main(){
int a[]={3,2,69,4,1,42,};
cout<<"UNsorted";
printArray(a,6);
insertionSort(a,6);
cout<<"sorted";
printArray(a,6);

return 0;
}