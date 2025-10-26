#include "Graph.h"

int Graph::findPersonIndex(const string& name) const {
    for (int i = 0; i < (int)people.size(); ++i) {
        if (people[i].name == name)
            return i;
    }
    return -1;
}

bool Graph::pairExists(const vector<pair<int, int>>& pairs, int a, int b) const {
    for (auto& p : pairs) {
        if ((p.first == a && p.second == b) || (p.first == b && p.second == a))
            return true;
    }
    return false;
}

void Graph::addPerson(const string& name) {
    if (findPersonIndex(name) != -1)
        return;
    people.emplace_back(name);
    adj.emplace_back();
}

void Graph::addFriendship(const string& a, const string& b) {
    addPerson(a);
    addPerson(b);

    int u = findPersonIndex(a);
    int v = findPersonIndex(b);

    if (find(adj[u].begin(), adj[u].end(), v) == adj[u].end())
        adj[u].push_back(v);
    if (find(adj[v].begin(), adj[v].end(), u) == adj[v].end())
        adj[v].push_back(u);
}

vector<pair<string, string>> Graph::findThreeHandshakePairs() {
    vector<pair<int, int>> pairs;
    int n = people.size();

    for (int start = 0; start < n; ++start) {
        vector<int> dist(n, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        for (int v = 0; v < n; ++v) {
            if (dist[v] == 3 && !pairExists(pairs, start, v)) {
                pairs.push_back(make_pair(start, v));
            }
        }
    }

    vector<pair<string, string>> result;
    for (const auto& p : pairs) {
        result.push_back(make_pair(people[p.first].name, people[p.second].name));
    }

    return result;
}

void Graph::printGraph() const {
    cout << "\nСоциальный граф:\n";
    for (size_t i = 0; i < people.size(); ++i) {
        cout << people[i].name << " знаком с: ";
        for (int v : adj[i]) {
            cout << people[v].name << " ";
        }
        cout << "\n";
    }
    cout << endl;
}