#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int l,int m,int h) {
	int k = l;
	int n1 = m - l + 1;
	int n2 = h - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[l+i];
	for (int i = 0; i < n2; i++)
		R[i] = a[m + i + 1];
	int i = 0, j = 0;
	while (i < n1 && j < n2) {
		a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}
	while (i < n1)
		a[k++] = L[i++];
	while (j < n2)
		a[k++] = R[j++];
}
void mergesort(int a[], int l, int h) {
	if (l < h) {
		int m = l + (h-l) / 2;
		mergesort(a, l, m);
		mergesort(a, m+1, h);
		merge(a, l, m, h);
	}
}
void shakersort(int a[], int n) {
	int i=0, j = n - 1,l=0,r=n-1,k=n-1;
	while (l < r) {
		j = r;
		i = l;
		while (j > l) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				k = j;
			}
			j--;
		}
		l = k;
		while (i < r) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				k = i;
			}
			i++;
		}
		r = k;
	}
}
void shellsort(int a[], int n, int h[], int k) {
	int step, len, i, j, x;
	for (step = 0; step < k; step++) {
		len = h[step];
		for (i = len; i < n; i++) {
			x = a[i];
			j = i - len;
			while (x < a[j] && j >= 0) {
				a[j + len] = a[j];
				j = j - len;
			}
			a[j + len] = x;
		}
	}
}
int main() {
	int a[] = { 12,2,1,4,3,7,4,9 };
	int h[] = { 5,3,1 };
	shellsort(a, 8, h, 3);
	for (int i = 0; i < 8; i++)
		cout << a[i] << ' ';
	return 0;
}
