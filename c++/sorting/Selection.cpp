#include <iostream>
using namespace std;

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // find the minimum number
        int k = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[k] > A[j])
            {
                k = j;
            }
        }

        swap(A[i], A[k]);
    }
}
int minElement(int A[], int n)
{
    int min = A[0];
    for (int i = 1; i < n; i++)
    {
        if (min > A[i])
        {
            min = A[i];
        }
    }
    return min;
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
    cout << "Selection sort" << endl;
    int arry[] = {23, 3, 33, 4, 5, 7, 8};
    // int arry[] = {33, 1, 3, 4, 7, 8, 23};

    // cout << minElement(arry, 7) << endl;
    SelectionSort(arry, 7);

    printArray(arry, 7);
    return 0;
}