#include <bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY O(n^2)
pair<int,int> bubbleSort(int *input, int size)
{
    int count_swaps = 0;
    int count_comparisons = 0;
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (input[i] > input[i + 1])
            {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
                count_swaps++;
            }
            count_comparisons++;
        }
    }
    pair<int,int> ans;
    ans.first = count_swaps;//first member would store the number of swaps.
    ans.second = count_comparisons;//second member would store the number of comparisons.
    return ans;
}

//TIME COMPLEXITY O(n^2)
pair<int,int> SelectionSort(int *input,int size)
{
    int min_index;
    int count_swaps = 0;
    int count_comparisons = 0;
    for(int i=0;i<size;i++)
    {
        min_index = i;
        for(int j=i+1;j<size;j++)
        {
            if(input[j]<input[min_index])
            {
                min_index = j;
                count_swaps++;
            }
            count_comparisons++;
        }
        int temp = input[i];
        input[i] = input[min_index];
        input[min_index] = temp;
    }
    pair<int,int> ans;
    ans.first = count_swaps;
    ans.second = count_comparisons;
    return ans;
}

int main()
{
    int n;
    cout << "Enter size of array :- ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pair<int,int> bubble = bubbleSort(arr,n);
    pair<int,int> selection = SelectionSort(arr,n);

    cout << "Comparison between insertion and bubble sort. " << endl;

    cout << "1. On the basis of number of comparisons : " << " ";
    if(bubble.second > selection.second)
    {
        cout << "More comparsions are required for bubble sort." << endl;
    }
    else if(bubble.second < selection.second)
    {
        cout << "More comparisons are required for selection sort." << endl;
    }
    else
    {
        cout << "Both require equal number of comparsions." << endl;
    }
    cout << endl;

    //second comparison

    cout << "2. On the basis of ROF swaps : " << " ";
    if(bubble.first > selection.first)
    {
        cout << "More swaps are required for bubble sort." << endl;
    }
    else if(bubble.first < selection.first)
    {
        cout << "More swaps are required for selection sort." << endl;
    }
    else
    {
        cout << "Both require equal number of swaps." << endl;
    }
    cout << endl;

    cout << "3. As both bubble sort and selection sort are In-place algorithms, therefore both of their Inplace Algorithms have been written above." << endl;

}
