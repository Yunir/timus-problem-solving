#include <iostream>
#include <stack>

using namespace std;

/* 188 */
/* Монобильярд */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1494 */

bool validate(int count) {
    int last = 0;
    stack<int> pocket;
    int *balls = new int[count];
    for (int i = 0; i < count; ++i) {
        cin >> balls[i];
    }
    for(int i = 0; i < count; ++i) {
        if(balls[i] > last) {
            for(int j = last + 1; j < balls[i]; ++j) {
                pocket.push(j);
            }
            last = balls[i];
        }
        else {
            if (pocket.top() != balls[i]) return false;
            pocket.pop();
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    cin >> n;
    if (validate(n)) {
        cout << "Not a proof" << endl;
    } else {
        cout << "Cheater" << endl;
    }
    return 0;
}

