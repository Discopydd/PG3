#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> 

typedef void (*PFunc)(int *);


void checkResult(int *guess) {
    int diceResult = rand() % 6 + 1; 
    std::cout << "サイコロの目は " << diceResult << " です。" << std::endl;

    bool isEven = (diceResult % 2 == 0);
    bool userGuessedEven = (*guess == 2);

    if ((isEven && userGuessedEven) || (!isEven && !userGuessedEven)) {
        std::cout << "正解！" << std::endl;
    } else {
        std::cout << "不正解..." << std::endl;
    }
}

void setTimeout(PFunc p, int guess) {
    std::cout << "3秒待って...\n";
    Sleep(3000);

    p(&guess);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int userGuess;
    std::cout << "奇数か偶数か当ててください (1: 奇数, 2: 偶数): ";
    std::cin >> userGuess;

    if (userGuess != 1 && userGuess != 2) {
        std::cout << "無効な入力です。1（奇数）か2（偶数）を入力してください。" << std::endl;
        return 1;
    }

    PFunc callback = checkResult;

    setTimeout(callback, userGuess);

    return 0;
}
