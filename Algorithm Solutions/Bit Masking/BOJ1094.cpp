#include <iostream>

using namespace std;

int main(void) {
    int X;
    cin >> X;
    
    unsigned int stick = 64ul;
    unsigned int lastElement = 64ul;
    unsigned int result = 1ul;
    
    while(stick != X) {
        if(stick > X) {
            stick = (stick & ~lastElement) | (lastElement >> 1);
        } else {
            stick += lastElement >> 1;
        	result += 1ul;
        }
        
        lastElement = lastElement >> 1;
    }
    
    cout << result << endl;
    return 0;
}
