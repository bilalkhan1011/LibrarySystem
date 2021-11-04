//Main .c file for library system containing the implementation of functions from
//users.c and bookManagement.c.





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "book_management.h"
#include "users.h"


//print main menu before a user has logged in
void mainMenu(){
  printf("\nPlease choose an option\n");
  printf("1) Register an account\n");
  printf("2) Login\n");
  printf("3) Search for books\n");
  printf("4) Display all books\n");
  printf("5) Quit\n");
  printf(" Option: ");
}

//print menu for admin
void adminMenu(){
  printf("\nPlease choose an option\n");
  printf("1) Add a book\n");
  printf("2) Remove a book\n");
  printf("3) Search for books\n");
  printf("4) Display all books\n");
  printf("5) Log out\n");
  printf("\n Option: ");
}

//print menu for user who is logged in
void userMenu(){
  printf("\nPlease choose an option\n");
  printf("1) Borrow a book\n");
  printf("2) Return a book\n");
  printf("3) Search for books\n");
  printf("4) Display all books\n");
  printf("5) Log out\n");
  printf("\n Option: ");
}

//print search menu
void searchMenu(){
  printf("\nPlease choose an option\n");
  printf("1) Find books by title\n");
  printf("2) Find books by author\n");
  printf("3) Find books by year\n");
  printf("4) Return to previous menu\n");
  printf("\n Option: ");
}


void printBooks(){
  if(numBooks == 0){
    printf("There are currently no books in the library.\n");
  }
  else {
  printf("\n\n%-50s %-50s %-10s %-10s %-10s\n", "Title", "Authors", "Year", "Copies", "ID");
  for(int i=0; i<numBooks; i++){
    printf("%-50s %-50s %-10d %-10d %-10i\n", books[i].title, books[i].authors, books[i].year, books[i].copies,  books[i].id);
  }
}
}

