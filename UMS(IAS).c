#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <dirent.h>
#include <stdbool.h>

//vriable
int len_max;
char running_id[30];
struct subject
{
    char name[500];
    int code;
};
struct teacher
{
    char name1[100], name2[100], gender[100], blood[100], department[100], moblile[100], email[100], permanent_add[100], dob[100], joiningdate[100], id[100], pos[50], university[100], cgpa[100];
};
struct EMPLOYEE
{
    char name1[100], name2[100], gender[100], blood[100], department[100], moblile[100], email[100], permanent_add[100], dob[100], joiningdate[100], id[100], pos[50], university[100], cgpa[100];
};
struct student
{
    char name1[100], name2[100], gender[100], blood[100], department[100], moblile[100], email[100], permanent_add[100], dob[100], joiningdate[100], id[100], intake[50], sec[10];
};
struct result_subject
{
    char name[500];
    int code;
    double mid, final, viva, total, gpa;
};
struct messege
{
    char index[100], name1[100], name2[100];
};
struct notice
{
    int index;
    char name[100], path[100];
};

//functions heading
void view_all_notice();
void gotoxy(int x, int y);
void clean_string(char s[], int n);
void clean_n(char s[]);
bool age_ki_input_dice(struct subject ob[], int n, int scode);
bool ase_naki_subject_code(struct subject ob[], int n, int scode);
bool ase_naki_result_sub_code(struct result_subject ob[], int n, int scode);
struct subject find_subject(struct subject ob[], int n, int scode);
int subject_position(struct result_subject ob[], int n, int scode);
void len_name(struct student s_d[], int n);
char borokoro(char c);
void uppercase(char s[]);
int stringtoint(char num[]);
void wrong_selection();
void messenger_frame();
void already_add_frame();
void seeteacherdataFrame(struct teacher ob);
void seestudentdataFrame(struct student ob);
void seeemployeedataFrame(struct EMPLOYEE ob);
void after_save_frame(char id[], char name1[], char name2[], char gender[], char dob[], char admit[]);
int enter_id_frame();
void after_delete_frame(char id[], char name1[], char name2[], char gender[], char dob[], char admit[]);
void want_to_frame_front();
void h_light_want_to_save_menu(int option);
bool wantTosaveframe();
bool wantTosendframe();
bool wantTodeleteframe();
void tdataentryframe();
void Sdataentryframe();
void Edataentryframe();
int enter_n_course_frame();
void batch(char s[]);
void enter_semester_number(char s[]);
struct subject enter_course_frame(int i);
void currtent_course_frame(struct subject ob[], int n);
void academic_frame(struct result_subject ob[], int n);
void update_course_frame(struct subject ob[], int n);
void try_agin_frame();
void h_light_try_agin_menu(int option);
bool try_agin();
void adminframe();
void h_light_admin_menu(int option);
void teacherframe();
void teacher_sectoin_frame();
void h_light_teacher_function_menu(int option);
void employeeframe();
void employee_section_frame();
void h_light_employee_function_menu(int option);
void studentframe();
void h_light_Student_menu(int option);
void student_section_frame();
void h_light_student_function_menu(int option);
void longinframe(char pass[], long long int *userid);
void menuframe();
void h_light_main_menu(int option);
void loading();
bool reg_off_frame();
bool reg_on_frame();
void course_registration_tryleaterFrame();
void sucessfullysaveframe();
void sucessfullysendframe();
void select_course_frame(struct subject ob[], int n, struct subject ob2[], int *x);
double calculate_gpa(double mark);
int mid_final_viva();
void change_mark(char status[], double *mark);
void update_academic_frame(struct result_subject ob[], int n);
void savefile(struct student s_d[], struct result_subject ob[], int n);
int how_many_studen_frame(int *s_code, char sems[]);
void write_new_message(char body[]);
void read_message(char adress[]);
void append_txt_in_file(char adress[]);
void message_body(struct messege ob);
void data_entry_frame(char ch[], char data[]);
void h_light_student_update_helper_frame();
void h_light_student_update_frame(int option, struct student ob);
void h_light_employee_update_helper_frame();
void h_light_employee_update_frame(int option, struct EMPLOYEE ob);
void h_light_teacher_update_helper_frame();
void h_light_teacher_update_frame(int option, struct teacher ob);
void change_password_frame();
void sucessfullychangepass();
void h_light_employee_menu(int option);
void h_light_messenger_menu(int option);
void view_all_notice_frame(int n);
void view_one_notice(char adress[]);
void sucessfullydeleteframe();
void update_notice_frame(int n);
void date_hading_frame(char date[], char heading[]);
void write_notice(char body[]);
void h_light_notice_section(int option);
void h_light_Teacher_menu(int option);

void readpass(char address[], long long int *id, char pass[]);
void readpassForStudentTeacherEmployee(char address[], char pass[]);
bool check_couse();
void update_on_off(int d);
void on_off_course();
bool comparepass(char m_pass[], char ch[], long long int m_id, long long int id);
bool comparepassForStudentTeacherEmployee(char m_pass[], char ch[]);
void genarete_address_from_id(char type[], char id[], char adreess[]);
int genareteid(char address[]);
void change_password_function(char type[]);
struct teacher tdataentry();
void t_save_personaldata(struct teacher ob, char add[]);
void AddNewTeacher();
struct teacher tread_single_pd(char address[]);
void tdeleteid(char m[], char a1[], char a2[], char a3[]);
void deleteTeacher();
void searchTeacher();
void teacherfunction();
struct student sdataentry();
void s_save_personaldata(struct student ob, char add[]);
void AddNewStudent();
struct student sread_single_pd(char address[]);
void sdeleteid(char m[], char a1[]);
void deletestudent();
void searchstudent();
void studentfunction();
struct EMPLOYEE edataentry();
void e_save_personaldata(struct EMPLOYEE ob, char add[]);
void AddNewEmployee();
struct EMPLOYEE eread_single_pd(char address[]);
void edeleteid(char m[], char a1[], char a2[], char a3[]);
void deleteEmployee();
void searchemployee();
void employeefunction();
bool Admin_login();
bool Employee_login();
bool student_login();
bool teacher_login();
void writeincourse(char add[], char status[]);
void present_courses(char add[], char status[]);
void currentcourse(char add[], char status[], bool flag);
void updateCourse(bool flag);
void read_reciver_sender_name(char from[], char to[], char r_id[], char name1[], char name2[]);
void message_list(struct messege ob[], int n, char type[]);
void send_message(char from[], char to[], char body[], char p1[], char p2[], char t_id[]);
void view_message(char type[]);
void messenger_function(char from[], char to[]);
void e_save_update_data(struct EMPLOYEE ob, char adress[]);
void main_employee_upadte_function(struct EMPLOYEE ob, char adress[]);
void t_save_update_data(struct teacher ob, char adress[]);
void main_teacher_upadte_function(struct teacher ob, char adress[]);
void s_save_update_data(struct student ob, char adress[]);
void main_student_upadte_function(struct student ob, char adress[]);
void update_personal_data(char type[]);
int read_notice_quantity();
void read_notice(struct notice ob[], int n);
void view_all_notice();
void create_new_notice();
void append_notice();
void delete_notice();
void update_notice();
void Admin();
void seedataemployee();
void Employee();
void save_course(struct subject sub[], int n);
void add_courses(char add[], char status[]);
void courseForintake();
void student_registration();
void student_present_course();
void seedatastudent();
void academic_informetion();
void StuDent();
void teachersearchstudent();
void seedatateacher();
void teacherseepresentCourse();
void save_result(struct result_subject ob[], int n, char adress[]);
void Update_result();
void Update_result();
struct result_subject make_result_helper1(int subject_code, char s_id[], char sems[]);
struct student make_result_helper2(char s_id[]);
void make_result_sheet();
void Teacher();
void main_menu();
bool new_or_old();

int main()
{
    //system("color 30");
    new_or_old();
    loading();
    main_menu();
    getchar();
    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clean_string(char s[], int n)
{
    while (n--)
        s[n] = '\0';
}
void clean_n(char s[])
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            s[i] = '\0';
        i++;
    }
}
bool age_ki_input_dice(struct subject ob[], int n, int scode)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ob[i].code == scode)
            return true;
    }
    return false;
}
bool ase_naki_subject_code(struct subject ob[], int n, int scode)
{
    system("cls");
    int i;
    for (i = 0; i < n; i++)
    {
        if (ob[i].code == scode)
            return false;
    }
    return true;
}
bool ase_naki_result_sub_code(struct result_subject ob[], int n, int scode)
{
    system("cls");
    int i;
    for (i = 0; i < n; i++)
    {
        if (ob[i].code == scode)
            return false;
    }
    return true;
}
struct subject find_subject(struct subject ob[], int n, int scode)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ob[i].code == scode)
            return ob[i];
    }
}
int subject_position(struct result_subject ob[], int n, int scode)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ob[i].code == scode)
            return i;
    }
    return 0;
}

void len_name(struct student s_d[], int n)
{
    len_max = 0;
    char name[200];
    for (int i = 0; i < n; i++)
    {
        clean_string(name, 199);
        strcat(name, s_d[i].name1);
        strcat(name, s_d[i].name2);
        if (len_max < strlen(name))
            len_max = strlen(name);
    }
    len_max = len_max + 4;
}
char borokoro(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        c = c - 32;
        return c;
    }
    return c;
}
void uppercase(char s[])
{
    int i = 0;
    while (s[i])
    {
        s[i] = borokoro(s[i]);
        i++;
    }
}
int stringtoint(char num[])
{
    int len = strlen(num), result = 0, i;
    for (i = 0; i < len; i++)
    {
        result = result * 10 + (num[i] - '0');
    }
    return result;
}
void wrong_selection()
{
    system("cls");
    system("color 40");
    gotoxy(34, 8);
    printf("#####################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 17);
    printf("#####################             ###################\n");
    gotoxy(45, 14);
    printf("OH!!NO!!WRONG OPTION SELECTED...");
    fflush(stdout);
    Sleep(1500);
}
void messenger_frame()
{
    fflush(stdin);
    system("cls");
    gotoxy(40, 10);
    printf(" #################          ############# \n");
    gotoxy(40, 11);
    printf("#                                        #\n");
    gotoxy(40, 12);
    printf("#                                        #\n");
    gotoxy(40, 13);
    printf("#                                        #\n");
    gotoxy(40, 14);
    printf("#                                        #\n");
    gotoxy(40, 15);
    printf("#                                        #\n");
    gotoxy(40, 16);
    printf("#                                        #\n");
    gotoxy(40, 17);
    printf("#                                        #\n");
    gotoxy(40, 18);
    printf("#                                        #\n");
    gotoxy(40, 19);
    printf("#                                        #\n");
    gotoxy(40, 20);
    printf(" ################          ##############\n");
}
void already_add_frame()
{
    system("cls");
    system("color 40");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 15);
    printf("#####################             ###################\n");
    gotoxy(45, 12);
    printf("OH!!NO!!ALREADY OPTION SELECTED...");
    Sleep(1800);
    system("color 02");
    fflush(stdout);
}
void seeteacherdataFrame(struct teacher ob)
{
    fflush(stdin);
    int i;
    system("cls");
    gotoxy(48, 6);
    printf(" ***SEE INFORMATION****");
    gotoxy(27, 4);
    printf("  #######################              #######################   \n");
    for (i = 1; i < 22; i++)
    {
        gotoxy(27, 4 + i);
        printf("#\t\t\t\t\t\t\t\t  #");
    }
    gotoxy(27, 25);
    printf("  #######################              #######################   \n");

    gotoxy(34, 10);
    printf("[1] NAME          : %s %s\n", ob.name1, ob.name2);
    gotoxy(34, 11);
    printf("[2] ADDRESS       : %s\n", ob.permanent_add);
    gotoxy(34, 12);
    printf("[3] GENDER        : %s\n", ob.gender);
    gotoxy(34, 13);
    printf("[4] CONTACT NUMBER: %s\n", ob.moblile);
    gotoxy(34, 14);
    printf("[5] DOB           : %s\n", ob.dob);
    gotoxy(34, 15);
    printf("[6] BLOOD GROUP   : %s\n", ob.blood);
    gotoxy(34, 16);
    printf("[7] DEPARTMENT    : %s\n", ob.department);
    gotoxy(34, 17);
    printf("[8] E-MAIL        : %s\n", ob.email);
    gotoxy(34, 18);
    printf("[9] POSITION      : %s\n", ob.pos);
    gotoxy(34, 19);
    printf("[10] J/D          : %s\n", ob.joiningdate);
    gotoxy(50, 21);
    printf("Press enter to continue");
    getchar();
}
void seestudentdataFrame(struct student ob)
{
    fflush(stdin);
    int i;
    system("cls");
    gotoxy(48, 6);
    printf(" ***SEE INFORMATION****");
    gotoxy(27, 4);
    printf("  #######################              #######################   \n");
    for (i = 1; i < 22; i++)
    {
        gotoxy(27, 4 + i);
        printf("#\t\t\t\t\t\t\t\t  #");
    }
    gotoxy(27, 25);
    printf("  #######################              #######################   \n");

    gotoxy(34, 10);
    printf("[1] NAME          : %s %s\n", ob.name1, ob.name2);
    gotoxy(34, 11);
    printf("[2] ADDRESS       : %s\n", ob.permanent_add);
    gotoxy(34, 12);
    printf("[3] GENDER        : %s\n", ob.gender);
    gotoxy(34, 13);
    printf("[4] CONTACT NUMBER: %s\n", ob.moblile);
    gotoxy(34, 14);
    printf("[5] DOB           : %s\n", ob.dob);
    gotoxy(34, 15);
    printf("[6] BLOOD GROUP   : %s\n", ob.blood);
    gotoxy(34, 16);
    printf("[7] DEPARTMENT    : %s\n", ob.department);
    gotoxy(34, 17);
    printf("[8] E-MAIL        : %s\n", ob.email);
    gotoxy(34, 18);
    printf("[9] SECTION       : %s\n", ob.sec);
    gotoxy(34, 19);
    printf("[10] INTAKE       : %s\n", ob.intake);
    gotoxy(50, 21);
    printf("Press enter to continue");
    getchar();
}
void seeemployeedataFrame(struct EMPLOYEE ob)
{
    fflush(stdin);
    int i;
    system("cls");
    gotoxy(48, 6);
    printf(" ***SEE YOUR INFORMATION***");
    gotoxy(27, 2);
    printf("#########################              ######################### \n");
    for (i = 1; i < 23; i++)
    {
        gotoxy(27, 2 + i);
        printf("#\t\t\t\t\t\t\t\t  #");
    }
    gotoxy(27, 25);
    printf("#########################              ######################### \n");

    gotoxy(34, 10);
    printf("[1] NAME          : %s %s\n", ob.name1, ob.name2);
    gotoxy(34, 11);
    printf("[2] ADDRESS       : %s\n", ob.permanent_add);
    gotoxy(34, 12);
    printf("[3] GENDER        : %s\n", ob.gender);
    gotoxy(34, 13);
    printf("[4] CONTACT NUMBER: %s\n", ob.moblile);
    gotoxy(34, 14);
    printf("[5] DOB           : %s\n", ob.dob);
    gotoxy(34, 15);
    printf("[6] BLOOD GROUP   : %s\n", ob.blood);
    gotoxy(34, 16);
    printf("[7] DEPARTMENT    : %s\n", ob.department);
    gotoxy(34, 17);
    printf("[8] E-MAIL        : %s\n", ob.email);
    gotoxy(34, 18);
    printf("[9] POSITION      : %s\n", ob.pos);
    gotoxy(34, 19);
    printf("[10] J/D          : %s\n", ob.joiningdate);
    gotoxy(50, 21);
    printf("Press enter to continue");
    getchar();
}
void after_save_frame(char id[], char name1[], char name2[], char gender[], char dob[], char admit[])
{
    system("cls");
    fflush(stdin);
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 10; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 17);
    printf("#####################             ###################\n");
    gotoxy(53, 8);
    printf("Successfully save..");
    gotoxy(35, 10);
    printf("Name  : %s %s", name1, name2);
    gotoxy(73, 10);
    printf("Gender: %s", gender);
    gotoxy(35, 11);
    printf("DOB   : %s", dob);
    gotoxy(35, 12);
    printf("ID    : %s (Note Your id.It's important)", id);
    gotoxy(35, 13);
    printf("J/D   : %s", admit);
    gotoxy(50, 15);
    printf("Press enter to continue");
    getchar();
}

