/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on August 25, 2020, 4:08 PM
 * Purpose: Converts space separated binary to text
 */

#include <fstream>
#include <string>
using namespace std;

int main() {
    //Declare variables
    string str;
    fstream in("input.txt", ios::in), out("output.txt", ios::out);
    
    //Read in space separated binary numbers, convert, and output to file
    while(in>>str) {
        char c = 0;
        for(int i = str.size() - 1; i >= 0; --i) c |= (str[i] - '0') << (str.size() - i - 1);
        out<<c;
    }

    //Close files
    in.close();
    out.close();
    
    //A Sebastian Production
    return 0;
}