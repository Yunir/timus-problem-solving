#include <iostream>
/* Стенка на стенку */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=2025 */

int rec(int n, int k) {
    if(n==k)
        return 1;
    if(k==1)
        return n;
    return rec(n-1, k-1)+rec(n-1, k);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int t, n, k, min, res;

    std::cin >> t;
    while (std::cin >> n >> k) {


        if (n > k) {
            res = rec(k, 2);
            min = n/k;
            if(n%k == 0) res = res*min*min;
            else {
                res = 0;
                int a, b;
                for (int i = 0; i < k; ++i) {
                    a = i < n%k ? min+1 : min;
                    for (int j = i+1; j < k; ++j) {
                        b = j < n%k ? min+1 : min;
                        res += a*b;
                    }
                }
            }
        } else {
            res = rec(n, 2);
        }
        std::cout << res << std::endl;
    }
    return 0;

}