int enter_id_frame()
{
    fflush(stdin);
    system("cls");
    int id;

    gotoxy(40, 10);
    printf(" ######################################## \n");
    gotoxy(40, 11);
    printf("#                                        #\n");
    gotoxy(40, 12);
    printf("#                                        #\n");
    gotoxy(40, 13);
    printf("#                                        #\n");
    gotoxy(40, 14);
    printf("#                                        #\n");
    gotoxy(40, 15);
    printf("#                                        #\n");
    gotoxy(40, 16);
    printf(" ########################################\n");
    gotoxy(47, 13);
    printf("Enter id :");
    scanf("%d", &id);
    return id;
}
void after_delete_frame(char id[], char name1[], char name2[], char gender[], char dob[], char admit[])
{
    system("cls");
    fflush(stdin);
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 10; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 17);
    printf("#####################             ###################\n");
    gotoxy(53, 8);
    printf("Successfully deleted..");
    gotoxy(35, 10);
    printf("Name  : %s %s", name1, name2);
    gotoxy(73, 10);
    printf("Gender: %s", gender);
    gotoxy(35, 11);
    printf("DOB   : %s", dob);
    gotoxy(35, 12);
    printf("ID    : %s (Note Your id.It's important)", id);
    gotoxy(35, 13);
    printf("J/D   : %s", admit);
    gotoxy(50, 15);
    printf("Press enter to continue");
    getchar();
}
void want_to_frame_front()
{
    system("cls");
    gotoxy(34, 9);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 18);
    printf("#####################             ###################\n");
    gotoxy(50, 12);
    printf("  DO YOU WANT TO SAVE?");
}
void h_light_want_to_save_menu(int option)
{
    gotoxy(56, 14);
    printf("YES      ");
    gotoxy(56, 15);
    printf("NO       ");
    switch (option)
    {
    case 1:
        gotoxy(56, 14);
        printf("-> SAVE  ");
        break;
    case 2:
        gotoxy(56, 15);
        printf("-> CANCEL");
        break;
    }
}
bool wantTosaveframe()
{
    fflush(stdin);
    want_to_frame_front();
    int option = 1;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 3)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 2;
            break;
        }

        h_light_want_to_save_menu(option);
        ch = getch();
        if (ch == 13)
        {

            switch (option)
            {
            case 1:
                return true;
            case 2:
                return false;
            default:
                wrong_selection();
                return wantTosaveframe();
            }
        }
    }
}
bool wantTosendframe()
{
    system("cls");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 15);
    printf("#####################             ###################\n");

    gotoxy(50, 8);
    printf("DO YOU WANT TO SEND?");
    gotoxy(56, 10);
    printf("[1]YES");
    gotoxy(56, 11);
    printf("[2]NO");
    gotoxy(51, 13);
    printf("ENTER OPTION:");
    int option;
    gotoxy(64, 13);
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        return true;
    case 2:
        return false;
    default:
        wrong_selection();
        return wantTosendframe();
    }
}
bool wantTodeleteframe()
{
    system("cls");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 15);
    printf("#####################             ###################\n");

    gotoxy(50, 8);
    printf("DO YOU WANT TO DELETE?");
    gotoxy(56, 10);
    printf("[1]YES");
    gotoxy(56, 11);
    printf("[2]NO");
    gotoxy(51, 13);
    printf("ENTER OPTION:");
    int option;
    gotoxy(64, 13);
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        return true;
    case 2:
        return false;
    default:
        wrong_selection();
        return wantTodeleteframe();
    }
}
void tdataentryframe()
{
    system("cls");
    gotoxy(50, 5);
    puts("**TEACHER DATA ENTRY**");
    gotoxy(28, 3);
    printf("##########################             ########################\n");
    for (int i = 0; i < 19; i++)
        printf("\t\t\t   #\t\t\t\t\t\t\t\t   #\n");
    gotoxy(28, 23);
    printf(" #########################             ####################### \n");
}
void Sdataentryframe()
{
    system("cls");
    gotoxy(50, 5);
    puts("**STUDENT DATA ENTRY**");
    gotoxy(28, 3);
    printf("##########################             ########################\n");
    for (int i = 0; i < 18; i++)
        printf("\t\t\t   #\t\t\t\t\t\t\t\t   #\n");
    gotoxy(28, 22);
    printf(" #########################             ####################### \n");
}
void Edataentryframe()
{
    system("cls");
    gotoxy(47, 5);
    puts("**EMPLOYEE DATA ENTRY**");
    gotoxy(28, 3);
    printf("##########################             ########################\n");
    for (int i = 0; i < 19; i++)
        printf("\t\t\t   #\t\t\t\t\t\t\t\t   #\n");
    gotoxy(28, 23);
    printf(" #########################             ####################### \n");
}
int enter_n_course_frame()
{
    fflush(stdin);
    system("cls");
    int n;

    gotoxy(40, 10);
    printf(" ######################################## \n");
    gotoxy(40, 11);
    printf("#                                        #\n");
    gotoxy(40, 12);
    printf("#                                        #\n");
    gotoxy(40, 13);
    printf("#                                        #\n");
    gotoxy(40, 14);
    printf("#                                        #\n");
    gotoxy(40, 15);
    printf("#                                        #\n");
    gotoxy(40, 16);
    printf(" ########################################\n");
    gotoxy(47, 13);
    printf("Enter course quantity :");
    scanf("%d", &n);
    return n;
}
void batch(char s[])
{
    fflush(stdin);
    system("cls");
    int n;

    gotoxy(40, 10);
    printf(" ######################################## \n");
    gotoxy(40, 11);
    printf("#                                        #\n");
    gotoxy(40, 12);
    printf("#                                        #\n");
    gotoxy(40, 13);
    printf("#                                        #\n");
    gotoxy(40, 14);
    printf("#                                        #\n");
    gotoxy(40, 15);
    printf("#                                        #\n");
    gotoxy(40, 16);
    printf(" ########################################\n");
    gotoxy(47, 13);
    printf("Enter Intake :");
    scanf("%s", s);
}
void enter_semester_number(char s[])
{
    fflush(stdin);
    system("cls");
    int n;

    gotoxy(40, 10);
    printf(" ######################################## \n");
    gotoxy(40, 11);
    printf("#                                        #\n");
    gotoxy(40, 12);
    printf("#                                        #\n");
    gotoxy(40, 13);
    printf("#                                        #\n");
    gotoxy(40, 14);
    printf("#                                        #\n");
    gotoxy(40, 15);
    printf("#                                        #\n");
    gotoxy(40, 16);
    printf(" ########################################\n");
    gotoxy(47, 13);
    printf("Enter Semester Number :");
    scanf("%s", s);
}
struct subject enter_course_frame(int i)
{
    fflush(stdin);
    system("cls");
    struct subject ob;
    gotoxy(30, 10);
    printf(" ######################            ##################### \n");
    gotoxy(30, 11);
    printf("#                                                       #\n");
    gotoxy(30, 12);
    printf("#                                                       #\n");
    gotoxy(30, 13);
    printf("#                                                       #\n");
    gotoxy(30, 14);
    printf("#                                                       #\n");
    gotoxy(30, 15);
    printf("#                                                       #\n");
    gotoxy(30, 16);
    printf(" ######################            #####################\n");
    gotoxy(50, 11);
    printf("   Subject : %d\n", i + 1);
    gotoxy(33, 13);
    printf("Enter subject Code  :");
    gotoxy(33, 14);
    printf("Enter subject titel :");
    gotoxy(33 + 21, 13);
    scanf("%d", &ob.code);
    getchar();
    gotoxy(33 + 21, 14);
    gets(ob.name);
    return ob;
}
void currtent_course_frame(struct subject ob[], int n)
{
    fflush(stdin);
    system("cls");
    gotoxy(47, 9);
    puts("**CURRTENT COURCES**");
    gotoxy(25, 6);
    printf("##########################             ########################\n");
    for (int i = 0; i < n + 6; i++)
        printf("\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(25, 6 + n + 7);
    printf(" #########################             ####################### \n");
    int j = 0, i, k = 1;
    for (i = 11, j = 0; i < n + 11; i++, k++)
    {
        gotoxy(35, i);
        printf("%.2d  %.3d  %s\n", k, ob[i - 11].code, ob[i - 11].name);
    }
    gotoxy(44, i + 1);
    printf("Press enter to continue..");
    getchar();
}
void academic_frame(struct result_subject ob[], int n)
{
    fflush(stdin);
    system("cls");
    gotoxy(47, 8);
    puts("    **CURRTENT COURCES**");
    gotoxy(18, 6);
    printf("######################################                ##############################\n");
    for (int i = 0; i < n + 7; i++)
        printf("\t\t#\t\t\t\t\t\t\t\t\t\t\t#\n");
    gotoxy(18, 6 + n + 8);
    printf(" #####################################                ############################# \n");
    gotoxy(22, 10);
    printf("Serial  Sub-Code      Name ");
    gotoxy(62, 10);
    printf("   Mid    Final  V/P/A    Total    GPA\n");
    int j = 0, i, k = 1;
    for (i = 11, j = 0; i < n + 11; i++, k++)
    {
        gotoxy(24, i);
        printf("%.2d    %.3d     %s ", k, ob[i - 11].code, ob[i - 11].name);
        gotoxy(64, i);
        printf("%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n", ob[i - 11].mid, ob[i - 11].final, ob[i - 11].viva, ob[i - 11].total, ob[i - 11].gpa);
    }
    gotoxy(44, i + 1);
    printf("    Press enter to continue..");
    getchar();
}

void update_course_frame(struct subject ob[], int n)
{
    fflush(stdin);
    system("cls");
    gotoxy(47, 5);
    puts("**UPDETED COURCES**");
    gotoxy(25, 3);
    printf("##########################             ########################\n");
    for (int i = 0; i < n + 5; i++)
        printf("\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(25, 3 + n + 6);
    printf(" #########################             ####################### \n");
    int j = 0;
    for (int i = 7, j = 0; i < n + 7; i++)
    {
        gotoxy(35, i);
        printf("%.2d  %.3d  %s\n", i - 6, ob[i - 7].code, ob[i - 7].name);
    }
    gotoxy(44, 3 + n + 5);
    printf("Press enter to continue..");
    getchar();
}

void try_agin_frame()
{
    system("cls");
    gotoxy(34, 9);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 18);
    printf("#####################             ###################\n");
    gotoxy(45, 11);
    printf("OH!!NO!!WRONG USERID AND PASSWORD!");
    gotoxy(50, 13);
    printf("DO YOU WANT TO TRY AGIN?");
}
void h_light_try_agin_menu(int option)
{
    gotoxy(56, 15);
    printf("YES        ");
    gotoxy(56, 16);
    printf("NO         ");
    switch (option)
    {
    case 1:
        gotoxy(56, 15);
        printf("-> Try AGIN");
        break;
    case 2:
        gotoxy(56, 16);
        printf("-> CANCEL  ");
        break;
    }
}
bool try_agin()
{
    fflush(stdin);
    try_agin_frame();
    int option = 1;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 3)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 2;
            break;
        }

        h_light_try_agin_menu(option);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                return true;
            case 2:
                return false;
            default:
                return try_agin();
            }
        }
    }
}
void adminframe()
{
    system("cls");
    gotoxy(55, 9);
    printf("  WELCOME ADMIN");
    gotoxy(32, 6);
    printf("  #########################             ########################\n");
    for (int i = 0; i < 15; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(32, 22);
    printf(" #########################             ########################\n");
}
void h_light_admin_menu(int option)
{
    int x = 50;
    gotoxy(x, 12);
    printf("TEACHER                      ");
    gotoxy(x, 13);
    printf("EMPLOYEE                     ");
    gotoxy(x, 14);
    printf("STUDENT                      ");
    gotoxy(x, 15);
    printf("REGISTRATION                 ");
    gotoxy(x, 16);
    printf("SEMESTER COURCES             ");
    gotoxy(x, 17);
    printf("UPDATE COURCES               ");
    gotoxy(x, 18);
    printf("NOTICE BOARD                 ");
    gotoxy(x, 19);
    printf("EXIT.                        ");
    switch (option)
    {
    case 1:
        gotoxy(x, 12);
        printf("-> TEACHER SECTION           ");
        break;
    case 2:
        gotoxy(x, 13);
        printf("-> EMPLOYEE SECTION          ");
        break;
    case 3:
        gotoxy(x, 14);
        printf("-> STUDENT SECTION           ");
        break;
    case 4:
        gotoxy(x, 15);
        printf("-> ON/OFF COURSE REGISTRATION");
        break;
    case 5:
        gotoxy(x, 16);
        printf("-> RUNNING SEMESTER COURCES  ");
        break;
    case 6:
        gotoxy(x, 17);
        printf("-> EDIT/CREAT COURCES        ");
        break;
    case 7:
        gotoxy(x, 18);
        printf("-> UPDATE NOTICE BOARD       ");
        break;
    case 8:
        gotoxy(x, 19);
        printf("-> EXIT FROM ADMIN           ");
        break;
    }
}
void teacherframe()
{
    system("cls");
    gotoxy(55, 8);
    printf("  WELCOME TEACHER");
    gotoxy(32, 6);
    printf(" #########################             ########################\n");
    for (int i = 0; i < 13; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(32, 20);
    printf(" #########################             ########################\n");
}
void teacher_sectoin_frame()
{
    system("cls");
    gotoxy(55, 9);
    printf(" TEACHER SECTION");
    gotoxy(32, 6);
    printf(" #########################             ########################\n");
    for (int i = 0; i < 13; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(32, 20);
    printf(" #########################             ########################\n");
}
void h_light_teacher_function_menu(int option)
{
    int x = 54;
    gotoxy(x, 12);
    printf("NEW                   ");
    gotoxy(x, 13);
    printf("UPDATE                ");
    gotoxy(x, 14);
    printf("DELETE                ");
    gotoxy(x, 15);
    printf("SEARCH                ");
    gotoxy(x, 16);
    printf("EXIT                  ");
    switch (option)
    {
    case 1:
        gotoxy(x, 12);
        printf("-> ADD A NEW TEACHER  ");
        break;
    case 2:
        gotoxy(x, 13);
        printf("-> UPDATE TEACHER DATA");
        break;
    case 3:
        gotoxy(x, 14);
        printf("-> DELETE A TEACHER   ");
        break;
    case 4:
        gotoxy(x, 15);
        printf("-> SEARCH A TEACHER   ");
        break;
    case 5:
        gotoxy(x, 16);
        printf("-> EXIT FROM TEACHER  ");
        break;
    }
}
void employeeframe()
{
    system("cls");
    gotoxy(55, 8);
    printf("  WELCOME EMPLOYEE");
    gotoxy(32, 6);
    printf(" #########################             ########################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(32, 15);
    printf(" #########################             ########################\n");
}
void employee_section_frame()
{
    system("cls");
    gotoxy(55, 8);
    printf(" EMPLOYEE SECTION");
    gotoxy(32, 6);
    printf(" #########################             ########################\n");
    for (int i = 0; i < 13; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(32, 20);
    printf(" #########################             ########################\n");
}
void h_light_employee_function_menu(int option)
{
    int x = 54;
    gotoxy(x, 12);
    printf("NEW                    ");
    gotoxy(x, 13);
    printf("UPDATE                 ");
    gotoxy(x, 14);
    printf("DELETE                 ");
    gotoxy(x, 15);
    printf("SEARCH                 ");
    gotoxy(x, 16);
    printf("EXIT                   ");
    switch (option)
    {
    case 1:
        gotoxy(x, 12);
        printf("-> ADD A NEW EMPLOYEE  ");
        break;
    case 2:
        gotoxy(x, 13);
        printf("-> UPDATE EMPLOYEE     ");
        break;
    case 3:
        gotoxy(x, 14);
        printf("-> DELETE A EMPLOYEE   ");
        break;
    case 4:
        gotoxy(x, 15);
        printf("-> SEARCH A EMPLOYEE   ");
        break;
    case 5:
        gotoxy(x, 16);
        printf("-> EXIT FROM EMPLOYEE  ");
        break;
    }
}
void studentframe()
{
    system("cls");
    gotoxy(55, 8);
    printf("  WELCOME STUDENT");
    gotoxy(32, 6);
    printf(" #########################             ########################\n");
    for (int i = 0; i < 13; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(32, 20);
    printf(" #########################             ########################\n");
}

void h_light_Student_menu(int option)
{
    int x = 50;
    gotoxy(x, 10);
    printf("INFORMETION             ");
    gotoxy(x, 11);
    printf("PRESENT COURCES         ");
    gotoxy(x, 12);
    printf("REGISTRATION            ");
    gotoxy(x, 13);
    printf("RESULTS                 ");
    gotoxy(x, 14);
    printf("MESSENGER               ");
    gotoxy(x, 15);
    printf("PASSWOARD               ");
    gotoxy(x, 16);
    printf("EXIT                    ");
    switch (option)
    {
    case 1:
        gotoxy(x, 10);
        printf("->SEE YOUR INFORMETION ");
        break;
    case 2:
        gotoxy(x, 11);
        printf("->SEE PRESENT COURCES  ");
        break;
    case 3:
        gotoxy(x, 12);
        printf("->SEMESTER REGISTRATION");
        break;
    case 4:
        gotoxy(x, 13);
        printf("->SEE YOUR ALL RSULTS  ");
        break;
    case 5:
        gotoxy(x, 14);
        printf("->OPEN MESSENGER       ");
        break;
    case 6:
        gotoxy(x, 15);
        printf("->CHANGE YOUR PASSWOARD");
        break;
    case 7:
        gotoxy(x, 16);
        printf("->EXIT FROM STUDENT     ");
        break;
    }
}
void student_section_frame()
{
    system("cls");
    gotoxy(55, 8);
    printf(" STUDENT SECTION");
    gotoxy(32, 6);
    printf(" #########################             ########################\n");
    for (int i = 0; i < 13; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(32, 20);
    printf(" #########################             ########################\n");
}
void h_light_student_function_menu(int option)
{
    int x = 54;
    gotoxy(x, 12);
    printf("NEW                   ");
    gotoxy(x, 13);
    printf("UPDATE                ");
    gotoxy(x, 14);
    printf("DELETE                ");
    gotoxy(x, 15);
    printf("SEARCH                ");
    gotoxy(x, 16);
    printf("EXIT                  ");
    switch (option)
    {
    case 1:
        gotoxy(x, 12);
        printf("-> ADD A NEW STUDENT  ");
        break;
    case 2:
        gotoxy(x, 13);
        printf("-> UPDATE A STUDENT   ");
        break;
    case 3:
        gotoxy(x, 14);
        printf("-> DELETE A STUDENT   ");
        break;
    case 4:
        gotoxy(x, 15);
        printf("-> SEARCH A STUDENT   ");
        break;
    case 5:
        gotoxy(x, 16);
        printf("-> EXIT FROM STUDENT  ");
        break;
    }
}
void longinframe(char pass[], long long int *userid)
{
    system("cls");
    gotoxy(55, 10);
    printf("PLEASE LOGIN");
    gotoxy(33, 8);
    printf("######################             ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 17);
    printf("#####################             ###################\n");
    gotoxy(40, 13);
    printf("USER ID  :");
    gotoxy(40, 14);
    printf("PASSWORD :");
    gotoxy(50, 13);
    scanf("%lld", userid);
    gotoxy(50, 14);
    scanf("%s", pass);
}
void menuframe()
{
    system("cls");
    gotoxy(25, 3);
    printf("###############################             ##########################  \n");
    for (int i = 0; i < 20; i++)
        printf("\t\t\t#\t\t\t\t\t\t\t\t\t#\n");
    gotoxy(25, 24);
    printf("###############################             ##########################  \n");
}
void h_light_main_menu(int option)
{
    int x = 52;
    gotoxy(x, 12);
    printf("ADMIN               ");
    gotoxy(x, 13);
    printf("EMPLOYEE            ");
    gotoxy(x, 14);
    printf("TEACHER             ");
    gotoxy(x, 15);
    printf("STUDENT             ");
    gotoxy(x, 16);
    printf("NOTICE BOARD        ");
    gotoxy(x, 17);
    printf("EXIT                ");
    switch (option)
    {
    case 1:
        gotoxy(x, 12);
        printf("-> LOGIN AS  ADMIN  ");
        break;
    case 2:
        gotoxy(x, 13);
        printf("-> LOGIN AS EMPLOYEE");
        break;
    case 3:
        gotoxy(x, 14);
        printf("-> LOGIN AS TEACHER ");
        break;
    case 4:
        gotoxy(x, 15);
        printf("-> LOGIN AS STUDENT ");
        break;
    case 5:
        gotoxy(x, 16);
        printf("-> VIEW ALL NOTICES  ");
        break;
    case 6:
        gotoxy(x, 17);
        printf("-> EXIT               ");
        break;
    }
}
void loading()
{
    menuframe();
    int c = 13, t = 3;
    fflush(stdout);
    Sleep(200);
    gotoxy(57, 11);
    printf("LOADING...\n");
    gotoxy(44, 14);
    while (c--)
    {
        t = 3;
        while (t--)
        {
            printf("%c", 221);
            fflush(stdout);
            Sleep(50);
        }
    }
    system("cls");
}
bool reg_off_frame()
{
    fflush(stdin);
    system("cls");
    int choice;
    gotoxy(40, 10);
    printf(" ##################         ###################### \n");
    gotoxy(40, 11);
    printf("#                                                 #\n");
    gotoxy(40, 12);
    printf("#                                                 #\n");
    gotoxy(40, 13);
    printf("#                                                 #\n");
    gotoxy(40, 14);
    printf("#                                                 #\n");
    gotoxy(40, 15);
    printf("#                                                 #\n");
    gotoxy(40, 16);
    printf("#                                                 #\n");
    gotoxy(40, 17);
    printf("#                                                 #\n");
    gotoxy(40, 18);
    printf(" ##################         ######################\n");
    gotoxy(50, 12);
    printf("Course registration now off....");
    gotoxy(56, 14);
    printf("Do you want to on?");
    gotoxy(57, 15);
    printf("[1] YES. [2] NO");
    gotoxy(56, 17);
    printf("Enter choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        return true;
    case 2:
        return false;
    default:
        wrong_selection();
        return reg_off_frame();
    }
}
bool reg_on_frame()
{
    fflush(stdin);
    system("cls");
    int choice;
    gotoxy(40, 10);
    printf(" ##################         ###################### \n");
    gotoxy(40, 11);
    printf("#                                                 #\n");
    gotoxy(40, 12);
    printf("#                                                 #\n");
    gotoxy(40, 13);
    printf("#                                                 #\n");
    gotoxy(40, 14);
    printf("#                                                 #\n");
    gotoxy(40, 15);
    printf("#                                                 #\n");
    gotoxy(40, 16);
    printf("#                                                 #\n");
    gotoxy(40, 17);
    printf("#                                                 #\n");
    gotoxy(40, 18);
    printf(" ##################         ######################\n");
    gotoxy(50, 12);
    printf("Course registration now on....");
    gotoxy(56, 14);
    printf("Do you want to off?");
    gotoxy(57, 15);
    printf("[1] YES. [2] NO");
    gotoxy(56, 17);
    printf("Enter choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        return true;
    case 2:
        return false;
    default:
        wrong_selection();
        return reg_on_frame();
    }
}
void course_registration_tryleaterFrame()
{
    fflush(stdin);
    system("cls");
    int choice;
    gotoxy(40, 10);
    printf(" ##################         ###################### \n");
    gotoxy(40, 11);
    printf("#                                                 #\n");
    gotoxy(40, 12);
    printf("#                                                 #\n");
    gotoxy(40, 13);
    printf("#                                                 #\n");
    gotoxy(40, 14);
    printf("#                                                 #\n");
    gotoxy(40, 15);
    printf("#                                                 #\n");
    gotoxy(40, 16);
    printf("#                                                 #\n");
    gotoxy(40, 17);
    printf("#                                                 #\n");
    gotoxy(40, 18);
    printf(" ##################         ######################\n");
    gotoxy(50, 12);
    printf("Course registration now off....:)");
    gotoxy(50, 14);
    printf("     Try  again later..");
    gotoxy(50, 16);
    printf("        Thank you.");
    Sleep(1800);
}

void sucessfullysaveframe()
{
    system("cls");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 15);
    printf("#####################             ###################\n");
    gotoxy(45, 12);
    printf("SUCESSFULLY ADDED...");
    Sleep(1800);
}
void sucessfullysendframe()
{
    system("cls");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 15);
    printf("#####################             ###################\n");
    gotoxy(45, 12);
    printf("SUCESSFULLY SEND...");
    Sleep(1800);
}
void select_course_frame(struct subject ob[], int n, struct subject ob2[], int *x)
{
    fflush(stdin);
    system("cls");
    gotoxy(45, 9);
    puts("**CURRTENT AVAILABLE COURCES**");
    gotoxy(27, 8);
    puts("STOP = 0");
    gotoxy(25, 6);
    printf("##########################             ########################\n");
    for (int i = 0; i < n + 11 + *x; i++)
        printf("\t\t\t#\t\t\t\t\t\t\t\t#\n");
    gotoxy(25, 6 + n + 12 + *x);
    printf(" #########################             ####################### \n");
    int j = 0, i, k = 1, id;
    char s[10];
    for (i = 11, j = 0; i < n + 11; i++, k++)
    {
        gotoxy(35, i);
        printf("%.2d  %.3d  %s\n", k, ob[i - 11].code, ob[i - 11].name);
    }
    i += 1;
    j = i;
    i += 2;
    gotoxy(44, i);
    printf("YOU ADD COURSE FOR YOU");
    for (k = 0; k < *x; k++)
    {
        gotoxy(35, i + k + 2);
        printf("%.2d  %.3d  %s\n", k + 1, ob2[k].code, ob2[k].name);
    }
    gotoxy(44, j);
    printf("Press enter subject code :");
    scanf("%d", &id);
    if (id == 0)
    {
        return;
    }
    else if (age_ki_input_dice(ob2, *x, id))
    {
        already_add_frame();
        return select_course_frame(ob, n, ob2, x);
    }
    else if (ase_naki_subject_code(ob, n, id))
    {
        wrong_selection();
        return select_course_frame(ob, n, ob2, x);
    }
    else
    {
        ob2[*x] = find_subject(ob, n, id);
        *x += 1;
        return select_course_frame(ob, n, ob2, x);
    }
}
double calculate_gpa(double mark)
{
    if (mark >= 80)
        return 4.00;
    else if (mark >= 75)
        return 3.75;
    else if (mark >= 70)
        return 3.50;
    else if (mark >= 65)
        return 3.25;
    else if (mark >= 60)
        return 3.00;
    else if (mark >= 55)
        return 2.75;
    else if (mark >= 50)
        return 2.50;
    else if (mark >= 45)
        return 2.25;
    else if (mark >= 40)
        return 2.00;
    else
        return 0.00;
}
int mid_final_viva()
{
    fflush(stdin);
    int option;
    system("cls");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 15);
    printf("#####################             ###################\n");
    gotoxy(38, 10);
    printf("[1] MID TERM.   [2] FINAL TERM.   [3] V/P/A. ");
    gotoxy(54, 12);
    printf("ENTER OPTION :");
    scanf("%d", &option);
    if (option <= 0 || option >= 4)
    {
        wrong_selection();
        return mid_final_viva();
    }
    return option;
}
void change_mark(char status[], double *mark)
{
    fflush(stdin);
    double m;
    system("cls");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 6; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 13);
    printf("#####################             ###################\n");
    gotoxy(38, 10);
    printf("%s ", status);
    scanf("%lf", &m);
    *mark = m;
}
void update_academic_frame(struct result_subject ob[], int n)
{
    fflush(stdin);
    system("cls");
    int sub_code;
    gotoxy(47, 8);
    puts("    **CURRTENT COURCES**");
    gotoxy(18, 6);
    printf("######################################                ##############################\n");
    for (int i = 0; i < n + 7; i++)
        printf("\t\t#\t\t\t\t\t\t\t\t\t\t\t#\n");
    gotoxy(18, 6 + n + 8);
    printf(" #####################################                ############################# \n");
    gotoxy(22, 10);
    printf("Serial  Sub-Code      Name ");
    gotoxy(62, 10);
    printf("   Mid    Final  V/P/A    Total    GPA\n");
    int j = 0, i, k = 1;
    for (i = 11, j = 0; i < n + 11; i++, k++)
    {
        gotoxy(24, i);
        printf("%.2d    %.3d     %s ", k, ob[i - 11].code, ob[i - 11].name);
        gotoxy(64, i);
        printf("%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n", ob[i - 11].mid, ob[i - 11].final, ob[i - 11].viva, ob[i - 11].total, ob[i - 11].gpa);
    }
    gotoxy(44, i + 1);
    printf("    ENTER SUBJECT CODE :");
    scanf("%d", &sub_code);
    if (ase_naki_result_sub_code(ob, n, sub_code))
    {
        wrong_selection();
        return update_academic_frame(ob, n);
    }
    int option = mid_final_viva();
    i = subject_position(ob, n, sub_code);
    switch (option)
    {
    case 1:
        change_mark("ENTER MID TERM MARK :", &ob[i].mid);
        break;
    case 2:
        change_mark("ENTER FINAL TERM MARK :", &ob[i].final);
        break;
    case 3:
        change_mark("ENTER V/P/A MARK :", &ob[i].viva);
        break;
    }
}

void savefile(struct student s_d[], struct result_subject ob[], int n)
{
    FILE *save_info;
    int i = 0;
    save_info = fopen("C://save.txt", "w");
    if (save_info == NULL)
    {
        printf("Could not open file");
    }
    else
    {
        int c = 0, b;
        len_name(s_d, n);
        uppercase(ob[0].name);
        fprintf(save_info, "                         BUBT INTAKE %s SECTION %s %s TOTAL RESULT\n\n", s_d[0].intake, s_d[0].sec, ob[0].name);
        fprintf(save_info, "S.No.      ID        NAME");

        for (c = 9; c <= len_max; c++)
        {
            fprintf(save_info, " ");
        }

        fprintf(save_info, "   MID         FINAL       V/P/A     TOTAL      GPA\n");

        for (i = 0; i < n; i++)
        {
            fprintf(save_info, "%.4d\t", i + 1);
            fprintf(save_info, " ");
            int d = stringtoint(s_d[i].id);
            fprintf(save_info, "%.5d ", d);
            fprintf(save_info, " ");
            char name[200];
            clean_string(name, 199);
            strcat(name, s_d[i].name1);
            strcat(name, s_d[i].name2);
            fprintf(save_info, "%s %s", s_d[i].name1, s_d[i].name2);

            b = strlen(name + 1);
            for (c = b; c <= len_max; c++)
            {
                fprintf(save_info, " ");
            }

            fprintf(save_info, "%.2f\t", ob[i].mid);
            fprintf(save_info, "    ");
            fprintf(save_info, "%.2f\t", ob[i].final);
            fprintf(save_info, " ");
            fprintf(save_info, "%.2f\t", ob[i].viva);
            fprintf(save_info, "  ");
            fprintf(save_info, "%.2f\t", ob[i].total);
            fprintf(save_info, "     ");
            fprintf(save_info, "%.2f\n", ob[i].gpa);
        }
    }
    fclose(save_info);
}
int how_many_studen_frame(int *s_code, char sems[])
{
    fflush(stdin);
    system("cls");
    int n, x;

    gotoxy(40, 10);
    printf(" ######################################## \n");
    gotoxy(40, 11);
    printf("#                                        #\n");
    gotoxy(40, 12);
    printf("#                                        #\n");
    gotoxy(40, 13);
    printf("#                                        #\n");
    gotoxy(40, 14);
    printf("#                                        #\n");
    gotoxy(40, 15);
    printf("#                                        #\n");
    gotoxy(40, 16);
    printf(" ########################################\n");
    gotoxy(47, 12);
    printf("Enter Student quantity :");
    scanf("%d", &n);
    gotoxy(47, 13);
    printf("Enter Subject Code     :");
    scanf("%d", &x);
    *s_code = x;
    gotoxy(47, 14);
    printf("Enter semester number  :");
    scanf("%s", sems);
    return n;
}
void write_new_message(char body[])
{
    system("cls");
    fflush(stdin);
    printf("WRITE MESSAGE :-");
    gets(body);
}
void read_message(char adress[])
{
    FILE *ptr = fopen(adress, "r");
    char name[100], body[500];
    fgets(name, 100, ptr);
    fgets(name, 100, ptr);

    while (fgets(name, 100, ptr))
    {
        fgets(body, 500, ptr);
        clean_n(name);
        clean_n(body);
        printf("%s : %s\n", name, body);
    }
    fclose(ptr);
}
void append_txt_in_file(char adress[])
{
    fflush(stdin);
    char name[100], body[500];
    gets(name);
    printf("\nENTER REPLY :");
    gets(body);

    FILE *ptr;
    ptr = fopen(adress, "a+");
    fprintf(ptr, "%s\n", name);
    fprintf(ptr, "%s\n", body);
    fclose(ptr);
}
void message_body(struct messege ob)
{
    fflush(stdin);
    system("cls");
    int option;
    read_message(ob.index);

    printf("\n[1] REPLY. [2] EXIT.\n");
    printf("ENTER OPTION :");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        printf("\nENTER YOUR NAME :");
        append_txt_in_file(ob.index);
    }
}
void data_entry_frame(char ch[], char data[])
{
    fflush(stdin);
    system("cls");
    gotoxy(40, 10);
    printf("  ###########################################  \n");
    gotoxy(40, 11);
    printf("#                                            #\n");
    gotoxy(40, 12);
    printf("#                                            #\n");
    gotoxy(40, 13);
    printf("#                                            #\n");
    gotoxy(40, 14);
    printf("#                                            #\n");
    gotoxy(40, 15);
    printf("#                                            #\n");
    gotoxy(40, 16);
    printf("  ##########################################  \n");
    gotoxy(43, 13);
    printf("ENTER %s : ", ch);
    gets(data);
}
void h_light_student_update_helper_frame()
{
    fflush(stdin);
    int i;
    system("cls");
    gotoxy(48, 6);
    printf(" ***UPDATE INFORMATION****");
    gotoxy(27, 4);
    printf("  #######################              #######################   \n");
    for (i = 1; i < 22; i++)
    {
        gotoxy(27, 4 + i);
        printf("#\t\t\t\t\t\t\t\t  #");
    }
    gotoxy(27, 25);
    printf("  #######################              #######################   \n");
}
void h_light_student_update_frame(int option, struct student ob)
{
    gotoxy(34, 10);
    printf("FIRST NAME    : %s   ", ob.name1);
    gotoxy(34, 11);
    printf("LAST NAME     : %s   ", ob.name2);
    gotoxy(34, 12);
    printf("ADDRESS       : %s   ", ob.permanent_add);
    gotoxy(34, 13);
    printf("GENDER        : %s   ", ob.gender);
    gotoxy(34, 14);
    printf("CONTACT NUMBER: %s   ", ob.moblile);
    gotoxy(34, 15);
    printf("DOB           : %s   ", ob.dob);
    gotoxy(34, 16);
    printf("BLOOD GROUP   : %s   ", ob.blood);
    gotoxy(34, 17);
    printf("DEPARTMENT    : %s   ", ob.department);
    gotoxy(34, 18);
    printf("E-MAIL        : %s   ", ob.email);
    gotoxy(34, 19);
    printf("SECTION       : %s   ", ob.sec);
    gotoxy(34, 20);
    printf("INTAKE        : %s   ", ob.intake);
    gotoxy(34, 21);
    printf("EXIT                 ");

    switch (option)
    {
    case 1:
        gotoxy(34, 10);
        printf("-> FIRST NAME    : %s", ob.name1);
        break;
    case 2:
        gotoxy(34, 11);
        printf("-> LAST NAME     : %s", ob.name2);
        break;
    case 3:
        gotoxy(34, 12);
        printf("-> ADDRESS       : %s", ob.permanent_add);
        break;
    case 4:
        gotoxy(34, 13);
        printf("-> GENDER        : %s", ob.gender);
        break;
    case 5:
        gotoxy(34, 14);
        printf("-> CONTACT NUMBER: %s", ob.moblile);
        break;
    case 6:
        gotoxy(34, 15);
        printf("-> DOB           : %s", ob.dob);
        break;
    case 7:
        gotoxy(34, 16);
        printf("-> BLOOD GROUP   : %s", ob.blood);
        break;
    case 8:
        gotoxy(34, 17);
        printf("-> DEPARTMENT    : %s", ob.department);
        break;
    case 9:
        gotoxy(34, 18);
        printf("-> E-MAIL        : %s", ob.email);
        break;
    case 10:
        gotoxy(34, 19);
        printf("-> SECTION       : %s", ob.sec);
        break;
    case 11:
        gotoxy(34, 20);
        printf("-> INTAKE        : %s", ob.intake);
        break;
    case 12:
        gotoxy(34, 21);
        printf("-> SAVE CHANGES      ");
        break;
    }
}
void h_light_employee_update_helper_frame()
{
    fflush(stdin);
    int i;
    system("cls");
    gotoxy(48, 6);
    printf(" ***UPDATE INFORMATION****");
    gotoxy(27, 4);
    printf("  #######################              #######################   \n");
    for (i = 1; i < 22; i++)
    {
        gotoxy(27, 4 + i);
        printf("#\t\t\t\t\t\t\t\t  #");
    }
    gotoxy(27, 25);
    printf("  #######################              #######################   \n");
}

void h_light_employee_update_frame(int option, struct EMPLOYEE ob)
{
    gotoxy(34, 10);
    printf("FIRST NAME    : %s   ", ob.name1);
    gotoxy(34, 11);
    printf("LAST NAME     : %s   ", ob.name2);
    gotoxy(34, 12);
    printf("ADDRESS       : %s   ", ob.permanent_add);
    gotoxy(34, 13);
    printf("GENDER        : %s   ", ob.gender);
    gotoxy(34, 14);
    printf("CONTACT NUMBER: %s   ", ob.moblile);
    gotoxy(34, 15);
    printf("DOB           : %s   ", ob.dob);
    gotoxy(34, 16);
    printf("BLOOD GROUP   : %s   ", ob.blood);
    gotoxy(34, 17);
    printf("DEPARTMENT    : %s   ", ob.department);
    gotoxy(34, 18);
    printf("E-MAIL        : %s   ", ob.email);
    gotoxy(34, 19);
    printf("UNIVERSITY    : %s   ", ob.university);
    gotoxy(34, 20);
    printf("POSITION      : %s   ", ob.pos);
    gotoxy(34, 21);
    printf("CGPA          : %s   ", ob.cgpa);
    gotoxy(34, 22);
    printf("EXIT                 ");

    switch (option)
    {
    case 1:
        gotoxy(34, 10);
        printf("-> FIRST NAME    : %s", ob.name1);
        break;
    case 2:
        gotoxy(34, 11);
        printf("-> LAST NAME     : %s", ob.name2);
        break;
    case 3:
        gotoxy(34, 12);
        printf("-> ADDRESS       : %s", ob.permanent_add);
        break;
    case 4:
        gotoxy(34, 13);
        printf("-> GENDER        : %s", ob.gender);
        break;
    case 5:
        gotoxy(34, 14);
        printf("-> CONTACT NUMBER: %s", ob.moblile);
        break;
    case 6:
        gotoxy(34, 15);
        printf("-> DOB           : %s", ob.dob);
        break;
    case 7:
        gotoxy(34, 16);
        printf("-> BLOOD GROUP   : %s", ob.blood);
        break;
    case 8:
        gotoxy(34, 17);
        printf("-> DEPARTMENT    : %s", ob.department);
        break;
    case 9:
        gotoxy(34, 18);
        printf("-> E-MAIL        : %s", ob.email);
        break;
    case 10:
        gotoxy(34, 19);
        printf("-> UNIVERSITY    : %s", ob.university);
        break;
    case 11:
        gotoxy(34, 20);
        printf("-> POSITION      : %s", ob.pos);
        break;
    case 12:
        gotoxy(34, 21);
        printf("-> CGPA          : %s", ob.cgpa);
        break;
    case 13:
        gotoxy(34, 22);
        printf("-> SAVE CHANGES      ");
        break;
    }
}
void h_light_teacher_update_helper_frame()
{
    fflush(stdin);
    int i;
    system("cls");
    gotoxy(48, 6);
    printf(" ***UPDATE INFORMATION****");
    gotoxy(27, 4);
    printf("  #######################              #######################   \n");
    for (i = 1; i < 22; i++)
    {
        gotoxy(27, 4 + i);
        printf("#\t\t\t\t\t\t\t\t  #");
    }
    gotoxy(27, 25);
    printf("  #######################              #######################   \n");
}
void h_light_teacher_update_frame(int option, struct teacher ob)
{
    gotoxy(34, 10);
    printf("FIRST NAME    : %s   ", ob.name1);
    gotoxy(34, 11);
    printf("LAST NAME     : %s   ", ob.name2);
    gotoxy(34, 12);
    printf("ADDRESS       : %s   ", ob.permanent_add);
    gotoxy(34, 13);
    printf("GENDER        : %s   ", ob.gender);
    gotoxy(34, 14);
    printf("CONTACT NUMBER: %s   ", ob.moblile);
    gotoxy(34, 15);
    printf("DOB           : %s   ", ob.dob);
    gotoxy(34, 16);
    printf("BLOOD GROUP   : %s   ", ob.blood);
    gotoxy(34, 17);
    printf("DEPARTMENT    : %s   ", ob.department);
    gotoxy(34, 18);
    printf("E-MAIL        : %s   ", ob.email);
    gotoxy(34, 19);
    printf("UNIVERSITY    : %s   ", ob.university);
    gotoxy(34, 20);
    printf("POSITION      : %s   ", ob.pos);
    gotoxy(34, 21);
    printf("CGPA          : %s   ", ob.cgpa);
    gotoxy(34, 22);
    printf("EXIT                 ");

    switch (option)
    {
    case 1:
        gotoxy(34, 10);
        printf("-> FIRST NAME    : %s", ob.name1);
        break;
    case 2:
        gotoxy(34, 11);
        printf("-> LAST NAME     : %s", ob.name2);
        break;
    case 3:
        gotoxy(34, 12);
        printf("-> ADDRESS       : %s", ob.permanent_add);
        break;
    case 4:
        gotoxy(34, 13);
        printf("-> GENDER        : %s", ob.gender);
        break;
    case 5:
        gotoxy(34, 14);
        printf("-> CONTACT NUMBER: %s", ob.moblile);
        break;
    case 6:
        gotoxy(34, 15);
        printf("-> DOB           : %s", ob.dob);
        break;
    case 7:
        gotoxy(34, 16);
        printf("-> BLOOD GROUP   : %s", ob.blood);
        break;
    case 8:
        gotoxy(34, 17);
        printf("-> DEPARTMENT    : %s", ob.department);
        break;
    case 9:
        gotoxy(34, 18);
        printf("-> E-MAIL        : %s", ob.email);
        break;
    case 10:
        gotoxy(34, 19);
        printf("-> UNIVERSITY    : %s", ob.university);
        break;
    case 11:
        gotoxy(34, 20);
        printf("-> POSITION      : %s", ob.pos);
        break;
    case 12:
        gotoxy(34, 21);
        printf("-> CGPA          : %s", ob.cgpa);
        break;
    case 13:
        gotoxy(34, 22);
        printf("-> SAVE CHANGES      ");
        break;
    }
}

void change_password_frame()
{
    int i;
    system("cls");
    gotoxy(35, 8);
    printf("#####################            ###################\n");
    for (i = 0; i < 10; i++)
    {
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    }
    gotoxy(35, 19);
    printf("#####################            ###################\n");

    gotoxy(50, 10);
    printf("CHANGE YOUR PASSWORD");
    gotoxy(38, 12);
    printf("CURRENT PASSWORD  : ");
    gotoxy(38, 14);
    printf("NEW PASSWORD      : ");
    gotoxy(38, 16);
    printf("CONFIRAM PASSWORD : ");
}
void sucessfullychangepass()
{
    system("cls");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 15);
    printf("#####################             ###################\n");
    gotoxy(45, 12);
    printf("SUCESSFULLY CHANGED PASSWOARD..");
    Sleep(1800);
}
void h_light_employee_menu(int option)
{
    gotoxy(45, 11);
    printf("INFORMETION             ");
    gotoxy(45, 12);
    printf("PASSWOARD               ");
    gotoxy(45, 13);
    printf("Exit                    ");
    switch (option)
    {
    case 1:
        gotoxy(45, 11);
        printf("-> SEE YOUR INFORMETION ");
        break;
    case 2:
        gotoxy(45, 12);
        printf("-> CHANGE YOUR PASSWOARD");
        break;
    case 3:
        gotoxy(45, 13);
        printf("-> EXIT FROM EMPLOYEE   ");
        break;
    }
}
void h_light_messenger_menu(int option)
{
    gotoxy(54, 14);
    printf("VIEW MESSAGES         ");
    gotoxy(54, 15);
    printf("SEND MESSAGE          ");
    gotoxy(54, 16);
    printf("EXIT                  ");
    switch (option)
    {
    case 1:
        gotoxy(54, 14);
        printf("-> VIEW MESSAGES      ");
        break;
    case 2:
        gotoxy(54, 15);
        printf("-> SEND MESSAGE       ");
        break;
    case 3:
        gotoxy(54, 16);
        printf("-> EXIT FROM MESSENGER");
        break;
    }
}
void view_all_notice_frame(int n)
{
    system("cls");
    int i;
    gotoxy(35, 8);
    printf("#####################            ###################\n");
    for (i = 0; i < n + 7; i++)
    {
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    }
    gotoxy(35, 16 + n);
    printf("#####################            ###################\n");
    gotoxy(50, 10);
    printf("WELCOME TO NOTICE BOARD");
}
void view_one_notice(char adress[])
{
    system("cls");
    fflush(stdin);
    FILE *ptr;
    ptr = fopen(adress, "r");
    char c;
    while (fscanf(ptr, "%c", &c) != EOF)
    {
        printf("%c", c);
    }
    fclose(ptr);
    printf("\n\t\t\t\t\t\tPRESS ENTER TO EXIT.....");
    getchar();

    return view_all_notice();
}
void sucessfullydeleteframe()
{
    system("cls");
    gotoxy(34, 6);
    printf("######################            ####################\n");
    for (int i = 0; i < 8; i++)
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(34, 15);
    printf("#####################             ###################\n");
    gotoxy(45, 12);
    printf("SUCESSFULLY DELETED...");
    Sleep(1800);
}
void update_notice_frame(int n)
{
    system("cls");
    int i;
    gotoxy(35, 8);
    printf("#####################            ###################\n");
    for (i = 0; i < n + 7; i++)
    {
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    }
    gotoxy(35, 16 + n);
    printf("#####################            ###################\n");
    gotoxy(50, 10);
    printf("WELCOME TO NOTICE SCTION");
}
void date_hading_frame(char date[], char heading[])
{
    system("cls");
    fflush(stdin);
    int i;
    int n = 3;
    gotoxy(35, 10);
    printf("#####################            ###################\n");
    for (i = 0; i < n + 5; i++)
    {
        printf("\t\t\t\t#\t\t\t\t\t\t\t#\n");
    }
    gotoxy(35, 16 + n);
    printf("#####################            ###################\n");
    gotoxy(50, 12);
    printf("DATE FORMAT (DD/MM/YY) ");
    gotoxy(38, 14);
    printf("ENTER DATE    : ");
    gotoxy(38, 16);
    printf("ENTER SUBJRCT : ");
    gotoxy(38 + 16, 14);
    gets(date);
    gotoxy(38 + 16, 16);
    gets(heading);
}
void write_notice(char body[])
{
    system("cls");
    fflush(stdin);
    printf("\t\t\t\t\t\tWRITE YOUR NOTICE :)\nSTART WRITING :- ");
    gets(body);
}
void h_light_notice_section(int option)
{
    gotoxy(53, 13);
    printf("NEW                   ");
    gotoxy(53, 14);
    printf("UPDATE                ");
    gotoxy(53, 15);
    printf("DELETE                ");
    gotoxy(53, 16);
    printf("EXIT                  ");
    switch (option)
    {
    case 1:
        gotoxy(53, 13);
        printf("-> CREATE A NEW NOTICE");
        break;
    case 2:
        gotoxy(53, 14);
        printf("-> UPDATE A NOTICE    ");
        break;
    case 3:
        gotoxy(53, 15);
        printf("-> DELETE A NOTICE    ");
        break;
    case 4:
        gotoxy(53, 16);
        printf("-> EXIT FROM NOTICE   ");
    }
}
void h_light_Teacher_menu(int option)
{
    int x = 50;
    gotoxy(x, 10);
    printf("INFORMETION               ");
    gotoxy(x, 11);
    printf("RESULT                    ");
    gotoxy(x, 12);
    printf("STUDENT INFORMATION       ");
    gotoxy(x, 13);
    printf("UPDATE                    ");
    gotoxy(x, 14);
    printf("MESSENGER                 ");
    gotoxy(x, 15);
    printf("COURCES                   ");
    gotoxy(x, 16);
    printf("RESULT SHEET              ");
    gotoxy(x, 17);
    printf("PASSWOARD                 ");
    gotoxy(x, 18);
    printf("EXIT                      ");

    switch (option)
    {
    case 1:
        gotoxy(x, 10);
        printf("-> SEE YOUR INFORMETION   ");
        break;
    case 2:
        gotoxy(x, 11);
        printf("-> SEE STUDENT RESULT     ");
        break;
    case 3:
        gotoxy(x, 12);
        printf("-> SEE STUDENT INFORMATION");
        break;
    case 4:
        gotoxy(x, 13);
        printf("-> UPDATE STUDENTUPDATE STUDENT RESULTS ");
        break;
    case 5:
        gotoxy(x, 14);
        printf("-> OPEN MESSENGER         ");
        break;
    case 6:
        gotoxy(x, 15);
        printf("-> SEE PRESENT COURCES    ");
        break;
    case 7:
        gotoxy(x, 16);
        printf("-> MAKE A RESULT SHEET    ");
        break;
    case 8:
        gotoxy(x, 17);
        printf("-> CHANGE YOUR PASSWOARD  ");
        break;
    case 9:
        gotoxy(x, 18);
        printf("->EXIT FROM TEACHER       ");
        break;
    }
}

void readpass(char address[], long long int *id, char pass[])
{
    fflush(stdin);
    FILE *read;
    read = fopen(address, "r");
    fscanf(read, "%lld%s", id, pass);
    fclose(read);
}
void readpassForStudentTeacherEmployee(char address[], char pass[])
{
    fflush(stdin);
    FILE *read;
    read = fopen(address, "r");
    fscanf(read, "%s", pass);
    fclose(read);
}
bool check_couse()
{
    FILE *ptr;
    int i;
    ptr = fopen("C://UMS(IAS)//data//course//status.txt", "r");
    fscanf(ptr, "%d", &i);
    fclose(ptr);
    if (i == 1)
        return true;
    return false;
}
void update_on_off(int d)
{
    FILE *ptr;
    ptr = fopen("C://UMS(IAS)//data//course//status.txt", "w");
    fprintf(ptr, "%d", d);
    fclose(ptr);
}
void on_off_course()
{
    if (check_couse())
    {
        if (reg_on_frame())
            update_on_off(0);
    }
    else
    {
        if (reg_off_frame())
            update_on_off(1);
    }
    return Admin();
}

bool comparepass(char m_pass[], char ch[], long long int m_id, long long int id)
{
    int i = 0;
    while (m_pass[i] || ch[i])
    {
        if (m_pass[i] != ch[i])
            return false;
        i++;
    }
    if (m_id != id)
        return false;
    return true;
}
bool comparepassForStudentTeacherEmployee(char m_pass[], char ch[])
{
    int i = 0;
    while (m_pass[i] || ch[i])
    {
        if (m_pass[i] != ch[i])
            return false;
        i++;
    }
    return true;
}
void genarete_address_from_id(char type[], char id[], char adreess[])
{
    strcat(adreess, "C://UMS(IAS)//data//");
    strcat(adreess, type);
    strcat(adreess, "//");
    strcat(adreess, id);
}
int genareteid(char address[])
{
    int n, start, eNd;
    FILE *read;

    read = fopen(address, "r");
    fscanf(read, "%d%d%d", &n, &start, &eNd);
    eNd += 1;
    n += 1;
    fclose(read);
    FILE *write;
    write = fopen(address, "w+");
    fprintf(write, "%d %d %d", n, start, eNd);
    fclose(write);

    return eNd;
}

void change_password_function(char type[])
{
    fflush(stdin);
    change_password_frame();
    char real_pass[100], currentpass[100], new_pass[100], confirm_pass[100], adress[100];
    clean_string(real_pass, 99);
    clean_string(currentpass, 99);
    clean_string(new_pass, 99);
    clean_string(confirm_pass, 99);
    clean_string(adress, 99);

    gotoxy(38 + 20, 12);
    scanf("%s", currentpass);
    gotoxy(38 + 20, 14);
    scanf("%s", new_pass);
    gotoxy(38 + 20, 16);
    scanf("%s", confirm_pass);

    genarete_address_from_id(type, running_id, adress);
    strcat(adress, "//pass.txt");
    FILE *ptr;
    ptr = fopen(adress, "r");
    fscanf(ptr, "%s", real_pass);
    fclose(ptr);
    if (comparepassForStudentTeacherEmployee(currentpass, real_pass) && comparepassForStudentTeacherEmployee(new_pass, confirm_pass))
    {
        sucessfullychangepass();
        ptr = fopen(adress, "w");
        fprintf(ptr, "%s", new_pass);
        fclose(ptr);
    }
    else
    {
        if (try_agin())
        {
            return change_password_function(type);
        }
    }
    if (comparepassForStudentTeacherEmployee(type, "student"))
        return StuDent();
    else if (comparepassForStudentTeacherEmployee(type, "teacher"))
    {
        return Teacher();
    }
    else
        return Employee();
}

struct teacher tdataentry()
{
    system("cls");
    fflush(stdin);
    struct teacher ob;
    tdataentryframe();
    int x = 30;
    gotoxy(x, 8);
    printf("ENTER FIRST NAME  :");
    gotoxy(x, 9);
    printf("ENTER LAST NAME   :");
    gotoxy(x, 10);
    printf("ENTER GENDER      :");
    gotoxy(x, 11);
    printf("BLOOD GROUP       :");
    gotoxy(x, 12);
    printf("DEPARTMENT        :");
    gotoxy(x, 13);
    printf("UNIVERSITY        :");
    gotoxy(x, 14);
    printf("CGPA              :");
    gotoxy(x, 15);
    printf("POSITION          :");
    gotoxy(x, 16);
    printf("MOBILE NUMBER     :");
    gotoxy(x, 17);
    printf("E-MAIL            :");
    gotoxy(x, 18);
    printf("PERMANENT ADDRESS :");
    gotoxy(x, 19);
    printf("DATE OF BIRTH (DD | MM | YY): ");
    gotoxy(x, 20);
    printf("JOINING DATE  (DD | MM | YY): ");

    gotoxy(x + 19, 8);
    gets(ob.name1);
    if (strlen(ob.name1) == 0)
        ob.name1[0] = ' ';
    gotoxy(x + 19, 9);
    gets(ob.name2);
    if (strlen(ob.name2) == 0)
        ob.name2[0] = ' ';
    gotoxy(x + 19, 10);
    gets(ob.gender);
    gotoxy(x + 19, 11);
    gets(ob.blood);
    gotoxy(x + 19, 12);
    gets(ob.department);
    gotoxy(x + 19, 13);
    gets(ob.university);
    gotoxy(x + 19, 14);
    gets(ob.cgpa);
    gotoxy(x + 19, 15);
    gets(ob.pos);
    gotoxy(x + 19, 16);
    gets(ob.moblile);
    gotoxy(x + 19, 17);
    gets(ob.email);
    gotoxy(x + 19, 18);
    gets(ob.permanent_add);
    gotoxy(x + 29, 19);
    gets(ob.dob);
    gotoxy(x + 29, 20);
    gets(ob.joiningdate);
    return ob;
}
void t_save_personaldata(struct teacher ob, char add[])
{
    char s[100], s2[100], s3[100];
    clean_string(s, 99);
    clean_string(s2, 99);
    clean_string(s3, 99);
    strcpy(s, add);
    strcpy(s2, add);
    strcpy(s3, add);
    strcat(s, "//pass.txt");
    strcat(add, "//pd.txt");
    strcat(s2, "//chat.txt");
    strcat(s3, "//0.txt");
    FILE *t;
    t = fopen(s3, "w");
    fprintf(t, "Welcome to my chat system...:)\nIftekhar Ahamed Siddiquee..");
    fclose(t);
    FILE *ptr, *ftr, *f;
    ptr = fopen(add, "w");
    fprintf(ptr, "%s\n", ob.id);
    fprintf(ptr, "%s\n", ob.name1);
    if (strlen(ob.name2) == 1 && ob.name2[0] == ' ')
        fprintf(ptr, "%c\n", 'n');
    else
        fprintf(ptr, "%s\n", ob.name2);
    fprintf(ptr, "%s\n", ob.gender);
    fprintf(ptr, "%s\n", ob.blood);
    fprintf(ptr, "%s\n", ob.department);
    fprintf(ptr, "%s\n", ob.university);
    fprintf(ptr, "%s\n", ob.cgpa);
    fprintf(ptr, "%s\n", ob.pos);
    fprintf(ptr, "%s\n", ob.moblile);
    fprintf(ptr, "%s\n", ob.email);
    fprintf(ptr, "%s\n", ob.permanent_add);
    fprintf(ptr, "%s\n", ob.dob);
    fprintf(ptr, "%s\n", ob.joiningdate);
    fclose(ptr);
    ftr = fopen(s, "w");
    fprintf(ftr, "12345\n");
    fclose(ftr);
    f = fopen(s2, "w");
    //fprintf(f,"\n");
    fclose(f);
    after_save_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);
    Admin();
}
void AddNewTeacher()
{
    fflush(stdin);
    struct teacher ob;
    int id;
    clean_string(ob.name1, 99);
    clean_string(ob.name2, 99);
    clean_string(ob.gender, 99);
    clean_string(ob.blood, 99);
    clean_string(ob.department, 99);
    clean_string(ob.university, 99);
    clean_string(ob.university, 99);
    clean_string(ob.cgpa, 99);
    clean_string(ob.pos, 49);
    clean_string(ob.moblile, 99);
    clean_string(ob.email, 99);
    clean_string(ob.permanent_add, 99);
    clean_string(ob.dob, 99);
    clean_string(ob.joiningdate, 99);
    clean_string(ob.id, 99);

    ob = tdataentry();

    if (!wantTosaveframe())
        return Admin();
    id = genareteid("C://UMS(IAS)//data//teacher//status.txt");
    char adress[100], con[11];
    clean_string(adress, 99);
    clean_string(con, 10);
    strcpy(adress, "C://UMS(IAS)//data//teacher//");
    sprintf(con, "%d", id);
    strcpy(ob.id, con);
    strcat(adress, con);
    mkdir(adress);
    t_save_personaldata(ob, adress);
    //printf("%s %s %s %s %s %s %s %s %s\n",name1,name2,gender,blood,department,moblile,email,permanent_add,dob,joiningdate);
}
struct teacher tread_single_pd(char address[])
{
    struct teacher ob;
    int i = 0;
    FILE *ptr;
    ptr = fopen(address, "r");
    fgets(ob.id, 100, ptr);
    clean_n(ob.id);
    fgets(ob.name1, 100, ptr);
    clean_n(ob.name1);
    fgets(ob.name2, 100, ptr);
    if (strlen(ob.name2) == 1 && ob.name2[0] == 'n')
        ob.name2[0] = ' ';
    clean_n(ob.name2);
    fscanf(ptr, "%s", ob.gender);
    fscanf(ptr, "%s", ob.blood);
    fscanf(ptr, "%s", ob.department);
    fscanf(ptr, "%s", ob.university);
    fscanf(ptr, "%s", ob.cgpa);
    fscanf(ptr, "%s", ob.pos);
    fscanf(ptr, "%s", ob.moblile);
    fscanf(ptr, "%s", ob.email);
    fscanf(ptr, "%s", ob.permanent_add);
    fscanf(ptr, "%s", ob.dob);
    fscanf(ptr, "%s", ob.joiningdate);
    /*
    printf("ID = %s\n",ob.id);
    printf("Name = %s %s\n",ob.name1,ob.name2);
    printf("Gender = %s\n",ob.gender);
    printf("Blood = %s\n",ob.blood);
    printf("Department = %s\n",ob.department);
    printf("Mobile = %s\n",ob.moblile);
    printf("email = %s\n",ob.email);
    printf("Address = %s\n",ob.permanent_add);
    printf("DOB = %s\n",ob.dob);
    printf("join date = %s\n",ob.joiningdate);
    */
    fclose(ptr);
    return ob;
}
void tdeleteid(char m[], char a1[], char a2[], char a3[])
{
    struct teacher ob;
    ob = tread_single_pd(a1);
    after_delete_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);

    if (wantTodeleteframe())
    {
        DIR *folder;
        struct dirent *entry;
        int files = 0;
        folder = opendir(m);

        while ((entry = readdir(folder)))
        {
            files++;
            char re[100];
            clean_string(re, 99);
            strcat(re, m);
            strcat(re, "\\");
            strcat(re, entry->d_name);
            //printf("%s",re);
            //getchar();
            remove(re);
        }

        closedir(folder);
        rmdir(m);
        after_delete_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);
    }
    return Admin();
}
void deleteTeacher()
{
    int id;
    char co[10], adress[100], type[] = "teacher", ad2[100], ad3[100], ad4[100];
    clean_string(co, 9);
    clean_string(adress, 99);
    clean_string(ad2, 99);
    clean_string(ad3, 99);
    clean_string(ad4, 99);
    id = enter_id_frame();
    sprintf(co, "%d", id);
    genarete_address_from_id(type, co, adress);
    strcpy(ad2, adress);
    strcpy(ad3, adress);
    strcpy(ad4, adress);
    strcat(ad2, "//pd.txt");
    strcat(ad3, "//pass.txt");
    strcat(ad4, "//chat.txt");
    return tdeleteid(adress, ad2, ad3, ad4);
}

