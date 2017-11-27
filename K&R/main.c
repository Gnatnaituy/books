#include <stdio.h>
#include <memory.h>


swap1(int x,int y)
{
    int w;                //交换x与y的值
    w=x; x=y; y=w;
}
swap2(int *p1,int *p2)
{
    int *p;               //交换p1与p2里存的地址
    p=p1; p1=p2; p2=p;
}
swap3(int *pa, int *pb)
{
    int p;                //交换pa与pb所对应变量的值
    p=*pa; *pa=*pb; *pb=p;
}
test_swap(){
    int a = 5,b = 7, *ptr1, *ptr2;
    ptr1=&a; ptr2=&b;
    swap1(*ptr1,*ptr2);
    printf("data1=%d\tdata2=%d\n",*ptr1,*ptr2);
    swap2(ptr1,ptr2);
    printf("data3=%d\tdata4=%d\n",*ptr1,*ptr2);
    printf("data5=%d\tdata6=%d\n",a,b);
    swap3(ptr1,ptr2);
    printf("data7=%d\tdata8=%d\n",*ptr1,*ptr2);
    printf("data9=%d\tdata10=%d\n",a,b);
}


int main(void)
{
//    int a = -1, b = 4, k;
//    k = !((++a < 0) && !(b-- < 0));
//    printf("%d%d%d\n", k, a, b); //output: 104

//    int i;
//    i=1, ++i, ++i||++i, i;
//    printf("%d", i);  //output: 3

//    char s[] = "\\141\141abc\t";
//    int i;
//    for(i = 0; i < strlen(s); i++)
//        printf("%c\n", s[i]);
//    printf("%d", strlen(s));
    int i,n=0;
    for( i=2;i<5;i++){
        do{
            if(i%3)
                continue;
            n++;
        }while(!i);
        n++;
    }
    printf("n=%d\n",n);
}
