#include "function.h"

Function::Function()
{
    ifstream ifs;
    ifs.open("data.txt",ios::in);

    string buf,name,number,password;
    int count,isice;

    while(getline(ifs,buf)){
        istringstream istr(buf);
        istr >> name >> number >> password >> count >> isice;
        users.push_back(new Account(name,number,password,count,isice));
    }

}//初始化读取文件，将所有用户存入用户组

Function::~Function(){

}

Account* Function::Sign(string num){
    for(auto real:this->users){
        if(num==real->GetNumber()){
            return real;
        }
    }
    return NULL;
}//从用户中查找相应账号，若无此账户或此账户冻结则返回NULL，若有则返回该对象指针

int Function::InspectPass(Account* u,string pass){
    if(u->isice==0){
        if(u->GetPassword()==pass){
            return 1;
        }
        else{
            this->passwordNum++;
            if(passwordNum==5){
                u->isice=1;
                this->InIce(u->GetNumber());
            }
            return 0;
        }
    }
    else if(u->isice==1){
        return 2;
    }
}//相应密码错误则返回0，错误则密码输入次数加一，次数达到一定限度则冻结，并返回2，正确则返回1

void Function::InIce(string num){
    ifstream ifs;
    ofstream ofs;
    ifs.open("data.txt",ios::in);
    ofs.open("temp.txt",ios::out);

    string buf,name,number,password,count;
    int isice;

    while(getline(ifs,buf)){
        istringstream istr(buf);
        istr >> name >> number >> password >> count >> isice;
        if(number!=num){
            ofs << buf <<endl;
        }
        else{
            ofs << name << " " << number << " " << password << " " << count << " " << "1" << endl;
        }
    }

    ifs.close();
    ofs.close();

    remove("data.txt");
    rename("temp.txt","data.txt");

    return;
}//使相应用户isice改变为1，操作文件将文件中的内容更改

int Function::IfIce(string num){
    ifstream ifs;
    ifs.open("data.txt",ios::in);

    string buf,name,number,password;
    int isice,count;

    while(getline(ifs,buf)){
        istringstream istr(buf);
        istr >> name >> number >> password >> count >> isice;
        if(number==num){
            return isice;
        }
    }
    return 2;
}//账户冻结则返回1，未冻结则返回0，账号错误返回2

bool Function::TransCount(Account *a,string num,int count){
    if((a->GetCount())>=count){
        //扣除登录账户的余额
        a->OutCount(count);

        ifstream ifs;
        ofstream ofs;
        ifs.open("data.txt",ios::in);
        ofs.open("temp.txt",ios::out);//打开文件

        string buf,na,nu,p;
        int isice,c;

        while(getline(ifs,buf)){
            istringstream istr(buf);
            istr >> na >> nu >> p >> c >> isice;
            if(num!=nu){
                ofs << buf <<endl;
            }
            else{
                c+=count;
                ofs << na << " " << nu << " " << p << " " << c << " " << isice << endl;
            }
        }//逐行读取逐行更改

        ifs.close();
        ofs.close();

        remove("data.txt");
        rename("temp.txt","data.txt");

        return 1;
    }//账号存在且余额充足，扣除余额后打开文件并查找转入账户，增加其账户金额

    else{
        return 0;
    }//余额不足
}
