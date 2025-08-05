#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find_root(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = find_root(parent[n]);
    }

    void union_by_rank(int a, int b)
    {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if (root_a == root_b)
            return;
        if (rank[root_a] > rank[root_b])
        {
            parent[root_b] = root_a;
        }
        else if (rank[root_a] < rank[root_b])
        {
            parent[root_a] = root_b;
        }
        else
        {
            parent[root_a] = root_b;
            rank[root_b]++;
        }
    }
    void union_by_size(int a, int b)
    {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if (root_a == root_b)
            return;
        if (size[root_a] > size[root_b])
        {
            size[root_a] += size[root_b];
            parent[root_b] = root_a;
        }
        else
        {
            size[root_b] += size[root_a];
            parent[root_a] = root_b;
        }
    }
};

int main()
{
    int size, cmd = -1;
    cout << "Enter the size of DSU: ";
    cin >> size;
    DSU dsu(size);
    while (cmd != 0)
    {
        cout << "Enter command (1 for union, 2 for find root, 0 to exit): ";
        cin >> cmd;
        if (cmd == 1)
        {
            int a, b;
            cout << "Enter two elements to union: ";
            cin >> a >> b;
            dsu.union_by_rank(a, b);
        }
        else if (cmd == 2)
        {
            int a;
            cout << "Enter element to find root: ";
            cin >> a;
            cout << "Root of " << a << " is: " << dsu.find_root(a) << endl;
        }
        else if (cmd != 0)
        {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    return 0;
}
