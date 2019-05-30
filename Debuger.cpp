int LCS(string a, string b) {

	aSize = a.length();
	bSize = b.length();

	int mat[aSize+1][bSize+1];

	for (int i=0; i<=aSize; i++) 
		mat[i][0] = 0;

	for (int i=0; i<=bSize; i++)
		mat[0][i] = 0;

	for (int i=1; i<=aSize; i++) {
		
		for (int j=1; j<=bSize; j++) {

			if (a[i-1] == b[j-1]) 
				mat[i][j] = mat[i-1][j-1]+1;

			else
				mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
		}
	}

	return mat[aSize][bSize];
}