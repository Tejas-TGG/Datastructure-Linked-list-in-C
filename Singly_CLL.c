////////////////////////////////////////////////////////////////////////////////////////
// 
// These file conatains source code of singly circular Linked list 
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
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE head, PNODE tail)
{
    PNODE temp = head;

    printf("Elements of linked list are :\n");

    if ((head == NULL) && (tail == NULL))
    {
        printf("->NULL");
        return;
    }
    else
    {
        do
        {
            printf("%d ->", temp->Data);
            temp = temp->next;

        } while (temp != (tail->next));
    }

    printf("NULL\n");
}

int Count(PNODE head, PNODE tail)
{
    PNODE temp = head;
    int iCount = 0;

    if ((head == NULL) && (tail == NULL))
    {
        return 0;
    }
    else
    {
        do
        {
            iCount++;
            temp = temp->next;

        } while (temp != (tail->next));
    }

    return iCount;
}

void InsertFirst(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newn = (NODE *)malloc(sizeof(NODE));
    newn->Data = iNo;
    newn->next = NULL;

    if ((*head) == NULL && (*tail) == NULL)
    {
        *head = newn;
        *tail = newn;
        newn->next = *head;
    }
    else
    {
        newn->next = *head;
        *head = newn;
        (*tail)->next = newn;
    }
}

void InsertLast(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newn = (NODE *)malloc(sizeof(NODE));
    newn->Data = iNo;
    newn->next = NULL;

    if ((*head) == NULL && (*tail) == NULL)
    {
        *head = newn;
        *tail = newn;
        newn->next = *head;
    }
    else
    {
        newn->next = *head;
        (*tail)->next = newn;
        (*tail) = newn;
    }
}

void InsertAtPos(PPNODE head, PPNODE tail, int iNo, int ipos)
{
    int Size = Count(*head, *tail);

    if (ipos < 1 && ipos > (Size + 1))
    {
        return;
    }
    else if (ipos == 1)
    {
        InsertFirst(head, tail, iNo);
    }
    else if (ipos == (Size + 1))
    {
        InsertLast(head, tail, iNo);
    }
    else
    {
        PNODE Newn = (NODE *)malloc(sizeof(NODE));
        Newn->Data = iNo;
        Newn->next = NULL;

        PNODE temp = *head;

        int i = 0;

        for (i = 1; i < (ipos - 1); i++)
        {
            temp = temp->next;
        }
        Newn->next = temp->next;
        temp->next = Newn;
    }
}

void DeleteFirst(PPNODE head, PPNODE tail)
{
    if ((*head) == NULL && (*tail) == NULL)
    {
        return;
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        PNODE tempdelete = (*head);

        *head = (*head)->next;
        (*tail)->next = *head;
        free(tempdelete);
    }
}

void Deletelast(PPNODE head, PPNODE tail)
{
    if ((*head) == NULL && (*tail) == NULL)
    {
        return;
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        PNODE temp = *head;
        while (temp->next != *tail)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = *head;
        *tail = temp;
    }
}

void DeleteAtPos(PPNODE head, PPNODE tail, int ipos)
{
    int Size = Count(*head, *tail);

    if (ipos < 1 && ipos > (Size))
    {
        return;
    }
    else if (ipos == 1 )
    {
        DeleteFirst(head, tail);
    }
    else if (ipos == (Size))
    {
        Deletelast(head, tail);
    }
    else
    {
        PNODE temp = *head;

        int i = 0;

        for (i = 1; i < (ipos - 1); i++)
        {
            temp = temp->next;
        }

        PNODE tempdelete = temp->next;

        temp->next = temp->next->next;
        free(tempdelete);
    }
}

int main()
{
    int iret = 0;
    PNODE first = NULL;
    PNODE last = NULL;

    InsertFirst(&first, &last, 51);
    InsertFirst(&first, &last, 21);
    InsertFirst(&first, &last, 11);

    Display(first, last);
    iret = Count(first, last);
    printf("Number of nodes are  -> %d \n", iret);

    InsertLast(&first, &last, 101);
    InsertLast(&first, &last, 121);
    InsertLast(&first, &last, 151);

    Display(first, last);
    iret = Count(first, last);
    printf("Number of nodes are  -> %d \n", iret);

    DeleteFirst(&first, &last);
    DeleteFirst(&first, &last);

    Display(first, last);
    iret = Count(first, last);
    printf("Number of nodes are  -> %d\n", iret);

    Deletelast(&first, &last);
    Deletelast(&first, &last);

    Display(first, last);
    iret = Count(first, last);
    printf("Number of nodes are  -> %d\n", iret);

    InsertAtPos(&first, &last, 1, 1);
    InsertAtPos(&first, &last, 121, 4);
    InsertAtPos(&first, &last, 151, 5);
    InsertAtPos(&first, &last, 71, 3);
    InsertAtPos(&first, &last, 91, 4);

    Display(first, last);
    iret = Count(first, last);
    printf("Number of nodes are  -> %d\n ", iret);

    DeleteAtPos(&first, &last, 1);
    DeleteAtPos(&first,&last,6);
    DeleteAtPos(&first,&last,3);

    Display(first, last);
    iret = Count(first, last);
    printf("Number of nodes are  -> %d\n ", iret);

    return 0;
}