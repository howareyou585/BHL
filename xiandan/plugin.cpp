#include "plugin.h"
#include "stable_header.h"
#include "usage_yield.h"
#include "usage_typeid.h"
#include "PlaceNewDemo.h"

//#include "utils/bubble_sort.h"
//#include "E:\github\BHL\xiandan\utils\bubble_sort.h"
//不透明指针
void excutePlugin01()
{
	// 创建一个银行账户
	// 用户只能通过接口操作
	BankAccount myAccount = bank_create("1234567890", 1000.0);
	printf("余额：%.2f\n", bank_getBalance(myAccount));
	printf("账号：%s\n", bank_getAccountNumber(myAccount));
	// 但这些都会导致编译错误！
	// printf("密码: %s\n", myAccount->password);           // 错误！
	// printf("账号: %s\n", myAccount->accountNumber);      // 错误！
	// myAccount->balance = 1000000;                       // 错误！
}
void excutePlugin02()
{
	// 显式实例化 TestHandler<IncompleteTypePtr>
	TestHandler<IncompleteTypePtr> handler;
	handler.doSomething();
	printf("Handler value: %llu\n", handler.value);
}

void excutePlugin03()
{
	std::thread proThread(UsageYield::producer);
	std::thread conThread(UsageYield::consumer);
	proThread.join();
	conThread.join();
}
void excutePlugin04()
{
	UsageTypeID::Base* obj = new UsageTypeID::Base();
	UsageTypeID::identifyType(obj);
	UsageTypeID::Base* objA = new UsageTypeID::DerivedA();
	UsageTypeID::identifyType(objA);
	UsageTypeID::Base* objB = new UsageTypeID::DerivedB();
	UsageTypeID::identifyType(objB);
}

void executePlugin05()
{
	//在栈上直接构造对象
	std::cout << "在栈上直接构造对象:" << std::endl;
	// 预先分配内存（这里使用栈上的内存，也可以使用其他来源的内存）
	alignas(PlaceNewDemo::MyClass) char buffer[sizeof(PlaceNewDemo::MyClass)];
	PlaceNewDemo::MyClass* obj = new(buffer) PlaceNewDemo::MyClass(42); // 在预分配的内存上构造对象
	//使用对象
	//....
	//必须显式调用析构函数
	obj->~MyClass();
	std::cout << "-----------------" << std::endl;
	alignas(PlaceNewDemo::MyClass) char buffer2[sizeof(PlaceNewDemo::MyClass)*5];
	PlaceNewDemo::MyClass* objs[5] = {};
	for (int i = 0; i < 5; i++)
	{
		objs[i] = new(buffer2 + i * sizeof(PlaceNewDemo::MyClass)) PlaceNewDemo::MyClass(i); // 在预分配的内存上构造对象
		
	}
	
	//析构对象必须是反序的
	std::cout << "-----------------" << std::endl;
	for (int i = 4; i >= 0; i--)
	{
		objs[i]->~MyClass();
	}
	//在堆上直接构造对象
	std::cout << "在堆上直接构造对象=》方法1" << std::endl;
	void* heapObj = ::operator new(sizeof(PlaceNewDemo::MyClass)); // 在堆上分配内存
	PlaceNewDemo::MyClass* tempObj = new (heapObj) PlaceNewDemo::MyClass(88); // 在已分配的堆内存上构造对象 
	tempObj->~MyClass(); // 显式调用析构函数销毁对象
	::operator delete(heapObj); // 释放堆内存

	std::cout << "在堆上直接构造对象=》方法2" << std::endl;
	PlaceNewDemo::MyClass* tempObj2 = new PlaceNewDemo::MyClass(99); // 使用普通new在堆上分配内存并构造对象
	delete tempObj2;
	tempObj2 = nullptr;
	
	std::cout << std::endl;
	std::cout << "-------验证全局::operator new 的作用：只分配内存，不构成对象----------" << std::endl;
	void* tempObj3 = ::operator new(sizeof(PlaceNewDemo::MyClass));
	::delete tempObj3;
}

void excutePlugin06()
{
	
	//int value;
	//obj._get_get()("value", value);
}



