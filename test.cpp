#include <iostream>
#include <cstddef>
#include <gtest/gtest.h>
#include "fifo.h"

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


