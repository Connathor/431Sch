// Sch.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	cout << "\nHello, World!\n\n\n";

	int x = 1;

	int id[8];
	int arr[8];
	int burst[8];
	int pri[8];

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	ifstream myReadFile;
	myReadFile.open("jobs.txt");
	char output[100];
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {

			myReadFile >> output;
			cout <<  output;
			cout << "	";
			
			int y = atol(output);

			if (x % 4 == 1) {
				id[a] = y;
				a++;
			}

			if (x % 4 == 2) {
				arr[b] = y;
				b++;
			}

			if (x % 4 == 3) {
				burst[c] = y;
				c++;
			}

			if (x % 4 == 0) {
				cout << "\n";
				pri[d] = y;
				d++;
			}

			x++;

		}

		cout << "\n";
	}

	myReadFile.close();

	int com[8];
	int run[8];
	int w = 0;
	int att = 0;
	int art = 0;

	cout << "FCFS\n";
	cout << "Process ID      Completion time     First time in RunQ\n";
	com[w] = burst[w];
	run[w] = arr[w];
	for (w = 1; w < 7; w++) {
		com[w] = com[w - 1] + burst[w];
		run[w] = com[w - 1];
	}

	for (int n = 0; n < 7; n++) {
		cout << id[n];
		cout << "             ";
		cout << com[n];
		cout << "                  ";
		cout << run[n];
		cout << "\n";

		art = art + run[n] - arr[n];
		att = att + com[n] - arr[n];
	}

	float ART = art / 7.0;
	float ATT = att / 7.0;

	cout << "\n";
	cout << "ART";
	cout << "\n";
	cout << ART;
	cout << "\n\n";
	cout << "ATT";
	cout << "\n";
	cout << ATT;
	cout << "\n\n\n";

	cout << "SJF";
	cout << "\n";
	cout << "Process ID      Completion time     First time in RunQ\n";


	art = 0;
	att = 0;
	ART = 0;
	ATT = 0;
	int time = 0;
	bool active[8];
	bool done[11];
	for (int e = 0; e < 7; e++) {
		done[e] = false;
	}
	int me;
	int pickme;



	for (w = 0; w < 7; w++) {
		for (int e = 0; e < 7; e++) {
			active[e] = false;
		}

		for (int num = 0; num < 7; num++) {
			if (arr[num] <= time) {
				active[num] = true;
			}
		}
		pickme = 10;
		for (int e = 0; e < 7; e++) {
			if ((arr[e] <= time) && (active[e] == true) && done[e] == false) {
				me = e;
				if (pickme == 10) {
					pickme = me;
				} 
					
				if (burst[me] < burst[pickme]) {
					pickme = me;
				}
					
			}
				
		}

		
		done[pickme] = true;
		run[pickme] = time;
		time = time + burst[pickme];
		com[pickme] = time;

	}
	art = 0;
	att = 0;

	for (int n = 0; n < 7; n++) {
		cout << id[n];
		cout << "             ";
		cout << com[n];
		cout << "                  ";
		cout << run[n];
		cout << "\n";

		art = art + run[n] - arr[n];
		att = att + com[n] - arr[n];
	}
	ART = art / 7.0;
	ATT = att / 7.0;

	cout << "\n";
	cout << "ART";
	cout << "\n";
	cout << ART;
	cout << "\n\n";
	cout << "ATT";
	cout << "\n";
	cout << ATT;
	cout << "\n\n\n";

	cout << "RR";
	cout << "\n";
	cout << "Process ID      Completion time     First time in RunQ\n";

	for (int e = 0; e < 7; e++) {
		active[e] = false;
	}
	for (int e = 0; e < 7; e++) {
		done[e] = false;
	}
	time = 0;
	art = 0;
	att = 0;
	ART = 0;
	ATT = 0;
	me = 0;
	pickme = 0;
	int quan = 10;

	int timeleft[8];
	for (int e = 0; e < 7; e++) {
		timeleft[e] = burst[e];
	}

	bool running = true;
	while (running) {
		for (int start = 0; start < 7; start++) {
			if (arr[start] <= time) {
				if (active[start] == false) {
					active[start] = true;
					run[start] = time;
				}
				if ((timeleft[start] > 0) && (arr[start] <= time)) {
					if (timeleft[start] < quan) {
						time = time + timeleft[start];
						timeleft[start] = 0;
					}
					else {
						time = time + quan;
						timeleft[start] = timeleft[start] - quan;
					}
					if (timeleft[start] == 0) {
						done[start] = true;
						com[start] = time;

					}
				}
			}
		}
		if ((done[0] && done[1] && done[2] && done[3] && done[4] && done[5] && done[6] && done[7]) == true) {
			running = false;
		}
	}

	art = 0;
	att = 0;

	for (int n = 0; n < 7; n++) {
		cout << id[n];
		cout << "             ";
		cout << com[n];
		cout << "                  ";
		cout << run[n];
		cout << "\n";

		art = art + run[n] - arr[n];
		att = att + com[n] - arr[n];
	}
	ART = art / 7.0;
	ATT = att / 7.0;

	cout << "\n";
	cout << "ART";
	cout << "\n";
	cout << ART;
	cout << "\n\n";
	cout << "ATT";
	cout << "\n";
	cout << ATT;
	cout << "\n\n\n";







	cout << "\n";

	system("pause");
	return 0;
}


