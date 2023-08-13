#include<iostream>
using namespace std;
int fun(int a,int b)
{
    return a+b;
}
int main()
{
    int a = 1;
    const int b = 2;
    int *p = (int*)&b;
    *p = 200;
    fun(a,b);
    cout<<b<<endl;
    cout<<*p<<endl;
    cout<<&b<<endl;
    cout<<p<<endl;
    return 0;
}
