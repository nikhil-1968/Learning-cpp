#include <iostream>
using namespace std;
int subseq(string input,string output[])
{
    
    if(input=="")  return 1;        //Base case
    
    subseq(input.substr(1),output); //Recursion
    
    int size=pow(2,input.size());   //our work
    
    for(int i=0;i<size/2;i++)
    {
    output[size/2+i]=input[0]+output[i];
    }
    return size;
}
int main()
{
    string output[100];
    int size=subseq("set", output);
    cout<<size<<"\t";
    
    for(int i=0;i<size;i++)
        cout<<output[i]<<"\t:";
    
    
    cout<<endl;
    return 0;
}