int numBooks = 0;
int numUsers = 0;
int bookID = 0;



  int main(){
    printf("****************************************************************************************\t\t\t\n");

    User * admin;
    admin = ((User*) malloc (sizeof(User)));
    strcpy(admin->email, "admin@library.com");
    strcpy(admin->name, "Bilal Khan");
    strcpy(admin->username, "admin");
    strcpy(admin->password, "admin");
    users[numUsers] = admin;
    numUsers++;

    struct Book * book1;
    book1 = (struct Book*)malloc (sizeof(struct Book));
    book1->id = bookID;
    book1->title =  malloc(18);
    strcpy(book1->title, "Game Of Thrones");
    book1->authors = malloc(16);
    strcpy(book1->authors, "George RR Martin");
    book1->year = 1999;
    book1->copies = 6;
    add_book(*book1);
    numBooks++;
    bookID++;

    struct Book * book2;
    book2 = (struct Book*)malloc (sizeof(struct Book));
    book2->id = bookID;
    book2->title =  malloc(24);
    strcpy(book2->title, "Lord Of The Rings");
    book2->authors = malloc(13);
    strcpy(book2->authors, "JRR Tolkien");
    book2->year = 1976;
    book2->copies = 6;
    add_book(*book2);
    numBooks++;
    bookID++;




    // printf("\n\nLoading books from books.txt file\n");
    // FILE * loadBooks;
    // load_books(loadBooks);

    // printf("\n\n\nLoading users from users.txt file\n\n");
    // FILE * loadUser;
    // loadUsers(loadUser);


    int z = 0;
    int userChoice;
    while(z==0){

      mainMenu();
      scanf(" %i", &userChoice);

      //Register an account
      if(userChoice == 1){
        //prompt the user to enter their full name.
        char fullName[30];
        printf("Please enter your full name: ");
        getchar();
        fgets(fullName, sizeof(fullName), stdin);
        //prompt to enter email address and validate by checking for an '@' symbol.
        int a = 0;
        char emailAdd[45];
        while(a==0){
          printf("Enter email: ");
          scanf(" %s", emailAdd);
          int emailval = validateEmail(emailAdd);
          if (emailval == 1){
            break;
          }
        }
        //prompt user to enter username and check if it is already taken.
        int b = 0;
        char username[45];
        while (b==0){
          printf("Enter a username: ");
          scanf(" %s", username);
          if(validateUsername(username) == 1){
            break;
          }
        }
        //Prompt user for password and check it for one uppercase, 3 digits and 8 characters.
        int c = 0;
        char password[20];
        while(c==0){
          printf("Enter password: ");
          scanf(" %s", password);
          int passwordval = (validatePassword(password));
          if (passwordval == 1){
            break;
          }
        }
        //register user and add to array of users.
        User* u;
        u = (User*) malloc (sizeof(User));
        u = (registerUser(u, fullName, emailAdd, username, password));
        users[numUsers] = (u);
        numUsers++;
    }

    //user login
    else if(userChoice == 2){
      char username[20];
      printf("\nEnter a username: ");
      scanf(" %s", username);

      char password[20];
      printf("\nEnter password: ");
      scanf(" %s", password);

      if ((userLogin(username, password)) == 1){
        int r=0;
        while(r==0) {

          //logged in as admin
          if(strcmp(username, "admin") == 0){
            printf("\n(logged in as %s)", username);
            adminMenu();
            int adminChoice;
            scanf(" %i", &adminChoice);

            //Add a book
            if (adminChoice == 1){

              char titleAdd[30];
              printf("Enter a book title: ");
              getchar();
              fgets(titleAdd, sizeof(titleAdd), stdin);
              titleAdd[strlen(titleAdd)-1] = '\0';

              char authorsAdd[20];
              printf("Enter the books authors: ");
              fgets(authorsAdd, sizeof(authorsAdd), stdin);
              authorsAdd[strlen(authorsAdd)-1] = '\0';

              unsigned int yearAdd;
              printf("Enter year of publication: ");
              scanf(" %u", &yearAdd);

              unsigned int copiesAdd;
              printf("Enter number of copies: ");
              scanf(" %u", &copiesAdd);

              struct Book * book;
              book = (struct Book*)malloc (sizeof(struct Book));
              book->id = bookID;
              book->title =  malloc(strlen(titleAdd)+1);
              strcpy(book->title, titleAdd);
              book->authors = malloc(strlen(authorsAdd)+1);
              strcpy(book->authors, authorsAdd);
              book->year = yearAdd;
              book->copies = copiesAdd;
              add_book(*book);
              numBooks++;
              bookID++;
              printf("Book added successfully!\n\n");
            }

            //remove a book
            else if (adminChoice == 2){
              int removeBook;
              printBooks();
              printf("\nPlease enter the ID of the book you wish to remove: ");
              scanf(" %i", &removeBook);
              struct Book bookRemove;
              for(int y=0; y<numBooks; y++){
                if(books[y].id == removeBook){
                  remove_book(books[y]);
                }
              }
            }

            //search for books
            else if (adminChoice == 3){
              int l = 0;
              while (l == 0){
                searchMenu();
                int searchChoice;
                scanf(" %i", &searchChoice);


                //search by title
                if(searchChoice == 1){
                  char *titleSearch;
                  titleSearch = malloc(40);
                  printf("Please enter the title of the book you want to find: ");
                  getchar();
                  fgets(titleSearch, sizeof(titleSearch), stdin);
                  for(int w = 0; w<numBooks; w++){
                    if(strcmp(books[w].title, titleSearch) == 0){
                      printf("Book Found");
                      printf("%-50s %-50s %-10d %-10d %-10i\n", books[w].title, books[w].authors, books[w].year, books[w].copies,  books[w].id);
                    }
                  }
                }


                // else if(searchChoice ==2){
                //   find_book_by_author();
                // }
                // else if(searchChoice ==3){
                //   find_book_by_year();
                // }
                else if(searchChoice == 4){
                  printf("Returning to previous menu.\n");
                  break;
                }
                else {
                  printf("Invalid option entered try again.\n");
                }


              }
            }

            else if (adminChoice == 4){
              printBooks();
            }

            else if (adminChoice == 5){
              printf("Admin logged out\n");
              break;
            }
          }

          //logged in as user
          else{
            printf("\n(logged in as %s)", username);
            userMenu();
            int userChoice1;
            scanf(" %i", &userChoice1);

            //borrow a book
            if (userChoice1 == 1){
              printBooks();
              int borrowBook;
              printf("\nPlease enter the ID of the book you wish to borrow");
              scanf(" %i", &borrowBook);
              for(int o=0; o<numBooks; o++){
                if(books[o].id == borrowBook){
                  (books[o].copies)--;
                }
              }
            }

            //return a book
            else if(userChoice1 == 2){
              printBooks();
              int returnBook;
              printf("\nPlease enter the ID of the book you wish to return");
              scanf(" %i", &returnBook);
              for(int o=0; o<numBooks; o++){
                if(books[o].id == returnBook){
                  (books[o].copies)++;
                }
              }
            }

            else if(userChoice1 == 3){
              printf("Feature not implemented\n");
            }

            else if(userChoice1 == 4){
              printBooks();
            }

            else if(userChoice1 == 5){
              printf("User logged out");
              break;
            }

            else {
              printf("Invalid option entered try again.");
            }
        }
      }
    }
  }


    else if(userChoice == 3){
      printf("Feature not implemented\n");
    }

    else if(userChoice == 4){
      printBooks();
    }

    else if(userChoice == 5){
      // printf("\nStoring books");
      // FILE * storeBooks;
      // store_books(storeBooks);
      //
      // printf("\nStoring users\n");
      // FILE * storeUser;
      // saveUsers(storeUser);

      exit(1);
    }


    else {
      printf("Invalid option entered please try again");
    }



  }



  return  0;
  }
