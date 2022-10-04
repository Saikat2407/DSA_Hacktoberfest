#include <iostream>
using namespace std;

int Partioning(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low, j = high + 1;

    while (i < j)
    {
        do
        {
            i++;
        } while (A[i] <= pivot); // if A[i]  is greater then pivot then stop

        do
        {
            j--;
        } while (A[j] > pivot); // if A[i]  is Small then pivot then stop

        if (i < j)
        {
            swap(A[i], A[j]);
        }
    }
    swap(A[low], A[j]);
    return j; // sorted element
}
void QuickSort(int A[], int low, int high)
{
    // low - first elment
    // high - last elment
    if (low < high)
    {
        int j = Partioning(A, low, high);
        QuickSort(A, low, j);
        QuickSort(A, j + 1, high);
    }
};

void printArray(int Array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << Array[i] << ' ';
    }
}

int main()
{
    cout << "Quick sort" << endl;
    int arry[] = {23, 5, 3};
    // int arry[] = {33, 1, 3, 4, 7, 8, 230};

    QuickSort(arry, 0, 2);

    printArray(arry, 3);

    return 0;

    
}

/*
ALgo->
! main function logic
make first element pivot

i initialize with first index
j initialize with last index

loop while i < j
    increase i till i-th element > pivot
    decrease j till j-th elment <  pivot

    swap i-th elemnt with j-th element

swap pivot with j-th element

!recursive logic
    i initialize with second index
    j initialize with last index
    pivot => first element


fun(pivot , i , j)


    loop while i < j
        increase i till i-th element > pivot
        decrease j till j-th elment <  pivot

         swap i-th elemnt with j-th element

    swap pivot with j-th element

    fun(A[0] , 1 , j - 1);
    fun(A[i] , i+`1 , maxValue);

*/
