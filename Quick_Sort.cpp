#include <iostream>
using namespace std;
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partion(int a[],int si,int ei)
{
    int i=si;int k=si;
    for(;i<ei;i++)
    {
        if(a[i]<a[ei])
        {
            swap(a,i,k);
            k++;
        }
    }
    swap(a,k,ei);
    return k;
}
void quicksort(int a[],int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int pivit=partion(a,si,ei);
    quicksort(a,si,pivit-1);
    quicksort(a,pivit+1,ei);
}
int main()
{
    int a[]={1,4,235,345,69,6969,77,88};
    quicksort(a, 0, 7);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<"\t";
    }
}
