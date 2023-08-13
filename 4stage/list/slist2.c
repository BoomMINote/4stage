#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
typedef struct linklist
{
    struct node* head;
    struct node* tail;
}*linklist;
void list_init(linklist l)
{
    l->head = NULL;
    l->tail = NULL;
}
void insert_tail(linklist l,int data)
{
    node *cur = (node*)malloc(sizeof(node));
    cur->next = NULL;
    cur->data = data;
    if(l->head == NULL)
    {
        l->head = cur;
        l->tail = cur;
    }
    else
    {
        l->tail->next = cur;
        l->tail = cur;
    }
    // printf("head:%p tail:%p\n",l->head,l->tail);
    return;
}
void insert_head(linklist l,int data)
{
    node *cur = (node*)malloc(sizeof(node));
    cur->data = data;
    cur->next = NULL;
    if(l->head == NULL)
    {
        l->head = cur;
        l->tail = cur;
    }
    else
    {
        cur->next = l->head;
        l->head = cur;
    }
    // printf("head:%p tail:%p\n",l->head,l->tail);
    return;
}
void traverse(linklist l)
{
    node* aux = l->head;
    while(aux->next!=NULL)
    {
        printf("%d->",aux->data);
        aux = aux->next;
    }
    printf("%d\n",aux->data);
}
void input(linklist l)
{
    int num;
    printf("input the number of nodes:");
    scanf("%d",&num);
    printf("input the insert method 0 for tail and 1 for head:");
    int method;
    scanf("%d",&method);
    if(method == 0)
    {
        while(num--)
        {
            int data;
            scanf("%d",&data);
            insert_tail(l,data);
        }
    }
    else
    {
        while(num--)
        {
            int data;
            scanf("%d",&data);
            insert_head(l,data);
        }
    }
    traverse(l);
}
void reverse_by_3pt(linklist l)
{
    //1->2->3->4->5
    //1<-2<-3<-4<-5
    if (l->head == NULL || l->head->next == NULL)return;
    else 
    {
        node* pre = l->head;
        node* cur = l->head->next;
        node* nex = cur->next;
        while(cur->next != NULL)
        {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        cur->next = pre;
        // l->head = cur;
        l->tail = l->head;
        l->tail->next = NULL;
        l->head = cur; 
    }
    return;
}
void reverse_by_insert_to_head_without_dummy(linklist l)
{
    if(l->head == NULL || l->head->next==NULL){return;}
    node* pre = l->head;
    node* p = pre->next;
    node* nex = p->next;
    pre->next = NULL;

    //swap head and tail
    node* tem = l->head;
    l->head = l->tail;
    l->tail = tem;

    while(p->next!=NULL)
    {
        p->next = pre;
        pre = p;
        p = nex;
        nex = nex->next;
    }
    p->next = pre;
    return;
}
void reverse_by_insert_to_head_with_dummy(linklist l)
{
    if(l->head == NULL || l->head->next==NULL)return;
    node *hd = (node*)malloc(sizeof(node));
    hd->next = NULL;

    node *pre = l->head;
    node *p = pre->next;
    //swap head and tail
    node* tmp = l->head;
    l->head = l->tail;
    l->tail = tmp;
    while(p!=NULL)
    {
        pre->next = hd->next;
        hd->next = pre;
        pre = p;
        p = p->next;
    }
    pre->next = hd->next;
    hd->next = pre;
    return;
}
node* reverse_by_recursion(node* hd)
{
    if(hd == NULL || hd->next == NULL) return hd;
    node* new_hd = reverse_by_recursion(hd->next);
    hd->next->next = hd;
    hd->next = NULL;
    return new_hd;
}
node* merge_two_ordered_linklist(linklist l1,linklist l2)
{
    if(l1->head == NULL && l2->head == NULL) return NULL;
    if(l1->head == NULL && l2->head != NULL) return l2->head;
    if(l1->head != NULL && l2->head == NULL) return l1->head;
    node *dummy,*tail,*p1,*p2,*p1n,*p2n;
    dummy = (node*)malloc(sizeof(node));
    dummy->next = NULL;
    tail = dummy;
    p1 = l1->head;
    p2 = l2->head;
    p1n = p1->next;
    p2n = p2->next;
    while(p1n!=NULL && p2n!=NULL)
    {   
        if(p1->data <= p2->data)
        {
            tail->next = p1;
            p1 = p1n;
            p1n = p1n->next; 
        }
        else
        {
            tail->next = p2;
            p2 = p2n;
            p2n = p2n->next;
        }
        tail = tail->next;
    }
    if(p1->data <= p2->data)
    {
        tail->next = p1;
        tail = tail->next;
        tail->next = p2;
    }
    else
    {
        tail->next = p2;
        tail = tail->next;
        tail->next = p1;
    }
    return dummy->next;
}
void check_is_huiwen(linklist ll)
{
    if(ll->head == NULL || ll->head->next==NULL){printf("huiwen\n");return;}
    int a[100] = {0};
    int id = 0;
    node*p = ll->head;
    while(p!=NULL)
    {
        a[id++]=p->data;
        p =p->next;
    }
    int l = 0,r = id - 1;
    while(l<=r)
    {
        if(a[l] != a[r])
        {
            printf("not huiwen\n");return;
        }
        else
        {
            l++,r--;
        }
    }
    printf("huiwen\n");return;
}
node* add_two_list(linklist l1,linklist l2)
{
    if(l1->head==NULL && l2->head==NULL)return NULL;
    if(l1->head==NULL && l2->head!=NULL)return l2->head;
    if(l1->head!=NULL && l2->head==NULL)return l1->head;
    node* nl1 = reverse_by_recursion(l1->head);
    node* nl2 = reverse_by_recursion(l2->head);
    node* dummy = (node*)malloc(sizeof(node));
    node* p1 = nl1;
    node* p2 = nl2;
    int carry = 0;
    while(p1!=NULL || p2!=NULL)
    {
        int a = p1==NULL?0:p1->data;
        int b = p2==NULL?0:p2->data;
        int sum = a+b+carry;
        carry = sum/10;
        node* cur = (node*)malloc(sizeof(node));
        cur->data = sum%10;
        cur->next = dummy->next;
        dummy->next = cur;
        p1 = p1==NULL?NULL:p1->next;
        p2 = p2==NULL?NULL:p2->next;
    }
    return dummy->next;
}
int main()
{
    
    // input(l1);
    // linklist l1 = (linklist)malloc(sizeof(struct linklist));
    // list_init(l1);
    // insert_tail(l1,1);
    // insert_tail(l1,2);
    // insert_tail(l1,1);
    // check_is_huiwen(l1);
    // insert_tail(l1,1);
    // check_is_huiwen(l1);
    // insert_head(l1,5);
    // insert_head(l1,6);
    // insert_head(l1,7);
    // traverse(l1);
    // reverse_by_3pt(l1);
    // traverse(l1);
    // reverse_by_insert_to_head_without_dummy(l1);
    // traverse(l1);
    // reverse_by_insert_to_head_with_dummy(l1);
    // traverse(l1);
    // node* newhd = reverse_by_recursion(l1->head);
    // l1->head = newhd;
    // traverse(l1);
    


    linklist l2 = (linklist)malloc(sizeof(struct linklist));
    linklist l3 = (linklist)malloc(sizeof(struct linklist));
    list_init(l2);list_init(l3);
    insert_tail(l2,1);
    insert_tail(l2,6);
    insert_tail(l2,6);
    insert_tail(l2,6);
    traverse(l2);
    insert_tail(l3,3);
    insert_tail(l3,3);
    insert_tail(l3,4);
    insert_tail(l3,4);
    insert_tail(l3,5);
    traverse(l3);
    // node *new_hd = merge_two_ordered_linklist(l2,l3);
    // l2->head = new_hd;
    // traverse(l2);
    node* new_hd = add_two_list(l2,l3);
    l2->head = new_hd;
    traverse(l2);
    return 0;
}
