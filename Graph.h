#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    Person(const string& n) : name(n) {}
};

class Graph {
private:
    vector<Person> people;
    vector<vector<int>> adj;

    int findPersonIndex(const string& name) const;
    bool pairExists(const vector<pair<int, int>>& pairs, int a, int b) const;

public:

    void addPerson(const string& name);

    void addFriendship(const string& a, const string& b);

    vector<pair<string, string>> findThreeHandshakePairs(); 

    void printGraph() const;
};

