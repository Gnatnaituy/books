#define MAXSIZE = 25
typedef struct
{
    int data[MAXSIZE];
    int length;    //当前线性表长度
} SqList;

//La 表示集合a Lb表示集合b
void unionL(List *La, List Lb)
{
    int La_len, Lb_len, i;

    int e;
    La_len = ListLength( *La );
    Lb_len = ListLength( *Lb );

    for( i = 1; i <= Lb_len; i++ )
    {
        GetElem( Lb, i, &e );
        if( !LocateElem( La, e ) )
        {
            ListInsert( La, ++La_len, e );
        }
    }
}

int LocateElem(SqList L, e)
{
    if(L.length == 0)
    {
        return 0;
    }
    for(int i = 0; i < L.length-1; i++)
    {
        if( e == L.data[i])
        {
            return i;
        }
        else
        {
            return 0;
        }
    }

}

int GetElem( SqList L, int i, int *e )
{
    if(L.length == 0 || i < 1 || i > L.length)
    {
        return 0;
    }
    *e = L.data[i-1];

    return 1;
}

int ListInsert(SqList *L, int i, int *e)
{
    int k;

    if(L->length == MAXSIZE || i < 1 || i > L->length)  //线性表已满或i不在范围内
    {
        return 0;
    }
    if(i <= L.length) //若插入数据不在表尾
    {
        for(k = L->length-1; k >= i-1; k--)  //将要插入位置后元素向后挪一位
        {
            L->data[k+1] = L->data[k];
        }
    }

    L->data[i-1] = *e;
    L->length++;

    return 1;
}

int ListDelete(SqList *L, int i, int *e)
{
    int k;

    if(L->length == 0 || i < 1 || i > L->length)  //线性表为空


        或i不在范围内
    {
        return 0;
    }

    *e = L->data[i-1];

    if(i < L.length) //若要删除的数据不在表尾
    {
        for(k = i; k < L->length; k++)  //将要插入位置后元素向前挪一位
        {
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;

    return 1;
}