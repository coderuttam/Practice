#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int value;
    int weight;
    double vwratio;
};
void swapItem(Item *a, Item *b)
{
    Item p;
    p = *a;
    *a = *b;
    *b = p;
}
void valueWeightRatio(Item arr[], int i, int n)
{
    arr[i].vwratio = (double)arr[i].value / arr[i].weight;
    if (i < n)
        valueWeightRatio(arr, ++i, n);
}

void sortByRatio(Item arr[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i].vwratio > arr[j].vwratio)
                swapItem(&arr[i], &arr[j]);
}
void displayKnapsack(Item arr[], int i, double fw)
{
    double vsum=0;
    cout << "The value (profit)/weight ratio along with their specific weight that they carries in a knapsack is listed below :\n";
    for (int a = 0; a < i; a++)
    {
        if((fw!=0) && (a==i-1)) cout<<fw;
        else cout << 1 << "\t";
    }
    cout<<endl;
    for (int a = 0; a < i; a++)
    {
        if (fw == 0)
            cout << arr[a].weight << "\t";
        if (fw != 0)
        {
            if (a == i - 1)
            {
                vsum+=(fw*arr[a].value);
                cout << ((arr[a].weight) * fw);
                break;
            }
            else
                cout << arr[a].weight << "\t";
        }
        vsum += arr[a].value;
    }
    cout << "\nMaximum value (profit) we can obtain = "<<vsum;
}
void fillKnapsack(int w, Item arr[], int &i, int n, double &fw)
{
    if ((i == n) || (w == 0))
    {
        displayKnapsack(arr, i, fw);
    }
    if ((w > 0) && (i < n))
    {
        if (arr[i].weight <= w)
        {
            int wc = w - arr[i].weight;
            fillKnapsack(wc, arr, ++i, n, fw);
        }
        else
        {
            fw = (double)w / arr[i].weight;
            fillKnapsack(0, arr, ++i, n, fw);
        }
    }
}
void fractionalKnapsack(int weight, Item arr[], int n)
{
    double fw = 0;
    int i = 0;
    valueWeightRatio(arr, 0, n);
    sortByRatio(arr, n);
    fillKnapsack(weight, arr, i, n, fw);
}
int main()
{
    int W = 50;
    //Item arr[] = {{60, 10}, {100, 20}, {120, 30}, {20, 30}, {10, 50}, {150, 20}, {100, 50}, {80, 30}};
    Item arr[] = {{60, 10}, {120, 30}, {100, 20}};
    int n = sizeof(arr) / sizeof(arr[0]);
    fractionalKnapsack(W, arr, n);
    return 0;
}