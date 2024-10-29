#include <iostream>

// クラステンプレートの定義
template <typename T>
class MinClass {
public:
    // 2つの引数の小さい方を返すメンバ関数
    T Min(T a, T b) {
        return (a < b) ? a : b;
    }
};

int main() {
    // int型のインスタンス
    MinClass<int> intMin;
    std::cout << "int型: " << intMin.Min(3, 5) << std::endl;

    // float型のインスタンス
    MinClass<float> floatMin;
    std::cout << "float型: " << floatMin.Min(2.5f, 1.5f) << std::endl;

    // double型のインスタンス
    MinClass<double> doubleMin;
    std::cout << "double型: " << doubleMin.Min(7.1, 3.9) << std::endl;

    // int と float の組み合わせ（intをfloatにキャストして比較）
    MinClass<float> intFloatMin;
    std::cout << "intとfloat型: " << intFloatMin.Min(static_cast<float>(4), 3.5f) << std::endl;

    // int と double の組み合わせ（intをdoubleにキャストして比較）
    MinClass<double> intDoubleMin;
    std::cout << "intとdouble型: " << intDoubleMin.Min(static_cast<double>(6), 5.8) << std::endl;

    // float と double の組み合わせ（floatをdoubleにキャストして比較）
    MinClass<double> floatDoubleMin;
    std::cout << "floatとdouble型: " << floatDoubleMin.Min(static_cast<double>(2.4f), 3.5) << std::endl;

    return 0;
}
