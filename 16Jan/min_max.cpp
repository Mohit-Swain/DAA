#include<iostream>
#include<climits>
using namespace std;

class Pair{
public:
	int min,max;
	Pair(){
		min = INT_MAX;
		max = INT_MIN;
	}
	
	Pair(int min,int max){
		this->min = min;
		this->max = max;
	}
};

Pair min_max(int a[],int s,int e){
	if(s>e){
		Pair p;
		return p;
	}
	if(s==e){
		Pair p(a[s],a[s]);
		return p;
	}
	
	int mid = (s+e)/2;
	Pair c1 = min_max(a,s,mid-1);
	Pair c2 = min_max(a,mid + 1,e);
	
	Pair ans;
	ans.max = max(a[mid],max(c1.max,c2.max));
	ans.min = min(a[mid],min(c1.min,c2.min));
	
	return ans;
	
};

int main(){
	int n;
	cout<<"Enter the size of the array ";
	cin>>n;
	int a[n];
	cout<<"Enter "<<n<<" numbers"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	Pair ans = min_max(a,0,n-1);
	
	cout<<"max is "<<ans.max<<endl;
	cout<<"min is "<<ans.min<<endl;
	return 0;
}
