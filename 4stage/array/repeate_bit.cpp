#include<iostream>
using namespace std;
int check_rep(int *p,int n)
{
    int *hash = new int[n/32+1];
    for(int i = 0; i < n; i++)
    {
        int array_index = p[i]/32;
        int shift_index = p[i]%32;
        int bit = (hash[array_index]>>shift_index)&0x01;
        if(bit){delete[] hash;return 1;}
        hash[array_index]^=1<<shift_index;
    }
    delete[] hash;
    return 0;
}
int main()
{
    int num = 2'000'000'000;
    int *arr = new int[num];
    for(int i = 0; i < num; i ++)arr[i] = i;
    arr[num-1] = arr[num-2];
    int ret = check_rep(arr,num);
    if(ret)cout<<"repeat"<<endl;
    else cout<<"non repeat"<<endl;
    return 0;
}
