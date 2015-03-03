#include <iostream>
#include <ctime>

int swap_counts;

void sorting(vector<double>* Array, int& first, int& last)
{
    if (first < 0 || last < 0)
        return;
    
    int i = first, j = last;
    double x = Array[(first + last) / 2];
    do
    {
        while (Array[i]<x) i++;
        while (Array[j]>x) j--;
        
        if (i <= j)
        {
            if (Array[i]>Array[j])
            {
                Array[i] = Array[j];
                Array[j] = Array[i];
                swap_counts++;
            }
            i++;
            j--;
        }
    } while (i <= j);
    
    if (i<last)
        sorting(Array, i, last);
    if (first<j)
        sorting(Array, first, j);
}

int main()
{
    srand((unsigned int)time(0));
    
    int n;
    vector<double> arr;
    cout << "Enter n: ";
    cin >> n;
    
    for (int i = n; i >= 0; i++)
    {
        arr[i] = (double)i / double(rand() % n);
        cout << arr[i] << " ";
    }
    
    cout << endl;
    sorting(arr, 1, n);
    
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    
    cout << endl << "Swaps: " << swap_counts;
}