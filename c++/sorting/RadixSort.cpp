#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Node
{
public:
    int data; // sorting data
    Node *next;
};

class linkedList
{
private:
    Node *root = nullptr;

public:
    void insert(int val)
    {
        if (root == nullptr)
        {
            root = new Node;
            root->data = val;
            root->next = nullptr;
            return;
        }
        Node *khona_jaye = root;
        while (khona_jaye->next)
        {
            khona_jaye = khona_jaye->next;
        }

        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;
        khona_jaye->next = newNode;
    }
    Node *getRoot()
    {
        return root;
    }
    int deleteAtFirst()
    {
        Node *deleteNode = root;
        int data = deleteNode->data;
        root = root->next;
        delete deleteNode;
        return data;
    }
    void display()
    {
        Node *khona_jaye = root;
        while (khona_jaye)
        {
            cout << khona_jaye->data << " ";

            khona_jaye = khona_jaye->next;
        }
    }
};

int maxArray(vector<int> &A)
{
    int max = A[0];

    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

int noOfDigits(int num)
{
    int i = 0;
    while (num != 0)
    {
        num = num / 10;
        i++;
    }
    return i;
}

int make1to100PovN(int ind)
{
    return pow(10, ind) / 10;
}
void RadixSort(vector<int> &A)
{

    // max elemet in given array
    vector<linkedList> aux(10);
    int max = maxArray(A);

    // aux array size of max given array

    // count all elements of given array in index of aux
    cout << max << endl;
    cout << noOfDigits(max) << endl;

    for (int k = 1; k <= noOfDigits(max); k++)
    {

        for (int i = 0; i < A.size(); i++)
        {
            int pos = (A[i] / make1to100PovN(k)) % 10;
            aux[pos].insert(A[i]);
        }
        int j = 0;
        for (int i = 0; i < aux.size(); i++)
        {

            while (aux[i].getRoot() != nullptr)
            {

                A[j] = aux[i].deleteAtFirst();
                j++;
                // aux[i]--;
            }
        }
    }
    // for (int i = 0; i < aux.size(); i++)
    // {
    //     cout << aux[i] << " ";
    // }
}

int main()
{
    vector<int> A = {237, 146, 259 ,259, 348, 152, 163, 235, 48, 36, 62};
    // vector<int> A(10, 5);
    RadixSort(A);
    cout << endl;

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
/*
algo->
need= Auxilary array which is size will be max element of given array

aux array asigned  all element with 0

traverse given array
    Aux[each elment] = Aux[each element]  + 1;

traverse Aux array
    if element is not zero
        loop while i become zero
            given[k] = index_aux;



*/