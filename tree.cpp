#include<bits/stdc++.h>
using namespace std;
class Node{
    int val;
    public:
    Node* left=NULL;
    Node* right=NULL;
    Node(int x){
        val=x;
    }
    int data(){
    	return this->val;
    }
    void sdata(int n){
    	val=n;
    }
};
void Insert(Node** r,int x){
    Node* n=new Node(x);
    Node *temp=*r;
    if(*r==NULL){*r=n;return;}
    Node* par=NULL,*curr=*r;
    while(curr){
    	par=curr;
    	if(par->data()>=x)curr=curr->left;
    	else curr=curr->right;
    }
    if(par->data()>=x)par->left=n;
    else par->right=n;
}
void rInsert(Node** root,int x){
	if(*root==NULL){
		Node* n=new Node(x);
		*root=n;
		return;
	}
	if(x<=(*root)->data())return rInsert(&(*root)->left,x);
	else return rInsert(&(*root)->right,x);
}
int depth(Node* root){
	queue<Node*> q;
	q.push(root);
	int h=0;
	int count=1;
	while(1){
		count=q.size();
		if(count==0)return h-1;
		h++;
		while(count>0){
			Node* n=q.front();
			q.pop();
			if(n->left)q.push(n->left);
			if(n->right)q.push(n->right);
			count--;
		}
	}
}
int rDepth(Node* root){
	if(root==NULL)return -1;
	int max=rDepth(root->left)>rDepth(root->right)?1+rDepth(root->left):1+rDepth(root->right);
	return max;
}
void preorder(Node* r){
	stack<Node*> s;
	s.push(r);
	while(!s.empty()){
		Node* temp=s.top();
		s.pop();
		cout<<temp->data()<<" ";
		if(temp->right)s.push(temp->right);
		if(temp->left)s.push(temp->left);
	}
	cout<<endl;
}
void inorder(Node* r){
	stack<Node*> s;
	Node* temp=r;
	while(temp||!s.empty()){
		while(temp){
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		cout<<temp->data()<<" ";
		temp=temp->right;
	}
	cout<<endl;
}
void postorder(Node* r){
	if(r=NULL)return;
	stack<Node*> s;
	Node* temp=r;
	while(temp||!s.empty()){
		while(temp){
			if(temp->right)s.push(temp->right);
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		if(temp->right && s.top()==temp->right){
			s.pop();
			s.push(temp);
			temp=temp->right;
		}
		else{
			cout<<temp->data()<<" ";
			temp=NULL;
		}

	}
	cout<<endl;
}
void rPreorder(Node* r){
	if(r==NULL)return;
	cout<<r->data()<<" ";
	rPreorder(r->left);
	rPreorder(r->right);
}
void rInorder(Node* r){
	if(r==NULL)return;
	rInorder(r->left);
	cout<<r->data()<<" ";
	rInorder(r->right);
}
void rPostorder(Node* r){
	if(r==NULL)return;
	rPostorder(r->left);
	rPostorder(r->right);
	cout<<r->data()<<" ";
}
Node* min(Node* r){
	if(r->left==NULL)return r;
	r->left=min(r->left);
}
Node* del(Node* r,int n){
	if(r==NULL)return r;
	else if(r->data()<n)r->left=del(r->left,n);
	else if(r->data()>n)r->right=del(r->right,n);
	else {
		if(r->left==NULL && r->right==NULL){
			delete r;
			r=NULL;
		}
		else if(r->left==NULL){
			Node* temp=r;
			r=r->right;
			delete temp;
		}
		else if(r->right==NULL){
			Node* temp=r;
			r=r->left;
			delete temp;
		}
		else{
			Node* temp=min(r->right);
			r->sdata(temp->data());
			r->right=del(r->right,temp->data());
		}
	}
	return r;

}
void lPrint(Node* r){
    queue<Node*> q;
    q.push(r);
    while(!q.empty()){
    	Node* temp=q.front();
    	cout<<temp->data()<<" ";
    	if(temp->left)q.push(temp->left);
    	if(temp->right)q.push(temp->right);
    	q.pop();
    }
    cout<<endl;

}

int main(){
    Node* root=NULL;
    rInsert(&root,8);
    rInsert(&root,3);
    rInsert(&root,1);
    rInsert(&root,6);
    rInsert(&root,4);
    rInsert(&root,7);
    Insert(&root,12);
    Insert(&root,10);
    Insert(&root,18);
    Insert(&root,13);
    //cout<<depth(root)<<endl;
    //cout<<rDepth(root)<<endl;
    //lPrint(root);
    //preorder(root);
    del(root,4);
    rInorder(root);cout<<endl;
    inorder(root);
    //postorder(root);

}
