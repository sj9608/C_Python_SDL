#include <stdio.h>
#include <malloc.h>

typedef struct _node
{
    int number;
    struct _node *p_next;
} NODE;

int main()
{
    NODE *pHead = NULL;

    pHead = (NODE *)malloc(sizeof(NODE));
    pHead->number = 12;
    pHead->p_next = NULL;

    // addition
    {
        NODE *p = pHead;
        while (p->p_next != NULL)
        {
            p = p->p_next;
        }
        p->p_next = (NODE *)malloc(sizeof(NODE));
        p = p->p_next;
        p->number = 13;
        p->p_next = NULL;
    }

    {
        NODE *p = pHead;
        while (p->p_next != NULL)
        {
            p = p->p_next;
        }
        p->p_next = (NODE *)malloc(sizeof(NODE));
        p = p->p_next;
        p->number = 14;
        p->p_next = NULL;
    }

    {
        NODE *p = pHead;
        while (p->p_next != NULL)
        {
            p = p->p_next;
        }
        p->p_next = (NODE *)malloc(sizeof(NODE));
        p = p->p_next;
        p->number = 15;
        p->p_next = NULL;
    }

    {
        NODE *p = pHead;
        while (p->p_next != NULL)
        {
            p = p->p_next;
        }
        p->p_next = (NODE *)malloc(sizeof(NODE));
        p = p->p_next;
        p->number = 16;
        p->p_next = NULL;
    }
    // 순회
    {
        NODE *p = pHead;

        while (p != NULL)
        {
            printf("%d \n", p->number);
            p = p->p_next;
        }
    }

    // del node
    {
        NODE *p = pHead;

        while (p != NULL)
        {
            printf("free %d \n", p->number);
            NODE *p_next = p->p_next;
            free(p);
            p = p_next;
        }
    }

    // // delete "x"
    // {
    //     NODE *p = pHead;
    //     NODE *_p_pre;
    //     NODE *_p_next;

    //     while (p != NULL)
    //     {
    //         _p_next = p->p_next;
    //         if (p->number == 13)
    //         {
    //             printf("find : %d \n", p->number);
    //             _p_pre->p_next = _p_next;
    //             free(p);
    //             break;
    //         }
    //         _p_pre = p;
    //         p = p->p_next;
    //     }
    // }

    //pop
    NODE *p = pHead;
    NODE *_p_pre = NULL;

    // get Tail
    while (p->p_next != NULL)
    {
        _p_pre = p;
        p = p->p_next;
    }
    printf("pop : %d \n",p->number);
    free(p);
    _p_pre->p_next = NULL;

    // del first
    {
        NODE *p = pHead;
        NODE *_p_next = p->p_next;

        printf("del : %d\n", p->number);
        free(p);
        pHead = _p_next;
    }
    return 0;
}