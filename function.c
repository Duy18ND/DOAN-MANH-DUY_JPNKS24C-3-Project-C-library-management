#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h> 
#include "function.h" 
//logic ham

void Choice_Login(int *choice_login){//lua chon logic 
			printf("Moi ban lua chon : ");
			scanf("%d",choice_login);
}

void Choice_Menu(int *choice_menu){//lua chon menu
			printf("Moi ban lua chon : ");
			scanf("%d",choice_menu);
}

int GoBack(){//Chuyen ve menu chuc nang
	
			char choice;
			
			printf("\n");
			printf("GO BACK(b) || EXIT(0) ");
			getchar();
			scanf("%c",&choice);
		if(choice == 'b'){
		}else if(choice == 0){
				return 1;	
			}
}

void Management(){//Lua chon quan ly Book hoac nguoi dung
			system("cls");
			
			printf("\n|=======================================|\n");
			printf("|\t     MANAGEMENT BOOK            |\n");
			printf("|=======================================|\n");
			printf("| [1]. Quan ly Book                     |\n");
			printf("| [2]. Quan ly khach hang               |\n");
			printf("|=======================================|\n");
			printf("\n");
} 

void MenuLogin(){//Menu lua chon dang nhap tai khoan
			printf("\n|=======================================|\n");
			printf("|\t     CHOOSE YOUR ROLE           |\n");
			printf("|=======================================|\n");
			printf("| [1] Admin                             |\n");  
			printf("| [2] User                              |\n");
			printf("| [3] New User                          |\n");
			printf("| [0] Exit The Program                  |\n");
			printf("|=======================================|\n");
}

int LoginAdmin(){//login admin
			system("cls");
			struct login logAdmin;	
			int check = -1;
		  	char checkEmail[] = "admin@email.com";  //Email cua admin
			char checkPass[] = "admin123";  // Pass cua admin
			
	do{//Neu nguoi dung dang nhap sai se duoc dang nhap lai
			fflush(stdin);
			printf("\t  LOGIN ADMIN             \n"); 	 
			printf("================================\n");
			printf("Email:(admin@email.com)=> ");//Yeu cau nguoi dung nhap tai khoan
			fgets(logAdmin.Email,sizeof(logAdmin.Email),stdin);
			logAdmin.Email[strcspn(logAdmin.Email, "\n")] = '\0';//strcspn tim do dai cua chuoi ky tu
			printf("Password:(admin123)=> ");//yeu cau nguoi dung nhap mat khau
			fgets(logAdmin.Password,sizeof(logAdmin.Password),stdin);//strcspn tim do dai cua chuoi ky tu
			logAdmin.Password[strcspn(logAdmin.Password, "\n")] = '\0';
			printf("================================\n");
			printf("\n");
			//Kiem tra tai khoan va mat khau da dung chua?

		if(strcmp(logAdmin.Email, checkEmail) ==0 && strcmp(logAdmin.Password, checkPass) == 0){//strcmp so sanh 
					check =1;
					printf("Dang nhap thanh cong \n");
					GoBack();//Tro ve Menu
			}else{
					printf("Dang Nhap khong thanh cong\n");
			}
			
	}while(check != 1);//while
}

void MenuBook(){//Hien thi menu danh sach
			system("cls");
			
		    printf("\n|=================================================|\n");
			printf("|                ***MENU***                       |\n");
			printf("===================================================\n");
			printf("| [1]. Hien thi so danh sach dang quan ly         |\n");//hien thi Book dang quan ly
			printf("| [2]. Them sach vao danh sach                    |\n");//Them Book vao danh sach
			printf("| [3]. Sua thong tin sach                         |\n");//Sua thong tin sach
			printf("| [4]. Xoa sach tai ID chi dinh                   |\n");//Xoa sach theo ID
			printf("| [5]. Tim sach theo ten                          |\n");//Tim sach theo Name
			printf("| [6]. Sap Xep theo gia tien                      |\n");//Sap xep sach theo gia tien [Tang dan] or [Giam dan]
			printf("| [7]. Check neu khong hop le thi yeu cau nhap lai|\n");//Sap xep sach theo gia tien [Tang dan] or [Giam dan]
			printf("| [8]. Thoat [EXIT]                               |\n");//Thoat khoi chuong trinh
			printf("|=================================================|\n");
} 

