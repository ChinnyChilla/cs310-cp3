#include "Array.h"	
using namespace std;

template <typename ArrayType>
Array<ArrayType>::Array()
{
	arr = new ArrayType[2];
	maxSize = 2;
	count = 0;
	
}

template <typename ArrayType>
Array<ArrayType>::~Array() {
	delete[] arr;
}

template <typename ArrayType>
Array<ArrayType>::Array(ArrayType items)
{
	arr = new ArrayType[2];
	maxSize = 2;
	count = 0;
}
template <typename ArrayType>
void Array<ArrayType>::grow()
{
	ArrayType* newArray = new ArrayType[maxSize * 2];
	for (unsigned int i=0; i < maxSize; i++) {
		newArray[i] = arr[i];
	}
	maxSize = maxSize*2;
	delete[] arr;
	arr = newArray;
	return;
}
template <typename ArrayType>
void Array<ArrayType>::push_back(ArrayType item)
{
	if(count == maxSize) grow();
	arr[count] = item;
	count++;
	return;
}
template <typename ArrayType>
void Array<ArrayType>::insert(unsigned int index, ArrayType item)
{
	if (count == maxSize) grow();
	create_space(index);
	arr[index] = item;
	count++;
	return;
}
template <typename ArrayType>
void Array<ArrayType>::create_space(unsigned int index)
{
	for (unsigned int i=count; i>index; i--) {
		arr[i] = arr[i-1];
	}
	return;
}
template <typename ArrayType>
void Array<ArrayType>::remove(unsigned int index)
{	
	for (unsigned int i=index+1; i<count; i++) {
		arr[i-1] = arr[i];
	}
	count--;
	return;
}
template <typename ArrayType>
ArrayType Array<ArrayType>::at(unsigned int index)
{
	return arr[index];
}