void searchTeacher()
{
    int id;
    char co[10], adress[100], type[] = "teacher";
    clean_string(co, 9);
    clean_string(adress, 99);
    id = enter_id_frame();
    sprintf(co, "%d", id);
    genarete_address_from_id(type, co, adress);
    strcat(adress, "//pd.txt");

    struct teacher ob;
    ob = tread_single_pd(adress);

    seeteacherdataFrame(ob);

    return teacherfunction();
}
void teacherfunction()
{
    fflush(stdin);
    teacher_sectoin_frame();
    int option = 1, x = 52;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 6)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 5;
            break;
        }

        h_light_teacher_function_menu(option);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                return AddNewTeacher();
            case 2:
                return update_personal_data("teacher");
            case 3:
                return deleteTeacher();
            case 4:
                return searchTeacher();
            case 5:
                return Admin();
            default:
                wrong_selection();
                return teacherfunction();
            }
        }
    }
}

struct student sdataentry()
{
    system("cls");
    fflush(stdin);
    struct student ob;
    Sdataentryframe();
    int x = 30;
    gotoxy(x, 8);
    printf("ENTER FIRST NAME  :");
    gotoxy(x, 9);
    printf("ENTER LAST NAME   :");
    gotoxy(x, 10);
    printf("ENTER GENDER      :");
    gotoxy(x, 11);
    printf("BLOOD GROUP       :");
    gotoxy(x, 12);
    printf("DEPARTMENT        :");
    gotoxy(x, 13);
    printf("INTAKE            :");
    gotoxy(x, 14);
    printf("SECTION           :");
    gotoxy(x, 15);
    printf("MOBILE NUMBER     :");
    gotoxy(x, 16);
    printf("E-MAIL            :");
    gotoxy(x, 17);
    printf("PERMANENT ADDRESS :");
    gotoxy(x, 18);
    printf("DATE OF BIRTH (DD | MM | YY): ");
    gotoxy(x, 19);
    printf("JOINING DATE  (DD | MM | YY): ");

