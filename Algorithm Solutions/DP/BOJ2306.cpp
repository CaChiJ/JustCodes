#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string str;
int longest[505][505];

int getMaxLen(int start, int end) {
    if(start >= end) {
        return 0;
    }
    
    if(longest[start][end] != -1) {
        return longest[start][end];
    }
    
    int maxLen = 0;
    
    for(int i = start; i < end; ++i) {
        maxLen = max(maxLen, getMaxLen(start, i) + getMaxLen(i+1, end));
    }
    
    if(str[start] == 'a' && str[end] == 't' || str[start] == 'g' && str[end] == 'c') {
        maxLen = max(maxLen, getMaxLen(start + 1, end - 1) + 2);
    }
    
    return longest[start][end] = maxLen;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> str;
    
    memset(longest, -1, sizeof(longest));
    
    cout << getMaxLen(0, str.length()-1) << endl;
    
    return 0;
}
