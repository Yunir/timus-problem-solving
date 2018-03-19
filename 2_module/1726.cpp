#include <iostream>
#include <algorithm>
using namespace std;

/* 267 */
/* Кто ходит в гости… */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1726 */

struct Neighbour {
    long long x;
    long long y;
};

bool compareX(Neighbour const& a, Neighbour const& b){
    return a.x < b.x;
}
bool compareY(Neighbour const& a, Neighbour const& b){
    return a.y < b.y;
}

int count(long n, long k) {
    if(n==k)
        return 1;
    if(k==1)
        return n;
    return count(n-1, k-1)+count(n-1, k);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    long long n, leftside, rightside;
    long long sum = 0, res;
    cin >> n;
    auto *list = new Neighbour[n];
    for (int i = 0; i < n; ++i) {
        cin >> list[i].x >> list[i].y;
    }
    stable_sort(list, list+n, &compareY);
    //work with all paths
    for (int i = 0; i < n-1; ++i) {
        leftside = i+1;
        rightside = n-(i+1);
        sum += (list[i+1].y - list[i].y)*leftside*rightside*2;
    }
    stable_sort(list, list+n, &compareX);
    for (int i = 0; i < n-1; ++i) {
        leftside = i+1;
        rightside = n-(i+1);
        sum += (list[i+1].x - list[i].x)*leftside*rightside*2;
    }
    res = sum/(n*(n-1));
    cout << res << endl;
    return 0;
}