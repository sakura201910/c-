/*
已知某学校的请假审批是分级进行的，即根据请假天数的不同由不同层次的教管人员来审批，
班主任可以审批10天以下（不包括10天）的请假条，学院可以审批10天至20天（不包括20天）的请假单，
教务处可以审批20天至50天（不包括50天）的请假条，
50天及以上的请假条就需要校办讨论决定。
*/
#include<bits/stdc++.h>
using namespace std;
int n;
class Approver{//父类型
protected:
    int day;
public:
    void SetDay(int day){
        this->day=day;
    }
    virtual int ProcessRequest()=0;
};

class SchoolOffice:public Approver{
public:
    int ProcessRequest(){
        cout<<"校办审批了该假条"<<endl;
    }
};

class SchoolDean:public Approver{
public:
    SchoolOffice* p;
    int ProcessRequest(){
        if(day<50){
            cout<<"教务处审批了该假条"<<endl;
        }
        else{
            p=new SchoolOffice();
            p->SetDay(n);
            p->ProcessRequest();
        }
    }
};

class Dean:public Approver{
public:
    SchoolDean* p;
    int ProcessRequest(){
        if(day<20){
            cout<<"院领导审批了该假条"<<endl;
        }
        else{
            p=new SchoolDean();
            p->SetDay(n);
            p->ProcessRequest();
        }
    }
};

class ChargerTeacher:public Approver{
public:
    Dean* p;
    int ProcessRequest(){
        if(day<10){
            cout<<"班主任审批了该假条"<<endl;
        }
        else{
            p=new Dean();
            p->SetDay(n);
            p->ProcessRequest();
        }
    }
};

int main() {
    cin>>n;
    Approver* opr;
    opr=new ChargerTeacher();
    opr->SetDay(n);
    opr->ProcessRequest();
    return 0;
}
