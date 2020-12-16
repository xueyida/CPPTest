#include <stdlib.h>
#include "memory.h"


// 创建一个二维数组并进行初始化，这里对内存进行模仿；
void createMemoryData(int row, int col, struct MemoryStruct* myMemory) {


	int total = sizeof(int) * row * col;

	myMemory->memoryData = (int*)malloc(total);

	int count = 0;




	myMemory->memoryData = (int*)malloc(row * col * sizeof(int));   //申请内存空间
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			myMemory->memoryData[i * col + j] = count;
			count++;
		}
	}

}