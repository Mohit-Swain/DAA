#include<bits/stdc++.h>
using namespace std;
void Copy(int **a,int ** b,int **c,int n,int i1,int j1){
    for(int i=0;i< n;i++){
        for(int j=0;j< n;j++){
            b[i1 + i][j1 + j] = a[i][j];
        }
    }
}
void add(int **a,int **b,int **c,int n,int i1,int j1){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i1+i][j1+j] = a[i][j] + b[i][j]; 
        }
    }
}
int ** mul(int** A,int** B,int n){
    int **C;
    C = new int*[n];
    for(int i=0;i<n;i++){
        C[i] = new int[n];
    }
    if(n<=2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                C[i][j] = 0;
                for(int k=0;k<n;k++){
                    C[i][j] += A[i][k] * B[j][k];
                }
            }
        }
        return C;
    }
    // &(*(A + i) + j) a = &(*(A+0)+0), b = &(*(A+0)+n/2), c = &(*(A+n/2)+0),d = &(*(A+n/2)+n/2) 
    int **ae = mul(((A+n/2*0)+0),((B+n/2*0)+0) ,n/2);
    int **bg = mul(((A+n/2*0)+n/2),((B+n/2*n/2)+0) ,n/2);
    int **af = mul(((A+n/2*0)+0),((B+n/2*0)+n/2) ,n/2);
    int **bh = mul(((A+n/2*0)+n/2),((B+n/2*n/2)+n/2) ,n/2);

    int **ce = mul(((A+n/2*n/2)+0),((B+n/2*0)+0) ,n/2) ;
    int **dg = mul(((A+n/2*n/2)+n/2),((B+n/2*n/2)+0) ,n/2);
    int **cf = mul(((A+n/2*n/2)+0), ((B+n/2*0)+n/2) ,n/2);
    int **dh = mul(((A+n/2)+n/2),((B+n/2*n/2)+n/2) ,n/2);

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
    int **a,**b;

    cout << "enter the "<< n * n << " numbers of first matrix" <<endl;
    a = new int*[n];
    for(int i=0;i<n;i++){
        a[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout << "enter the "<< n * n << " numbers of second matrix" <<endl;
    b = new int*[n];
    for(int i=0;i<n;i++){
        b[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }

    int ** c = mul(a,b,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}