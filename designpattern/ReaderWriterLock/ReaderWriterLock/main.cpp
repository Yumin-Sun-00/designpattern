#include <iostream>
#include <thread>
#include <chrono>
#include <shared_mutex>

class Resource {
public:
    void Read() {
        std::shared_lock<std::shared_timed_mutex> lock(mutex_);
        std::cout << "Reading resource: " << data_ << std::endl;
    }

    void Write(int data) {
        std::unique_lock<std::shared_timed_mutex> lock(mutex_);
        data_ = data;
        std::cout << "Writing resource: " << data_ << std::endl;
    }

private:
    int data_ = 0;
    std::shared_timed_mutex mutex_;
};

int main() {
    Resource resource;

    std::thread writer([&resource] {
        for (int i = 0; i < 5; ++i) {
            resource.Write(i);
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    });

    std::thread reader1([&resource] {
        for (int i = 0; i < 5; ++i) {
            resource.Read();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
    std::thread reader2([&resource] {
        for (int i = 0; i < 5; ++i) {
            resource.Read();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });


    reader1.join();
    reader2.join();
    writer.join();

    return 0;
}
