// wap which will take n node information only. and after taking n integer inputs it will prepare the normal node's part b and header node's all part [a,b,c,d]. display the linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node *create_linked_list(int n)
{
    struct node *head = NULL;
    struct node *temp = NULL;
    int data;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&data);
        if(head == NULL)
        {
            head = create_node(data);
            temp = head;
        }
        else
        {
            temp->next = create_node(data);
            temp = temp->next;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    struct node *head = create_linked_list(n);
    display(head);
    return 0;
}
