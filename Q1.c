//consider one header linked list where the header node and normal node contains the following information

// header node
//a. number of nodes
//b. average value of elements
//c. maximum difference of node value and average value
//d. minimum difference of node value and average value

//normal node
//a. node value or information
//b. difference of node value and average value [of header node]

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int diff;
    struct node *next;
};

struct header
{
    int num;
    int avg;
    int max;
    int min;
    struct node *next;
};

struct header *create_header()
{
    struct header *h = (struct header *)malloc(sizeof(struct header));
    h->num = 0;
    h->avg = 0;
    h->max = 0;
    h->min = 0;
    h->next = NULL;
    return h;
}

struct node *create_node(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->diff = 0;
    n->next = NULL;
    return n;
}

void insert_node(struct header *h, int data)
{
    struct node *n = create_node(data);
    struct node *temp = h->next;
    if (temp == NULL)
    {
        h->next = n;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    h->num++;
}

void display(struct header *h)
{
    struct node *temp = h->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("  num = %d", h->num);
    printf("  avg = %d", h->avg);
    printf("  max = %d", h->max);
    printf("  min = %d", h->min);
    printf(" diff = %d", h->max - h->min);

}

void calculate(struct header *h)
{
    struct node *temp = h->next;
    int sum = 0;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    h->avg = sum / h->num;
    temp = h->next;
    while (temp != NULL)
    {
        temp->diff = temp->data - h->avg;
        if (temp->diff > h->max)
        {
            h->max = temp->diff;
        }
        if (temp->diff < h->min)
        {
            h->min = temp->diff;
        }
        temp = temp->next;
    }
}

int main()
{
    struct header *h = create_header();
    insert_node(h, 10);
    insert_node(h, 20);
    insert_node(h, 30);
    insert_node(h, 40);
    insert_node(h, 50);
    insert_node(h, 60);
    insert_node(h, 70);
    insert_node(h, 80);
    insert_node(h, 90);
    insert_node(h, 100);
    display(h);
    calculate(h);
    printf(" num = %d", h->num);
    printf(" avg = %d", h->avg);
    printf(" max = %d", h->max);
    printf(" min = %d", h->min);
    printf(" diff = %d", h->max - h->min);
    return 0;
}
