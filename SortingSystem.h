
#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include <algorithm>   

//#include <type_traits> // For std::is_integral

using namespace std;

template <typename T>
class SortingSystem {
private:
    T* _data;  // Dynamic array for storing input data
    int _size; // Size of the array
    int CountIteration = 0;
public:
    SortingSystem(int n);  // Constructor
    ~SortingSystem();      // Destructor
    void SetData (T * Data);
    int GetSize();
    void insertionSort();  // (1) Insertion Sort
    void selectionSort();  // (2) Selection Sort
    void bubbleSort();     // (3) Bubble Sort
    void shellSort ();      // (4) Shell Sort
    void mergeSort (int left, int right); // (5) Merge Sort
    void quickSort (int left, int right); // (6) Quick Sort
    void countSort ();      // (7) Count Sort (Only for int)
    //void countSort(int mod , bool TurnOn );
    void radixSort ();      // (8) Radix Sort (Only for int)
    void bucketSort() ;     // (9) Bucket Sort

    void merge (int left, int mid, int right) ; // Merge Sort Helper
    int partition (int low, int high);         // Quick Sort Helper

    void displayData () ; // Print the current state of the array
    void measureSortTime (void (SortingSystem::* sortFunc)()); // Measure sorting time
    void displayIteration();// display data step by step during the sort
    void showMenu () ; // Display menu for user interaction
};
template<typename T>
int SortingSystem<T>::GetSize()
{
    return this->_size;
}
template<typename T>
void SortingSystem<T>::displayIteration()
{
    CountIteration++;
    cout << "Iteration " << CountIteration<<": ";
    this->displayData();
}
template<typename T>
void SortingSystem<T>::showMenu()
{
    cout << "\n Select a sorting algorithm:\n";
    cout << "\n 1. Insertion Sort\n";
    cout << "\n 2. Selection Sort\n";
    cout << "\n 3. Bubble Sort\n";
    cout << "\n 4. Shell Sort \n";
    cout << "\n 5. Merge Sort \n";
    cout << "\n 6. Quick Sort\n";
    cout << "\n 7. Count Sort (Only for integers) \n";
    cout << "\n 8. Radix Sort (Only for integers)\n";
    cout << "\n 9. Bucket Sort \n";
   
    cout << "\n Enter your choice (1-9): ";
}
template<typename T>
SortingSystem<T>::SortingSystem(int n)
{
    _size = n;
    _data = nullptr;
}

    template <typename T>
    void SortingSystem<T>::SetData(T * _Data)
    {
        if (_Data == nullptr) {
            throw std::invalid_argument("Input data pointer is null.");
        }

        // Allocate new memory first
        T* newData = nullptr;
        try {
            newData = new T[_size];
        }
        catch (const std::bad_alloc& e) {
            // Handle memory allocation failure
            throw std::runtime_error("Failed to allocate memory for data.");
        }

        // Copy data element-wise
        for (size_t i = 0; i < _size; i++) {
            newData[i] = _Data[i];
        }

        // Delete old data and replace with new data
        delete[] _data; // Safe to delete even if _data is nullptr
        _data = newData;
    }