    gotoxy(x + 19, 8);
    gets(ob.name1);
    if (strlen(ob.name1) == 0)
        ob.name1[0] = ' ';
    gotoxy(x + 19, 9);
    gets(ob.name2);
    if (strlen(ob.name2) == 0)
        ob.name2[0] = ' ';
    gotoxy(x + 19, 10);
    gets(ob.gender);
    gotoxy(x + 19, 11);
    gets(ob.blood);
    gotoxy(x + 19, 12);
    gets(ob.department);
    gotoxy(x + 19, 13);
    gets(ob.intake);
    gotoxy(x + 19, 14);
    gets(ob.sec);
    gotoxy(x + 19, 15);
    gets(ob.moblile);
    gotoxy(x + 19, 16);
    gets(ob.email);
    gotoxy(x + 19, 17);
    gets(ob.permanent_add);
    gotoxy(x + 29, 18);
    gets(ob.dob);
    gotoxy(x + 29, 19);
    gets(ob.joiningdate);
    return ob;
}
void s_save_personaldata(struct student ob, char add[])
{
    char s[100], s2[100], s3[100], s4[100];
    clean_string(s, 99);
    clean_string(s2, 99);
    clean_string(s3, 99);
    clean_string(s4, 99);
    strcpy(s, add);
    strcpy(s2, add);
    strcpy(s3, add);
    strcpy(s4, add);
    strcat(s, "//pass.txt");
    strcat(add, "//pd.txt");
    strcat(s2, "//chat.txt");
    strcat(s3, "//0.txt");
    strcat(s4, "//course.txt");
    FILE *t;
    t = fopen(s3, "w");
    fprintf(t, "Welcome to my chat system...:)\nIftekhar Ahamed Siddiquee..");
    fclose(t);
    FILE *ptr, *ftr, *f;
    ptr = fopen(add, "w");
    fprintf(ptr, "%s\n", ob.id);
    fprintf(ptr, "%s\n", ob.name1);
    if (strlen(ob.name2) == 1 && ob.name2[0] == ' ')
        fprintf(ptr, "%c\n", 'n');
    else
        fprintf(ptr, "%s\n", ob.name2);
    fprintf(ptr, "%s\n", ob.gender);
    fprintf(ptr, "%s\n", ob.blood);
    fprintf(ptr, "%s\n", ob.department);
    fprintf(ptr, "%s\n", ob.intake);
    fprintf(ptr, "%s\n", ob.sec);
    fprintf(ptr, "%s\n", ob.moblile);
    fprintf(ptr, "%s\n", ob.email);
    fprintf(ptr, "%s\n", ob.permanent_add);
    fprintf(ptr, "%s\n", ob.dob);
    fprintf(ptr, "%s\n", ob.joiningdate);
    fclose(ptr);
    ftr = fopen(s, "w");
    fprintf(ftr, "12345\n");
    fclose(ftr);
    f = fopen(s2, "w");
    //fprintf(f,"0\n");
    fclose(f);
    ftr = fopen(s4, "w");
    fprintf(ftr, "1\n");
    fclose(ftr);
    after_save_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);
    Admin();
}
void AddNewStudent()
{
    fflush(stdin);
    struct student ob;
    int id;
    clean_string(ob.name1, 99);
    clean_string(ob.name2, 99);
    clean_string(ob.gender, 99);
    clean_string(ob.blood, 99);
    clean_string(ob.department, 99);
    clean_string(ob.moblile, 99);
    clean_string(ob.email, 99);
    clean_string(ob.permanent_add, 99);
    clean_string(ob.dob, 99);
    clean_string(ob.joiningdate, 99);
    clean_string(ob.id, 99);
    clean_string(ob.intake, 49);
    clean_string(ob.sec, 9);

    ob = sdataentry();

    if (!wantTosaveframe())
        return Admin();

    id = genareteid("C://UMS(IAS)//data//student//status.txt");
    char adress[100], con[11];
    clean_string(con, 10);
    clean_string(adress, 99);
    strcpy(adress, "C://UMS(IAS)//data//student//");
    sprintf(con, "%d", id);
    strcpy(ob.id, con);
    strcat(adress, con);
    mkdir(adress);

    s_save_personaldata(ob, adress);
    //printf("%s %s %s %s %s %s %s %s %s\n",name1,name2,gender,blood,department,moblile,email,permanent_add,dob,joiningdate);
}

