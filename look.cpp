#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student{
    private:
    string ID;
    pair<string,string> name;
    vector<int> score;

    public:
    //初始化
    Student(string &Id,string &name1,string &name2,int &s1,int &s2,int &s3): ID(Id),name(name1,name2)
    {
        score.push_back(s1);
        score.push_back(s2);
        score.push_back(s3);

    }
    Student(){
        score.resize(3,0);
    }
    friend istream &operator>>(istream &in,Student &S);

        //获得新学生
    void get_a_new_student(vector<Student> &v){
        cin>>*this;
        int i=0;
        while(i<v.size()&&ID>v[i].ID){
            i++;
        }
        if(i==v.size())
        v.push_back(*this);
        else
        if(!(ID==v[i].ID)){
            v.insert(v.begin()+i,*this);

        }
    }


};
typedef void (Student::*function)(vector<Student>&);


//cin 重载
istream &operator>>(istream &in,Student &S){
    in>>S.ID>>S.score[0]>>S.score[1]>>S.score[2]>>S.name.first>>S.name.second;
    return in;
}
int main() {
    int select=-1;
    vector<Student> data;
    function f= &Student::get_a_new_student;
    /*function func[]= {NULL,
    &Student::get_a_new_student,
    &Student::modify,
    &Student::delete_student,
    &Student::find_ID,
    &Student::find_name,
    &Student::ID_out,
    &Student::Score_out,
    };*/
    Student S;
    (S.*f)(data);





}

