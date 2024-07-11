#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class Account
{
public:
    int isice;
    Account(string my_name,string my_number,string my_password,int my_count,int my_isice);
    ~Account();
    //用户获取用户的各种信息
    string GetName();
    string GetNumber();
    string GetPassword();
    int GetCount();
    int InCount(int my_count); //存款
    int OutCount(int my_count);//取款
    void ChangePassword(string newpassword);//修改密码

    private:
    string name;
    string number;
    string password;
    int count;
    void FileSaved(string newname,string newnumber,string newpassword,int newcount ,int newisice); // 文件保存操作

};

#endif // ACCOUNT_H
