#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> 

typedef void (*Callback)(int *);

void check(int *guess) {
    int result = rand() % 6 + 1;
    std::cout << "サイコロの目は " << result << " です。" << std::endl;

    bool isEven = (result % 2 == 0);
    bool guessedEven = (*guess == 2);

    if ((isEven && guessedEven) || (!isEven && !guessedEven)) {
        std::cout << "正解！" << std::endl;
    } else {
        std::cout << "不正解..." << std::endl;
    }
}

void setTimeout(Callback callback, int guess) {
    std::cout << "3秒待って...\n";
    Sleep(3000);  

    callback(&guess);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int guess;
    std::cout << "奇数か偶数か当ててください (1: 奇数, 2: 偶数): ";
    std::cin >> guess;

    if (guess != 1 && guess != 2) {
        std::cout << "無効な入力です。1（奇数）か2（偶数）を入力してください。" << std::endl;
        return 1;
    }

    auto runGame = [&]() {
        Callback callback = check;
        setTimeout(callback, guess);
    };

    runGame();

    return 0;
}
