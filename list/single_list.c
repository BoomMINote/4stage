#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}*linklist,node;
node *head = NULL;
node *tail = NULL;
int insert(linklist l,int data)
{
    if(l==NULL)
    {
        printf("%p",l);
        node* cur = (node*)malloc(sizeof(node));
        cur->data = data;
        cur->next = NULL;
        head = cur;
        tail = cur;
        printf("%p",head);
        printf("---\n");
        return 1;
    }
    else
    {
        node* cur = (node*)malloc(sizeof(node));
        cur->data = data;
        cur->next = NULL;
        tail->next = cur;
        tail = tail->next;
        printf("aa\n");
    }
    return 1;
}
int traverse()
{
    node* p = head;
    while(p->next!=NULL)
    {
        printf("%d->",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
    return 0;
}
int main()
{
    linklist l = head;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,5);
    traverse();
    return 0;
}
