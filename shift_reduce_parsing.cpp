#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// Define the grammar
vector<pair<string, vector<string>>> grammar = {
    {"E", {"E", "+", "E"}},
    {"E", {"E", "*", "E"}},
    {"E", {"(", "E", ")"}},
    {"E", {"id"}}
};

// Check if the stack can be reduced
bool canReduce(stack<string> &stack, string &reduction) {
    vector<string> stackElements;
    stack<string> tempStack = stack;

    // Copy stack elements into a vector (reversed order)
    while (!tempStack.empty()) {
        stackElements.push_back(tempStack.top());
        tempStack.pop();
    }
    reverse(stackElements.begin(), stackElements.end());

    // Try to find a matching rule
    for (auto &rule : grammar) {
        const string &lhs = rule.first;
        const vector<string> &rhs = rule.second;
        if (stackElements.size() >= rhs.size()) {
            bool match = true;
            for (size_t i = 0; i < rhs.size(); i++) {
                if (stackElements[stackElements.size() - rhs.size() + i] != rhs[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                reduction = lhs;
                return true;
            }
        }
    }
    return false;
}

// Perform shift-reduce parsing
void shiftReduceParser(const vector<string> &inputTokens) {
    stack<string> parseStack;
    vector<string> input = inputTokens;
    size_t inputPos = 0;

    cout << "Stack\t\tInput\t\tAction" << endl;

    while (inputPos < input.size() || !parseStack.empty()) {
        cout << "[";
        stack<string> tempStack = parseStack;
        vector<string> stackContent;

        // Print the stack contents
        while (!tempStack.empty()) {
            stackContent.push_back(tempStack.top());
            tempStack.pop();
        }
        reverse(stackContent.begin(), stackContent.end());
        for (const auto &elem : stackContent) cout << elem << " ";
        cout << "]\t\t";

        // Print the remaining input
        cout << "[";
        for (size_t i = inputPos; i < input.size(); i++) cout << input[i] << " ";
        cout << "]\t\t";

        // Try to reduce
        string reduction;
        if (canReduce(parseStack, reduction)) {
            size_t reductionSize = 0;
            for (auto &rule : grammar) {
                if (rule.first == reduction) {
                    reductionSize = rule.second.size();
                    break;
                }
            }
            for (size_t i = 0; i < reductionSize; i++) parseStack.pop();
            parseStack.push(reduction);
            cout << "Reduce by " << reduction << endl;
        } else if (inputPos < input.size()) {
            // Otherwise, shift
            parseStack.push(input[inputPos++]);
            cout << "Shift" << endl;
        } else {
            cout << "Error: Unable to parse" << endl;
            return;
        }
    }

    // Final check
    if (parseStack.size() == 1 && parseStack.top() == "E") {
        cout << "Success: String parsed successfully" << endl;
    } else {
        cout << "Error: Unable to parse" << endl;
    }
}

int main() {
    // Input string tokens
    vector<string> inputTokens = {"id", "+", "id", "*", "id"};

    // Call the parser
    shiftReduceParser(inputTokens);

    return 0;
}
