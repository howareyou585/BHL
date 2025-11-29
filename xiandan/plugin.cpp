#include "plugin.h"
#include "stable_header.h"
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
