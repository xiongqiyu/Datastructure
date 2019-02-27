#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

struct intlist{
  int num;
  intlist* next;
};


int main(){
  intlist* l=NULL;
  int a, length=0;;
  std::ifstream infile;
  std::string filename;
  std::cout<<"please enter the name of the file for input"<<std::endl;
  std::cin>>filename;
  infile.open(filename.c_str());
  if(!infile.is_open()){
    std::cout<<"the file cannot be opened"<<std::endl;
    exit(EXIT_FAILURE);
  }
  while(infile>>a){               //list input
    intlist* tmp=new intlist;
    tmp->num=a;
    tmp->next=l;
    l=tmp;
    length=length+1;
    
  }
  std::cout<<"the length is "<<length<<std::endl;
  std::cout<<std::endl;

  int search, pos=0;               //search intlist
  std::cout<<"enter the element you want to search"<<std::endl;
  std::cin>>search;

	intlist* c = l;

  while(l->next->num!=search && l->next->next !=NULL){
  	std::cout<<"number: "<<l->num<<"\n";
    if(l->next->num==search){
      intlist* searchlist=l->next;
      l->next=l->next->next;
      delete searchlist;
      pos++;
    }
    else{
    	l=l->next;
	}
  }
	l=c;
  intlist* lit=l;           //print whole list
  while(lit->next!=NULL){
    std::cout<<lit->num<<std::endl;
    lit=lit->next;
  }

  while(l->next!=NULL){            //delocalise list
    intlist* newtmp=l->next;
    delete l;
    l=newtmp;
  }
  return 0;
}
