#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int sequentialSearch(const vector<T> &vec, T target)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == target)
            return i;
    return -1;
}

template <typename T>
int rSequentialSearch(const vector<T> &vec, T target, int i = 0)
{
    if (i >= vec.size())
        return -1;
    if (vec[i] == target)
        return i;
    return rSequentialSearch(vec, target, i + 1);
}

template <typename T>
int binarySearch(const vector<T> &vec, T target)
{
    int left = 0, right = vec.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

template <typename T>
int rBinarySearch(const vector<T> &vec, T target, int left = -1, int right = -1)
{
    if (left == right && right == -1)
        return rBinarySearch(vec, target, 0, vec.size() - 1);
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (vec[mid] == target)
        return mid;
    if (vec[mid] < target)
        return rBinarySearch(vec, target, mid + 1, right);
    else
        return rBinarySearch(vec, target, left, mid - 1);
}

int main()
{
    int size;
    int choice;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Choose the searching algorithm \n1-sequential Search \n 2-recursive sequential search \n3-binarySearch\n4-recursive binary search" << endl;
    cin >> choice;
    while (choice >= 1 && choice <= 4)
    {
        int target;
        cout << "Enter the target element" << endl;
        cin >> target;
        int result;
        switch (choice)
        {
        case 1:
            result = sequentialSearch(arr, target);
            break;
        case 2:
            result = rSequentialSearch(arr, target);
            break;
        case 3:
            result = binarySearch(arr, target);
            break;
        case 4:
            result = rBinarySearch(arr, target);
            break;
        }
        if (result == -1)
            cout << "Element not found" << endl;
        else
            cout << "Element found at index " << result << endl;
        cout << "Choose the searching algorithm \n1-sequential Search \n2-recursive sequential search \n3-binarySearch\n4-recursive binary search" << endl;
        cin >> choice;
    }
    system("pause");
}
