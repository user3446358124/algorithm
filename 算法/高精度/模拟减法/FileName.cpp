#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> subtract(vector<int> a, vector<int> b) {
    vector<int> result(a.size(), 0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++) {
        if (a[i] < b[i]) {
            a[i] += 10;
            a[i + 1]--;
        }
        result[i] = a[i] - b[i];
    }
    for (int i = b.size(); i < a.size(); i++) {
        if (a[i] < 0) {
            a[i] += 10;
            a[i + 1]--;
        }
        result[i] = a[i];
    }
    reverse(result.begin(), result.end());
    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    }
    return result;
}

int main() {
    string sa, sb;
    cin >> sa >> sb;
    vector<int> a, b;
    for (int i = sa.size() - 1; i >= 0; i--) {
        a.push_back(sa[i] - '0');
    }
    for (int i = sb.size() - 1; i >= 0; i--) {
        b.push_back(sb[i] - '0');
    }
    vector<int> result = subtract(a, b);
    cout << sa << " - " << sb << " = ";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}
