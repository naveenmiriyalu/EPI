/*
Author: Naveen M
Date:   Jan 19 2015
Description: Given an array A, and an index i, rearrange elements in A such that
             i.   Elements less than A[i] appear first
			 ii.  Elements equal to A[i]
			 iii. Elements greater than A[i]
Goal:       O(1)- Space complexity
            O(|A|)- Time complexity
*/
#include<iostream>
using namespace std;
void printArray(int *A,int size);
void partition(int *A,int index,int size);
void swap(int *X,int *Y);

int main()
{
	int A[9] = {0,1,2,4,8,3,4,5,2};
	int B[9] = {8,8,8,4,4,4,4,3,3};
	int C[3] = {4,8,4}; // Fails for this particular condition
	printArray(A,9);
	partition(A,3,9);
	printArray(A,9);
	printArray(B,9);
	partition(B,3,9);
	printArray(B,9);
	printArray(C,3);
	partition(C,0,3);
	printArray(C,3);
}

void partition(int *A,int index,int size)
{
  int i =0;
  int j = size -1;
  int Element = A[index];
  int loopcount =0;

  while(i < j)
  {
    while( A[i] < Element) i++;
    while( A[j] > Element) j--;
	if(A[i] == A[j]) 
	{
		j--;
		continue;
	}
	else
	swap(&A[i],&A[j]);

	cout << "LP = " << loopcount++ << " i=" << i << " j=" << j <<  endl;
  }

}

void printArray(int *A,int size)
{
    cout << "-----" << "Array" << "----" << endl; 
  for(int i=0; i < size; i++)
  {
	cout << A[i] << " " ;
  }
  cout << endl;
}

void swap(int *X,int *Y)
{
  int temp;
  temp = *X;
  *X = *Y;
  *Y = temp;
}
