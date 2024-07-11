#include "account.h"
Account::Account(string my_name,string my_number,string my_password,int my_count,int my_isice)
{
    name = my_name;
    number = my_number;
    password = my_password;
    count = my_count;
    isice = my_isice;
}

Account::~Account()
{

}

string Account::GetName()
{
    return this->name;
}

string Account::GetNumber()
{
    return this->number;
}

string Account::GetPassword()
{
    return this->password;
}

int Account::GetCount()
{
    return this->count;
}

//输入需要存款的金额,返回值为0表示存款金额不为100的倍数 或者存款数目<=0  返回值为1表示成功  返回值2表示超过5000上限
int Account::InCount(int my_count)
{
    if(my_count % 100 != 0 || my_count <= 0)
    {
        return 0;
    }
    else if(my_count>5000)
        return 2;
    else
    {
        FileSaved(name,number,password,my_count+count,isice);
        return 1;
    }
}

//return 0表示取款不为整数 1表示成功 2表示余额超过最大值 3表示超过5000上限
int Account::OutCount(int my_count)
{
    if(my_count % 100 != 0 || my_count <=0)
    {
        return 0;
    }
    else if(my_count >5000)
        return 3;
    else if(this->count - my_count < 0)
    return 2;
     else{
        FileSaved(name,number,password,(count-my_count),isice);
        return 1;
    }
}

//修改密码
void Account::ChangePassword(string newpassword)
{
      FileSaved(name,number,newpassword,count,isice);
}

void Account::FileSaved(string newname,string newnumber,string newpassword,int newcount ,int newisice)
{
    ifstream ifs;
    ofstream ofs;
    ifs.open("data.txt",ios::in);
    ofs.open("temp.txt",ios::out);

    string buf,name,number,password;
    int count,isice;

    while(getline(ifs,buf)){
        istringstream istr(buf);
        istr >> name >> number >> password >> count >> isice;
        if(number!= this->number){
            ofs << buf <<endl;
        }
        else{
            this->name = newname;
            this->number= number;
            this->password = newpassword;
            this->count = newcount;
            this->isice = newisice;
            ofs << this->name << " " << this->number << " " << this->password << " " << this->count << " " << this->isice << endl;
        }
    }
    ifs.close();
    ofs.close();

    remove("data.txt");
    rename("temp.txt","data.txt");

    return;
}
