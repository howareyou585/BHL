#pragma once
#include <cstdint>
// 前向声明，不提供完整定义（模拟VkShaderModule_T的情况）
struct IncompleteType;

// 使用指针类型（模拟VkShaderModulePtr）
typedef IncompleteType* IncompleteTypePtr;

template <typename T>
class TestHandler
{
	public:
        void doSomething() {
            // 可以正常编译，因为不涉及T的细节
            value = 100;
        }

        uint64_t value;
	
};
