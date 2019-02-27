#include<iostream>

struct point{
  double x;
  double y;
};

int main(){
  int a=15;
  std::cout<<"a: "<<a<<std::endl;
  int* pa;
  pa=&a;
  *pa=3;
  std::cout<<"a(after the change through pa): "<<a<<std::endl;

  int* pb;
  pb=new int;

  *pb=3;
  std::cout<<"*pb: "<<*pb<<std::endl;

  delete pb;

  point* ppoint;
  ppoint=new point;
  ppoint->x=0.1;
  ppoint->y=-0.1;
  std::cout<<"ppoint->x: "<<ppoint->x<<" ppoint->y: "<<ppoint->y<<std::endl;
  delete ppoint;

  int* parr;
  int maxsize, lsize=0;
  std::cout<<"enter the amount of memory to allocate for array:"<<std::endl;
  std::cin>>maxsize;
  parr=new int[maxsize];

  parr[0]=3;
  lsize++;
  parr[1]=4;
  lsize++;
  for(int i=0; i<lsize; i++){
    std::cout<<"parr["<<i<<"]: "<<parr[i]<<std::endl;

  }
  delete[] parr;  //delete array should include '[]'

  return 0;
}
