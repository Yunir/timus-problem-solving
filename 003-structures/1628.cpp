#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

/* 469 */
/* White Streaks */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1628 */

struct block {
    long long x;
    long long y;
};

bool compareX(block const& a, block const& b){
    return a.x < b.x;
}
bool compareY(block const& a, block const& b){
    return a.y < b.y;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int m, n, count;
    cin >> m >> n >> count;
    ++count;
    block *list = new block[count];
    for (int i = 0; i < count-1; ++i) {
        cin >> list[i].x >> list[i].y;
    }

    list[count-1].x = m + 1;
    list[count-1].y = n;
    map<string, int> points;
    stable_sort(list, list+count, &compareX);
    stable_sort(list, list+count, &compareY);
    /*for (int i = 0; i < count; ++i) {
        cout << list[i].x << " " << list[i].y << endl;
    }*/
    int x = 0, y = 1;
    int sum = 0;
    if(n == 1) {
        for (int i = 0; i < count; ++i) {
            int diffX = list[i].x - x;
            if (diffX > 1) ++sum;
            x = list[i].x;
        }
        cout << sum << endl;
        return 0;
    } else if (m == 1) {
        list[count-1].x = m;
        list[count-1].y = n + 1;
        stable_sort(list, list+count, &compareX);

        /*for (int i = 0; i < count; ++i) {
            cout << list[i].x << " " << list[i].y << endl;
        }*/
        x = 1; y = 0;
        for (int i = 0; i < count; ++i) {
            int diffY = list[i].y - y;
            if (diffY > 1) ++sum;
            y = list[i].y;
        }
        cout << sum << endl;
        return 0;
    }
    for (int i = 0; i < count; ++i) {
        int diffY = list[i].y - y;
        if (diffY) {
            if(x+1 >= m) --diffY;
            if(m-x == 1) {
                ++x;
                string s = to_string(x) + ";" + to_string(y);
                points[s] = 99;
            }
            sum += diffY;
            x = 0;
        }
        int diffX = list[i].x - x;
        if (diffX > 2) ++sum;
        //cout << "diffX = " << diffX << " diffY = " << diffY << " sum = " << sum << " x = " << list[i].x << " " << x << " y = " << list[i].y << " " << y << endl;
        x = list[i].x;
        y = list[i].y;
        if (diffX == 2) {
            --x;
            string s = to_string(x) + ";" + to_string(y);
            points[s] = 99;
            ++x;
        }
    }
    //cout << "=====" << endl;
    //cout << sum << endl << "=====" << endl;
    list[count-1].x = m;
    list[count-1].y = n + 1;
    stable_sort(list, list+count, &compareX);
    /*for (int i = 0; i < count; ++i) {
        cout << list[i].x << " " << list[i].y << endl;
    }*/
    x = 1, y = 0;
    for (int i = 0; i < count; ++i) {
        int diffX = list[i].x - x;
        if (diffX) {
            if(y+1 >= n) --diffX;
            if(n-y == 1) {
                ++y;
                //cout << "xx " << x << " y " << y << endl;
                string s = to_string(x) + ";" + to_string(y);
                if(points[s] == 99) ++sum;
            }
            sum += diffX;
            y = 0;
        }
        int diffY = list[i].y - y;
        if (diffY > 2) ++sum;
        //cout << "diffX = " << diffX << " diffY = " << diffY << " sum = " << sum << " x = " << list[i].x << " " << x << " y = " << list[i].y << " " << y << endl;
        x = list[i].x;
        y = list[i].y;
        if (diffY == 2) {
            --y;
            string s = to_string(x) + ";" + to_string(y);
            if(points[s] == 99) ++sum;
            //cout << "x " << x << " y " << y << " p " << points[s] << " sum " << sum << endl;
            ++y;
        }
    }
    /*for (int i = 0; i < count; ++i) {
        cout << list[i].x << " " << list[i].y << endl;
    }*/
    //cout << "=====" << endl;
    cout << sum << endl;
    return 0;
}