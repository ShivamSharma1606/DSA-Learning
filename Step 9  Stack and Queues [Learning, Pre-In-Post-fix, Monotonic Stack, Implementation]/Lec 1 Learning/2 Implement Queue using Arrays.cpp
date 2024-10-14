// tc: 0(1) and sc: n
//  even we have less element we have to allocate the n space , which is the disadvantage of array for implement queue

// only for push and pop
// homework: make code for size and top
class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

// Function to push an element x in a queue.
void MyQueue ::push(int x)
{
    // Your Code
    if ((rear + 1) % 100005 == front)
        return;

    arr[rear] = x;
    rear = (rear + 1) % 100005;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    // Your Code
    if (front == rear)
        return -1;
    int el = arr[front];

    front = (front + 1) % 100005;

    return el;
}
