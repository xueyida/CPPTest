#ifndef _STUDENT_MEMORY
#define _STUDENT_MEMORY


#define MemoryRow 4
#define MemoryCol 4


/*
	主要用于模仿内存的工作机制
*/
struct MemoryStruct {
	int* memoryData;
	int* rowData;
	int returnData;
};

#endif
