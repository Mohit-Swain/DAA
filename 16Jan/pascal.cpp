#include<iostream>
using namespace std;
int dp[100][100] = {0};

int pascal(int r,int i){
	if(i<0){
		return 0;
	}
	
	if(dp[r][i]!=0)
		return dp[r][i];
		
	if(i == 0 || i==r){
		dp[r][i] = 1;
		return dp[r][i];
	}
	
	int ans = pascal(r-1,i-1) + pascal(r-1,i);
	dp[r][i] = ans;
	
	return dp[r][i];
}

void pascal_helper(int r){
	for(int i=0;i<r;i++)	
		pascal(r,i);
	
	for(int i=0;i<r;i++){
		for(int j = 0 ; j<= i;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
}
int main(){
	int r;
	cout<<"Enter the number of rows you wanna see ";
	cin>>r;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	pascal_helper(r);
}
