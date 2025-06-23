#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    map<string, vector<string>> library;
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        size_t pos = line.find(',');
        string book = line.substr(0, pos);
        string author = line.substr(pos + 1);
        library[author].push_back(book);
    }

    int q;
    cin >> q;
    cin.ignore();

    for (int i = 0; i < q; ++i) {
        string query;
        getline(cin, query);
        if (library.count(query)) {
            for (const string& book : library[query]) {
                cout << book << endl;
            }
        }
    }
    return 0;
}