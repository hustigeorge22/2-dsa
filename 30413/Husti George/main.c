#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

list *prim=NULL;
list *last=NULL;

void AL(int x)
{
    if(prim==NULL)
    {
        prim=malloc(sizeof(list));
        prim->data=x;
        prim->next=NULL;
        last=prim;
    }
    else
    {
        list *newelement=malloc(sizeof(list));
        newelement->data=x;
        newelement->next=NULL;
        last->next=newelement;
        last=newelement;
    }
}

void AF(int x)
{
    if(prim==NULL)
    {
        prim=malloc(sizeof(list));
        prim->data=x;
        prim->next=NULL;
        last=prim;
    }
    else
    {
        list *newelement=malloc(sizeof(list));
        newelement->data=x;
        newelement->next=prim;
        prim=newelement;

    }
}

void DF(void)
{
    if(prim==NULL)
    {
        return;
    }
    else
    {
        list *newelemet=prim;
        prim=prim->next;
        if(prim==NULL)
        {
            last=prim;
        }
        else
            free(newelemet);

    }

}

void DL(void)
{
    if(last==NULL)
    {
        return;
    }
    else
    {
        if(prim==last)
        {
            free(last);
            prim=last=NULL;
            return;
        }
        list* newelement=prim;
        while(newelement->next->next)
        {
            newelement=newelement->next;
        }
        last=newelement;
        newelement=newelement->next;
        last->next=NULL;
        free(newelement);
    }
}

void DOOM_THE_LIST(void)
{
    if(prim==NULL)
    {
        return;
    }
    else
    {
        list *newelement=prim;
        while(newelement)
        {
            prim=prim->next;
            free(newelement);
            newelement=prim;
        }
    }
    last=NULL;
}

void DE (int x)
{
    if(prim == NULL)
    {
        return;
    }
    else
    {
        list * newelement=prim;
        while(prim&&prim->data==x)
        {
            newelement=prim;
            prim=prim->next;
            free(newelement);
        }
        newelement=prim;
        if(!newelement)
        {
            last=prim;
        }
        else
            while(newelement->next)
            {
                if(newelement->next->data==x)
                {
                    list *q=newelement->next;
                    newelement->next=q->next;
                    free(q);
                }
                else
                    newelement=newelement->next;
            }
    }
}

void PRINT_ALL()
{
    list * newelement=prim;
    while (newelement)
    {
        printf("%d ",newelement->data);
        newelement=newelement->next;
    }
    printf("\n");
}

void PRINT_F(int data)
{
    list *newelement=prim;
    while (newelement && data--)
    {
        printf("%d ",newelement->data);
        newelement=newelement->next;
    }
    printf("\n");
}

int ElCount()
{
    list *newelement=prim;
    int i=0;
    while (newelement)
    {
        newelement=newelement->next;
        ++i;
    }
    return i;
}

void PRINT_L(int data)
{
    int nr=ElCount();
    if(data>nr)
    {
        PRINT_ALL();
    }
    else
    {
        list *newelement=prim;
        for(int i=0; i<nr-data; ++i)
        {
            newelement=newelement->next;
        }
        while(newelement)
        {
            printf("%d ",newelement->data);
            newelement=newelement->next;

        }
    }
    printf("\n");

}


int main()
{
    AF (5);
    AF (6);
    AF (21);
    AL (12);
    DF();
    DL();
    DE (3);
    DE (6);
    AF (2);
    AL (200);
    PRINT_ALL();
    AF (1);
    PRINT_F (2);
    PRINT_L (3);
    DOOM_THE_LIST();
    DL();
    AF (42);
    AL (24);
    AF (9);
    PRINT_ALL();
    PRINT_L (2);

    return 0;

}
