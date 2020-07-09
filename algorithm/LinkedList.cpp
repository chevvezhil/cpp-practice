#include<iostream>

using namespace std;

class Node {
    public :
        int data;
        Node* next;
        Node(int x){
          data =x;
        }

};

Node* head = NULL;

void appendLast(int val){
 
 Node* temp  = head;
        while(temp->next != NULL){
             temp  = temp->next;
        }

        Node* newNode = new Node(val);
        temp->next = newNode;
        newNode->next = NULL;
}

void appendInFront(int val){

    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void appendInMiddle(Node* prev_node ,int val){

    Node* newNode = new Node(val);
    newNode->next = prev_node->next;
    prev_node->next = newNode;

}

void createList(int val){

    if(head == NULL){
       head  = new Node(val);
       head->next = NULL;
    }else {
        appendLast(val);
        //appendInFront(val);
    
    }
}

void delete_node(int val){
    Node* temp = head ;
    Node* prev;

    if(temp != NULL && temp->data == val){
        head = temp->next;
        return;
    }

    while(temp != NULL && temp->data != val){
        prev = temp;
        temp = temp->next;
    }
    cout << "temp val" << temp->data <<endl;
    if(temp == NULL) return;
    prev->next = temp->next;

}

void traversal(){
 
    Node* temp = head;
    while(temp !=NULL){
        cout << temp->data <<endl;
        temp = temp ->next;
    }

}

void reverse(){

Node* current = head;
Node* prev = NULL;
Node* next = NULL;

while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
}
head = prev;

}

int main(){

    createList(10);
    createList(30);
    createList(40);
    appendInMiddle(head->next,20);
    traversal();
    cout << "Reversing" << endl;
    reverse();
   // delete_node(10);
    traversal();

    return 0;
}