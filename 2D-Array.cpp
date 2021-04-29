#include<iostream>
//#include<array>
//#include<vector>

using namespace std;
 int main()
{
//  input of aaray
    int n,m;
    cout<<"\nENTER SIZE N & M:\t";
    cin>>n>>m;
    int a[n][m];
    cout<<"\nEnter matrix:\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
//    here we go
    int sr=0,sc=0,er=n-1,ec=m-1;
    
    while(sr<=er&&sc<=ec)
    {
        for(int i=sc;i<=ec;i++)
        {
            cout<<a[i][sr]<<"\t";
        }
        sr++;
        for(int i=sr;i<=er;i++)
        {
            cout<<a[ec][i]<<"\t";
        }
        ec--;
        
        if(ec>sc)
        {
            
        
            for(int i=ec;i>=sc;i--)
            {
                cout<<a[i][er]<<"\t";
            }
            er--;
        }
        if(er>sr)
        {
            for(int i=er;i>=sr;i--)
            {
                cout<<a[sc][i]<<"\t";
            }
            sc++;
        }
    }
    
////  Output of array
//    for (int i=0; i<n; i++)
//    {
//        for (int j=0; j<m; j++)
//        {
//            cout<<a[i][j]<<"\t";;
//        }
//        cout<<endl;
//    }
        
        
        
    
        return 0;
}
