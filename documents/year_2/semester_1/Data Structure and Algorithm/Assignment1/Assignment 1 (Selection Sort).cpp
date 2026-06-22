#include <iostream>
using namespace std;

int swapCount = 0;

void swapData(int& x, int& y){
	int temp = x;
	
	x = y;
	y = temp;
	
	swapCount++;
}

void selectionSort(int studMarks[], int size, int& comparisonCount){
	
	for(int last=size-1; last>=1; last--){
		int largestIndex = 0;
		
		for (int i=1; i<=last; i++){
			if (studMarks[i] > studMarks[largestIndex]){
				largestIndex = i;
			}
			
			comparisonCount++;
		}
		
		swapData(studMarks[largestIndex], studMarks[last]);
	}
}

int main (){
	int studMarks[5] = {75, 95, 60, 88, 70};
	int comparisonCount = 0;
	
	selectionSort(studMarks, 5, comparisonCount);
	
	cout << "Student Marks array after being sorted: ";
	
	for (int k=0; k<5; k++){
		cout << studMarks[k] << " ";
	}
	
	cout << endl;
	
	cout << "Total number of comparisons: " << comparisonCount << endl;;
	cout << "Total number of swaps: " << swapCount;
}