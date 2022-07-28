#include <iostream>
using namespace std;

string str, newstr;
int p, q, r, s;

void buildNewString () {
    newstr = str;
    for (int i = 0; i < str.length(); i++) {
        switch (str[i])
        {
        case 'p':
            newstr[i] = p + '0';
            break;
        case 'q':
            newstr[i] = q + '0';
            break;
        case 'r':
            newstr[i] = r + '0';
            break; 
        case 's':
            newstr[i] = s + '0';
            break;   
        default:
            break;
        }
    }
}

int solve (int l, int r) {
    if (r - l == 1) {
        return newstr[l] - '0';
    }
    l++, r--;
    if (r - l == 2) {
        return 1 - (newstr[l + 1] - '0');
    }
    if (r - l == 3) {
        return (newstr[l] - '0') & (newstr[l + 2] - '0');
    }
    if (newstr[l] == '~')
        return 1 - solve(l + 1, r);
    int open = 0, close = 0;
    for (int i = l; i <= r; i++) {
        if (newstr[i] == '(')
            open++;
        else if (newstr[i] == ')')
            close++;
        else if (newstr[i] == '^' && open == close)
            return solve(l, i) && solve(i + 1, r);
    }
}

int main () {
    cin >> str;
    for (p = 1; p >= 0; p--) 
        for (q = 1; q >= 0; q--)
            for (r = 1; r >= 0; r--)
                for (s = 1; s >= 0; s--) {
                    buildNewString();
                    cout << ((solve(0, str.length()) == 1) ? 'T' : 'F');
                }
}