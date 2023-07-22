
#include "student.h"
#include"school.h"
//#include "Class.h"


student_t data_base [10] =
{
    {"mohamed hosam","01014552837",'D',1001,18},
    {"Ahmed Hessin","010141651837",'A',1002,21},
    {"jemmy neutron","01022142837",'F',1003,23},
    {"saad  eldally","01098451837",'C',1004,12},
    {"fares sedan",  "01016552837",'C',1005,10},
    {"frida  bdr","01098451837",'C',1006,12},
    {"salwa hesham",  "01016552837",'C',1007,13},
    {"samer shawky",  "01002331658",'F',1008,21}
};


int main()
{
    char nameindex [30] = {0} ;
    int size = 0 ;
    char op = 0 ;
    school_t test  ;
    init_school(&test);
    copyDataBase(&test,data_base,7 ) ;
    //
    // print_School(&test);

    /*
        for (int i = 0 ; i < test.size ; i++ )
        {
            scan_Student_t(test.school[i] );
        }
        int index = 0 ;

        if (index!=-1)
            Print_Student_t(test.school[index]);
        print_School(&test);
        */

    print_loudingscreen(1,"Wolcome");
    while (1)
    {
        system("cls");
        printf("\n\n\n\t\t\t[1] Print School Students\n");
        printf(" \t\t\t[2] Add students data \n");
        printf(" \t\t\t[3] Edit  Students\n");
        printf(" \t\t\t[4] Call  Student\n");
        printf(" \t\t\t[5] Delete student \n");
        op = getch();
        switch (op)
        {
        case '1' :
            system("cls");
            BSortSchool(&test) ;
            print_School(&test);
            op = getch();
            while (op != 27 )
            {
                op = getch();
            }
            break ;
        case '2' :
            system("cls");
            while (test.size < STUDENTS_NUM )
            {
                int r = Blank_Student(&test);
                if (r >=0)
                {
                    scan_Student_t(test.school[r]);
                }
                else
                {
                    Create_Student(&test.school[test.size]);
                    test.school[test.size]->id = id ++;
                    scan_Student_t(test.school[ test.size]);
                }
                printf(" \t\t\t\tone more ? ANY_KEY [Y] ESC[N] ");
                test.size++ ;
                fflush(stdin);
                op = getch();
                if (op==27) break ;
            }
            if (!(size < STUDENTS_NUM ))
            {
                printf(" \t\tout of memory ");
            }
            while (op != 27 )
            {
                op = getch();
            }
            break ;
        case '3' :
            system("cls");
            printf(" [1] Name \n");
            printf(" [2] ID  \n");
            op = getch();
            switch(op)
            {
            case '1' :
                system("cls");
                printf("\n name : ");
                scan_name(nameindex) ;
                int index  = 0 ;
                int  x  = BSearch(&test,nameindex,&index);
                if (x  == 1 )
                {
                    Print_Student_t(test.school[index]);
                    delay(3000);
                    edit_student(test.school[index]);
                }
                else
                {
                    printf("\ncant find him/her ");
                    delay(1000);
                }
                break ;
            case '2' :
                ;
                int data = 0 ;
                system("cls");
                printf("\n ID : ");
                scanf("%d",&data);
                int  y  = ID_search(&test,data);
                if (y >= 0  )
                {
                    Print_Student_t(test.school[y]);
                    delay(3000);
                    edit_student(test.school[y]);
                }
                else
                {
                    printf("\ncant him/her  ");
                    delay(1000);
                }
                break ;
            }
            break ;
        case '4':
            ;
            studentCall(&test);
            break ;
        case '5':
            ;
            studentDelet(&test);
            break ;
        }
    }
}
