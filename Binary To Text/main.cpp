/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on August 25, 2020, 4:08 PM
 * Purpose: Converts space separated binary to text
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
    stringstream ss(str);
    
    while(ss >> str) {
        char c = 0;
        for(int i = str.size() - 1; i >= 0; --i)
            c |= (str[i] - '0') << (str.size() - i - 1);
        cout<<c;
    }

    //A Sebastian Production
    return 0;
}