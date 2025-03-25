#include <iostream>
#include"DataInput.h"
#include<string>// use it for casting only
static bool TurnOn = false;
static int mod = 10;
using namespace std;
template<typename T>
class SortingSystem {
private:
    T* _data;       // Pointer to the array to be sorted
    int _size;      // Size of the array
    int CountIteration = 0;
public:
    // Constructor
    SortingSystem( int size) :  _size(size) {}
    SortingSystem(){}
    // Destructor
    ~SortingSystem() {}

    // Counting Sort function
    void countSort();
    void insertionSort();  // (1) Insertion Sort
    void selectionSort();  // (2) Selection Sort
    void bubbleSort();     // (3) Bubble Sort
    void shellSort();      // (4) Shell Sort
    void mergeSort(int left, int right); // (5) Merge Sort
    void quickSort(int left, int right); // (6) Quick Sort
    void radixSort();      // (8) Radix Sort (Only for int)
    void bucketSort();     // (9) Bucket Sort
    void merge(int left, int mid, int right); // Merge Sort Helper
    int partition(int low, int high);         // Quick Sort Helper

    void SetData(T* _Data );
    // Utility function to print the array
    void displayData();
    void showMenu();
    void selectSortingAlgorithm();
};
template<typename T>
void SortingSystem<T>::SetData(T* _Data)
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
void SortingSystem<T>::displayData()
{
    for (size_t i = 0; i < this->_size; i++)
    {
        cout << this->_data[i] << ", ";
    }

    cout << endl;
}
template<typename T>
void SortingSystem<T>::countSort() {
    if constexpr (is_integral<T>::value)
    {
        if (_size <= 1) return; // No need to sort if array has 0 or 1 element
       
        
        auto x = [](T n) { return TurnOn ? (n % mod) / (mod / 10) : n; };


        int maxElement = x(static_cast<int>(_data[0]));
        for (size_t i = 0; i < this->_size; i++)
        {
            if (maxElement < x(static_cast<int>(_data[i])))
                maxElement = x(static_cast<int>(_data[i]));
        }
        int K = (maxElement); // Convert to integer for counting


        int* Count = new int[K + 1] {0};


        int* Temp = new int[_size] { 0 };
        if(!TurnOn)// use this print for count sort only not radix sort
        cout << "count the numbers and store it in the count array\n";
        for (int i = 0; i < _size; i++) {
            int index = (x(static_cast<int>(_data[i]))); 
            Count[index]++;
            if (!TurnOn)// use it for count sort only not radix sort
            {
                cout << "Iteration " << ++CountIteration << ": ";
                for (size_t j = 0; j < _size; j++)
                {
                    cout << Count[j] << ", ";
                }
                cout << endl;
            }
            
        }
        CountIteration = 0;
        if(!TurnOn)// use this print for count sort only not radix sort
        cout << "compute the comulative and store it in the count array\n";
        
        for (int i = 1; i <= K; i++) {
            Count[i] += Count[i - 1];
            if (!TurnOn)// use it for count sort only not radix sort
            {
                cout << "Iteration " << ++CountIteration << ": ";
                for (size_t j = 0; j < _size; j++)
                {
                    cout << Count[j] << ", ";
                }
                cout << endl;
            }
            
        }
        CountIteration = 0;
        cout << "iterations for sorting the data\n";
        for (int i = _size - 1; i >= 0; i--) {
            int index = (x(static_cast<int>(_data[i])));
            Temp[Count[index] - 1] = x(static_cast<int>(_data[i]));
            Count[index]--;

            //print the iterations
            cout << "Iteration " << ++CountIteration << ": ";
            for (size_t i = 0; i < this->_size; i++)
            {
                cout << Temp[i] << ", ";
            }

            cout << endl;
        }

        for (int i = 0; i < _size; i++) {
            _data[i] = Temp[i];

        }
        CountIteration = 0;
        delete[] Count;
        delete[] Temp;


    }
   
};
template<typename T>
void SortingSystem<T>::selectSortingAlgorithm()
{
     showMenu();
     int choice = DataInput::ReadChoice(1, 9);


        cout << "\nInitial Data: ";
        displayData();
        switch (choice)
        {
        case 1:
            insertionSort();
            break;
        case 2:
            selectionSort();
            break;
        case 3:
            bubbleSort();
            break;
        case 4:
            shellSort();
            break;
        case 5:
            mergeSort(0, this->_size - 1);
            break;
        case 6:
           quickSort(0, this->_size - 1);
            break;
        case 7:
            countSort();
            break;
        case 8:
            radixSort();
            break;
        case 9:
            bucketSort();
            break;

        }
}
template <typename T>
void SortingSystem<T>::shellSort()
{
    for (int g = this->_size / 2;g > 0;g /= 2)
    {
        for (int i = g; i < this->_size; i++)
        {
            for (int j = i; j >= g; j -= g)
            {
                if (this->_data[j] < this->_data[j - g])
                {
                    T tmep = this->_data[j];
                    this->_data[j] = this->_data[j - g];
                    this->_data[j - g] = tmep;
                    //print iterations
                    cout << "Iteration " << ++CountIteration << ": ";
                    displayData();
                }
                else break;
            }
        }
    }
    CountIteration = 0;
}

