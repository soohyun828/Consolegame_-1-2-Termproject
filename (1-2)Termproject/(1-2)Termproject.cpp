#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
const int ROW = 25, COLUMN = 40;
using Matrix = int[ROW][COLUMN];
int tempMap[ROW][COLUMN];
void gameSetting_titleUI() {
	cout << "\n\n";
	cout << "--------------------------------------------------------------------------------\n";
	cout << "     ■■■■■■  ■■■■  ■■■■■  ■■■■■  ■■  ■■  ■■■■■     ";
	cout << "     ■■■■■■  ■■■■  ■■■■■  ■■■■■  ■■  ■■  ■■■■■     ";
	cout << "         ■■        ■■    ■■        ■■        ■■  ■■  ■■           ";
	cout << "         ■■        ■■    ■■■■■  ■■■■■  ■■  ■■  ■■■■■     ";
	cout << "         ■■        ■■    ■■■■■  ■■■■■  ■■  ■■  ■■■■■     ";
	cout << "         ■■        ■■          ■■        ■■  ■■  ■■  ■■           ";
	cout << "         ■■      ■■■■  ■■■■■  ■■■■■  ■■■■■  ■■■■■     ";
	cout << "         ■■      ■■■■  ■■■■■  ■■■■■  ■■■■■  ■■■■■     ";
	cout << "\n\n";
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "                            press 'space' to start";
	cout << "\n\n\n--------------------------------------------------------------------------------\n";
	cout << "\n\n\n\n\n\n";
}

void Next_stageUI() {
	cout << "\n\n";
	cout << "--------------------------------------------------------------------------------\n";
	cout << "           ■■     ■■    ■■■■■    ■■    ■■    ■■■■■■          ";
	cout << "           ■■■   ■■    ■■            ■■ ■■         ■■              ";
	cout << "           ■■ ■  ■■    ■■■■■        ■■            ■■              ";
	cout << "           ■■   ■■■    ■■            ■■ ■■         ■■              ";
	cout << "           ■■     ■■    ■■■■■    ■■     ■■       ■■              ";
	cout << "\n\n";
	cout << "       ■■          ■■■■■    ■■      ■    ■■■■■   ■■            ";
	cout << "       ■■          ■■           ■■    ■     ■■         ■■            ";
	cout << "       ■■          ■■■■■      ■■  ■      ■■■■■   ■■            ";
	cout << "       ■■          ■■             ■■■       ■■         ■■            ";
	cout << "       ■■■■■    ■■■■■        ■■        ■■■■■   ■■■■■      ";
	cout << "\n--------------------------------------------------------------------------------\n";
	Sleep(1100);
}

void game_overUI(string name, int score) {
	std::cout << "\n";
	std::cout << "--------------------------------------------------------------------------------\n";
	std::cout << "            ■■■■■        ■■       ■■    ■■■    ■■■■■           ";
	std::cout << "          ■■               ■■■      ■ ■  ■ ■■    ■■                 ";
	std::cout << "          ■■   ■■■     ■  ■■     ■  ■■  ■■    ■■■■■           ";
	std::cout << "          ■■     ■■    ■■■■■    ■   ■   ■■    ■■                 ";
	std::cout << "            ■■■■■    ■      ■■   ■        ■■    ■■■■■           ";
	std::cout << "\n\n";
	std::cout << "           ■■■■■     ■■      ■    ■■■■■■    ■■■■■            ";
	std::cout << "          ■■    ■■     ■■    ■     ■■            ■■     ■           ";
	std::cout << "          ■■    ■■      ■■  ■      ■■■■■■    ■■■■■            ";
	std::cout << "          ■■    ■■       ■■■       ■■            ■■   ■■           ";
	std::cout << "           ■■■■■         ■■        ■■■■■■    ■■    ■■          ";
	std::cout << "\n--------------------------------------------------------------------------------";
	std::cout << "\n\n                           " << name << "'s SCORE : " << score << "\n\n";
}