int Display_Book ( int *number, Book Books[100]){//Hien thi Book dang quan ly
			system("cls");
			
			printf("\n");
			printf("|=========================================================================================|\n");
		    printf("|                        DANH SACH BOOK DANG QUAN LY                                      |\n");
		  	printf("|============================================================================|============|\n");
		    printf("|============|===========================|======================|============|============|\n");
		    printf("|   BookID   |         Ten Sach          |     Ten Tac Gia      |  So Luong  |  Gia Tien  |\n");
		    printf("|============|===========================|======================|============|============|\n");
    	
		for (int i = 0; i < *number; i++) {
	   		printf("| %-10d | %-25s | %-20s | %-10d | %-10.3lf |\n",
            Books[i].ID, 
            Books[i].Name, 
            Books[i].Author, 
            Books[i].Quantity,
            Books[i].Price);
   		}
   			printf("|=========================================================================================|\n");
		
			GoBack();//Tro ve Menu
}

int Add_Book (int *number, Book Books[100]){//Them Book
			int temp;
			int count =2; 
			system("cls");
			
			printf("\n");
			printf("Nhap so luong can them la: ");
			scanf("%d",&temp);
			printf("\n");
			
		for(int i=0;i<temp;i++){
			Books[*number].ID = *number +1;
			printf("ID: %d\n",Books[*number].ID);
	
			fflush(stdin);
			printf("Moi ban nhap ten sach: ");
			fgets(Books[*number].Name,sizeof(Books[*number].Name),stdin);
			Books[*number].Name[strcspn(Books[*number].Name, "\n")] = '\0';
			
			printf("Moi ban nhap ten tac gia: ");
			fgets(Books[*number].Author,sizeof(Books[*number].Author),stdin);
			Books[*number].Author[strcspn(Books[*number].Author, "\n")] = '\0';
			
			printf("Nhap so luong sach hien co: ");
			scanf("%d",&Books[*number].Quantity);
			
			printf("Moi ban nhap gia tien: ");
			scanf("%lf",&Books[*number].Price);
			(*number)++;
		}
		
		//Kiem tra sach nhap vao co hop le khong	
		for(int i=0 ;i< *number;i++){
			int size = strlen(Books[i].Name);
			if( size > 0 ){//Kiem tra do dai cua sach
				}else{
					printf("\n");
					printf("Do dai Book ID: %d khong hop le\n",i+1);
					count = 0;
				}			
		}
		
		//Kiem tra ID co trung nhau hay khong
		for(int i=0; i< *number; i++){
			for(int j=i+1; j< *number;j++){
				if(Books[i].ID == Books[j].ID){//Kiem tra ID sach co trung nhau khong
					printf("\n");
					printf("ID: %d trung voi ID: %d. VUI LONG KIEM TRA LAI!!! \n",i+1,j+1);	
					count = 0;
				}
			}
		}
		
		//Kiem tra Name co trung nhau hay khong
		for(int i=0; i< *number; i++){
			for(int j= i +1 ; j< *number ; j++){
				if(strcmp(Books[i].Name, Books[j].Name) == 0){
					printf("\n");
					printf(" BOOK - ID: %d Trung voi  BOOK - ID: %d\n",i+1,j+1);
					count = 0;
				}
			}
		}
	
		GoBack();//Tro ve Menu
		return count;
}