template <typename T>
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
                //print iterations
                cout << "Iteration " << ++CountIteration << ": ";
                displayData();
            }
            else break;
        }
    }
    CountIteration = 0;
}

template <typename T>
void SortingSystem<T>::bubbleSort()
{
    auto Swap = [](T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
        };

    for (int i = 0; i < this->_size; i++)
    {
        for (int j = 1; j < this->_size ; j++)
        {
            if (this->_data[j] < this->_data[j - 1])
                Swap(this->_data[j], this->_data[j - 1]);
            //print iterations
            cout << "Iteration " << ++CountIteration << ": ";
            displayData();
        }
    }
    CountIteration = 0;
}

template <typename T>
void SortingSystem<T>::selectionSort()
{
    for (int i = 0; i < this->_size; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < this->_size ; j++)
        {
            if (_data[j] < _data[MinIndex])
            {
                MinIndex = j;
            }

        }
        T temp = _data[i];
        _data[i] = _data[MinIndex];
        _data[MinIndex] = temp;
        //print iterations
        cout << "Iteration " << ++CountIteration << ": ";
        displayData();
    }
    CountIteration = 0;
}

template <typename T>
void SortingSystem<T>::mergeSort(int left, int right)
{
    if (left < right)
    {
        int Medium = (left + right) / 2;
        mergeSort(left, Medium);
        mergeSort(Medium + 1, right);
        merge(left, Medium, right);
    }
    CountIteration = 0;
}

template <typename T>
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
    //print iterations
    cout << "Iteration " << ++CountIteration << ": ";
    displayData();

}

template <typename T>
void SortingSystem<T>::quickSort(int left, int right)
{
    if (left < right)
    {
        int _PivotIndex = partition(left, right);
        quickSort(left, _PivotIndex - 1);
        quickSort(_PivotIndex + 1, right);

    }
    CountIteration = 0;
}

