#include "Display_module.h"
#include "book_management.h"
#include "Head_file.h"

void Display_module()
{
	Book *show; //用于遍历图书链表 
	show=Book_Head.array;
	
	//printf("%s",show->next->title);
	
	if(Book_Head.length==0) //如果书籍链表没有书 
	{
		printf("No data\n");
		return;
	}
	
	printf("ID\t");
	printf("Name\t");
	printf("Authors\t");
	printf("Year\t");
	printf("Copies\t");
	printf("Copies now\n");
	
	while(show!=NULL)
	{
		printf("%d\t",show->id);
		printf("%s\t",show->title);
		printf("%s\t",show->authors);
		printf("%d\t",show->year);
		printf("%d\t",show->copies);
		printf("%d\n",show->now_copies);
		show=show->next;
	}
	
	return;
}
