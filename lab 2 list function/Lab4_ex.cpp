#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

//typedef int list_t;
//typedef double list_t;
//typedef char list_t;
typedef std::string list_t;

struct listnode {
   list_t val;
   listnode* next;
};

typedef listnode* mlist;

void consref(list_t el, mlist& l);
mlist consret(list_t el, mlist l);
void printlist(mlist l);
void deallocate_c(mlist l);
void deallocate_r(mlist& l);
//-------------below is additional functions-----------------------------------
void length(mlist l);
void search (list_t el, mlist l, std::string a);
void search_delete (list_t el, mlist l, std::string a);
void concatenates (list_t ela, list_t elb, mlist l1, mlist l2,std::string a);


int main() {
  mlist la = NULL;
  mlist lb = NULL;
  list_t ela, elb;

  std::string textfilename1, textfilename2, wordsfilename;
  std::cout << "please enter the nmaes of the input files: "<<std::endl;
  std::cin >> textfilename1;
  std::cin >> textfilename2;


  std::ifstream infile1;
  std::ifstream infile2;

  infile1.open(textfilename1.c_str());
  if(!infile1.is_open()){
    std::cout<<"error opening" <<textfilename1 <<std::endl;
    exit(EXIT_FAILURE);
  }
  while(infile1 >> ela){
     consref(ela, la);
    // lb = consret(ela, lb);
  }
  std::cout <<std::endl;
  printlist(la);
  std::cout <<std::endl;

  infile2.open(textfilename2.c_str());
  if(!infile2.is_open()){
    std::cout<<"error opening" <<textfilename2 <<std::endl;
    exit(EXIT_FAILURE);
  }
  while(infile2 >> elb){
     consref(elb, lb);
  }
  std::cout <<std::endl;
  printlist(lb);

  //------------------------------------------------------------
  std::cout<<"-------below is additional operations-----------"<<std::endl;
  //below is additional operations
  length(la);

  std::string a;
  //search_delete(ela, la, a);
  std::cout<<std::endl;
  concatenates (ela, elb, la, lb, a);


  deallocate_c(la);
  deallocate_c(lb);

  return 0;
}
void concatenates (list_t ela, list_t elb, mlist l1, mlist l2,std::string a){
  mlist tmpp1 = new listnode;
  mlist tmpp2 = new listnode;
  tmpp1 -> next = l1;
  tmpp2 -> next = l2;
  while(l1 != NULL) {
   std::cout << l1->val <<std::endl;
   l1 = l1->next;
  }
  l1 = tmpp1;
  while(l2 != NULL) {
   std::cout << l2->val <<std::endl;
   l2 = l2->next;
  }
  l2 = tmpp2;
  std::cout<<"search and delete one element in list1"<<std::endl;
  search_delete(ela, l1, a);
  std::cout<<std::endl;
  std::cout<<"search and delete one element in list2"<<std::endl;
  search_delete(elb, l2, a);
  std::cout<<std::endl;

  printlist (l1);
  printlist (l2);
}
void search_delete (list_t el, mlist l, std::string a){
  std::cout<<"please enter an element again:"<<std::endl;
  std::cin>>a;
  int m=0;
  mlist tmpp = new listnode;
  tmpp = l;
  while(l!=NULL){
    m=m+1;
    if(l->val==a){
      l=l->next;
      //std::cout <<"detect"<<std::endl;
    }
    else{
      std::cout<<l->val<<std::endl;
      l=l->next;
    }
    //l=tmpp;
  }
}
void search (list_t el, mlist l,std::string a){
  int m=0;
  int o=0;
  int p;
  std::cout<<"please input an element: " <<std::endl;
  std::cin >> a;
  while(l!=NULL){
    m=m+1;
    if(l->val==a){
      o=1;
      p=m;
    }
    l=l->next;
  }
  l=l;
  if(o==1){
    std::cout<<"the position of " << a <<" is: "<<p<<std::endl;
  }
  else{
    std::cout<<a<<" not found in the file"<<std::endl;
  }

}
void length (mlist l){
  int length = 0;
  while(l!=NULL){
       length=length+1;
       l=l->next;
  }
  std::cout<<"the length of the file is: "<<length<<std::endl;
}
void consref(list_t el, mlist& l){
  mlist tmpp = new listnode;
  tmpp->val = el;

  tmpp->next = l;
  l = tmpp;
}

mlist consret(list_t el, mlist l){
  mlist tmpp = new listnode;
  tmpp->val = el;
  tmpp->next = l;
  return tmpp;
}

void printlist(mlist l) {
  while(l != NULL) {
   std::cout << l->val <<std::endl;
   l = l->next;
   //std::cout<<"q"<<std::endl;
  }
}

void deallocate_c(mlist l) {
  while (l != NULL){
   mlist nextl = l->next;
   delete l;
   l = nextl;
  }
}

void deallocate_r(mlist& l) {
  while (l != NULL){
   mlist nextl = l->next;
   delete l;
   l = nextl;
  }
}
