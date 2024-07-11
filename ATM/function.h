#ifndef FUNCTION_H
#define FUNCTION_H

#include "account.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace::std;

class Function
{
private:
    int passwordNum=0;//密码输入次数
    vector<Account*> users;//用户组
public:
    Function();//构造函数逐行读取文件，对用户组users进行初始化，将所有用户存入其中
    ~Function();
    Account* Sign(string num);//传入账号，从用户中查找相应账号，若无此账户或此账户冻结则返回NULL，若有则返回该对象指针
    int InspectPass(Account* u,string pass);
    //传入用户指针和密码，相应密码错误则返回0，错误则密码输入次数加一，次数达到一定限度则冻结，并返回2，正确则返回1
    void InIce(string num);//传入账号，使相应用户isice改变为1，操作文件将文件中的内容更改
    int IfIce(string num);//传入账号，账户冻结则返回1，未冻结则返回0，账号错误返回2
    bool TransCount(Account *a,string num,int count);//转账，将a中count元转入num账户中，若成功则返回1，余额不足返回0
};

#endif // FUNCTION_H
