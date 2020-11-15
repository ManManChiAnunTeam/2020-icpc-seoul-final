#include <iostream>
#include <set>
#include <vector>
#include <climits>

struct Edge
{
    int next, dist;

    Edge(int n, int d)
    {
        next = n;
        dist = d;
    }

    bool operator<(const Edge& e) const
    {
        return dist < e.dist;
    }
};

int n, k;
std::set<Edge> graph[100001];
bool isGood[100001];
std::vector<int> apart;

int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n-1; ++i)
    {
        int a, b, v;
        scanf("%d %d %d", &a, &b, &v);
        graph[a].emplace(b, v);
        graph[b].emplace(a, v);
    }

    for (int i = 0; i < k; ++i)
    {
        int a;
        scanf("%d", &a);
        isGood[a] = true;
        apart.push_back(a);
    }

    int result = 0;
    for (int ap : apart)
    {
        ++result;
        auto min = graph[ap].begin();
        auto upper = graph[ap].upper_bound({0, min->dist});
        if (std::next(min) == upper && !isGood[min->next])
        {
            ++result;
            isGood[min->next] = true;
        }
    }

    printf("%d", result);

    return 0;
}