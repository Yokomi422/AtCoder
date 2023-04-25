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
//練習問題 https://pyteyon.hatenablog.com/entry/2019/02/20/194140
//https://qiita.com/ganyariya/items/33f1326154b85db465c3
int main() {
    //昇順のソートが施された配列に対してある要素がその配列に含まれているかを判定する binary_search(list.begin(),list.end(),n)
    vector<int> A(10);
    rep(i,0,10) A[i] = i+1;
    cout << binary_search(A.begin(),A.end(),4) << endl;
     
}
//setに対して使う場合はset.lower_boundを使わないとS(N)になる。それ以外はS(logN)
//lower_bound n以上の整数を持つ最小値を取り出す。(indexではなく、その数を出す。)
//応用例　1.lower_boundはnより小さい値の数を示す。2.(総数-lower_bound)はn以上の個数を示す
int main() {
    vector<int> A(10);
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
    cout << *lower_bound(a.begin(),a.end(),5) << endl;
    //1.の例　正直イテレータとかポイントとかよくわからない。*がないことに注意
    cout << lower_bound(a.begin(),a.end(),12) - a.begin() << endl;
    //2.の例
    cout <<  a.end() - lower_bound(a.begin(),a.end(),12) << endl;
}

//upper_bound keyより大きい要素のうちの一番一番左のイテレータを出力
//1.n以下の値の個数を出力する 2.nより大きい個数を出力する
int main() {
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
    //1.
    cout << lower_bound(a.begin(),a.end(),12) - a.begin() << endl;
    //2.
    cout <<  a.end() - lower_bound(a.begin(),a.end(),12) << endl;
}

//それぞれを用いた応用 ある要素の個数を出力
int main() {
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
    cout << lower_bound(a.begin(),a.end(),12) - upper_bound(a.begin(),a.end(),12) << endl;
}