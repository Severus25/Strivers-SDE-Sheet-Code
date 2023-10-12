// Problem Statement:
// https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Problem Solution:
#include <bits/stdc++.h>

void sort(stack<int> &stack,int element){
  if(stack.empty()||(!stack.empty()&&stack.top()<element)){
    stack.push(element);
    return;
  }
  int num=stack.top();
  stack.pop();
  sort(stack,element);
  stack.push(num);
}

void sortStack(stack<int> &stack)
{
// Write your code here
  if(stack.empty()){
    return;
  }
  int element=stack.top();
  stack.pop();
  sortStack(stack);
  sort(stack,element);
}
