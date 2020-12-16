#include <stdlib.h>
#include "memory.h"
#include "controller.h"


void locationMemoryData(int row, int col, struct MemoryStruct* myMemory) {

	myMemory->rowData = malloc(sizeof(int) * MemoryCol);

	// 第一次请求数据 先获取第i行的所有数保存到缓存中

	for (int i = 0; i < MemoryCol; i++) {
		myMemory->rowData[i] = myMemory->memoryData[MemoryCol * row + i];
	}


	//第二次请求数据 把第j行的值保存到内存缓存中
	myMemory->returnData = myMemory->rowData[col];

}

int getMemoryData(struct MemoryStruct* myMemory) {
	return myMemory->returnData;
}

void setMemoryData(int row, int col, int value, struct MemoryStruct* myMemory) {

	myMemory->rowData = malloc(sizeof(int) * MemoryCol);

	// 还需清楚内存时如何设置值的


	//第二次请求数据 把第j行的值保存到内存缓存中
	myMemory->memoryData[MemoryCol * row + col] = value;
}



struct ControllerStruct myController = {
	.locationMemoryData = locationMemoryData,
	.getMemoryData = getMemoryData,
	.setMemoryData = setMemoryData
};

