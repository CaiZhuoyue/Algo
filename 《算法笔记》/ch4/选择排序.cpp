#include<stdio.h>
#include<stdlib.h>

//简单选择排序
void selectSort(int A[], int len){
    for(int i=0;i<len;i++)
    {
        int k=i;
        for(int j=i;j<len;j++)
        {
            if(A[k]>A[j])
                k=j;
        }
        int temp=A[i];
        A[i]=A[k];
        A[k]=temp;
    }
}

int main()
{
    int A[]={9,8,7,6,5,4,3,2,1};
    printf("len:%d\n",(sizeof(A)/sizeof(int)));
    selectSort(A,9);
    for(int i=0;i<9;++i)
        printf("%d ",A[i]);
    printf("\n");
}