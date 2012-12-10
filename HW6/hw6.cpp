#include <iostream>

using namespace std;

int * copyarr(int arr[], int size) {
	int * newarr = new int[size];

	for (int i=0; i<size; i++) {
		newarr[i] = arr[i];
	}

	return newarr;
}

void bubblesort(int arr[], int num) {
	bool swapped = true;
	int * newarr = copyarr(arr, num);
	int j = 0;
	int tmp;
	int swaps = 0;
	int compares = 0;

	while (swapped) {
	    swapped = false;
	    j++;
	    for (int i = 0; i < num - j; i++) {
	    	compares++;
	    	if (newarr[i] > newarr[i + 1]) {

	            tmp = newarr[i];
	            newarr[i] = newarr[i + 1];
	            newarr[i + 1] = tmp;
	            swapped = true;
	            swaps++;
	        }
	    }
	}

	for (int i=0; i<num; i++) {
		cout << newarr[i] << " ";	
	}
    cout << "Bubblesort had " << compares << " comparisons and " << swaps << " swaps." << endl;
}

void quicksort(int arr[], int left, int right, int & compares, int & swaps) {

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */

      while (i <= j) {

            while (arr[i] < pivot) {
                  i++;
             }

            while (arr[j] > pivot) {
                  j--;
             }

            compares++;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
                  swaps++;
            }
      };

      if (left < j)
            quicksort(arr, left, j, compares, swaps);

      if (i < right)
            quicksort(arr, i, right, compares, swaps);

}

void merge(int*, int*, int, int, int, int &, int &);
void mergesort(int * a, int* b, int low, int high, int & compares, int & swaps)
{
    int pivot;
    if(low < high)
    {
        pivot=(low + high)/2;
        mergesort(a, b, low, pivot, compares, swaps);
        mergesort(a, b, pivot+1, high, compares, swaps);
        merge(a, b, low, pivot, high, compares, swaps);
    }

}

void merge(int * a, int * b, int low, int pivot, int high, int & compares, int & swaps) {
    int h, i, j, k;
    h = low;
    i = low;
    j = pivot + 1;
 
    while((h <= pivot) && (j <= high)) {
    	compares++;
        if(a[h] <= a[j]){
            b[i] = a[h];
            h++;
        }
        else {
        	swaps++;
            b[i] = a[j];
            j++;
        }
        i++;
    }
    
    if(h > pivot) {
        for (k = j; k <= high; k++) {

            b[i] = a[k];
            i++;
        }
    }
    else {
        for (k = h; k <= pivot; k++) {
        	swaps++;
            b[i] = a[k];
            i++;
        }
    }

    for (k = low; k <= high; k++) {
    	a[k] = b[k];

    }
    
}

void quicksort_counter(int arr[], int num) {
	int swaps = 0;
	int compares = 0;
	int * newarr = copyarr(arr, num);

	quicksort(newarr, 0, num, swaps, compares);
	
	for (int i=0; i<num; i++) {
		cout << newarr[i] << " ";	
	}
	cout << "Quicksort had " << compares << " comparisons and " << swaps << " swaps." << endl;
}

void mergesort_counter(int arr[], int num) {
	int swaps = 0;
	int compares = 0;
	int * newarr = copyarr(arr, num);
	int y[num];

	mergesort(newarr, y, 0, num - 1, swaps, compares);

	for (int i=0; i<num; i++) {
		cout << newarr[i] << " ";	
	}
	cout << "Mergesort had " << compares << " comparisons and " << swaps << " swaps." << endl;
}

void readIn(int x[], int num) {
	
	//Print out unsorted array
	for (int i=0; i<num; i++) {
		cout << x[i] << " ";	
	}

	cout << endl;

	mergesort_counter(x, num);
	quicksort_counter(x, num);
	bubblesort(x, num);

}

int main() {

	cout << "Here is a group of 10 almost sorted numbers" << endl;
	int a[10] = {1, 2, 3, 7, 5, 6, 4, 8, 10, 9};
	int num = sizeof(a) / sizeof(int);
	readIn(a, num);

	cout << "Here is a group of 10 random numbers" << endl;
	int b[10] = {4, 2, 4, 5, 15, 6, 3, 1, 7, 11};
	num = sizeof(b) / sizeof(int);
	readIn(b, num);

	cout << "Here is a group of 10 reverse numbers" << endl;
	int c[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	num = sizeof(c) / sizeof(int);
	readIn(c, num);



}
