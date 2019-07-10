/*****************************通讯录*********************************/
/*                   ——————————————							
				    |	1. 添加联系人信息        |
					|	2. 删除指定联系人信息    |
					|	3. 查找指定联系人信息    |
					|	4. 修改指定联系人信息    |
					|	5. 显示所有联系人信息    |
					|	6. 清空所有联系人	     |
					|	7. 以名字排序所有联系人  |
					|	8. 保存联系人到文件	     |
					|	9. 加载联系人			 |				
					 ——————————————				
*********************************************************************/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 1000

//定义一个联系人信息结构体，其中包含联系人姓名、性别、年龄、电话、地址，
//并为其重命名为：Contact_Info
typedef struct Contact_Info{
	char name[N];
	char sex[5];
	char age[N];
	char phone[N];
	char address[N];
}Contact_Info;

//定义一个通讯录结构体，其中包含最大联系人个数，有效联系人个数
//并为其重命名为：Address_Book
typedef struct Address_Book{
	Contact_Info contact[N];
	int size;
}Address_Book;

Address_Book g_address_book;//定义一个全局变量
//联系人信息初始化
void Init(){
	g_address_book.size = 0;//初始化有效联系人个数为0
	for (int i = 0; i < N; ++i){
		g_address_book.contact[i].name[i] = '\0';
		g_address_book.contact[i].sex[i] = '\0';
		g_address_book.contact[i].age[i] = '\0';
		g_address_book.contact[i].phone[i] = '\0';
		g_address_book.contact[i].address[i] = '\0';
	}
}
//菜单
int Menu(){
	printf("||==========菜单===========||\n");
	printf("|| 1. 添加联系人信息       ||\n");
	printf("|| 2. 删除指定联系人信息   ||\n");
	printf("|| 3. 查找指定联系人信息   ||\n");
	printf("|| 4. 修改指定联系人信息   ||\n");
	printf("|| 5. 显示所有联系人信息   ||\n");
	printf("|| 6. 清空所有联系人       ||\n");
	printf("|| 7. 以名字排序所有联系人 ||\n");
	printf("|| 8. 保存联系人到文件     ||\n");
	printf("|| 9. 加载联系人           ||\n");
	printf("|| 0. 退出                 ||\n");
	printf("||=========================||\n");
	printf("请根据所需操作输入你的选项：\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
//该函数用来凑数，便于使用转移表
void Empty(){

}
//添加联系人
void Add_Contact_Info(){
	printf("添加联系人\n");
	if (g_address_book.size > N){
		printf("添加联系人失败！\n");
		return;
	}
	Contact_Info* contact_info = &g_address_book.contact[g_address_book.size];
	printf("请输入联系人姓名：");
	scanf("%s",contact_info->name);
	printf("请输入联系人性别：");
	scanf("%s", contact_info->sex);
	printf("请输入联系人年龄：");
	scanf("%s", contact_info->age);
	printf("请输入联系人电话：");
	scanf("%s", contact_info->phone);
	printf("请输入联系人地址：");
	scanf("%s", contact_info->address);
	++g_address_book.size;
	printf("添加联系人成功！\n");
}
//删除指定联系人信息
void Delete_Contact_Info(){
	printf("删除指定联系人！\n");
	if (g_address_book.size < 0){
		printf("删除联系人失败，通讯录为空！\n");
	}
	printf("请输入指定联系人的序号：");
	int id;
	scanf("%d",&id);
	if (id < 0 || id >= g_address_book.size){
		printf("删除联系人失败,输入序号非法！\n");
		return 0;
	}

	
	printf("删除联系人成功！\n");
}
//查找指定联系人信息
void Find_Contact_Info(){
	printf("查找指定联系人！\n");
	printf("");
}
//修改指定联系人信息
void Update_Contact_Info(){

}
//显示全部联系人信息
void Print_Contact_Info(){
	printf("打印全部联系人\n");
	for (int i = 0; i < g_address_book.size; ++i){
		Contact_Info* info = &g_address_book.contact[i];
		printf("[%d]%s\t%s\t%s\t%s\t%s\n",
		i, info->name, info->sex, info->age, info->phone, info->address);
	}
	printf("共打印了%d条数据！\n", g_address_book.size);
	printf("打印全部联系人成功！\n");
}
//清空联系人
void Clear_Contact_Info(){
	printf("清空全部联系人！\n");
	g_address_book.size = 0;
	printf("清空全部联系人成功！\n");
}
//以名字排序全部联系人
void Sort_Contact_Info(){

}
//保存联系人到文件
void Preserve_Contact_Info_Into_Files(){

}
//加载联系人
void Loading_Contact_Info(){

}
typedef void(*Func)();
int main(){
    //转移表
	Func arr[] = {
		Empty,
		Add_Contact_Info,
		Delete_Contact_Info,
		Find_Contact_Info,
		Update_Contact_Info,
		Print_Contact_Info,
		Clear_Contact_Info,
		Sort_Contact_Info,
		Preserve_Contact_Info_Into_Files,
		Loading_Contact_Info
	};

	Init();

	while(1){
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])){
			printf("您的输入有误！\n");
			continue;
		}
		if (choice == 0){
			printf("Good bye!\n");
			break;
		}
		arr[choice]();//调用转移表函数
	}
	Menu();
	system("pause");
	return 0;
}