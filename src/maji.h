#ifndef MAJI_H
#define MAJI_H

#define MAX_CUSTOMER 100
#define MAX_BOOK 100

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


typedef struct
{
    int ID;
    int if_borrow;
    string title;
} Book;

typedef struct
{
    int num;
    Book book[MAX_BOOK];
} BookShelf;

typedef struct
{
    int ID;
    string name;
    BookShelf books;
} Customer;

typedef struct
{
    int num;
    Customer customer[MAX_CUSTOMER];
} CustomerManagement;

#endif // MAJI_H