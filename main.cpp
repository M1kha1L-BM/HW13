#include<iostream>
#include "Graph.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "ru");
    Graph g;

    cout << "Введите количество людей: ";
    int n; cin >> n;
    cin.ignore();

    cout << "Введите имена людей (по одному в строке):\n";
    for (int i = 0; i < n; ++i) {
        string name;
        getline(cin, name);
        g.addPerson(name);
    }

    cout << "Введите количество знакомств: ";
    int m; cin >> m;
    cin.ignore();

    cout << "Введите пары знакомых (два имени через пробел):\n";
    for (int i = 0; i < m; ++i) {
        string a, b;
        getline(cin, a);
        // Если ввели два слова, разделим:
        size_t spacePos = a.find(' ');
        if (spacePos != string::npos) {
            b = a.substr(spacePos + 1);
            a = a.substr(0, spacePos);
        }
        else {
            // Если ввели только одно слово — запрашиваем ещё одно
            cout << "Введите второе имя для знакомства: ";
            getline(cin, b);
        }
        g.addFriendship(a, b);
    }

    g.printGraph();

    auto pairs = g.findThreeHandshakePairs();

    cout << "Пары людей, знакомые через три рукопожатия:\n";
    if (pairs.empty()) {
        cout << "Таких пар нет.\n";
    }
    else {
        for (const auto& p : pairs)
            cout << p.first << " — " << p.second << "\n";
    }

    return 0;
}