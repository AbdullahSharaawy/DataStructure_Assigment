#pragma once
#include"DataAccess.h"
#include"SortingSystem.h"
#include"DataInput.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Controller
{
private:
	
	static void SelectSortingAlgo(int choice,SortingSystem<T>& obj);
	
public:
	static void StartSortingSystem();
	
};

template<typename T>
void Controller<T>::StartSortingSystem()
{
	int choice,size=0;// for the menu
	T* _Data=nullptr;
	DataAccess<T>::ReadData(_Data,size);
	
	SortingSystem<T> obj(size);

	//SortingObject = SelectObject(Data.size(),DataType);
	obj.SetData(_Data);
	
	delete []_Data;

	obj.showMenu();
	choice = DataInput::ReadChoice(1, 9);

	SelectSortingAlgo(choice, obj);

}

template<typename T>
void Controller<T>::SelectSortingAlgo(int choice,SortingSystem<T> &obj)
{
	cout << "\nInitial Data: ";
	obj.displayData();
	switch (choice)
	{
	case 1:
		obj.insertionSort();
		break;
	case 2:
		obj.selectionSort();
		break;
	case 3:
		obj.bubbleSort();
		break;
	case 4:

		break;
	case 5:
		obj.mergeSort(0, obj.GetSize() - 1);
		break;
	case 6:
		obj.quickSort(0, obj.GetSize() - 1);
		break;
	case 7:
		obj.countSort();
		break;
	case 8:
		//obj.radixSort();
		break;
	case 9:

		break;

	}
}