struct student sread_single_pd(char address[])
{
    struct student ob;
    int i = 0;
    FILE *ptr;
    ptr = fopen(address, "r");
    fgets(ob.id, 100, ptr);
    clean_n(ob.id);
    fgets(ob.name1, 100, ptr);
    clean_n(ob.name1);
    fgets(ob.name2, 100, ptr);
    if (strlen(ob.name2) == 1 && ob.name2[0] == 'n')
        ob.name2[0] = ' ';
    clean_n(ob.name2);
    fscanf(ptr, "%s", ob.gender);
    fscanf(ptr, "%s", ob.blood);
    fscanf(ptr, "%s", ob.department);
    fscanf(ptr, "%s", ob.intake);
    fscanf(ptr, "%s", ob.sec);
    fscanf(ptr, "%s", ob.moblile);
    fscanf(ptr, "%s", ob.email);
    fscanf(ptr, "%s", ob.permanent_add);
    fscanf(ptr, "%s", ob.dob);
    fscanf(ptr, "%s", ob.joiningdate);
    fclose(ptr);
    return ob;
}
void sdeleteid(char m[], char a1[])
{
    struct student ob;
    ob = sread_single_pd(a1);
    after_delete_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);

    if (wantTodeleteframe())
    {
        DIR *folder;
        struct dirent *entry;
        int files = 0;
        folder = opendir(m);

        while ((entry = readdir(folder)))
        {
            files++;
            char re[100];
            clean_string(re, 99);
            strcat(re, m);
            strcat(re, "\\");
            strcat(re, entry->d_name);
            //printf("%s",re);
            //getchar();
            remove(re);
        }

        closedir(folder);
        rmdir(m);
        after_delete_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);
    }
    return Admin();
}
void deletestudent()
{
    int id;
    char co[10], adress[100], type[] = "student", ad2[100], ad3[100], ad4[100];
    clean_string(co, 9);
    clean_string(adress, 99);
    clean_string(ad2, 99);
    clean_string(ad3, 99);
    clean_string(ad4, 99);
    id = enter_id_frame();
    sprintf(co, "%d", id);
    genarete_address_from_id(type, co, adress);
    strcpy(ad2, adress);
    //    strcpy(ad3,adress);
    //    strcpy(ad4,adress);
    strcat(ad2, "//pd.txt");
    //    strcat(ad3,"//pass.txt");
    //    strcat(ad4,"//chat.txt");
    return sdeleteid(adress, ad2);
}
void searchstudent()
{
    int id;
    char co[10], adress[100], type[] = "student";
    clean_string(co, 9);
    clean_string(adress, 99);
    id = enter_id_frame();
    sprintf(co, "%d", id);
    genarete_address_from_id(type, co, adress);
    strcat(adress, "//pd.txt");

    struct student ob;
    ob = sread_single_pd(adress);

    seestudentdataFrame(ob);

    return studentfunction();
}

void studentfunction()
{
    fflush(stdin);
    student_section_frame();
    int option = 1, x = 52;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 6)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 5;
            break;
        }

        h_light_student_function_menu(option);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                return AddNewStudent();
            case 2:
                return update_personal_data("student");
            case 3:
                return deletestudent();
            case 4:
                return searchstudent();
            case 5:
                return Admin();
                ;
            default:
                wrong_selection();
                return studentfunction();
            }
        }
    }
}

