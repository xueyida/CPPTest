### c++输入输出上

- 为什么学习c++?

    c++跟c对比？
    开发效率更快

   2. c++版本 
    
    https://isocpp.org  查看编辑器的兼容性

    https://zh.cppreference.com  语法标准


<!-- 34分钟开始 -->

- c++对c的提升

    类型敏感

    ```c++
    
        int n3 = {5.6} // 类型严格匹配



    ```

    类型占位符

    1. 注意跟js中的var的区别
    2. 可以根据复制推断类型
    3. decltype

    
    ```c++
        
        <!-- 类型推导 -->

        auto n0 = 3;  //3分配为int 类型

    
    ```


    空指针

        NULL
        nullptr


    范围迭代

        ```c++

            for(int val:ary){
                printf("%d", val);
            }
        
        ```



### c++输入输出下

<< 作用域运算符    自动识别类型；

using namespace


设置进制的两种写法：


    ```c++


    
    ```

- 浮点



    ```c++

        std::fixed<<13.6958<<endl; //定点
        std::scientific<<13.6958<<endl; //科学计数法


        // 精度

        cout.percision(3); //精度  对于定点，显示的是所有的位

    
    
    ```

- 对齐

    ```c++

        cout.width(40);

        cout<< std::right << "world" << endl;
    
    ```


- 输入

    不读取空格
    ```c++
        char szBuff[255] = { 0 };
	    int n = 0;

        cin >> szBuff ;
        int nCntAvil = cin.rdbuf()->in_avail();
	    cin.ignore(nCntAvil);
    
    ```

    读取部分空格
    ```c++
        char ary[255] = { 0 };

        cin.getline(ary, sizeof(ary));

        
	 
    
    ```






### 布尔/const

1. c语言使用布尔类型的方法

```c

typedef int BOOL;
#define TRUE 1
#define FALSE 0

int main(){
    BOOL bVal = TRUE;
    bVal = FALSE;
}



```

2. const

    - 作用：定义一个常量；

    - 为什么会出现：对c语言中的**无参宏**进行了改进

      

    - 场景： const 修饰指针 （34分钟）

        const type *p;    p指针本身可以修改；指向的内容不能修改
        
        type  const *p;    p指针本身可以修改；指向的内容不能修改

        type * const p; p指向内容可以修改，p本身不可以修改

    
        限制少的可以往限制多的转换，反之不行；

    -   无参宏与const的对比
        

        相同点：
        

        不同点：

        1. 无参宏没有类型检查
            ```c++
                #define i  10.0 
                #define i  10

                int j = 10;  
                std::cout << i / 3 << std::endl;  
                std::cout << j * 10 << std::endl;  


                int j = 10;  
                std::cout << i / 3 << std::endl;  
                std::cout << j * 10 << std::endl; 

                
                // const的用法
                const int i = 10;  
                int j = 10;  
                std::cout << i / 3 << std::endl;  
                std::cout << j * 10 << std::endl;  



            ```
        2. const在编译阶段被翻译；宏会在预编译阶段执行

        3. 宏在代码段中，const在数据段中

        4. 宏可以重复定义
        
            ```c++
                int main()    
                {    
                    #define MODI 10    
                    cout << MODI << endl;    
                    #undef MODI    
                    cout << MODI + 1 << endl;    
                    return 0;    
                }
            ```


### 引用


题外话：vs重命名的功能，右键有提示

基本使用

```c++
    
    int n1 = 2;
    int & n1Ref = n1;



```

替代c语言中的指针，解决指针的危害：空指针和野指针

- 引用必须初始化，所以可以避免空指针和野指针

- 引用没有多级引用

-   
    ```c++
    
    int n1 = 2;
    int & n1Ref = n1;

    int n2 = 3;

    n1Ref = n2;  // n1改为3；

    ```
-  不要返回局部变量的引用

    ```c++
        int& func(){
            int n=1;
            return n;
        }

        int& nRef1 = func(); //不要返回局部变量的引用


    ```

