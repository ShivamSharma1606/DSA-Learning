//brute force approach
/*
1 create a map (with node and int i.e timer ) 
2 increase the timer by 1 while traversing the node
3 while traversing the node, compare the give node with the map elements
4 if node is present find the differnce between new timer and previous timer
5 return the difference time
sc=0(n) and tc=n+logn
*/

//optimal approach
//sc =0(1) O(n)

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
int findingTheLength(Node *slow, Node *fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int lengthOfLoop(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return findingTheLength(slow,fast);
        }
    }
    return 0;
}
