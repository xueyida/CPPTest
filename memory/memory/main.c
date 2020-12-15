#include <stdio.h>
#include <stdlib.h>

#define MemoryRow 4
#define MemoryCol 4



/* 
	主要用于模仿内存的工作机制
*/
struct MemoryStruct {
	int *memoryData;
	int *rowData;
	int returnData;
};

struct ControllerStruct{
	
	// 定位数据，并缓存在内部行缓存区
	void (*locationMemoryData)(int i, int j);

	// 定位好之后，从内存中取数据
	int (*getMemoryData)();


	// 添加数据
	void (*setMemoryData)(int i, int j, int value);


};


struct MemoryStruct myMemory;
struct ControllerStruct myController;



void locationMemoryData(int row, int col) {

	myMemory.rowData = malloc(sizeof(int) * MemoryCol);
	
	// 第一次请求数据 先获取第i行的所有数保存到缓存中

	for (int i = 0; i < MemoryCol;i++) {
		myMemory.rowData[i] = myMemory.memoryData[MemoryCol * row + i];
	}

	
	//第二次请求数据 把第j行的值保存到内存缓存中
	myMemory.returnData = myMemory.rowData[col];


}

int getMemoryData() {
	return myMemory.returnData;
}

void setMemoryData(int row, int col, int value) {
	
	myMemory.rowData = malloc(sizeof(int) * MemoryCol);

	// 还需清楚内存时如何设置值的
	

	//第二次请求数据 把第j行的值保存到内存缓存中
	myMemory.memoryData[MemoryCol * row + col] = value;
}



// 创建一个二维数组并进行初始化，这里对内存进行模仿；
void createMemoryData(int row, int col){


	int total = sizeof(int) * row * col;

	myMemory.memoryData = (int *)malloc(total);
	
	int count = 0;

	


	myMemory.memoryData = (int*)malloc(row * col * sizeof(int));   //申请内存空间
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			myMemory.memoryData[i * col + j] = count;
			count++;
		}
	}

}


int main() {

	//模拟内存数据
	createMemoryData(MemoryRow,MemoryCol);


	// 模拟控制器
	myController.locationMemoryData = locationMemoryData;
	myController.getMemoryData = getMemoryData;
	myController.setMemoryData = setMemoryData;
	

	myController.setMemoryData(0, 0, 100);

	myController.locationMemoryData(0, 0);
	

	int resData = myController.getMemoryData();

	printf("%d", resData);



	return 0;
}

