#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <stdio.h>
#define NAMESIZE 30
#define PHONENUM 12

#define MIN_AGE 6
#define MAX_AGE 25

#define INIT_TRUE 1
#define INIT_FAULS 0

#define TERMINATE_CHAR '\n'

typedef struct student student_t ;
struct student
{
    char name[NAMESIZE];
    char phone[PHONENUM];
    char Grade ;
    int id ;
    int age ;


} ;
void init_Student (student_t *data, int val) ;
void Print_Student_t( const student_t *data ) ;
void scan_Student_t(student_t *data ) ;
char scan_name(char* data );
char scan_Grade(student_t* data );
char scan_age(student_t* data );
char scan_phoneNum(char* data ) ;



#endif // STUDENT_H_INCLUDED
