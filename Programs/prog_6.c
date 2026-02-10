#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
} Heap;

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}

void minHeapify(Heap*h,int i){
    int smallest=i,l=left(i),r=right(i);
    if(l<h->size && h->arr[l]<h->arr[smallest]) smallest=l;
    if(r<h->size && h->arr[r]<h->arr[smallest]) smallest=r;
    if(smallest!=i){swap(&h->arr[i],&h->arr[smallest]); minHeapify(h,smallest);}
}

void maxHeapify(Heap*h,int i){
    int largest=i,l=left(i),r=right(i);
    if(l<h->size && h->arr[l]>h->arr[largest]) largest=l;
    if(r<h->size && h->arr[r]>h->arr[largest]) largest=r;
    if(largest!=i){swap(&h->arr[i],&h->arr[largest]); maxHeapify(h,largest);}
}

Heap* buildHeap(int arr[],int n,int isMin){
    Heap*h=(Heap*)malloc(sizeof(Heap));
    h->arr=(int*)malloc(n*sizeof(int));
    h->size=n;
    for(int i=0;i<n;i++) h->arr[i]=arr[i];
    for(int i=n/2-1;i>=0;i--)
        if(isMin) minHeapify(h,i);
        else maxHeapify(h,i);
    return h;
}

int extractRoot(Heap*h,int isMin){
    if(h->size<=0) return -1;
    int root=h->arr[0];
    h->arr[0]=h->arr[h->size-1];
    h->size--;
    if(isMin) minHeapify(h,0);
    else maxHeapify(h,0);
    return root;
}

void displayHeap(Heap*h,char*name){
    printf("%s Heap: ",name);
    for(int i=0;i<h->size;i++) printf("%d ",h->arr[i]);
    printf("\n");
}

int main(){
    int arr[]={45,12,78,34,89,23,67,11,56,90,3,44};
    int n=sizeof(arr)/sizeof(arr[0]);

    Heap* minHeap=buildHeap(arr,n,1);
    Heap* maxHeap=buildHeap(arr,n,0);

    displayHeap(minHeap,"Min");
    displayHeap(maxHeap,"Max");

    printf("Extract Min: %d\n",extractRoot(minHeap,1));
    displayHeap(minHeap,"Min");

    printf("Extract Max: %d\n",extractRoot(maxHeap,0));
    displayHeap(maxHeap,"Max");

    free(minHeap->arr); free(minHeap);
    free(maxHeap->arr); free(maxHeap);

    return 0;
}
