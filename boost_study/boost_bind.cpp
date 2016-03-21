#include<boost/bind.hpp>
#include<vector>
#include<algorithm>
#include<iostream>

void print(int i)
{
  std::cout << " " << i;
}

bool compare(int i, int j)
{
  return i > j;
}

int main(int argc, char** atgv)
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(0);
  v.push_back(-1);
  v.push_back(3);
  //for_each需要的是一个参数的函数
  std::for_each(v.begin(), v.end(), boost::bind(print, _1));
  std::cout << std::endl;

  //sort需要的是两个参数的函数
  std::sort(v.begin(), v.end(), boost::bind(compare, _1, _2));
  std::for_each(v.begin(),v.end(),boost::bind(print,_1));
  
  std::cout << std::endl;
  return 0;
}
