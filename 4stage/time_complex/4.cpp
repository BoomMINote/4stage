#include<iostream>
#include<limits>
int main()
{
    std::cout<<std::numeric_limits<int>::lowest()<<std::endl;
    std::cout<<std::numeric_limits<int>::min()<<std::endl;
    std::cout<<std::numeric_limits<int>::max()<<std::endl;
    std::cout<<std::numeric_limits<int>::epsilon()<<std::endl;
    std::cout<<std::numeric_limits<float>::epsilon()<<std::endl;
    std::cout<<std::numeric_limits<int>::digits<<std::endl;
    std::cout<<std::numeric_limits<unsigned int>::digits<<std::endl;
}
