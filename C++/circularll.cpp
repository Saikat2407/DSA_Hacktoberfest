#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void inserAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head->next = n;
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        inserAtHead(head,val);
        return;
    }
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while (temp!=head);
    cout<<endl;
    
}
int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    inserAtHead(head,6);
    display(head);

    return 0;   
}