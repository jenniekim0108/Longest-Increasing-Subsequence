#include <bits/stdc++.h>

using namespace std;
int lis(int arr[], int n) {
  int lis[n];

  lis[0] = 1;

  for (int i = 1; i < n; i++) {
    lis[i] = 1;
    for (int j = 0; j < i; j++){
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;
    }
  }
  //find maximum element dari elemen pertama hingga elemen ke-n
  return *max_element(lis, lis + n);
}
int main() {
	int arr[] = {4,1,13,7,0,2,8,11,3};
	int n = sizeof arr/ sizeof arr[0];
	cout << lis(arr, n) << endl;
	return 0;
}

/*
arr[1] < arr[0] {No change}
arr[2] > arr[0] {LIS[2] = max(LIS [2], LIS[0]+1 = 2}
arr[3] > arr[0] {LIS[3] = max(LIS [3], LIS[0]+1 = 2}
arr[4] < arr[0] {No change}
arr[5] < arr[0] {No change}
arr[6] > arr[0] {LIS[6] = max(LIS [6], LIS[0]+1 = 2}
arr[7] > arr[0] {LIS[7] = max(LIS [7], LIS[0]+1 = 2}
arr[8] < arr[0] {No change}
arr[2] > arr[1] {LIS[2] = max(LIS [2], LIS[1]+1 = 2}
-berlaku sampai array ke 8-
arr[6] > arr[3] {LIS[6] = max(LIS [6], LIS[3]+1 = 3}
*/
