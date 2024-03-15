#include <iostream>
using namespace std;

int bitManipulation3(int n, int i) {
int key=0;
for(int j=0;j<i;j++){
    key |= 1<<(31-j);
}
return n^key;
}

int main() {
	int t, n, i;
	cin>>t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}