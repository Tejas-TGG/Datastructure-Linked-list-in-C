////////////////////////////////////////////////////////////////////////////////////////
// 
// These file conatains source code of singly linear Linked list 
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
    PNODE Newn = (NODE *)malloc(sizeof(NODE));
    Newn->Data = iNo;
    Newn->next = NULL;

    if ((*head) == NULL)
    {
        (*head) = Newn;
    }
    else
    {
        Newn->next = (*head);
        (*head) = Newn;
    }
}

void InsertLast(PPNODE head, int iNo)
{
    PNODE Newn = (NODE *)malloc(sizeof(NODE));
    Newn->Data = iNo;
    Newn->next = NULL;

    if ((*head) == NULL)
    {
        (*head) = Newn;
    }
    else
    {
        PNODE temp = (*head);

        while ((temp->next) != NULL)
        {
            temp = temp->next;
        }
        temp->next = Newn;
    }
}

void InsertAtPos(PPNODE head, int ino, int ipos)
{
    int Size = Count((*head));

    if (ipos < 1 && ipos > (Size + 1))
    {
        return;
    }
    else if (ipos == 1)
    {
        InsertFirst(head, ino);
    }
    else if (ipos == (Size + 1))
    {
        InsertLast(head, ino);
    }
    else
    {
        PNODE Newn = (NODE *)malloc(sizeof(NODE));
        Newn->Data = ino;
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

void DeleteFirst(PPNODE head)
{

    if ((*head) == NULL)
    {
        return;
    }
    else
    {
        PNODE tempdelete = *head;

        (*head) = (*head)->next;

        free(tempdelete);
    }
}

void Deletelast(PPNODE head)
{
    if ((*head) == NULL)
    {
        return;
    }
    else
    {
        PNODE temp = (*head);

        while ((temp->next->next) != NULL)
        {
            temp = temp->next;
        }
        PNODE tempdelete = temp->next;
        temp->next = NULL;
        free(tempdelete);
    }
}

void DeleteAtPos(PPNODE head, int ipos)
{
    int Size = Count((*head));

    if (ipos < 1 && ipos > (Size ))
    {
        return;
    }
    else if (ipos == 1)
    {
        DeleteFirst(head);
    }
    else if (ipos == (Size))
    {
        Deletelast(head);
    }
    else
    {
        
        PNODE temp = *head;

        int i = 0;

        for (i = 1; i < (ipos - 1); i++)
        {
            temp = temp->next;
        }
        PNODE tempdelete=temp->next;
        temp->next=temp->next->next;
        free(tempdelete);
        
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

    InsertLast(&first, 101);
    InsertLast(&first, 121);
    InsertLast(&first, 151);
    Display(first);
    iret = Count(first);
    printf("Number of Node in LL are ->%d\n ", iret);

    DeleteFirst(&first);
    DeleteFirst(&first);
    Display(first);
    iret = Count(first);
    printf("Number of Node in LL are ->%d \n", iret);

    Deletelast(&first);
    Deletelast(&first);
    Display(first);
    iret = Count(first);
    printf("Number of Node in LL are ->%d \n", iret);

    InsertAtPos(&first, 1, 1);
    InsertAtPos(&first, 156, 4);
    InsertAtPos(&first, 21, 2);
    InsertAtPos(&first, 41, 3);
    InsertAtPos(&first, 71, 5);

    Display(first);
    iret = Count(first);
    printf("Number of Node in LL are ->%d \n", iret);


    DeleteAtPos(&first,1);
    DeleteAtPos(&first,6);
    DeleteAtPos(&first,3);
    DeleteAtPos(&first,2);
    Display(first);
    iret = Count(first);
    printf("Number of Node in LL are ->%d \n", iret);
    

    return 0;
}