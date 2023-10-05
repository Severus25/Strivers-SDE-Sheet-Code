// Problem Statement:
// https://www.codingninjas.com/studio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Problem Solution:
#include <bits/stdc++.h>

int removemin(vector<int> &heap){

    int ans=heap[0];

    heap[0]=heap[heap.size()-1];

    heap.pop_back();

    int pi=0;

    int n=heap.size();

    int minindx;

    while(pi<n){

        int lci=2*pi+1;

        int rci=2*pi+2;

        if(lci<n&&rci<n){

            if(heap[lci]<heap[rci]) minindx=lci;

            else minindx=rci;

        }

        else if(lci<n&&rci>=n){

            minindx=lci;

        }else break;

        if(heap[minindx]<heap[pi]){

            swap(heap[minindx],heap[pi]);

        }else break;

        pi=minindx;

    }

    return ans;

} 

void insertinheap(vector<int> &heap,int ele){

    heap.push_back(ele);

    int ci=heap.size()-1;

    while(ci>0){

        int pi=(ci-1)/2;

        if(heap[ci]<heap[pi]){

            swap(heap[ci],heap[pi]);

        }else{

            break;

        }

        ci=pi;

    }

}

vector<int> minHeap(int n, vector<vector<int>>& q) {

    

    vector<int> heap;

    vector<int> ans;

    for(int i=0;i<q.size();i++){

        if(q[i][0]==0){

            insertinheap(heap,q[i][1]);

        }else{

            int removed=removemin(heap);

            ans.push_back(removed);

        }

    }

    return ans;

}
