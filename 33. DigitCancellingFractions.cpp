/*
* Author: Sheesh_Bakht
* Created: 2026.08.31 19:13:53
*/
/*
   ███████ ██   ██ ███████ ███████ ███████ ██   ██
   ██      ██   ██ ██      ██      ██      ██   ██
   ███████ ███████ █████   █████   ███████ ███████
        ██ ██   ██ ██      ██           ██ ██   ██
   ███████ ██   ██ ███████ ███████ ███████ ██   ██
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
//#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'


// vector <int> common_factors(int a, int b) {
//     vector<int> primeFactors = {
//         2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
//         31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
//         73, 79, 83, 89, 97
//     };
//     int n = primeFactors.size();
//     vector <int> v;
//     for (int i = 0; i < n; i++) {
//         if (a%primeFactors[i] == 0 && b%primeFactors[i] == 0) {
//             v.pb(primeFactors[i]);
//         }
//     }
//     return v;
// }

pair<int, int> lowestForm(int a, int b) {
    int g = gcd(a, b);
    return make_pair(a/g, b/g);
}

bool fn(int a, int b) {
    pair<int, int> lowest = lowestForm(a, b);
    double d = (double) lowest.first / lowest.second; //4 / 8 = 0.5
    if (d >= 1) return false;
    string sa = to_string(a);
    string sb = to_string(b);
    if (count(all(sa), '0') > 0) return false;
    if (count(all(sb), '0') > 0) return false;
    sort(all(sa));
    sort(all(sb));
    if (sa == sb) return false;
    char same = 'a';
    if (sa[0] == sb[1]) same = sb[1];
    else if (sa[0] == sb[0]) same = sb[0];
    else if (sa[1] == sb[1]) same = sb[1];
    else if (sa[1] == sb[0]) same = sb[0];
    if (same == 'a') return false;
    for (size_t i = 0; i < sa.size(); i++) {
        if (sa[i] == same) sa.erase(sa.begin() + i);
    }
    for (size_t i = 0; i < sb.size(); i++) {
        if (sb[i] == same) sb.erase(sb.begin() + i);
    }
    int l = stoi(sa); //4
    int r = stoi(sb); //8

    double ax = (double) l/r;
    return d == ax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //eg 49/98
    vector <pair<int, int>> curious;
   // curious.push_back(make_pair(49, 98));
    for (int i = 11; i < 100; i++) {
        for (int j = i+1; j < 100; j++) {
            if (fn(i, j) && i < j) {
                curious.pb(make_pair(i, j));
            }
        }
    }
    int num = 1, denom = 1;
    for (auto &[a, b] : curious) {
        cout << a << " " << b << endl;
        pair<int, int> arc = lowestForm(a, b);
        num *= arc.first;
        denom *= arc.second;
    }
    pair <int, int> ans = lowestForm(num, denom);
    cout << ans.second << endl;
    return 0;
}
