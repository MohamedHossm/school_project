#include"school.h"

int id = ID_START ;
void convertString(char *data,char *Redata  )
{
    int j = 0 ;
    for (int i = 0 ; data[i] ; i++ )
    {
        if (data[i] >='A'&&data[i] <='Z')
        {
            Redata[j] = data[i] + ('a'-'A') ;
            j++;
        }
        else if (data[i] >='a'&&data[i] <='z')
        {
            Redata[j] = data[i] ;
            j++;
        }
        else if  (data[i] ==' ')
        {
        }
    }
    Redata[j] = 0 ;
}
int ID_search(school_t *data,int index )
{
    if (data->size < 1 )
    {
        printf("\n no data to search in ");
        return -1 ;
    }
    for (int i = 0 ; i < data->size ; i++ )
    {
        if (index == data->school[i]->id)
        {
            return i ;
        }
    }
    return -1 ;
}
int BSearch(school_t *data, char*name, int *index )
{
    if (data->size < 1 )
    {
        //  printf("\n no data to search in ");
        return 0 ;
    }
    int s = 0 ;
    BSortSchool(data);
    char name1[NAMESIZE] = {0} ;
    char name2[NAMESIZE] = {0};
    convertString(name,name2);
    int end = data->size-1 ;
    int mid= 0 ;
    *index = -1 ;
    while (s<=end )
    {
        mid = (s+end) / 2 ;
        convertString(data->school[mid]->name,name1 );
        if (strcmp(name1, name2) == 0)
        {
            *index = mid ;
            return 1;
        }
        else   if (strcmp(name1, name2) > 0)
        {
            end= mid -1 ;
        }
        else   if (strcmp(name1, name2) < 0)
        {
            s= mid +1 ;

        }
    }
    return 0;
}
void BSortSchool  (school_t *data)
{

    int check = 1 ;
    student_t * temp = NULLPOINTER ;
    for (int i = 0 ; i < data->size ; i++  )
    {
        check = 1 ;
        for (int j = 0 ; j < data->size-1-i ; j++ )
        {
            if (/*data->school[j]->name[0]== 0 ||*/
                strcmp(data->school[j]->name,data->school[j+1]->name)>0)
            {
                temp = data->school[j] ;
                data->school[j] = data->school[j+1] ;
                data->school[j+1] = temp ;
                check = 0;
            }

        }
        if (check) break ;
    }
    /*
    for (int j = 0 ; j < data->size ; j++ )
    {
        data->school[j]->id = ID_START+j ;
    }
    */
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void print_louding(int time,student_t *string)
{

    for (long long  i = 0 ; i <time*10 ; i++ )
    {
        system("cls");
        //  if (!i)
        printf("\n\n\t\tCALL : %s \n",string->name);
        printf("\t\t%s\n",string->phone);
        delay(300);
        printf(" . ");
        delay(300);
        printf(" . ");
        delay(300);
        printf(" . ");
        delay(300);

    }

    printf("\n\n\tNO ANSWER\n");
    getch();
}
void print_loudingscreen(int time,char * data)
{

    for (long long  i = 0 ; i <time*10 ; i++ )
    {
        system("cls");
        //  if (!i)
        printf("\n\n\n\t\t\t\t------------------------------------------------------\n");
        printf("\n\n\t\t\t\t\t\t\t %s \n\n\n",data);
        printf("\t\t\t\t------------------------------------------------------\n");
        printf("\t\t\tLOUDING");
        delay(100);
        printf(" . ");
        delay(100);
        printf(" . ");
        delay(100);
        printf(" . ");
        delay(100);

    }



}
void copyDataBase(school_t * scData,student_t * data, int size )
{
    int size1 = 0 ;
    for (int i = 0 ; i < size ; i ++)
    {
        size1  = Get_Student_num(scData);
        Create_Student(&scData->school[size1]);
        *(scData->school[size1]) = data[i] ;
        id ++ ;
    }

}
void studentDelet(school_t * scData)
{
    char name [NAMESIZE] = {0};
    char op = 0 ;
    int index  = 0 ;
    system("cls");
    printf("Enter student name : ");
    scan_name(name) ;
    int  x  = BSearch(scData,name,&index);
    if (x  == 1 )
    {
        Print_Student_t(scData->school[index]);
        printf ("\n\npress ENTER delete\n\n");
        op = getch();
        if (op == 13)
        {
            init_Student(scData->school[index],INIT_FAULS);
            BSortSchool(scData) ;
            system("cls");
            print_School(scData);

        }
        else
        {
            printf(" close  ");
        }

    }
    else
    {
        printf("\n\n\n\t\t\tWrong Name ");

    }
    getch();

}

void studentCall(school_t * scData)
{
    char name [NAMESIZE] = {0};
    char op = 0 ;
    int index  = 0 ;
    system("cls");
    printf("Enter student name : ");
    scan_name(name) ;
    int  x  = BSearch(scData,name,&index);
    if (x  == 1 )
    {
        Print_Student_t(scData->school[index]);
        printf ("\n\npress ENTER to Start a call\n\n");
        op = getch();
        if (op == 13)
        {
            print_louding(1, scData->school[index]  );

        }
        else
        {
            printf(" close  ");
        }
    }
    else
    {
        printf("\n\n\n\t\t\tWrong Name ");

    }
    getch();

}
void edit_student(student_t * data)
{
    char op = 0 ;
    int x = 1 ;
    while(1)
    {
        system("cls");
        printf(" [1]  edit Student Age \n");
        printf(" [2]  edit Student Name \n");
        printf(" [3]  edit Student phone number\n");
        printf(" [4]  edit Student grade\n");

        x = 1 ;
        fflush(stdin);
        op = getch();
        switch (op)
        {
        case '1':
            while (x)
            {
                x = 0 ;
                system("cls");
                printf (" Student age  : ");
                x = scan_age(data);
            }
            break ;
        case '2':
            while (x)
            {
                system("cls");
                printf ("\n Student name : ");
                x = scan_name(data->name);
            }

            break ;
        case '3':
            while (x)
            {
                system("cls");
                printf (" Student Phone number : ");
                x = scan_phoneNum(data->phone);
            }
            break ;
        case '4':
            while (x)
            {
                x = 0 ;
                system("cls");
                printf (" Student grade  : ");
                x =scan_Grade(data);
            }
            break ;
        }
        if (op == 27)break ;
    }
}
int Blank_Student(school_t * scData )
{
    BSortSchool(scData);
    for (int i =  0 ; i < scData->size ; i++ )
    {
        if (scData->school[i]->name[0]==0 && scData->school[i]->id !=0 )
        {
            return i ;
        }
    }
    return -1 ;
}
void init_school (school_t * data)
{
//   int index = 0 ;
    data->size = 0 ;
    for (int i = 0 ; i < STUDENTS_NUM  ; i++ )
    {
        data->school[i] = NULLPOINTER ;
    }
    /*
    printf("Enter School Students numbers [max is %d] : ",STUDENTS_NUM);
    scanf("%d",&index);
    if (index>=1&&index<=STUDENTS_NUM)
    {
        data->size =index ;
        // printf("\n Done ");
    }
    else
    {
        data->size = STUDENTS_NUM;
        printf("\n invalid entry, student number became %d \n",STUDENTS_NUM);
    }
    for (int i = 0 ; i < data->size ; i++ )
    {
        Create_Student(&data->school[i]);
        data->school[i]->id =id++;
    }
    */

}

void Create_Student( student_t **School)
{
    student_t *temp = ( student_t *)calloc(1,sizeof(student_t));
    init_Student(temp,INIT_TRUE);
    *School = temp;
}
void print_School(school_t * data)
{
    /*
    if (data->school[0]->name[0]==0)
    {
        printf("NO Data to print ");
        return ;
    }
    */
    //printf(" \n ur school has %d students \n",data->size);
    printf(" \n St_name        St_age     St_ID     St_Grade ");
    //int x = Get_Student_num(data);
    // printf("%d",data->size);
    for (int i = 0 ; i < data->size; i++ )
    {
        if (data->school[i]== NULLPOINTER) continue ;
        if (data->school[i]->name[0]== 0) continue ;
        printf(" \n %-15s    %-2d       %-2d       %-2c ",data->school[i]->name,data->school[i]->age,data->school[i]->id
               ,data->school[i]->Grade);
    }

}
int Get_Student_num(school_t * data)
{
    // if (data->size > 0 )
    // BSortSchool(data);
    data->size ++ ;
    return data->size -1;
}
