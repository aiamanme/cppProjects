#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arraySize;
    string line;
    cin >> arraySize;
    getline(cin >> ws, line);
    reverse(line.begin(), line.end());

    cout << line;
    
    return 0;
}
