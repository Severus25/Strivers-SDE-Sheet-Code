// Problem Statement:
// https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

// Problem Solution:
class Stack {
    
public:

    int size;
    int *arr;
    int top1;
    
    Stack(int capacity) {
        // Write your code here.
        this->size=capacity;
        arr=new int[size];
        top1=-1;
    }

    void push(int num) {
        // Write your code here.
        if(size-top1>1){
            top1++;
            arr[top1]=num;
        } else {
            return;
        }
    }

    int pop() {
        // Write your code here.
        if(top1==-1){
            return -1;
        }
        else{
            int result=arr[top1];
            top1--;
            return result;
        }
    }
    
    int top() {
        // Write your code here.
        if(top1==-1){
            return -1;
        }
        else{
            return arr[top1];                               
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(top1==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int isFull() {
        // Write your code here.
        if(top1==size-1){
            return 1;
        }
        else{
            return 0;                                        
        }
    }
    
};
