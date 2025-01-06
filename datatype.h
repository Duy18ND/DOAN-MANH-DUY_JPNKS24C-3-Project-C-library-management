#include<stdbool.h>
//cau truc 
struct login{//cau truc dang nhap tk,mk
//tai khoan nguoi dung nhap vao 
	char Email[150];
	char Password[100];	
};
typedef struct {//Quan ly thoi gian muon sach cua khach hang
	int mouth, day, year;
}Date;

typedef struct {//Quan ly Book
	int ID;
	char Name[100];
	char Author[100]; 
	int Quantity;
	double Price;
	Date publication;
}Book;

typedef struct {//Quan ly Khach hang
	int ID;
	char Name[100];
	char Email[150];
	char Phone[20];
	char Status[20];
	Book BorrowBooks[];
}Member;