class MAP {
public:
	int stage = 1;
	int map1[ROW][COLUMN] = {
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,2},
					{2,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,2},
					{2,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,5,5,5,5,5,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,2},
					{2,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,1,1,1,1,1,5,5,5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,5,5,5,5,5,1,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,0,1,1,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,1,1,1,1,1,2},
					{2,0,0,3,0,0,0,0,0,0,1,5,5,5,1,0,0,0,0,0,1,5,5,5,5,5,1,0,0,0,0,0,0,0,1,1,1,1,1,2},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

	//공백(0), 벽(1), 유저캐릭터(3), 장애물(5), 아이템(7), 도착지(8)
	int map2[ROW][COLUMN] = {
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,2},
					{2,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,2,0,0,0,0,1,1,1,2},
					{2,1,1,0,0,0,0,2,2,0,0,0,2,2,0,0,0,0,0,7,0,0,0,7,0,0,0,2,2,0,2,2,0,0,0,1,1,0,0,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,2,2,0,0,0,0,0,0,0,1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,1,1,2,2,0,0,0,2,2,5,5,5,5,5,5,5,5,5,5,5,5,5,2,2,0,2,2,1,1,1,0,0,0,0,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,0,0,0,0,0,0,7,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,2},
					{2,1,1,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,1,5,1,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,1,1,1,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,2,2,1,0,0,0,0,0,0,2},
					{2,0,0,7,0,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,1,1,1,0,0,0,7,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,0,0,0,0,0,0,0,2},
					{2,1,1,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,0,0,0,0,1,1,1,2},
					{2,0,0,0,0,0,0,2,2,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,0,0,0,0,0,0,0,2},
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,2,1,1,0,0,0,0,0,2},
					{2,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,0,0,0,2},
					{2,1,5,5,5,5,1,0,0,0,1,5,5,5,5,5,1,0,0,0,1,5,5,1,0,0,1,0,0,0,0,2,0,0,0,3,0,0,0,2},
					{1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };
};

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = 2*x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void scoreData(string name, int score) {
	/*txt 파일에 새로운 스코어 로드하기
	1. 최대 5위까지 데이터 가지고 있음.
	2. newScore가 5위 안에 들면 txt파일 업데이트
	3. 동점이 있을 경우 최근 데이터가 뒷 순위
	*/
	std::ifstream ifs("ranking.txt");
	if (ifs.fail()) {
		ifs.close();
		std::ofstream ofs("ranking.txt");
		ofs << name << ":" << score << '\n';
		gotoxy(15, 20);
		std::cout<< "1. " <<  name << ':' << score << '\n';
		ofs.close();
	}
	else {
		//ifs.close();
		std::vector<std::vector<string>> ranking;
		std::vector<int> Vscore;
		string str;
		//std::ifstream ifs("ranking.txt");
		while (getline(ifs, str)) {
			std::vector<string> tempRanking;
			int n = str.rfind(':');
			tempRanking.push_back(str.substr(0, n));
			tempRanking.push_back(str.substr(n+1));
			Vscore.push_back(stoi(str.substr(n+1)));
			ranking.push_back(tempRanking);
		}
		ifs.close();
		std::vector<string> userScore = { name, std::to_string(score) };
		for (int i = 1; i <= Vscore.size(); i++) {
			if (Vscore[0] < score) {
				ranking.insert(ranking.begin(), userScore);
				break;
			}
			else if (Vscore[Vscore.size() - i] >= score) {
				if (i == 1) {
					ranking.push_back(userScore);
					break;
				}
				else{
					ranking.insert(ranking.begin() + (Vscore.size() - i+1), userScore);
					break;
				}
			}
		}
		std::ofstream ofs("ranking.txt");
		if (ranking.size() < 6) {
			for (int i = 0; i < ranking.size(); i++) {
				ofs << ranking[i][0] << ':' << ranking[i][1] << '\n';
				gotoxy(15, 20+i);
				std::cout << i + 1 << ". " << ranking[i][0] << ':' << ranking[i][1] << '\n';
			}
		}
		else {
			for (int i = 0; i < 5; i++) {
				ofs << ranking[i][0] << ':' << ranking[i][1] << '\n';
				gotoxy(15, 20 + i);
				std::cout << i + 1 << ". " << ranking[i][0] << ':' << ranking[i][1] << '\n';
			}
		}
		ofs.close();
	}	
}

