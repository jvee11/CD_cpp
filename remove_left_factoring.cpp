#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string nonTerminal, production, commonPrefix, factored, newProduction;
    int n;

    cout << "Enter the Non-Terminal: ";
    cin >> nonTerminal;
    cout << "Enter the number of productions: ";
    cin >> n;

    vector<string> productions(n);
    cout << "Enter the productions:\n";
    for (int i = 0; i < n; ++i) {
        cout << nonTerminal << " -> ";
        cin >> productions[i];
    }

    // Find the common prefix
    commonPrefix = productions[0];
    for (int i = 1; i < n; ++i) {
        int j = 0;
        while (j < commonPrefix.size() && j < productions[i].size() && commonPrefix[j] == productions[i][j])
            j++;
        commonPrefix = commonPrefix.substr(0, j);
    }

    // Generate factored productions
    factored = nonTerminal + " -> " + commonPrefix + nonTerminal + "'\n";
    newProduction = nonTerminal + "' -> ";
    for (int i = 0; i < n; ++i) {
        if (productions[i].substr(0, commonPrefix.size()) == commonPrefix) {
            string suffix = productions[i].substr(commonPrefix.size());
            newProduction += (suffix.empty() ? "#" : suffix) + "|";
        } else {
            factored += nonTerminal + " -> " + productions[i] + "\n";
        }
    }
    newProduction.pop_back(); // Remove the trailing '|'
    factored += newProduction;

    cout << "After Left Factoring:\n" << factored << endl;
    return 0;
}
