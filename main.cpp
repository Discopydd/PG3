#include <iostream>
#include <cmath>
#define PI 3.14159

// 抽象基类
class IShape {
public:
   
    virtual double size() const = 0;  // 面積を計算
    virtual void draw() const = 0;    // 形状を表示

    // 仮想デストラクタ
    virtual ~IShape() = default;
};

// 派生クラス：Circle（円）
class Circle : public IShape {
private:
    double radius;  // 半径

public:
    // コンストラクタ
    Circle(double r) : radius(r) {}

    // 面積を計算
    double size() const override {
        return PI * radius * radius;
    }

    // 円を描画（コンソールに表示）
    void draw() const override {
        std::cout << "円の描画: 半径 = " << radius << ", 面積 = " << size() << std::endl;
    }
};

// 派生クラス：Rectangle（矩形）
class Rectangle : public IShape {
private:
    double width;   // 幅
    double height;  // 高さ

public:
    // コンストラクタ
    Rectangle(double w, double h) : width(w), height(h) {}

    // 面積を計算
    double size() const override {
        return width * height;
    }

    // 矩形を描画（コンソールに表示）
    void draw() const override {
        std::cout << "矩形の描画: 幅 = " << width << ", 高さ = " << height << ", 面積 = " << size() << std::endl;
    }
};

int main() {
    // Circle と Rectangle のインスタンスを作成
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // それぞれの図形を描画
    circle.draw();
    rectangle.draw();

    return 0;
}
