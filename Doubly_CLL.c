////////////////////////////////////////////////////////////////////////////////////////
// 
// These file conatains source code of doubly circular Linked list 
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
    PNODE newn = (struct node *)malloc(sizeof(NODE));
    newn->Data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*head) == NULL && (*tail) == NULL)
    {
        (*head) = newn;
        (*tail) = newn;
        (*head)->next = newn;
        (*tail)->next = newn;
    }
    else if ((*head) == (*tail))
    {
        newn->next = (*head);
        (*head) = newn;
        (*head)->prev = (*tail);
        (*tail)->next = newn;
        (*tail)->prev = newn;
    }
    else
    {
        newn->next = (*head);
        (*head)->prev = newn;
        (*head) = newn;
        newn->prev = (*tail);
        (*tail)->next = newn;
    }
}

void InsertLast(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newn = (struct node *)malloc(sizeof(NODE));
    newn->Data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*head) == NULL && (*tail) == NULL)
    {
        (*head) = newn;
        (*tail) = newn;
        (*head)->next = newn;
        (*tail)->next = newn;
    }
    else if ((*head) == (*tail))
    {
        (*tail)->next = newn;
        (*tail) = newn;
        newn->next = (*head);
        newn->prev = (*head);
        (*head)->prev = newn;
    }
    else
    {
        (*tail)->next = newn;
        newn->next = (*head);
        newn->prev = (*tail);
        (*tail) = newn;
        (*head)->prev = newn;
    }
}

void InsertAtPos(PPNODE head, PPNODE tail, int iNo, int iPos)
{
    int Size = Count((*head), (*tail));

    if (iPos < 0 && iPos > (Size + 1))
    {
        printf("Invalid Number\n");
        return;
    }
    else if (iPos == 1)
    {
        InsertFirst(head, tail, iNo);
    }
    else if (iPos == (Size + 1))
    {
        InsertLast(head, tail, iNo);
    }
    else
    {
        PNODE newn = (struct node *)malloc(sizeof(NODE));
        newn->Data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = *head;
        int i = 0;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;
        newn->next->prev = newn;
    }
}

void DeleteFirst(PPNODE head, PPNODE tail)
{
    if ((*head) == NULL && (*tail) == NULL)
    {
        return;
    }
    else if ((*head) == (*tail))
    {
        free(*head);
        (*head) = NULL;
        (*tail) = NULL;
    }
    else
    {
        (*head) = (*head)->next;
        free((*head)->prev);
        (*head)->prev = (*tail);
        (*tail)->next = (*head);
    }
}

void DeleteLast(PPNODE head, PPNODE tail)
{
    if ((*head) == NULL && (*tail) == NULL)
    {
        return;
    }
    else if ((*head) == (*tail))
    {
        free(*head);
        (*head) = NULL;
        (*tail) = NULL;
    }
    else
    {
        (*tail)->prev->next = (*head);
        (*tail) = (*tail)->prev;
        free((*head)->prev);
        (*head)->prev = *tail;
    }
}

void DeleteAtPos(PPNODE head, PPNODE tail, int iPos)
{
    int Size = Count((*head), (*tail));

    if (iPos < 0 && iPos > (Size))
    {
        printf("Invalid Number\n");
        return;
    }
    else if (iPos == 1)
    {
        DeleteFirst(head, tail);
    }
    else if (iPos == (Size))
    {
        DeleteLast(head, tail);
    }
    else
    {
        PNODE temp = *head;
        int i = 0;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        PNODE tempdelete = temp->next;
        temp->next = temp->next->next;
        free(tempdelete);
        temp->next->prev=temp;
    }
}

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;
    int iret = 0;

    InsertFirst(&First, &Last, 51);
    InsertFirst(&First, &Last, 21);
    InsertFirst(&First, &Last, 11);
    Display(First, Last);
    iret = Count(First, Last);
    printf("Number of nodes are  -> %d\n ", iret);

    InsertLast(&First, &Last, 101);
    InsertLast(&First, &Last, 121);
    InsertLast(&First, &Last, 151);
    Display(First, Last);
    iret = Count(First, Last);
    printf("Number of nodes are  -> %d\n ", iret);

    DeleteLast(&First, &Last);
    DeleteLast(&First, &Last);
    Display(First, Last);
    iret = Count(First, Last);
    printf("Number of nodes are  -> %d\n ", iret);

    DeleteFirst(&First, &Last);
    DeleteFirst(&First, &Last);
    Display(First, Last);
    iret = Count(First, Last);
    printf("Number of nodes are  -> %d\n ", iret);

    InsertAtPos(&First, &Last, 1, 1);
    InsertAtPos(&First, &Last, 121, 4);
    InsertAtPos(&First, &Last, 71, 3);

    Display(First, Last);
    iret = Count(First, Last);
    printf("Number of nodes are  -> %d\n ", iret);

    DeleteAtPos(&First, &Last, 1);
    DeleteAtPos(&First, &Last, 4);
    DeleteAtPos(&First, &Last, 2);
    Display(First, Last);
    iret = Count(First, Last);
    printf("Number of nodes are  -> %d\n ", iret);

    return 0;
}