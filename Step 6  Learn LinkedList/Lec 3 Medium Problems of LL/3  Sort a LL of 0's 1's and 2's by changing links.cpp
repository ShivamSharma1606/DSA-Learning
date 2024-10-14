/*
brute force approach
1 we make the temp0 , temp1, temp2
2 which count the occurence of 0, 1, 2 by traverse the linked list
3 update the ll by checking the number of temp0 i.e must be greater than 0
4 redue the temp0 by 1
5 repeat step 3 and 4 for temp1 and temp2
tc = o(2n) and sc=1 
*/

/*
optimal approach in o(n)
1 make a link of ll of 0
2 make a link of ll of 1
3 make a link of ll of 2
connect 2 with 1 
connect 21 with 0
All have done in one pass
sc=o(1)
*/


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
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* sortList(Node *head){
    // Write your code here.
    Node *zeroH=new Node(-1);
    Node *oneH=new Node(-1);
    Node *twoH=new Node(-1);

    Node *zero=zeroH;
    Node *one=oneH;
    Node *two=twoH;

    Node *temp=head;

    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }else if(temp->data==1){
            one->next=temp;
            one=temp;
        }else{
            two->next=temp;
            two=temp;
        }

        temp=temp->next;
    }
    
    //read the following three line on copy and pen very important
    zero->next=(oneH->next)?(oneH->next):(twoH->next);
    one->next=twoH->next;
    two->next=NULL;

    Node *newHead=zeroH->next;

    //this is for more optimization , code can run without them also
    free(zeroH);
    free(oneH);
    free(twoH);
    
    return newHead;
}

int main(){

}