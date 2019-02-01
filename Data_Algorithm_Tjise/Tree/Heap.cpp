#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define OK 1
#define FALSE 0
#define ERROR 0

typedef int Status;
typedef int KeyType;

typedef struct {
    KeyType key;
} RecordType, RcdType;

typedef struct {
    RcdType *rcd;
    int length;
    int size;
} RcdSqList;

typedef struct {
    RcdType *rcd;
    int n;
    int size;
    int tag;
} Heap;


int greatPrior(KeyType x, KeyType y) {
    return x >= y;
}


int lessPrior(KeyType x, KeyType y) {
    return x <= y;
}


Status InitHeap(Heap &H, int size, int tag) {
    H.rcd = NULL;
    H.size = size;
    H.n = 0;
    H.tag = tag;

    return OK;
}

Status SwapHeapElem(Heap &H, int i, int j) {
    if (i <= 0 || i > H.n || j <= 0 || j > H.n) {
        return ERROR;
    }
    RcdType temp;
    temp = H.rcd[i];
    H.rcd[i] = H.rcd[j];
    H.rcd[j] = temp;

    return OK;
}

void ShiftDown(Heap &H, int pos) {
    int left, right;
    while (pos <= H.n / 2) {
        left = pos * 2;
        right = pos * 2 + 1;
        if (H.tag == 0) {
            if (!lessPrior(H.rcd[left].key, H.rcd[right].key)) {
                left = right;
            }
            if (lessPrior(H.rcd[pos].key, H.rcd[left].key)) {
                return;
            }
        } else {
            if (!greatPrior(H.rcd[left].key, H.rcd[right].key)) {
                left = right;
            }
            if (greatPrior(H.rcd[pos].key, H.rcd[left].key)) {
                return;
            }
        }
        SwapHeapElem(H, pos, left);
        pos = left;
    }
}


void MakeHeap(Heap &H, RcdType *E, int n, int size, int tag) {
    H.rcd = E;
    H.n = n;
    H.size = size;
    H.tag = tag;
    for (int i = n / 2; i > 0; i--) {
        ShiftDown(H, i);
    }
}


Status DestoryHeap(Heap &H) {
    free(H.rcd);
    H.rcd = NULL;
    H.n = 0;
    H.size = 0;

    return OK;
}


Status InsertHeap(Heap &H, RcdType e) {
    if (H.n >= H.size - 1) {
        return ERROR;
    }
    int cur = ++H.n;
    H.rcd[cur] = e;
    if (H.tag == 0) {
        while (cur != 1 && lessPrior(H.rcd[cur].key, H.rcd[cur / 2].key)) {
            SwapHeapElem(H, cur, cur / 2);
            cur /= 2;
        }
    } else {
        while (cur != 1 && greatPrior(H.rcd[cur].key, H.rcd[cur / 2].key)) {
            SwapHeapElem(H, cur, cur / 2);
            cur /= 2;
        }
    }

    return OK;
}


Status RemoveFisrtHeap(Heap &H, RcdType &e) {
    if (H.n <= 0) {
        return ERROR;
    }
    e = H.rcd[1];
    SwapHeapElem(H, 1, H.n);
    H.n--;
    if (H.n > 1) {
        ShiftDown(H, 1);
    }

    return OK;
}


Status RemoveHeap(Heap &H, int pos, RcdType &e) {
    if (H.n <= 0 || pos <= 0 || pos > H.n) {
        return ERROR;
    }
    e = H.rcd[pos];
    SwapHeapElem(H, pos, H.n);
    H.n--;
    if (H.n > 1) {
        ShiftDown(H, pos);
    }

    return OK;
}


void HeapSort(RcdSqList &L, int tag) {
    Heap H;
    RcdType e;
    MakeHeap(H, L.rcd, L.length, L.size, tag);
    for (int i = H.n; i > 0; i--) {
        RemoveFisrtHeap(H, e);
    }
}


int Depth(Heap H) {
    return 1 + log2(H.n);
}


void PrintHeap(Heap H) {
    if (H.rcd == NULL) {
        printf("堆为�?");
        return;
    }
    printf("˳�򴢴��?: ");
    for (int i = 1; i < H.n; i++) {
        printf("%d", H.rcd[i].key);
    }
    printf("\n���νṹ: ");
    for (int i = 1, j = 1; i < H.n; i++) {
        printf("%d", H.rcd[i].key);
        if ((int) pow(2, j) - 1 == i) {
            printf("\n");
            j++;
        }
    }
    printf("\n��������?%d", Depth(H));
}


void testHeapSort() {
    RcdSqList L;      
	int size=40,i,n;
	int tag;
    RcdType R[40];
    
    printf("请选择 0-降序 1-升序");
    scanf("%d",&tag);
    while(tag!=0&&tag!=1) {
        printf("������������������ѡ��\n");
        scanf("%d",&tag);
        break;
    }
    printf("��Ҫ����ļ�¼�ж��ٸ���\n");
    scanf("%d",&L.length);
    while(L.length>=size)
	{
		printf("������������������ѡ��\n");
		scanf("%d",&L.length);
	}
        L.size=size;
        for(i=1;i<=L.length;i++){
        printf("��%d����¼�ؼ���:",i);
        scanf("%d",&R[i].key);
    }
    L.rcd=R;
    HeapSort(L,tag);
    printf("��������\n");
    for(i=1;i<=L.length;i++){
        printf("%d ",L.rcd[i].key);
    }
    printf("\n");    
}


int main() {
    testHeapSort();
}
