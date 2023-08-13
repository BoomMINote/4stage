#include<iostream>
#include<vector>
using namespace std;
int main()
{
    std::vector<int> a{1,2,3,4,5,6};
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    cout<<a.size()<<endl;
    a.resize(10,4);
    cout<<a.size()<<endl;
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    return 0;
}
