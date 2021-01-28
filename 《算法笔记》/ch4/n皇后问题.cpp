#include<stdio.h>
#include<stdlib.h>

int board[20][20]={{false}};
bool isOK(int n, int row, int col);
int ans=0;

void NQueens(int n, int row)
{
    // for(int i=0;i<n;++i)
    //     {
    //         for(int j=0;j<n;++j)
    //             printf("%d ",board[i][j]);
    //         printf("\n");
    //     }
    // printf("\n");

    if(row>=n)
    {
        // printf("找到了一个n皇后方法！\n");
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=0;j<n;++j)
        //         printf("%d ",board[i][j]);
        //     printf("\n");
        // }
        ans++;
        return;
    }
        
    for(int i=row;i<n;++i)
    {
        int flag=0;
        for(int j=0;j<n;++j)
        {
            if(isOK(n,i,j))
            {
                board[i][j]=true;
                NQueens(n,row+1);
                board[i][j]=false;
            }    
        }
        if(flag==0)
            return;
    }
   

}

int fabs(int x)//求绝对值
{
    return x>0?x:-x;
}

bool isOK(int n, int row, int col)//看某个位置可不可以放
{
    for(int i=0;i<row;i++)
    {
        if(board[i][col]!=0)
            return false;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=row && board[i][j]==1 && fabs(i-row)==fabs(j-col))
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    NQueens(8,0);
    printf("8皇后问题的解有:%d种\n",ans);
}
