#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int parent[N];
int size[N];

void make(int v)
{
  parent[v] = v;
  size[v] = 1;
}

int find(int v)
{
  if (v == parent[v])
  {
    return v;
  }
  return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
  int pa = find(a);
  int pb = find(b);
  if (pa != pb)
  {
    if (sizes[pa] < sizes[pb])
      swap(pa, pb);
    parent[pb] = pa;
    size[pa] += size[pb];
  }
}

void solve()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    make(i);
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int a, b;
    cin >> a >> b;
    Union(a, b);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    if (parent[i] == i)
    {
      cnt++;
    }
  }
  cout << cnt << "\n";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
