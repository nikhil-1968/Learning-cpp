#include<bits/stdc++.h>
using namespace std;
#define fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
typedef vector<int>		vi;
class node{
public:
    int data;
    vector<node*> children;
    node(int val)
    {
        data=val;
    }
    ~node(){
        for(int i=0;i<children.size();i++)
        delete children[i];
    }
};
void printTreeLevelWise(node* root)
{
    queue<node*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        node* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();i++)
        {
             pendingNodes.push(front->children[i]);
             cout<<front->children[i]->data<<" , ";
        }
        cout<<endl;
    }
}
node* takeInputLevelWise(){
    cout<<"Enter Root"<<":\t";;
    int data;cin>>data;
    node* root=new node(data);
    queue<node*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        node* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"\nEnter Number of child's of "<<front->data<<":\t";
        int childNum;cin>>childNum;
        for(int i=0;i<childNum;i++)
        {
            int childData;
            cout<<"\nEnter "<<i<<"th child of "<<front->data<<":\t";;
            cin>>childData;
            node* child = new node(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
int countNodesGreaterThanX(node* root,int x)
{
    int count=0;
    for(int i=0;i<root->children.size();i++)
    {   
        count+= countNodesGreaterThanX(root->children[i],x);
    }
    if(root->data > x)
    return count+1;

    return count;
}
int sumOfNode(node* root)
{
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=root->children[i]->data;
    }
    return sum;
}
pair<node*,int>  nodeWithMaxSum(node* root)
{
    pair<node*,int> ans;
    ans = make_pair( root,sumOfNode(root));
    for(int i=0;i<root->children.size();i++)
    {
        pair<node*,int> x;
        x=make_pair(root->children[i],sumOfNode(root->children[i]));
        if(ans.second<x.second)
        {return x;}
    }
    return ans;
}
int main(){
    cout<<endl;
    node* root= takeInputLevelWise();
    printTreeLevelWise(root);
    pair<node*,int> ans=nodeWithMaxSum(root);
    cout<<endl<<ans.first->data<<" WITH SUM "<<ans.second<<endl;
    
return 0;
}