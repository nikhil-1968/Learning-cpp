#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    vector<node*> children;
    node(int val)
    {
        data=val;
    }
};
void printTree(node* root)
{
    cout<< root->data<<": ";
    for(int i=0 ;i < root->children.size(); i++)
    {
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i=0 ;i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
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
node* takeInput(){
    cout<<"Enter data\t";
    int data;cin>>data;
    node* root=new node(data);
    cout<<"Enter Number of children\t";
    int num;cin>>num;
    for(int i=0;i<num;i++)
    {
        node* child=takeInput();
        root->children.push_back(child);
    }
    return root;
};
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
int countNodes(node* root)
{
    int sum=0;
    for(int i=0;i<root->children.size();i++)
    sum+=countNodes(root->children[i]);

    return sum+1;
}
int heightOfTree(node* root)
{
    int mx=0;
    for(int i=0;i < root->children.size();i++)
    {
        mx=max(mx,heightOfTree(root->children[i]));
    }
    return mx+1;
}
void printAtLevelK(node* root,int k)
{
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
  
    for(int i=0;i < root->children.size();i++)
    {
        printAtLevelK(root->children[i],k-1);
    }

}
void preorder(node* root)
{
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    preorder(root->children[i]);
}
void postorder(node* root)
{
    for(int i=0;i<root->children.size();i++)
    postorder(root->children[i]);
    cout<<root->data<<" ";
}
int main(){
    cout<<endl;
    node* root= takeInputLevelWise();
    printTreeLevelWise(root);
    cout<<"Number of nodes : ";
    cout<<countNodes(root)<<endl;
    cout<<"Height : ";
    cout<<heightOfTree(root)<<endl;
    cout<<"printAtLevelK : "<<endl;
    printAtLevelK(root,1);
    cout<<endl;
    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder : ";
    postorder(root);
    cout<<endl;
    
    //1 4 1 2 3 4 2 6 7 1 8 1 9 1 11 0 0 0 1 10 2 11 13 0 0 0 
return 0;
}