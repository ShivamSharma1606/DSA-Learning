//brute force apprach
/*
1 create a stack and push the elemnt in the stack
2 pop the stack element and replace with the given link list
2 it take 0(2n) complexity
*/

//optimal solution


class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};



Node* reverseDLL(Node* head)
{   
    if(head==NULL || head->next==NULL)  {
        return head;
    }


    //please do it on copy and pen
    Node * current =head;
    Node * back= NULL;

    while(current!=NULL){
        back=current->prev;

        current->prev=current->next;
        current->next=back;

        current=current->prev;
    }
    return back->prev;
}

int main(){
    
}