
#include <iostream>

using namespace std;

void print(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

void solve(int *arr, int index, int sum)
{

    if (index == 2 && sum < 8)
    {

        arr[2] = 8 - sum;
        cout << '[' << arr[0] << " " << arr[1] << " " << arr[2] << ']' << endl;
    }

    for (int i = (index == 0) ? 1 : arr[index - 1]; i <= 9 - sum; i++)
    {
        arr[index] = i;
        solve(arr, index + 1, sum + i);
    }

    return;
}

int main()
{

    int size{3};
    int *arr = new int[size];

    // print(arr, size);
    solve(arr, 0, 0);

    delete[] arr;
    return 0;
}