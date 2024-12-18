#include <iostream>
#include <thread>
#include <future>

void threadTask(int threadNumber, std::promise<void> done, std::future<void> start) {
    start.wait(); 
    std::cout << "thread " << threadNumber << std::endl;
    done.set_value();
}

int main() {
    // promiseとfutureを準備
    std::promise<void> p1, p2, p3;
    std::future<void> f1 = p1.get_future();
    std::future<void> f2 = p2.get_future();
    std::future<void> f3 = p3.get_future();

    // 各スレッドを作成
    std::thread t1(threadTask, 1, std::move(p1), std::promise<void>().get_future()); 
    std::thread t2(threadTask, 2, std::move(p2), std::move(f1)); 
    std::thread t3(threadTask, 3, std::move(p3), std::move(f2)); 
    // スレッドを結合
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
