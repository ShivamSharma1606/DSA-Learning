//leetcode problem
//pen and paper

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=1;i<q.size();i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement= q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


//whole codestudio code

class Stack {
	// Define the data members.

    public:
    queue<int> q;
    int size;
    Stack() {
        // Implement the Constructor.
        size=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        if(isEmpty()){
            size=0;
            return size;  
        } 
        return size;

    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }
    //o(n)
    void push(int element) {
        // Implement the push() function.
        q.push(element);
        for(int i=1;i<q.size();i++){
            q.push(q.front());
            q.pop();
        }
        size++;
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty())   return -1;
        int TopElement= q.front();
        q.pop();
        size--;
        return TopElement;
    }

    int top() {
        if(isEmpty())   return -1;
        // Implement the top() function.
        return q.front();
    }
};