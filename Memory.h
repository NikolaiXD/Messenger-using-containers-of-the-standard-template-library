#pragma once
#include <iostream>

template<typename T>
class Memory
{
private:
	int size;
	T* data;
	int i;
public:
	Memory() : size(1), data(new T[size]), i(0) {}
	~Memory() { delete[] data; }

	void AddSms(const T& value)
	{
		if (i < size)
		{
			data[i] = value;
			++i;
		}
		else
		{
			int newSize = size * 2;
			T* newData = new T[newSize];
			for (int j = 0; j < size; j++)
			{
				newData[j] = data[j];
			}
		}
		newData[i] = value;
		++i;
		delete[] data;
		data = newData;
		size = newSize;
	}
	Void Display()
	{
		for (int f = 0; f < i; f++)
		{
			cout << "В чате есть сообщение! Кому: " << data[i].getRecepient() << ". От кого: " << data[f].getSend() << std;
			std::cout << "Сообщение: " << "'" << data[f].getText() << "'" << std::endl;
		}
	}
};