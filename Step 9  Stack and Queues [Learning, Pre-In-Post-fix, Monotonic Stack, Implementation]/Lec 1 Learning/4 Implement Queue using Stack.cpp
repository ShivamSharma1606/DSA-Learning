//pen and paper
//leetcode

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
         
    }

    //2n
    void push(int x) {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    
    int pop() {
        if(empty()) return -1;
        int dat=s1.top();
        s1.pop();
        return dat;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */





// more optimize approach

class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int> s1,s2;

    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(!s2.empty()){
            int dat=s2.top();
            s2.pop();
            return dat;
        }
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()){
            int dat=s2.top();
            s2.pop();
            return dat;
            }
        return -1;
        }
    }

    int peek() {
        // Implement the peek() function here.
        if(!s2.empty())   return s2.top();
        else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty()){
                return s2.top();
        }
        return -1;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return (s1.empty() && s2.empty())  ;
        
    }
};
