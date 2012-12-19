#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int * copyarr(int arr[], int size) {
	int * newarr = new int[size];

	for (int i=0; i<size; i++) {
		newarr[i] = arr[i];
	}

	return newarr;
}

int maxNum(int arr[], int num) {
	int * max = max_element(arr, arr + num);
	return * max;
}

int minNum(int arr[], int num) {
	int * min = min_element(arr, arr + num);
	return * min;
}

void bubblesort(int arr[], int num, int & compares, int & swaps) {
	bool swapped = true;
	int * newarr = copyarr(arr, num);
	int j = 0;
	int tmp;
	swaps = 0;
	compares = 0;

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
	cout << endl;
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
        pivot = (low + high) / 2;
        mergesort(a, b, low, pivot, compares, swaps);
        mergesort(a, b, pivot + 1, high, compares, swaps);
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
        	
            b[i] = a[k];
            i++;
        }
    }

    for (k = low; k <= high; k++) {
    	a[k] = b[k];

    }
    
}

void quicksort_counter(int arr[], int num, int & compares, int & swaps) {
	swaps = 0;
	compares = 0;
	int * newarr = copyarr(arr, num);

	quicksort(newarr, 0, num - 1, swaps, compares);
	
	for (int i=0; i<num; i++) {
		cout << newarr[i] << " ";	
	}

	cout << endl;
	cout << "Quicksort had " << compares << " comparisons and " << swaps << " swaps." << endl;
}

void mergesort_counter(int arr[], int num, int & compares, int & swaps) {
	swaps = 0;
	compares = 0;
	int * newarr = copyarr(arr, num);
	int y[num];

	mergesort(newarr, y, 0, num - 1, compares, swaps);

	for (int i=0; i<num; i++) {
		cout << newarr[i] << " ";	
	}
	cout << endl;
	cout << "Mergesort had " << compares << " comparisons and " << swaps << " swaps." << endl;
}

void readIn(int x[], int num) {
	int bubble_swaps = 0;
	int bubble_compares = 0;
	int merge_swaps = 0;
	int merge_compares = 0;
	int quick_swaps = 0;
	int quick_compares = 0;
	int swaparr[3];
	int comparr[3];
	//Print out unsorted array
	for (int i=0; i<num; i++) {
		cout << x[i] << " ";	
	}

	cout << endl;

	mergesort_counter(x, num, merge_compares, merge_swaps);
	quicksort_counter(x, num, quick_compares, quick_swaps);
	bubblesort(x, num, bubble_compares, bubble_swaps);

	swaparr[0] = bubble_swaps;
	swaparr[1] = quick_swaps;
	swaparr[2] = merge_swaps;

	comparr[0] = bubble_compares;
	comparr[1] = quick_compares;
	comparr[2] = merge_compares;

	cout << "The sort with the most swaps was at " << maxNum(swaparr, 3) << " swaps and the most comparisons was at " << maxNum(comparr, 3) << " comparisons." << endl;
	cout << "The sort with the least swaps was " << minNum(swaparr, 3) << " swaps and the least comparisons was " << minNum(comparr, 3) << " comparisons." << endl;
}

int * randomarr(int num) {
	int * arr = new int[num];
	srand ( time(0) );
	for (int i=0; i<num; i++) {
		
		arr[i] = rand() % num + 1;
	}
	return arr;
}

int * almostarr(int num) {
	int * arr = new int[num];
	int randomnum = rand() % num;
	int randomnum2 = rand() % num;
	for (int i=0; i<num; i++) {
		arr[i] = i + 1;
	}

	arr[8] = 2;
	arr[7] = 3;
	return arr;

}

int * reversearr(int num) {
	int * arr = new int[num];
	for (int i=0; i<num; i++) {
		arr[i] = num - i;
	}
	return arr;
}

int main() {

	int num;
	cout << "Here is a group of 10 almost sorted numbers" << endl;
	int a[10] = {1, 2, 3, 7, 5, 6, 4, 8, 10, 9};
	num = sizeof(a) / sizeof(int);
	readIn(a, num);

	cout << "Here is a group of 10 random numbers" << endl;
	num = 10;
	int * b = randomarr(num);
	readIn(b, num);

	cout << "Here is a group of 10 reverse numbers" << endl;
	int c[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	num = sizeof(c) / sizeof(int);
	readIn(c, num);

	cout << "Here is a group of 50 almost sorted numbers" << endl;
	num = 50;
	int * d = almostarr(num);
	readIn(d, num);	

	cout << "Here is a group of 50 random numbers" << endl;
	num = 50;
	int * e = randomarr(num);
	readIn(e, num);	

	cout << "Here is a group of 50 reverse numbers" << endl;
	num = 50;
	int * f = reversearr(num);
	readIn(f, num);

	cout << "Here is a group of 50 almost sorted numbers" << endl;
	num = 100;
	int * g = almostarr(num);
	readIn(g, num);	

	cout << "Here is a group of 100 random numbers" << endl;
	num = 100;
	int * h = randomarr(num);
	readIn(h, num);	
	
	cout << "Here is a group of 100 reverse numbers" << endl;
	num = 100;
	int * i = reversearr(num);
	readIn(i, num);


}
