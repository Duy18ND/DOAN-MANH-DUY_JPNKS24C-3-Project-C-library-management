#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main(int argc, char *argv[]) {
	int choice_managemet; //Lua chon quan ly
	int choice_login;//Lua chon dang nhap
	int choice_menu;//lua chon chuc nang trong menu
	int number = 5;// 5 Phan tu cua Books
	int check;
	Book Books[100] = {//Quan ly Book
	{1,"Truyen Kieu","Nguyen Du",5 ,45},
	{2,"Doraemon","Fujiko",7 ,15},
	{3,"One Piece","Oda",3 ,20},
	{4,"Mat Biec","Nguyen Nhat Anh",9 ,40},
	{5,"Dat Rung Phuong Nam","Doan Gioi",12 ,35}
	};
	int length = 5;// 5 Phan tu cua Quan ly khach hang
	Member Members[100] = {//Quan ly khach hang
	{1,"Doan Manh Duy","duy18namdinh@gmail.com","023452232", "OPEN"},
	{2,"Tran Van A","TranVanA@gmail.com","082381221", "OPEN"},
	{3,"Do Van B","DoVanB@gmail.com","083478232", "OPEN"},
	{4,"Dao Xuan C","DaoXuanC@gmail.com","096783456", "OPEN"},
	{5,"Vu Van Diep","VuVanDiep@gmail.com","097436234", "OPEN"},
	};
	
	MenuLogin();//Hien thi Menu dang nhap tai khoan , mat khau
	Choice_Login(&choice_login);//Lua chon cach thuc dang nhap
	
switch(choice_login){//Lua chon cach dang nhap
	
	case 0://Thoat khoi chuong trinh
	printf("Ban da thoat khoi login\n");
		break;
		
	case 1://login admin
		LoginAdmin();
		Management();
		printf("Moi ban lua chon\n");
		scanf("%d",&check);
		
		
			if(check == 1){//Menu Quan ly sach
			while(choice_menu !=8){
					MenuBook();
					Choice_Menu(&choice_menu);
					
					switch(choice_menu){//switch lua chon menu
					case 1:
						Load_Book (&number , Books);
						Display_Book(&number,Books);//In Book
						break;
						
					case 2:	
						if(Add_Book(&number, Books) == 2){//Them book
							Save_Book(&number, Books);
						}
						break;
						
					case 3:
						if(Modify_Book(&number, Books) == 2){//Sua sach
							Save_Book (&number, Books);
						}
						break;
					
					case 4:
						if(Delete_Book(&number, Books) == 2){//Xoa
						Save_Book (&number, Books);
					}
						break;
						
					case 5:
						Search_Book(&number,Books);//Tim sach
						break;
						
					case 6:
						if(Arrange_Book (&number,Books) == 2){//Sap Xep Book
						Save_Book(&number, Books);
					}
						break;
						
					case 7:
						if(CheckData_Book(&number,Books) == 2){
						Save_Book (&number,Books);
						}
						break;
						
					case 8:
						printf("Cam On Ban Da Su Dung Chuong Trinh Cua Minh ^^ \n");
						break;
						
					default:
						printf("LUA CHON CUA BAN KHONG HOP LE. VUI LONG NHAP LAI!!!\n");
						
				}//switch lua chon menu	
			}	
		}
		
			if(check == 2){
			while(choice_menu !=8){
			//Menu quan ly khach hang
				MenuCustomer();//Menu quan ly khach hang
				Choice_Menu(&choice_menu);//Lua chon menu quan ly khach hang
			
				switch(choice_menu){
						case 1:
						Load_Customer (&length, Members);
						Display_Customer (&length, Members);//In thong tin khach hang 
						break;
						
						case 2:
						if(Add_Customer (&length, Members) == 2){//Them khach hang
						Save_Customer (&length, Members);
					}
							break;	
						
						case 3:
						if(Modify_Customer (&length, Members) == 2){//Sua thong tin khach hang
						Save_Customer (&length, Members);
					}

							break;	
						
						case 4:
						Block_Customer (&length, Members);//Block va Open khach hang
						Save_Customer (&length, Members);
							break;
						
						case 5:
							Search_Customer (&length, Members);
							break;
						
						case 6:
							//Chua hoan thien

							break;
							
						case 7:
							//Chua hoan thien
							break;
							
						case 8:
							if(CheckData_Customer (&length, Members) == 2){
							Save_Customer (&length, Members);
							}
							break;
						
						case 9:
						printf("Cam On Ban Da Su Dung Chuong Trinh Cua Minh ^^ \n");
						break;
						
					default:
						printf("LUA CHON CUA BAN KHONG HOP LE. VUI LONG NHAP LAI!!!\n");
				}//switch quan ly khach hang
			}
		}	
			break;
	
	
	
	
	case 2://login Student
	
		break;
	
	case 3://teacher
	
		break;
		
	default:
		printf("Lua chon cua ban khong hop le. Vui long chon lai\n");	
}
	return 0;

}
