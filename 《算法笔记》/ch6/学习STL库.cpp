#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<set>
#include<string>//注意 string和string.h是不同的
#include<iostream>

using namespace std;

vector<int> a;
vector<int> b[10];//这种情况下b[0]-b[9]都是vector容器
set<int> c;//集合 内部自动有序 且不含重复元素

vector<int>::iterator it1;
set<int>::iterator it2;

string s;//只能对string用cin和cout


int main()
{
    for(int i=0;i<5;i++)
        a.push_back(i);

    for(it1=a.begin();it1!=a.end();it1++)
    //注意 遍历结束只能用!= 不能用< a.end()
        printf("%d ",*(it1));
    printf("\n");

    string str="hello,world!";
    string str2="world!";
    printf("%s\n",str.c_str());//只有这样才能变为字符数组输出
    cout<<(str+=str2)<<endl;

    cout<<str2.substr(0,2);
    cout<<str.find(str2);
    return 0;
}
