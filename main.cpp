#include <iostream>
#include <fstream>

// 関数: 一般的な賃金体系の総賃金を計算する
double calculateRegularWage(int hours) {
    const double regularHourlyWage = 1072.0;  // 一般的な賃金体系の時給
    return hours * regularHourlyWage;
}

// 関数: 再帰的な賃金体系の総賃金を計算する
double calculateRecursiveWage(int hours) {
    double wage = 0.0;
    double previousHourlyWage = 100.0;  // 再帰的な賃金体系の最初の1時間の賃金は100円

    for (int i = 1; i <= hours; ++i) {
        wage += previousHourlyWage;
        previousHourlyWage = previousHourlyWage * 2 - 50;  // 次の1時間の賃金の計算式
    }

    return wage;
}

int main() {
    int hours = 0;

    // 作業時間を入力
    std::cout << "作業時間（時間単位）を入力してください：";
    std::cin >> hours;

    // 2つの賃金体系の総賃金を計算
    double regularTotalWage = calculateRegularWage(hours);
    double recursiveTotalWage = calculateRecursiveWage(hours);

    // 結果を出力
    std::cout << "一般的な賃金体系の総賃金: " << regularTotalWage << " 円" << std::endl;
    std::cout << "再帰的な賃金体系の総賃金: " << recursiveTotalWage << " 円" << std::endl;

    // どちらが有利か比較
    if (recursiveTotalWage > regularTotalWage) {
        std::cout << hours << "時間後、再帰的な賃金体系の方が有利です。" << std::endl;
    } else {
        std::cout << hours << "時間後、一般的な賃金体系の方が有利です。" << std::endl;
    }

    // 結果を answer.md ファイルに書き込む
    std::ofstream answerFile("answer.md");
    if (recursiveTotalWage > regularTotalWage) {
        answerFile << hours << "時間後、再帰的な賃金体系の方が有利です。" << std::endl;
    } else {
        answerFile << hours << "時間後、一般的な賃金体系の方が有利です。" << std::endl;
    }
    answerFile.close();

    return 0;
}
