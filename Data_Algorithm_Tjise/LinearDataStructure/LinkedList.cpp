//
// Created by Hasaker on 2018/10/23.
//

#include "LinearDataStructure.h"

Status InitList_SL(SinglyLinkedList &SL) {
    /**
     * Create the head Node of the Singly Linked List
     */
    if ((SL = (SLNode *) malloc((sizeof(SLNode)))) == nullptr)
        return OVERFLOW;
    SL->next = nullptr;

    return OK;
}


Status DestoryList_SL(SinglyLinkedList &SL) {
    SL->next = nullptr;
    free(SL);

    return OK;
}


Status ClearList_SL(SinglyLinkedList &SL) {
    SL->next = nullptr;

    return OK;
}


Status ListEmpty_SL(SinglyLinkedList SL) {
    return SL->next == nullptr;
}


int ListLength_SL(SinglyLinkedList SL) {
    int length = 0;
    while (SL->next != nullptr) {
        SL = SL->next;
        length++;
    }

    return length;
}


Status OutList_SL(SinglyLinkedList SL) {
    if (SL->next == nullptr) {
        printf("This is a empty linked list ! ");
    } else {
        while (SL->next != nullptr) {
            SL = SL->next;
            printf("%d ", SL->data);
        }
    }
    printf("\n");

    return OK;
}


SLNode * Search_SL(SinglyLinkedList SL, ElementType e) {
    while (SL->data != e)
        SL = SL->next;
    if (SL->data == e)
        return SL;
    else
        return nullptr;
}


SLNode * NextElement_SL(SLNode * p) {
    if (p == nullptr)
        return nullptr;
    return p->next;
}


SLNode * MakeNode_SL(ElementType e) {
    /**
     * Create a SLNode with element e
     * @arg e an Integer
     * @return a SLNode with element e and NULL next
     */
    SLNode * p;
    p = (SLNode *) malloc(sizeof(SLNode));
    if (p != nullptr) {
        p->data = e;
        p->next = nullptr;
    }

    return p;
}


Status InsertAfter_SL(SLNode * node, SLNode * insert) {
    if (node == nullptr || insert == nullptr)
        return ERROR;
    insert->next = node->next;
    node->next = insert;

    return OK;
}


Status DeleteAfter_SL(SLNode * node, ElementType &e) {
    if (node == nullptr || node->next == nullptr)
        return ERROR;
    else {
        e = node->next->data;
        node->next = node->next->next;

        return OK;
    }
}


Status ListInsert_SL(SinglyLinkedList &SL, int i, ElementType e){
    /**
     * Insert e before i in SL
     * @arg SL a SNL
     * @arg i the address to be inserted
     * @arg e the integer to be inserted
     * @return return OK if success else ERROR
     */
    SLNode * node = SL;
    for (int j = 1; j < i; ++j) {
        node = node->next;
    }
    if (node == nullptr) {
        return ERROR;
    } else
        InsertAfter_SL(node, MakeNode_SL(e));

    return OK;
}


Status ListDelete_SL(SinglyLinkedList &SL, int i, ElementType &e) {
    /**
     * Delete the ith element in SL
     * Assignment the value deleted to e
     * @arg i the address to be inserted
     * @arg e the deleted element
     */

    if (SL->next == nullptr) {
        return ERROR;
    } else {
        SLNode * deleteNode = SL;
        for (int j = 1; j < i; ++j) {
            deleteNode = deleteNode->next;
        }
        DeleteAfter_SL(deleteNode, e);

        return OK;
    }
}


Status CreateList_SL(SinglyLinkedList &SL) {
    /**
     * Create a Singly Linked List
     * n: the length of the linked list
     */
    SLNode * tail, * tempNode;
    int n;
    ElementType element;

    if (InitList_SL(SL) == OVERFLOW) return OVERFLOW;
    tail = SL;

    printf("请输入要创建的链表的长度: ");
    scanf("%d", &n);
    printf("请输入%d个整数: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        tempNode = MakeNode_SL(element);
        InsertAfter_SL(tail, tempNode);
        tail = tempNode;
    }

    return OK;
}


void ListTraverse_SL(SinglyLinkedList SL, Status (* visit) (ElementType e)) {

}


void InverseList_SL(SinglyLinkedList SL) {
    /**
     * Inverse a Singly Linked List Which has a head Node
     */
    SLNode * p, * q;
    if (SL->next == nullptr || SL->next->next == nullptr)
        return;
    p = SL->next;
    SL->next = nullptr;
    while (p != nullptr) {
        q = p->next;
        InsertAfter_SL(SL, p);
        p = q;
    }
}


void MergeList_SL(SinglyLinkedList &SLa, SinglyLinkedList &SLb, SinglyLinkedList &SLc) {
    SinglyLinkedList pa, pb, pc, temp;
    pa = SLa->next;
    pb = SLb->next;
    SLc = pc = pa;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            temp = pa->next;
            InsertAfter_SL(pc, pa);
            pc = pa;
            pa = temp;
        } else {
            temp = pb->next;
            InsertAfter_SL(pc, pb);
            pc = pb;
            pb = temp;
        }
    }
    pc->next = pa ? pa : pb;
    free(SLb);
}