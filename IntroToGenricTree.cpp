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
int main(){
    
    node* root= takeInputLevelWise();
    printTreeLevelWise(root);
    
return 0;
}