#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> mul(vector<int> &A,vector<int> &B)
{
	vector<int> C(A.size() + B.size(), 0);
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B.size();j++)
		{
			C[i+j]+=A[i]*B[j];
			C[i+j+1]+=C[i+j]/10;
			C[i+j]%=10;
		}
	}
	while(C.size()>1&&C.back()==0)C.pop_back();
	return C;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    string a, b;
    vector<int>A, B, C;
    cin >> a >> b;
    //cnt记录负号出现的次数
    int cnt = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        if(a[i] == '-') cnt++;
        else A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        if(b[i] == '-') cnt++;
        else B.push_back(b[i] - '0');
    }
    if(cnt % 2 != 0 && a[0] != '0' && b[0] != '0') cout << '-';
    C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << endl; 
    return 0;
}