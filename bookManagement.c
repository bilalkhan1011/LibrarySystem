// extra .c file containing functions for management of books within the library to be used in LibraryMain.c



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book_management.h"


struct Book books[10];


//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file)
{

  file = fopen("books.bin","wb");
  if(file == NULL){
    return 404;
  }
  else {
    fprintf(file, " %d", numBooks);
    fwrite(&books, sizeof(struct Book), numBooks, file);
    fclose(file);
    return 0;
  }

}

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file){

  file = fopen("books.bin","rb");
  if(file == NULL){
      return 404;
    }
  else {
    fscanf(file, " %d", &numBooks);
    fread(&books, sizeof(struct Book), numBooks, file);
    fclose(file);
    return 0;
  }
}

//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(struct Book book){
  books[numBooks] = book;
  return 0;
}

//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(struct Book book){
  int index = 1;
  for(int i=0; i<numBooks; i++){
    if((book.id) == (books[i].id)){
      books[i] = books[i+index];
      index++;
      numBooks--;
      return 0;
    }
  }
  return 404;

}

//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_title (const char *title){

  struct BookArray bookByTitle;
  int searchCounter = 0;
  for (int i=0; i<numBooks; i++){
    if (strcmp(books[i].title,title) == 0){
      printf("Book Found");
      bookByTitle.array[searchCounter] = books[i];
      searchCounter++;
    }
  }
  bookByTitle.length = searchCounter;
  return bookByTitle;
}

// //finds books with the given authors.
// //returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
// //provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
// //array is the null pointer.
// struct BookArray find_book_by_author (const char *author){
//   for (int i=0; i<numBooks; i++){
//     if (strcmp(books[i]->authors,author) == 0){
//
//     }
//   }
//
// }
//
// //finds books published in the given year.
// //returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the
// //provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
// //array is the null pointer.
// struct BookArray find_book_by_year (unsigned int year){
//   for (int i=0; i<numBooks; i++){
//     if (books[i]->year == year){
//
//     }
//   }
//
// }
