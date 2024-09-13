#include <stdio.h>//contains functions for input/output printf() and scanf()
#include <stdlib.h>//Memory Allocation/Freeing
#include <string.h>//contains functions for manipulating strings

    struct student{//stucture contains variables to store student information
        int    Id; // student unique ID
        char    first_name[10]; //first name
        char    last_name[10];// last name
        char    birth[10];// date of birth
        float   mark;//Note
        char    depart[10];// Department
    };

    struct  student stud[100]; // structure variable
        int counter = 0;// counter to count students
        int id = 0  ;// to store students ID

void    add_student(){// function helps to add student

                printf("Student number:%d\n", counter+1);
                printf("Enter the student's first name: ");
                scanf(" %[^\n]s", &stud[counter].first_name);
                printf("Enter the student's last name: ");
                scanf(" %[^\n]s", &stud[counter].last_name);
                printf("Enter the student's birth by this form [dd/mm/yyyy]: ");
                scanf(" %[^\n]s", &stud[counter].birth);
                printf("Select the department:\n");
                scanf("%s",&stud[counter].depart);
                printf("Enter the student's generale mark:\n");
                scanf("%f",&stud[counter].mark);
                stud[counter].Id = ++id;// store the new ++ID value in the Id
                counter++;// increment the counter
                main();// Go back to the main to chose new selection from the menu
    }
void    modify(){//function to modify a function by the Id number
        int select;//to store the user choice from the menu
        int numb;//to compare entred number with stored numbers

        printf("Enter the student Id: ");
        scanf("%d",&numb);
            for(int i=0; i<counter; i++){
                if(stud[i].Id - numb == 0){// if entred number equal existed number do the following
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
                            case 1://to modify first name
                                printf("Enter the student's first name:");
                                scanf(" %[^\n]s", &stud[i].first_name);
                                break;
                            case 2://to modify last name
                                printf("Enter the student's last name:");
                                scanf(" %[^\n]s", &stud[i].last_name);
                                break;
                            case 3://to modify date of birth
                                printf("Enter the student's day of birth:");
                                scanf(" %[^\n]s", &stud[i].birth);
                                break;
                            case 4://to modify department
                                printf("Enter the student's department:");
                                scanf(" %[^\n]s", &stud[i].depart);
                                break;
                            case 5://to modify mark
                                printf("Enter the student's general mark:");
                                scanf(" %[^\n]s", &stud[i].mark);
                                break;
                            }

                    }
            }
            main();// Go back to the main to chose new selection from the menu
    }
void    affiche(){//list all the students information
        int i;

        if(counter == 0)// No student added yet
        {
            printf("******** There are NO students here ******** \n");
            printf("\n");
        }
        for(i=0; i<counter ;i++){// loop to show students information -at least there is one student-
            printf("------------------------------------------\n");
            printf(" Student %d first name : %s | ", i+ 1, stud[i].first_name);
            printf("Id :%d | ", stud[i].Id);
            printf("last name :%s | " ,stud[i].last_name);
            printf("Birth :%s | ", stud[i].birth);
            printf("Department :%s | ", stud[i].depart);
            printf("General Mark :%.2f \n", stud[i].mark);
            printf("**************************************\n");
        }
        main();//Go back to the main to chose new selection from the menu
    }
