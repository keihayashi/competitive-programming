#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// 505Bの問題
// UnionFindって何だったっけ？
struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) {}
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};


int main()
{
  int vert, edge, a, b, c, query, ans;
  scanf("%d %d", &vert, &edge);
  UnionFind **UF = new UnionFind*[edge + 1];
  for (int i = 0; i <= edge; i++) {
    UF[i] = new UnionFind(vert + 1);
  }

  for (int i = 0; i < edge; i++) {
    scanf("%d %d %d", &a, &b, &c);
    UF[c]->unionSet(a,b);
  }

  scanf("%d", &query);
  for (int i = 0; i < query; i++) {
    ans = 0;
    scanf("%d %d", &a, &b);
    for (int j = 0; j <= edge; j++) {
      if (UF[j]->findSet(a, b)) ans++;
    }
    cout << ans << endl;
  }
}
