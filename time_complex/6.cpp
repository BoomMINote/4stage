#include<iostream>
using namespace std;
int main()
{
    int m = 0xff;
    int n = 0xf0;
    int a[8]={1,2,3,4,5,6,7,8};
    int p = 0x11;
    int q = 0x22;
    cout<<sizeof(*((&a+1)+0))<<endl;
    cout<<(*(int (*)[8])(&a+1))[-3]<<endl;
    cout<<((int*)(&a+1))[-3]<<endl;
    return 0;
}
