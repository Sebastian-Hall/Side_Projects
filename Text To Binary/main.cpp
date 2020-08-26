/* 
 * File:   main.cpp
 * Author: Sebastian Hall
 * Created on August 25, 2020, 3:51 PM
 * Purpose: Translates text to binary
 */

#include <fstream>
using namespace std;

int main() {
    //Declare variables
    char c;
    fstream in("input.txt", ios::in), out("output.txt", ios::out);
    
    //Read in each character, convert to binary, and write to file space separated
    while(in.get(c)) {
        for(int j = 7; j >= 0; --j) out<<((bool)(c & (1 << j)));
        out<<" ";
    }

    //Close file
    in.close();
    out.close();
    
    //A Sebastian Production
    return 0;
}