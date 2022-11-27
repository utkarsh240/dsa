//consider one header linked list where the header node and normal node contains the following information

// header node
//a. number of nodes
//b. average value of elements
//c. maximum difference of node value and average value
//d. minimum difference of node value and average value

//normal node
//a. node value or information
//b. difference of node value and average value [of header node]

// wap which will take n node information only. and after taking n integer inputs it will prepare the normal node's part b and header node's all part [a,b,c,d]. display the linked list.

#include <stdio.h>

struct node
{
    int info;
    int diff;
    struct node *next;
};

struct header
{
    int no_of_nodes;
    int avg;
    int max_diff;
    int min_diff;
    struct node *next;
};

void main() {
    int n, i, sum = 0, avg, max_diff, min_diff;
    struct header *h;
    struct node *p, *q;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    h = (struct header *) malloc(sizeof(struct header));
    h->no_of_nodes = n;
    h->next = NULL;

    printf("Enter the node information: ");
    for (i = 0; i < n; i++) {
        p = (struct node *) malloc(sizeof(struct node));
        scanf("%d", &p->info);
        sum += p->info;
        p->next = NULL;

        if (h->next == NULL) {
            h->next = p;
        } else {
            q->next = p;
        }
        q = p;
    }

    avg = sum / n;
    h->avg = avg;

    p = h->next;
    max_diff = p->info - avg;
    min_diff = p->info - avg;
    while (p != NULL) {
        p->diff = p->info - avg;
        if (p->diff > max_diff) {
            max_diff = p->diff;
        }
        if (p->diff < min_diff) {
            min_diff = p->diff;
        }
        p = p->next;
    }

    h->max_diff = max_diff;
    h->min_diff = min_diff;

    printf(" Header node information: ");
    printf(" Number of nodes: %d", h->no_of_nodes);
    printf(" Average value of elements: %d", h->avg);
    printf(" Maximum difference of node value and average value: %d", h->max_diff);
    printf(" Minimum difference of node value and average value: %d", h->min_diff);

    printf(" Normal node information: ");
    p = h->next;
    while (p != NULL) {
        printf(" Node value: %d", p->info);
        printf(" Difference of node value and average value: %d", p->diff);
        p = p->next;
    }

}
