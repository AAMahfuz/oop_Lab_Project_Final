/** Project - 04 **/

#include <bits/stdc++.h>
using namespace std;
#define READ(f)         freopen(f, "r", stdin)
#define WRITE(f)        freopen(f, "w", stdout)

#define __              std::ios_base::sync_with_stdio(false); cin.tie(0);
#define ___             cerr << endl << "Execution Time : " << 1 * clock() / CLOCKS_PER_SEC << endl;
#define START           double start_s=clock();
#define STOP            double stop_s=clock();
#define _               cerr << "Time Elapsed : " << (stop_s-start_s)/double(CLOCKS_PER_SEC);

#define mem(x,y)        memset(x,y,sizeof(x))
#define DEBUG(x)        cout << #x << " = " << x << endl

#define TC(T)           int T;cin>>T;while(T--)
#define FTC(T)          int T;cin>>T;for(int TestCase=1;TestCase<=T;TestCase++)
#define CASE_OUT()      cout << "Case " << TestCase << ": ";
#define pf              cout <<
#define sc              cin >>

#define ERR             1e-9
#define pi              (2*acos(0))
#define PI              3.141592653589793
#define MOD             1000000009
#define el              cout << endl
#define bor             |
#define infinity        1e10

typedef long double LD;
typedef unsigned int UI;
typedef long long int LL;
typedef unsigned long long int ULL;
#define SS              stringstream
#define vi              vector<int>
#define vii             vector< vi >
#define pb              push_backh>
using namespace std;
#define dateOfBirth    dob


class Person
{
public:
    string name,dateOfBirth;
    Person() {};
    Person(string name,string dateOfBirth) {
        this->name=name; this->dateOfBirth=dateOfBirth;
    };

    void viewPerson() {
        pf "Name : "; pf this->name; el; pf "Birthday : "; pf this->dateOfBirth; el;
    }

};

class Department
{
public:
    string departmentName;
    Department() {};
    Department(string departmentName) {
        this->departmentName = departmentName;
    }
    void viewDepartment() {
        pf"Department : "; pf this->departmentName; el;
    }
};

class Student : public Person
{
public:
    int totalSolves,id;
    string typeOfCoder;
    Department department;

    Student() {};
    Student(string name,string dob,Department department,int id,int totalSolves,string typeOfCoder) : Person(name,dob) {
        this->id=id; this->department=department; this->totalSolves=totalSolves; this->typeOfCoder=typeOfCoder;
    }
    void view_student_info() {
        pf"Student name: ";pf this->name;el; department.viewDepartment();
        pf"Student ID: "; pf this->id ; el; pf"Students Birthday: "; pf this->dateOfBirth; el;pf"Students type: ";
        pf this->typeOfCoder; el; el;

    }
};

class Faculty : public Person
{
public:
    string designation;
    Department department;
    Faculty() {};
    Faculty(string designation,string name,string dob, Department department):Person(name,dob) {
        this->department=department; this->designation=designation;
    }
    view_faculty() {
        pf"Name: "; pf name; el; department.viewDepartment();
        pf"Designation: "; pf this->designation; el;
    }

};

int main()
{

    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // READ("input.txt");
    //WRITE("output.txt");

    Department *departments[5]= {
            new Department("CSE"), new Department("ICT"), new Department("MATHEMATICS"), new Department("MARKETING"), new Department("PHYSICS")
        };


    string TypeofCoder[] = {
        "Regular Contestent",
        "Not Regular" ,
        "WORLD FINALIST"
    };



    Student *students[5]= {
        new Student("Mahfuz Rahman","11-02-1997",*departments[0],11609021,247,TypeofCoder[0]),
        new Student("Anis Mahmood","25-23-1998",*departments[1],11707025,10,TypeofCoder[1]),
        new Student("Tamim Hasan","31-1-1997",*departments[0],11508011,547,TypeofCoder[2]),
        new Student("Asif Bin Muttaqin","13-5-1997",*departments[0],11608003,201,TypeofCoder[0]),
        new Student("Yasir Hamid","11-5-1997",*departments[4],11608016,0,TypeofCoder[1])
    };


    pf"INFORMATION OF APPLICANTS: "; el; el;
    for(int i=0; i<5; i++) {
        pf "Information of Students : "<< i+1 <<": "; el; students[i]->view_student_info(); el;el;
        pf"-----------------------------------------------------------------------"; el;
        pf"-----------------------------------------------------------------------"; el; el; el;
    }


    Faculty *faculty_member[3]= {
        new Faculty("Assistant Professor","Kamal Hossain Chowdhury","12-02-1982",*departments[0]),
        new Faculty("Assistant Professor","Mahmudul Hasan","23-02-1983",*departments[0]),
        new Faculty("Lecturer","Khairul Kabir","11-11-1989",*departments[3])
    };



    el; el;el;el;
     pf"-----------------------------------------------------------------------"; el;
    pf"-----------------------------------------------------------------------"; el; el; el;
    pf"INFORMATION OF FACULTY: "; el;el;
    for(int i=0; i<3; i++) {
        pf"INFO OF FACULTY "<<i+1<<": "; el;
        faculty_member[i]->view_faculty(); el;
    }
    pf"-----------------------------------------------------------------------"; el;
    pf"-----------------------------------------------------------------------"; el; el; el;


    pf"Problem setters & selected number of problems"; el; el; el; el;


    for(int i=0;i<5;i++) {
        if(students[i]->totalSolves<400 and students[i]->totalSolves>=200) {
            pf"No of Problems Selected : 1"; el; pf"Problem setter name : "<<students[i]->name; el;
        }
        else if(students[i]->totalSolves>=400 and students[i]->typeOfCoder=="WORLD FINALIST") {
            pf"No of Problems Selected : 2"; el; pf"Problem setter name : "<<students[i]->name; el;
        }
        el;
    }

    return 0;
}