template<typename T>
SortingSystem<T>::~SortingSystem()
{
    delete[] this->_data;
}
template<typename T>
void SortingSystem<T>::insertionSort()
{
    for (int i = 0;i < this->_size - 1;i++)
    {
        for (int j = i + 1;j > 0;j--)
        {

            if (_data[j] < _data[j - 1])
            {
                T tmep = _data[j];
                _data[j] = _data[j - 1];
                _data[j - 1] = tmep;
                displayIteration();
            }
            else break;
        }
    }
    CountIteration = 0;
}
template<typename T>
void SortingSystem<T>::displayData()
{
    for (size_t i = 0; i < this->_size; i++)
    {
        cout << this->_data[i] << ", ";
    }
        
    cout << endl;
}
template<typename T>
void SortingSystem<T>::bubbleSort()
{
    auto Swap = [](T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
        };
   
        for (int i = 0; i < this->_size; i++)
        {
            for (int j = 1; j < this->_size - i; j++)
            {
                if (this->_data[j] < this->_data[j - 1])
                    Swap( this->_data[j], this->_data[j - 1]);
                displayIteration();
            }
        }
        CountIteration = 0;
}
template<typename T>
void SortingSystem<T>::selectionSort()
{
    for (int i = 0; i < this->_size; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < this->_size - 1; j++)
        {
            if (_data[j] < _data[MinIndex])
            {
                MinIndex = j;
            }

        }
        T temp = _data[i];
        _data[i] = _data[MinIndex];
        _data[MinIndex] = temp;
        displayIteration();
    }
    CountIteration = 0;
}
template<typename T>
void SortingSystem<T>::countSort( )
{
    T maxElement = *max_element(_data, _data + _size);

    int K = static_cast<int>(maxElement);
    int* Count= new int[K + 1] {0};  // Initialize count array with zeros
    T* Temp = new T[_size] {0};
    int Sum=0;

    // Lambda function use it during radix sort only
  //  auto x = [TurnOn, mod](T n) { return TurnOn ? (n % mod) / (mod / 10) : n; };

//     Find the max value of x(_data[i])
   /* for (int i = 0; i < _size; i++) {
        int current = _data[i];
        if (current > K)
            K = current;
    }*/

    

    // Count occurrences
    for (int i = 0; i < _size; i++) {
        int index = static_cast<int>(_data[i]);
        Count[index]++;
    }

    // Compute cumulative sum (position)
    Sum = Count[0];
    for (int i = 1; i <= K; i++) {
        Sum += Count[i];
        Count[i] = Sum;
    }

    // Sorting process
    for (int i = _size - 1; i >= 0; i--) {
        int element = static_cast<int>(_data[i]);
        int index = Count[element] - 1;
        
        Count[element]--;  // Update cumulative position
        Temp[index] = static_cast<int>(_data[i]);
        // display the iteration step by step
        CountIteration++;
        cout << "Iteration " << CountIteration << ": ";
        for (size_t i = 0; i < this->_size; i++)
        {
            cout << Temp[i] << ", ";
        }

        cout << endl;
    }
    delete[] _data;//deep copy
    _data = Temp;

    // Cleanup dynamically allocated arrays
    delete[] Count;
    
}

template<typename T>
void SortingSystem<T>::radixSort()
{
    // Ensure T is an integer type
   // static_assert(is_integral<T>::value, "radixSort requires integer types");


    T * MaxElement = 0; // Find the maximum element

    int d = 0;// number of call the Count Sort
    int Mode = 10;
    for (size_t i = 0; i < _size; i++)
    {
        if (_data[i] > MaxElement)
            MaxElement = _data[i];

    }
        
    while (MaxElement > 0)
    {
        d += 1;
        MaxElement /= 10;
    }

    while (d > 0)
    {
       // countSort( );
        d--;
        Mode *= 10;
    }
}
template<typename T>
void SortingSystem<T>::mergeSort(int left, int right)
{
    if (left < right)
    {
        int Medium = (left + right) / 2;
        mergeSort( left, Medium);
        mergeSort( Medium + 1, right);
        merge(  left, Medium, right);
    }
    CountIteration = 0;
}
template<typename T>
void SortingSystem<T>::merge(int left, int mid, int right)
{
    int Lower1 = left;
    int Lower2 = mid + 1;
    int index = 0;
    T* temp = new T[right - left + 1];
    while (Lower1 <= mid && Lower2 <= right)
    {
        if (_data[Lower1] <= _data[Lower2])
        {
            temp[index] = _data[Lower1];
            Lower1++;
            index++;
        }
        else
        {
            temp[index] = _data[Lower2];
            Lower2++;
            index++;
        }

    }
    while (Lower1 <= mid)
        temp[index++] = _data[Lower1++];

    while (Lower2 <= right)
        temp[index++] = _data[Lower2++];

    index = 0;
    for (int i = left; i <= right; i++)
        _data[i] = temp[index++];
    displayIteration();

}
template<typename T>
void SortingSystem<T>::quickSort(int left, int right)
{
    if (left < right)
    {
        int _PivotIndex = partition( left, right);
        quickSort( left, _PivotIndex - 1);
        quickSort( _PivotIndex + 1, right);

    }
    CountIteration = 0;
}
template<typename T>
int SortingSystem<T>::partition(int low, int high)
{
    int StartIndex = low, EndIndex = high;
    int PivotIndex = StartIndex++;

    auto Swap = [](T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
        };


    while (StartIndex <= EndIndex)
    {
        while (StartIndex <= EndIndex && _data[StartIndex] <= _data[PivotIndex])
            StartIndex++;
        while (StartIndex <= EndIndex && _data[EndIndex] > _data[PivotIndex])
            EndIndex--;
        if (StartIndex <= EndIndex)
            Swap(_data[StartIndex++], _data[EndIndex--]);
    }

    Swap(_data[PivotIndex],_data[ EndIndex]);
    displayIteration();
    return EndIndex;

}
