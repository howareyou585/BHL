#pragma once
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <queue>
#include <mutex>
namespace UsageYield {
    //std::atomic<bool> ready(false);
   
    //void consumer() {
    //    // 忙等待，但通过yield让出CPU
    //    while (!ready.load()) {
    //        std::this_thread::yield();  // 让出CPU，让其他线程运行
    //    }
    //    std::cout << "Resource is ready!\n";
    //}

    //void producer() {
    //    std::this_thread::sleep_for(std::chrono::seconds(1));
    //    ready.store(true);
    //}

    std::queue<int> data_queue;
    std::mutex queue_mutex;
    std::atomic<bool> done(false);

    void consumer() {
        while(done.load() == false || !data_queue.empty()) {
           
            {
                std::lock_guard<std::mutex> lock(queue_mutex);
                if(!data_queue.empty()) {
                    int data = data_queue.front();
                    data_queue.pop();
                    std::cout << "Consumed: " << data << std::endl;
                }
                else 
                {
                    std::cout << "No data to consume, yielding..." << std::endl;
                    std::this_thread::yield(); // 如果没有数据，释放CPU给其他线程
                }
            }
            
		}
    }

    void producer() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
       for(int i = 0; i < 10; ++i) {
            {
                std::lock_guard<std::mutex> lock(queue_mutex);
                data_queue.push(i);
				//queue_mutex.unlock();   
                std::cout << "Produced: " << i << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
           
        }
	   done.store(true);
    }
}


