#include<iostream>

typedef int list_t;

struct listnode{
	list_t val;
	listnode* next;
};

typedef listnode* mlist;

//function declaration
void consref(list_t el, mlist& l);
mlist consret(list_t el, mlist l);
mlist constail_rec(list_t el, mlist l);
void printlist_rec(mlist l);
void printrevlist_rec(mlist l);
void deallocate_r_rec(mlist& l);
mlist deallocate_c_rec(mlist l);
void deallocate_r_rec_wrong(mlist& l);
int mfact(int n);
//additional function
int expo(int n, int p);
void insert_order(mlist& l, int n);


int main(){
	mlist la = NULL;
	mlist lb = NULL;
	mlist lc = NULL; //factorial list
	mlist ld = NULL; //exponential list
	
	//list input
	int n, p; //p is power
	list_t el;
	std::cout<<"how many elements ?"<<std::endl;
	std::cin>>n;
	std::cout<<"expo valueis "<<std::endl;
	std::cin>>p;
	
	for(int i=0; i<n; i++){
		std::cout<<"enter element: "<<std::endl;
		std::cin>>el;
		
		la = consret(el, la);
		lb = constail_rec(el, lb);
		lc = consret(mfact(el), lc);
		ld = consret(expo(el, p), ld);
	}
	
	std::cout<<std::endl;
	
	//print list
	std::cout<<"print in the normal order :"<<std::endl;
	printlist_rec(la);
	std::cout<<std::endl;
	printlist_rec(lb);
	std::cout<<std::endl;
	printlist_rec(lc);
	std::cout<<std::endl;
	printlist_rec(ld);
	
	std::cout<<std::endl;
	
	std::cout<<"print in reverse order :"<<std::endl;
	printrevlist_rec(la);
	std::cout<<std::endl;
	printrevlist_rec(lb);
	
	std::cout<<std::endl;
	
	//insert
	int ele;
	std::cout<<"enter an element"<<std::endl;
	std::cin>>n;
	insert_order(lb, ele);
	printlist_rec(lb);
	
	
	//deallocate list
	deallocate_r_rec(la);
	std::cout<<la<<std::endl;
	lb = deallocate_c_rec(lb);
	std::cout<<lb<<std::endl;
	
	return 0;
}

//function definition
int mfact(int n){
	if(n==0){
		return 1;
	}
	else{
		return n*mfact(n-1);
	}
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

mlist constail_rec(list_t el, mlist l){
	if(l==NULL){
		return consret(el, l);
	}
	else{
		l->next = constail_rec(el, l->next);
		return l;
	}
}

void printhead(mlist l){
	std::cout<<l->val<<std::endl;
}

void printlist_rec(mlist l){
	if(l != NULL){
		printhead(l);
		printlist_rec(l->next);
	}
}

void printrevlist_rec(mlist l){
	if(l != NULL){
		printrevlist_rec(l->next);
		printhead(l);
	}
}


void deallocate_r_rec_wrong(mlist& l){
	if(l != NULL){
		mlist nextl = l->next;
		delete l;
		deallocate_r_rec_wrong(nextl);
	}
}

void deallocate_r_rec(mlist& l){
	if(l != NULL){
		mlist tmp = l;
		l = l->next;
		delete tmp;
		deallocate_r_rec(l);
	}
}

mlist deallocate_c_rec(mlist l){
	if(l==NULL){
		return l;
	}
	else{
		mlist nextl = l->next;
		delete l;
		return deallocate_c_rec(nextl);
	}
}

//additional function
int expo(int n, int p){
	if(p==0){
		return 1;
	}
	else{
		p = p-1;
		return n*expo(n, p);
	}
}

void insert_order(mlist& l, int n){
	mlist start = l;
	bool found = false;
	if(l == NULL){
		mlist tmp = new listnode;
		tmp->val = n;
		tmp->next = l;
		start = tmp;
	}
	else{
		if(l->val>=n){
			mlist tmp = new listnode;
			tmp->val = n;
			tmp->next = l;
		    start = tmp;
		}
		else{
			if(l!=NULL && !found){
				if(l->next->val<n){
					l = l->next;
				}
				else{
					mlist tmp = new listnode;
					tmp->val = n;
					tmp->next = l->next;
					l->next = tmp;
					found = true;
				}
			}
		}
	}
	l = start;
}




































