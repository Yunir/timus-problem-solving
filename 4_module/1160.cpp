#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

#define INF 1000000000
using namespace std;

/* 325 */
/* Network */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1160 */

struct connection {
    int from, to, length;
};

int sortLength(connection const &left, connection const &right){
    return left.length < right.length;
}

vector<int> p(1000);
int dsu_get (int v) {
    return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
    a = dsu_get (a);
    b = dsu_get (b);
    if (rand() & 1)
        swap (a, b);
    if (a != b)
        p[a] = b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    bool completed = false;
    int hubsCount, connectionsCount, countOfSelected = 0, countOfConnections = 0, maxOfMin, separated = 0;
    scanf("%d%d", &hubsCount, &connectionsCount);
    vector<connection> g;
    int selected[hubsCount];
    for (int i = 0; i < hubsCount; ++i) {
        selected[i] = -1;
    }
    for (int i = 0; i < connectionsCount; ++i) {
        connection temp;
        scanf("%d%d%d", &temp.from, &temp.to, &temp.length);
        --temp.from; --temp.to;
        g.push_back(temp);
    }
    sort(g.begin(), g.end(), &sortLength);

    int cost = 0;
    vector < pair<int,int> > res;
    p.resize (hubsCount);
    for (int i=0; i<hubsCount; ++i)
        p[i] = i;

    for (int i=0; i<connectionsCount; ++i) {
        int a = g[i].from,  b = g[i].to,  l = g[i].length;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            res.push_back (make_pair(g[i].from, g[i].to));
            dsu_unite (a, b);
            maxOfMin = l;
        }
    }
    cout << maxOfMin << endl;
    cout << res.size() << endl;
    for(pair<int, int> k : res) cout << k.first+1 << " " << k.second+1 << endl;

    /*ostringstream os;
    map<int, int> isolated;
    for (int i = 0; i < g.size(); ++i) {
        if(countOfSelected >= hubsCount && g[i].length > maxOfMin && separated == 0) break;
        if(selected[g[i].to] == -1 || selected[g[i].from] == -1) {
            bool a = false, b = false;
            if(selected[g[i].to] == -1) {
                a = true;
                selected[g[i].to] = g[i].length;
                ++countOfSelected;
            }
            if (selected[g[i].from] == -1) {
                b = true;
                selected[g[i].from] = g[i].length;
                ++countOfSelected;
            }
            if(a && b) {
                ++separated;

                isolated
            }
            maxOfMin = g[i].length;
            ++countOfConnections;
            os << g[i].from+1 << " " << g[i].to+1 << endl;
        } else if (maxOfMin <= g[i].length) {
            ++countOfConnections;
            os << g[i].from+1 << " " << g[i].to+1 << endl;
        }
    }*/
    /*cout << maxOfMin << endl;
    cout << countOfConnections << endl;
    cout << os.str();*/


    return 0;
}