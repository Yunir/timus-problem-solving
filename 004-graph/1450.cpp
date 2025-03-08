#include <iostream>
#include <vector>

#define INF 10001
using namespace std;

/* 313 */
/* Russian Pipelines */
/* link: http://acm.timus.ru/problem.aspx?space=1&num=1450 */

struct edge {
    int from, to, income;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif

    int nodesCount, edgesCount, source, destination;
    scanf("%d%d", &nodesCount, &edgesCount);
    vector<edge> g;
    for (int i = 0; i < edgesCount; ++i) {
        edge temp;
        scanf("%d%d%d", &temp.from, &temp.to, &temp.income);
        --temp.from; --temp.to;
        temp.income = 0 - temp.income;
        g.push_back(temp);
    }
    scanf("%d%d", &source, &destination);
    --source; --destination;

    vector<int> d (nodesCount, INF);
    d[source] = 0;
    for (;;) {
        bool any = false;
        for (int j=0; j < edgesCount; ++j)
            if (d[g[j].from] < INF)
                if (d[g[j].to] > d[g[j].from] + g[j].income) {
                    d[g[j].to] = d[g[j].from] + g[j].income;
                    any = true;
                }
        if (!any)  break;
    }

    if(d[destination] == INF) {
        cout << "No solution" << endl;
        return 0;
    }
    d[destination] = 0 - d[destination];
    cout << d[destination] << endl;

    return 0;
}