int Modify_Book (int *number, Book Books[100]){//Sua thong tin sach
				system("cls");
				char check;
				int temp;
				int j;
				int count= -1;//Bien check ID
			
				printf("\n");
				printf("Moi ban nhap ID can sua la:");
				scanf("%d",&temp);
			
		if(temp <0){
			printf("ID CAN XOA KHONG HOP LE\n");
			return 1;
		}
			
			printf("******************Thong Tin Book*******************\n");
		for(int i=0;i<*number;i++){
			if(Books[i].ID == temp){//Check ID co ton tai khong
				count = 1;
				j = i;
				printf("ID: %d\n",Books[i].ID);
				printf("Ten sach: %s \n",Books[i].Name);
				printf("Ten tac gia: %s\n",Books[i].Author);
				printf("So luong hien co: %d\n",Books[i].Quantity);
				printf("Gia tien: %.3lf\n",Books[i].Price);
				printf("\n");
			}
		}
		
			if(count == -1){
				printf("ID KHONG TON TAI\n");
			}
		
				getchar();
				printf("\n");
				printf("YES(y) || NO(n) ");
				scanf("%c",&check);
				
			if(check == 'y'){
				count = 2;
				printf("**************Cap Nhap Thong Tin Sach**************\n");//Cap nhap thong tin sau khi sua
				
				Books[j].ID = temp;
				printf("ID: %d\n",Books[j].ID);
				
				fflush(stdin);
				printf("Moi ban nhap Ten sach: ");
				fgets(Books[j].Name,sizeof(Books[j].Name),stdin);
				Books[j].Name[strcspn(Books[j].Name, "\n")] = '\0';
				
				fflush(stdin);
				printf("Moi ban nhap Ten tac gia: ");
				fgets(Books[j].Author,sizeof(Books[j].Author),stdin);
				Books[j].Author[strcspn(Books[j].Author, "\n")] = '\0';
				
				printf("Nhap so luong sach :");
				scanf("%d",&Books[j].Quantity);
				
				printf("Moi ban nhap Gia tien: ");
				scanf("%lf",&Books[j].Price);
				
				printf("BAN DA SUA THANH CONG\n");
			}
			
			GoBack();//Tro ve Menu
			return count;
}

int Delete_Book ( int *number, Book Books[100]){//Xoa thong tin Book
				system("cls");
				char check;//Lua chon xoa hoac khong
				int temp;
				int count= -1;//Bien check ID
			
				printf("\n");
				printf("Moi ban nhap ID can xoa la:");
				scanf("%d",&temp);
				
			if(temp <0){
				printf("ID CAN XOA KHONG HOP LE\n");
				return 1;
			}
			
			printf("******************Thong Tin Book*******************\n");
		for(int i=0;i<*number;i++){
			if(Books[i].ID == temp){//Check ID co ton tai khong
				count = i;
				printf("ID: %d\n",Books[i].ID);
				printf("Ten Sach: %s \n",Books[i].Name);
				printf("Ten Tac Gia: %s\n",Books[i].Author);
				printf("So luong hien co: %d\n",Books[i].Quantity);
				printf("Gia Tien: %.3lf\n",Books[i].Price);
				printf("\n");
			}
		}
		
		if(count==-1){
				printf("ID KHONG TON TAI\n");
		}else{
				printf("DELETE (y) || NO DELETE (n)  ");
				getchar();	
				printf("Moi ban lua chon ");
				scanf("%c", &check);
			
			if(check == 'y'){//xoa
				count = 2;
				printf("XOA THANH CONG\n");
					for(int j= count ; j<*number ; j++){
						Books[j] = Books[j+1];
					}		
				(*number)--;
			}
		}
		
			GoBack();//Tro ve Menu
			return count;
}

int Search_Book (int *number, Book Books[100]){//Tim Book theo ID
				system("cls");
				int temp =0;
				char search[100];
			
				fflush(stdin);
				printf("Nhap sach ban muon tim la: ");
				fgets(search,sizeof(search),stdin);
				search[strcspn(search, "\n")] = '\0'; 
				
				search[0] = toupper(search[0]);
			
				printf("\n");
				printf("|=========================================================================================|\n");
			    printf("|                           DANH SACH BOOK DANG QUAN LY                                   |\n");
			  	printf("|=========================================================================================|\n");
			    printf("|============|===========================|======================|============|============|\n");
			    printf("|   BookID   |         Ten Sach          |     Ten Tac Gia      |  So Luong  |  Gia Tien  |\n");
			    printf("|============|===========================|======================|============|============|\n");
		    
		for(int i=0;i< *number;i++){
			if(strstr(Books[i].Name, search)!= NULL){
		   		printf("| %-10d | %-25s | %-20s | %-10d | %-10.3lf |\n",
	            Books[i].ID, 
	            Books[i].Name, 
	            Books[i].Author,
				Books[i].Quantity, 
	            Books[i].Price);
	        printf("|=========================================================================================|\n");
	            temp =1;
   			} 
   		}
   		
			if(temp ==0){
			   	printf("\n");
   				printf("\tBOOK BAN TIM KHONG CO TRONG DANH SACH!!!\n");
			}
			
			GoBack();//Tro ve Menu
}