template <typename T>
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

    Swap(_data[PivotIndex], _data[EndIndex]);
    //print iterations
    cout << "Iteration " << ++CountIteration << ": ";
    displayData();
    return EndIndex;

}
template <typename T>
void SortingSystem<T>::radixSort()
{
    if constexpr (is_integral<T>::value)
    {
        int MaxElement = 0; // Find the maximum element
        TurnOn = true;
        int d = 0;// number of call the Count Sort
       
        for (size_t i = 0; i < _size; i++)
        {
            if (static_cast<int>(_data[i]) > MaxElement)
                MaxElement = static_cast<int>(_data[i]);
        }

        while (MaxElement > 0)
        {
            d += 1;
            MaxElement /= 10;
        }

        while (d > 0)
        {
            countSort();
            d--;
            mod *= 10;
            
        }
    }
}
template<typename T>
void SortingSystem<T>::bucketSort()
{
    // insertion sort as lambda function
    auto insertionSort = [](T* data, int size) {
        for (int i = 0;i < size - 1;i++)
        {
            for (int j = i + 1;j > 0;j--)
            {

                if (data[j] < data[j - 1])
                {
                    T tmep = data[j];
                    data[j] = data[j - 1];
                    data[j - 1] = tmep;

                }
                else break;
            }
        }

        };
    int BucketCount;
    T** Buckets = nullptr;
    int* BucketsSizes=nullptr;
    T* newData = nullptr;
    // algo for the numbers only
    if constexpr (is_integral<T>::value ||
        is_same_v<T, char> ||
        is_same_v<T, double> ||
        is_same_v<T, float>)
    {
        
        BucketCount = ceil(sqrt(this->_size));

        int Min = static_cast<int>(this->_data[0]);
        int Max = static_cast<int>(this->_data[0]);

        for (size_t i = 0; i < this->_size; i++)
        {
            if (Min > static_cast<int>(_data[i]))
                Min = static_cast<int>(_data[i]);
            if (Max < static_cast<int>(_data[i]))
                Max = static_cast<int>(_data[i]);
        }
        int range = (Max - Min) / BucketCount + 1e-9;

         Buckets = new T * [BucketCount];
        for (size_t i = 0; i < BucketCount; i++)
        {
            Buckets[i] = new T[this->_size];
        }
         BucketsSizes = new int[BucketCount]();
         
        for (size_t i = 0; i < this->_size; i++)
        {
            int index = (static_cast<int>(this->_data[i]) - Min) / range;
            while (index >= BucketCount)
                index--;
            Buckets[index][BucketsSizes[index]++] = this->_data[i];
         }
        cout << "Iterations for store the data in the buckets\n";

        //print iterations
        for (size_t k = 0; k < BucketCount; k++)
        {
            cout << "Bucket " << k + 1 << ": ";

            for (size_t j = 0;j < BucketsSizes[k];j++)
                cout << Buckets[k][j] << ", ";
            cout << endl;

        }

        // sorting
        for (size_t i = 0; i < BucketCount; i++)
        {
            insertionSort(Buckets[i], BucketsSizes[i]);
        }
      
        int index = 0;
         newData = new T[this->_size];
         for (size_t i = 0; i < BucketCount; i++)
        {
            for (size_t j = 0; j < BucketsSizes[i]; j++)
            {
                newData[index++] = Buckets[i][j];
                
            }
        }
         cout << "Iterations for sorting the buckets\n";

         for (size_t k = 0; k < BucketCount; k++)
         {
             cout << "Bucket " << k + 1 << ": ";

             for (size_t j = 0;j < BucketsSizes[k];j++)
                 cout << Buckets[k][j] << ", ";
             cout << endl;

         }

         cout << "the data after merge the buckets it\n";
         for (size_t i = 0; i < _size; i++)
         {
             cout << newData[i] << ", ";
         }
         cout << endl;
       
    }
    // algo for string
    else if  constexpr (is_same_v<T, string>)
    {
        BucketCount = 28;
        Buckets = new T * [BucketCount];
        for (size_t i = 0; i < BucketCount; i++)
        {
            Buckets[i] = new T[this->_size];
        }
        BucketsSizes = new int[BucketCount]();
       
        for (size_t i = 0; i < this->_size; i++)
        {
            int index = (_data[i][0]-'a');
            Buckets[index][BucketsSizes[index]++] = this->_data[i];
            
        }
        cout << "Iterations for store the data in the buckets\n";

        //print iterations
          for (size_t k = 0; k < BucketCount; k++)
        {
              cout << "Bucket " << k+1 << ": ";

            for (size_t j = 0;j < BucketsSizes[k];j++)
                cout << Buckets[k][j] << ", ";
            cout << endl;

          }
        // sorting
        for (size_t i = 0; i < BucketCount; i++)
        {
            insertionSort(Buckets[i], BucketsSizes[i]);
            }
        //print iterations
        cout << "Iterations for sorting the buckets\n";

        for (size_t k = 0; k < BucketCount; k++)
        {
            cout << "Bucket " << k + 1 << ": ";

            for (size_t j = 0;j < BucketsSizes[k];j++)
                cout << Buckets[k][j] << ", ";
            cout << endl;

        }

        int index = 0;
       
        newData = new T[this->_size];

        for (size_t i = 0; i < BucketCount; i++)
        {
            for (size_t j = 0; j < BucketsSizes[i]; j++)
            {
                newData[index++] = Buckets[i][j];
            }
        }
        cout << "the data after merge the buckets it\n";
        for (size_t i = 0; i < _size; i++)
        {
            cout << newData[i] << ", ";
        }
        cout << endl;
    }
    delete[] this->_data;
    this->_data = newData;
    for (int i = 0; i < BucketCount; i++) {
        delete[] Buckets[i]; // Delete each bucket
    }
    delete[] Buckets;      // Delete bucket pointers array
    delete[] BucketsSizes;  // Delete bucket sizes array
    }
