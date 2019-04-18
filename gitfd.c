int i, n, k, m = 0;
for (n = 100; n < 201; n++){
	k = sqrt(n);
	for (i = 2; i < k + 1; i++){
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
