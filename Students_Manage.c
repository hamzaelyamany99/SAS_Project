#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int    uniqId;
    char    first_name[10];
    char    last_name[10];
    char    birth[10];
    float   mark;
    char    depart[10];
};
    char    svt[] = "SVT";
    char    pc[] = "PC";
    char    math[] = "MATH";

struct  student stud[100];
    int counter = 0;
    int id = 1;

void    add_student(){
    int select;
    int i;
        for (i=0 ; i <= counter; i++){
            printf("Student number:%d\n", id);
            printf("Enter the student's first name: ");
            scanf(" %[^\n]s", &stud[counter].first_name);
            printf("Enter the student's last name: ");
            scanf(" %[^\n]s", &stud[counter].last_name);
            printf("Enter the student's birth by this form [dd/mm/yy]: ");
            scanf(" %[^\n]s", &stud[counter].birth);
            printf("Select the department:\n");
            printf("************  SELECT    **********\n");
            printf("*            1 - SVT             *\n");
            printf("*            2 - PC              *\n");
            printf("*            3 - MATH            *\n");
            printf("**********************************\n");
                scanf("%d", &select);
                    switch (select)
                    {
                    case 1:
                        strcpy(stud[counter].depart, svt);
                        break;
                    case 2:
                        strcpy(stud[counter].depart, pc);
                        break;
                    case 3:
                        strcpy(stud[counter].depart, math);
                        break;
                    }
            printf("Enter the student's generale mark:\n");
            scanf("%f",&stud[counter].mark);
            }
            counter++;
            stud[counter].uniqId = id;;
            id++;
            main();
}
void    modify(){
    int i;
    int numb;
    int dpp;

    i = 0;

    while(numb<=id){
    printf("Enter the student number: ");
    scanf("%d",&numb);
        if(numb == stud[counter].uniqId){
                printf("Enter the student's first name: ");
                scanf(" %[^\n]s", &stud[counter].first_name);
                printf("Enter the student's last name: ");
                scanf(" %[^\n]s", &stud[counter].last_name);
                printf("Enter the student's birth by this form [dd/mm/yy]: ");
                scanf(" %[^\n]s", &stud[counter].birth);
                printf("Select the department:\n");
                printf("************  SELECT    **********\n");
                printf("*            1 - SVT             *\n");
                printf("*            2 - PC              *\n");
                printf("*            3 - MATH            *\n");
                printf("**********************************\n");
                scanf("%d", &dpp);
                    switch (dpp)
                    {
                            case 1:
                                stud[counter].depart[10] = "SVT";
                                break;
                            case 2:
                                stud[counter].depart[10] = "PC";
                                break;
                            case 3:
                                stud[counter].depart[10] = "MATH";
                                break;
                            default:
                            break;
                    }
                }
            i++;
        }
        main();
}
void    affiche(){
    int i;

    if(counter == 0)
    {
        printf("******** There are NO students here ******** \n");
        printf("\n");
    }
    for(i=0; i<counter ;i++){
        printf("Student number :%d\n", stud[i].uniqId + 1);
        printf("Student first name :%s\n", stud[i].first_name);
        printf("Student last name :%s\n", stud[i].last_name);
        printf("Birth :%s\n", stud[i].birth);
        printf("Department :%s \n", stud[i].depart);
        printf("General Mark :%.2f \n", stud[i].mark);
        printf("**************************************\n");
    }
    main();
}
int main(){
    int i, choice;

do{
    printf("#####################################################\n");
    printf("#   1 - Ajouter un Etudiant                         #\n");
    printf("#   2 - Modifier un Etudiant                        #\n");
    printf("#   3 - supprimer un Etudiant                       #\n");
    printf("#   4 - Afficher les details d'un Etudiant          #\n");
    printf("#   5 - Calculer la moyenne generale                #\n");
    printf("#   6 - Statistiques                                #\n");
    printf("#   7 - Rechercher un Etudiant par                  #\n");
    printf("#   8 - Trier un Etudiant                           #\n");
    printf("#####################################################\n");

    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        add_student();
        break;
    case 2:
        modify();
        break;
    //case 3:
        //del();
        //break;
    case 4:
        affiche();
        break;
    default:
        break;
    }

}while(!(choice >= 1 && choice <= 8));
return 0;
}
