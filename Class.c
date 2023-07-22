#include "Class.h"
#include "student.h"
char *subjects [MAXSUBJECTS]= {"Arabic", "English","Math", "History","Geography" };
void init_Class(class_t* data)
{
    int x  = 1 ;
    while (x)
    {
        printf(" Enter Class Name :  ");
        x =  scan_Class_name(data->name);
    }
    CLass_subJects(data);
}
void CLass_subJects(class_t* data)
{
    char saved_data [MAXSUBJECTS] = {0} ;
    printf("choose Class subjects :  \n");
    for (int i = 0; i< MAXSUBJECTS ; i++ )
    {
        printf("%d -%s \n",i+1,subjects[i] );
    }
    printf(" Enter numbers of subjects separated by space  ");
    scan_subjects(saved_data);
    printf("class subjects is :\n ");
    for (int i = 0; i< MAXSUBJECTS&&saved_data[i] ; i++ )
    {
        data->subjects[i]=subjects[saved_data[i]-'1'] ;

        printf(" %s ", data->subjects[i] );
        //printf(" %s ", subjects[saved_data[i]-'0']);
    }

}
void Class_print_names(class_t* data)
{
    printf(" class subjects is ");
    for (int i = 0 ; i < data->subjects_num ; i++ )
    {
        printf("  %s ",data->subjects);
    }
    for (int i = 0 ; i < data->students_num ; i++ )
    {
        printf(" %d - %s \n",i+1,data->students[i]->name);
    }


}
char scan_subjects(char* data )
{
    int i = 0 ;
    char index = 0 ;
    int flage = 0 ;
    fflush(stdin);
    scanf("%c",&index);
    for (; index!=TERMINATE_CHAR && i < MAXSUBJECTS ; )
    {
        if (flage == 0 )
        {
            if (index>='1' &&index<='9')
            {
                data[i] = index ;
                i++ ;
            }
            else if (index =' ')
            {
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
char scan_Class_name(char* data )
{
    int i = 0 ;
    char index = 0 ;
    int flage = 0 ;
    fflush(stdin);
    scanf("%c",&index);
    for (; index!=TERMINATE_CHAR && i < CLASS_NAME_SIZE ; )
    {
        if (flage == 0 )
        {
            if ((index>='A' &&index<='Z'))
                flage = 0 ;
            else if ((index>='0' &&index<='9'))
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
