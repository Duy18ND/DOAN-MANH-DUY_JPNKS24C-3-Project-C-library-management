#include "datatype.h"
//nguyen mau ham
//LUA CHON 
void Choice_Login(int *choice_login);//lua chon dang nhap
void Choice_Menu(int *choice_menu);//lua chon chuc nang
//LOGIN
int LoginAdmin();//dang nhap tai khoan admin
void LoginUser();//dang nhap tai khoan User
void LoginNewUser();//dang ky User moi

//Lua chon quan ly
void Management();

//Menu Book
void MenuLogin();//hien thi lua chon login
void MenuBook();//menu quan ly sach
void MenuCustomer();//menu quan ly khach hang

//Chuc nang Book
int Display_Book  (int *number, Book Books[100]);//In sach
int Add_Book      (int *number, Book Books[100]);//Them Sach
int Modify_Book   (int *number, Book Books[100]);//sua danh sach Book
int Delete_Book   (int *number, Book Books[100]);//Xoa Book theo ID chi dinh
int Search_Book   (int *number, Book Books[100]);//Tim book theo ten 
int Arrange_Book  (int *number, Book Books[100]);//Sap Xep Book theo gia tien
int CheckData_Book(int *number, Book Books[100]);//Check du lieu nhap vao book co hop le khong

//Chuc nang quan ly khach hang
int Display_Customer  (int *length, Member Members[100]);//In thong tin khach hang
int Add_Customer      (int *length, Member Members[100]);//Them khach hang
int Modify_Customer   (int *length, Member Members[100]);//Sua thong tin khach hang
int Block_Customer    (int *length, Member Members[100]);//Mo khoa hoac khoa khach hang
int Search_Customer   (int *length, Member Members[100]);//Tim khach hang
int Borrow_Customer   (int *length, Member Members[100]);//Cho khach hang muon sach

int CheckData_Customer(int *length, Member Members[100]);//Check du lieu nhap khach hang co hop le khong

//GO BACK
int GoBack();

//FILE 
int Save_Book (int *number, Book Books[100]);//Luu Book vao file
int Load_Book (int *number , Book Books[100]);//Lay Du lieu tu FILE
int Save_Customer (int *length, Member Members[100]);//Luu du lieu vao FILE
int Load_Customer (int *length, Member Members[100]);//Lay du lieu tu FILE

