//#include<omp.h>
//#include<iostream>
//using namespace std;
//int main()
//{
//#pragma omp parallel sections num_threads(4)
//	{
//#pragma omp section
//		{
//			cout << "section 1 线程ID：" << omp_get_thread_num() << "\n";
//		}
//#pragma omp section
//		{
//			cout << "section 2 线程ID：" << omp_get_thread_num() << "\n";
//		}
//#pragma omp section
//		{
//			cout << "section 3 线程ID：" << omp_get_thread_num() << "\n";
//		}
//#pragma omp section
//		{
//			cout << "section 4 线程ID：" << omp_get_thread_num() << "\n";
//		}
//	}
//	system("pause");
//}
//
//#include<iostream>
//#include<time.h>
//using namespace std;
//int main() {
//	int t = 1;
//	int start_t = clock();
//	while (t) {
//		int end_t = clock();
//		if (end_t - start_t >= 10000) {
//			t = 0;
//			cout << (end_t - start_t) / 1000;
//		}
//	}
//	return 0;
//}

#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#define MAX_L 100000
using namespace std;
//冒泡排序
void maopao_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//选择排序
void xuanze_sort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
//插入排序
void charu_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j;
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}

	}
}
//希尔排序
void xier_sort(int arr[], int n) {
	int insream = n;
	int i, j, k;
	do {
		insream = insream / 3 + 1;
		for (i = 0; i < insream; i++) {
			for (j = i + insream; j < n; j += insream) {
				if (arr[j] < arr[j - insream]) {
					int temp = arr[j];
					for (k = j - insream; k >= 0 & temp < arr[k]; k -= insream) {
						arr[k + insream] = arr[k];
					}
					arr[k + insream] = temp;
				}
			}
		}


	} while (insream > 1);
}
//快速排序
void kuaisu_sort(int arr[], int start, int end) {

	int i = start;
	int j = end;
	int temp = arr[start];
	if (i < j) {
		while (i < j) {
			while (i < j&&arr[j] >= temp) {
				j--;
			}
			if (i < j) {
				arr[i] = arr[j];
				i++;
			}
			while (i < j&&arr[i] <= temp)
			{
				i++;
			}
			if (i < j) {
				arr[j] = arr[i];
				j--;
			}

		}
		arr[i] = temp;
		kuaisu_sort(arr, start, i - 1);
		kuaisu_sort(arr, i + 1, end);
	}
}
//归并排序
void merge(int arr[], int start, int end, int mid, int *temp) {//合并两个数组
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int length = 0;//辅助空间元数个数
	while (i_start <= i_end && j_start <= j_end) {
		if (arr[i_start] < arr[j_start]) {
			temp[length] = arr[i_start];
			length++;
			i_start++;
		}
		else {
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}

	}
	while (i_start <= i_end) {
		temp[length] = arr[i_start];
		length++;
		i_start++;
	}
	while (j_start <= j_end) {
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}
	//将辅助空间元素增加到原空间
	for (int i = 0; i < length; i++) {
		arr[start + i] = temp[i];
	}
}
void guibing_sort(int arr[], int start, int end, int *temp) {
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;

	guibing_sort(arr, start, mid, temp);

	guibing_sort(arr, mid + 1, end, temp);

	merge(arr, start, end, mid, temp);

}
int main() {
	srand((unsigned int)time(NULL));
	int t = rand() % 10000;
	int arr[MAX_L];
	int arr1[MAX_L];
	int arr2[MAX_L];
	int arr3[MAX_L];
	int arr4[MAX_L];
	int arr5[MAX_L];
	for (int i = 0; i < MAX_L; i++) {
		arr[i] = rand() % 10000;
		arr1[i] = arr[i];
		arr2[i] = arr[i];
		arr3[i] = arr[i];
		arr4[i] = arr[i];
		arr5[i] = arr[i];
		//arr2[i] = arr[i];
	}
	// cout<<"before:"<<endl;
	// for(int i=0;i<MAX_L;i++){
	// cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	int s_k_t = clock();
	kuaisu_sort(arr, 0, MAX_L - 1);//快速排序
	int e_k_t = clock();
	cout << "k_end:" <<( e_k_t - s_k_t) << endl;

	int s_x_t = clock();
	xuanze_sort(arr1, MAX_L);//选择排序
	int e_x_t = clock();
	cout << "x_end:" << (e_x_t - s_x_t) << endl;

	int s_m_t = clock();
	 maopao_sort(arr2,MAX_L);//冒泡排序
	 int e_m_t = clock();
	 cout << "m_end:" << (e_m_t - s_m_t) << endl;

	 int s_c_t = clock();
	 charu_sort(arr3, MAX_L);//插入排序
	 int e_c_t = clock();
	 cout << "c_end:" << (e_c_t - s_c_t) << endl;

	 int s_xi_t = clock();
	 xier_sort(arr4, MAX_L);//希尔排序
	 int e_xi_t = clock();
	 cout << "xi_end:" << (e_xi_t - s_xi_t) << endl;


	//xuanze_sort(arr,MAX_L);//选择排序
	//charu_sort(arr,MAX_L);//插入排序
	// xier_sort(arr,MAX_L);//希尔排序
	
	int temp[MAX_L];
	int s_g_t = clock();
	guibing_sort(arr5, 0, MAX_L - 1, temp);
	int e_g_t = clock();
	cout << "then:" <<e_g_t-s_g_t<< endl;
	// for(int i=0;i<MAX_L;i++){
	// cout<<arr[i]<<" ";
	// }

	return 0;
}