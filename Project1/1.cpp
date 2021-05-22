//#include<iostream>
//using namespace std;
//struct point {
//	int x;
//	int y;
//	int w;
//};
//int main() {
//	int n, m, k;
//	cin >> n >> m >> k;
//	int net[3][5];
//	int line = n + 1;
//	int row = m + 1;
//	bool map[6][5] = { false };
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < 5; j++) {
//			cin >> net[i][j];
//		}
//		map[net[i][0]][net[i][1]] = true;
//		map[net[i][2]][net[i][3]] = true;
//	}
//	if (!map[1][1] || !map[n][m]) {
//		cout << "-1" << endl;
//		return 0;
//	}
//	int ans = 0;
//	point minp;
//	int i = n,j = m;
//	int flag = 1;
//	while (i != 1 && j != 1) {
//		//if (!map[i][j])break;
//		
//		int tempw = 0;
//		if (flag == 1) {
//			for (int l = 0; l < k; l++) {
//				if (net[l][2] == n && net[l][3] == m) {
//					minp.x = net[l][0];
//					minp.y = net[l][1];
//					minp.w = net[l][4];
//					flag = 0;
//				}
//			}
//		}
//		else {
//			int fl = 1;
//			for (int l = 0; l < k; l++) {
//				if(fl==1){
//					if (net[l][2] == i && net[l][3] == j ) {
//						minp.x = net[l][0];
//						minp.y = net[l][1];
//						minp.w = net[l][4];
//						tempw= net[l][4];
//						fl = 0;
//					}
//				}
//				else {
//					if (net[l][2] == i && net[l][3] == j&& tempw >net[l][4]) {
//						minp.x = net[l][0];
//						minp.y = net[l][1];
//						minp.w = net[l][4];
//						tempw = net[l][4];
//					}
//				}
//			}
//		}
//		
//		ans += minp.w;
//		if (minp.x == 1 && minp.y == 1) {
//			cout << ans << endl;
//			return 0;
//		}
//		i = minp.x;
//		j = minp.y;
//	}
//	return 0;
//}