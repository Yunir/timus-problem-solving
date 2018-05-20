#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/* 256 */
/* Раскраска карты */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1080 */

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    int count; // число вершин
    cin >> count;
    vector<int> *cities = new vector<int>[count]; // граф
    for (int i = 0; i < count; ++i) {
        int temp = -1;
        do {
            if (temp != -1){
                cities[i].push_back(temp-1);
                cities[temp-1].push_back(i);
            }
            cin >> temp;
        } while (temp);
    }

    // обход
    int color;
    queue<int> q;
    int *colors = new int[count];
    q.push(0);
    for (int i = 0; i < count; ++i) colors[i] = -1;
    colors[0] = 0;
    color = 1;
    while (!q.empty()) {
        int curr = q.front();
        color = !colors[curr] ? 1 : 0;

        //cout << curr << ". ";

        q.pop();
        for (int i = 0; i < cities[curr].size(); ++i) {
            int to = cities[curr].at(i);

            //cout << "Checking " << curr << "-" << to << " ";
            //cout << colors[to] << " now ";

            if (colors[to] == -1) {
                colors[to] = color;
                q.push(to);
            } else {
                if (colors[to] != color) {
                    cout << -1 << endl;
                    return 0;
                }
            }

            //cout << colors[to] << endl;

        }
    }
    for (int i = 0; i < count; ++i) {
        cout << colors[i];
    }
    cout << endl;
    return 0;
}