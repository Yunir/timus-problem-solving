#include <iostream>

/* 91 */
/* Куча камней */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1005 */

int count(int a, int b, int i, int arr[]) {
    if (i-- != 0) {
        return std::min(count(a+arr[i], b, i, arr), count(a, b+arr[i], i, arr));
    } else {
        return std::abs(a-b);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t, n;
    std::cin >> t;
    int arr[t];
    for (int i = 0; i < t; ++i) {
        std::cin >> arr[i];
    }
    std::cout << count(0, 0, t, arr);
    return 0;

}

