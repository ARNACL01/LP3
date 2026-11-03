// Write a program for analysis of quick sort by using deterministic and randomized variant.


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Deterministic partition using the last element as pivot
int partitionDet(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Randomized partition using a random pivot
int partitionRand(int a[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(a[randomIndex], a[high]);

    return partitionDet(a, low, high);
}

// Deterministic Quick Sort
void quickSortDet(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partitionDet(a, low, high);

        quickSortDet(a, low, p - 1);
        quickSortDet(a, p + 1, high);
    }
}

// Randomized Quick Sort
void quickSortRand(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partitionRand(a, low, high);

        quickSortRand(a, low, p - 1);
        quickSortRand(a, p + 1, high);
    }
}

// Display array
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid size";
        return 0;
    }

    int *a = new int[n];
    int *b = new int[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    quickSortDet(a, 0, n - 1);
    cout << "\nDeterministic Quick Sort: ";
    display(a, n);

    quickSortRand(b, 0, n - 1);
    cout << "Randomized Quick Sort: ";
    display(b, n);

    delete[] a;
    delete[] b;

    return 0;
}
