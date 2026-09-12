#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next ;
} ;

ListNode* insertNodeAtEnd(ListNode *head,int val){
    if(head==NULL){         //i fhead will be neull then create a new node and return it as head
        head= new ListNode ;
        head->data = val;        //assign the value to the new node
        head->next = NULL ;  // to save the next node address we will assign it to null as it is the last node.
        return head;
    }
    ListNode *itr = head ;
    while(itr->next!=NULL){
        itr= itr->next ;
    }
    itr->next = new ListNode ;
    itr= itr->next ;
    itr->data= val ;
    itr->next = nullptr ;
    return head ;
}

//Previously there we have written void deleteLast(ListNode *head, ListNode *end) but it is not a good approach because we have to pass the head and end pointer to the function. 
// So we will write a new function which will take only head pointer and return the new head pointer after deleting the last node.
ListNode* deleteNodeAtEnd(ListNode *head){ // changed: returns the updated head
    if(head == NULL){
        return NULL ;
    }

    if(head->next == NULL){ // if there is only one node in the linked list then we will delete it and return NULL as head pointer.
        delete head ;
        return NULL ;
    }

    ListNode *itr = head ;
    while(itr->next->next!=NULL){
        itr= itr->next ;
    }
    delete itr->next ; // delete the last node
    itr->next = NULL ;
    return head ;
}

void displayLinkedList(ListNode *head){
    ListNode *itr = head ;
    while(itr!=NULL){
        cout<<itr->data<<"->" ;
        itr= itr->next ;
    }
    cout<<"nullptr\n" ;
}

ListNode* insertNodeAtStart(ListNode *head, int val){
    ListNode *temp = new ListNode ;
    temp->data = val ;
    temp->next = NULL ;
    temp->next = head ;
    head = temp ;
    return head ;
}

ListNode* deleteNodeAtStart(ListNode *head){ // changed: returns the updated head
    if(head == NULL){ // if the head is null then return null because there is no node to delete
        return NULL ;
    }

    ListNode *temp = head ;
    head= head->next ;
    delete temp ; // here we need to delete temp(node) it might we case it is still pointing to the heap memory and we need to free it.
    return head ;
}


int main() 
{
    ListNode *head = NULL ;
    int n ;
    cin>>n ;
    int temp ;
    while(n--){
        cin>>temp ;
        head= insertNodeAtEnd(head, temp) ;
    }
    displayLinkedList(head) ;
    head = deleteNodeAtEnd(head); // in this line will save the updated head pointer after deelting the LAST node
    displayLinkedList(head) ;
    head = deleteNodeAtStart(head) ; // this line will save the updatd head pointer after deleting the FIRST node
    displayLinkedList(head) ;
    cout<<"Insert element-> " ;
    cin>>temp ;
    head = insertNodeAtStart(head, temp) ;
    displayLinkedList(head) ;
    return 0;
}


// WORKING OF THE CODE:
/*
 we created struct ListNode which contains two members data and next pointer.
 where data =  value of the node and next = pointer to the next node.
We created a function insertNodeAtEnd which takes head pointer and value as input and returns the
    updated head pointer after inserting the new node at the end of the linked list.
    then we created a function deleteNodeAtEnd which takes head pointer as input and returns the updated head pointer after deleting the last node of the linked list.
    then we created a function displayLinkedList which takes head pointer as input and displays the linked list.
    then we created a function insertNodeAtStart which takes head pointer and value as input and returns the updated head pointer after inserting the new node at the start of the linked list.
    then we created a function deleteNodeAtStart which takes head pointer as input and returns the updated head pointer after deleting the first node of the linked list.
*/