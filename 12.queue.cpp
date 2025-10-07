//FIFO


//STL implementation of queue
int main(){
    //create
    queue<int> q;
    //insert
    q.push(5);
    //size
    cout<<q.size();
    //empty
    if(q.empty() == true)
        {
            cout<<"queue is empty";
        }
    else{
        cout<<"queue is not empty"  
    }
    //remove
    q.pop();

    //queue front
    cout<<q.front()<<endl;
    //last element in queue
    cout<<q.back()<<endl;
    return 0;
}

//Queue implementation from scratch ..with array
//O(1) ...time complexity for push pop size ..get front get back 
//push - rear //pop - front 
//front = -1 and back -1;

class queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    queue(int size)
        {
            arr = new int[size];
            this->size = -1;
            front = -1;
            rear = -1;

        }

        void push(int val)
        {
            //check full
            if(rear == size-1)
                {
                    cout<<"queue overflow"<<endl;
                    return;
                }
            else if(front == -1 && rear == -1){
                //empty case
                front++;
                rear++;
                arr[rear] = val; 
            }
            else{
                //normal case
                rear++;
                arr[rear] = val; //??
            }
        }

        void pop(){
            //underflow
            if(front == -1 && rear == -1)
                {
                    cout<<"queue underflow"
                    return;
                }

                else if(front == rear)
                    {
                        arr[front] = -1;
                        front = -1;
                        rear = -1;
                    }
                else{
                    //normal case
                    arr[front] = -1;
                    front++;
                }
            }
    
    bool isEmpty(){
        if(front == -1 && rear == -1)
            {
                return true;
            }
            else{
                return flase;
            }
    }

    bool getSize(){
        if(front == -1 && rear == -1)
            {
                return 0; //need this since rear-front+1 gives wring value on empty case
            }
        else{
        return rear-front+1;
        }
    }

    int getFront(){
        if(front == -1)
            {
                cout<<"no element in queue"<<endl;
                return -1;              
            }
            else{
                return arr[front];
            }
            
    }

    void print(){

    }
}

//circular queue
//normal queue implementation waste alot of memory in certain cases for we use cir queue
//only difference 

class cqueue{
    public:
    int* arr;
    int size;
    int front;
    int rear;

