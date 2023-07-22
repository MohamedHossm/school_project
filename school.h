#ifndef SHCOOL_H_
#define SHCOOL_H_
#include<time.h>
#include <String.h>
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#define STUDENTS_NUM 100
#define NULLPOINTER ((void*)0)
#define DELAY 3
#define DELAY2 5
#define ID_START 1001

extern int id ;
typedef struct
{
    student_t * school [STUDENTS_NUM] ;
    int size ;
} school_t;
void init_school (school_t * data);
void Create_Student( student_t **School);
void print_School(school_t * data);
void delay(unsigned int mseconds) ;
void BSortSchool  (school_t *data);
int BSearch(school_t *data, char*name, int *index );
void convertString(char *data,char *Redata  );
int Get_Student_num(school_t * data);
int ID_search(school_t *data,int index );
void print_louding(int time,student_t *string);
void copyDataBase(school_t * scData,student_t * data, int size );
void edit_student(student_t * data);
void studentCall(school_t * scData);
int Blank_Student(school_t * scData );
void studentDelet(school_t * scData);

#endif
