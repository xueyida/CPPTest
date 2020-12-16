#include "memory.h"
#ifndef _STUDENT_CONTROLLER
#define _STUDENT_CONTROLLER


// 内存控制器相关的工作了
struct ControllerStruct {

	// 定位数据，并缓存在内部行缓存区
	void (*locationMemoryData)(int i, int j);

	// 定位好之后，从内存中取数据
	int (*getMemoryData)();


	// 添加数据
	void (*setMemoryData)(int i, int j, int value);


};

void setMemoryData(int row, int col, int value, struct MemoryStruct* myMemory);

int getMemoryData(struct MemoryStruct* myMemory);


void locationMemoryData(int row, int col, struct MemoryStruct* myMemory);



struct ControllerStruct myController;

#endif



