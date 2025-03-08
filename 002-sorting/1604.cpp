#include <iostream>
#include <algorithm>

using namespace std;

/* 324 */
/* Country of Fools */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1604 */

struct Sign {
    int id;
    int count;
};

bool descCompare(Sign const& a, Sign const& b){
    return a.count > b.count;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int k, all = 0;
    cin >> k;
    auto *n = new Sign[k];
    for (int i = 0; i < k; ++i) {
        n[i].id = i+1;
        cin >> n[i].count;
        all += n[i].count;
    }
    sort(n, n+k, descCompare);
    auto *subline = new int[n[0].count*2+1];

    int pointer = 1, lmt = n[0].count;
    for (int i = 0; i < lmt; ++i) {
        subline[i*2] = n[0].id;
        --n[0].count;
        if (n[pointer].count == 0) ++pointer;

        //lack of difference
        if(pointer == k) {
            for (int j = 0; j <= i*2; ++j) {
                cout << subline[j] << " ";
            }
            while (n[0].count) {
                cout << n[0].id << " ";
                --n[0].count;
            }
            return 0;
        }

        subline[i*2+1] = n[pointer].id;
        --n[pointer].count;
    }
    if (n[pointer].count == 0) ++pointer;

    //full difference
    for (int l = 0; l < lmt; ++l) {
        cout << subline[l*2] << " " << subline[l*2+1] << " ";
        for (int i = pointer; i < k; ++i) {
            if(!n[i].count) continue;
            cout << n[i].id << " ";
            --n[i].count;
        }

    }


    /*int sum = n[0].count, pos = 0, first = 1, last = k;
    bool begin = true, less = false;
    while(sum > 0) {
        if(pos == k) {
            less = true;
            break;
        }
        ++pos;
        sum -= n[pos].count;
    }*/

    /*sum = abs(sum);
    while (n[0].count) {
        if(!begin) cout << " ";
        cout << n[0].id;
        --n[0].count;
        if (n[first].count) {
            --n[first].count;
            cout << " " << n[first].id;
        }
        if (!n[first].count && first != pos) ++first;
        if (sum && !less){
            cout << " " << n[pos].id;
            --n[pos].count;
            --sum;
        }
        for (int i = pos+1; i < last; ++i) {
            if(n[i].count) {
                cout << " " << n[i].id;
                --n[i].count;
            }
        }
        if (!n[last].count) --last;
        begin = false;
    }*/
    return 0;
}