- 引用可以引用所有的数据类型，着重介绍了对指针的应用；

- 引用的本质：限制更多的指针；

- 引用与指针的区别


### 默认参

- 没有提供实参的话，会使用默认参

```c++

    void Say(const char * szUser,  const char * szCon = "你好"){

    }

```

- 题外话：函数的压栈顺序

- 声明文件如何 使用默认参： 默认参放到声明里面（59分钟处）





### 命名空间

- 解决的问题
    
     名字冲突

- 基本使用方式：

1. 定义命名空间（带有名字的作用域）
2. 使用命名空间


```c++

   
    namespace Test{
        int  a=1;
    }

     // 第一种方式
    int main(){
        {
            using namespace Test;
            a=2;
        }
        return 0;
    }


    // 第二张方式
    Test::a = 2;

    // 第三种方式
    using Test::a;
    a=2


```

- 复杂使用

1. namespace可以拆分

2. 取别名

```c++

    // 1
    namespace Test {
        int a=2;
    }

    namespace Test {
        int b=3;
    }

    // 2

    namespace Test1=Test;

```

### 函数重载

- 构成重载的条件：

0. 所有的重载函数的作用域需要相同
1. 参数（参数类型，参数数量，参数顺序）不同
2. 函数名相同
3. 不能用不同的调用约定，定义一个重载函数（调用约定不同，其余都相同的两个函数）
    调用的时候，没有办法制定调用约定
4. 不能用不同的返回值，定义一个重载函数（返回值不同，其余都相同的两个函数）
    调用函数的时候，可以不接受返回值，所以编译器对返回值类型，不考虑

```c++

    int Add(int n1, int n2){
        return n1+n1;
    }

    float Add(float n1, float n2){
        return n1+n2;
    }

    float Add(float n1, float n2, float n3){
        return n1+n2+n3;
    }

    // 调用约定

    int __stdcall Add(int n)
    {
        return 0;
    }

    int __cdecl Add(int n){
        return 0;
    }

```

- 函数重载原理：名称粉碎

    多余的方法：
    - 如何看一个函数粉碎后的名字

        1. 到obj文件找
        2. 只给一个函数的声明，不给实现，编译器文件会找到
    
    - 如何根据粉碎后的名字，查看函数的实现
        undname


    - windows里的cmd与vs2019的cmd的使用区别
        
        2019的cmd中有vs2019需要的环境变量，比如cl\undname

    - c的粉碎规则


- 如何在c++调用c的函数？

    // 告诉函数名称粉碎规则使用c，而不是c++

    注意事项： 使用extern "C" 无法使用函数重载

    ```c++

        extern "C" void Test();

        int main(){
            Test();
            return 0;
        }
    
    ```

    


- 重载使用注意事项

    1. 重载使用过程中，需要注意参数的完美匹配

        ```c++
            
            void Add(int a){

            }

            void Add(float a){

            }

            int main(){
                // 会报错 36.5是double
                Add(36.5);
            }
        
        ```
    

    2. 默认参对函数的调用也是有影响




### 内联


- 相似的功能：

短函数（函数准备的时间比函数体执行的时间要多）
    
    体积小  效率低  方便调试 

函数式宏定义（在每个地方使用的地方都会展开，展开的意思是，把函数体内的内容直接拿出来使用，不用去）

    体积大   效率高  不方便调试





- 内联产生的原因 

   既可以像短函数一样调试，也可以在调用点像宏一样展开

内联使用的注意事项：


1. debug版任何函数都不会展开；


2. 建议编译器内联，但是能不能内联成功，看编译器

    - 内联相关的编译选项：
    ob0:所有的函数都不内联
    ob1：有依赖的内联
    ob2：所有都尝试内联

3. 内联函数声明与实现不能拆开，建议内联函数定义与实现都放在头文件中

    放在头文件会不会重定义：

    内联函数被编译器变成文件作用域；包含内联函数的头文件， 被多个cpp调用，然后实现，不会出现重定义的问题



### 继承









