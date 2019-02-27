#include <iostream>
#include<stdlib.h>
struct intlist {
  int val;
  intlist* next;
};

int main(){

  intlist* l=NULL;
  int n, el;
  std::cout<<"how many elements?"<<std::endl;
  std::cin>>n;

  for(int i=0; i<n; i++){
    std::cout<<"enter element"<<i+1<<std::endl;
    std::cin>>el;

    intlist* tmp = new intlist;
    tmp->val=el;
    tmp->next=l;
    l=tmp;
  }

  std::cout<<std::endl;

  intlist* lit=l;

  while(lit!=NULL){
    std::cout<<lit->val<<std::endl;
    lit=lit->next;
  }

  while (l!=NULL){
    intlist* tmpl=l->next;
    delete l;
    l=tmpl;
  }
  return 0;
}
