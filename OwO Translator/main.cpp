/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on August 6, 2020, 11:47 PM
 * Purpose: 
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    char c;
    ofstream out("output.txt", ios::out);
    ifstream in("input.txt", ios::in);
    
    while(in.get(c)) {
        switch(c) {
            case 'l':
            case 'r': out<<"w";break;
            case 'L':
            case 'R': out<<"W";break;
            default:  out<<c;
        }
    }
    out.close();
    //A Sebastian Production
    return 0;
}