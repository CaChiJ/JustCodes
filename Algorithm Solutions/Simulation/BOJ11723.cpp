#include <iostream>

using namespace std;
	
bool set[21];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int M;
	cin >> M;
	
	for (int i = 0; i < M; ++i) {
		char op[7];
		cin >> op;
		
		switch (op[0]) {
			case 'a':
			{
				if (op[1] == 'd') {
					// add
					int x;
					cin >> x;
					set[x] = true;
				} else {
					// all
					for (int i = 1; i <= 20; ++i) {
						set[i] = true;
					}
				}
				
				break;
			}
			case 'r':
			{
				// remove
				int x;
				cin >> x;
				set[x] = false;
				break;
			}
			case 'c':
			{
				// check
				int x;
				cin >> x;
				cout << (set[x] ? "1" : "0") << "\n";
				break;
			}
			case 't':
			{
				// toggle
				int x;
				cin >> x;
				set[x] = !set[x];
				break;
			}
			case 'e':
			{
				// empty
				for (int i = 1; i <= 20; ++i) {
					set[i] = false;
				}
				break;
			}
		}
	}
	
	return 0;
}