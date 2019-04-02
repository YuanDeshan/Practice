#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
/*#pragma comment(lib,"winmm.lib")*///多媒体头文件
#define MAX_ROW 10
#define MAX_COL 10
#define MINE_COUNT 10
#define PIX 60//像素大小
int a[MAX_ROW][MAX_COL];
int hitnum;
IMAGE img[12];
void InitMap(){
	//初始化地图
	hitnum = 0;
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
			a[MAX_ROW][MAX_COL] = 0;
		}
	}
	srand((unsigned)time(NULL));
	//随机生成十组坐标,并给对应的元素赋值-1(-1代表雷);
	int col, row;
	int n = MINE_COUNT;
	while (n>0){
		col = rand() % MAX_COL;
		row = rand() % MAX_ROW;
		if (a[row][col] == 0){//判断该位置是否被占用
			a[row][col] = -1;
			--n;
		}
	}
	//生成地图
	//遍历数组,每找到一个雷,则给附近8个元素加一
	for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
			if (a[i][j] == -1){
				//确定雷周围的8个元素位置
				for (int row = i - 1; row <= i + 1; ++row){
					for (int col = j - 1; col <= j + 1; ++col){
						//判断row,col是否越界与a[y][x]是否为雷,然后给对应的元素加1
						if (col >= 0 && col < MAX_COL && row >= 0 && row < MAX_ROW && a[row][col] != -1){
							++a[row][col];
						}
					}
				}
			}
		}
	}
	//TODO 测试地图
	/*for (int i = 0; i < MAX_ROW; ++i){
		for (int j = 0; j < MAX_COL; ++j){
		printf("%d\t", a[i][j]);
		}
		putchar('\n');
		}*/
	//加载图片
	/*for (int i = 0; i < 12; i++){*/
		loadimage(&img[0], _T("Picture/0.jpg"), PIX, PIX);
		loadimage(&img[1], _T("Picture/1.jpg"), PIX, PIX);//图片大小64*64
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
					putimage(j *  PIX, i *  PIX, &img[9]);//贴图的坐标+地址
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
	MOUSEMSG msg = {0};//定义一个鼠标消息
	msg= GetMouseMsg();//获取鼠标消息
	switch (msg.uMsg){
		//点击鼠标左键翻开,贴上相应的图片
	case WM_LBUTTONDOWN://   Left+button+down
		if (a[msg.y / PIX ][msg.x / PIX ] < 9){
			a[msg.y / PIX ][msg.x / PIX ] += 10;
			++hitnum;
		}
		return a[msg.y / PIX][msg.x / PIX];//返回当前元素的值
		break;
		//将判断为雷的位置加上标记
	case WM_RBUTTONDOWN:// Right+button+down
		if (a[msg.y / PIX][msg.x / PIX] < 9){
			a[msg.y / PIX][msg.x / PIX] += 25;
		}
		//取消标记
		else if (a[msg.y / PIX][msg.x / PIX]>20){
			a[msg.y / PIX][msg.x / PIX] -= 25;
		}
		break;
	}


}
int main(){
	int flag;
	initgraph(PIX * MAX_ROW, PIX*MAX_COL);//打印一个窗口
	HWND hwnd = GetHWnd();//获得窗口句柄
	/*PlaySound()*/
	/*while (1)
	{*/
		InitMap();
		while (1){
			DrawMap();
			flag = Game();
			if (flag == 9){
				DrawMap();
				MessageBox(hwnd, _T("你输了,真菜!"), _T(""), MB_OK);
				break;
			}
			//如果总的数量-点开的数量=雷的数量 就是玩家赢了
			else if (MAX_ROW*MAX_COL - hitnum == MINE_COUNT){
				DrawMap();
				MessageBox(hwnd, _T("恭喜你赢了!"), _T(""), MB_OK);
				break;
			}
		}
		/*if (MessageBox(hwnd, _T("再来一局?"), _T(""), MB_RETRYCANCEL) == IDCANCEL){
			break;*/
		/*}*/
	//}
	system("pause");
	return 0;
}