    cqueue(size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
        {
            //overflow

            //empty case

            //circular nature

            //normal flow
            if((front == 0 && rear == size-1)||(rear == front-1))
                {
                    cout<<"overflow"<<endl;
                }
            else if(front == -1 && rear ==-1)
                {
                    front++;
                    rear++;
                    arr[rear] = val;
                }
            else if(rear == size-1 && front != 0)
                {
                    rear = 0;
                    arr[rear] = val;
                }
            else{
                rear++;
                arr[rear] = val;
            }
        }

    void pop(){
        //underflow
        //single element
        //circular nature
        //normal flow

        if(front == -1 && rear == -1)
            {
                cout<<"underflow"<<endl;
            }
        else if(front == rear)
            {
                arr[front] = -1;
                front++; //ohhh noo
                front = -1;
                rear = -1;
            }
         else if(front == size-1)
            {
                arr[front] = -1;
                front = 0;
            }
        else{
            arr[front] = -1;
            front++;
        }
    } 
}

//Doubly ended queue 
dqueue
//push and pop from both ends possible 

class Dq
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Dq(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void pushFront(int val)
    {
        /* // overFlow
         if (front == 0)
         {
             cout << "OverFlow" << endl;
             return;
         }
         // empty case
         else if (front == -1 && rear == -1)
         {
             front++;
             rear++;
             arr[front] = val;
         }
         // normal case
         else
         {
             front--;
             arr[front] = val;
         }
         */
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) // imp condition
        {
            cout << "OverFlow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[front] = val;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }
    void pushBack(int val)
    {
        /* // overflow
         if (rear == size - 1)
         {
             cout << "OverFlow" << endl;
             return;
         }
         // empty case
         else if (front == -1 && rear == -1)
         {
             front++;
             rear++;
             arr[rear] = val;
         }
         // normal case
         else
         {
             rear++;
             arr[rear] = val;
         }
         */
        // The above code is garbage as humme Circular Nature maintain krna he padega
        // over flow
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) // imp condition
        {
            cout << "OverFlow" << endl;
            return;
        }
        // first Ele
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // circular Nature
        else if (rear == size - 1 & front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // normal pushing
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void popFront()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Queue underFlow" << endl;
            return;
        }
        else if (front == size - 1)
        {
            // single element
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    void popBack()
    {
        // undeflow
        if (front == -1 && rear == -1)
        {
            cout << "UnderFlow" << endl;
            return;
        }
        // single element
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // circular Nature
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        // normal Flow
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
};

int main()
{
    // queue<int> q;
    // q.push(5);
    // cout << "Size of Queue: " << q.size() << endl;
    // cout << "Element in Queue: " << q.front() << endl;
    // q.pop();
    // cout << "Size of Queue: " << q.size() << endl;
    // cout << "Queue is empty: " << q.empty() << endl;
    // q.push(10);
    // cout << "Element in Queue: " << q.front() << endl;
    // q.push(15);
    // cout << "Last Element in the Queue: " << q.back() << endl;
    // q.push(20);
    // cout << "Last Element in the Queue: " << q.back() << endl;

    // CustomQueue q(5);
    // q.pop();
    // cout << "Is Queue Empty: " << q.isEmpty() << endl;
    // q.push(10);
    // q.print();
    // q.pop();
    // q.print();
    // q.pop();
    // q.print();
    // q.push(20);
    // q.pop();
    // q.print();
    // q.push(30);
    // q.print();
    // q.pop();
    // q.push(40);
    // q.print();
    // q.push(50);
    // q.print();
    // q.push(60);
    // q.print();
    // cout << "Front Element: " << q.getFront() << endl;
    // cout << "Rear element: " << q.getRear() << endl;

    // circular Queue
    // CircularQueue q(5);
    // // q.print();
    // q.push(10);
    // q.push(10);
    // q.push(10);
    // q.push(10);
    // q.push(10);
    // // q.push(69);
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.push(69);
    // q.push(190);
    // q.push(1902);
    // q.push(190);
    // q.push(0);
    // q.print();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.print();
    // q.pop();
    // q.print();
    // q.pop();

    // dequeue
    //(Doubly Ended Queue)
    // front se pop push and rear se push pop
    // #include<dequeu>->include
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(20);
    cout << "Size of DQ: " << dq.size() << endl;
    cout << "Front Ele: " << dq.front() << endl;
    cout << "Back Ele(Rear Ele): " << dq.back() << endl;
    dq.pop_front();
    cout << "Size of DQ: " << dq.size() << endl;
    cout << "Front Ele: " << dq.front() << endl;
    cout << "Back Ele(Rear Ele): " << dq.back() << endl;
    // process scheduling types of queue  -> OS

    // Implement Doubly Ended Queue From Scratch

    // Circular Dq->need rto do to 

    return 0;
}


//Reverse a queue
..using stack?

void reverseQueue(queue<int> &q)
    {
        stack<int> s;

            while(!q.empty)
                {
                    int frontElement = q.front();
                    q.pop();

                    s.push(frontElement);
                }
            while(!s.empty())
                {
                    int element = s.top();
                    s.pop();

                    q.push(element);
                }
    }
int main()
    {
        queue<int> q;

        p.push(10);
        p.push(20);
        p.push(30);
        p.push(40);
        p.push(50);

        reverseQueue(q);

        while(!q.empty)
            {
                int element = q.front();
                q.pop();
                cout<<element;
            }
    }


//Reverse K elements 

void reverseFirstk(){
    stack<int> s;
    //push first k into stack 
        for(int i = 0;i<k;i++)
            {
                int temp = q.front();
                q.pop();
                s.push(temp);
            }
    //push all k element into queue

    while(!s.empty)
            {
                int temp = s.top();
                s.pop();
                q.push(temp);
            }
    //pop and push first(n-k) elements into queue again

    for(int i = 0;i<(n-k);i++)
            {
                int temp = q.front();
                q.pop();
                q.push(temp);
            }

}
//
//Interleave the First Half of the Queue with Second Half
https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1
input -> 10,20,30,40,50,60,70,80
output-> 10,50,20,60,30,70,40,80
 
//using queue and not stack since that would reverse the order 
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int half = q.size()/2;
        
        queue<int> q1;
        
        
        //push first half of original queue into second queue
        for(int i = 0;i<half;i++)
            {
                int temp = q.front();
                q.pop();
                q1.push(temp);
            }
        
        //merge both into the original queue
        
        for(int i = 0;i<half;i++)
            {
                int temp = q1.front();
                q1.pop();
                
                q.push(temp);
                
                temp = q.front(); 
                q.pop();
                
                q.push(temp); //rear ma push brooooo
            }
        
    }
};


//First negitive integer in every window of k

//any window questions i see just apply sliding window ...ezz pzz 

input 2,-5,4,-1,-2,0,5
k = 3 
window: 2,-5,4
        -5,5,-1 ...


