// Problem Statement:
// https://www.codingninjas.com/studio/problems/implement-queue-using-arrays_8390825?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// Problem Solution:
class Queue
{
    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100001);
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        // Write your code here.
        arr[rear] = e;
        rear++;
    }

    // Dequeue (retrieve) the element from the front of the queue.

    int dequeue()

    {

        // Write your code here.

        if (front == rear)

        {

            return -1;
        }

        else
        {

            int ans = arr[front];

            front++;

            return ans;
        }
    }
};
