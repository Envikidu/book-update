#ifndef BOOK_MANAGEMENT_GUARD__H 
#define BOOK_MANAGEMENT_GUARD__H
//#include "Head_file.h"

#include <stdio.h>



typedef struct _Book {   //��ڵ�Ľṹ�� 
	    unsigned int id;   //���id�� 
		char *title;   //������� 
		char *authors;   //������� 
		unsigned int year;  // ��ĳ������ 
		unsigned int copies;   //ͼ��ݼ�¼�ڰ��ĸ����ܿ�� 
		unsigned int now_copies;  //��ǰ����Ŀ�� 
		struct _Book *next;   //ָ����һ���� 
}Book;



typedef struct _BookArray {  //�����鼮�����ͷ�� 
	 Book* array;    //ָ�������еĵ�һ���� 
	 unsigned int length;   // �����������������������ͷ���鼮�����ж��ٽڵ㣩 
}BookArray;


BookArray Book_Head;  //�����鼮����ͷ����ʵ������������ͷ�� 






typedef struct _Users{  //�û��ڵ�Ľṹ�� 
	char name[99];  //�û������� 
	char password[99];  //�û������� 
	char real_name[99]; //��ʵ���� 
	int borrowed[99];   //�����¼��ǰ���û����ڽ�����ID��borrowed[0]��¼��һ�����id�ţ��Դ����� 
	int borrow_number;  //��¼�û���ǰ���ڽ��������� 
	struct _Users *next;  //ָ����һ���û� 
	
}Users;


typedef struct _UsersArray{  //�����û������ͷ�� 
	Users *array;  //ָ�������е�һ���û� 
	int number;  //�������û�����������������ͷ���û������ж��ٽڵ㣩 
}UsersArray;

UsersArray User_Head; //�����鼮����ͷ����ʵ������������ͷ�� 
//--------------------------------------------------------------------------------// 

Users *user_end; //ʼ��ָ��β�ڵ� 
Book *book_end;  //ʼ��ָ��β�ڵ� 


//interface.c 
int store_books();
int store_users(); 

int load_books();
int load_users();

int add_book();
int add_user();



//int login_flag;  //��¼�Ƿ�ǰ���û���¼��1Ϊ���û���¼״̬��2Ϊ����Ա��¼״̬ 


//Registration_module.c

 
int remove_books();

void find_book_by_title (char titles[]);
void find_book_by_author (char author[]);
void find_book_by_year (int years);


#endif
