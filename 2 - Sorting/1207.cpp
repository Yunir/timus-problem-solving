#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/* 179 */
/* Медиана на плоскости */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1207 */

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t,  x = numeric_limits<int>::max(), y = numeric_limits<int>::max(), choosed = -1;
    cin >> t;
    int *xs = new int[t];
    int *ys = new int[t];
    map<double, int> num;
    vector<int> numV;
    for (int i = 0; i < t; ++i) {
        cin >> xs[i] >> ys[i];
        if (xs[i] < x || (xs[i] == x && ys[i] < y)) {
            y = ys[i];
            x = xs[i];
            choosed = i;
        }
    }
    for (int j = 0; j < t; ++j) {
        if (j != choosed) {
            if (xs[j] == x) continue;
            num[(double)(ys[j]-y)/(xs[j]-x)] = j+1;
        }
    }
    transform(num.begin(), num.end(), back_inserter(numV), [](const map<float, int>::value_type& val){return val.second;} );
    cout << choosed+1 << " " << numV[(t-1)/2] << endl;
    cout << endl;
    return 0;
}