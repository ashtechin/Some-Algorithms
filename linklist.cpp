#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* next;
};
void insertBeg(Node** h,int x){
Node* p=new Node;
p->data=x;
p->next=*h;
*h=p;
}
void insertEnd(Node** h,int x){
Node** p=h;
while(*p){
p=&(*p)->next;
}
*p=new Node;
(*p)->data=x;
(*p)->next=NULL;
}
void insertRend(Node** h,int x){
    if(*h==NULL){
        Node* n=new Node;
        n->data =x;
        n->next=NULL;
        *h=n;
        return ;
    }
    else return insertRend(&((*h)->next),x);
}
void insertKey(Node** h,int x,int key){
	if(*h){
		int flag=0;
		Node* temp=*h;
		while(temp->next){
			if(temp->data==key){flag=1;break;}
			temp=temp->next;
		}
		if(flag){
			Node* n=new Node;
			n->data=x;
			n->next=temp->next;
			temp->next=n;
		}
		else{
			cout<<"Not allowed"<<endl;
		}
	}
	else cout<<"Not Allowed"<<endl;
}
void deleteKey(Node** h,int key){
    if(*h){
    Node* prev=*h,*temp=*h;
    while(temp){
        if(temp->data==key)break;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    }
}
void deleteEnd(Node** h){
    if(*h){
    Node* prev=*h,*temp=*h;
    while(temp->next){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    }
}
void search(Node** h,int key){
    if(*h){
        Node* temp=*h;
        int flag=0;
        while(temp){
            if(temp->data==key){flag=1;break;}temp=temp->next;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
void Rsearch(Node** h,int x){
    
    if((*h)->data==x){
        cout<<"Found"<<"\n"; 
    }
    else if(*h==NULL){
        cout<<"Not Found"<<"\n";
        return ;
    }
    else return Rsearch(&((*h)->next),x);
}
int findN(Node** h,int x){
    if(*h==NULL){cout<<"Can't do";return 0;}
    else if(x==1||x==0)return (*h)->data;
    else return (&(*h)->next,x-1);
}
void deleteFirst(Node** h){
    if(*h){
        Node* temp=*h;
        *h=temp->next;
        free(temp);
    }
}
void print(Node* h){
    Node* temp=h;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void appendList(Node** h1,Node** h2){
    Node* temp=*h1;
    while(temp->next)temp=temp->next;
    temp->next =*h2;
}
void revList(Node** h){
    Node* nxt=NULL,*prv=NULL,*temp=*h;
    while(temp){
        nxt=temp->next;
        temp->next=prv;
        prv=temp;
        temp=nxt;
    }
    *h=prv;
}
void listCpy(Node** h1,Node** h2){
    Node* temp=*h1;
    Node* n;*h2=n;
    while(temp->next){
        n=new Node;
        n->data=temp->data;
        n=n->next;
        temp=temp->next;
    }
}
int length(Node** h){
    if(*h==NULL)return 0;
    else return 1+length(&(*h)->next);
}
Node* tail(Node** h){
    if(*h){
        return tail(&(*h)->next);
    }
    else return *h;
}
void swap(Node* a,Node* b){
    int x=a->data;a->data=b->data;b->data=x;
}
void bubbleSort(Node** h){
    if(*h){
        Node* temp=(*h),*last=NULL,*prev;
        while(temp->next){prev=*h;
            while(prev->next!=last){
                if(prev->data>prev->next->data)swap(prev,prev->next);
                prev=prev->next;
            }
        last=prev;
        temp=temp->next;
        }
    }
}

int main(){
cout<<"Ashutosh Bundela\n181112054\n";
Node* h=NULL;
insertBeg(&h,5);print(h);
insertBeg(&h,7);
insertBeg(&h,4);print(h);
insertEnd(&h,9);print(h);
insertEnd(&h,2);
insertKey(&h,3,5);
print(h);
deleteKey(&h,7);
//	deleteEnd(&h);
//search(&h,11);
//	deleteFirst(&h);
Node* k=NULL;
listCpy(&h,&k);
//	deleteEnd(&h);
//search(&k,11);
//	deleteFirst(&h);
//appendList(&h,&k);
//revList(&h);
//Rsearch(&h,9);
//cout<<findN(&h,2)<<"\n";
//bubbleSort(&h);
print(k);
print(h);
//cout<<length(&h);
return 0;}
