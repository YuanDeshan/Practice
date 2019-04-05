int score;
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
