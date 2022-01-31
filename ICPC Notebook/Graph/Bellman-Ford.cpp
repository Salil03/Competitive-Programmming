// inside int main()
// initially, only source has distance = 0 and in the queue
//let source = s
int distance[n + 1] = {0}; // INIT TO INF
distance[s] = 0;
queue<int> q;
q.push(s);
bool in_queue[n + 1] = {0};
int cnt[n + 1] = {0};
in_queue[s] = 1;
bool negative = false;
while (!q.empty())
{
    int u = q.front();
    q.pop();
    in_queue[u] = 0;
    for (auto v : graph[u])
    {
        int x = v.first, weight = v.second;
        if (distance[u] + weight < distance[x])
        {                                       // if can relax
            distance[x] = distance[u] + weight; // relax
            if (!in_queue[x])
            {              // add to the queue
                q.push(x); // only if it is not already in the queue
                cnt[x]++;
                in_queue[x] = 1;
                if (cnt[to] > n)
                {
                    negative = true;
                    break;
                }
            }
        }
    }
    if (negative)
    {
        break; //negative cycle
    }
}