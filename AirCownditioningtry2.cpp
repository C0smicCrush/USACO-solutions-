#include <bits/stdc++.h>
using namespace std;

//Not my code, took ben qi's sol and modified
int main() {
	int N;
	cin >> N;
	vector<int> p(N), t(N), d(N);
	for (int i = 0; i < N; ++i)
		cin >> p[i];
	for (int i = 0; i < N; ++i)
		cin >> t[i];
	for (int i = 0; i < N; ++i)
		d[i] = p[i] - t[i];
	int first_nonzero = 0, ans = 0;
	while (true) {
		while (first_nonzero < N && d[first_nonzero] == 0)
			++first_nonzero;
		if (first_nonzero == N)
			break;
		int r = first_nonzero;
        int minNum = d[first_nonzero];
		auto sgn = [&](int x) {
			if (x < 0)
				return -1;
			if (x > 0)
				return 1;
			return 0;
		};
        if(d[first_nonzero] > 0){
		while (r + 1 < N && sgn(d[r + 1]) == sgn(d[first_nonzero])){
			++r;
            minNum = min(minNum, d[r]);
        }
        }else{
		while (r + 1 < N && sgn(d[r + 1]) == sgn(d[first_nonzero])){
			++r;
            minNum = max(minNum, d[r]);
        }

        }
		for (int i = first_nonzero; i <= r; ++i) {
			if (d[i] < 0)
				d[i] -= minNum;
			else
				d[i] -= minNum;
		}
        if(minNum > 0){
            ans += minNum;
        }else{
            ans -= minNum;
        }
	}
	cout << ans << "\n";
}

