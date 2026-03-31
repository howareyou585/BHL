#include "PlaceNewDemo.h"
#include <iostream>
using namespace std;

namespace PlaceNewDemo
{
	MyClass::MyClass(int value) :m_data(value)
	{
		std::cout << "Constructor called, data = " << m_data << std::endl;
	}
	MyClass::~MyClass()
	{
		std::cout << "Destructor called, data = " << m_data << std::endl;
	}

	 void* MyClass::operator new(size_t size, void* place)
	{
		std::cout << "Custom placement new called, size = " << size << std::endl;
		return place; // 返回预分配的内存地址
	}
	 void MyClass::operator delete(void* ptr, void* place)
	{
		std::cout << "Custom placement delete called" << std::endl;
		// 不需要释放内存，因为它是预分配的
	}
	 void* MyClass::operator new(size_t size)
	{
		std::cout << "Custom object_self new called, size = " << size << std::endl;
		return ::operator new(size); // 调用全局new分配内存
	}
	 void MyClass::operator delete(void* ptr)
	{
		std::cout << "Custom object_self delete called" << std::endl;
		::operator delete(ptr); // 调用全局delete释放内存
	}
}
