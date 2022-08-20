#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int> > vc(n,vector<int> (m));
  int n_of_1=0;
  string s;
  for(int i=0;i<n;i++){
    cin>>s;
    for(int j=0;j<m;j++){
      vc[i][j]=s[j]-'0';
      n_of_1+=vc[i][j];
    }
  }
  int cnt_1=INT_MAX;
  int op=0;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m-1;j++){
      int temp=vc[i][j]+vc[i+1][j]+vc[i][j+1]+vc[i+1][j+1];
      cnt_1=min(cnt_1,temp);
      if(cnt_1==0) op=0;
      else if(cnt_1==1) op=1;
      else if(cnt_1>=2) op=2;
    }
  }
  cout<<n_of_1-cnt_1+op<<endl;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  cin >> T;
  while (T--)
  {
    solve();
  }
  return 0;
}
