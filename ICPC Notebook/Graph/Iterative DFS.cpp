bool visited[n + 1] = {0};
stack<int> stack;
stack.push(s);

while (!stack.empty())
{
    int a = stack.top();
    stack.pop();

    if (!visited[a])
    {
        //process a
        visited[a] = true;
    }

    for (auto u : graph[a])
    {
        if (!visited[u])
        {
            stack.push(u);
        }
    }
}