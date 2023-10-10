// Problem Statement:
// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support 
// all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:
// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or 
// deque (double-ended queue) as long as you use only a stack's standard operations.

// Example 1:
// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false

// Problem Solution:
class MyQueue {
    stack<int> s1,s2;
    public:
        struct queueType
        {
            int val;
            queueType *next;
        };
        queueType *myQueue = NULL, *head = NULL;
        
        /* Push element x onto myQueue */
        void push(int x) {
            if(myQueue == NULL)
            {
                head = new queueType();
                head->val = x;
                head->next = NULL;
                myQueue = head;;
            }
            else
            {
                queueType *pik;
                pik = new queueType();
                pik->val = x;
                pik->next = NULL;
                myQueue->next = pik;
                myQueue = myQueue->next;
            }
        }
        
        /** Removes the element on front of the myQueue and returns that element. */
        int pop() {
            queueType *pik = head;
            head = head->next;
            int ret = pik->val;
            delete(pik);
            myQueue = head == NULL ? NULL : myQueue;
            return ret;
        }
        
        /* Get the front element. */
        int peek() { return head->val; }
        
        /* Returns whether the stack is empty. */
        bool empty() { return head == NULL; }
};
