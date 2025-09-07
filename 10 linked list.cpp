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

////tortoise algorithm//slow & fast approch  
//Helps reduce time complexity

//slow pointer moves 1 step forward  ...and slow will only move 1 step forward when the fast pointer has the space to move 2 steps forward
//fast pointer moves 2 steps forward
//quickly find the middle node

ListNode* middleNode(ListNode* head) { //Need to use this in OA insted of the basic ass solution
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) //fast->next != NULL if in even case where if i have 6 elements question states mid element is  3rd not 4th 
            {
                fast = fast->next;
                if(fast != NULL)
                    {
                       fast = fast->next; 
                       slow = slow->next;
                    }
                
            }
            return slow;



//234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/description/
//TC - O(N)

1.Break into 2 halves.
2.Reverse the second half.
3.Compare both of them.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // A list with 0 or 1 node is always a palindrome
        }
        
        // 1. Find the end of the first half
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 2. Reverse the second half
        ListNode* secondHalfHead = slow->next; // FIX: Start of the second half
        slow->next = nullptr; // FIX: Split the list into two halves

        ListNode* prev = nullptr;
        ListNode* current = secondHalfHead;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        // After this loop, 'prev' is the new head of the reversed second half

        // 3. Compare the two halves
        ListNode* firstHalfHead = head;
        ListNode* reversedSecondHalfHead = prev; // FIX: Use the correct pointer

        while (firstHalfHead != nullptr && reversedSecondHalfHead != nullptr) {
            if (firstHalfHead->val != reversedSecondHalfHead->val) {
                return false; // Mismatch found
            }
            firstHalfHead = firstHalfHead->next;
            reversedSecondHalfHead = reversedSecondHalfHead->next;
        }

        return true; // All values matched
    }
};


//Check Cycle in a linked list 

///i did this with map ....bad solution lol
//https://leetcode.com/problems/linked-list-cycle/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        map<ListNode*, bool> table;

        ListNode* temp = head;

        while(temp!=NULL)
            {
                if(table[temp] == false)
                    {
                        table[temp] = true;
                    }
                else{
                    //cycle present
                    return true;
                }
                temp = temp->next;
            }
    return false;
    }
};

Questions Asked -
1.check for loop 
2.starting point of loop 
3.remove loop

//Another approach to check loop //tortoise algorithm
O(N)
bool checkloop(Node* &head)
    {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL)
            {
                fast = fast->next;

                if(fast != NULL)
                    {
                        fast = fast->next;
                        slow = slow->next;
                    }
                if(fast == slow)
                    {
                        return true;
                    }
            }
        return flase;
        
    }

//starting point of loop 
1. we use the slow fast pointer to find that loop exits ...both pointers will point to the same element
2. slow = head 
3.start moving the slow and the fast pointer 1 step forward 
4.where the 2 pointers meet is the starting point of the loop

//Why does this even work though ? a+b = k*c //long ass proof dont care lol
//the fast pointer does a number of cycles before it meets the slow one ....

//142. Linked List Cycle II
//https://leetcode.com/problems/linked-list-cycle-ii/submissions/1759312635/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL)
            {
                fast = fast->next;
                

                if(fast != NULL)
                    {   
                        fast = fast->next;
                        slow = slow->next;
                    }
                
                if(fast == slow)
                    {
                        break;
                    }
                
            }
        if(fast == NULL)
            {   
                //no cycle present
                return NULL;
            }
        
    slow = head;

    while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};


//Remove a loop 
//since i already know the starting point of the loop i can just remove the loop 

bool checkloop(Node* &head)
    {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL)
            {
                fast = fast->next;

                if(fast != NULL)
                    {
                        fast = fast->next;
                        slow = slow->next;
                    }
                if(fast == slow)
                    {
                        return true;
                    }
            }
        return flase;
        
    }

void removeLoop(Node* &head)
    {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL)
            {
                fast = fast->next;
                
                if(fast != NULL)
                    {
                        fast=fast->next;
                        slow=slow->next;
                    }
                if(fast == slow)
                    {
                        break;
                    }
            }
        
            slow = head;

            while(fast!= slow)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
            node* temp = slow;

            while(temp->next != slow)
                {
                    temp = temp->next;
                }

            temp->next = NULL;
    }

//Add 1 to a linked list
//132
   +1
  133 ///not +1 to each individual element like i intially thought.

  //if carry is 0 i dont need to go throught the whole linked list
  //since addition is done from right to left ...reverse the linked list then do what i need
  //for the final answer i need to reverse it again ....

Node* reverse(Node* &head)
    {
        Node* prev = NULL
        Node* curr = head;

        while(curr!=NULL)
            {
                Node* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
     return prev;   
    }


void addOne(Node* &head)
    {
        //reverse 

        head = reverse(head);

        //add one 
        int carry = 1;
        node* temp = head;
        while(temp->next != NULL) //stop loop before last node so i can handle case where new node insertion needed 
        {   
            int totalsum = temp->data + carry;
            int digit = totalsum%10;
            carry = totalsum/10;
            temp->data = digit;
            temp = temp->next;

            if(carry == 0) //only adding 1 to the first elemnt so of we have no carry no need to traverse the whole thing
                {
                    break;
                }
        }

        if(carry!=0){
        int total sum = temp->data +carry;
        int digit = totalsum%10;
        carry = totalsum/10;
        
        temp->data = digit
        if(carry!=0)
            {
                Node *newNode = new Node;
                temp->next = newNode;

            }
        }

        //reverse
        head = reverse(head);
    }
    
another similar question i should do - 
//https://leetcode.com/problems/add-two-numbers/description/




    ///////VVV IMP
Linked list reverse in groups of k 