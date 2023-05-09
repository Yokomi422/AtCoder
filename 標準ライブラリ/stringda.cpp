#include <iostream>
#include <iomanip>
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
#include <typeinfo>
#include <utility>
#include <list>
#include <numeric>

using namespace std;
#define rep(i,k, n) for (int i = k; i < (int)(n); i++)

//部分文字列の場所を見つける find abc122Cを参照
int main() {
    string str = "Hello, world!";
    string substr = "world";

    size_t pos = str.find(substr); // substrが出現する位置を検索

    if (pos != string::npos) {
        cout << "Substring found at position " << pos << endl; // 出現する位置を表示
    } else {
        cout << "Substring not found" << endl; // 出現しない場合
    }
    return 0;
}