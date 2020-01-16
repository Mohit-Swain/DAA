#include<bits/stdc++.h>
using namespace std;
int binary(int a[],int s,int e,int key){
	if(s>e){
		return -1;
	}
	
	int mid = (s+e)/2;
	if(a[mid]==key){
		return mid;
	}
	else if(a[mid]<key){
		return binary(a,mid+1,e,key);
	}
	else{
		return binary(a,s,mid -1 ,key);
	}
}
int terniary(int a[],int s,int e,int key) {
	if(s>e){
		return -1;
	}
	
	int mid1 = (s + 2*e)/3;
	int mid2 = (2*s + e)/3;
	
	if(a[mid1]==key){
		return mid1;
	}
	else if(a[mid2]==key){
		return mid2;
	}
	else if(key < a[mid1]){
		return terniary(a,s,mid2-1,key);
	}
	else if(key > a[mid2]){
		return terniary(a,mid1+1,e,key);
	}
	else{
		return terniary(a,mid1+1,mid2-1,key);
	}
}
int main(){
	int n, key;
	cout<<"Enter the number of elements";
	cin>>n;
	int a[n];
	cout<<"Enter n elements ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cout<<"Enter Key ";
	cin>>key;
	cout<<binary(a,0,n-1,key)<<endl;
	cout<<terniary(a,0,n-1,key)<<endl;
	return 0;
}