struct EMPLOYEE edataentry()
{
    system("cls");
    fflush(stdin);
    struct EMPLOYEE ob;
    Edataentryframe();
    int x = 30;
    gotoxy(x, 8);
    printf("ENTER FIRST NAME  :");
    gotoxy(x, 9);
    printf("ENTER LAST NAME   :");
    gotoxy(x, 10);
    printf("ENTER GENDER      :");
    gotoxy(x, 11);
    printf("BLOOD GROUP       :");
    gotoxy(x, 12);
    printf("DEPARTMENT        :");
    gotoxy(x, 13);
    printf("UNIVERSITY        :");
    gotoxy(x, 14);
    printf("CGPA              :");
    gotoxy(x, 15);
    printf("POSITION          :");
    gotoxy(x, 16);
    printf("MOBILE NUMBER     :");
    gotoxy(x, 17);
    printf("E-MAIL            :");
    gotoxy(x, 18);
    printf("PERMANENT ADDRESS :");
    gotoxy(x, 19);
    printf("DATE OF BIRTH (DD | MM | YY): ");
    gotoxy(x, 20);
    printf("JOINING DATE  (DD | MM | YY): ");

    gotoxy(x + 19, 8);
    gets(ob.name1);
    if (strlen(ob.name1) == 0)
        ob.name1[0] = ' ';
    gotoxy(x + 19, 9);
    gets(ob.name2);
    if (strlen(ob.name2) == 0)
        ob.name2[0] = ' ';
    gotoxy(x + 19, 10);
    gets(ob.gender);
    gotoxy(x + 19, 11);
    gets(ob.blood);
    gotoxy(x + 19, 12);
    gets(ob.department);
    gotoxy(x + 19, 13);
    gets(ob.university);
    gotoxy(x + 19, 14);
    gets(ob.cgpa);
    gotoxy(x + 19, 15);
    gets(ob.pos);
    gotoxy(x + 19, 16);
    gets(ob.moblile);
    gotoxy(x + 19, 17);
    gets(ob.email);
    gotoxy(x + 19, 18);
    gets(ob.permanent_add);
    gotoxy(x + 29, 19);
    gets(ob.dob);
    gotoxy(x + 29, 20);
    gets(ob.joiningdate);
    return ob;
}

void e_save_personaldata(struct EMPLOYEE ob, char add[])
{
    char s[100], s2[100], s3[100];
    clean_string(s, 99);
    clean_string(s2, 99);
    clean_string(s3, 99);
    strcpy(s, add);
    strcpy(s2, add);
    strcpy(s3, add);
    strcat(s, "//pass.txt");
    strcat(add, "//pd.txt");
    strcat(s2, "//chat.txt");
    strcat(s3, "//0.txt");
    FILE *t;
    t = fopen(s3, "w");
    fprintf(t, "Welcome to my chat system...:)\nIftekhar Ahamed Siddiquee..");
    fclose(t);
    FILE *ptr, *ftr, *f;
    ptr = fopen(add, "w");
    fprintf(ptr, "%s\n", ob.id);
    fprintf(ptr, "%s\n", ob.name1);
    if (strlen(ob.name2) == 1 && ob.name2[0] == ' ')
        fprintf(ptr, "%c\n", 'n');
    else
        fprintf(ptr, "%s\n", ob.name2);
    fprintf(ptr, "%s\n", ob.gender);
    fprintf(ptr, "%s\n", ob.blood);
    fprintf(ptr, "%s\n", ob.department);
    fprintf(ptr, "%s\n", ob.university);
    fprintf(ptr, "%s\n", ob.cgpa);
    fprintf(ptr, "%s\n", ob.pos);
    fprintf(ptr, "%s\n", ob.moblile);
    fprintf(ptr, "%s\n", ob.email);
    fprintf(ptr, "%s\n", ob.permanent_add);
    fprintf(ptr, "%s\n", ob.dob);
    fprintf(ptr, "%s\n", ob.joiningdate);
    fclose(ptr);
    ftr = fopen(s, "w");
    fprintf(ftr, "12345\n");
    fclose(ftr);
    f = fopen(s2, "w");
    //fprintf(f,"0\n");
    fclose(f);
    after_save_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);
    Admin();
}

void AddNewEmployee()
{
    fflush(stdin);
    struct EMPLOYEE ob;
    int id;
    clean_string(ob.name1, 99);
    clean_string(ob.name2, 99);
    clean_string(ob.gender, 99);
    clean_string(ob.blood, 99);
    clean_string(ob.department, 99);
    clean_string(ob.university, 99);
    clean_string(ob.university, 99);
    clean_string(ob.cgpa, 99);
    clean_string(ob.pos, 49);
    clean_string(ob.moblile, 99);
    clean_string(ob.email, 99);
    clean_string(ob.permanent_add, 99);
    clean_string(ob.dob, 99);
    clean_string(ob.joiningdate, 99);
    clean_string(ob.id, 99);

    ob = edataentry();

    if (!wantTosaveframe())
        return Admin();
    id = genareteid("C://UMS(IAS)//data//employee//status.txt");

    char adress[100], con[11];
    clean_string(con, 10);
    clean_string(adress, 99);
    strcpy(adress, "C://UMS(IAS)//data//employee//");
    sprintf(con, "%d", id);
    strcpy(ob.id, con);
    strcat(adress, con);
    mkdir(adress);

    e_save_personaldata(ob, adress);
    //printf("%s %s %s %s %s %s %s %s %s\n",name1,name2,gender,blood,department,moblile,email,permanent_add,dob,joiningdate);
}

struct EMPLOYEE eread_single_pd(char address[])
{
    struct EMPLOYEE ob;
    int i = 0;
    char c;
    FILE *ptr;
    ptr = fopen(address, "r");
    fgets(ob.id, 100, ptr);
    clean_n(ob.id);
    fgets(ob.name1, 100, ptr);
    clean_n(ob.name1);
    fgets(ob.name2, 100, ptr);
    if (strlen(ob.name2) == 1 && ob.name2[0] == 'n')
        ob.name2[0] = ' ';
    clean_n(ob.name2);
    fscanf(ptr, "%s", ob.gender);
    fscanf(ptr, "%s", ob.blood);
    fscanf(ptr, "%c", &c);
    fgets(ob.department, 100, ptr);
    clean_n(ob.department);
    fscanf(ptr, "%c", &c);
    fgets(ob.university, 100, ptr);
    clean_n(ob.university);
    fscanf(ptr, "%s", ob.cgpa);
    fscanf(ptr, "%c", &c);
    fgets(ob.pos, 100, ptr);
    clean_n(ob.pos);
    fscanf(ptr, "%s", ob.moblile);
    fscanf(ptr, "%s", ob.email);
    fscanf(ptr, "%s", ob.permanent_add);
    fscanf(ptr, "%s", ob.dob);
    fscanf(ptr, "%s", ob.joiningdate);
    /*
    printf("ID = %s\n",ob.id);
    printf("Name = %s %s\n",ob.name1,ob.name2);
    printf("Gender = %s\n",ob.gender);
    printf("Blood = %s\n",ob.blood);
    printf("Department = %s\n",ob.department);
    printf("Mobile = %s\n",ob.moblile);
    printf("email = %s\n",ob.email);
    printf("Address = %s\n",ob.permanent_add);
    printf("DOB = %s\n",ob.dob);
    printf("join date = %s\n",ob.joiningdate);
    */
    fclose(ptr);
    return ob;
}

void edeleteid(char m[], char a1[], char a2[], char a3[])
{
    struct EMPLOYEE ob;
    ob = eread_single_pd(a1);
    after_delete_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);

    if (wantTodeleteframe())
    {
        DIR *folder;
        struct dirent *entry;
        int files = 0;
        folder = opendir(m);

        while ((entry = readdir(folder)))
        {
            files++;
            char re[100];
            clean_string(re, 99);
            strcat(re, m);
            strcat(re, "\\");
            strcat(re, entry->d_name);
            remove(re);
        }

        closedir(folder);
        rmdir(m);
        after_delete_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);
    }
    return Admin();
}

void deleteEmployee()
{
    int id;
    char co[10], adress[100], type[] = "employee", ad2[100], ad3[100], ad4[100];
    clean_string(co, 9);
    clean_string(adress, 99);
    clean_string(ad2, 99);
    clean_string(ad3, 99);
    clean_string(ad4, 99);
    id = enter_id_frame();
    sprintf(co, "%d", id);
    genarete_address_from_id(type, co, adress);
    strcpy(ad2, adress);
    strcpy(ad3, adress);
    strcpy(ad4, adress);
    strcat(ad2, "//pd.txt");
    strcat(ad3, "//pass.txt");
    strcat(ad4, "//chat.txt");
    return edeleteid(adress, ad2, ad3, ad4);
}
void searchemployee()
{
    int id;
    char co[10], adress[100], type[] = "employee";
    clean_string(co, 9);
    clean_string(adress, 99);
    id = enter_id_frame();
    sprintf(co, "%d", id);
    genarete_address_from_id(type, co, adress);
    strcat(adress, "//pd.txt");

    struct EMPLOYEE ob;
    ob = eread_single_pd(adress);

    seeemployeedataFrame(ob);

    return employeefunction();
}
void employeefunction()
{
    fflush(stdin);
    employee_section_frame();
    int option = 1, x = 52;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 6)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 5;
            break;
        }

        h_light_employee_function_menu(option);
        ch = getch();
        if (ch == 13)
        {

            switch (option)
            {
            case 1:
                return AddNewEmployee();
            case 2:
                return update_personal_data("employee");
            case 3:
                return deleteEmployee();
            case 4:
                return searchemployee();
            case 5:
                return Admin();
                ;
            default:
                wrong_selection();
                return employeefunction();
            }
        }
    }
}

bool Admin_login()
{
    system("cls");
    long long int id, m_id;
    char ch[20], m_pass[20];
    clean_string(ch, 19);
    clean_string(m_pass, 19);
    longinframe(ch, &id);
    char address[] = "C://UMS(IAS)//data//admin//pass.txt";
    readpass(address, &m_id, m_pass);
    system("cls");
    if (comparepass(m_pass, ch, m_id, id))
        return true;
    else
    {
        if (try_agin())
            return Admin_login();
        else
            return false;
    }
    return true;
}

bool Employee_login()
{

    fflush(stdin);
    system("cls");
    long long int id, m_id;
    char ch[20], m_pass[20], address[100];
    clean_string(address, 99);
    clean_string(ch, 19);
    clean_string(m_pass, 19);

    longinframe(m_pass, &id);
    sprintf(ch, "%lld", id);

    clean_string(running_id, 20);
    strcpy(running_id, ch);

    genarete_address_from_id("employee", ch, address);

    strcat(address, "//pass.txt");

    clean_string(ch, 19);
    readpassForStudentTeacherEmployee(address, ch);
    system("cls");
    if (comparepassForStudentTeacherEmployee(m_pass, ch))
        return true;
    else
    {
        if (try_agin())
            return Employee_login();
        else
            return false;
    }
}
bool student_login()
{
    fflush(stdin);
    system("cls");
    long long int id, m_id;
    char ch[20], m_pass[20], address[100];
    clean_string(address, 99);
    clean_string(ch, 19);
    clean_string(m_pass, 19);

    longinframe(m_pass, &id);
    sprintf(ch, "%lld", id);

    clean_string(running_id, 20);
    strcpy(running_id, ch);

    genarete_address_from_id("student", ch, address);

    strcat(address, "//pass.txt");

    clean_string(ch, 19);
    readpassForStudentTeacherEmployee(address, ch);
    system("cls");
    if (comparepassForStudentTeacherEmployee(m_pass, ch))
        return true;
    else
    {
        if (try_agin())
            return student_login();
        else
            return false;
    }
}

bool teacher_login()
{
    fflush(stdin);
    system("cls");
    long long int id, m_id;
    char ch[20], m_pass[20], address[100];
    clean_string(address, 99);
    clean_string(ch, 19);
    clean_string(m_pass, 19);

    longinframe(m_pass, &id);
    sprintf(ch, "%lld", id);

    clean_string(running_id, 20);
    strcpy(running_id, ch);

    genarete_address_from_id("teacher", ch, address);

    strcat(address, "//pass.txt");

    clean_string(ch, 19);
    readpassForStudentTeacherEmployee(address, ch);
    system("cls");
    if (comparepassForStudentTeacherEmployee(m_pass, ch))
        return true;
    else
    {
        if (try_agin())
            return teacher_login();
        else
            return false;
    }
}

void writeincourse(char add[], char status[])
{
    int n, i = 0;
    n = enter_n_course_frame();
    struct subject sub[n];
    while (i < n)
    {
        sub[i] = enter_course_frame(i);
        //printf("%d %s\n",sub[i].code,sub[i].name);
        i++;
    }
    FILE *ptr, *ftr;

    ftr = fopen(status, "w");
    fprintf(ftr, "%d", n);
    fclose(ftr);

    ptr = fopen(add, "w");
    i = 0;
    while (i < n)
    {
        fprintf(ptr, "%d\n", sub[i].code);
        fputs(sub[i].name, ptr);
        fprintf(ptr, "\n", ptr);
        i++;
    }
    fclose(ptr);
    update_course_frame(sub, n);
    return Admin();
}
void present_courses(char add[], char status[])
{
    int n, i = 0;
    FILE *ptr, *ftr;
    struct subject sub1[2];
    ftr = fopen(status, "r");
    if (ftr == NULL)
    {
        fclose(ftr);
        currtent_course_frame(sub1, 0);
    }
    else
    {
        fscanf(ftr, "%d", &n);
        struct subject sub[n];
        fclose(ftr);
        ptr = fopen(add, "r");
        while (fscanf(ptr, "%d", &sub[i].code) != EOF)
        {
            char c;
            fscanf(ptr, "%c", &c);
            fgets(sub[i].name, 100, ptr);
            clean_n(sub[i].name);
            i++;
        }
        currtent_course_frame(sub, n);
    }
}
void currentcourse(char add[], char status[], bool flag)
{
    present_courses(add, status);
    if (flag)
        return writeincourse(add, status);
    else
        return Admin();
}
void updateCourse(bool flag)
{
    char ad[100], intake[100];
    clean_string(intake, 99);
    clean_string(ad, 99);
    batch(intake);
    strcat(ad, "C://UMS(IAS)//data//course//");
    strcat(ad, intake);
    clean_string(intake, 99);
    strcpy(intake, ad);
    strcat(intake, "//status.txt");
    if (flag)
    {
        FILE *ptr;
        ptr = fopen(intake, "r");
        if (ptr == NULL)
        {
            mkdir(ad);
        }
        fclose(ptr);
    }
    strcat(ad, "//course.txt");
    return currentcourse(ad, intake, flag);
}

void read_reciver_sender_name(char from[], char to[], char r_id[], char name1[], char name2[])
{
    char adress1[100], adress2[100];
    clean_string(adress1, 99);
    clean_string(adress2, 99);

    strcat(adress1, "C://UMS(IAS)//data//");
    strcat(adress1, from);
    strcat(adress1, "//");
    strcat(adress1, running_id);
    strcat(adress1, "//pd.txt");

    strcat(adress2, "C://UMS(IAS)//data//");
    strcat(adress2, to);
    strcat(adress2, "//");
    strcat(adress2, r_id);
    strcat(adress2, "//pd.txt");

    if (comparepassForStudentTeacherEmployee(from, "student") && comparepassForStudentTeacherEmployee(to, "teacher"))
    {
        struct student ob = sread_single_pd(adress1);
        strcat(name1, ob.name1);
        strcat(name1, " ");
        strcat(name1, ob.name2);
        struct teacher ob2 = tread_single_pd(adress2);
        strcat(name2, ob2.name1);
        strcat(name2, " ");
        strcat(name2, ob2.name2);
    }
    else if (comparepassForStudentTeacherEmployee(from, "teacher") && comparepassForStudentTeacherEmployee(to, "student"))
    {
        struct student ob = sread_single_pd(adress2);
        strcat(name2, ob.name1);
        strcat(name2, " ");
        strcat(name2, ob.name2);
        struct teacher ob2 = tread_single_pd(adress1);
        strcat(name1, ob2.name1);
        strcat(name1, " ");
        strcat(name1, ob2.name2);
    }
    else
    {
        puts("BUG");
    }
}

