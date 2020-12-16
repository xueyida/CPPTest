#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "controller.h"


struct MemoryStruct myMemory;


int main() {

	//模拟内存数据
	createMemoryData(MemoryRow,MemoryCol, &myMemory);


	myController.setMemoryData(0, 0, 100, &myMemory);
	myController.locationMemoryData(0, 0, &myMemory);

	int resData = myController.getMemoryData(&myMemory);

	printf("%d", resData);

	return 0;
}