void    del(){//Delete student
        int del;//To store the the student Id
        if(counter == 0)// No student added yet
        {
            printf("---------------------------------------------\n");
            printf("******** There are NO students here ******** \n");
            printf("\n");
        }
            else{//At least there is one student
            printf("Enter student Id :");
            scanf("%d",&del);// store the student Id in del
            for (int i=0;i<counter;   i++){
                if (stud[i].Id - del == 0){//if del value equal an existed value in Id do
                        for (int j = i;j<counter;j++){//loop to swipe the next student the the position before
                            stud[j] = stud[j+1];
                    }
                    counter--;//to loop it to the first position
                }
              }
            printf("-----------==============----------\n");
            printf("   Student removed successfully \n");
            printf("-----------==============----------\n");
  }
  main();//Go back to the main to chose new selection from the menu
}
void    find(){//find student by last name or by department
        char name[20];//to store the name to be founded
        char dep[20];//to store the department to be founded
        int select;//store the user selection
            printf("------------------------\n");
            printf("1. Search by last name.\n");
            printf("2. Search by department.\n");
            printf("------------------------\n");
            printf("Select from the menu :");
            scanf("%d",&select);
        switch(select){
        case 1:
                printf("Enter the name:");
                scanf(" %[^\n]s",&name);
                for(int i=0;i<counter;i++){// loop to compare the the inputed name to the existed names
                    if(strcmp(stud[i].last_name,name)== 0){
                        printf("***Student Id :%d\n", stud[i].Id);
                        printf("        Student first name :%s\n", stud[i].first_name);
                        printf("        Student last name :%s\n", stud[i].last_name);
                        printf("        Birth :%s\n", stud[i].birth);
                        printf("        Department :%s \n", stud[i].depart);
                        printf("        General Mark :%.2f \n", stud[i].mark);
                        printf("*******************************************************\n");
                    }
                    else
                        printf("------------Not found---------------\n");
                        printf("------------------------------------\n");
                }
        break;
        case 2:
                printf("Enter the department :");
                scanf(" %[^\n]s",&dep);
                for (int i=0;i<counter;i++){// loop to compare the the inputed department to the existed departs
                if (strcmp(stud[i].depart, dep)==0){
                        printf("***Student Id :%d\n", stud[i].Id);
                        printf("        Student first name :%s\n", stud[i].first_name);
                        printf("        Student last name :%s\n", stud[i].last_name);
                        printf("        Birth :%s\n", stud[i].birth);
                        printf("        Department :%s \n", stud[i].depart);
                        printf("        General Mark :%.2f \n", stud[i].mark);
                        printf("*******************************************************\n");
                }
                    else
                        printf("--------------Not found-------------\n");
                        printf("------------------------------------\n");
            }
        }
        main();
}
void    stats(){//some statistics
    int choice;//To store the selected
    int C=1;//counter
    float S=0,temp=0;//S = threshold, temp = store before swap

            printf("-----+++++++--------------------------+++++++-----------------------+-\n");// Stats menu
            printf("    1. Afficher le nombre total d'etudiants inscrits.\n");
            printf("     . Afficher le nombre d'etudiants dans chaque departement.\n");
            printf("    3. Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
            printf("    4. Afficher les 3 etudiants ayant les meilleures notes.\n");
            printf("    5. Afficher le nombre d'etudiants ayant reussi dans chaque departement.\n");
            printf("    6. Retour.\n");
            printf("-----------------------+++++++-------------------+++++++--------------\n");
            printf("Enter your selection: ");
            scanf("%d",&choice);//store selection to "choice"
            printf("-----------------------+++++++-------------------+++++++--------------\n");
                switch(choice){
                case 1:
                    printf("Total students number  : %d\n",counter);// List the total number of students based on the counter
                    stats();//Go back the stats menu
                    break;
                case 3:
                    printf("Enter the threshold :");
                    scanf("%f",&S);//Store the threshold in S
                    for (int i=0;i<counter;i++){
                        if(stud[i].mark >= S){//Check if the students mark greater or equal the S value
                            printf("\t\t--Student-- %d :\n",C);//Show the students who have mark greater or equal S
                                    printf("******** Student Id :%d\n", stud[i].Id);
                                    printf("    Student first name :%s\n", stud[i].first_name);
                                    printf("    Student last name :%s\n", stud[i].last_name);
                                    printf("    Birth :%s\n", stud[i].birth);
                                    printf("    Department :%s \n", stud[i].depart);
                                    printf("    General Mark :%.2f \n", stud[i].mark);
                                    printf("**************************************\n");
                            C++;
                        }
                    }
                    stats();//Go back the stats menu
                    break;
                case 4:
                    for(int i =0;i<counter;i++){// two loops to cover all the possibilities
                        for(int j=0;j<counter;j++){
                            if(stud[j].mark < stud[j+1].mark){// Doing the Swap technique to sort marks
                                temp = stud[j].mark;//store the first mark in an int called temp
                                stud[j].mark = stud[j+1].mark;//store next mark value in the previous one
                                stud[j+1].mark = temp;//take the temp value and put it in the second value
                            }
                        }
                    }
                    for(int i=0;i<3;i++){//loop to display * start with i=0 and i<3 to show only first 3
                        printf("\n");
                        printf("\t\t--Student-- %d :\n",i+1);// start the loop with the new order
                                    printf("******** Student Id :%d\n", stud[i].Id);
                                    printf("Student first name :%s\n", stud[i].first_name);
                                    printf("Student last name :%s\n", stud[i].last_name);
                                    printf("Birth :%s\n", stud[i].birth);
                                    printf("Department :%s \n", stud[i].depart);
                                    printf("General Mark :%.2f \n", stud[i].mark);
                                    printf("**************************************\n");
                    }
                    stats();//Go back the stats menu
                    break;
                case 5:
                    for (int i =0;i<counter;i++){//loop to check all students based on the counter
                        if(stud[i].mark >= 10){//condition to include and display only who have equal or greater than 10
                            printf("================================\n");
                            printf("Student : %s\n",stud[i].first_name);
                            printf("Student : %s\n",stud[i].last_name);
                            printf("Mark : %.2f",stud[i].mark);
                            printf("================================\n");
                        }
                    }
                   stats();//Go back the stats menu
                   break;
                case 6:
                    main();//Go back to main menu
                    break;
                }
}
int main(){
    int choice;

    do{
        printf("#####################################################\n");
        printf("#   1 - Ajouter un Etudiant                         #\n");
        printf("#   2 - Modifier un Etudiant                        #\n");
        printf("#   3 - supprimer un Etudiant                       #\n");
        printf("#   4 - Afficher les details d'un Etudiant          #\n");
        printf("#   - - Calculer la moyenne generale                #\n");
        printf("#   6 - Statistiques                                #\n");
        printf("#   7 - Rechercher un Etudiant                      #\n");
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
        //case 5:
            //calc();
            //break;
        case 6:
            stats();
            break;
        case 7:
            find();
            break;
        default:
            break;
        }

    }while(!(choice >= 1 && choice <= 7));
    return 0;
}
