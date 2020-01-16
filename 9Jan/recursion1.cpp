#include<iostream>
using namespace std;

int deter(int a[][100],int n){
	if(n==1){
		return a[0][0];
	}
	int sum = 0,i=0;
	
		for(int j=0;j<n;j++){
			int mul = (i+j)%2 == 0 ? 1 : -1;
			int b[100][100],x=0,y=0;
			for(int i1=1;i1<n;i1++){	
				for(int j1=0;j1<n;j1++){		
					if(j!=j1){
						b[x][y] = a[i1][j1];
						y++;
					}
				}
				y = 0;
				x++;
			}
			sum += mul*a[0][j]*deter(b,n-1);	//Non-tail Recursion
			
		}
	
	return sum;
}
int main(){
	int n;
	cout<<"Enter the value of n ";
	cin>>n;
	cout<<"Enter "<<n*n<<" numbers "<<endl;
	int a[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];		
		}
	}
	
	int ans = deter(a,n);
	cout<<ans<<endl;
	return 0;
}
