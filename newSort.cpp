#include<bits/stdc++.h>
using namespace std;
void swap(int* a,int* b){
    int t=*a;*a=*b;*b=t;
}

int partition(int* a,int l,int r){
    int pivot=a[r];
    int i=l,j;
    for(j=l;j<r;j++){
        if(a[j]<pivot){
            swap(&a[i],&a[j]);
            i++;
        }
    }
    swap(&a[r],&a[i]);
    return i;
}

void quickSort(int*a,int l,int r){
    if(l>=r)return;
    int p=partition(a,l,r);
    quickSort(a,l,p-1);
    quickSort(a,p+1,r);
}

void selSort(int* a,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j])swap(a+i,a+j);
        }
    }
}

void insSort(int* a,int n){
    int j,key;
    for(int i=0;i<n;i++){
        key=a[i],j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(int* a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j])swap(a+j+1,a+j);
        }
    }
}

void iQuickSort(int* a,int l,int r){
    if(l>=r)return;
    stack<int> s;
    s.push(l);
    s.push(r);
    while(!s.empty()){

        r=s.top();s.pop();
        l=s.top();s.pop();
        int p=partition(a,l,r);
        if(p-1>l){
            s.push(l);
            s.push(r);
        }
        if(p+1<r){
            s.push(p+1);
            s.push(r);
        }
    }
}

void countSort(int* a,int n,int e){
    int c[10]={0};
    for(int i=0;i<n;i++){
        c[(a[i]/e)%10]++;
    }
    for(int i=1;i<10;i++){
        c[i]+=c[i-1];
    }
    int b[n];
    for(int i=n-1;i>=0;i--){
        b[c[(a[i]/e)%10]-1]=a[i];
        c[(a[i]/e)%10]--;
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}

void radixSort(int* a,int n){
    int m=*max_element(a,a+n);
    int digits=0;
    for(int exp=1;m/exp>0;exp*=10)4
        countSort(a,n,exp);
}

int main(){
    int a[]={40,33,536,111,567,342,825,1199,2};
    radixSort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
}
