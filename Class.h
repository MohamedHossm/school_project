
#include"student.h"
#ifndef CLASS_H_
#define CLASS_H_
#define CLASS_NAME_SIZE 3
#define MAXSUBJECTS 5
#define CLASSCAPACITY 8
extern char *subjects [MAXSUBJECTS] ;


typedef struct CLass class_t ;
struct CLass
{
    int students_num  ;
    int subjects_num  ;
    char name [CLASS_NAME_SIZE] ;
    student_t  *students[CLASSCAPACITY];
    char*  subjects [MAXSUBJECTS] ;
} ;
char scan_subjects(char* data );
char scan_Class_name(char* data );

#endif // CLASS_H_
