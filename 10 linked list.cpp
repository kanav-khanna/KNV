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

//insert
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
 









