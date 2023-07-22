#include "student.h"

int ID = 1 ;
void flushName(student_t *data)
{
    for (int i = 0 ; data->name[i] &&i<NAMESIZE; i++ )
    {
        data->name[i] = 0 ;
    }
}
void init_Student (student_t *data, int val)
{
    data->age =  0 ;
    flushName(data->name) ;
    data->phone[0] = 0 ;
    if (val==INIT_TRUE)
        data->id =  0 ;
    data->Grade = 'F' ;
}
char scan_phoneNum(char* data )
{
    int i = 0 ;
    char index = 0 ;
    int flage = 0 ;
    fflush(stdin);
    scanf("%c",&index);
    for (; index!=TERMINATE_CHAR && i < PHONENUM ; )
    {
        if (flage == 0 )
        {
            if (index>='0' &&index<='9')
            {
                data[i] = index ;
                i++ ;
            }
            else
            {
                flage = 1 ;
            }
        }
        scanf("%c",&index) ;
    }
    if (flage == 1 )
    {
        data[0] = 0 ;
        return 1 ;
    }
    data[i] = 0 ;
    return 0 ;
}
char scan_name(char* data )
{
    int i = 0 ;
    char index = 0 ;
    int flage = 0 ;
    scanf(" %c",&index);
    for (; index!=TERMINATE_CHAR && i < NAMESIZE ; )
    {
        if (flage == 0 )
        {
            if ((index>='a' &&index<='z'))
                flage = 0 ;
            else if ((index>='A' &&index<='Z'))
                flage = 0 ;
            else if((index == ' '))
                flage = 0 ;
            else if((index == '\n'))
                flage = 0 ;
            else
                flage =1 ;
        }
        data[i] = index ;
        i++ ;
        scanf("%c",&index) ;
    }
    if (flage == 1 )
    {
        data[0] = 0 ;
        return 1 ;
    }
    data[i] = 0 ;
    return 0 ;
}
char scan_age(student_t* data )
{
    //int flage = 0 ;
    int input  = 0 ;
    fflush(stdin);
    scanf("%d",&input) ;

    if   ((input <=MAX_AGE
            &&input >=MIN_AGE ))
    {
        data->age  = input ;
        return 0 ;
    }

    return 1 ;
}
char scan_Grade(student_t* data )
{
    // int flage = 0 ;
    fflush(stdin);
    scanf("%c",&data->Grade) ;
    if   ((data->Grade <='F' &&data->Grade >='A' ))
        return 0 ;
    return 1 ;
}
char scan_ID(student_t* data )
{
    // int flage = 0 ;
    fflush(stdin);
    scanf("%d",&data->id) ;
    if   ((data->id >=1000 &&data->id <=1000000 ))
        return 0 ;
    return 1 ;
}
void scan_Student_t(student_t *data )
{
    int x  = 1 ;
    fflush(stdin);
    while (x)
    {
        printf ("\n Student name : ");
        x = scan_name(data->name);
    }

    x = 1 ;
    while (x)
    {
        printf (" Student Phone number : ");
        x = scan_phoneNum(data->phone);
    }

    x = 1 ;
    while (x)
    {
        x = 0 ;
        printf (" Student age  : ");
        x = scan_age(data);
    }
    /*
    x = 1 ;
    while (x)
    {
        x = 0 ;
        printf (" Student ID  : ");
        x = scan_ID(data);
    }
    */
    x = 1 ;
    while (x)
    {
        x = 0 ;
        printf (" Student grade  : ");
        x =scan_Grade(data);
    }

}

void Print_Student_t( const student_t *data )
{
    printf("\n---------------------------\n");
    printf("\n name : %s \n phone : %s \n age : %d \n ID :%d \n grade : %c \n",
           data->name, data->phone, data->age, data->id, data->Grade);
    printf("\n---------------------------\n\n");
}

