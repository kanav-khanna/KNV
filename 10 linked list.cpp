//Read about operating system storage management linked list use

//I always miss some testcases in OA ....some edge cases need to be better handled


Types-
1.singly
2.doubly
3.circular singly
4.circular doubly


#include<iostream>
using namespace std;

class node;;{
    
    public:
    int data;
    node* next;
    
    node(){
        cout<<"default constr";
        this->next = NULL;
    }
    
    node(int data){
         cout<<" constr";
        this->data = data;
        this->next = NULL;
    }
    
};

void print(node* head)
{
    node* temp = head;
    int length = 0;
    while(temp!=NULL)
    {   
        length++;
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<length<<endl;
}

int main() {
    //node a; //static allocation
    //node* head = new node(); //dynamic allocation 
    node* head = new node();
    node* first = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    
    head = first;
    first->next = second;
    second->next = third;
    
    print(head);
    
    return 0;
}

//insert////////////////
#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }


};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                
        }
        else {
            //step1: creatae a node
            Node* newNode = new Node(data);
            //step2: connect woth tail ndoe
            tail->next = newNode;
            //step3: update tail;
            tail = newNode;
        }

}
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        int len = findLength(head);
        
        if(position == 1) {
                insertAtHead(head, tail , data);
                return;
        }
        else if(position > len) {
                insertAtTail(head, tail, data);
                return;
        }
        else {
            Node* newNode = new Node(data);
            
            Node* prev = NULL;
            Node* curr = head;
            while(position != 1) {
                position--;
                prev = curr;
                curr = curr->next;
            }
            
            //step3:
            newNode -> next = curr;

            //step4:
            prev -> next = newNode;
            
        }
        
}



int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail,20);
        insertAtHead(head, tail,50);
        insertAtHead(head, tail,60);
        insertAtHead(head,tail, 90);
        insertAtTail(head, tail, 77);

        print(head);
        cout << endl;

        return 0;
}
 

////Delete 


#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }


};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                
        }
        else {
            //step1: creatae a node
            Node* newNode = new Node(data);
            //step2: connect woth tail ndoe
            tail->next = newNode;
            //step3: update tail;
            tail = newNode;
        }

}

void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        int len = findLength(head);
        
        if(position == 1) {
                insertAtHead(head, tail , data);
                return;
        }
        else if(position > len) {
                insertAtTail(head, tail, data);
                return;
        }
        else {
            Node* newNode = new Node(data);
            
            Node* prev = NULL;
            Node* curr = head;
            while(position != 1) {
                position--;
                prev = curr;
                curr = curr->next;
            }
            
            //step3:
            newNode -> next = curr;

            //step4:
            prev -> next = newNode;
            
        }
        
}
//delete

void deletenode(Node* &head, Node* &tail, int position)
    {   
        int len = findLength(head)
        if(head == NULL)
        {
            cout<<"empty ...cannot delete";
        }
        
        if(position ==1)
        {
            //delete first node
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            
        }
        
        else if(position == len)
        {
            //delete last node
            
            //find prev 
            node* prev = head;
            while(prev ->next != tail)
            {
                prev = prev ->next;
            }
             
            prev->next = NULL;
            delete tail;
            tail = prev;
            
        }
        else{
            Node* prev = NULL;
            Node* curr = head;
            
            while(posiion != 1) //1 = position should pass this in as function param
            {
                position--;
                prev = curr;
                curr = curr->next;
            }
            
            prev->next = curr->next;
            curr->next = NULL;
            delete curr
            
        }
    }


int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail,20);
        insertAtHead(head, tail,50);
        insertAtHead(head, tail,60);
        insertAtHead(head,tail, 90);
        insertAtTail(head, tail, 77);

        print(head);
        cout << endl;
        deleteNode(head,tail,1);
    

        return 0;
}

////////////////////Doubly Linked list/////////////////////
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node()
    {
       this->prev = NULL;
       this->next = NULL;        
    }
    
    Node(int data)
    {
        this->prev = NULL;
        this->next = NULL;
        this->data = data;
    }
};
void print(Node* head)
{
        Node* temp = head;
        
        while(temp != NULL) //not temp next or you wont print the last node
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }

int findLength(Node* &head) //& needed
{
    int count = 0;
    Node* temp = head;
    while(temp != NULL)
    {
       count++;
       temp = temp->next;
    }
    
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data)
{   
    //ll empty case
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = new Node(data);
    
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    //ll empty case
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    
    else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head, Node* &tail, int data, int pos)
{
    int len = findLength(head);
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    
    else{
        if(pos == 1)
        {
            insertAtHead(head,tail,data);
        }
        
        else if(pos == len+1)
        {
            insertAtTail(head,tail,data);
        }
        else{
            Node* newNode = new Node(data);
            Node* prevNode = NULL;
            Node* currNode = head;
            
        while(pos != 1)
         {
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
          }
            
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
     
}

void deleteNode(Node* &head, Node* &tail, int data, int position)
{   
    int len = findLength(head);
    //single element case
    if(head == tail)
    {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    if(head == NULL)
    {   
        //delete from head
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    
    else if(position == len)
    {
        //delete from tail 
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev - NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        //delete at position
        Node* prevNode = NULL;
        node* currNode = head;
        
        while(position != 1)
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        
        Node* nextNode = currNode->next;
        
        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        
        nextNode -> prev = prevNode;
        delete currNode;
    }
}

int main() {
            
        Node* head = new Node(10);
        //Node* second = new Node(20);
        Node* tail = head;
        
        insertAtHead(head,tail,20);
        insertAtHead(head,tail,30);
        insertAtTail(head,tail,90);
        InsertAtPosition(head,tail,100,2);
        print(head);
    
        return 0;
}


/////Look into dedect and delete loop in linked list //////////////////


////Reverse a linked list///////
https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* currNode = head;
        ListNode* prevNode = NULL;

        while(currNode != NULL)
            {
                ListNode* nextval = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = nextval;
            }
        
        return prevNode;
        
    }
};
///Middle of a linked list 
https://leetcode.com/problems/middle-of-the-linked-list/
//bad time complexity since i have to do 2 passes of the linked list. //tortoise algorithm needed 
class Solution {
public:
    int getLength(ListNode* head)
        {
            int len = 0;
            ListNode* temp = head;
            while(temp != NULL)
                {
                    len++;
                    temp = temp->next;
                }
            return len;
        }

    ListNode* middleNode(ListNode* head) {
        
        int len = getLength(head);
        int position = len/2 + 1;
        int currentpos = 1;
        ListNode* temp = head;
        while(currentpos != position)
            {   
                currentpos++;
                temp = temp->next;
            }
        return temp;
    }
};


