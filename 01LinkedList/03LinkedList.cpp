// A complete working C++ program to demonstrate
// all insertion methods on Linked List
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
public:
    int data;
    Node *next;
};

/* Given a reference (pointer to pointer) to the head of
a list and an int, inserts a new node on the front of the list. */
void push(Node **head_ref, int new_data)
{

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(Node *prev_node, int new_data)
{

    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;

    // Make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // move the next of prev_node as new_node
    prev_node->next = new_node;
}

/* To insert a new element after a given element in the linked list */
void insertAfterElement(Node *head, int new_data, int element)
{

    Node *newNode = new Node();
    Node *temp = head;
    while (temp->data != element)
    {
        temp = temp->next;
    }

    newNode->data = new_data;
    newNode->next = temp->next;
    temp->next = newNode;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *temp = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    // If the Linked List is empty, then make the new node as head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Else traverse till the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Change the next of last node
    temp->next = new_node;
    return;
}

// This function prints contents of
// linked list starting from head
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    insertAfterElement(head, 5, 8);

    cout << "Created Linked list is: ";
    printList(head);

    return 0;
}