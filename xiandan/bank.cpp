#include "bank.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 结构体实际定义 - 用户看不到这个！
struct BankAccountImpl {
    char accountNumber[20];
    double balance;
    char password[50];        // 敏感信息，对用户隐藏
    int loginAttempts;        // 内部状态，对用户隐藏
    time_t createTime;        // 内部信息，对用户隐藏
};

BankAccount bank_create(const char* accountNumber, double initialBalance) {
    struct BankAccountImpl* acc = (struct BankAccountImpl*)malloc(sizeof(struct BankAccountImpl));
    strncpy(acc->accountNumber, accountNumber, sizeof(acc->accountNumber) - 1);
    acc->balance = initialBalance;
    acc->loginAttempts = 0;
    acc->createTime = time(NULL);
    return (BankAccount)acc;
}

double bank_getBalance(BankAccount account) {
    struct BankAccountImpl* acc = (struct BankAccountImpl*)account;
    return acc->balance;
}

const char* bank_getAccountNumber(BankAccount account)
{
    struct BankAccountImpl* acc = (struct BankAccountImpl*)account;
    return acc->accountNumber;
}