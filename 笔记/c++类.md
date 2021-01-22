### 类

1. 为什么会有class
    
    可以实现面向对象编程，面向对象包括封装，继承，多态；
    面向对象主要解决了复用的问题

2. class 与 struct

    实现封装的对比：

        struct实现的封装的与class封装的对比

    区别：

    - class默认属性是公有的，struct是私有的

    - struct没有public,private等

    内存结构
    - class 与 struct的内存布局是一样的

    - class访问权限控制是语法限制

    - cTest没有成员变量，使用一个字节占位

4. 成员函数指针

    ```c++

        typedef void(* PFN_SETX)(int nX);

        PFN_SETX pfnSetX = &CPlayer::Setx;  // 不能给到pfnSetX
        
        void *p = &CPlayer::Setx;  // 报错




        typedef void(CPlayer::* PFN_SETX)(int nX);

        PFN_SETX pfnSetX = &CPlayer::Setx;  // 正确


        player.*pfnSetX(9)  //成员函数变量指针调用，使用类对象

        CPlayer* p = &player;

        (p->*pfnSetX)(99);



    
    ```



5. 声明和定义分开

    声明写到头文件
    实现写到cpp文件

    属性写在声明的部分，函数写在声明的下部分；先公有，再私有

    public: 函数


    private： 函数

    public: 属性


    private： 




6. __thiscall
    调用传参约定

    类成员函数通过ecx传入this指针的调用约定叫做__thiscall

    调用约定可以改；




7. 类对象的共享问题

    类对象的成员属性是单独的

    类对象的成员函数是同一份，通过this确定哪个对象调用




8. 判断数据类型的方法

    把要判断的数据类型赋值给int类型，编译器会告诉我们

9. 判断是否是语法限制？
    使用强转判断


10. this存在寄存器中，无法取地址




### 构造和析构

不使用构造解析：

1. 在修改函数里面添加判断
2. 生成对象之后，马上给个初始化函数 


如果类没有初始化，函数是如何对类进行初始化的？


解决问题：class的初始化

构造：函数名和类名形同；无返回值；可以重载；
析构：函数名和类名形同，前面加~；无返回值；不可以重载；没有参数

- 构造和析构可以手动调用，不建议使用；


- 构造和析构的调用（举个例子）：

    在对象的生命周期开始时（生成对象时），调用构造
    
    在对象的生命周期结束时（return 0之之后，对象在栈中被清除之时），调用析构


- 调用构造时，两种传参方式

    ```c++
        
        CDataBuff buf0;
        CDataBuff buf1 = 8;
        CDataBuff buf2 ={ (char*)"hello", 5 };
        CDataBuff buf3{ (char*)"hello", 5 };
        CDataBuff buf4 ((char*)"hello", 5);
        CDataBuff buf5 (8);
        

    
    ```


- javascript也有构造函数，没有析构



### new delete

new 申请堆内存，并调用构造
delete 调用析构，并释放堆

解决问题：

    堆上分配的数据,不能自动调用构造 

使用方式：

    数组：
        CFoo *paryF = new CFoo[5]{{},{},{},{},{}} 
        delete[] paryF;

29分钟开始不常用：

    ```c++

        class CFoo2
        {
            CFoo2(){

            }
            int m_n;
        }

        int *pInt = new CFoo2[6];

    ```

    没有析构函数，对内存不会分配内存数的位置


### class的默认初始化

1. 普通变量函数体外，定义的变量初始成0，函数体内不进行自动初始化(包括数组)

2. class的初始话：

    - 无论在函数体内，还是体外

    - 首先调用构造函数初始化（也可以手动初始化）

    - 如果没有构造函数，编译器会调用默认构造函数


### 拷贝构造

解决问题：参数传对象，会有重复释放的问题

struct传参时，会把内存复制过去

拷贝构造的使用场景：

1. 对象传参

```c++

    class CDataBuff{

    }

    void Foo(CDataBuff buf)
    {
        cout <<buf.GetData()<<endl;
    }

    int main(){
        CDataBuff buf0((char*)"hello", 6);
        Foo(buf0);
        return 0;
    }

```




### 编程经验

实现类的时候，一定要实现默认构造、拷贝构造、=运算符重载


类成员函数返回局部对象会不会不安全？

返回对象时，会调用拷贝构造；临时的是销毁了，但是还是会生成一个新的临时对象



类成员函数返回对象引用

