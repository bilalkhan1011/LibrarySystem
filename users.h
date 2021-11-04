//Header file for users.c.



#include <stdio.h>

typedef struct {
  char email[30]; //users email
  char name[30]; //users name
  char username[30]; //users username
  char password[30]; //users password
} User;


User *users[20]; //array of all users, stores pointer to a user struct.
extern int numUsers; //counter of number of users registered

//function that validates an email address by checking it includes '@'
//returns 0 if address is invalid and 1 if valid.
int validateEmail(char* emailAddress);

//function that validates password if its length is at least 8 and it contains
//at least 1 uppercase character and 3 digits. returns 0 for invalid password
int validatePassword(char* password);


//Function that iterates over users array to see if username is already taken.
int validateUsername(char* username);

//function to check email is valid and then add it to
//email variable of user struct.
int registerEmail(User *u, char* email);

//fucntion to check for valid password and assign to user.
int registerPassword(User *u, char* password);

//fucntion to check for valid username and assign to user.
int registerUsername(User *u, char* username);

//Function to implement all previous registration functions to fill
//fields in the user struct.
User* registerUser(User* u, char* name, char* email, char* username, char* password);

//Function to allow user to login with registered user and password.
int userLogin(char* username, char* password);

int loadUsers(FILE *file);

int saveUsers(FILE *file);
