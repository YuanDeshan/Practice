#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//void action1(int x, int y){
//	printf("x+y=%d\n,x+y");
//}
//void action2(int x, int y){
//	printf("x*y=%d\n", x + y);
//}
#define SUM 100000
//void print(int n){
//	if (n > 9){
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int fun(int x, int y){
//	int c;
//	while (x%y != 0){
//		c = x%y;
//		x = y;
//		y = c;
//	}
//	return(y);
//}
//int fun1(int x, int y){
//	int n;
//	int a = x*y;
//	n = a / fun(x, y);
//	return(n);
//}

void menu(){
	printf("      *猜数字游戏*    \n");
	printf("######################\n");
	printf("######> 1.play <######\n");
	printf("######> 2.exit <######\n");
	printf("######################\n");
}
void game(){
	int random = rand() % 100 + 1;//产生一个0~100的随机数
	int input = 0;//定义一个整形变量input,并进行初始化
	while (1){
		printf("请输入猜的数字:\n");//提示输入
		scanf("%d", &input);//输入input的值
		if (input > random){//
			printf("猜大了\n");//
		}
		else if (input < random){//
			printf("猜小了\n");//
		}
		else{
			printf("猜对了\n");//
			break;//
		}
	}
}
int main(){//
	int input = 0;//
	srand((unsigned)time(NULL));//
	do{
		menu();
		printf("请选择\n");//
		scanf("%d", &input);//
		switch (input){//
		case 1://
			game();//
			break;//
		case 2://
			break;//
		default:
			printf("选择错误,请重新输入!\n");//
			break;//
		}
	}
		while (input);//




	/*int i, j,n;
	for (i = 1; i < 5; i++){
	
		for (j = 1; j <=5- i; j++){
			printf(" ");
		}
		for (j = 1; j < (2*i); j++){
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i < 4; i++){
		for (j = 1; j <= i; j++){
			printf(" ");
		}
		for (j = 1; j < 7- 2*i; j++){
			printf("*");
		}
		printf("\n");

	}
*/
	/*int sum=1, i;
	for (i = 0; i < 9; i++){
		sum =(sum+1)* 2 ;
	}
	printf("%d\n", sum);*/

	
	//double h = 100, H = 0;
	//int i;
	//for (i = 0; i < 10; i++){
	//	if (h == 100){
	//	H = h;
	//	}
	//	else{
	//		H += 2 * h;
	//	}
	//	h = h / 2;
	//}
	//printf("%f\n%f\n",h,H);
	
	

	//int  n;
	//	double  sum = 0, a = 1.0, b = 2.0,c;
	//for (n = 0; n <3; n++){
	//	sum += (b / a);
	//	c = a + b;
	//	a = b;
	//	b = c;
	//	
	//}
	//printf("%f",sum);
	//
	/*int i, n;
	for (n = 1; n < 1000; n++){
		for (i = 1; i < n; i++){
			if (n%i == 0&&){
				pirintf("%d its factors are %%% ");
			}
		}
	}
	*/
	
	//int a, b, c, i,sum;
	//for (i = 100; i < 1000; i++){
	//	a = i / 100;
	//	b = i / 10 % 10;
	//	c = i % 10;
	//	sum = a*a*a + b*b*b + c*c*c;
	//	if (sum == i){
	//		printf("%d\n", sum);
	//	}
	//}

	
	/*int num = 1234;
	print(num);
	putchar('\n');
	return 0;
	*/
	
	
	
	/*int sum1 = 0, sum2 = 0, i;
	double  sum3 = 0,sum;
	for (i = 1; i < 101; i++){
		sum1 += i;
	}
	for (i = 1; i <51; i++){
		sum2 += i*i;
	}
	for (i = 1; i < 11; i++){
		sum3 += 1.0 / i;
	}
	sum = sum1 + sum2 + sum3;
	printf("%f\n",sum);*/


	/*int i,sum=0,j,a=0;
	for (i = 1; i <21; i++){
		a = i;
		for (j = 1; j < i; j++){
			a *= j;
		}
		sum += a;
	}
	printf("%d\n",sum);*/
	
	
	/*int sum=0,n,i,a;
	printf("enter a nuember:\n");
	scanf("%d",& n);
	a = n;
	for (i = 0; i < 5; i++){
		sum += n;
		n= 10 *n +a;

	}
	printf("%d\n", sum);
	*/
	
	/*char a[] = { 0 };
	int i,english=0,num=0,blank=0,other=0;
	printf("请输入一串字符:\n");
	for (i = 0; i < 5; i++){
		scanf("%C", &a[i]);
		if ((35 <= a[i] && a[i] <= 90) || (97 <= a[i] && a[i] <= 122)){
			english++;
			continue;
		}
		if (a[i] = 32){
			blank++;
			continue;
		}
		if (48 <= a[i] && a[i] <= 57){
			num++;
			continue;
		}
		else{
			other++;
		}
		printf("%c ", a[i]);
	}
	printf("english=%d num=%d blank =%d other=%d", english, num, blank, other);
*/

	//int m, n,t=1;
	//printf("please erter m&n:\n");
	//scanf("%d%d", &m, &n);
	//while(m%n!=0){
	//	t = m%n;
	//	m = n;
	//	n = t;
	//}
	//printf("%d", n);

	
	/*int i;
	char c,a;
	for (i = 0; i <6; i ++ ){
		
		c = getchar();
		if (i == 5){
			break;
		}
		a = c + 4;
		printf("%c", a);

	}
	printf("%c", c);
	putchar('\n');*/
	
	/*int i,n,k,m=0;
	for (n = 100; n < 201;n++){
		k = sqrt(n);
		for (i = 2; i < k+1; i++){
			if (n%i == 0){
				break;
			}
		}
			if (i >k){
				printf("%d ", n);
				m++;
			}
			if (m % 10 == 0){
				putchar('\n');
			}
	}
	putchar('\n');
	*/
	
	/*int n, i;
	printf("please enter a integer number,,n=?\n");
	scanf("%d", &n);
	for (i = 2; i < n; i++){
		if (n%i == 0){
			break;
		}
	}
	if (i < n){
		printf("%d is not a prime number.\n",n);
	}
	else {
		printf("%d is a prime number.\n",n);
	}*/
	
	/*int f1=1, f2=1;
	int i;
	for (i = 1; i <= 20; i++){
		printf("%12d%12d", f1, f2);
		if (i%2 == 0){
			putchar('\n');
		}
		f1 = f1 + f2;
		f2 = f2 + f1;
	}*/
	
	
	/*int f1 = 1, f2 = 1, f3;
	int i;
	printf("%12d\n%12d\n", f1, f2);
	for (i = 1; i <= 28; i++){
		f3 = f1 + f2;
		printf("%12d\n", f3);
		f1 = f2;
		f2 = f3;
	}
	*/
	
	/*
	int sign = 1;
	double pi = 0.0, n = 1.0, term = 1.0;
	while (fabs(term) > 1e-6){
		pi = pi + term;
		n = n + 2;
		sign = -sign;
		term = sign / n;
	}
	pi = pi * 4;
	printf("pi=%10.8f\n", pi);
	*/
	
	
	/*int i, j;
	for (i = 1; i < 5; i++){
		for (j = 1; j < 6; j++){
			if (i == 3 && j == 1){
				continue;
			}
			printf("%d\t", i*j);
		}
		putchar('\n');
	}
	putchar('\n');*/

/*int num = 10;
	int* p = &num;
	*p = 20;*/
	/*printf("%d\n",sizeof(short *));*/
		/*int sum = 10;
	&sum;
	printf("%p\n", &sum);*/
	
	/*int sum =ADD(2, 3);
	printf("sum=%d\n", sum);
	sum = 10 * (2, 3);
	printf("sum=%d\n", sum);
		return 0;*/


//static	int i;
//	for (i = 0; i < 10; i++){
//		test();

	
	/*int i = 0;*/
	/*int a[10] = { 1, 2, 3,4, 5, 6, 7, 8, 9,10 };
	for (i = 0; i < 10; i++){
		printf("%d\n", a[i]);
	}
	printf("\n");
	return 0;*/

	/*double a, b, c, s, area;
	a = 3.67;
	b = 5.43;
	c = 6.21;
	s = (a + b + b) / 2;
	area = sqrt(s*(s - a)*(s - b)*(s - c));
	printf("a=%f\tb=%f\t%f\n ", a, b, c);
	printf("area=%f\n", area);*/
	
	
	//char c1, c2;
	//c1 = 'A';
	//c2 = c1 + 32;
	//printf("%c\n", c2);
	//printf("%d\n", c2);

	/*float f, c;
	f = 64.0;
	c = (5.0 / 9)*(f - 32);
	printf("%f\n%f\n",f, c);*/
	/*int i, sum=0;
	for (i = 1; i < 101; i++){
		sum = sum + i;
	}
	printf("%d\n", sum);
	*/
	/*int a = 1;
	double	b=2.0, sum=0,c=1,t;
	while (b < 101){
		a= (-1)*a;
		t = a/b;
		sum = sum + t;
		b++;
	}
		printf("%f\n", sum);
*/


	
	/*int a[5];
	int i;
	printf("请输入50名同学成绩\n");
	for (i = 0; i < 6; i++){
		scanf("%d", &a[i]);
	}
	i = 0;
		while (a[i] >= 80){
			printf("%d", a[i]);
			i++;
		}*/
	/*int a = 1, i = 2;
	while (i < 6){
	a = i*a;
		i++;
	}
	printf("%d\n", a);*/
	


	/*int n;
	for (n = 100; n < 201; n++){
		if (n % 3 == 0){
			continue;
		}
		printf("%-4d", n);
	}
	putchar('\n');*/
	
	/*float amount, aver, total;
	int i;
	for (i = 1, total = 0; i <=1000; i++){
		printf("please enter amount\n");
		scanf("%f", &amount);
		total = total + amount;
		if (total >= SUM){
			break;
		}
	}
	aver = total / i;
	printf("num=%d\n aver=%10.2f\n", i, aver);*/
	
	
	
	/*int sum = 0,  i=1;
	do{
		sum = sum + i;
		i++;

	} while (i < 101);
	printf("%d\n", sum);*/




	//int i = 1, sum = 0;
	//while (i < 101){
	//	sum = sum + i;
	//	i++;
	//}
	//printf("%d\n", sum);

	
	
	//int h = 10;
	//float x1 = 2.0, y1 = 2.0,
	//	  x2 = -2.0, y2 = 2.0,
	//	  x3 = -2.0, y3 = -2.0,
	//	  x4 = 2.0, y4 = -2.0,
	//	  d1, d2, d3, d4,x, y;
	//printf("请输入坐标(x,y):\n");
	//scanf("%f,%f", &x, &y);
	//d1 = (x - x1)*(x - x1) + (y - y1)*(y - y1);
	//d2 = (x - x2)*(x - x2) + (y - y2)*(y - y2);
	//d3 = (x - x3)*(x - x3) + (y - y3)*(y - y3);
	//d4 = (x - x4)*(x - x4) + (y - y4)*(y - y4);
	//if (d1 > 1 && d2 > 1 && d3 > 1 && d4 > 1){
	//	h = 0;
	//	printf("高度=%d\n", h);
	//}
	//else
	//	printf("高度=%d\n", h);


	/*int  a,b,c,d,t;
	printf("请输入四个数:\n");
	scanf("%d%d%d%d", &a,&b,&c,&d);
	if (a<b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (c<d)
	{
		t = c;
		c = d;
		d = t;
	}
	if (a<c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b<c)
	{
		t = b;
		b = c;
		c = t;
	}
	if (b<d)
	{
		t = b;
		b = d;
		d = t;
	}
	if (c<d)
	{
		t = c;
		c = d;
		d = t;
	}
	printf("%d %d %d %d\n", a, b, c, d);*/
	

	
	

	int I;
	double bonus;
	printf("请输入你的工资:\n");
	scanf("%d", &I);
	if (I <= 100000){
		bonus =I+ I * 0.1;
			printf("%d\n", bonus);
	}
	if (I > 100000 && I <= 200000){
		bonus = I + 100000 * 0.1
			+(I - 100000)*0.075;
	}
	if (I > 200000 && I <= 400000){
		bonus = I + 100000 * 0.1
			+ 100000 * 0.075
			+ (I - 200000)*0.05;
	}
	if (I > 400000 && I <= 600000){
		bonus = I + 100000 * 0.1
			+ 100000 * 0.075 
			+ 200000*0.05
			+(I-400000)*0.03;
	}
	if (I > 600000 && I <= 1000000){
		bonus = I + 100000 * 0.1
			+ 100000 * 0.075
			+ 200000 * 0.05
			+ 200000 * 0.03
			+ (I - 600000)*0.015;
	}
	if (I > 1000000){
		bonus = I + 100000 * 0.1
			+ 100000 * 0.075
			+ 200000 * 0.05
			+ 200000 * 0.03
			+ 400000*0.015
			+(I-1000000)*0.01;
	}
	printf("%lf\n", bonus);
	   */




	/*int count=1,n=12345,i;
	int a, b, c, d, e;
	while (n >= 10){
		n /= 10;
		count++;
	}
	printf("n是%d位数\n",count);
	n = 12345;
	a = n / 10000;
	b = n % 10000 / 1000;
	c = n % 1000 / 100;
	d = n % 100 / 10;
	e=n % 10;

	printf("%d %d %d %d %d\n", a,b,c,d,e);
	printf("%d%d%d%d%d\n", e, d, c, b, a);
*/

	

	
	
	
	
	/*int score;
	printf("enter the score:\n");
	scanf("%d", &score);
	if (score >= 90){
		printf("A\n");
	}
	if (score >= 80 && score < 90){
		printf("B\n");
	}
	if (score >= 70 && score < 80){
		printf("C\n");
	}
	if (score >= 60 && score < 70){
		printf("D\n");
	}
	if (score < 60){
		printf("E\n");
	}
		*/
	/*int x, y;
	printf("enter x:\n");
	scanf("%d", &x);
	y = 0; 
	if(x>=0){
		if (x > 0){
			y = 1;
		}
	}
	else{
		y = -1;
	}
	printf("x=%d,y=%d\n",x, y);*/
	
	
	/*int x,a; 
	printf("请输入一个整数:\n");
	scanf("%d",&x);
	if (x < 1){
		a = x;
		printf("%d\n", a);
	}
	if (x >= 1 && x < 10){
		a = 2 * x - 1;
		printf("%d\n", a);
	}
	if (x >= 10){
		a = 3 * x - 11;
		printf("%d\n", a);
	}*/
	
	
	/*int a,s;
	scanf("%d", &a);
	if (a <= 1000){
		s = sqrt(a);
		printf("%d\n", s);
	}
	else{
		printf("enter data error!\n");
	}
	
	*/
	//int a, b, c,t;
	//scanf("%d %d %d",&a,&b,&c);
	//if (a < b){
	//	t =b;
	//	b = a;
	//	a = t;1
	//}
	//if (a < c){
	//	t = c;
	//	c = a;
	//	a = t;
	//}
	//if (b < c){
	//	t = c;
	//	b = c;
	//	a = t;
	//}
	//printf("%d\n",b);
	
	
	//int c, s;
	//float p, w,d, f;
	//printf("please enter price ,weight,discount:");
	//scanf("%f %f %d", &p, &w, &s);
	//if (s >= 3000){
	//	c = 12;
	//}
	//else{
	//	c = s / 250;
	//}
	//switch (c){
	//case 0:d = 0;
	//	break;
	//case 1:d = 2;
	//	break;
	//case 2:
	//case 3:d = 5;
	//	break;
	//case 4:
	//case 5:
	//case 6:
	//case 7:d = 8;
	//	break;
	//case 8:
	//case 9:
	//case 10:
	//case 11:d = 10;
	//	break;
	//case 12:d = 15;
	//	break;
	//}
	//f = p*w*s*(1 - d / 100);
	//printf("freight=%10.2f\n", f);
	
	
	//double a, b, c, disc, x1, x2, realpart, imagpart;
	//scanf("%lf %lf %lf", &a,&b, &c);
	//printf("The equation");
	//if (fabs(a) <= 1e-6){
	//	printf("is not a quadratic\n");
	//}
	//else{
	//	disc = b*b - 4 * a*c;
	//	if (fabs(disc) <= 1e-6){
	//		printf("has two equal roots:%8.4f\n", -b / (2 * a));
	//	}else
	//	if (disc > 1e-6){
	//		x1 = (-b + sqrt(disc) / (2 * a));
	//		x2 = (-b - sqrt(disc)) / (2 * a);
	//		printf("has distinct  real roots:%8.4fand%8.4f\n", x1, x2);
	//	}
	//	else{
	//		realpart = -b / (2 * a);
	//		imagpart = sqrt(-disc) / (2 * a);
	//		printf("has complx roots:\n");
	//		printf("%8.4f+%8.4fi\n", realpart, imagpart);
	//		printf("%8.4f-%8.4fi\n", realpart, imagpart);
	//	}
	//	}

	/*int year, leap;
	printf("enter year:");
	scanf("%d", &year);
	if (year % 4 == 0){
		if (year % 100 == 0){
		leap = 1;
	}
	else{
		leap = 0;
	}
	}
	else{
		leap = 0;
	}
	if (leap = 0){
		printf("%d is ", year);
		if (leap = 1){
			printf("%d is not", year);
		}
	}*/
	/*void action1(a, b), action2(int, int);
	char ch;
	int a = 15, b = 23;
	ch = getchar();
	switch (ch){
	case 'a':
	case 'A':action1(a, b);
		break;
	case 'b':
	case 'B':action2(a, b);
		break;
	default:putchar("\n");
	}
	return  0;*/

	/*char grade;
	scanf("%c", &grade);
	printf("Your score:\n");
	switch (grade){
	case 'A':printf("85~100\n");
		break;
	case 'B':printf("70~84\n");
	case 'C':printf("60~69\n");
	case 'D':printf("<60\n");
	default:printf("enter data error!\n");
	}*/
	
	//int x, y;
	//scanf("%d", &x);
	//if (x >= 0){
	//	if (x >= 0){
	//		y = 1;
	//	}
	//	else{
	//		y = 0;
	//	}
	//}
	//else{
	//	y = -1;
	//}
	//printf("x=%d, y=%d\n", x, y);

	//	int x, y;
//	scanf("%d", &x);
//	if (x < 0){
//		y = -1;
//	}
//	else{
//		if (x == 0){
//			y = 0;
//		}
//		else y = 1;
//	}
//		printf("x=%d,y=%d\n", x, y);
	return 0;
}