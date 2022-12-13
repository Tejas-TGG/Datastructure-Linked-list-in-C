////////////////////////////////////////////////////////////////////////////////////////
// 
// These file conatains source code of doubly linear Linked list 
// 
//  11 ->21 ->51 ->101 ->121 ->151 ->NULL
// 
// ////////////////////////////////////////////////////////////////////////////////////





#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE head)
{
    PNODE temp = head;

    while ((temp) != NULL)
    {
        printf("%d ->", (temp->Data));

        temp = temp->next;
    }

    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCount = 0;
    PNODE temp = head;

    while (temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }

    return iCount;
}

void InsertFirst(PPNODE head, int iNo)
{
    PNODE newn = (NODE *)malloc(sizeof(NODE));
    newn->next = NULL;
    newn->Data = iNo;
    newn->prev = NULL;

    if ((*head) == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
}

void Insertlast(PPNODE head, int iNo)
{
    PNODE newn = (NODE *)malloc(sizeof(NODE));
    newn->next = NULL;
    newn->Data = iNo;
    newn->prev = NULL;

    if ((*head) == NULL)
    {
        *head = newn;
    }
    else
    {
        PNODE temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

void InsertAtPos(PPNODE head, int iNo, int ipos)
{
    int Size = Count((*head));

    if (ipos < 1 && ipos > (Size + 1))
    {
        return;
    }
    else if (ipos == 1)
    {
        InsertFirst(head, iNo);
    }
    else if (ipos == (Size + 1))
    {
        Insertlast(head, iNo);
    }
    else
    {
        PNODE newn = (NODE *)malloc(sizeof(NODE));
        newn->next = NULL;
        newn->Data = iNo;
        newn->prev = NULL;

        PNODE temp = *head;
        int i = 0;
        for (i = 1; i < (ipos - 1); i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        newn->next->prev = newn;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE head)
{

    if ((*head) == NULL)
    {
        return;
    }
    else
    {
        PNODE tempdelete = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;

        free(tempdelete);
    }
}

void DeleteLast(PPNODE head)
{
    if ((*head) == NULL)
    {
        return;
    }
    else
    {
        PNODE temp = *head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE head, int ipos)
{
    int Size = Count((*head));

    if (ipos < 1 && ipos > (Size))
    {
        return;
    }
    else if (ipos == 1)
    {
        DeleteFirst(head);
    }
    else if (ipos == (Size))
    {
        DeleteLast(head);
    }
    else
    {

        PNODE temp = *head;

        int i = 0;

        for (i = 1; i < (ipos - 1); i++)
        {
            temp = temp->next;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
        
    }
}

int main()
{
    int iret = 0;
    PNODE first = NULL;
    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);
    Display(first);

    iret = Count(first);
    printf("Number of Node in LL are ->%d\n ", iret);

    Insertlast(&first, 101);
    Insertlast(&first, 121);
    Insertlast(&first, 151);

    Display(first);

    iret = Count(first);
    printf("Number of Node in LL are ->%d\n ", iret);

    DeleteFirst(&first);
    DeleteFirst(&first);
    Display(first);

    iret = Count(first);
    printf("Number of Node in LL are ->%d\n ", iret);

    DeleteLast(&first);
    DeleteLast(&first);

    Display(first);

    iret = Count(first);
    printf("Number of Node in LL are ->%d\n ", iret);

    InsertAtPos(&first, 1, 1);
    InsertAtPos(&first, 121, 4);
    InsertAtPos(&first, 31, 2);
    InsertAtPos(&first, 71, 4);
    Display(first);

    iret = Count(first);
    printf("Number of Node in LL are ->%d\n ", iret);


    DeleteAtPos(&first,1);
    DeleteAtPos(&first,5);
    DeleteAtPos(&first,3);

    Display(first);

    iret = Count(first);
    printf("Number of Node in LL are ->%d\n ", iret);


    return 0;
}