#include<iostream>
#include<set>
using namespace std;
int check_rep(int *p, int n)
{
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        if(s.count(p[i]))return 1;
        s.insert(p[i]);
    }
    return 0;
}
int main()
{
    int num = 10000'000;
    int *arr = new int[num];
    for (int i = 0; i < num; i++) {
        arr[i] = i;
    }
    arr[num - 1] = arr[num - 2];
    int ret = check_rep(arr, num);
    if (ret) {
        cout << "repeat" << endl;
    } else {
        cout << "non repeat" << endl;
    }
    delete[] arr;
    return 0;
}