int Arrange_Book (int *number,Book Books[100]){//Sap xep Book theo gia tien
				system("cls");
				int i,j;
				int check;
				int count = -1;
				int variable = 0;
	
				getchar();
				printf("[1] Sap xep theo thu tu tang dan \n");
				printf("[2] Sap xep theo thu tu giam dan\n");
				printf("[3] Sap xep lai ID\n");//theo thu tu tang dan
	
				printf ("\n");
				printf("Moi ban lua chon: ");
				scanf("%d",&check);
			
	if(check == 1){//tang dan
		for(i=0 ; i< *number ; i++){
			for(j=0 ; j< *number-i-1 ; j++){
				if(Books[j].Price > Books[j+1].Price){
					count =2;
					Book temp = Books[j];
					Books[j] = Books[j+1];
					Books[j+1] = temp;
				}
			}
		}
	} 
	
	if(check == 2){//giam dan
		for(i=0 ; i< *number ; i++){
			for(j=0 ; j< *number-i-1 ; j++){
				if(Books[j].Price < Books[j+1].Price){
					count =2;
					Book temp = Books[j];
					Books[j] = Books[j+1];
					Books[j+1] = temp;
				}
			}
		}
	}
	
	if(check == 3){//Sap xep theo ID
		for(int i=0 ;i< *number;i++){
			for(j=0 ; j< *number-i-1 ; j++){
				if(Books[j].ID > Books[j+1].ID){
					count =2;
					Book temp = Books[j];
					Books[j] = Books[j+1];
					Books[j+1] = temp;
				}
			}
		}
	} 
	
			if(count == 0){//lua chon khong hop le
				printf("LUA CHON CUA BAN KHONG HOP LE !!!\n");
			}
	
			if(count == 2){//Thong bao ket qua
				printf("Sap xep thanh cong\n");
			}else if(!count){
			printf("Sap xep khong thanh cong\n");
			}
			
			GoBack();//Tro ve Menu
			return count;
} 

