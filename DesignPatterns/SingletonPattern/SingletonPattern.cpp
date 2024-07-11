#include <iostream>
#include <memory>
#include <mutex>

class ThreadSafeSingleton
{
private:
    ThreadSafeSingleton()
    {
        printf("ThreadSafeSingleton Created\n");
    }
   /* ~ThreadSafeSingleton() {
        printf("ThreadSafeSingleton Destroyed\n");
    }*/
    

    static void initSingleton() {
        instance.reset(new ThreadSafeSingleton());
        //instance= std::make_shared<ThreadSafeSingleton>();
    }
public:
    static std::shared_ptr<ThreadSafeSingleton> instance;
    static std::once_flag initInstanceFlag;
    static std::shared_ptr<ThreadSafeSingleton> getInstance() {
        std::call_once(initInstanceFlag, &ThreadSafeSingleton::initSingleton);
        return instance;
    }

    ThreadSafeSingleton(const ThreadSafeSingleton&) = delete;
    ThreadSafeSingleton& operator=(const ThreadSafeSingleton&) = delete;

    void someBusinessLogic() {
        std::cout << "ThreadSafeSingleton instance address: " << this << std::endl;
    }
};

std::shared_ptr<ThreadSafeSingleton> ThreadSafeSingleton::instance = nullptr;
std::once_flag ThreadSafeSingleton::initInstanceFlag;

class Singleton
{
private:
    Singleton()
    {
        printf("Singleton Created\n");
    }
    /*~Singleton() {
        printf("Singleton Destroyed\n");
    }*/
    
public:
    static std::shared_ptr<Singleton> instance;
    static std::shared_ptr<Singleton> getInstance() {
        if (!instance) {
            instance.reset(new Singleton());
        }
        return instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    void someBusinessLogic() {
        std::cout << "Singleton instance address: " << this << std::endl;
    }
};

std::shared_ptr<Singleton> Singleton::instance = nullptr;


void SingletonThread1() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::shared_ptr<Singleton> singleton = Singleton::getInstance();
    singleton->someBusinessLogic();
}

void SingletonThread2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::shared_ptr<Singleton> singleton = Singleton::getInstance();
    singleton->someBusinessLogic();
}

void ThreadSafeSingletonThread1() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::shared_ptr<ThreadSafeSingleton> singleton = ThreadSafeSingleton::getInstance();
    singleton->someBusinessLogic();
}

void ThreadSafeSingletonThread2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::shared_ptr<ThreadSafeSingleton> singleton = ThreadSafeSingleton::getInstance();
    singleton->someBusinessLogic();
}

int main()
{
    std::thread t1(SingletonThread1);
    std::thread t2(SingletonThread2);
    t1.join();
    t2.join();

    std::thread ts1(ThreadSafeSingletonThread1);
    std::thread ts2(ThreadSafeSingletonThread2);
    ts1.join();
    ts2.join();
    std::shared_ptr<ThreadSafeSingleton> singleton11 = ThreadSafeSingleton::getInstance();
    singleton11->someBusinessLogic();

    std::shared_ptr<ThreadSafeSingleton> singleton22 = ThreadSafeSingleton::getInstance();
    singleton22->someBusinessLogic();

    std::shared_ptr<Singleton> singleton1 = Singleton::getInstance();
    singleton1->someBusinessLogic();

    std::shared_ptr<Singleton> singleton2 = Singleton::getInstance();
    singleton2->someBusinessLogic();
    return 0;
}