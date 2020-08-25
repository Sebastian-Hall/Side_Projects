/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on August 25, 2020, 3:51 PM
 * Purpose: Translates text to binary
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double triple;

int main() {
    ios::sync_with_stdio(false);
    //Declare variables
    string str;
    
    getline(cin, str);
    
    for(int i = 0; i < str.size(); ++i) {
        for(int j = 7; j >= 0; --j) {
            cout<<((bool)(str[i] & (1 << j)));
        }
        cout<<" ";
    }

    //A Sebastian Production
    return 0;
}