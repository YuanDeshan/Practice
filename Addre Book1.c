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

//定义一个联系人信息结构体，其中包含联系人姓名、性别、年龄、电话、地址，并为其命名为：Contact_Info
typedef struct Contact_Info{
	char name[N];
	char sex[3];
	int age[N];
	char phone[N];
	char address[N];
}Contact_Info;

//定义一个通讯录结构体，其中包含最大联系人个数，有效联系人个数
struct Address_Book{
	Contact_Info contact[N];
	int size;
};

void Menu(){
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
}

void InitPerson(){
	
}

int main(){
	Menu();
	system("pause");
	return 0;
}