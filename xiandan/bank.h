#pragma once
// bank.h - 给用户的头文件
// 只声明结构体存在，但不定义其内容！
// 操作接口
#ifdef __cplusplus
extern "C" {
#endif
	typedef struct BankAccountImpl* BankAccount;// 前向声明
	// 只提供操作接口
	BankAccount bank_create(const char* accountNumber, double initialBalance);
	double bank_getBalance(BankAccount account);
	const char* bank_getAccountNumber(BankAccount account);
#ifdef __cplusplus
	}
#endif