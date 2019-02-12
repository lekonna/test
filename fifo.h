#ifndef FIFO_H
#define FIFO_H

#include "fifo.h"
#include <iostream>
template <class T>
class fifo {
public:
	int queue( const T value );
	T dequeue();
	fifo<T>( int size  );
	~fifo<T>();
	void print_fifo();
	const T operator [] ( const int index );
private:
	fifo();
	T *_buffer;
	int _first;
	int _last;
	int _size;
	int _usage;
};
template <class T>
fifo<T>::fifo( int size )
{
	_buffer = new T[size];
	if (_buffer == NULL) {
		std::cout << "memory allocation failed\n";
	}
	_first = _last = _usage = 0;
	_size = size;
}
template <class T>
fifo<T>::~fifo()
{
	delete[] _buffer;
}
template <class T>
const T fifo<T>::operator [] (const int index) {

	if( index>=_usage ) return -1;
	return (_first + index >= _size ? _buffer[index - (_size - _first)] :
		 _buffer[_first + index]);
}
template <class T>
void fifo<T>::print_fifo()
{
	int current = _first;
	for (int i = 0; i < _size ; i++)
	{
		std::cout << _buffer[i] << "\n";
	}
}
template <class T>
int fifo<T>::queue( T value )
{
	if(_usage+1 > _size)
	{
		std::cout << "fifo full\n";
		return 0;
	}
	_usage++;
	_buffer[_last] = value;
	_last++;
	if(_last>=_size) _last=0;
	return 1;

}
template <class T>
T fifo<T>::dequeue()
{
	if(_usage==0) {
		std::cout << "no items to dequeue\n";
		return -1;
	}
	int value = _buffer[_first];
	_buffer[_first] = -1;
	_first++;
	_usage--;
	if(_first >= _size) _first=0;
	return value;
}
#endif