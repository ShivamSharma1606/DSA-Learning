//brute force approach using map data structure
/*
1 first we create the map and store the node(node not its data) and int(can be bool or any other thing)
2 compare the map with the secound node element 
3 if node is present break and return the node else repeat step 2
4 repeat untill the 2nd ll is not finished
*/

//better approach   
/*
1 first find the length of ll l1 and l2
2 calulate the differece of l1 and l2
3 move the greater link list by differnce
4 start comparing the element of l1 and l2 (when greater linked list is moved by greater)
5 return true when two node are same
6 else return false
 tc n1+n2 +(n2-n1)+n1 ie o(n1 +2n2) and sc =1
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *collisionPoint(ListNode *temp1, ListNode *temp2, int diff){
        while(diff){
            diff--;
            temp2=temp2->next;
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1; //we can also choose temp2
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //better approach
        ListNode *tempa = headA;
        ListNode *tempb = headB;

        int n1=0;
        int n2=0;

        while(tempa!=NULL){
            n1++;
            tempa=tempa->next;
        }

        while(tempb!=NULL){
            n2++;
            tempb=tempb->next;
        }

        if(n1<n2){
            return collisionPoint(headA,headB,n2-n1);
        }else{
            return collisionPoint(headB,headA,n1-n2);
        }        
    }
};


//optimal approach
//tc=0(n1+n2) sc=1


