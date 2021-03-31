#ifndef BOOK_MANAGEMENT_GUARD__H 
#define BOOK_MANAGEMENT_GUARD__H
//#include "Head_file.h"

#include <stdio.h>



typedef struct _Book {   //书节点的结构体 
	    unsigned int id;   //书的id号 
		char *title;   //书的名字 
		char *authors;   //书的作者 
		unsigned int year;  // 书的出版年份 
		unsigned int copies;   //图书馆记录在案的该书总库存 
		unsigned int now_copies;  //当前该书的库存 
		struct _Book *next;   //指向下一本书 
}Book;



typedef struct _BookArray {  //用于书籍链表的头部 
	 Book* array;    //指向链表中的第一本书 
	 unsigned int length;   // 链表中书的总数（即不包括头，书籍链表有多少节点） 
}BookArray;


BookArray Book_Head;  //声明书籍链表头部的实例，方便索引头部 






typedef struct _Users{  //用户节点的结构体 
	char name[99];  //用户的名字 
	char password[99];  //用户的密码 
	char real_name[99]; //真实姓名 
	int borrowed[99];   //数组记录当前该用户所在借的书的ID，borrowed[0]记录第一本书的id号，以此类推 
	int borrow_number;  //记录用户当前所在借的书的总数 
	struct _Users *next;  //指向下一个用户 
	
}Users;


typedef struct _UsersArray{  //用于用户链表的头部 
	Users *array;  //指向链表中第一个用户 
	int number;  //链表中用户的总数（即不包括头，用户链表有多少节点） 
}UsersArray;

UsersArray User_Head; //声明书籍链表头部的实例，方便索引头部 
//--------------------------------------------------------------------------------// 

Users *user_end; //始终指向尾节点 
Book *book_end;  //始终指向尾节点 


//interface.c 
int store_books();
int store_users(); 

int load_books();
int load_users();

int add_book();
int add_user();



//int login_flag;  //记录是否当前有用户登录，1为有用户登录状态，2为管理员登录状态 


//Registration_module.c

 
int remove_books();

void find_book_by_title (char titles[]);
void find_book_by_author (char author[]);
void find_book_by_year (int years);


#endif
