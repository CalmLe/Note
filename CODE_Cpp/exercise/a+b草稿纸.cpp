#include<iostream>
#include<vector>
using namespace std;

bool flag=0;

vector<int> add(vector<int> &A,vector<int> &B)
{
    vector<int> C;
    int t=0;
    for(auto i=0;i<A.size()||i<B.size();i++)
    {
        if(i<A.size())t+=A[i];
        if(i<B.size())t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t)C.push_back(t);
    return C;
}

vector<int> sub(vector<int> &A,vector<int> &B)
{
	if(A.size()<=B.size()){
		int i;
		for( i=A.size()-1;i>=0;i--){
			if(A[i]<B[i])break;
		}
		if(i>=0){
			flag=1;
			return sub(B,A);
		}		
	}
	vector<int> C;
	int t=0;
	for(int i=0;i<A.size();i++)
	{
		t=A[0]-t;
		if(i<B.size())t-=B[i];
		C.push_back((t+10)%10);
		t/=10;
	}
	if(t<0)t=1;
	else t=0;
	while(C.size()>1&&C.back()==0)C.pop_back();
	return C;
 } 
 
int main()
{
    string a,b;
    vector<int> A,B;
    cin>>a>>b;
	
    if(a[0]!='-')
	{
		if(b[0]!='-')
		{
			for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
		    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
		    auto C=add(A,B);
		    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
		}else
		{
			for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
		    for(int i=b.size()-1;i>0;i--)B.push_back(b[i]-'0');
		    auto C=sub(A,B);
		    if(flag)cout<<"-";
		    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
		}
	}else{
		if(b[0]!='-'){
			for(int i=a.size()-1;i>0;i--)A.push_back(a[i]-'0');
		    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
		    auto C=sub(B,A);
		    if(flag)cout<<"-";
		    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
		}else{
			for(int i=a.size()-1;i>0;i--)A.push_back(a[i]-'0');
		    for(int i=b.size()-1;i>0;i--)B.push_back(b[i]-'0');
		    auto C=add(A,B);
		    cout<<"-";
		    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
		}
	}
	
    return 0;
}