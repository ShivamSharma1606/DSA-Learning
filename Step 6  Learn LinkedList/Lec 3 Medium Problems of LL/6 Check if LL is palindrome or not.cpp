// brute force approach
/*
1 first we create stack data structure
2 push all the elment
3 compare the top element with head
4 repeat step 3 for head->next
5 if thier is any false comparison return FALSE
6 after all comparison return true
tc =2n and sc =n
*/

// optimal approach
//  tc=2n and sc=1

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *reverseLinkedList(Node *head)
{
    // Write your code here
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    // n/2
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // n/2
    Node *newHead = reverseLinkedList(slow->next);

    Node *first = head;
    Node *second = newHead;
    // n/2
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            // n/2
            reverseLinkedList(slow->next);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLinkedList(slow->next);
    return true;
}