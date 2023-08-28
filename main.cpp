/*
 * A Doubly Linked list
 */
#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node* prev;
};

//print the doubly linked list
void Print_list(Node* head) {
    while(head != NULL) {
        cout<<head->value<<" ";
        head = head->next;
    }
}

//create the node to start the doubly linked list
Node* newNode(int val) {
    Node* temp = new Node();
    temp->value = val;
    temp->next = NULL; //Set our next to Null
    temp->prev = NULL; //Set our prev to Null
    return temp;
}

//create a function to insert a node at the front of our doubly linked list
void InsertAttheFront(Node** head, int value) {
   //prepare a new node
    Node* newnode = newNode(value);
    newnode->next = *head;
    newnode->prev = NULL;
    (*head)->prev = newnode;
    //point to the node with just replaced for head node
    *head = newnode;
}

//create a function to insert a node at the end of our doubly linked list
void InsertAttheEnd(Node** head, int value) {
    //prepare a new node
    Node* newnode = newNode(value);
    //check if the linked list is empty, new node will be head node if it is empty
    if(*head == NULL) {
        *head = newnode;
        return;
    }

    Node* currentnode = *head;
    //traverse the list to find the last node
    while(currentnode->next != NULL) {
        currentnode = currentnode->next;
    }
    //update pointer to insert node at the end
    currentnode->next = newnode; //set our last node to point to our new node and so now new node is last node
    newnode->prev = currentnode; //set the prev of our newnode to point to our replaced last node now
    newnode->next = NULL; //set our newnode which is last to point to null now
}

//Insert After a given node
void InsertAfter(Node* prevnode, int newValue) {
    //check if the previous node is null
    if(prevnode == NULL) {
        cout<<"node cannot be NULL"<<endl;
        return;
    }
    //Prepare the new Node
    Node* newnode = newNode(newValue);
    newnode->next = prevnode->next;
    newnode->prev = prevnode;

    if(prevnode->next != NULL) {
        prevnode->next->prev = newnode;
    }

    prevnode->next = newnode;
}

//Delete a node
void DeleteNode(Node** head, int Target) {
    //check if list is empty
    if(*head == NULL) {
        cout<<"List is empty! cannot delete anything!"<<endl;
        return;
    }
    //if the head node contain the target
    if((*head)->value == Target) {
        Node* temp = *head;
        *head =(*head)->next;
        (*head)->prev = NULL;
        delete temp;
        return;
    }

    Node* previous = *head;
    Node* current = (*head)->next;

    //Traverse list to find target value
    while(current != NULL) {
        if(current->value == Target) {
            previous->next = current->next;
            if(current->next != NULL) {
                current->next->prev = previous;
                delete current;
            }
            return;
        }
        previous = current;
        current = current->next;
    }
}

//function to reverse the list to print it backwards
void reverse(Node* head) {
    //base case
    if(head == NULL) {
        return;
    }

    //print the list after head node
    reverse(head->next);
    cout<<head->value<<" ";
}



int main()
{
    //initialize node with a headNode
 Node* headNode = newNode(1);
 //Insert After
 InsertAfter(headNode, -1);
 //insert at the front of list
 InsertAttheFront(&headNode, 0);
 //insert at the end of list
 InsertAttheEnd(&headNode, 2);
 InsertAttheEnd(&headNode, 3);
 //delete a target in the list
 DeleteNode(&headNode, 2);
 //print the list
 Print_list(headNode);
 //print the list in reverse
 cout<<" "<<endl;
 cout<<"List in reverse: "<<endl;
 reverse(headNode);
    return 0;
}

