#include <iostream>
#include <list>

using namespace std;

/* 291 */
/* War Games 2 */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1521 */
int soldier_id = 0;

int find(pair<int, int> *t, int pos, int left, int right, int needed_id) {
    if (left == right) {
        --t[pos].first;
        return t[pos].second;
    }
    int medium = (left+right) / 2;
    --t[pos].first;
    if (t[2*pos].first >= needed_id)
        find(t, 2*pos, left, medium, needed_id);
    else
        find(t, 2*pos+1, medium+1, right,needed_id-t[2*pos].first);
}

void build_tree(pair<int, int> *t, int pos, int left, int right) {
    if (left == right) {
        t[pos].first = 1;
        t[pos].second = ++soldier_id;
        return;
    }

    int medium = (left+right) / 2;

    build_tree(t, 2*pos, left, medium);
    build_tree(t, 2*pos+1, medium+1, right);

    t[pos].first = t[2*pos].first + t[2*pos+1].first;
    t[pos].second = -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif


    int n, c;
    cin >> n >> c;

    pair<int, int> tree[4*n];
    build_tree(tree, 1, 1, n);

    int current = c;
    for (int i=0; i<n; ++i) {
        int soldier_id = find(tree, 1,1,n, current);
        cout << soldier_id << " ";
        if (i == n-1) break;
        current = (current-1+c)%(n-1-i);
        if (!current) current += n-1-i;
    }
    return 0;
}