#pragma once
namespace PlaceNewDemo
{
	class MyClass
	{
	public:
		MyClass(int value);
		~MyClass();
		static void* operator new(size_t size, void* place);
		static void operator delete(void* ptr, void* place);
		static void* operator new(size_t size);
		static void operator delete(void* ptr);
	private:
		int m_data; // 用于存储整数的动态内存
	};
}