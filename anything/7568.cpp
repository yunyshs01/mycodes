#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
	int n;

	cin >> n;
	/*int* weight = new int[n];
	int* height = new int[n];

	int * biggermen = new int[n];*/

	int weight	[50];
	int height	[50];
				
	int biggermen[50];


	for (int i = 0; i < n; i++) {
		biggermen[i] = 0;
	}

	int randseed = 12345;
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> height[i];
		/*srand(randseed);
		randseed = rand()*rand();
		weight[i] = randseed % 190 + 10;
		srand(randseed);
		height[i] = rand() %190 +10;
		
		
		cout << weight[i] << ' ' << height[i] << endl;*/
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (weight[i] > weight[j] && height[i] > height[j])
				biggermen[j]++;				
		}
	}
	
	/*
	int score[50][2];
	for (int i = 0; i < 50; i++) {

		score[i][0] = 0;
		score[i][1] = 0;
	}

	for (int i = 0; i < n; i++) {
		score[biggermen[i]][0]++;
	}

	int rank = 1;
	for (int i = 0; i < n; i++) {
		if (score[i][0] != 0) {
			score[i][1] = rank;

			rank += score[i][0];
		}
		
	}*/

	for (int i = 0; i < n; i++) {
		cout << biggermen[i] + 1 << ' ';
	}
	cout << endl;


}