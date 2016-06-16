#include <iostream>
#include <windows.h>


using namespace std;

int main()

{   int n=0;
    double f;
    setlocale(LC_ALL,"RUSSIAN");
    double *arr = new double[n];
 do {
    cout<<"Введите число: ";
    cin>>arr[n];

    cout<<"\n";
    for (int i=0;i<=n; i++)
        { if (arr[n]<0) break;
            cout<<arr[i]<<" ";
            f=arr[i];
        }
    cout<<" \n";
    n++;
    f=arr[n-1];
   } while(f>0);

    return 0;
}