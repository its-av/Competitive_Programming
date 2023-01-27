#include <bits/stdc++.h>
#define int long long
using namespace std;
//e+e e o
//e+o o e
//o+o e o

void solve()
{
  int n,temp,o=0,e=0;
  cin>>n;
  vector<pair<int,int>> v;
  for(int i=0;i<n;i++){
    cin>>temp;
    if(temp%2==0) e++;
    else o++;
    v.push_back({temp,i});
  }
  if(o>=3){
    cout<<"YES\n";
    int cnt=0;
    for(int i=0;i<n;i++){
      if(v[i].first%2!=0){
        cout<<i+1<<" ";
        cnt++;
      }
      if(cnt==3){
        cout<<endl;
        break;
      }
    }
  }
  else if(e>=2 && o>=1){
    cout<<"YES\n";
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
      if(v[i].first%2!=0 && cnt2<1){
        cout<<i+1<<" ";cnt2++;
      }
      else if(v[i].first%2==0 && cnt1<2){
        cout<<i+1<<" ";cnt1++;
      }
      if(cnt1==2 && cnt2==1){
        cout<<endl;
        break;
      }
    }
  }
  else{
    //cout<<endl;
    cout<<"NO\n";
  }
  
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
