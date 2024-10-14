// tc : 2(1) and 2(steps)

class Node {
public:
    string data;
    Node* next;
    Node* back;

    Node(string &url) {
        data = url;
        next = nullptr;
        back = nullptr;
    }
};


class Browser
{
    Node* currentPage;
    public:
    
    Browser(string &homepage)
    {
        // Write you code here
        currentPage = new Node(homepage);
    }

    void visit(string &url)
    {
        // Write you code here
        Node *newNode= new Node(url);
        currentPage->next=newNode;
        newNode->back=currentPage;
        currentPage=newNode;
    }

    string back(int steps)
    {
        // Write you code here
        while(steps){
            if(currentPage->back){
                currentPage=currentPage->back;
            }else{
                break;
            }
            steps--;
        }

        return currentPage->data;
    }

    string forward(int steps)
    {
        // Write you code here
        while(steps){
            if(currentPage->next){
                currentPage=currentPage->next;
            }else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};
