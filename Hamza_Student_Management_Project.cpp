#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class subject
{
    public :
    double sub_assignments,sub_quizez,sub_labs,sub_projects;
};
class Student
{
    public:
    string student_user_name,student_passwords,student_name,student_department;
    int student_batch,student_warning_count,student_roll_num,student_semester;
    string student_phone;
    char attandence[40];
};
class faculty
{
public:
    string faculty_user_name,faculty_login_passwords,faculty_name,cp_sub,en_sub,dld_sub,cp_grade,en_grade,dld_grade;

};
class Admin: public Student,public faculty,public subject
{
public:
    string admin_username,admin_password;
public:
    Admin()
    {
        admin_username = " ";
        admin_password = " ";
        student_name = " ";
        student_passwords= " ";
        student_user_name= " ";
    }

    void setinfo_admin(string u,string p)
    {
        admin_username = u;
        admin_password = p;
    }
    void display_admin_info()
    {
        cout<<"The admin details are:"<<endl;
        cout<<"Username : "<<admin_username<<endl;
        cout<<"Password : "<<admin_password<<endl;
    }


};
void display(int caution_students,int caution_teachers)
{
    if (caution_students==0 && caution_teachers==0)
        {
            cout<<"Menu."<<endl;
            cout<<"1.Signup student"<<endl;
            cout<<"2.Signup faculty"<<endl;
            cout<<"3.Exit"<<endl;
        }
    else if (caution_students==1 && caution_teachers==0)
    {
        cout<<"Menu."<<endl;
        cout<<"2.Signup faculty"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"4.update students password"<<endl;
        cout<<"8.view single student record: "<<endl;
        cout<<"9.View all students records "<<endl;

    }
    else if (caution_students==0 &&caution_teachers==1)
    {
        cout<<"Menu."<<endl;
        cout<<"1.Signup student"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"5.update teachers password"<<endl;
        cout<<"6.Assingn subject to the teacher"<<endl;
        cout<<"7.Remove subject access for a teacher:"<<endl;


    }
    else if (caution_students==1 && caution_teachers==1)
    {
        cout<<"Menu."<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"4.update students password"<<endl;
        cout<<"5.update teachers password"<<endl;
        cout<<"6.Assingn subject to the teacher"<<endl;
        cout<<"7.Remove subject access for a teacher:"<<endl;
        cout<<"8.View single student's record:"<<endl;
        cout<<"9.View all students records "<<endl;

    }
}
void check_input(int a,int &choice_login,int caution_students,int caution_teachers)
{
    if (caution_students==0 && caution_teachers==0)
    {
        while(a>0 )
        {

            if (choice_login <1 || choice_login>3)
            {
                cout<<"Invalid choice! please enter correct option"<<endl;
                cin>>choice_login;
                cin.clear();
                cin.ignore(100,'\n');
            }
            else{
                a=0;
            }

        }
    }
     else if (caution_students==0 && caution_teachers==1)
     {
         while(a>0 )
        {

            if (choice_login !=1 && choice_login != 3 && choice_login != 6 && choice_login!=7)
            {
                cout<<"Invalid choice! please enter correct option"<<endl;
                cin>>choice_login;
                cin.clear();
                cin.ignore(100,'\n');
            }
            else{
                a=0;
            }

        }
     }
     else if (caution_students==1 && caution_teachers==0 )
     {
         while(a>0 )
        {
            if (choice_login !=2 && choice_login != 3 && choice_login!=8 && choice_login!=9)
            {
                cout<<"Invalid choice! please enter correct option"<<endl;
                cin>>choice_login;
                cin.clear();
                cin.ignore(100,'\n');
            }
            else{
                a=0;
            }

        }
     }
     else if (caution_students==1 && caution_teachers==1)
     {
         while (a>0)
         {
             if (choice_login != 3 && choice_login!=4 && choice_login!=5 && choice_login!=6 && choice_login!=7 && choice_login!=8 && choice_login!=9)
             {
                cout<<"Invalid choice! please enter correct option"<<endl;
                cin>>choice_login;
                cin.clear();
                cin.ignore(100,'\n');
             }
             else
             {
                 a=0;
             }
         }
     }

}
void input_choice(int &choice_login)
{
    cout<<"Enter the choice"<<endl;
    cin>>choice_login;
    cin.clear();
    cin.ignore(100,'\n');
}
int main()
{
    Admin admin;
    int temp_cp = -1;
    int temp_en = -1;
    int temp_dld = -1;
    int max_students=0;
    int max_teachers=0;
    int caution_students=0;
    int caution_teachers = 0;
    int b=1;
    string u,p;
    cout<<"\t \t \t *****Welcome to the Neon database*****"<<endl<<endl;
    cout<<"\a";
    cout<<"Enter the admin user name and password:"<<endl;
    cout<<"Enter the username: ";
    getline(cin,u);
    cout<<"\a";
    cin.ignore();
    cout<<"Enter the password: ";
    getline(cin,p);
    cout<<"\a";
    cin.ignore();
    system("CLS");
    admin.setinfo_admin(u,p);
    cout<<"Successfully signed up as admin now please enter the number of maximum students and teachers which can be stored in the neon database: "<<endl;
    cout<<"Enter max students: ";
    cin>>max_students;
    cout<<"\a";
    cout<<"Enter max teachers: ";
    cin>>max_teachers;
    cout<<"\a";
    system("CLS");
    Admin info[max_students];
    Admin data[max_teachers];
    int a = 1;
    int choice_signup;
    int count =0;
    cout<<"Admin successfully signed up"<<endl<<endl;
    cout<<"Admin Login for assigning passwords and usernames to student and faculty "<<endl<<endl;
    while (a!=0) // admin module
    {
            cout<<"Enter the username: ";
            cin.ignore();
            getline(cin,u);
            cout<<"\a";
            cin.ignore();
            cout<<"Enter the password: ";
            getline(cin,p);
            cout<<"\a";
            if (u==admin.admin_username && p==admin.admin_password)
            {
                cout<<"Logged in successfully!"<<endl;
                a=0;

            }
            else
            {
                cout<<"Wrong username or password if you want to exit press 0!"<<endl;
                cin>>a;
            }
    }
    a=1;
    int roll = 0;
    while ((a==1 && caution_students==0 && caution_teachers==0) || (a==1 && caution_students>0 && caution_teachers==0) || (a==1 && caution_students==0 && caution_teachers>0) || (a==1 && caution_students>0 && caution_teachers>0))
    {
        display(caution_students,caution_teachers);
        input_choice(choice_signup);
        cout<<"\a";
        system ("CLS");
        check_input(a,choice_signup,caution_students,caution_teachers);
        switch(choice_signup)
        {
            case 1 :    for (int i=0;i<max_students;i++)
                        {
                            cout<<"Enter the username for student "<<i+1<<" ";
                            getline(cin,info[i].student_user_name);
                            cout<<"\a";
                            cin.ignore();
                            cout<<"Enter the password for student "<<i+1<<" ";
                            getline(cin,info[i].student_passwords);
                            cout<<"\a";
                            cout<<"Enter the name for student "<<i+1<<" ";
                            getline(cin,info[i].student_name);
                            cout<<"\a";
                            cin.ignore();
                            cout<<"Enter the phone for student  "<<i+1<<" ";
                            getline(cin,info[i].student_phone);
                            cin.ignore();
                            cout<<"Enter the degree name for student  "<<i+1<<" ";
                            getline(cin,info[i].student_department);
                            cin.ignore();
                            while(b=1)
                            {
                                if (info[i].student_department!="cs" && info[i].student_department!="ee" && info[i].student_department!="bba" && info[i].student_department!="af")
                               {
                                    cout<<"Invalid department name ! Again  Enter the degree name for student "<<i+1<<" ";
                                    getline(cin,info[i].student_department);
                                    cin.ignore();
                                }
                                else
                                {
                                    break;
                                }
                            }
                            cout<<"Enter the batch for student  "<<i+1<<" ";
                            cin>>info[i].student_batch;
                            cout<<"Enter the roll number of the student "<<i+1<<" ";
                            cin>>info[i].student_roll_num;
                            cout<<"Enter the semester number of the student "<<i+1<<" ";
                            cin>>info[i].student_semester;
                            info[i].student_warning_count=0;
                        }
                        caution_students++;
                            break;
            case 2:      for (int i=0;i<max_teachers;i++)
                        {
                             cout<<"Enter the username for faculty member "<<i+1<<" ";
                            getline(cin,data[i].faculty_user_name);
                            cout<<"\a";
                            cin.ignore();
                            cout<<"Enter the password for faculty member "<<i+1<<" ";
                            getline(cin,data[i].faculty_login_passwords);
                            cout<<"\a";
                            cout<<"Enter the name for faculty member "<<i+1<<" ";
                            getline(cin,data[i].faculty_name);
                            cout<<"\a";
                            cin.ignore();
                        }caution_teachers++;
                        break;
            case 3 : cout<<"Exiting this menu now!"<<endl;a=0;break;
            case 4 : cout<<"Enter the student's username whose password you want to reset:";
                    count=0;
                     getline(cin,u);
                     for (int i=0;i<max_students;i++)
                     {
                         if (u==info[i].student_user_name)
                         {
                             count++;
                             cout<<"Admin now you can reset the password!"<<endl;
                            cin.ignore();

                             cout<<"Enter the new password: ";
                             getline(cin,info[i].student_passwords);
                         }
                     }
                     if (count==0)
                     {
                         cout<<"no such username found in the database!"<<endl;
                     }
                     break;
            case 5 :
                     cout<<"Enter the Teachers 's username whose password you want to reset:";
                     count=0;
                     getline(cin,u);
                     for (int i=0;i<max_teachers;i++)
                     {
                         if (u==data[i].faculty_user_name)
                         {
                             count++;
                             cout<<"Admin now you can reset the password!"<<endl;
                             cin.ignore();
                             cout<<"Enter the new password: ";
                             getline(cin,data[i].faculty_login_passwords);
                         }
                     }
                     if (count==0)
                     {
                         cout<<"no such username found in the database!"<<endl;
                     }
                     break;
        case 6 : cout<<"The available subjects which can be assigned are dld,cp and english!"<<endl;
                 cout<<"Enter the name of the teacher whom you want to assign a subject:";
                 count=0;
                 getline(cin,u);
                 cout<<u<<endl;
                 for (int i=0;i<max_teachers;i++)
                 {
                     if (u==data[i].faculty_user_name)
                     {
                         count++;
                         cout<<"Enter the subject name which you want to assign this teacher: ";
                         getline(cin,u);
                         if (u=="english")
                         {

                            data[i].en_sub = "english";
                             cout<<"English assigned"<<endl;
                         }
                         else if (u=="cp")
                         {
                             data[i].cp_sub = "cp";
                             cout<<"Cp assigned"<<endl;
                         }
                         else if (u=="dld")
                         {
                             data[i].dld_sub="dld";
                             cout<<"dld assigned"<<endl;
                         }
                         else
                         {
                             cout<<"No such subject found!"<<endl;
                         }

                     }
                 }
                 if (count==0)
                 {cout<<"No teacher with such name exists"<<endl;}break;
        case 7: cout<<"Enter the username of the teacher whose subject access you wan to remove: ";
        getline(cin,u);
        count=0;
        for (int i=0;i<max_teachers;i++)
        {
            if (u==data[i].faculty_user_name)
            {
                count++;
                if (data[i].en_sub !=" ")
                {
                    cout<<"Access removed"<<endl;
                    data[i].en_sub = "subject removed";
                }
                else if (data[i].cp_sub !=" ")
                {
                    cout<<"Access removed"<<endl;
                    data[i].cp_sub = "subject removed";
                }
                else if (data[i].dld_sub !=" ")
                {
                    cout<<"Access removed"<<endl;
                    data[i].dld_sub = "subject removed";
                }
            }

        }
        if (count==0)
        {
            cout<<"No username matched"<<endl;
        }
        break;
    case 8: cout<<"Enter the roll number of the student whose record you want to search: ";
            cin>>roll;
            count =0;
            for (int i=0;i<max_students;i++)
            {
                    if (roll==info[i].student_roll_num)
                    {
                        count++;
                        cout<<"The name of the student is: "<<info[i].student_name<<endl;
                        cout<<"The batch of the student is: "<<info[i].student_batch<<endl;
                        cout<<"The department of the student is: "<<info[i].student_department<<endl;
                        cout<<"The phone number of of the student is: "<<info[i].student_phone<<endl;
                        cout<<"The warning count of the student is: "<<info[i].student_warning_count<<endl;

                    }
            }
            if (count==0)
            {
                cout<<"Invalid roll number entered!"<<endl;
            }break;
        case 9: for (int i=0;i<max_students;i++)
                {
                    cout<<"The student "<<i+1<<" "<<"has following details:"<<endl;
                    cout<<"The Roll number of student is "<<info[i].student_roll_num<<endl;
                    cout<<"The name of the student is: "<<info[i].student_name<<endl;
                    cout<<"The batch of the student is: "<<info[i].student_batch<<endl;
                    cout<<"The department of the student is: "<<info[i].student_department<<endl;
                    cout<<"The phone number of of the student is: "<<info[i].student_phone<<endl;
                    cout<<"The warning count of the student is: "<<info[i].student_warning_count<<endl;
                    cout<<"The semester of the student is: "<<info[i].student_semester<<endl;

                }break;
        }
    }
    int choice_login;
    int total_subject_marks=0;
    cout<<"Menu:"<<endl;
    cout<<"1.Login as Student: "<<endl;
    cout<<"2.Login as faculty: "<<endl;
    cout<<"Enter the choice:";
    cin>>choice_login;
    system("CLS");
    cout<<"\a";
    int student_menu_choice,total_marks;
    int count_marks=0;
    char stat;
    total_marks = 100;
    int assignment_wattage;
    int temp;
    int teacher_menu_marks;
    if (choice_login==1) // student module
    {

        count =0;
        a=1;
        while(a!=0)
        {
            cout<<"Enter the username and password:"<<endl;
            cout<<"Enter the username: ";
            cin.ignore();
            getline(cin,u);
            cout<<"\a";
            cin.ignore();
            cout<<"Enter the password: ";
            getline(cin,p);
            cout<<"\a";
            system("CLS");
            count=0;
            for (int i=0;i<max_students;i++)
            {
                if (u==info[i].student_user_name  && p==info[i].student_passwords)
                {
                    cout<<"student Successfully logged in!"<<endl;
                    temp = i;
                    count++;
                    break;
                }

            }
            if (count>0)
            {
                cout<<"Student Menu:"<<endl;
                cout<<"1.Change password:"<<endl;
                cout<<"Enter your choice : ";
                cin>>student_menu_choice;
                if (student_menu_choice==1)
                {
                    cin.ignore();
                    cout<<"Enter the new password!"<<endl;
                    getline(cin,info[temp].student_passwords);
                    cout<<"password updated!"<<endl;
                }
            }
            else if (count==0)
            {
                cout<<"No such account exists! If you want to logout press 0 else press something else"<<endl;
                cin>>a;
            }
        }
    }
    else if (choice_login==2)
    {
        count =0;
        a=1;
        while(a!=0)
        {
            if (student_menu_choice==4)
            {
                break;
            }
            cout<<"Enter the username and password:"<<endl;
            cout<<"Enter the username: ";
            cin.ignore();
            getline(cin,u);
            cout<<"\a";
            cin.ignore();
            cout<<"Enter the password: ";
            getline(cin,p);
            cout<<"\a";
            system("CLS");
            count=0;
            for (int i=0;i<max_teachers;i++)
            {
                if (u==data[i].faculty_user_name  && p==data[i].faculty_login_passwords)
                {
                    cout<<"Teacher Successfully logged in!"<<endl;
                    total_marks=100;
                    temp = i;
                    count++;
                    break;
                }

            }
            if (count>0)
            {
                while (true)
                {
                    if (total_marks==0)
                    {
                        break;
                    }
                    cout<<"Student Menu:"<<endl;
                    cout<<"1.Change password:"<<endl;
                    cout<<"2.subject marks:"<<endl;
                    cout<<"3.Calculate grade: "<<endl;
                    cout<<"4.Exit"<<endl;
                    cout<<"5.Attendance menu"<<endl;
                    cout<<"6.view attandence of a student"<<endl;
                    cout<<"Enter your choice : ";
                    cin>>student_menu_choice;
                    if (student_menu_choice==1)
                    {
                        cin.ignore();
                        cout<<"Enter the new password!"<<endl;
                        getline(cin,data[temp].faculty_login_passwords);
                        cout<<"password updated!"<<endl;
                    }
                    else if (student_menu_choice==2)
                    {
                        cin.ignore();
                        cout<<"Enter the subject name for which you want to upload marks : ";
                        getline(cin,u);
                        if ((u==data[temp].cp_sub || u==data[temp].en_sub || u==data[temp].dld_sub )&& (data[temp].cp_sub!="subject removed" || data[temp].en_sub!="subject removed" || data[temp].en_sub!="subject removed"))
                        {
                            cout<<"Welcome to the menu for uploading "<<" marks"<<endl;
                            cout<<"Menu:"<<endl;
                            cout<<"1.Assignment marks"<<endl;
                            cout<<"2.quizez marks"<<endl;
                            cout<<"3.lab marks"<<endl;
                            cout<<"4.project marks"<<endl;
                            cout<<"Enter the option"<<endl;
                            cin>>teacher_menu_marks;
                            if(teacher_menu_marks==1)
                            {
                                cout<<"Enter the total marks of the assignment: ";
                                cin>>assignment_wattage;
                                total_marks -= assignment_wattage;
                                cout<<"Enter the obtained marks: ";
                                cin>>data[temp].sub_assignments;
                                if (data[temp].sub_assignments>assignment_wattage || total_marks <0)
                                {
                                    cout<<"invalid obtained marks exceed the total marks"<<endl;
                                }
                                else
                                {
                                    total_subject_marks += data[temp].sub_assignments;
                                    count_marks++;
                                }
                            }
                            else if (teacher_menu_marks==2)
                            {
                                cout<<"Enter the total marks of the quiz: ";
                                cin>>assignment_wattage;
                                total_marks -= assignment_wattage;
                                cout<<"Enter the obtained marks: ";
                                cin>>data[temp].sub_quizez;
                                if (data[temp].sub_quizez>assignment_wattage || total_marks <0)
                                {
                                    cout<<"invalid obtanied marks exceed the total marks or marks distribution error"<<endl;
                                }
                                else
                                {
                                    total_subject_marks += data[temp].sub_quizez;
                                    count_marks++;
                                }
                            }
                            else if (teacher_menu_marks==3)
                            {
                                cout<<"Enter the total marks of the lab: ";
                                cin>>assignment_wattage;
                                total_marks -= assignment_wattage;
                                cout<<"Enter the obtained marks: ";
                                cin>>data[temp].sub_labs;
                                if (data[temp].sub_labs>assignment_wattage || total_marks <0)
                                {
                                    cout<<"invalid obtanied marks exceed the total marks or marks distribution error"<<endl;
                                }
                                else
                                {
                                    total_subject_marks += data[temp].sub_labs;
                                    count_marks++;
                                }
                            }
                            else if (teacher_menu_marks==4)
                            {
                                cout<<"Enter the total marks of the project: ";
                                cin>>assignment_wattage;
                                total_marks -= assignment_wattage;
                                cout<<"Enter the obtained marks: ";
                                cin>>data[temp].sub_projects;
                                if (data[temp].sub_projects>assignment_wattage || total_marks <0)
                                {
                                    cout<<"invalid obtanied marks exceed the total marks or marks distribution error"<<endl;
                                }
                                else
                                {
                                    total_subject_marks += data[temp].sub_projects;
                                    count_marks++;
                                }
                            }
                            else
                            {
                                cout<<"invalid option!"<<endl;
                            }
                        }

                    }

                    if (student_menu_choice==3 && count_marks>0 && total_marks==100)
                    {
                        cin.ignore();
                        cout<<"Enter the name of the subject you want to calculate the grade for! "<<endl;
                        getline(cin,u);
                        if (u==data[temp].en_sub ||u==data[temp].cp_sub||  u==data[temp].dld_sub )
                        {
                            if (total_subject_marks>=0 && total_subject_marks<20)
                            {
                                if (u=="dld")
                                {
                                    data[temp].dld_grade = "F";
                                }
                                else if (u=="cp")
                                {
                                    data[temp].cp_grade="F";
                                }
                                else if (u=="english")
                                {
                                    data[temp].en_grade="F";
                                }
                            }
                            else if (total_subject_marks>=20 && total_subject_marks<40)
                            {
                                 if (u=="dld")
                                {
                                    data[temp].dld_grade = "D+";
                                }
                                else if (u=="cp")
                                {
                                    data[temp].cp_grade="D+";
                                }
                                else if (u=="english")
                                {
                                    data[temp].en_grade="D+";
                                }
                            }
                            else if (total_subject_marks>=40 && total_subject_marks<60)
                            {
                                 if (u=="dld")
                                {
                                    data[temp].dld_grade = "C+";
                                }
                                else if (u=="cp")
                                {
                                    data[temp].cp_grade="C+";
                                }
                                else if (u=="english")
                                {
                                    data[temp].en_grade="C+";
                                }
                            }
                            else if (total_subject_marks>=60 && total_subject_marks<80)
                            {
                                 if (u=="dld")
                                {
                                    data[temp].dld_grade = "B+";
                                }
                                else if (u=="cp")
                                {
                                    data[temp].cp_grade="B+";
                                }
                                else if (u=="english")
                                {
                                    data[temp].en_grade="B+";
                                }
                            }
                            else if (total_subject_marks>=80 && total_subject_marks<=100)
                            {
                                 if (u=="dld")
                                {
                                    data[temp].dld_grade = "A+";
                                }
                                else if (u=="cp")
                                {
                                    data[temp].cp_grade="A+";
                                }
                                else if (u=="english")
                                {
                                    data[temp].en_grade="A+";
                                }
                            }
                        }
                        else
                        {
                            cout<<"No such subject exists!"<<endl;
                        }
                    }
                    if (student_menu_choice==4)
                    {
                        break;
                    }
                    if (student_menu_choice==5)
                    {
                        count=0;
                        cout<<"Enter the subject name: ";
                        cin>>u;
                        cout<<"Enter the roll number of the student whose attendance you want to upload :";
                        cin>>roll;
                        for (int i=0;i<max_students;i++)
                        {
                            if (roll==info[i].student_roll_num && u==data[i].cp_sub )
                            {
                                count++;
                                cout<<"Enter P for present and a for absent"<<endl;
                                cin>>stat;

                                while(1)
                                {
                                    if (stat!= 'p' && stat != 'a')
                                    {
                                        cout<<"invalid character"<<endl;
                                        cin>>stat;
                                    }
                                    else if (stat== 'p' || stat == 'a')
                                    {
                                        break;
                                    }
                                }
                                temp_cp++;
                                info[i].attandence[temp_cp] = stat;
                                break;
                            }
                            if (roll==info[i].student_roll_num && u==data[i].en_sub )
                            {
                                count++;
                                cout<<"Enter P for present and a for absent"<<endl;
                                cin>>stat;

                                while(1)
                                {
                                    if (stat!= 'p' && stat != 'a')
                                    {
                                        cout<<"invalid character"<<endl;
                                        cin>>stat;
                                    }
                                    else if (stat== 'p' || stat == 'a')
                                    {
                                        break;
                                    }
                                }
                                temp_en++;
                                info[i].attandence[temp_en] = stat;
                                break;
                            }
                            if (roll==info[i].student_roll_num && u==data[i].dld_sub )
                            {
                                count++;
                                cout<<"Enter P for present and a for absent"<<endl;
                                cin>>stat;

                                while(1)
                                {
                                    if (stat!= 'p' && stat != 'a')
                                    {
                                        cout<<"invalid character"<<endl;
                                        cin>>stat;
                                    }
                                    else if (stat== 'p' || stat == 'a')
                                    {
                                        break;
                                    }
                                }
                                temp_dld++;
                                info[i].attandence[temp_dld] = stat;
                                break;
                            }

                        }
                        if (count==0)
                        {
                            cout<<"No such rollnumber or subject found!"<<endl;
                        }
                    }
                    if (student_menu_choice==6)
                    {
                        count =0;
                        cout<<"Enter the roll number of the student : ";
                        cin>>roll;
                        cout<<"Enter the subject name: ";
                        cin>>u;
                        system("CLS");
                        for (int i=0;i<max_students;i++)
                        {
                            if (roll==info[i].student_roll_num && u==data[i].cp_sub)
                            {
                                count++;
                                cout<<"The attandence is: "<<endl;
                                for (int j=0;j<temp_cp+1;j++)
                                {
                                    cout<<info[i].attandence[j]<<",";
                                }
                                cout<<endl;
                            }
                            if (roll==info[i].student_roll_num && u==data[i].en_sub)
                            {
                                count++;
                                cout<<"The attandence is: "<<endl;
                                for (int j=0;j<temp_en+1;j++)
                                {
                                    cout<<info[i].attandence[j]<<",";
                                }
                                cout<<endl;
                            }
                            if (roll==info[i].student_roll_num && u==data[i].dld_sub)
                            {
                                count++;
                                cout<<"The attandence is: "<<endl;
                                for (int j=0;j<temp_dld+1;j++)
                                {
                                    cout<<info[i].attandence[j]<<",";
                                }
                                cout<<endl;
                            }
                        }
                        if (count==0)
                        {
                            cout<<"No such record found"<<endl;
                        }
                    }
                }
            }
                else if (count==0)
                {
                    cout<<"No such account exists! If you want to logout press 0 else press something else"<<endl;
                    cin>>a;
                }


        }
}

}
