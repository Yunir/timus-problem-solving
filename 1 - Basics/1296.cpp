#include <iostream>

/* 102 */
/* Гиперпереход */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1296 */

int getEnergy(int max, int res) {
    int n;
    while(std::cin >> n) {
        if(n < 0) {
            if(max+n <= 0) {
                res = std::max(res, max);
                max = 0;
            } else {
                max = std::max(max, getEnergy(max+n, res));
                res = std::max(res, max);
            }
        } else {
            max += n;
        }
    }
    if(n >= 0) res = std::max(res, max);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t;
    std::cin >> t;
    std::cout << getEnergy(0, 0);
    return 0;
}
