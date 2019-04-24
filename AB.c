/*****************************ͨѶ¼*********************************/
/*                   ����������������������������							
				    |	1. �����ϵ����Ϣ        |
					|	2. ɾ��ָ����ϵ����Ϣ    |
					|	3. ����ָ����ϵ����Ϣ    |
					|	4. �޸�ָ����ϵ����Ϣ    |
					|	5. ��ʾ������ϵ����Ϣ    |
					|	6. ���������ϵ��	     |
					|	7. ����������������ϵ��  |
					|	8. ������ϵ�˵��ļ�	     |
					|	9. ������ϵ��			 |				
					 ����������������������������				
*********************************************************************/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 1000

//����һ����ϵ����Ϣ�ṹ�壬���а�����ϵ���������Ա����䡢�绰����ַ��
//��Ϊ��������Ϊ��Contact_Info
typedef struct Contact_Info{
	char name[N];
	char sex[5];
	char age[N];
	char phone[N];
	char address[N];
}Contact_Info;

//����һ��ͨѶ¼�ṹ�壬���а��������ϵ�˸�������Ч��ϵ�˸���
//��Ϊ��������Ϊ��Address_Book
typedef struct Address_Book{
	Contact_Info contact[N];
	int size;
}Address_Book;

Address_Book g_address_book;//����һ��ȫ�ֱ���
//��ϵ����Ϣ��ʼ��
void Init(){
	g_address_book.size = 0;//��ʼ����Ч��ϵ�˸���Ϊ0
	for (int i = 0; i < N; ++i){
		g_address_book.contact[i].name[i] = '\0';
		g_address_book.contact[i].sex[i] = '\0';
		g_address_book.contact[i].age[i] = '\0';
		g_address_book.contact[i].phone[i] = '\0';
		g_address_book.contact[i].address[i] = '\0';
	}
}
//�˵�
int Menu(){
	printf("||==========�˵�===========||\n");
	printf("|| 1. �����ϵ����Ϣ       ||\n");
	printf("|| 2. ɾ��ָ����ϵ����Ϣ   ||\n");
	printf("|| 3. ����ָ����ϵ����Ϣ   ||\n");
	printf("|| 4. �޸�ָ����ϵ����Ϣ   ||\n");
	printf("|| 5. ��ʾ������ϵ����Ϣ   ||\n");
	printf("|| 6. ���������ϵ��       ||\n");
	printf("|| 7. ����������������ϵ�� ||\n");
	printf("|| 8. ������ϵ�˵��ļ�     ||\n");
	printf("|| 9. ������ϵ��           ||\n");
	printf("|| 0. �˳�                 ||\n");
	printf("||=========================||\n");
	printf("�������������������ѡ�\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
//�ú�����������������ʹ��ת�Ʊ�
void Empty(){

}
//�����ϵ��
void Add_Contact_Info(){
	printf("�����ϵ��\n");
	if (g_address_book.size > N){
		printf("�����ϵ��ʧ�ܣ�\n");
		return;
	}
	Contact_Info* contact_info = &g_address_book.contact[g_address_book.size];
	printf("��������ϵ��������");
	scanf("%s",contact_info->name);
	printf("��������ϵ���Ա�");
	scanf("%s", contact_info->sex);
	printf("��������ϵ�����䣺");
	scanf("%s", contact_info->age);
	printf("��������ϵ�˵绰��");
	scanf("%s", contact_info->phone);
	printf("��������ϵ�˵�ַ��");
	scanf("%s", contact_info->address);
	++g_address_book.size;
	printf("�����ϵ�˳ɹ���\n");
}
//ɾ��ָ����ϵ����Ϣ
void Delete_Contact_Info(){
	printf("ɾ��ָ����ϵ�ˣ�\n");
	if (g_address_book.size < 0){
		printf("ɾ����ϵ��ʧ�ܣ�ͨѶ¼Ϊ�գ�\n");
	}
	printf("������ָ����ϵ�˵���ţ�");
	int id;
	scanf("%d",&id);
	if (id < 0 || id >= g_address_book.size){
		printf("ɾ����ϵ��ʧ��,������ŷǷ���\n");
		return 0;
	}

	
	printf("ɾ����ϵ�˳ɹ���\n");
}
//����ָ����ϵ����Ϣ
void Find_Contact_Info(){
	printf("����ָ����ϵ�ˣ�\n");
	printf("");
}
//�޸�ָ����ϵ����Ϣ
void Update_Contact_Info(){

}
//��ʾȫ����ϵ����Ϣ
void Print_Contact_Info(){
	printf("��ӡȫ����ϵ��\n");
	for (int i = 0; i < g_address_book.size; ++i){
		Contact_Info* info = &g_address_book.contact[i];
		printf("[%d]%s\t%s\t%s\t%s\t%s\n",
		i, info->name, info->sex, info->age, info->phone, info->address);
	}
	printf("����ӡ��%d�����ݣ�\n", g_address_book.size);
	printf("��ӡȫ����ϵ�˳ɹ���\n");
}
//�����ϵ��
void Clear_Contact_Info(){
	printf("���ȫ����ϵ�ˣ�\n");
	g_address_book.size = 0;
	printf("���ȫ����ϵ�˳ɹ���\n");
}
//����������ȫ����ϵ��
void Sort_Contact_Info(){

}
//������ϵ�˵��ļ�
void Preserve_Contact_Info_Into_Files(){

}
//������ϵ��
void Loading_Contact_Info(){

}
typedef void(*Func)();
int main(){
    //ת�Ʊ�
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
			printf("������������\n");
			continue;
		}
		if (choice == 0){
			printf("Good bye!\n");
			break;
		}
		arr[choice]();//����ת�Ʊ���
	}
	Menu();
	system("pause");
	return 0;
}