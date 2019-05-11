#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"Winmm.lib")
#define PIX 100
#define MAX_ROW 3
#define MAX_COL 3
int arr[MAX_ROW][MAX_COL];
int  hitnum=0;
int flag = 2;
IMAGE img[3];
void InitMap(){
	//初始化地图
	hitnum = 0;
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
			arr[i][j] = 0;
		}
	}
	loadimage(&img[0], _T("P/0.jpg"), PIX, PIX);
	loadimage(&img[1], _T("P/1.jpg"), PIX, PIX);//图片大小64*64
	loadimage(&img[2], _T("P/2.jpg"), PIX, PIX);
}
void Winner();
void DrawMap(){
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
				switch (arr[i][j]){
			case 10:
			case 11:
			case 12:
				putimage(j *  PIX, i *  PIX, &img[1]);
				Winner();
				break;
			case 20:
			case 21:
			case 22:
				putimage(j *  PIX, i *  PIX, &img[0]);
				Winner();
				break;
			default:
				putimage(j *  PIX, i *  PIX, &img[2]);
			}
		}
	}
}
void Game(){
	if (hitnum % 2 == 0){
		MOUSEMSG msg = { 0 };//定义一个鼠标消息
		msg = GetMouseMsg();//获取鼠标消息
		if (msg.uMsg == WM_LBUTTONDOWN&&arr[msg.y / PIX][msg.x / PIX] < MAX_ROW){
			PlaySound(TEXT("D:\\3.wav"), NULL, SND_FILENAME | SND_ASYNC);
			arr[msg.y / PIX][msg.x / PIX] += 10;
			++hitnum;
		}
	}
	else if(hitnum%2==1){
		srand((unsigned)time(NULL));
		int col, row;
		col = rand() % MAX_COL;
		row = rand() % MAX_ROW;
		if (arr[col][row] != 10 && arr[col][row] != 11 
			&& arr[col][row] != 12&&arr[col][row]<MAX_ROW){
			arr[col][row] += 20;
			++hitnum;
		}
	}
}void Winner(){
	
		//判断所有行是否连成一条线
		for (int row = 0; row < MAX_ROW; ++row){
			if (arr[row][0] >= 10 && arr[row][0] <= 12 &&
				arr[row][1] >= 10 && arr[row][1] <= 12 &&
				arr[row][2] >= 10 && arr[row][2] <= 12){
				flag = 1;
			}
		}
		//判断所有列是否连成一条线
		for (int col = 0; col < MAX_COL; ++col){
			if (arr[0][col] >= 10 && arr[0][col] <= 12 &&
				arr[1][col] >= 10 && arr[1][col] <= 12 &&
				arr[2][col] >= 10 && arr[2][col] <= 12){
				flag = 1;
			}
		}
		//判断对角线是否连成一行
		if (arr[0][0] >= 10 && arr[0][0] <= 12 &&
			arr[1][1] >= 10 && arr[1][1] <= 12 &&
			arr[2][2] >= 10 && arr[2][2] <= 12){
			flag = 1;
		}
		if (arr[0][2] >= 10 && arr[0][2] <= 12 &&
			arr[1][1] >= 10 && arr[1][1] <= 12 &&
			arr[2][0] >= 10 && arr[2][0] <= 12){
			flag = 1;
		}
		for (int row = 0; row < MAX_ROW; ++row){
			if (arr[row][0] >= 20 && arr[row][0] <= 22 &&
				arr[row][1] >= 20 && arr[row][1] <= 22 &&
				arr[row][2] >= 20 && arr[row][2] <= 22){
				flag = 0;
			}
		}
		for (int col = 0; col < MAX_COL; ++col){
			if (arr[0][col] >= 20 && arr[0][col] <= 22 &&
				arr[1][col] >= 20 && arr[1][col] <= 22 &&
				arr[2][col] >= 20 && arr[2][col] <= 22){
				flag = 0;
			}
		}
		if (arr[0][0] >= 20 && arr[0][0] <= 22 &&
			arr[1][1] >= 20 && arr[1][1] <= 22 &&
			arr[2][2] >= 20 && arr[2][2] <= 22){
			flag = 0;
		}
		if (arr[0][2] >= 20 && arr[0][2] <= 22 &&
			arr[1][1] >= 20 && arr[1][1] <= 22 &&
			arr[2][0] >= 20 && arr[2][0] <= 22){
			flag = 0;
		}
}
int main(){
	HWND hwnd = GetHWnd();//获得窗口句柄
	initgraph(PIX * MAX_ROW, PIX * MAX_COL);
	InitMap();
	//while (1){
		while (1){
			DrawMap();
			Game();
			if (flag == 1){
				MessageBox(hwnd, _T("恭喜你取得了胜利!"), _T(""), MB_OK);
				break;
			}
			else if (flag == 0){
				MessageBox(hwnd, _T("连电脑都下不过,真菜!"), _T(""), MB_OK);
				break;
			}
			if (hitnum == 9){
				MessageBox(hwnd, _T("你和电脑打平了!"), _T(""), MB_OK);
				break;
			}
		}
		/*int ret = MessageBox(hwnd, TEXT("再来一局？"), _T(""), MB_YESNO | MB_ICONQUESTION);
		if (ret == IDYES){
		break;
		}*/
	//}
	system("pause");
	return 0;
}