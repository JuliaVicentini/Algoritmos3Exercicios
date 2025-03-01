#include<iostream>
#include<list>
using namespace std;

struct node {
	   int info;
	   node * left, * right;	
};

void insert(node * & curr, int new_info){
	if(curr == NULL){
		curr = new node;
		curr->info = new_info;
		curr->left = NULL;
		curr->right = NULL;
	} else {
		if(new_info < curr->info){
			insert(curr->left, new_info);
		} else {
			insert(curr->right, new_info);
		}
	}
}

node * search(node * curr, int searched_info){
	if(curr == NULL)
		return NULL;
	if(curr->info == searched_info)
		return curr;
	if(searched_info < curr->info){
		return search(curr->left, searched_info);
	} else {
		return search(curr->right, searched_info);
	}	
}

node * point_smaller(node * &curr){
	if(curr->left == NULL){
		node * aux = curr;
		curr = curr->right;
		return aux;
	} else {
		return point_smaller(curr->left);
	}	
}

bool remove(node * &curr, int removing_info){
	if(curr == NULL)
		return false;
	if(curr->info == removing_info){
		node * aux = curr;
		if(curr->left == NULL)
			curr = curr->right;
		else if(curr->right == NULL)
			curr = curr->left;
		else {
			aux = point_smaller(curr->right);
			curr->info = aux->info;
		}
		delete aux;
		return  true;
	} else if(removing_info < curr->info){
		return remove(curr->left, removing_info);
	} else {
		return remove(curr->right, removing_info);
	}	
}

void pre_order(node * curr){
	if(curr != NULL){
		cout << curr->info << endl;
		pre_order(curr->left);
		pre_order(curr->right);
	}
}

void pos_order(node * curr){
	if(curr != NULL){
		pos_order(curr->left);
		pos_order(curr->right);
		cout << curr->info << endl;
	}
}

void destruct(node * &curr){
	if(curr != NULL){
		destruct(curr->left);
		destruct(curr->right);
		delete curr;
		curr = NULL;
	}
}

void in_order_asc(node * curr){
	if(curr != NULL){
		in_order_asc(curr->left);
		cout << curr->info << endl;
		in_order_asc(curr->right);		
	}
}

void in_order_desc(node * curr){
	if(curr != NULL){
		in_order_desc(curr->right);
		cout << curr->info << endl;
		in_order_desc(curr->left);		
	}
}

void in_level(node * curr){
	list<node *> visit_queue;
	if(curr != NULL){
		visit_queue.push_back(curr);
		while(!visit_queue.empty()){
			node * aux = visit_queue.front();
			visit_queue.pop_front();
			if(aux->left != NULL)
				visit_queue.push_back(aux->left);
			if(aux->right != NULL)
				visit_queue.push_back(aux->right);
			cout << aux->info << endl;
		}
	}
}

int main(){
	
	node * result, * root = NULL;
	
	int N = 0;
	
	while(N != -1){
	    cin >> N;
	    if(N == -1){
	        break;
	    }
	    insert(root, N);
	}
	
	in_level(root);
	destruct(root);
	
	return 0;
}