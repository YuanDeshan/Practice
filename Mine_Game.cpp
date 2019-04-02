#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
/*#pragma comment(lib,"winmm.lib")*///��ý��ͷ�ļ�
#define MAX_ROW 10
#define MAX_COL 10
#define MINE_COUNT 10
#define PIX 60//���ش�С
int a[MAX_ROW][MAX_COL];
int hitnum;
IMAGE img[12];
void InitMap(){
	//��ʼ����ͼ
	hitnum = 0;
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
			a[MAX_ROW][MAX_COL] = 0;
		}
	}
	srand((unsigned)time(NULL));
	//�������ʮ������,������Ӧ��Ԫ�ظ�ֵ-1(-1������);
	int col, row;
	int n = MINE_COUNT;
	while (n>0){
		col = rand() % MAX_COL;
		row = rand() % MAX_ROW;
		if (a[row][col] == 0){//�жϸ�λ���Ƿ�ռ��
			a[row][col] = -1;
			--n;
		}
	}
	//���ɵ�ͼ
	//��������,ÿ�ҵ�һ����,�������8��Ԫ�ؼ�һ
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
			if (a[i][j] == -1){
				//ȷ������Χ��8��Ԫ��λ��
				for (int row = i - 1; row <= i + 1; ++row){
					for (int col = j - 1; col <= j + 1; ++col){
						//�ж�row,col�Ƿ�Խ����a[y][x]�Ƿ�Ϊ��,Ȼ�����Ӧ��Ԫ�ؼ�1
						if (col >= 0 && col < MAX_COL && row >= 0 && row < MAX_ROW && a[row][col] != -1){
							++a[row][col];
						}
					}
				}
			}
		}
	}
	//TODO ���Ե�ͼ
	/*for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
		printf("%d\t", a[i][j]);
		}
		putchar('\n');
		}*/
	//����ͼƬ
	/*for (int i = 0; i < 12; i++){*/
		loadimage(&img[0], _T("Picture/0.jpg"), PIX, PIX);
		loadimage(&img[1], _T("Picture/1.jpg"), PIX, PIX);//ͼƬ��С64*64
		loadimage(&img[2], _T("Picture/2.jpg"), PIX, PIX);
		loadimage(&img[3], _T("Picture/3.jpg"), PIX, PIX);
		loadimage(&img[4], _T("Picture/4.jpg"), PIX, PIX);
		loadimage(&img[5], _T("Picture/5.jpg"), PIX, PIX);
		loadimage(&img[6], _T("Picture/6.jpg"), PIX, PIX);
		loadimage(&img[7], _T("Picture/7.jpg"), PIX, PIX);
		loadimage(&img[8], _T("Picture/8.jpg"), PIX, PIX);
		loadimage(&img[9], _T("Picture/9.jpg"), PIX, PIX);
		loadimage(&img[10], _T("Picture/10.jpg"), PIX, PIX);
		loadimage(&img[11], _T("Picture/11.jpg"), PIX, PIX);

}
void DrawMap(){
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
			if (a[i][j]>20){
				putimage(j *  PIX, i *  PIX, &img[10]);
			}
			else{
				switch (a[i][j]){
				case 9://+10
					putimage(j *  PIX, i *  PIX, &img[9]);//��ͼ������+��ַ
					break;
				case 10:
					putimage(j *  PIX, i *  PIX, &img[0]);
					break;
				case 11:
					putimage(j *  PIX, i *  PIX, &img[1]);
					break;
				case 12:
					putimage(j *  PIX, i *  PIX, &img[2]);
					break;
				case 13:
					putimage(j *  PIX, i *  PIX, &img[3]);
					break;
				case 14:
					putimage(j *  PIX, i *  PIX, &img[4]);
					break;
				case 15:
					putimage(j *  PIX, i *  PIX, &img[5]);
					break;
				case 16:
					putimage(j *  PIX, i *  PIX, &img[6]);
					break;
				case 17:
					putimage(j *  PIX, i *  PIX, &img[7]);
					break;
				case 18:
					putimage(j *  PIX, i *  PIX, &img[8]);
					break;
				default:
					putimage(j *  PIX, i * PIX, &img[11]);
					break;
				}
			}
		}
	}
}
int Game(){
	MOUSEMSG msg = {0};//����һ�������Ϣ
	msg= GetMouseMsg();//��ȡ�����Ϣ
	switch (msg.uMsg){
		//�������������,������Ӧ��ͼƬ
	case WM_LBUTTONDOWN://   Left+button+down
		if (a[msg.y / PIX ][msg.x / PIX ] < 9){
			a[msg.y / PIX ][msg.x / PIX ] += 10;
			++hitnum;
		}
		return a[msg.y / PIX][msg.x / PIX];//���ص�ǰԪ�ص�ֵ
		break;
		//���ж�Ϊ�׵�λ�ü��ϱ��
	case WM_RBUTTONDOWN:// Right+button+down
		if (a[msg.y / PIX][msg.x / PIX] < 9){
			a[msg.y / PIX][msg.x / PIX] += 25;
		}
		//ȡ�����
		else if (a[msg.y / PIX][msg.x / PIX]>20){
			a[msg.y / PIX][msg.x / PIX] -= 25;
		}
		break;
	}


}
int main(){
	int flag;
	initgraph(PIX * MAX_ROW, PIX*MAX_COL);//��ӡһ������
	HWND hwnd = GetHWnd();//��ô��ھ��
	/*PlaySound()*/
	/*while (1)
	{*/
		InitMap();
		while (1){
			DrawMap();
			flag = Game();
			if (flag == 9){
				DrawMap();
				MessageBox(hwnd, _T("������,���!"), _T(""), MB_OK);
				break;
			}
			//����ܵ�����-�㿪������=�׵����� �������Ӯ��
			else if (MAX_ROW*MAX_COL - hitnum == MINE_COUNT){
				DrawMap();
				MessageBox(hwnd, _T("��ϲ��Ӯ��!"), _T(""), MB_OK);
				break;
			}
		}
		/*if (MessageBox(hwnd, _T("����һ��?"), _T(""), MB_RETRYCANCEL) == IDCANCEL){
			break;*/
		/*}*/
	//}
	system("pause");
	return 0;
}