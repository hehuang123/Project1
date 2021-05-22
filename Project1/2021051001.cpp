//#include<iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//int main() {
//	int n ;
//	cin >> n;
//	int l = n;
//	char map[1000][1000];
//	//bool bmap[1000][1000];
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//			//bmap[i][j] = false;
//		}
//	}
//	char ans[1000]; int k = 0;
//	int f_j=1,f_i = 1,b=1;
//	int i = 0, j = 0;
//	int dp_in = n,dp_i0=0,dp_j0=0,dp_jn=n;
//	while (map[i][j] != '0'&&k<n*n) {
//		ans[k++] = map[i][j];
//		if (b == 1) {
//			if (f_i == 1) {
//				j++;
//				if (j >= dp_jn) {
//					j =j - 1;
//					f_i = 0;
//					b = 0;
//					i++;
//					dp_jn--;
//				}
//			}
//			else {
//				j--;
//				if (j < dp_j0) {
//					j = j+1;
//					f_i = 1;
//					b = 0;
//					i--;
//					dp_j0++;
//				}
//			}
//		}
//		else {
//			if (f_j == 1) {
//				i++;
//				if (i >= dp_in) {
//					i= i - 1;
//					f_j = 0;
//					b = 1;
//					j--;
//					dp_in--;
//				}
//			}
//			else {
//				i--;
//				if (i <=dp_i0) {
//					i = i+1;
//					f_j = 1;
//					b = 1;
//					j++;
//					dp_i0++;
//				}
//			}
//		}
//	}
//	/*for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (map[i][j] != '0') {
//				ans[k] = map[i][j];
//				k++;
//			}
//		}
//	}*/
//	for (int i = 0; i < k; i++) {
//		cout << ans[i];
//	}
//	return 0;
//}