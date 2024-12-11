#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Heap
{
private:
    vector<int> elements;

    void heapifyUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (elements[i] > elements[parent])
            {
                swap(elements[i], elements[parent]);
                i = parent;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int i, int heapSize)
    {

        while (i < heapSize )
        {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            int largest = i;

            if (leftChild < heapSize  && elements[leftChild] > elements[largest]) {
                largest = leftChild;
            }
            if (rightChild < heapSize && elements[rightChild] > elements[largest]) {
                largest = rightChild;
            }
            if (largest != i)
            {
                swap(elements[i], elements[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }

public:

    // Insert element into the heap
    void insertElem(int elem)
    {
        elements.push_back(elem);
        heapifyUp(elements.size() - 1);
    }

    // Find and remove the max element from the heap
    int findMax()
    {
        if (elements.empty()) throw runtime_error("Heap is empty, no Maximum to extract.");

        int maxVal = elements[0];
        elements[0] = elements.back();
        elements.pop_back();

        if (!elements.empty())
            heapifyDown(0, elements.size());

        return maxVal;
    }

    // Find the minimum element in the heap
    int findMin()
    {
        if (elements.empty()) throw runtime_error("Heap is empty, no minimum to find.");

        int minIndex = (elements.size() - 1) / 2 + 1;
        int minVal = elements[minIndex];

        for (int i = minIndex + 1; i < elements.size(); ++i) {
            if (elements[i] < minVal)
                minVal = elements[i];
        }

        return minVal;
    }

    // Display the contents
    void display() const
    {
        for (int value : elements)
            cout << value << " ";
        cout << "\n---------------------------------------\n";
    }

    // Heap sort: Sort array using the heap
    void heapSort(vector<int>& arr)
    {
        elements = arr;
        int heapSize = elements.size();

        // Build max heap
        for (int i = heapSize / 2 - 1; i >= 0; --i)
            heapifyDown(i, heapSize);


        // One by one extract
        for (int i = heapSize - 1; i > 0; --i) {
            swap(elements[0], elements[i]);
            heapifyDown(0, i);
        }

        arr = elements;
    }

};

class PriorityQueue
{
private:
    Heap heap;

public:
    // Insert an element with a priority [ higher number = higher priority ]
    void enqueue(int value)
    {
        heap.insertElem(value);
    }

    // Extract the element with the highest priority
    int extractHighestPriority()
    {
        return heap.findMax();
    }

    void display() const
    {
        heap.display();
    }
};


void insertMultipleElements(Heap& heap, vector<int>& arr)
{
    int n, value;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    arr.clear();

    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        heap.insertElem(value);
        arr.push_back(value);
    }
}

void insertMultipleElements(PriorityQueue& queue, vector<int>& arr)
{
    int n, value;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    arr.clear();

    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        queue.enqueue(value);
        arr.push_back(value);
    }
}


int main(){

    Heap heap;
    PriorityQueue testQueue;
    vector<int> array;
    int choice;
    string s = "\n---------------------------------------\n";

    do {
        cout << "\nPlease Select a valid option from [ 1 to 9 ]:" << endl;
        cout << "1. Insert into Heap" << endl;
        cout << "2. Extract Max from Heap" << endl;
        cout << "3. Extract Min from Heap" << endl;
        cout << "4. Display Heap" << endl;
        cout << "5. Insert into Priority Queue" << endl;
        cout << "6. Extract Highest Priority from Queue" << endl;
        cout << "7. Display Priority Queue" << endl;
        cout << "8. Heap Sort" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        try {
            switch (choice)
            {
                case 1:
                {
                    insertMultipleElements(heap, array);
                    break;
                }

                case 2:
                {
                    cout << s << "Extracted max: " << heap.findMax() << " from Heap." << s;
                    break;
                }

                case 3:
                {
                    cout << s << "Extracted min: " << heap.findMin() << " from Heap." << s;
                    break;
                }

                case 4:
                {
                    cout << s << "Heap contents: ";
                    heap.display();
                    break;
                }

                case 5:
                {
                    insertMultipleElements(testQueue, array);
                    break;
                }

                case 6:
                {
                    cout << s << "Extracted highest priority: " << testQueue.extractHighestPriority() << " from Priority Queue." << s;
                    break;
                }

                case 7:
                {
                    cout << s << "Priority Queue contents: ";
                    testQueue.display();
                    break;
                }

                case 8:
                {
                    vector<int> originalArray = array;
                    heap.heapSort(array);
                    cout << s << "Array after heap sort: ";
                    for (const int v : array)
                        cout << v << " ";
                    cout << s;

                    // Restore the original heap
                    array = originalArray;
                    break;
                }

                case 9:
                {
                    cout << s << "Exiting program." << s;
                    break;
                }

                default:
                    cout << s << "Invalid choice, please try again." << s;
            }
        } catch (const exception& e) {
            cout << "\nError: " << e.what() << s;
        }

    } while (choice != 9);

    return 0;
}
