    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct student{
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
void    calc(){
     char T[20][50];
     int countDep=0;
     int stocker = 0;
     float somme = 0;
     int lengthDep = 0;
        for (int i = 0; i < counter; i++){
            for (int j = 0; j < i; j++){
                if (strcmp(stud[i].depart, stud[j].depart) == 0){
                stocker = 1;
                break;
                }
            }
                if (!stocker){
                      strcpy(T[countDep], stud[i].depart);
                      countDep++;
                }
        }

        for (int i = 0; i < countDep; i++){
            for (int j = 0; j < counter; j++){
                if (strcmp(T[i], stud[j].depart) == 0){
                    somme += stud[j].mark;
                    lengthDep++;
                }
            }
        printf("Department %s = %.2f \n",stud[i].depart,somme / lengthDep);
        }
        main();
}
void    first_menu(){ // function to show the menu of elements
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
void    affiche(){
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
void    del(){
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
void    find(){
        char name[20];//to store the name to be founded
        char dep[20];//to store the department to be founded
        int select;//store the user selection
        int N=0;
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
                    N++;
                }
                    else
                        printf("--------------Not found-------------\n");
                        printf("------------------------------------\n");
            }
        }
        main();
}
void stats(){
    int choice;//To store the selected
    char depS[20];
    char depR[20];
    int N=1,C=1,X=1;
    float S=0,temp=0;
    char T[20][50];
    int countDep=0;
    int stocker = 0;
    float somme = 0;
    int lengthDep = 0;

            printf("-----+++++++--------------------------+++++++-------------\n");
            printf("1. Afficher le nombre total d'etudiants inscrits.\n");
            printf("2. Afficher le nombre d'etudiants dans chaque departement.\n");
            printf("3. Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
            printf("4. Afficher les 3 etudiants ayant les meilleures notes.\n");
            printf("5. Afficher le nombre d'etudiants ayant reussi dans chaque departement.\n");
            printf("6. Retour.\n");
            printf("-----------------------+++++++-------------------+++++++--\n");
            printf("Enter votre choix: ");
            scanf("%d",&choice);
                switch(choice){
                case 1:
                    printf("Total students number  : %d.\n",counter);
                    stats();
                    break;
                case 2:
                    for (int i = 0; i < counter; i++){
                        for (int j = 0; j < i; j++){
                            if (strcmp(stud[i].depart, stud[j].depart) == 0){
                            stocker = 1;
                            break;
                            }
                        }
                    if (!stocker){
                          printf("%s\n", stud[i].depart);
                          strcpy(T[countDep], stud[i].depart);
                          countDep++;
                        }
                    }
                    for (int i = 0; i < countDep; i++){
                        for (int j = 0; j < counter; j++){
                                if (strcmp(T[i], stud[j].depart) == 0){
                                    somme += stud[j].mark;
                                    lengthDep++;
                                }
                        }
                    }
                    for (int i=0;i<countDep;i++)
                    printf("Department %s = %.2f \n: ", stud[i].depart, somme / lengthDep);
                break;
                case 3:
                    printf("Entrez le seuil :");
                    scanf("%f",&S);
                    for (int i=0;i<counter;i++){
                        if(stud[i].mark>=S){
                            printf("\t\t--Etudiant-- %d :\n",C);
                                    printf("******** Student Id :%d\n", stud[i].Id);
                                    printf("Student first name :%s\n", stud[i].first_name);
                                    printf("Student last name :%s\n", stud[i].last_name);
                                    printf("Birth :%s\n", stud[i].birth);
                                    printf("Department :%s \n", stud[i].depart);
                                    printf("General Mark :%.2f \n", stud[i].mark);
                                    printf("**************************************\n");
                            C++;
                        }
                    }
                    break;
                case 4:
                    for(int i =0;i<counter;i++){
                        for(int j=0;j<counter;j++){
                            if(stud[j].mark < stud[j+1].mark){
                                temp = stud[j].mark;
                                stud[j].mark = stud[j+1].mark;
                                stud[j+1].mark = temp;
                            }
                        }
                    }
                    for(int i=0;i<3;i++){
                        printf("\n");
                        printf("\t\t--Student-- %d :\n",i+1);
                                    printf("******** Student Id :%d\n", stud[i].Id);
                                    printf("Student first name :%s\n", stud[i].first_name);
                                    printf("Student last name :%s\n", stud[i].last_name);
                                    printf("Birth :%s\n", stud[i].birth);
                                    printf("Department :%s \n", stud[i].depart);
                                    printf("General Mark :%.2f \n", stud[i].mark);
                                    printf("**************************************\n");
                    }
                    break;
                case 5:
                    for (int i =0;i<counter;i++){
                        if(stud[i].mark >= 10){
                            printf("================================");
                            printf("Student : %s",stud[i].first_name);
                            printf("Student : %s",stud[i].last_name);
                            printf("Mark : %.2f",stud[i].mark);
                            printf("================================");
                        }
                    }
                case 6:
                    main();
                    break;
                }
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
        case 5:
            calc();
            break;
        case 6:
          stats();
            break;
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