int CheckData_Book(int *number, Book Books[100]){//Check neu book trong du lieu or trung du lieu se duoc thay doi
				int result;//Lua chon thay doi ID nao
				int count = -1;
				//Kiem tra Name trong
				printf("\n");
				
		for(int i = 0 ; i < *number ; i++){
				char check[100];
				int size = strlen(Books[i].Name);
			if(size <= 0){
				count = 2;
				printf("ID: %d\n",i+1);
				printf("Du lieu Name Trong!!!. Vui long nhap Name: ");
				scanf("%25s",&check);
				strcpy(Books[i].Name, check);
				Books[i].Name[strcspn(Books[i].Name, "\n")] == '\0';
			}
		}
		
			//Kiem tra Author trong	
				printf("\n");
		for(int i=0 ; i < *number ; i++){
				char check[100];
				int size = strlen(Books[i].Author);
			if(size <= 0){
				count = 2;
				printf("ID: %d\n",i+1);
				printf("Du lieu Author trong!!!. Vui long nhap Author: ");
				scanf("%20s",&check);
				strcpy(Books[i].Author, check);
				Books[i].Author[strcspn(Books[i].Author, "\n")] == '\0';
			}
		}	
		
			//Kiem tra Price trong
		for(int i=0 ; i < *number ; i++){
				double check;
			if(Books[i].Price <= 0){
				count = 2;
				printf("ID: %d\n",i+1);
				printf("Du lieu Price trong!!!. Vui long nhap Price: ");
				scanf("%10lf",&check);
				Books[i].Price = check;
			}
		}	
		
			//Kiem tra So luong sach trong
		for(int i=0; i< *number;i++){
			if(Books[i].Quantity <=0){
				count = 2;
				printf("ID: %d\n",i+1);
				printf("Du lieu trong Quatity trong!!!. Vui long nhap Quatity: ");
				scanf("%d",&Books[i].Quantity);
			}
		}
			
			//kiem tra Name neu trung thi doi lai
		for(int i=0; i< *number; i++){
			for(int j= i +1 ; j< *number ; j++){
				if(strcmp(Books[i].Name, Books[j].Name) == 0){
						count = 2;
						
						printf("***********THONG TIN SACH TRUNG NHAU***********\n");
						printf("ID: %d\n",Books[i].ID);
						printf("Ten sach: %s\n",Books[i].Name);
						printf("Ten tac gia: %s\n",Books[i].Author);
						printf("So luong: %d\n",Books[i].Quantity);
						printf("Gia tien: %.3lf\n",Books[i].Price);
						
						printf("\n");
						
						printf("ID: %d\n",Books[j].ID);
						printf("Ten sach: %s\n",Books[j].Name);
						printf("Ten tac gia: %s\n",Books[j].Author);
						printf("So luong: %d\n",Books[j].Quantity);
						printf("Gia tien: %.3lf\n",Books[j].Price);
						
						printf("Nhap ID thay doi Name sach la: ");
						scanf("%d",&result);
					if(result == Books[i].ID){
						fflush(stdin);
						printf("Ten sach la: ");
						fgets(Books[i].Name,sizeof(Books[i].Name),stdin);
						Books[i].Name[strcspn(Books[i].Name, "\n")] = '\0';
					}else if(result == Books[j].ID){
						fflush(stdin);
						printf("Ten sach la: ");
						fgets(Books[j].Name,sizeof(Books[j].Name),stdin);
						Books[j].Name[strcspn(Books[j].Name, "\n")] = '\0';
					}
				}
			}
		}
	
		GoBack();//Tro ve Menu
		return count;
}

int Save_Book(int *number, Book Books[100]){//Luu du lieu vao FILE
			
			//Mo FILE
			FILE *fptr;
			fptr = fopen("BookData.dat","wb");//LUU FILE
			
			//Thao tac voi FILE
			if(fptr == NULL){//Kiem tra FIle
				printf("Khong mo  duoc FILE\n");
			}
			fwrite(Books, sizeof(Book), *number, fptr);
			printf("Luu FILE thanh cong\n");
			//Dong FILE
			fclose(fptr);	
}

int Load_Book (int *number , Book Books[100]){//Doc du lieu
			//Mo FILE
			FILE *fptr;
			fptr = fopen("BookData.dat","rb");//Doc File
			//Thao tac voi FILE
			if(fptr == NULL){
				printf("Khong mo duoc FILE\n");	
			}
			Book ReadBook[100];
			*number = fread(ReadBook, sizeof(Book),100,fptr);
			for(int i=0 ;i < *number;i++){
				Books[i] = ReadBook[i];
			}
			//Dong FILE
			printf("Doc FILE thanh cong \n");
			fclose(fptr);	
}

void MenuCustomer(){//Hien thi menu quan ly khach hang
				system("cls");
				
				printf("\n|==========================================|\n");
				printf("|                ***MENU***                |\n");
				printf("============================================\n");
				printf("| [1]. Hien thi thong tin khach hang       |\n");//hien thi Book dang quan ly
				printf("| [2]. Them khach hang                     |\n");//Them Book vao danh sach
				printf("| [3]. Sua thong tin khach hang            |\n");//Sua thong tin sach
				printf("| [4]. Khoa va mo khoa khach hang          |\n");
				printf("| [5]. Tim kiem khach hang theo ten        |\n");
				printf("| [6]. DANG UPDATE                         |\n");
				printf("| [7]. DANG UPDATE                         |\n");
				printf("| [8]. Kiem tra du lieu nhap cho khach     |\n");
				printf("| [9]. Thoat [EXIT]                        |\n");
				printf("|==========================================|\n");
}

