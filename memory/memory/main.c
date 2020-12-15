#include <stdio.h>
#include <stdlib.h>

#define MemoryRow 4
#define MemoryCol 4



/* 
	��Ҫ����ģ���ڴ�Ĺ�������
*/
struct MemoryStruct {
	int *memoryData;
	int *rowData;
	int returnData;
};

struct ControllerStruct{
	
	// ��λ���ݣ����������ڲ��л�����
	void (*locationMemoryData)(int i, int j);

	// ��λ��֮�󣬴��ڴ���ȡ����
	int (*getMemoryData)();


	// �������
	void (*setMemoryData)(int i, int j, int value);


};


struct MemoryStruct myMemory;
struct ControllerStruct myController;



void locationMemoryData(int row, int col) {

	myMemory.rowData = malloc(sizeof(int) * MemoryCol);
	
	// ��һ���������� �Ȼ�ȡ��i�е����������浽������

	for (int i = 0; i < MemoryCol;i++) {
		myMemory.rowData[i] = myMemory.memoryData[MemoryCol * row + i];
	}

	
	//�ڶ����������� �ѵ�j�е�ֵ���浽�ڴ滺����
	myMemory.returnData = myMemory.rowData[col];


}

int getMemoryData() {
	return myMemory.returnData;
}

void setMemoryData(int row, int col, int value) {
	
	myMemory.rowData = malloc(sizeof(int) * MemoryCol);

	// ��������ڴ�ʱ�������ֵ��
	

	//�ڶ����������� �ѵ�j�е�ֵ���浽�ڴ滺����
	myMemory.memoryData[MemoryCol * row + col] = value;
}



// ����һ����ά���鲢���г�ʼ����������ڴ����ģ�£�
void createMemoryData(int row, int col){


	int total = sizeof(int) * row * col;

	myMemory.memoryData = (int *)malloc(total);
	
	int count = 0;

	


	myMemory.memoryData = (int*)malloc(row * col * sizeof(int));   //�����ڴ�ռ�
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

	//ģ���ڴ�����
	createMemoryData(MemoryRow,MemoryCol);


	// ģ�������
	myController.locationMemoryData = locationMemoryData;
	myController.getMemoryData = getMemoryData;
	myController.setMemoryData = setMemoryData;
	

	myController.setMemoryData(0, 0, 100);

	myController.locationMemoryData(0, 0);
	

	int resData = myController.getMemoryData();

	printf("%d", resData);



	return 0;
}

