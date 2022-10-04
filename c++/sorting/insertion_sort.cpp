#include <iostream>
using namespace std;
//this takes O(n^2) any how
void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
            }
        }
    }
}

//this takes O(n) if array is already sorted

void InsertionSir(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = A[i];
        int j = i - 1;
        while (j >= -1 && x > A[j])
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
void printArray(int Array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << Array[i] << ' ';
    }
}
int main()
{
    cout << "Insertion sort" << endl;
    int arry[] = {23, 3, 33, 4, 1, 7, 8};
    // int arry[] = {33, 1, 3, 4, 7, 8, 23};

    InsertionSir(arry, 7);

    printArray(arry, 7);

    return 0;
}