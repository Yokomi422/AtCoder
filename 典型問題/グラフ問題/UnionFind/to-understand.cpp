#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cassert>
#include <bitset>

using namespace std;
#define rep(i,k, n) for (int i = k; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;

#include <iostream>
#include <vector>
using namespace std;


struct UnionFind {
    vector<int> par,siz,rank;
    //コンストラクタ
    UnionFind(int n) : par(n,-1),siz(n,1),rank(n,0) {};
    //値を求める
    int root(int x) {
        if (par[x] == -1) return x;
        else par[x] = root(par[x]);
    };
    //連結か否かを判定する
    bool issame(int x, int y) {
        return root(x) == root(y);
    };
    //union
    bool unite(int x, int y) {
        int rx = root(x), ry = root(y);
        //union by rank
        //ryをrxに突っつける
        if (issame(x,y)) return false;
        if (rank[rx] < rank[ry]) swap(rx,ry);
        par[ry] = rx;
        //ここわからない。どうしてryの変更はしないのか
        //わかった。子供要素は実際どうでも良くて、大切なのは親要素なのだ。
        if (rank[ry] == rank[rx]) rank[rx]++;
        siz[rx] += siz[ry];
    }
    int size(int x) {
        return siz[root(x)];
    }
};