#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void *insertAtHead(Node**root, int d1)
{
    Node *node1 = createNode(d1);
    node1->next = *root;
    *root = node1;
}

Node* reverseLL(Node*root){
    if(root == NULL){
        return NULL;
    }
    if(root->next == NULL){
        return root;
    }
    Node* extra = reverseLL(root->next);
    root->next->next = root;
    root->next = NULL;
    return extra;
}

void traverse(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    traverse(head);
    head = reverseLL(head);
    traverse(head);
}