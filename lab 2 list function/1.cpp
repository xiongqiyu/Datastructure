#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

typedef int list_t;

struct listnode{
	list_t val;
	listnode* next;
};

typedef listnode* mlist;

void consref(list_t el, mlist& l);
mlist consret(list_t el, mlist l);
void printlist(mlist l);
void deallocate_c(mlist l);
void deallocate_r(mlist& l);
//additional function
void printlength(mlist l);
int position(mlist l, int n);
void search_delete(mlist& l, int n);
mlist concatenate(mlist a, mlist b);

int main(){
	mlist la = NULL;
	mlist lb = NULL;
	
	//input from file
    std::ifstream infile;   
    std::string filename;
    std::cout<<"please enter the name of the file for input"<<std::endl;
    std::cin>>filename;
    infile.open(filename.c_str());
    if(!infile.is_open()){
    std::cout<<"the file cannot be opened"<<std::endl;
    exit(EXIT_FAILURE);
    }
	
    //into linked list
	list_t el;
	while(infile>>el){
		consref(el, la);
		lb = consret(el, lb);
	}
	
	std::cout<<std::endl;
	printlist(la);
	
	std::cout<<std::endl;
	printlist(lb);
	
	std::cout<<std::endl;
	printlength(la);
	
	std::cout<<std::endl;
	printlength(lb);
	
	std::cout<<std::endl;
	int search;
	std::cout<<"enter the element "<<std::endl;
	std::cin>>search; 
	int firstpos;
	firstpos = position(la, search);
	if(firstpos==0){
		std::cout<<"not found"<<std::endl;
	}
	else{
		std::cout<<"the position is "<<firstpos<<std::endl;
	}
	
	search_delete(la, search);
	printlist(la);
	
	mlist clist = new listnode;
	//std::cout<<"123"<<std::endl;
	clist = concatenate(la, lb);
	printlist(clist);
	
	deallocate_c(la);
	deallocate_r(lb);
	
	return 0;
		
}

void consref(list_t el, mlist& l){
	mlist tmpp = new listnode;
	tmpp->val = el;
	tmpp->next = l;
	l=tmpp;
}

mlist consret(list_t el, mlist l){
	mlist tmpp = new listnode;
	tmpp->val = el;
	tmpp->next = l;
	return tmpp;
}

void printlist(mlist l){
	while(l != NULL){
		std::cout<<l->val<<std::endl;
		l = l->next;
	}
}

void deallocate_c(mlist l){
	while(l != NULL){
		mlist nextl = l->next;
		delete l;
		l = nextl;
	}
}

void deallocate_r(mlist& l){
	while(l != NULL){
		mlist nextl = l->next;
		delete l;
		l = nextl;
	}
}

void printlength(mlist l){
	int i=0;
	while(l != NULL){
		l=l->next;
		i++;
	}
	std::cout<<"the length is "<<i<<std::endl;
}

int position(mlist l, int n){
	int pos=0;
	int a=0;
	while(l != NULL){
		if(l->val != n){
			pos++;
			l=l->next;
		}
		else{
			pos++;
			a=pos;
			l=l->next;
		}
	}
	return a;
}

void search_delete(mlist& l, int n){
    bool found= false;
    mlist searchptr;
    mlist oldptr;
    mlist lastptr;
    
    if (l==NULL) {
        return;
    }
    else if (l->val==n)
    {
        oldptr=l;
        l=l->next;
        delete oldptr;
    }
    else{
        found=false;
        searchptr=l;
        lastptr=l;
        while ((searchptr!=NULL)&&(!found)) {
            if (searchptr->val==n) {
                found=true;
                lastptr->next=searchptr->next;
                delete searchptr;
            }
            else
            {
                lastptr=searchptr;
                searchptr=searchptr->next;
            }
        }
    }
}

mlist concatenate(mlist a, mlist b){
	mlist newlist = new listnode;
	newlist = a;
	while(a->next != NULL){
		a = a->next;
	}
	a->next = b;
	
	return newlist;
}





