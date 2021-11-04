// users.c file is a set of functions handling all the validation and registration of users within the library system.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#include "users.h"

User *users[20]; // array of all users



//function that validates an email address by checking it includes '@'
//returns 0 if address is invalid and 1 if valid.
int validateEmail(char* emailAddress){
  int symbolChecker = 0;
  int emailLength = strlen(emailAddress);
  for(int i = 0; i < emailLength; i++){
    if (emailAddress[i] == '@'){
      symbolChecker++;
    }
  }
  if (symbolChecker == 1){
    printf("Email accepted\n");
    return 1;
  }
  else {
    printf("Email address must include '@', please try again.\n");
    return 0;
  }
}


//function that validates password if its length is at least 8 and it contains
//at least 1 uppercase character and 3 digits. returns 0 for invalid password
int validatePassword(char* password){
  int upperCheck = 0;
  int digitCheck = 0;
  int passLength = strlen(password);

  for (int i = 0; i < passLength; i++){

    if(password[i]>='A' && password[i]<='Z'){
      upperCheck++;
    }
    else if(password[i]>='0' && password[i]<='9'){
      digitCheck++;
    }
  }

    if( (upperCheck >=1) && (digitCheck >= 3) && (passLength >= 8) ){
      printf("Password accepted\n");
      return 1;
    }
    else {
      printf("Password must include at least 8 characters, 3 numbers and 1 uppercase character.\n");
      return 0;
    }

  }



  //Function that iterates over users array to see if username is already taken.
  int validateUsername(char* username){
    for(int i = 0; i<numUsers; i++){
      int z = (strcmp(users[i]->username, username));
      if (z==0){
        printf("Username is taken please try again\n");
        return 0;
      }
    }
    printf("Username accepted");
    return 1;
  }

//Function to implement all previous registration functions to fill
//fields in the user struct.
User* registerUser(User* u, char* name, char* email, char* username, char* password) {
  u = (User*) malloc (sizeof(User));
  strcpy((u->name), name);
  strcpy((u->email), email);
  strcpy((u->username), username);
  strcpy((u->password), password);
  printf("User successfully registered.");
  return u;
}



//Function to allow user to login with registered user and password.
int userLogin(char* username, char* password){
  for(int i=0; i<numUsers; i++){
    if((strcmp((users[i]->username), username) == 0) && (strcmp((users[i]->password), password) == 0)){
      printf("\nUser logged in succesfully!");
      return 1;
    }
  }
  printf("\n\nUser not found\n\n");
  return 0;
}


  int loadUsers(FILE *file){
    file = fopen("users.bin","rb");
    if(file == NULL){
        return 404;
      }
    else {
      fscanf(file, "%d ", &numUsers);
      fread(&users, sizeof(User), numUsers, file);
      fclose(file);
      return 0;
    }
  }

  int saveUsers(FILE *file){
    file = fopen("users.bin","wb");
    if(file == NULL){
      return 404;
    }
    else {
      fprintf(file, "%d ", numUsers);
      fwrite(&users, sizeof(User), numUsers, file);
      fclose(file);
      return 0;
    }

  }
