#include<iostream>
using namespace std;
int check_repeat(long *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == i)continue;
        else
        {
            if(arr[arr[i]] == arr[i])return 1;
            else swap(arr[i],arr[arr[i]]);
        }
    }
    return 0;
}
int main()
{
    int num = 2'000'000'000;
    long *arr = new long[num];
    for(int i = 0; i < num; i++)arr[i] = i;
    arr[num-1]=arr[num-2];
    int ret = check_repeat(arr,num);
    if(ret)cout<<"repeate"<<endl;
    else cout<<"no repeate"<<endl;
    return 0;
}
