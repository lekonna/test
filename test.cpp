#include <iostream>
#include <cstddef>
#include <gtest/gtest.h>
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


TEST(FifoTest, normalQueueFloat) {
	fifo <float>fifo(6);
	fifo.queue(1);
	fifo.queue(2);
	fifo.queue(3);
	fifo.queue(4);
	fifo.queue(5);
	fifo.queue(6);
	ASSERT_EQ(1,fifo[0]);
	ASSERT_EQ(2,fifo[1]);
	ASSERT_EQ(3,fifo[2]);
	ASSERT_EQ(4,fifo[3]);
	ASSERT_EQ(5,fifo[4]);
	ASSERT_EQ(6,fifo[5]);
	ASSERT_EQ(1,fifo.dequeue());
	ASSERT_EQ(2,fifo[0]);

	fifo.queue(7);
	ASSERT_EQ(2,fifo[0]);
	ASSERT_EQ(7,fifo[5]);

}
TEST(FifoTest, normalQueueInt) {
	fifo <int>fifo(6);
	fifo.queue(1);
	fifo.queue(2);
	fifo.queue(3);
	fifo.queue(4);
	fifo.queue(5);
	fifo.queue(6);
	ASSERT_EQ(1,fifo[0]);
	ASSERT_EQ(2,fifo[1]);
	ASSERT_EQ(3,fifo[2]);
	ASSERT_EQ(4,fifo[3]);
	ASSERT_EQ(5,fifo[4]);
	ASSERT_EQ(6,fifo[5]);
	ASSERT_EQ(1,fifo.dequeue());
	ASSERT_EQ(2,fifo[0]);

	fifo.queue(7);
	ASSERT_EQ(2,fifo[0]);
	ASSERT_EQ(7,fifo[5]);

}

using namespace std;

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

