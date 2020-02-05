#include<iostream>
using namespace std;

void mul(int a[][100],int b[][100],int n){
    int c[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j] = 0;
            for(int k=0;k<n;k++){
                c[i][j] += a[i][k] * b[j][k];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout << "enter the size of the matrix ";
    cin >> n;
    int a[100][100] = {0}, b[100][100] = {0};
    cout << "enter the "<< n * n << " numbers of first matrix" <<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout << "enter the "<< n * n << " numbers of second matrix" <<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }

    mul(a,b,n);
    return 0;
}