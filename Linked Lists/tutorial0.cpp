#include <iostream>

using std::cout;
using std::string;
using std::cin;
using std::endl;

//linked list node
struct Node{
    int data;
    struct Node* next;
};
                    /*        INSERTION          */
/*
    (head)2 -> 3 -> 4 -> 5(tail)
    push(1) on the beginning

    1. create a new node (1)
    2. set data of this node
    3. 1 must point at the current head (id. 2)
    4. Now we set 1 as a new head
*/
void pushOnBeginning(struct Node** head, int node_data){
    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->next = (*head);
    (*head) = newNode;
}

/*
    (head)2 -> 4 -> 5 -> 6(tail)
    push (3) after (2)
    1. check if 2 even exists
    2. 3's next is set to the current 2's next
    3. 2's (previous') next is set to the current

*/
void insertAfter(struct Node* previous, int node_data){
    if(previous == NULL){
        cout << "no previous node\n";
        return;
    }
    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->next = previous->next;
    previous->next = newNode;

    
}
/*
    (head)2 -> 3 -> 4 -> 5(last/tail)
    append (6)

    1. create new node
    2. last = head -> not quitly, but it will change
    3. set data of new node and its next to null
    4. if list is empty -> head becomes that new Node
    5. does the last (at the beginning head(2)) point to nothing?
        if not: last becomes the next element of whatever it is assigned
                to it at this time
                example:
                at the beginning last = head [last: 2]
                2 points to 3 so it doesn't point to null
                last = 3
                3 points to 4 -> last = 4
                4 points to 5 -> last = 5
                5 points to null -> stop it, 5 is the last element
        repeat until condition is met
*/
void append(struct Node** head, int node_data){
    struct Node* newNode = new Node;
    struct Node* last = *head;

    newNode->data = node_data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    
    last->next = newNode;
    return;
}

                    /*        DELETION          */

/*
    how to delete first node:
    1) no head - no deletion - return NULL
    2) create temporary Node to store head address 
    3) now the next element will be the head
    4) delete tempNode that stores original head
    5) return head
*/
Node* deleteFirstNode(struct Node* head){
    if(head == NULL)
        return NULL;

    Node* tempNode = head;
    head = head->next;
    delete tempNode;

    return head;    
}
/*
    1-2-3-4-5-6
    1) no head - no deletion - return null
    2) only one element = delete that element and return null 
    3) if at least 2 elements (there is somewhere a second last element):
        repeat if next -> next isn't null (it's not really a second last):
            make the next node a possible second_last
        If we have a second last, then we have a last node
    4) Delete last node (second_last->next)
    5) second last must now point to the NULL

*/
Node* removeLastNode(struct Node* head){
    // no head??:(
    if(head == NULL)
        return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* second_last = head;
    while(second_last->next->next != NULL)
        second_last = second_last->next;
    
    delete(second_last->next);
    second_last->next = NULL;
    
    return head;
}
void displayList (struct Node* node){
    while(node!= NULL){
        cout << node->data << "-->";
        node = node->next;
    }
    if(node==NULL)
        cout << "null";
}
int main(){
    struct Node* head = NULL;

    append(&head, 10); // 10
    pushOnBeginning(&head, 20); // 20 -> 10
    pushOnBeginning(&head, 30); // 30 -> 20 -> 10
    append(&head, 40); // 30 -> 20 -> 10 -> 40
    cout << "head's value is: " << head->data <<endl; // 30
    insertAfter(head->next, 50); // add 50 after next node after head 
                                // 30 -> 20 -> 50 -> 10 -> 40
    //I can also do this magic trick because (head->next is already an object of type Node)
    insertAfter(head->next->next->next->next,69);
    //if I add way more next than it exists -> boohoo compiler mad 
    displayList(head);
    /*              Deletion        */
    cout << endl;
    cout << "deleting first node:\n";
    head = deleteFirstNode(head);
    displayList(head);
    cout << endl;

    head = removeLastNode(head);
    cout << "deleting last node:\n";
    displayList(head);
    cout << endl;
    return 0;
}