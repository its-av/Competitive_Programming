#include <bits/stdc++.h>
#define int long long
using namespace std;
void build(int ind, int low, int high, int arr[], int seg[])
{
  if (low == high)
  {
    seg[ind] = arr[low];
    return;
  }
  int mid = (low + high) / 2;
  build(2 * ind + 1, low, mid, arr, seg);
  build(2 * ind + 2, mid + 1, high, arr, seg);
  seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int query(int ind, int low, int high, int l, int r, int seg[])
{
  if (l == low && r == high)
  {
    return seg[ind];
  }
  else if (r < low || l > high)
  {
    return INT_MAX;
  }
  else
  {
    int a, b;
    int mid = (low + high) / 2;
    a = query(2 * ind + 1, low, mid, l, min(mid, r), seg);
    b = query(2 * ind + 2, mid + 1, high, max(mid + 1, l), r, seg);
    return min(a, b);
  }
}
void update(int ind, int low, int high, int i, int val, int seg[])
{
  if (low == high)
  {
    seg[ind] = val;
    return;
  }
  int mid = (low + high) / 2;
  if (i <= mid)
  {
    update(2 * ind + 1, low, mid, i, val, seg);
  }
  else
  {
    update(2 * ind + 2, mid + 1, high, i, val, seg);
  }
  seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
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
    int n;
    cin >> n;
    // int arr[n];
    int arr[n];
    int seg[4 * n + 1];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    // cout<<"av";
    build(0, 0, n - 1, arr, seg);
    int q;
    cin >> q;
    int type, a, b;
    while (q--)
    {
      cin >> type;
      if (type == 1)
      {
        cin >> a >> b;
        cout << query(0, 0, n - 1, a, b, seg) << endl;
      }
      else
      {
        cin >> a >> b;
        arr[a] = b;
        update(0, 0, n - 1, a, b, seg);
      }
    }
  }
  return 0;
}
