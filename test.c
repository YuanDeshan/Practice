#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 0
int main()
{
	int day;
	scanf("%d", &day);

	switch (day)
	{
	case 1:
			printf("Monday\n");
			break;
		case 2:
			printf("Tuesday\n");
			break;
		case 3:
			printf("Wednesday\n");
			break;
		case 4:
			printf("Thursday\n");
			break;
		case 5:
			printf("Friday\n");
			break;
		case 6:
			printf("Saturday\n");
			break;
		case 7:
			printf("Sunday\n");
			break;
		default:
				printf(" ‰»Î”–ŒÛ£°\n");
			break;
	}

	return 0;
}
#endif

#if 0
int main()
{
	int i = 1;

	while (i <= 5)
	{
		printf("%d\n", i);
		++i;
	}

	return 0;
}
#endif


int main()
{
	int i = 1;
	do
	{
		printf("%d\n", i);
		++i;
	} while (i <= 5);

	return 0;
}