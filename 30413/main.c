#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    struct list *next;
    struct list *previous;

} list;

list *first=NULL;
list *last=NULL;

void AF(int x)
{
    if(first == NULL)
    {
        first = (list*)malloc(sizeof(list));
        first->next = last;
        first->value = x;
        last = first;
    }
    else

    {
        list *NewElement=(malloc)(sizeof(list));
        NewElement->value=x;
        first->previous=NewElement;
        NewElement->next=first;
        NewElement->previous=NULL;
        first=NewElement;
    }
}

void AL(int x)
{
    if(first == NULL)
    {
        first =(list*)malloc(sizeof(list));
        first->next = last;
        first->value = x;
        last = first;
    }
    else

    {
        list *NewElement=malloc(sizeof(list));
        NewElement->value=x;
        last->next=NewElement;
        NewElement->previous=last;
        NewElement->next=NULL;
        last=NewElement;
    }
}

void DF(void)
{
    if(first==NULL)
    {
        return;
    }
    else
    {
        list *NewElement=first;
        first=first->next;
        if(first == NULL)
        {
            last=first;
        }
        free(NewElement);
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
        if(first==last)
        {
            free(first);
            first=last=NULL;
            return;
        }
        list *current=first;
        while(current->next->next)
        {
            current=current->next;
        }
        last=current;
        current=current->next;
        last->next=NULL;
        free(current);
    }
}

void DOOM_THE_LIST(void)
{
    if(first==NULL)
        return;
    else
    {
        list *current=first;
        while(first!=NULL)
        {
            first=first->next;
            free(current);
            current=first;
        }
    }
    last=NULL;
}

void DE(int x)
{
    if(first==NULL)
        return;
    else
    {
        list *current=first;
        while(first!=NULL&&first->value==x)
        {
            current=first;
            first=first->next;
            free(current);

        }

        current=first;
        if(!current)
        {
            last=first;
        }
        else
            while(current->next)
            {
                if(current->next->value==x)
                {
                    list *current2=current->next;
                    current->next=current2->next;
                    free(current2);
                }
                else
                    current=current->next;
            }
    }
}


void PRINT_ALL(void)
{
    list *current=first;
    while(current->next!=NULL)
    {
        printf("%d ",current->value);
        current=current->next;
    }
    printf("%d",current->value);
    printf("\n");
}

void PRINT_F(int x)
{
    list *current=first;
    while (current!=NULL && (x--)>0)
    {
       printf("%d ",current->value);
       current=current->next;
    }
    printf("\n");
}

int ElementCount()
{
    list *current=first;
    int i=0;
    while (current!=NULL)
    {
        current=current->next;
        i++;
    }
    return i;
}

void PRINT_L(int x)
{
    int nr=ElementCount();
    if(x>nr)
    {
        PRINT_ALL();
    } else
    {
        list *current=current;
        for(int i=0;i<nr-x;++i)
        {
            current=current->next;
        }
        while(current!=NULL)
        {
            printf("%d ",current->value);
            current=current->next;
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
    DF ();
    DL ();
    DE (3);
    DE (6);
    AF (2);
    AL (200);
    PRINT_ALL ();
    AF (1);
    PRINT_F (2);
    PRINT_L (3);
    DOOM_THE_LIST ();
    DL ();
    AF (42);
    AL(24);
    AF (9);
    PRINT_ALL ();
    PRINT_L (2);
    return 0;
}
