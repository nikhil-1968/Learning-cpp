class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL )
        {
            fast=fast->next->next;
            slow=slow->next;
        }
         return slow;
    }
  ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* temp=head->next;
        ListNode*ans=reverseList(head->next);
        head->next=NULL;
        temp->next=head;
        return ans;
    }
  
  void print(ListNode* head)
    {
        while(head)
        {cout<<head->val<<" ";
        head=head->next;}
    }
    bool isPalindrome(ListNode* head) {
       if(head->next==NULL)
           return true;

        ListNode* Mid=middleNode(head);
        //cout<<Mid->val<<"  "<<Mid->next->val;

         Mid = reverseList(Mid);
        while(Mid)
        {
            if(Mid->val!=head->val)
                return 0;
            Mid=Mid->next;
            head=head->next;
        }
        return true;

    }
};
