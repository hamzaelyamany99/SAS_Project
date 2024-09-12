    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct student{
        int    Id;
        char    first_name[10];
        char    last_name[10];
        char    birth[10];
        float   mark;
        char    depart[10];
    };

    struct  student stud[100];
        int counter = 0;
        int id = 0  ;

    void    first_menu(){
        printf("################--------MENU------###################\n");
        printf("#   1 - Ajouter un Etudiant                         #\n");
        printf("#   2 - Modifier un Etudiant                        #\n");
        printf("#   3 - supprimer un Etudiant                       #\n");
        printf("#   4 - Afficher les details d'un Etudiant          #\n");
        printf("#   5 - Calculer la moyenne generale                #\n");
        printf("#   6 - Statistiques                                #\n");
        printf("#   7 - Rechercher un Etudiant                      #\n");
        printf("#   8 - Trier un Etudiant                           #\n");
        printf("#####################################################\n");
        }
    void    add_student(){

                printf("Student number:%d\n", counter+1);
                printf("Enter the student's first name: ");
                scanf(" %[^\n]s", &stud[counter].first_name);
                printf("Enter the student's last name: ");
                scanf(" %[^\n]s", &stud[counter].last_name);
                printf("Enter the student's birth by this form [dd/mm/yy]: ");
                scanf(" %[^\n]s", &stud[counter].birth);
                printf("Select the department:\n");
                scanf("%s",&stud[counter].depart);
                printf("Enter the student's generale mark:\n");
                scanf("%f",&stud[counter].mark);
                stud[counter].Id = ++id;
                counter++;
                main();
    }
    void    modify(){
        int select;
        int numb;

        printf("Enter the student Id: ");
        scanf("%d",&numb);
            for(int i=0; i<counter; i++){
                if(stud[i].Id - numb == 0){
                    printf("1 # Modify the student's first name: \n", stud[counter].first_name);
                    printf("2 # Modify the student's last name: \n", stud[counter].last_name);
                    printf("3 # Modify the student's birth by this form [dd/mm/yy]: \n", stud[counter].birth);
                    printf("4 # Modify the department:\n", stud[counter].depart);
                    printf("5 # Modify the student's generale mark:\n", stud[counter].mark);
                    printf("***********************************************************\n");
                    printf("Select from the menu: ");
                    scanf("%d",&select);
                            switch (select)
                            {
                            case 1:
                                printf("Enter the student's first name:");
                                scanf(" %[^\n]s", &stud[i].first_name);
                                break;
                            case 2:
                                printf("Enter the student's last name:");
                                scanf(" %[^\n]s", &stud[i].last_name);
                                break;
                            case 3:
                                printf("Enter the student's day of birth:");
                                scanf(" %[^\n]s", &stud[i].birth);
                                break;
                            case 4:
                                printf("Enter the student's department:");
                                scanf(" %[^\n]s", &stud[i].depart);
                                break;
                            case 5:
                                printf("Enter the student's general mark:");
                                scanf(" %[^\n]s", &stud[i].mark);
                                break;
                            }

                    }
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
            printf("------------------------------------------\n");
            printf(" Student %d first name : %s | ", i+ 1, stud[i].first_name);
            printf("Id :%d | ", stud[i].Id);
            printf("last name :%s | " ,stud[i].last_name);
            printf("Birth :%s | ", stud[i].birth);
            printf("Department :%s | ", stud[i].depart);
            printf("General Mark :%.2f \n", stud[i].mark);
            printf("**************************************\n");
        }
        main();
    }
void del(){
int del;
        if(counter == 0)
        {
            printf("---------------------------------------------\n");
            printf("******** There are NO students here ******** \n");
            printf("\n");
        }
            else{
            printf("Enter student Id :");
            scanf("%d",&del);
            for (int i=0;i<counter;i++){
                if (stud[i].Id - del == 0){
                        for (int j = i;j<counter;j++){
                            stud[j] = stud[j+1];
                    }
                    counter--;
                }
              }
            printf("-----------------------------------\n");
            printf("Student removed successfully.\n");
  }
  main();
}
    void    find(){
        char name[20];
        char dep[20];
        int select,N=0;
        printf("1. Search by last name.\n");
        printf("2. Search by department.\n");
        printf("Select from the menu :");
        scanf("%d",&select);
        switch(select){
        case 1:
                printf("Enter the name:");
                scanf(" %[^\n]s",&name);
                for(int i=0;i<counter;i++){
                    if(strcmp(stud[i].last_name,name)== 0){
                        printf("******** Student Id :%d\n", stud[i].Id);
                        printf("Student first name :%s\n", stud[i].first_name);
                        printf("Student last name :%s\n", stud[i].last_name);
                        printf("Birth :%s\n", stud[i].birth);
                        printf("Department :%s \n", stud[i].depart);
                        printf("General Mark :%.2f \n", stud[i].mark);
                        printf("**************************************\n");
                    }
                }
        break;
        case 2:
                printf("Enter the department :");
                scanf(" %[^\n]s",&dep);
                for (int i=0;i<counter;i++){
                if (strcmp(stud[i].depart, dep)==0){
                        printf("******** Student Id :%d\n", stud[i].Id);
                        printf("Student first name :%s\n", stud[i].first_name);
                        printf("Student last name :%s\n", stud[i].last_name);
                        printf("Birth :%s\n", stud[i].birth);
                        printf("Department :%s \n", stud[i].depart);
                        printf("General Mark :%.2f \n", stud[i].mark);
                        printf("**************************************\n");
                    N++;
                }
            }
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
        printf("#   7 - Rechercher un Etudiant                      #\n");
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
        case 3:
            del();
            break;
        case 4:
            affiche();
            break;
        /*case 5:
            calc();
            break;*/
        //case 6:
          //  stats();
            //break;
        case 7:
            find();
            break;
        /*case 8:
            sort();
            break;*/
        default:
            break;
        }

    }while(!(choice >= 1 && choice <= 8));
    return 0;
    }
