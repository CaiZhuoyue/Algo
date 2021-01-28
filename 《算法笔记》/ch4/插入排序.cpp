#include<stdlib.h>
#include<stdio.h>

//插入排序只需n-1次

//自己写的insertSort
void myInsertSort(int A[], int len)
{
    int i; //有序的最后一位序号
    for(i=0;i<len-1;i++)
    {
        int j=i+1;
        printf("i:%d,j:%d\n",i,j);
        for(int i=0;i<9;++i)
            printf("%d ",A[i]);
        printf("\n");
        if(A[j]>=A[i])
        {
            continue;
        }    
        else
        {
        int k=i;
        while(A[k]>A[j] && k>=0)
        {
            k--;
        }
        //最后得到的k是最大的 A[k]<A[j]的k值
        int temp=A[j];
        for(;j>k+1;j--)
        {
            A[j]=A[j-1];
        }
        A[k+1]=temp;
        for(int i=0;i<9;++i)
            printf("%d ",A[i]);
        printf("\n");
        }
    }
}

//标准答案
void insertSort(int A[],int len)
{
    for(int i=1;i<len;i++) //len-1次
    {
        int temp=A[i],j=i;
        while(j>0&&temp<A[j-1])
        {
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
}

int main()
{ int A[]={5,6,1,2,3,4,7,9,8};
//   myInsertSort(A,9);
  insertSort(A,9);
  for(int i=0;i<9;++i)
            printf("%d ",A[i]);
        printf("\n");

}