int Display_Customer(int *length, Member Members[100]) {//In danh sach khach hang 
			   system("cls");
			    
			   printf("\n");
			   printf("|=============================================================================================================|\n");
			   printf("|                                    DANH SACH KHACH HANG DANG QUAN LY                                        |\n");
			   printf("|=============================================================================================================|\n");
		       printf("|========|==========================|===============================|=========================|===============|\n");
			   printf("|   ID   |      Ten Khach Hang      |           Gmail               |      Phone              | Trang Thai    |\n");
			   printf("|========|==========================|===============================|=========================|===============|\n");
			
			for (int i = 0; i < *length; i++) {
		   	   printf("| %-6d | %-24s | %-29s | %-23s | %-13s |\n",
		           Members[i].ID, 
		           Members[i].Name, 
		           Members[i].Email, 
		           Members[i].Phone,
		           Members[i].Status);
			}
		   	   printf("|=============================================================================================================|\n"); 


			GoBack();//Tro ve Menu
}

int Add_Customer (int *length, Member Members[100]){//Them khach hang
				system("cls");
				int temp;
				int count = 2;
				
				printf("\n");
				printf("Nhap so luong can them : ");
				scanf("%d",&temp);
			
			for(int i=0; i< temp;i++){
				Members[*length].ID = *length +1;
				printf("ID: %d\n",Members[*length].ID);
				
				fflush(stdin);
				printf("Moi ban nhap Name: ");
				fgets(Members[*length].Name,sizeof(Members[*length].ID),stdin);
				Members[*length].Name[strcspn(Members[*length].Name, "\n")] = '\0';
				
				fflush(stdin);
				printf("Moi ban nhap Email: ");
				fgets(Members[*length].Email,sizeof(Members[*length].Email),stdin);
				Members[*length].Email[strcspn(Members[*length].Email, "\n")] = '\0';
				
				fflush(stdin);	
				printf("Moi ban nhap Phone: ");
				fgets(Members[*length].Phone,sizeof(Members[*length].Phone),stdin);
				Members[*length].Phone[strcspn(Members[*length].Phone, "\n")] = '\0';
				
				strcpy(Members[*length].Status, "OPEN");
				(*length)++;	
			}
		
		//Kiem tra ID co trung nhau hay khong
			for(int i=0; i< *length; i++){
				for(int j=i+1; j< *length;j++){
					if(Members[i].ID == Members[j].ID){//Kiem tra ID sach co trung nhau khong
					printf("\n");
					printf("ID: %d trung voi ID: %d. VUI LONG KIEM TRA LAI!!! \n",i+1,j+1);	
					count = 0;
					}
				}
			}
			
		//Kiem tra Phone co trung nhau khong
			for(int i=0; i< *length; i++){
				for(int j=i+1; j< *length;j++){
					if(strstr(Members[i].Phone, Members[j].Phone) != NULL){//Kiem tra ID sach co trung nhau khong
					printf("\n");
					printf("Phone ID: %d trung voi Phone ID: %d. VUI LONG KIEM TRA LAI!!! \n",i+1,j+1);	
					count = 0;
					}
				}
			}
			
		GoBack();//Tro ve Menu
		return count;
}

