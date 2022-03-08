#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
typedef pair<int,int> PII;
vector<PII> a;
bool cmp(PII b,PII c)
{

}
int main()
{
    int n;
    cin>>n;
    int st,ed;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    //区间合并
    sort(a.begin(),a.end(),cmp);

}