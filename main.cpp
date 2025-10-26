#include<iostream>
#include "Graph.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
    Graph g;

    cout << "������� ���������� �����: ";
    int n; cin >> n;
    cin.ignore();

    cout << "������� ����� ����� (�� ������ � ������):\n";
    for (int i = 0; i < n; ++i) {
        string name;
        getline(cin, name);
        g.addPerson(name);
    }

    cout << "������� ���������� ���������: ";
    int m; cin >> m;
    cin.ignore();

    cout << "������� ���� �������� (��� ����� ����� ������):\n";
    for (int i = 0; i < m; ++i) {
        string a, b;
        getline(cin, a);
        // ���� ����� ��� �����, ��������:
        size_t spacePos = a.find(' ');
        if (spacePos != string::npos) {
            b = a.substr(spacePos + 1);
            a = a.substr(0, spacePos);
        }
        else {
            // ���� ����� ������ ���� ����� � ����������� ��� ����
            cout << "������� ������ ��� ��� ����������: ";
            getline(cin, b);
        }
        g.addFriendship(a, b);
    }

    g.printGraph();

    auto pairs = g.findThreeHandshakePairs();

    cout << "���� �����, �������� ����� ��� �����������:\n";
    if (pairs.empty()) {
        cout << "����� ��� ���.\n";
    }
    else {
        for (const auto& p : pairs)
            cout << p.first << " � " << p.second << "\n";
    }

    return 0;
}