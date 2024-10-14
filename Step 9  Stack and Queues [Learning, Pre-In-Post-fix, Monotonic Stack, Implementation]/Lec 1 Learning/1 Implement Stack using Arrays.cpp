//tc: 0(1) and sc: n 
// even we have less element we have to allocate the n space , which is the disadvantage of array for implement stack

class Stack {
    
public:

    int capacity;
    int *arr;   
    int t; 
    Stack(int cap) {
        // Write your code here.
        capacity=cap;
        arr= new int[capacity];
        t=-1;
    }

    void push(int num) {
        // Write your code here.
        if(t==capacity-1)    return;
        t++;
        arr[t]=num;
    }

    int pop() {
        // Write your code here.
        if(t==-1)    return -1;
        int temp =arr[t];
        t--;
        return temp;
    }
        
    int top() {
        // Write your code here.
        if(t==-1) return -1;
        return arr[t];
    }
    
    int isEmpty() {
        // Write your code here.
        if(t==-1) return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(t==capacity-1)    return 1;
        return 0;
    }
    
};


