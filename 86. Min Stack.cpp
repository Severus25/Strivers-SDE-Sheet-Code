// Problem Statement:
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:
// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// Example 1:
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

// Problem Solution:
class MinStack 
{
public:
    stack<int>s1,s2;
 
 void push(int val) 
    {
        if(s1.empty()||val<=s2.top())
        { 
            s2.push(val);
        }
        s1.push(val);
    }
    void pop() 
    {
        if(s1.empty()||s1.top()==s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }
    int top() 
    {
      return s1.top();
    }
    int getMin() 
    {
       return s2.top();   
    }
};
