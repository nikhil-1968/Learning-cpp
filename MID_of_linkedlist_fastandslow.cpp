#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
int search(node* &head,int x)
{
    int pos=0;
    node* current=head;
    while(current!=NULL)
    {
        if(current->data==x)
        {
            return pos;
        }
        pos++;
        current=current->next;
    }
    return -1;
}
void addhead(node* &head,int data){
    node* n=new node(data);
    n->next=head;
    head=n;
}
void pushback(node* &head,int data){
    node* n=new node(data);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* current=head;
    
    while(current->next != NULL)
    {
        current=current->next;
    }
    current->next=n;
}
void display(node* &head){

    node* current=head;
    while(current!=NULL)
    {
        cout<<current->data<<"\t";;
        current=current->next;
    }
    cout<<endl;
}
int mid(node* &head){
node* fast=head->next; 
node* slow=head;
while(fast!=NULL&&fast->next!=NULL){
    fast=fast->next->next;
    slow=slow->next;
}
return slow->data;}
int main()
{
    node *LL1=NULL;
    pushback(LL1,10);
    pushback(LL1,20);
    pushback(LL1,50);
    pushback(LL1,90);
    cout<<mid(LL1);

return 0;
}
