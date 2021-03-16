#include <bits/stdc++.h>
using namespace std;
int mid;
double m;
int findNumber(int arr[], int value, int lo, int hi)
{
    if ((arr[hi] < value) || (arr[lo] > value))
        return -1;
    m = (double)(lo + hi) / 2;
    mid = m;
    if (arr[mid] == value)
        return mid;
    else if (arr[mid] > value)
    {
        if (m != mid)
            mid--;
        return findNumber(arr, value, lo, mid);
    }
    else
    {
        if (m != mid)
            mid++;
        return findNumber(arr, value, mid, hi);
    }
}


int main()
{
    int A[] = {-1,0, 1, 2};
    int num, check;
    cout << "Enter the no. you want to search from the array.\n";
    cin >> num;
    check = findNumber(A, num, 0, 3);
    if (check == -1)
        cout << "The no. you wanted to search was not found in the array.\n";
    else
        cout << "The no. you wanted to search was found at " << check + 1 << " position.\n";
    return 0;
}