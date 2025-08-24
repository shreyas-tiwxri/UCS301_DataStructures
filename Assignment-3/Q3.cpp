#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string exp) {
    stack<char> s;
    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;   // Note: cin stops at space, use getline(cin, exp) for full input
    
    if (isBalanced(exp)) {
        cout << "Balanced.\n";
    }
    else {
        cout << "Not Balanced.\n";
    }
}