void message_list(struct messege ob[], int n, char type[])
{
    fflush(stdin);
    system("cls");
    char adress[100];
    char sender_name[100];
    clean_string(sender_name, 99);
    clean_string(adress, 99);
    genarete_address_from_id(type, running_id, adress);
    strcat(adress, "//pd.txt");
    if (comparepassForStudentTeacherEmployee(type, "student"))
    {
        struct student ob = sread_single_pd(adress);
        strcat(sender_name, ob.name1);
        strcat(sender_name, " ");
        strcat(sender_name, ob.name2);
    }
    else if (comparepassForStudentTeacherEmployee(type, "teacher"))
    {
        struct teacher ob = tread_single_pd(adress);
        strcat(sender_name, ob.name1);
        strcat(sender_name, " ");
        strcat(sender_name, ob.name2);
    }
    int option;
    gotoxy(47, 9);
    puts("**MESSAGES**");
    gotoxy(25, 6);
    printf("######################             ####################\n");
    for (int i = 0; i < n + 8; i++)
        printf("\t\t\t#\t\t\t\t\t\t\t#\n");
    gotoxy(25, n + 15);
    printf(" #####################             #################### \n");
    int j = 0, i, k = 1;
    for (i = 11, j = 0; i < n + 11; i++, k++)
    {

        gotoxy(40, i);
        if (comparepassForStudentTeacherEmployee(sender_name, ob[i - 11].name1))
        {
            printf("[%.2d] %s\n", k, ob[i - 11].name2);
        }
        else
        {
            printf("[%.2d] %s\n", k, ob[i - 11].name1);
        }
    }
    gotoxy(40, i);
    printf("[%.2d] EXIT.\n", k);
    gotoxy(44, i + 2);
    printf("ENTER YOUR OPTION :");
    scanf("%d", &option);
    if (option > n + 1 || option < 1)
    {
        wrong_selection();
        return message_list(ob, n, type);
    }
    else if (option == n + 1)
        return;
    message_body(ob[option - 1]);
    return message_list(ob, n, type);
}
void send_message(char from[], char to[], char body[], char p1[], char p2[], char t_id[])
{
    fflush(stdin);
    char adress[100];
    clean_string(adress, 99);
    if (wantTosendframe())
    {
        strcat(adress, "C://UMS(IAS)//data//chat//");
        strcat(adress, from);
        strcat(adress, running_id);
        strcat(adress, t_id);
        strcat(adress, to);
        strcat(adress, ".txt");
        FILE *ptr;
        ptr = fopen(adress, "w");
        fprintf(ptr, "%s\n", p1);
        fprintf(ptr, "%s\n", p2);
        fprintf(ptr, "%s\n", p1);
        fprintf(ptr, "%s\n", body);
        fclose(ptr);

        char s1[100];
        clean_string(s1, 99);
        strcat(s1, "C://UMS(IAS)//data//");
        strcat(s1, to);
        strcat(s1, "//");
        strcat(s1, t_id);
        strcat(s1, "//chat.txt");
        ptr = fopen(s1, "a+");
        fprintf(ptr, "%s ", adress);
        fclose(ptr);

        clean_string(s1, 99);
        strcat(s1, "C://UMS(IAS)//data//");
        strcat(s1, from);
        strcat(s1, "//");
        strcat(s1, running_id);
        strcat(s1, "//chat.txt");
        ptr = fopen(s1, "a+");
        fprintf(ptr, "%s ", adress);
        fclose(ptr);

        sucessfullysendframe();
    }
    return messenger_function(from, to);
}
void view_message(char type[])
{
    char adress[100], adress2[100];
    clean_string(adress, 99);
    clean_string(adress2, 99);
    strcat(adress, "C://UMS(IAS)//data//");
    strcat(adress, type);
    strcat(adress, "//");
    strcat(adress, running_id);
    strcat(adress, "//chat.txt");
    FILE *ptr;
    ptr = fopen(adress, "r");
    struct messege ob[1000];
    int i = 0;

    while (fscanf(ptr, "%s", adress2) != EOF)
    {
        strcpy(ob[i].index, adress2);
        FILE *ftr;
        ftr = fopen(adress2, "r");
        fgets(ob[i].name1, 100, ftr);
        clean_n(ob[i].name1);
        fgets(ob[i].name2, 100, ftr);
        clean_n(ob[i].name2);
        fclose(ftr);
        clean_string(adress2, 99);
        i++;
    }
    int n = i;
    return message_list(ob, n, type);
}

void messenger_function(char from[], char to[])
{
    int option = 1;
    char ch = '0';
    messenger_frame();
    gotoxy(54, 12);
    printf("WELCOME TO MESSENGER\n");

    char body[1000], p1[100], p2[100], t_id[100];

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 4)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 3;
            break;
        }

        h_light_messenger_menu(option);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                view_message(from);
                return messenger_function(from, to);
            case 2:
                clean_string(t_id, 99);
                clean_string(p1, 99);
                clean_string(p2, 99);
                clean_string(body, 999);

                int id = enter_id_frame();
                sprintf(t_id, "%d", id);

                read_reciver_sender_name(from, to, t_id, p1, p2);

                write_new_message(body);
                send_message(from, to, body, p1, p2, t_id);
                return messenger_function(from, to);
            case 3:
                if (comparepassForStudentTeacherEmployee(from, "student"))
                    return StuDent();
                else
                    return Teacher();
            default:
                wrong_selection();
                return messenger_function(from, to);
            }
        }
    }
}

void e_save_update_data(struct EMPLOYEE ob, char adress[])
{
    FILE *ptr;
    ptr = fopen(adress, "w");
    fprintf(ptr, "%s\n", ob.id);
    fprintf(ptr, "%s\n", ob.name1);
    if (strlen(ob.name2) == 1 && ob.name2[0] == ' ')
        fprintf(ptr, "%c\n", 'n');
    else
        fprintf(ptr, "%s\n", ob.name2);
    fprintf(ptr, "%s\n", ob.gender);
    fprintf(ptr, "%s\n", ob.blood);
    fprintf(ptr, "%s\n", ob.department);
    fprintf(ptr, "%s\n", ob.university);
    fprintf(ptr, "%s\n", ob.cgpa);
    fprintf(ptr, "%s\n", ob.pos);
    fprintf(ptr, "%s\n", ob.moblile);
    fprintf(ptr, "%s\n", ob.email);
    fprintf(ptr, "%s\n", ob.permanent_add);
    fprintf(ptr, "%s\n", ob.dob);
    fprintf(ptr, "%s\n", ob.joiningdate);
    fclose(ptr);
    Admin();
}
void main_employee_upadte_function(struct EMPLOYEE ob, char adress[])
{

    int option = 1, x = 52;
    char ch = ' ';
    h_light_employee_update_helper_frame();
    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 14)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 13;
            break;
        }

        h_light_employee_update_frame(option, ob);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                data_entry_frame("FIRST NAME", ob.name1);
                h_light_employee_update_helper_frame();
                break;
            case 2:
                data_entry_frame("LAST NAME", ob.name2);
                h_light_employee_update_helper_frame();
                break;
            case 3:
                data_entry_frame("ADDRESS", ob.permanent_add);
                h_light_employee_update_helper_frame();
                break;
            case 4:
                data_entry_frame("GENDER", ob.gender);
                h_light_employee_update_helper_frame();
                break;
            case 5:
                data_entry_frame("CONTACT NUMBER", ob.moblile);
                h_light_employee_update_helper_frame();
                break;
            case 6:
                data_entry_frame("DOB", ob.dob);
                h_light_employee_update_helper_frame();
                break;
            case 7:
                data_entry_frame("BLOOD GROUP", ob.blood);
                h_light_employee_update_helper_frame();
                break;
            case 8:
                data_entry_frame("DEPARTMENT", ob.department);
                h_light_employee_update_helper_frame();
                break;
            case 9:
                data_entry_frame("E-MAIL", ob.email);
                h_light_employee_update_helper_frame();
                break;
            case 10:
                data_entry_frame("UNIVERSITY", ob.university);
                h_light_employee_update_helper_frame();
                break;
            case 11:
                data_entry_frame("POSITION", ob.pos);
                h_light_employee_update_helper_frame();
                break;
            case 12:
                data_entry_frame("CGPA", ob.cgpa);
                h_light_employee_update_helper_frame();
                break;
            case 13:
                return e_save_update_data(ob, adress);
            }
        }
    }
}
void t_save_update_data(struct teacher ob, char adress[])
{
    FILE *ptr;
    ptr = fopen(adress, "w");
    fprintf(ptr, "%s\n", ob.id);
    fprintf(ptr, "%s\n", ob.name1);
    if (strlen(ob.name2) == 1 && ob.name2[0] == ' ')
        fprintf(ptr, "%c\n", 'n');
    else
        fprintf(ptr, "%s\n", ob.name2);
    fprintf(ptr, "%s\n", ob.gender);
    fprintf(ptr, "%s\n", ob.blood);
    fprintf(ptr, "%s\n", ob.department);
    fprintf(ptr, "%s\n", ob.university);
    fprintf(ptr, "%s\n", ob.cgpa);
    fprintf(ptr, "%s\n", ob.pos);
    fprintf(ptr, "%s\n", ob.moblile);
    fprintf(ptr, "%s\n", ob.email);
    fprintf(ptr, "%s\n", ob.permanent_add);
    fprintf(ptr, "%s\n", ob.dob);
    fprintf(ptr, "%s\n", ob.joiningdate);
    fclose(ptr);
    Admin();
}
void main_teacher_upadte_function(struct teacher ob, char adress[])
{

    int option = 1, x = 52;
    char ch = ' ';
    h_light_teacher_update_helper_frame();
    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 14)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 13;
            break;
        }

        h_light_teacher_update_frame(option, ob);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                data_entry_frame("FIRST NAME", ob.name1);
                h_light_teacher_update_helper_frame();
                break;
            case 2:
                data_entry_frame("LAST NAME", ob.name2);
                h_light_teacher_update_helper_frame();
                break;
            case 3:
                data_entry_frame("ADDRESS", ob.permanent_add);
                h_light_teacher_update_helper_frame();
                break;
            case 4:
                data_entry_frame("GENDER", ob.gender);
                h_light_teacher_update_helper_frame();
                break;
            case 5:
                data_entry_frame("CONTACT NUMBER", ob.moblile);
                h_light_teacher_update_helper_frame();
                break;
            case 6:
                data_entry_frame("DOB", ob.dob);
                h_light_teacher_update_helper_frame();
                break;
            case 7:
                data_entry_frame("BLOOD GROUP", ob.blood);
                h_light_teacher_update_helper_frame();
                break;
            case 8:
                data_entry_frame("DEPARTMENT", ob.department);
                h_light_teacher_update_helper_frame();
                break;
            case 9:
                data_entry_frame("E-MAIL", ob.email);
                h_light_teacher_update_helper_frame();
                break;
            case 10:
                data_entry_frame("UNIVERSITY", ob.university);
                h_light_teacher_update_helper_frame();
                break;
            case 11:
                data_entry_frame("POSITION", ob.pos);
                h_light_teacher_update_helper_frame();
                break;
            case 12:
                data_entry_frame("CGPA", ob.cgpa);
                h_light_teacher_update_helper_frame();
                break;
            case 13:
                return t_save_update_data(ob, adress);
            }
        }
    }
}

void s_save_update_data(struct student ob, char adress[])
{
    FILE *ptr;
    ptr = fopen(adress, "w");
    fprintf(ptr, "%s\n", ob.id);
    fprintf(ptr, "%s\n", ob.name1);
    if (strlen(ob.name2) == 1 && ob.name2[0] == ' ')
        fprintf(ptr, "%c\n", 'n');
    else
        fprintf(ptr, "%s\n", ob.name2);
    fprintf(ptr, "%s\n", ob.gender);
    fprintf(ptr, "%s\n", ob.blood);
    fprintf(ptr, "%s\n", ob.department);
    fprintf(ptr, "%s\n", ob.intake);
    fprintf(ptr, "%s\n", ob.sec);
    fprintf(ptr, "%s\n", ob.moblile);
    fprintf(ptr, "%s\n", ob.email);
    fprintf(ptr, "%s\n", ob.permanent_add);
    fprintf(ptr, "%s\n", ob.dob);
    fprintf(ptr, "%s\n", ob.joiningdate);
    fclose(ptr);
    after_save_frame(ob.id, ob.name1, ob.name2, ob.gender, ob.dob, ob.joiningdate);
    Admin();
}
void main_student_upadte_function(struct student ob, char adress[])
{

    int option = 1, x = 52;
    char ch = ' ';
    h_light_student_update_helper_frame();
    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 13)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 12;
            break;
        }

        h_light_student_update_frame(option, ob);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                data_entry_frame("FIRST NAME", ob.name1);
                h_light_student_update_helper_frame();
                break;
            case 2:
                data_entry_frame("LAST NAME", ob.name2);
                h_light_student_update_helper_frame();
                break;
            case 3:
                data_entry_frame("ADDRESS", ob.permanent_add);
                h_light_student_update_helper_frame();
                break;
            case 4:
                data_entry_frame("GENDER", ob.gender);
                h_light_student_update_helper_frame();
                break;
            case 5:
                data_entry_frame("CONTACT NUMBER", ob.moblile);
                h_light_student_update_helper_frame();
                break;
            case 6:
                data_entry_frame("DOB", ob.dob);
                h_light_student_update_helper_frame();
                break;
            case 7:
                data_entry_frame("BLOOD GROUP", ob.blood);
                h_light_student_update_helper_frame();
                break;
            case 8:
                data_entry_frame("DEPARTMENT", ob.department);
                h_light_student_update_helper_frame();
                break;
            case 9:
                data_entry_frame("E-MAIL", ob.email);
                h_light_student_update_helper_frame();
                break;
            case 10:
                data_entry_frame("SECTION", ob.sec);
                h_light_student_update_helper_frame();
                break;
            case 11:
                data_entry_frame("INTAKE", ob.intake);
                h_light_student_update_helper_frame();
                break;
            case 12:
                return s_save_update_data(ob, adress);
            }
        }
    }
}

void update_personal_data(char type[])
{
    fflush(stdin);
    int id;
    char co[10], adress[100];
    clean_string(co, 9);
    clean_string(adress, 99);
    id = enter_id_frame();
    sprintf(co, "%d", id);
    genarete_address_from_id(type, co, adress);
    strcat(adress, "//pd.txt");
    if (comparepassForStudentTeacherEmployee(type, "student"))
    {
        struct student ob = sread_single_pd(adress);
        return main_student_upadte_function(ob, adress);
    }
    else if (comparepassForStudentTeacherEmployee(type, "teacher"))
    {
        struct teacher ob = tread_single_pd(adress);
        return main_teacher_upadte_function(ob, adress);
    }
    else
    {
        struct EMPLOYEE ob = eread_single_pd(adress);
        return main_employee_upadte_function(ob, adress);
    }
}

int read_notice_quantity()
{
    char adress[] = "C://UMS(IAS)//data//notice";
    DIR *folder;
    int files = 0;
    struct dirent *entry;
    folder = opendir(adress);
    while (entry = readdir(folder))
    {
        files++;
    }

    closedir(folder);
    return files - 2;
}
void read_notice(struct notice ob[], int n)
{
    char adress[] = "C://UMS(IAS)//data//notice";
    DIR *folder;
    struct dirent *entry;
    folder = opendir(adress);
    entry = readdir(folder);
    entry = readdir(folder);
    for (int i = 0; i < n; i++)
    {
        entry = readdir(folder);
        char re[100];
        clean_string(re, 99);
        strcat(re, adress);
        strcat(re, "//");
        strcat(re, entry->d_name);
        strcpy(ob[i].path, re);
        char na[100];
        clean_string(na, 99);
        strcpy(na, entry->d_name);
        na[strlen(na) - 4] = '\0';
        strcpy(ob[i].name, na);
        ob[i].index = i + 1;
    }

    closedir(folder);
}
void view_all_notice()
{
    int n = read_notice_quantity(), i, option;
    struct notice ob[n];
    read_notice(ob, n);
    view_all_notice_frame(n);
    for (i = 0; i < n; i++)
    {
        gotoxy(38, 12 + i);
        printf("[%.3d]  %s", ob[i].index, ob[i].name);
    }
    gotoxy(38, 12 + i);
    printf("[%.3d]  EXIT", i + 1);
    gotoxy(50, 13 + i + 1);
    printf("ENTER OPTION :");
    scanf("%d", &option);
    if (option > 0 && option <= n)
    {
        return view_one_notice(ob[option - 1].path);
    }
    else if (option == n + 1)
    {
        return main_menu();
    }
    else
    {
        wrong_selection();
        return view_all_notice();
    }
}
void create_new_notice()
{
    char heding[100], date[100], body[10000];
    clean_string(heding, 99);
    clean_string(date, 99);
    clean_string(body, 9999);
    date_hading_frame(date, heding);
    char adress[400];
    clean_string(adress, 399);
    strcat(adress, "C://UMS(IAS)//data//notice//");
    strcat(adress, date);
    strcat(adress, "-");
    strcat(adress, heding);
    strcat(adress, ".txt");
    write_notice(body);
    if (wantTosaveframe())
    {
        FILE *ptr;
        ptr = fopen(adress, "w");
        fprintf(ptr, "%s ", body);
        fclose(ptr);
    }
    return update_notice();
}
void append_notice()
{
    char heding[100], date[100], body[10000];
    clean_string(heding, 99);
    clean_string(date, 99);
    clean_string(body, 9999);
    date_hading_frame(date, heding);
    char adress[400];
    clean_string(adress, 399);
    strcat(adress, "C://UMS(IAS)//data//notice//");
    strcat(adress, date);
    strcat(adress, "-");
    strcat(adress, heding);
    strcat(adress, ".txt");
    write_notice(body);
    if (wantTosaveframe())
    {
        FILE *ptr;
        ptr = fopen(adress, "a");
        fprintf(ptr, "%s", body);
        fclose(ptr);
    }
    return update_notice();
}
void delete_notice()
{
    char heding[100], date[100], body[10000];
    clean_string(heding, 99);
    clean_string(date, 99);
    clean_string(body, 9999);
    date_hading_frame(date, heding);
    char adress[400];
    clean_string(adress, 399);
    strcat(adress, "C://UMS(IAS)//data//notice//");
    strcat(adress, date);
    strcat(adress, "-");
    strcat(adress, heding);
    strcat(adress, ".txt");
    if (wantTodeleteframe())
    {
        remove(adress);
        sucessfullydeleteframe();
    }
    return update_notice();
}
void update_notice()
{
    fflush(stdin);
    update_notice_frame(3);
    int option = 1;
    char ch = '0';
    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 5)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 4;
            break;
        }
        h_light_notice_section(option);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                create_new_notice();
                update_notice_frame(3);
                break;
            case 2:
                append_notice();
                update_notice_frame(3);
                break;
            case 3:
                delete_notice();
                update_notice_frame(3);
                break;
            case 4:
                return Admin();
            }
        }
    }
}

