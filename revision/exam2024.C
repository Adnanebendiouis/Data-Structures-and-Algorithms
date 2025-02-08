#include<stdio.h>
int max( int a, int b){
    return a>b?a:b;
}
struct cellule {
    int val;
    struct cellule *suivant;
};
typedef struct cellule cellule;
typedef cellule *Liste;

void Fusioneriter(int A[], int sizeA,int B[],int sizeB, int T[]) {
    int j=0;
 for(int i=0;i<max(sizeA,sizeB);i++){
     if(A[i]<B[i]){
         T[i]=A[i];
     }
     else{
         T[i]=B[j];
         j++;
     }
 }
 if(sizeA<sizeB){
    for(int i = sizeB-sizeA;i<sizeB;i++){
      T[i]=B[j++];
    }
 }
 else{
    for(int i = sizeA-sizeB;i<sizeA;i++){
      T[i]=A[i];
    }
 }
}
void fusionerrec(int A[], int sizeA, int sizeB, int B[], int T[],int i,int j,int k){
    if(i<sizeA && j<sizeB){
        if(A[i]<B[j]){
            T[k++]=A[i++];
        }else{
            T[k++]=B[j++];
        }
        fusionerrec(A,sizeA,sizeB,B,T,i,j,k);
    }
    if(i<sizeA){
        T[k++]=A[i++];
        fusionerrec(A,sizeA,sizeB,B,T,i,j,k);
    }
    if(j<sizeB){
        T[k++]=B[j++];
        fusionerrec(A,sizeA,sizeB,B,T,i,j,k);
    }
}
int nbrocc(int t[],int n,int val){
    int occ =0;
    for(int i=0;i<n;i++){
        if(t[i]==val)
        occ++;
    }
    return occ;
}
Liste creeliste(int t[];int n){
    if(n==0)
    return NULL;
    Liste head = NULL;


    for(int i = 0;i<n;i=i+nbrocc(t,n,t[i])){
        Liste current = malloc(sizeof(cellule));
        current->val = t[i];
        current->occ = nbrocc(t,n,t[i]);   
        current->suivant = NULL;
        if(head == NULL){
            head = current;
        }
        else{
            Liste tmp = head;
            while(tmp->suivant != NULL){
                tmp = tmp->suivant;
            }
            tmp->suivant = current;
        }
    }
    return head;

}
 Liste ajouterfin(Liste l,int val){
    cellule newelement = malloc (sizeof) 
 }
int main(){
    int a[4]={2,5,8,10};
    int b[]={2,3,5,6,7,8,8,9,10,12};
    int sizeb=sizeof(b)/sizeof(b[0]);
    int sizea=sizeof(a)/sizeof(a[0]);
    int size = sizea+sizeb;
    int t[size];
    fusionerrec(a,sizea,sizeb,b,t,0,0,0);
    for(int i =0;i<size;i++){
        printf("%d |",t[i]);
    }
}