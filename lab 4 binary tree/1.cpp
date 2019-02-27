#include <iostream>

typedef int tree_t;

struct treenode{
	tree_t val;
	treenode* left;
	treenode* right;
};

typedef treenode* mtree;

//function declaration
mtree constree(tree_t el, mtree l, mtree r);
mtree instree(tree_t el, mtree t);
void instree_ref(tree_t el, mtree& t);
void printtree(mtree t);
mtree deletefromtree_nmr(tree_t el, mtree t);
tree_t minvalnode(mtree t);
void deletetree(mtree t);
//additional function
void nodenum(mtree t, int& num);
int height(mtree t);
bool lookup(mtree t, int l);
int terpe(mtree t, int l);

//main function
int main(){
	int n;
	mtree t1 = NULL, t2 = NULL;
	tree_t tmp;
	std::cout<<"how many elements?"<<std::endl;
	std::cin>>n;
	for(int i=0;i<n;i++){
		std::cin>>tmp;
		t1 = instree(tmp, t1);
		instree_ref(tmp, t2);
	}
	
	std::cout<<std::endl;
	printtree(t1);
	std::cout<<std::endl;
	printtree(t2);
	
	//number of nodes
	int num=0;
	nodenum(t1, num);
	std::cout<<"the number of nodes is "<<num<<std::endl;
	
	//height of tree
	int h;
	h = height(t1);
	std::cout<<"the height of tree is "<<h<<std::endl;
	
	//looking for elements
	int l;
	std::cout<<"enter the element you are looking for: "<<std::endl;
	std::cin>>l;
	if(lookup(t1, l)==true){
	    std::cout<<"found"<<std::endl;
	}
	else{
	    std::cout<<"not found"<<std::endl;
	}
	
	//number of element smaller
	int a;
	std::cout<<"element an element: "<<std::endl;
	std::cin>>a;
	int te = terpe(t1, a);
	std::cout<<te<<std::endl;
	
	std::cout<<"enter element to delete"<<std::endl;
	std::cin>>n;
	
	t1 = deletefromtree_nmr(n, t1);
	t2 = deletefromtree_nmr(n, t2);
	
	std::cout<<std::endl;
	printtree(t1);
	std::cout<<std::endl;
	printtree(t2);
	
	deletetree(t1);
	t1 = NULL;
	deletetree(t2);
	t2 = NULL;
	
	return 0;
}

//function defination
mtree constree(tree_t el, mtree l, mtree r){
	mtree tmp = new treenode;
	tmp->val = el;
	tmp->left = l;
	tmp->right = r;
	return tmp;
}

mtree instree(tree_t el, mtree t){
	if(t==NULL){
		return constree(el, NULL, NULL);
	}
	else if(el<t->val){
		t->left = instree(el, t->left);
		return t;
	}
	else{
		t->right = instree(el, t->right);
		return t;
	}
}

void instree_ref(tree_t el, mtree& t){
	if(t==NULL){
		mtree tmp = new treenode;
		tmp->val = el;
		tmp->left = NULL;
		tmp->right = NULL;
		t = tmp;
	}
	else if(el<t->val){
		instree_ref(el, t->left);
	}
	else{
		instree_ref(el, t->right);
	}
}

void printroot(mtree t){
	std::cout<<t->val<<std::endl;
}

void printtree(mtree t){
	if(t!=NULL){
		printtree(t->left);
		printroot(t);
		printtree(t->right);
	}
}

tree_t minvalnode(mtree t){
	if(t->left==NULL){
		return t->val;
	}
	else{
		return minvalnode(t->left);
	}
}

mtree deletefromtree_nmr(tree_t el, mtree t){
	if(t==NULL){
		return t;
	}
	else if(el==t->val){
		if((t->left==NULL)&&(t->right==NULL)){
			delete t;
			return NULL;
		}
		else if(t->left==NULL){
			mtree temp = t->right;
			delete t;
			return temp;
		}
		else if(t->right==NULL){
			mtree temp = t->left;
			delete t;
			return temp;
		}
		else{
			t->val = minvalnode(t->right);
			t->right = deletefromtree_nmr(t->val, t->right);
			return t;
		}
	}
	else if(el<t->val){
		t->left = deletefromtree_nmr(el, t->left);
		return t;
	}
	else{
		t->right = deletefromtree_nmr(el, t->right);
		return t;
	}
}

void deletetree(mtree t){
	if(t!=NULL){
		deletetree(t->left);
		deletetree(t->right);
		delete t;
	}
} 

void nodenum(mtree t, int& num){
	if(t!=NULL){
		num = num+1;
		nodenum(t->left, num);
		nodenum(t->right, num);
	}
}

int height(mtree t){
    if(t==NULL){
        return 0;
    }
    int lh = height(t->left);
    int rh = height(t->right);
    if(lh>rh){
        return lh+1;
    }
    else{
        return rh+1;
    }
}

bool lookup(mtree t, int l){
    if(t!=NULL){
        if(t->val<l){
            return lookup(t->right, l);
        }
        if(t->val>l){
            return lookup(t->left, l);
        }
        if(t->val==l){
            return true;
        }
    }
    else{
        return false;
    }
}

int terpe(mtree t, int l){
    if(t!=NULL){
        if(t->val<l && t->right->val<l){
            terpe(t->right, l);
        }
        if(t->val>l && t->left->val>l){
            terpe(t->left, l);
        }
        if(t->val<l && t->right->val>=l){
            int a;
            nodenum(t->right, a);
            return a;
        }
        if(t->val>l && t->left->val<=l){
            int a;
            nodenum(t->left, a);
            return a;
        }
    }
    else{
        return 0;
    }
}


