int Modify_Customer (int *length, Member Members[100]){//Sua thong tin khach hang
		
				system("cls");
				char check;
				int temp;
				int j;
				int count= -1;//Bien check ID
			
				printf("\n");
				printf("Moi ban nhap ID can sua la:");
				scanf("%d",&temp);
			
			if(temp <0){
				printf("ID CAN XOA KHONG HOP LE\n");
				return 1;
			}
			
			printf("******************Thong Tin Khach Hang*******************\n");
		for(int i=0;i<*length;i++){
			if(Members[i].ID == temp){//Check ID co ton tai khong
				count = 2;
				j = i;
				printf("ID: %d\n",Members[i].ID);
				printf("Name: %s \n",Members[i].Name);
				printf("Email: %s\n",Members[i].Email);
				printf("Phone: %s\n",Members[i].Phone);
				printf("Trang thai: %s\n",Members[i].Status);
				printf("\n");
			}
		}
		
			if(count == -1){
				printf("ID KHONG TON TAI\n");
				return 1;
			}
		
				getchar();
				printf("\n");
				printf("YES(y) || NO(n) ");
				scanf("%c",&check);
				
			if(check == 'y'){
				count = 2;
				printf("**************Cap Nhap Thong Tin Khach Hang**************\n");//Cap nhap thong tin sau khi sua
				
				Members[j].ID = temp;
				printf("ID: %d\n",Members[j].ID);
				
				fflush(stdin);
				printf("Moi ban nhap Name: ");
				fgets(Members[j].Name,sizeof(Members[j].Name),stdin);
				Members[j].Name[strcspn(Members[j].Name, "\n")] = '\0';
				
				fflush(stdin);
				printf("Moi ban nhap Email: ");
				fgets(Members[j].Email,sizeof(Members[j].Email),stdin);
				Members[j].Email[strcspn(Members[j].Email, "\n")] = '\0';
				
				fflush(stdin);
				printf("Moi ban nhap Phone: ");
				fgets(Members[j].Phone,sizeof(Members[j].Phone),stdin);
				Members[j].Phone[strcspn(Members[j].Phone, "\n")] = '\0';
				
				printf("BAN DA SUA THANH CONG\n");
			}
			
			GoBack();//Tro ve Menu
			return count;
}

int Block_Customer (int *length, Member Members[100]){//Khoa hoac mo khoa nguoi dung
				system("cls");
				int temp;//Lua chon ID
				char n;//Co thay doi hay khong
				int i;
				int check = -1;//Bien check ID co ton tai hay khong
				
				printf("\n");
				printf("Nhap ID Khoa va Mo Khoa la: ");
				scanf("%d",&temp);
				printf("****************THONG TIN HIEN TAI******************\n");
			
		for( i=0; i< *length; i++){
			if(Members[i].ID == temp){
					check =i;
				printf("ID: %d\n",Members[i].ID);
				printf("Ho Va Ten: %s\n",Members[i].Name);
				printf("Email: %s\n",Members[i].Email);
				printf("Phone: %s\n",Members[i].Phone);
				printf("Status: %s\n",Members[i].Status);
			}
		}

			if(check != -1){
				getchar();
				printf("[y] BLOCK || [n] NO BLOCK\n");
				printf("Moi ban lua chon : ");
				scanf("%c",&n);
				
				if(n == 'y'){
					strcpy(Members[check].Status, "BLOCK");
					printf("BLOCK thanh cong\n");
				}
				
				if(n == 'n'){
					strcpy(Members[check].Status, "OPEN");
					printf("Xoa BLOCK thanh cong\n");
				}
			
			}else{
			printf("ID ban tim khong ton tai!!!\n");
			}
	
		GoBack();//Tro ve Menu
}

int Search_Customer (int *length, Member Members[100]){//Tim Book theo ID
				system("cls");
				int temp =0;
				char search[100];
			
				fflush(stdin);
				printf("Nhap Book Ban muon tim la: ");
				fgets(search,sizeof(search),stdin);
				search[strcspn(search, "\n")] = '\0'; 

				search[0] = toupper(search[0]);
			
				printf("\n");
			    printf("|=============================================================================================================|\n");
				printf("|                                    DANH SACH KHACH HANG DANG QUAN LY                                        |\n");
				printf("|=============================================================================================================|\n");
				printf("|========|==========================|===============================|=========================|===============|\n");
				printf("|   ID   |      Ten Khach Hang      |           Gmail               |      Phone              | Trang Thai    |\n");
				printf("|========|==========================|===============================|=========================|===============|\n");

		    
		for (int i = 0; i < *length; i++) {
			if(strstr(Members[i].Name, search)!= NULL){
               printf("| %-6d | %-24s | %-29s | %-23s | %-13s |\n",
	           Members[i].ID, 
	           Members[i].Name, 
	           Members[i].Email, 
	           Members[i].Phone,
	           Members[i].Status);
			}
				   temp = 1;
		}
		   	    printf("|=============================================================================================================|\n");

			if(temp ==0){
			   	printf("\n");
   				printf("\tKHACH HANG MUON TIM KHONG CO TRONG DANH SACH!!!\n");
			}
			
			GoBack();//Tro ve Menu
}

