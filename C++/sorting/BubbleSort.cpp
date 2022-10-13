#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n,t,flag=0;
    vector<int>a;
    cout<<"enter the number of element in array:"<<endl;
    cin>>n;
    cout<<"enter the elements of array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin>>m;
        a.push_back(m);
    }
    for (int i = 0; i < n-1; i++)
    {
        flag=0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
              t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
              flag=1;  
            }
        }
    }
    cout<<"sorted array is\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
