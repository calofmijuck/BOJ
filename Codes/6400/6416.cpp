#include <bits/stdc++.h>
using namespace std;

set<int> nodes;
map<int, vector<int>> indeg;

bool check_tree() {
    if(nodes.size() == 0)
        return true;
    bool root_found = false;
    set<int>::iterator it = nodes.begin();
    while(it != nodes.end()) {
        int v = *it;
        if(indeg.find(v) == indeg.end()) {
            if(!root_found)
                root_found = true;
            else
                return false;
        } else if(indeg[v].size() > 1)
            return false;
        it++;
    }
    if(!root_found)
        return false;
    return true;    
}

int main() {
    int tc = 0, u, v;
    while(true) {
        scanf("%d %d", &u, &v);
        if(u == 0 && v == 0) {
            tc++;
            bool tree = check_tree();
            printf("Case %d is %sa tree.\n", tc, (tree) ? "" : "not ");
            indeg.clear();
            nodes.clear();
            continue;
        } else if(u == -1 && v == -1)
            break;
        nodes.insert(u);
        nodes.insert(v);
        vector<int> in_adj;
        if(indeg.find(v) != indeg.end())
            in_adj = indeg[v];
        in_adj.push_back(u);
        indeg[v] = in_adj;
    }
    return 0;
}