int Borrow_Customer (int *length, Member Members[100]){//Cho khac muon sach
				int temp;
				int count  = 0;//Bien de check khach hang co ton tai khong
				char search[20];
				char Test[] = "OPEN";
				
				printf("Nhap ID khach hang muon sach la: ");
				scanf("%d",&temp);
		
		for(int i=0 ;i< *length; i++){	
			if(Members[i].ID == temp){//Check ID co trung khop hay khong
					count = 2;
					int result = strcmp(Members[i].Status, Test);
				
				if(result == 0){//Check khach hang co bi Block khong
					printf("Khach hang bi BLOCK, Khong the muon sach!!!\n");
					return 1;			
				}
				printf("Nhap sach muon muon la:");
				fflush(stdin);
				fgets(search,sizeof(search),stdin);
				search[strcspn(search, "\n")] = '\0';
			}
		}
		
			if(count == 0){
				printf("ID khach hang khong ton tai\n");
				return 1;
			}
}

int Pay_Customer ( int *length, Member Members[100]){
	
} 

int CheckData_Customer (int *length, Member Members[100]){//Check du lieu cho khach hang
	
				int result;//Lua chon thay doi ID nao
				int count;
				//Kiem tra Name trong
				printf("\n");
				
		for(int i = 0 ; i < *length ; i++){
				char check[100];
				int size = strlen(Members[i].Name);
			if(size <= 0){
				count = 2;
				printf("ID: %d\n",i+1);
				printf("Du lieu Name Trong!!!. Vui long nhap Name: ");
				scanf("%24s",&check);
				strcpy(Members[i].Name, check);
				Members[i].Name[strcspn(Members[i].Name, "\n")] == '\0';
			}
		}
		
			//Kiem tra Email trong	
				printf("\n");
		for(int i=0 ; i < *length ; i++){
				char check[100];
				int size = strlen(Members[i].Email);
			if(size <= 0){
				count = 2;
				printf("ID: %d\n",i+1);
				printf("Du lieu Email trong!!!. Vui long nhap Email: ");
				scanf("%29s",&check);
				strcpy(Members[i].Email, check);
				Members[i].Email[strcspn(Members[i].Email, "\n")] == '\0';
			}
		}	
		
			//Kiem tra Phone trong
		for(int i=0 ; i < *length ; i++){
				char check[20];
			if(Members[i].Phone <= 0){
				count = 2;
				printf("ID: %d\n",i+1);
				printf("Du lieu Phone trong!!!. Vui long nhap Phone: ");
				scanf("%23s",&check);
				strcpy(Members[i].Phone, check);
			}
		}	

		GoBack();//Tro ve Menu
		return count;
		
}

int Save_Customer (int *length, Member Members[100]){//Luu du lieu vao FILE
	//Mo FILE
			FILE *fptr;
			fptr = fopen("MemberData.dat","wb");//LUU FILE
			
			//Thao tac voi FILE
		if(fptr == NULL){//Kiem tra FIle
				printf("Khong mo  duoc FILE\n");
			}
			fwrite(Members, sizeof(Member), *length, fptr);
			printf("Luu FILE thanh cong\n");
			//Dong FILE
			fclose(fptr);	
}

int Load_Customer (int *length, Member Members[100]){//Lay du lieu FILE
			FILE *fptr;
			fptr = fopen("MemberData.dat","rb");//Doc File
			//Thao tac voi FILE
		if(fptr == NULL){
				printf("Khong mo duoc FILE\n");	
		}
			Member ReadMember[100];
			*length = fread(ReadMember, sizeof(Member),100,fptr);
		for(int i=0 ;i < *length;i++){
				Members[i] = ReadMember[i];
		}
			//Dong FILE
			printf("Doc FILE thanh cong \n");
			fclose(fptr);	
}

