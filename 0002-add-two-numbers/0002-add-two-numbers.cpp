/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // ListNode* temp1=l1;
        // ListNode* temp2=l2;
        // ListNode* curr=new ListNode(0);
        // ListNode* head=curr;
        // ListNode* prev1=NULL;
        // ListNode* prev2=NULL;;

        // int sum=0;
        // int carry=0;


        // while(temp1!=NULL && temp2!=NULL)
        // {
        //     prev1=temp1;
        //     prev2=temp2;
        //     sum=carry+temp1->val+temp2->val;

        //     if(sum>9)
        //     {
        //         carry=sum/10;
        //         sum=sum%10;
        //     }
        //     else{
        //         carry=0;
        //     }
        //     ListNode* node=new ListNode(sum);
        //     curr->next=node;
        //     curr=node;
        //     temp1=temp1->next;
        //     temp2=temp2->next;
        // }
        // while(temp1!=NULL)
        // {
        //     prev1=temp1;
        //     sum=carry+temp1->val;

        //     if(sum>9)
        //     {
        //         carry=sum/10;
        //         sum=sum%10;
        //     }
        //     else{
        //         carry=0;
        //     }
        //     ListNode* node=new ListNode(sum);
        //     curr->next=node;
        //     curr=node;
        //     temp1=temp1->next;
        // }
        // while(temp2!=NULL)
        // {
        //     prev2=temp2;
        //     sum=carry+temp2->val;

        //     if(sum>9)
        //     {
        //         carry=sum/10;
        //         sum=sum%10;
        //     }
        //     else{
        //         carry=0;
        //     }
        //     ListNode* node=new ListNode(sum);
        //     curr->next=node;
        //     curr=node;
        //     temp2=temp2->next;
        // }
        // if(carry!=0)
        // {
        //     if(prev1->val+prev2->val+carry>9)
        //     {
        //         ListNode* cnode=new ListNode(carry);
        //         curr->next=cnode;
        //         curr=cnode;
        //         curr->next=NULL;
        //     }
        // }
        // return head->next;

        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* curr=new ListNode(0);
        ListNode* head=curr;

        int sum=0;
        int carry=0;

        while(temp1!=NULL && temp2!=NULL)
        {
            sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode(sum);
            curr->next=node;
            curr=node;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL)
        {
            sum=temp1->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode(sum);
            curr->next=node;
            curr=node;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            sum=temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode(sum);
            curr->next=node;
            curr=node;
            temp2=temp2->next;
        }
        if(carry!=0)
        {
            ListNode* node=new ListNode(carry);
            curr->next=node;
            curr=node;
            curr->next=NULL;
        }
        return head->next;
    }
};