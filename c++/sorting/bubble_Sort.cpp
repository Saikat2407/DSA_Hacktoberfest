#include <iostream>
using namespace std;


void bubble_sort(int A[], int n)
{
    int temp;
    int flag;
        flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j] , A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return ;
        }
        
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
    int i;
    // int arry[] = {23, 3, 33, 4, 1, 7, 8};
    int arry[] = {33,1 ,3 ,4, 7, 8 ,23};

    bubble_sort(arry, 7);

    printArray(arry, 7);
 
    
    return 0;
}
