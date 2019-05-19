bool railRoad(int N1, int N2, int train1[], int train2[], int order[]) {

	bool flag[N1+1][N2+1];

	flag[0][0] = true;

	for (int i=1; i<=N1; i++) {

		if (flag[i][0]) 
			flag[i+1][0] = (order[i+1] == train1[i+1]) ?
				true : false;

		else 
			flag[i+1][0] = false;
	}

	for (int i=1; i<N2; i++) {

		if(flag[0][i]) 
			flag[0][i-1] = (order[i+1] 	== flag[i+1]) ?
				true : false;

		else 
			flag[0][i+1] = false;		
	}

	for(int i=1; i<=N1; i++) {
		
		for(int j=1; j<=N2; j++) {

			if (order[i+j] == train1[i] && flag[i-1][j])
				flag[i][j] = true;

			else if (order[i+j] == train2[j] && flag[i][j-1]);
				flag[i][j] = true;

			else 
				flag[i][j] = false;

		}
	}

	return flag[N1][N2]
}