class userC : public MAP {
public:
	int x = 0, y = 0, jump = 0, item = 0;
	bool isplaying, isjumping = false;
	void move(int* x, int* y, int mx, int my, int* stage) {
		int mapvalue = tempMap[*y + my][*x + mx];
		switch (mapvalue) {
		case 0:
			gotoxy(*x, *y);
			std::cout << "  ";
			gotoxy(*x + mx, *y + my);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			std::cout << "■";
			*x += mx; *y += my;
			break;
		case 5:
			gotoxy(*x, *y);
			std::cout << "  ";
			gotoxy(*x + mx, *y + my);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			std::cout << "■"; // water(obstacle)
			Sleep(100);
			isplaying = false;
			break;
		case 7:
			gotoxy(*x, *y);
			std::cout << "  ";
			gotoxy(*x + mx, *y + my);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			std::cout << "■";
			*x += mx; *y += my, item++;
			tempMap[*y][*x] = 0;
			break;
		case 8:
			gotoxy(*x, *y);
			std::cout << "  ";
			gotoxy(*x + mx, *y + my);
			(*stage)++; item += 3;
		}
	}
	void controlC() {
		int mx = 0, my = 0;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 && x > 1) {
			mx = -1;
			Sleep(30);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && x < 82) {
			mx = 1;
			Sleep(30);
		}
		move(&x, &y, mx, my, &stage);

		if (GetAsyncKeyState(VK_UP) & 0x8000 && y > 1) {
			if (jump == 0 && !isjumping) {
				my = -1;
				move(&x, &y, mx, my, &stage);
				jump++;
			}
		}

		if (jump < 3 && jump > 0) {
			my = -1;
			move(&x, &y, mx, my, &stage);
			jump++;
		}
		else if ((tempMap[y + my][x + mx] != 1) || (tempMap[y + my][x + mx] != 2)) {
			my = 1;
			move(&x, &y, mx, my, &stage);
		}
		if (!(tempMap[y + my][x + mx] == 0 || tempMap[y + my][x + mx] == 5 || tempMap[y + my][x + mx] == 7)) {
			jump = 0;
			isjumping = false;
		}
	}
};

void drawMap(Matrix map, int* x, int* y) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			switch (map[i][j]) {
			case 0:
				std::cout << "  ";
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				std::cout << "■"; // ceiling, ground wall
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				std::cout << "■"; // left, right wall
				break;
			case 3:
				map[i][j] = 0;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "●"; // user character
				*x = j; *y = i;
				break;
			case 5:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				std::cout << "■"; // water(obstacle)
				break;
			case 7:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				std::cout << "@ "; // item
				break;
			case 8:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				std::cout << "■"; // exit (go to next level or end)
				break;
			}
		}
		std::cout << '\n';
	}
}

void system_setting() {
	system("mode con: cols=80 lines=55");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

int main() {
	system_setting();
	unsigned int button = GetTickCount64();
	userC user;
	gameSetting_titleUI();
	if (_getch() == 32) {
		string name;
		gotoxy(10, 22);
		std::cout << "                                        ";
		do {
			gotoxy(10, 22);
			std::cout << "Enter your name : "; 
			std::cin >> name;		// 사용자 이름 입력
		} while (name.empty());
		system("cls");
		user.isplaying = true;
		int tempStage = 0;
		while (user.isplaying) {
			if (button + 30 < GetTickCount64()) {
				button = GetTickCount64();
				if (user.stage != tempStage) {
					tempStage = user.stage;
					system("cls");
					switch (user.stage) {
					case 1:
						memcpy(tempMap, user.map1, sizeof(tempMap));
						break;
					case 2:
						Next_stageUI();
						system("cls");
						memcpy(tempMap, user.map2, sizeof(tempMap));
						break;
					default:
						user.isplaying = false;
						system("cls");
						break;
					}
					drawMap(tempMap, &(user.x), &(user.y));
				}
				user.controlC();
				Sleep(1000 / 13);
				gotoxy(3, 27); std::cout << "점 수 : " << user.item * 10;
				gotoxy(13, 27); std::cout << "S T A G E " << user.stage;
			}
		}
		system("cls");
		game_overUI(name, user.item * 10);
		Sleep(1200);
		scoreData(name, user.item * 10);
	}
}