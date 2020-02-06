#include<bits/stdc++.h>
using namespace std;
int* neg(int *a,int n){
    int *A;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *((A+n*i)+j) = - *((a+n*i)+j);
        }
    }
    return A;
}
void add(int **a,int **b,int **c,int n,int i1,int j1){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i1+i][j1+j] = a[i][j] + b[i][j]; //*((a+i*n)+j) + *((b+i*n)+j); 
        }
    }
}
int ** mul(int* A,int* B,int n){
    int **C;
    C = new int*[n];
    for(int i=0;i<n;i++){
        C[i] = new int[n]();
    }

    if(n<=0){
        return C;
    }
    if(n==1){
        C[0][0] = int(*A) * int(*B);
        return C;
    }
    // &(*(A + i) + j) a = &(*(A+0)+0), b = &(*(A+0)+n/2), c = &(*(A+n/2)+0),d = &(*(A+n/2)+n/2) 
    int *a = ((A+n*0)+0);
    int *b = ((A+n*0)+n/2);
    int *c = ((A+n*n/2)+0);
    int *d = ((A+n*n/2)+n/2);

    int *e = ((B+n*0)+0);
    int *f = ((B+n*0)+n/2);
    int *g = ((B+n*n/2)+0);
    int *h = ((B+n*n/2)+n/2);

    

    int **ae = mul(a,e ,n/2);
    int **bg = mul(b,g ,n/2);
    int **af = mul(a,f ,n/2);
    int **bh = mul(b,h ,n/2);

    int **ce = mul(c,e ,n/2) ;
    int **dg = mul(d,g ,n/2);
    int **cf = mul(c,f ,n/2);
    int **dh = mul(d,h ,n/2);

    add(ae,bg,C,n/2,0,0);
    add(af,bh,C,n/2,0,n/2);
    add(ce,dg,C,n/2,n/2,0);
    add(cf,dh,C,n/2,n/2,n/2);

    return C;
}

int main(){
    int n;
    cout << "enter the size of the matrix ";
    cin >> n;
    int *a,*b;

    cout << "enter the "<< n * n << " numbers of first matrix" <<endl;
    a = new int[n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>*((a+n*i) + j);
        }
    }
    cout << "enter the "<< n * n << " numbers of second matrix" <<endl;
    b = new int[n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>*((b + n*i) + j);
        }
    }
    int ** c = mul((int *)a,(int *)b,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}