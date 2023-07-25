#include "MyString.h"

inline String::String()
{
	arr = new char[1];
	arr[0] = '\0';
	size_arr = 1;
}

inline String::String(const char* object)
{
	arr = new char[strlen(object) + 1];
	size_arr = strlen(object) + 1;
	for (size_t i = 0; i < strlen(object) + 1; i++)
	{
		arr[i] = object[i];
	}
}

inline String::String(const String& object)
{
	size_arr = object.size_arr;
	arr = new char[size_arr];
	for (size_t i = 0; i < size_arr; i++)
	{
		arr[i] = object.arr[i];
	}
}

inline String::~String()
{
	delete[] arr;
}

inline int String::length()
{
	return strlen(arr);
}

inline void String::append(const String& object)
{
	char* temp = new char[strlen(arr) + strlen(object.arr) + 1];
	for (size_t i = 0; i < strlen(arr); i++)
	{
		temp[i] = arr[i];
	}
	for (size_t i = 0; i < strlen(object.arr); i++)
	{
		temp[strlen(arr) + i] = object.arr[i];
	}
	temp[strlen(arr) + strlen(object.arr)] = '\0';
	delete[] arr;
	arr = new char[strlen(temp) + 1];
	for (size_t i = 0; i < strlen(temp) + 1; i++)
	{
		arr[i] = temp[i];
	}
	size_arr = strlen(temp) + 1;
	delete[] temp;
}

inline void String::append(const char object[])
{
	char* temp = new char[strlen(arr) + strlen(object) + 1];
	for (size_t i = 0; i < strlen(arr); i++)
	{
		temp[i] = arr[i];
	}
	for (size_t i = 0; i < strlen(object); i++)
	{
		temp[strlen(arr) + i] = object[i];
	}
	temp[strlen(arr) + strlen(object)] = '\0';
	delete[] arr;
	arr = new char[strlen(temp) + 1];
	for (size_t i = 0; i < strlen(temp) + 1; i++)
	{
		arr[i] = temp[i];
	}
	size_arr = strlen(temp) + 1;
	delete[] temp;
}

inline void String::reverse()
{
	int value = 1;
	if (strlen(arr) % 2 == 0) { value = 0; }
	for (size_t i = 0; i < (strlen(arr) - value) / 2; i++)
	{
		char temp = arr[i];
		arr[i] = arr[strlen(arr) - i - 1];
		arr[strlen(arr) - i - 1] = temp;
	}
}

inline void String::clear()
{
	delete[] arr;

	arr = new char[1];
	arr[0] = '\0';
	size_arr = 1;
}