void Admin()
{
    fflush(stdin);
    adminframe();
    int option = 1, x = 52;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 9)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 8;
            break;
        }

        h_light_admin_menu(option);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                return teacherfunction();
            case 2:
                return employeefunction();
            case 3:
                return studentfunction();
            case 4:
                return on_off_course();
            case 5:
                return updateCourse(false);
            case 6:
                return updateCourse(true);
            case 7:
                return update_notice();
            case 8:
                return main_menu();
            default:
                wrong_selection();
                return Admin();
            }
        }
    }
}

void seedataemployee()
{
    int id;
    char adress[100], type[] = "employee";
    clean_string(adress, 99);
    genarete_address_from_id(type, running_id, adress);
    strcat(adress, "//pd.txt");

    struct EMPLOYEE ob;
    ob = eread_single_pd(adress);

    seeemployeedataFrame(ob);

    return Employee();
}

void Employee()
{
    fflush(stdin);
    char ch = '0';
    int option = 1;
    employeeframe();
    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 4)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 3;
            break;
        }

        h_light_employee_menu(option);
        ch = getch();
        if (ch == 13)
        {

            switch (option)
            {
            case 1:
                return seedataemployee();
            case 2:
                return change_password_function("employee");
            case 3:
                return main_menu();
            default:
                wrong_selection();
                return Employee();
            }
        }
    }
}

void save_course(struct subject sub[], int n)
{
    system("cls");
    char adress[100], type[] = "student", adress2[100], s[5];
    clean_string(adress, 99);
    clean_string(adress2, 99);
    genarete_address_from_id(type, running_id, adress);
    genarete_address_from_id(type, running_id, adress2);
    strcat(adress, "//course.txt");

    FILE *ptr, *ftr;
    int i = 0, x;
    ftr = fopen(adress, "r");
    fscanf(ftr, "%d", &x);
    itoa(x, s, 5);
    strcat(adress2, "//");
    strcat(adress2, s);
    strcat(adress2, ".txt");
    fclose(ftr);
    ftr = fopen(adress, "w");
    fprintf(ftr, "%d", x + 1);
    fclose(ftr);

    ptr = fopen(adress2, "w");
    fprintf(ptr, "%d ", n);
    while (i < n)
    {
        fprintf(ptr, "%d\n", sub[i].code);
        fputs(sub[i].name, ptr);
        fprintf(ptr, "\n", ptr);
        fprintf(ptr, "0 0 0 0 0\n");
        i++;
    }
    fclose(ptr);
    sucessfullysaveframe();
    return StuDent();
}
void add_courses(char add[], char status[])
{
    int n, i = 0, c = 0;
    FILE *ptr, *ftr;

    ftr = fopen(status, "r");
    fscanf(ftr, "%d", &n);
    fclose(ftr);

    struct subject sub[n];
    struct subject sub2[n];
    ptr = fopen(add, "r");
    while (fscanf(ptr, "%d", &sub[i].code) != EOF)
    {
        char d;
        fscanf(ptr, "%c", &d);
        fgets(sub[i].name, 100, ptr);
        clean_n(sub[i].name);
        i++;
    }
    select_course_frame(sub, n, sub2, &c);
    if (wantTosaveframe())
        return save_course(sub2, c);
    else
        return StuDent();
}

void courseForintake()
{
    char ad[100], intake[100];
    clean_string(intake, 99);
    clean_string(ad, 99);
    batch(intake);
    strcat(ad, "C://UMS(IAS)//data//course//");
    strcat(ad, intake);
    clean_string(intake, 99);
    strcpy(intake, ad);
    strcat(ad, "//course.txt");
    strcat(intake, "//status.txt");
    return add_courses(ad, intake);
}
void student_registration()
{
    if (!check_couse())
    {
        course_registration_tryleaterFrame();
        return StuDent();
    }
    else
    {
        courseForintake();
    }
}
void student_present_course()
{
    char adress[100], type[] = "student", adress2[100], s[5];
    clean_string(adress, 99);
    clean_string(adress2, 99);
    genarete_address_from_id(type, running_id, adress);
    genarete_address_from_id(type, running_id, adress2);
    strcat(adress, "//course.txt");
    FILE *ptr;
    int n, i = 0;
    double number;
    ptr = fopen(adress, "r");
    fscanf(ptr, "%d", &n);
    fclose(ptr);
    ptr = fopen(adress, "w");
    fprintf(ptr, "%d", n);
    fclose(ptr);
    n = n - 1;
    itoa(n, s, 5);
    strcat(adress2, "//");
    strcat(adress2, s);
    strcat(adress2, ".txt");
    ptr = fopen(adress2, "r");

    if (ptr == NULL)
    {
        n = 0;
        struct subject ob[n];
        currtent_course_frame(ob, n);
        fclose(ptr);
        return StuDent();
    }
    fscanf(ptr, "%d", &n);
    struct subject sub[n];
    while (fscanf(ptr, "%d", &sub[i].code) != EOF)
    {
        char c;
        fscanf(ptr, "%c", &c);
        fgets(sub[i].name, 100, ptr);
        clean_n(sub[i].name);
        fscanf(ptr, "%lf", &number);
        fscanf(ptr, "%lf", &number);
        fscanf(ptr, "%lf", &number);
        fscanf(ptr, "%lf", &number);
        fscanf(ptr, "%lf", &number);
        i++;
    }
    currtent_course_frame(sub, n);
    return StuDent();
}
void seedatastudent()
{
    int id;
    char adress[100], type[] = "student";
    clean_string(adress, 99);
    genarete_address_from_id(type, running_id, adress);
    strcat(adress, "//pd.txt");

    struct student ob;
    ob = sread_single_pd(adress);

    seestudentdataFrame(ob);

    return StuDent();
}
void academic_informetion()
{
    int n, i = 0;
    char sems[5];
    clean_string(sems, 4);
    enter_semester_number(sems);
    char adress[100], type[] = "student";
    clean_string(adress, 99);
    genarete_address_from_id(type, running_id, adress);
    strcat(adress, "//");
    strcat(adress, sems);
    strcat(adress, ".txt");
    FILE *ptr;
    ptr = fopen(adress, "r");

    if (ptr == NULL)
    {
        wrong_selection();
        fclose(ptr);
        return StuDent();
    }
    fscanf(ptr, "%d", &n);
    struct result_subject sub[n];
    while (fscanf(ptr, "%d", &sub[i].code) != EOF)
    {
        char c;
        fscanf(ptr, "%c", &c);
        fgets(sub[i].name, 100, ptr);
        clean_n(sub[i].name);
        fscanf(ptr, "%lf", &sub[i].mid);
        fscanf(ptr, "%lf", &sub[i].final);
        fscanf(ptr, "%lf", &sub[i].viva);
        fscanf(ptr, "%lf", &sub[i].total);
        fscanf(ptr, "%lf", &sub[i].gpa);
        i++;
    }
    fclose(ptr);
    academic_frame(sub, n);
    return StuDent();
}
void StuDent()
{
    fflush(stdin);
    studentframe();
    int option = 1, x = 52;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 8)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 7;
            break;
        }

        h_light_Student_menu(option);
        ch = getch();
        if (ch == 13)
        {

            switch (option)
            {
            case 1:
                return seedatastudent();
            case 2:
                return student_present_course();
            case 3:
                return student_registration();
            case 4:
                return academic_informetion();
            case 5:
                messenger_function("student", "teacher");
                return StuDent();
            case 6:
                return change_password_function("student");
            case 7:
                return main_menu();
            default:
                wrong_selection();
                return StuDent();
            }
        }
    }
}

void teachersearchstudent()
{
    int id;
    char co[10], adress[100], type[] = "student";
    clean_string(co, 9);
    clean_string(adress, 99);
    id = enter_id_frame();
    sprintf(co, "%d", id);
    genarete_address_from_id(type, co, adress);
    strcat(adress, "//pd.txt");

    struct student ob;
    ob = sread_single_pd(adress);

    seestudentdataFrame(ob);

    return Teacher();
}
void seedatateacher()
{
    int id;
    char adress[100], type[] = "teacher";
    clean_string(adress, 99);
    genarete_address_from_id(type, running_id, adress);
    strcat(adress, "//pd.txt");

    struct teacher ob;
    ob = tread_single_pd(adress);

    seeteacherdataFrame(ob);

    return Teacher();
}
void teacherseepresentCourse()
{
    char ad[100], intake[100];
    clean_string(intake, 99);
    clean_string(ad, 99);
    batch(intake);
    strcat(ad, "C://UMS(IAS)//data//course//");
    strcat(ad, intake);
    clean_string(intake, 99);
    strcpy(intake, ad);
    strcat(ad, "//course.txt");
    strcat(intake, "//status.txt");
    present_courses(ad, intake);
    return Teacher();
}
void save_result(struct result_subject ob[], int n, char adress[])
{
    int i = 0;
    FILE *ptr;
    ptr = fopen(adress, "w");
    fprintf(ptr, "%d ", n);
    while (i < n)
    {
        fprintf(ptr, "%d ", ob[i].code);
        fputs(ob[i].name, ptr);
        fprintf(ptr, "\n", ptr);
        ob[i].total = ob[i].mid + ob[i].final + ob[i].viva;
        ob[i].gpa = calculate_gpa(ob[i].total);
        fprintf(ptr, "%.2lf %.2lf %.2lf %.2lf %.2lf\n", ob[i].mid, ob[i].final, ob[i].viva, ob[i].total, ob[i].gpa);
        i++;
    }
    fclose(ptr);
    sucessfullysaveframe();
    return Teacher();
}
void Update_result()
{
    int n, i = 0;
    char sems[5], s_id[10];
    clean_string(sems, 4);
    clean_string(s_id, 9);
    int id = enter_id_frame();
    sprintf(s_id, "%d", id);
    enter_semester_number(sems);
    char adress[100], type[] = "student";
    clean_string(adress, 99);
    genarete_address_from_id(type, s_id, adress);
    strcat(adress, "//");
    strcat(adress, sems);
    strcat(adress, ".txt");
    FILE *ptr;
    ptr = fopen(adress, "r");

    if (ptr == NULL)
    {
        wrong_selection();
        fclose(ptr);
        return Teacher();
    }
    fscanf(ptr, "%d", &n);
    struct result_subject sub[n];
    while (fscanf(ptr, "%d", &sub[i].code) != EOF)
    {
        char d;
        fscanf(ptr, "%c", &d);
        fgets(sub[i].name, 100, ptr);
        clean_n(sub[i].name);
        fscanf(ptr, "%lf", &sub[i].mid);
        fscanf(ptr, "%lf", &sub[i].final);
        fscanf(ptr, "%lf", &sub[i].viva);
        fscanf(ptr, "%lf", &sub[i].total);
        fscanf(ptr, "%lf", &sub[i].gpa);
        i++;
    }
    fclose(ptr);
    update_academic_frame(sub, n);
    return save_result(sub, n, adress);
}
void see_student_academic_result()
{
    int id = enter_id_frame();
    char s_id[10];
    clean_string(s_id, 9);
    sprintf(s_id, "%d", id);
    int n, i = 0;
    char sems[5];
    clean_string(sems, 4);
    enter_semester_number(sems);
    char adress[100], type[] = "student";
    clean_string(adress, 99);
    genarete_address_from_id(type, s_id, adress);
    strcat(adress, "//");
    strcat(adress, sems);
    strcat(adress, ".txt");
    FILE *ptr;
    ptr = fopen(adress, "r");

    if (ptr == NULL)
    {
        wrong_selection();
        fclose(ptr);
        return Teacher();
    }
    fscanf(ptr, "%d", &n);
    struct result_subject sub[n];
    while (fscanf(ptr, "%d", &sub[i].code) != EOF)
    {
        char c;
        fscanf(ptr, "%c", &c);
        fgets(sub[i].name, 100, ptr);
        clean_n(sub[i].name);
        fscanf(ptr, "%lf", &sub[i].mid);
        fscanf(ptr, "%lf", &sub[i].final);
        fscanf(ptr, "%lf", &sub[i].viva);
        fscanf(ptr, "%lf", &sub[i].total);
        fscanf(ptr, "%lf", &sub[i].gpa);
        i++;
    }
    fclose(ptr);
    academic_frame(sub, n);
    return Teacher();
}
struct result_subject make_result_helper1(int subject_code, char s_id[], char sems[])
{
    int n, i = 0;
    char adress[100], type[] = "student";
    clean_string(adress, 99);
    genarete_address_from_id(type, s_id, adress);
    strcat(adress, "//");
    strcat(adress, sems);
    strcat(adress, ".txt");
    FILE *ptr;
    ptr = fopen(adress, "r");

    if (ptr == NULL)
    {
        wrong_selection();
        fclose(ptr);
        struct result_subject ob;
        ob.code = 0;
        ob.final = 0;
        ob.gpa = 0;
        ob.mid = 0;
        ob.name[0] = ' ';
        ob.total = 0;
        ob.viva = 0;
        return ob;
    }
    fscanf(ptr, "%d", &n);
    struct result_subject sub[n];
    while (fscanf(ptr, "%d", &sub[i].code) != EOF)
    {
        char c;
        fscanf(ptr, "%c", &c);
        fgets(sub[i].name, 100, ptr);
        clean_n(sub[i].name);
        fscanf(ptr, "%lf", &sub[i].mid);
        fscanf(ptr, "%lf", &sub[i].final);
        fscanf(ptr, "%lf", &sub[i].viva);
        fscanf(ptr, "%lf", &sub[i].total);
        fscanf(ptr, "%lf", &sub[i].gpa);
        i++;
    }
    fclose(ptr);

    return sub[subject_position(sub, n, subject_code)];
}
struct student make_result_helper2(char s_id[])
{
    int id;
    char adress[100], type[] = "student";
    clean_string(adress, 99);
    genarete_address_from_id(type, s_id, adress);
    strcat(adress, "//pd.txt");

    struct student ob;
    ob = sread_single_pd(adress);

    return ob;
}

void make_result_sheet()
{
    int s_code;
    char sems[5];
    clean_string(sems, 4);
    int n = how_many_studen_frame(&s_code, sems), i, id;
    struct result_subject ob[n];
    struct student bio[n];
    for (i = 0; i < n; i++)
    {
        int id = enter_id_frame();
        char s_id[10];
        clean_string(s_id, 9);
        sprintf(s_id, "%d", id);
        bio[i] = make_result_helper2(s_id);
        ob[i] = make_result_helper1(s_code, s_id, sems);
    }
    savefile(bio, ob, n);
    sucessfullysaveframe();
    return Teacher();
}

void Teacher()
{
    fflush(stdin);
    teacherframe();
    int option = 1, x = 52;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 10)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 9;
            break;
        }

        h_light_Teacher_menu(option);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                return seedatateacher();
            case 2:
                return see_student_academic_result();
            case 3:
                return teachersearchstudent();
            case 4:
                return Update_result();
            case 5:
                messenger_function("teacher", "student");
                return Teacher();
            case 6:
                return teacherseepresentCourse(false);
            case 7:
                return make_result_sheet();
            case 8:
                return change_password_function("teacher");
            case 9:
                return main_menu();
            default:
                wrong_selection();
                return Teacher();
            }
        }
    }
}

void main_menu()
{
    fflush(stdin);
    time_t t;
    time(&t);
    menuframe();
    gotoxy(27, 5);
    printf("START TIME:-\n");
    gotoxy(71, 5);
    printf("%s\n", ctime(&t));
    gotoxy(50, 9);
    printf("Asalamualikum User.\n");
    int option = 1, x = 52;
    char ch = '0';

    while (1)
    {
        switch (ch)
        {
        case 80:
            option++;
            if (option == 7)
                option = 1;
            break;
        case 72:
            option--;
            if (option == 0)
                option = 6;
            break;
        }

        h_light_main_menu(option);
        ch = getch();
        if (ch == 13)
        {
            switch (option)
            {
            case 1:
                if (Admin_login())
                    return Admin();
                else
                    return main_menu();
            case 2:
                if (Employee_login())
                    return Employee();
                else
                    return main_menu();
            case 3:
                if (teacher_login())
                    return Teacher();
                else
                    return main_menu();
            case 4:
                if (student_login())
                    return StuDent();
                else
                    return main_menu();
            case 5:
                return view_all_notice();
            case 6:
                exit(0);
            default:
                wrong_selection();
                return main_menu();
            }
        }
    }
}
bool new_or_old()
{
    FILE *ptr;
    ptr = fopen("C://UMS(IAS)//status.txt", "r");
    if (ptr == NULL)
    {
        fclose(ptr);
        mkdir("C://UMS(IAS)");
        mkdir("C://UMS(IAS)//data");

        mkdir("C://UMS(IAS)//data//admin");
        ptr = fopen("C://UMS(IAS)//data//admin//pass.txt", "w");
        fprintf(ptr, "12345 iftekhar");
        fclose(ptr);

        mkdir("C://UMS(IAS)//data//course");
        ptr = fopen("C://UMS(IAS)//data//course//status.txt", "w");
        fprintf(ptr, "0");
        fclose(ptr);

        mkdir("C://UMS(IAS)//data//employee");
        ptr = fopen("C://UMS(IAS)//data//employee//status.txt", "w");
        fprintf(ptr, "0 0 0");
        fclose(ptr);

        mkdir("C://UMS(IAS)//data//notice");

        mkdir("C://UMS(IAS)//data//student");
        ptr = fopen("C://UMS(IAS)//data//student//status.txt", "w");
        fprintf(ptr, "0 0 0");
        fclose(ptr);

        mkdir("C://UMS(IAS)//data//teacher");
        ptr = fopen("C://UMS(IAS)//data//teacher//status.txt", "w");
        fprintf(ptr, "0 0 0");
        fclose(ptr);

        mkdir("C://UMS(IAS)//data//chat");

        ptr = fopen("C://UMS(IAS)//status.txt", "w");
        fputs("okey", ptr);
        fclose(ptr);
    }
}
