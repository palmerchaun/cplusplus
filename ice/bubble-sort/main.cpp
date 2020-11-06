//ICE on pointers
//10/25/2020
//Modified by Seth Palmer

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//accept two int pointers and swap them based on the contents of what they
//point to
void swap(int*& num1P, int*& num2P)  
{
    int *temp = num1P;
    num1P = num2P;
    num2P = temp;
}  

//print a regular array
void printArray(int arr[], int size)  
{  
	int i;  
	for (i = 0; i < size; i++)  
    	cout << arr[i] << " ";  
	cout << endl;  
}  


//this one will be very similar to the previous printArray function
void printArray(int* arr[], int size)
{  
    for (int i = 0; i < size; i++)
        cout << *(arr[i]) << " ";
    cout << endl;
}  

//The actual sorting algorithm
//have it accept an array of int pointers and a size n
void bubbleSort(int* arr[], int n)
{  
    int i;
	int j;

    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (*arr[j] > *arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }

	//loop until from i to 1 less than n
    	//loop from j to n-i-1
        	//Compare the contents of arr[j] to the contents of the next element
        	//if the current element is greater than the next element swap
}

int main()
{
	/*
	1. Dynamically create an array of random numbers 1 - 100
	2. Create an array of int pointers
	3. Initialize the array by pointing each element at each int of the array
	4. implement bubble sort to sort the array of pointers
	5. Print the original array
	6. Print the sorted array using the pointers
	*/
    
    
	//Dynamically create an array of 100 int
    int * arr;
    arr = new int[100];
   
	//Create an array of 100 int pointers
    int ** arrp;
    arrp = new int* [100];
	 
    
	//seed a random number generator
    srand(time(NULL));
	 
    
	//initialize your 100 element array with random numbers 0 - 999
	for (int x =0; x<100; x++)
    {
       	arr[x] = rand() % 100 + 1; 
    }
 	 
	//initialize the array of pointers by pointing each at an element of the
	//array of random numbers
	for (int x =0; x<100; x++)
    {
        arrp[x] = &arr[x];
    }
   	 
	//sort the array of pointers by the values they point at
	bubbleSort(arrp, 100);
    
	//print the original array
	printArray(arr, 100);
    
	//print the array sorted using the pointers
	printArray(arrp, 100);
    
	return 0;
}
