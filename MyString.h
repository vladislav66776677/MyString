#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	char* arr;
	int size_arr;

public:
	String();
	String(const char* object);
	String(const String& object);

	~String();

	void operator = (const String& object)
	{
		delete[] arr;
		size_arr = object.size_arr;
		arr = new char[size_arr];
		for (size_t i = 0; i < size_arr; i++)
		{
			arr[i] = object.arr[i];
		}
	}
	void operator = (const char object[])
	{
		delete[] arr;
		arr = new char[strlen(object) + 1];
		for (size_t i = 0; i < strlen(object) + 1; i++)
		{
			arr[i] = object[i];
		}
		size_arr = strlen(object) + 1;
	}
	String operator + (const String& object)
	{
		String temp;
		temp.append(arr);
		temp.append(object);
		return temp;
	}
	String operator + (const char object[])
	{
		String temp;
		temp.append(arr);
		temp.append(object);
		return temp;
	}
	bool operator ==(const String& other)
	{
		if (this->size_arr != other.size_arr)
		{
			return false;
		}

		for (int i = 0; i < this->size_arr; i++)
		{
			if (this->arr[i] != other.arr[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator !=(const String& other)
	{
		return !(this->operator==(other));
	}
	friend ostream& operator << (ostream& out, const String& object);
	friend istream& operator >> (istream& in, String& object);

	int length();

	void append(const String& object);
	void append(const char object[]);

	void reverse();

	void clear();
};

ostream& operator << (ostream& out, const String& object)
{
	out << object.arr;
	return out;
}
istream& operator >> (istream& in, String& object)
{
	delete[] object.arr;
	in >> object.arr;
	return in;
}