#include <iostream>
#include <stdlib.h>

template <typename ArrayType>
class Array {
	public:
		Array();
		Array(ArrayType items);

		void grow();
		void push_back(ArrayType item);
		void insert(unsigned int index, ArrayType item);
		void remove(unsigned int index);
		void create_space(unsigned int index);
		ArrayType at(unsigned int index);
	
	
		unsigned int maxSize;
		unsigned int count;
		ArrayType* arr;
};