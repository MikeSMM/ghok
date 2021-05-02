#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<io.h>
using namespace std;

struct Team {

	char name[15];
	int win_games;
	int lose_games;
	int tie_games;
	int score;
	void print() {
		cout << name << " score: " << score << "w: " << win_games << "l: " << lose_games << "t: " << tie_games << endl;
	}
	void calcScore() {
		score = win_games * 3 + tie_games;
	}

};

void initTeam(Team* team, int step = 0) {
	switch (step) {
	case 0:
		strcpy_s(team->name, "No_name_team");
	case 1:
		team->score = 0;
	case 2:
		team->win_games = 0;
	case 3:
		team->tie_games = 0;
	case 4:
		team->lose_games = 0;
	}
}

void createTeam(Team* Tour, int size, char *buff) {
	char* tmp = buff;
	char* next_buff = nullptr;
	tmp = strtok_s(tmp, " ", &next_buff);
	if (tmp == 0) {
		initTeam(Tour + size, 0);
		return;
	}
	strcpy_s((Tour + size)->name, tmp);
	tmp = strtok_s(NULL, " ", &next_buff);
	if (tmp == 0) {
		initTeam(Tour + size, 1);
		return;
	}
	(Tour + size)->score = atoi(tmp);
	tmp = strtok_s(NULL, " ", &next_buff);
	if (tmp == 0) {
		initTeam(Tour + size, 2);
		return;
	}
	(Tour + size)->win_games = atoi(tmp);
	tmp = strtok_s(NULL, " ", &next_buff);
	if (tmp == 0) {
		initTeam(Tour + size, 3);
		return;
	}
	(Tour + size)->tie_games = atoi(tmp);
	tmp = strtok_s(NULL, " ", &next_buff);
	if (tmp == 0) {
		initTeam(Tour + size, 4);
		return;
	}
	(Tour + size)->lose_games = atoi(tmp);
}

Team newTeam() {

	Team tmp;
	cout << "Enter team name: ";
	gets_s(tmp.name);
	cout << "Enter count win games: ";
	cin >> tmp.win_games;
	cout << "Enter count tie games: ";
	cin >> tmp.tie_games;
	cout << "Enter count lose games: ";
	cin >> tmp.lose_games;
	tmp.calcScore();
	getchar();
	return tmp;
}

bool oldTeam(Team* MasTeam, int size) {
	char delTeam[20];
	cout << "Enter team to delete: ";
	gets_s(delTeam);
	int pos = -1;

	for (int i = 0; i < size; i++) {
		if (strcmp(delTeam, (MasTeam + i)->name) == 0) {
			pos = i;
			break;
		}
	}
	if (pos == -1)
		return false;
	for (int j = pos; j < size - 1; j++) {
		swap(*(MasTeam + j), *(MasTeam + j + 1));
	}
	return true;
}

struct City {

	char Name[20];
	char Country[20];
	int popular;
	bool isTheCapital;
	void print() {

		cout << Name << " from " << Country << ". Popular - " << popular << " is";
		if (isTheCapital) {
			cout << "CAPITAL" << endl;
		}
		else
			cout << " province city" << endl;
	}
	void createCity(char* str);
};

void City::createCity(char* str) {
	char* tmp = str;
	char* next_buff = nullptr;
	tmp = strtok_s(tmp, ", :", &next_buff);
	if (tmp) {
		strcpy_s(Country, tmp);
		tmp = strtok_s(NULL, ", :", &next_buff);

		if (tmp) {
			strcpy_s(Name, tmp);
			tmp = strtok_s(NULL, ", :", &next_buff);
			if (tmp) {
				popular = atoi(tmp);
				tmp = strtok_s(NULL, ", :", &next_buff);
				if (tmp) {
					if (_stricmp(tmp, "yes") != 0) {
						isTheCapital = false;
					}
					else {
						isTheCapital = true;
					}
				}
				else {
					isTheCapital = false;
				}
			}
			else {
				popular = 0; isTheCapital = false;
			}
		}
		else {
			popular = 0; isTheCapital = false; strcpy_s(Name, "Magadan");
		}
	}
	else {
		popular = 0; isTheCapital = false; strcpy_s(Country, "USSR"); strcpy_s(Name, "Magadan");
	}
}

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	/*
	FILE* file_football = NULL;
	fopen_s(&file_football, "footbool.txt", "r");
	if (file_football == nullptr) {
		cout << "can't open file..." << endl;
		return 0;
	}
	cout << ftell(file_football) << endl;
	Team* OurChampionship = nullptr;
	int count = 0;

	while (!feof(file_football)) {
		char buff[100] = {};
		fgets(buff, 100, file_football);
		OurChampionship = (Team*)realloc(OurChampionship, sizeof(Team)*(++count));
		createTeam(OurChampionship, count - 1, buff);
	}
	cout << ftell(file_football) << " count team " << count << endl;
	fclose(file_football);

	for (int i = 0; i < count; i++) {
		(OurChampionship + i)->calcScore();
		(OurChampionship + i)->print();
	}

	{//добавление ф.команды
		OurChampionship = (Team*)realloc(OurChampionship, sizeof(Team)*++count);
		*(OurChampionship + count - 1) = newTeam();
	}

	{//удаление ф.команды

		if (oldTeam(OurChampionship, count)) {
			OurChampionship = (Team*)realloc(OurChampionship, sizeof(Team)*--count);
		}
	}

	fopen_s(&file_football, "footbool.txt", "w");
	//fseek(file_football, 0, SEEK_SET);

	for (int i = 0; i < count; i++) {
		fprintf(file_football, "%s %i %i %i %i", (OurChampionship + i)->name, (OurChampionship + i)->score,
			(OurChampionship + i)->win_games, (OurChampionship + i)->tie_games, (OurChampionship + i)->lose_games);
		if (i < count - 1)
			fprintf(file_football, "\n");
	}
	fclose(file_football);

	//------------------------------------------
	*/

	FILE* file_city = nullptr;
	fopen_s(&file_city, "Popular.txt", "r");
	if (file_city == nullptr) {
		cout << "can't open file...\n" << endl;
		return 0;
	}

	City* ManyCity = nullptr;
	unsigned int size = 0;

	while (!feof(file_city)) {
		char buff[100] = {};
		fgets(buff, 100, file_city);
		if (!strcmp(buff, ""))
			continue;
		ManyCity = (City*)realloc(ManyCity, sizeof(City) * ++size);
		ManyCity[size - 1].createCity(buff);
	}
	for (int i = 0; i < size; i++) {
		ManyCity[i].print();
	}
	system("pause");
	return 0;
}