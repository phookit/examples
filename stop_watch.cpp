//Sample provided by Fabio Galuppo
//April 2015
//http://www.simplycpp.com

#include <chrono>

struct stop_watch final
{
    stop_watch() : Start_(now()) {}
    
    std::chrono::seconds elapsed_s() const
    {
        using std::chrono::seconds;
        return std::chrono::duration_cast<seconds>(elapsed());
    }
    
    std::chrono::milliseconds elapsed_ms() const
    {
        using std::chrono::milliseconds;
        return std::chrono::duration_cast<milliseconds>(elapsed());
    }
    
    std::chrono::microseconds elapsed_us() const
    {
        using std::chrono::microseconds;
        return std::chrono::duration_cast<microseconds>(elapsed());
    }
    
    std::chrono::nanoseconds elapsed_ns() const
    {
        using std::chrono::nanoseconds;
        return std::chrono::duration_cast<nanoseconds>(elapsed());
    }
    
    void restart() { Start_ = now(); }
    
    stop_watch(const stop_watch&) = delete;
    stop_watch& operator=(const stop_watch&) = delete;
    
private:
    static std::chrono::high_resolution_clock::time_point now()
    {
        return std::chrono::high_resolution_clock::now();
    }
    
    std::chrono::duration<double> elapsed() const
    {
        return now() - Start_;
    }
    
    std::chrono::high_resolution_clock::time_point Start_;
};

#include <iostream>

int main()
{
    stop_watch sw;
    
    int total0 = 0;
    const int N0 = 100;
    for (int i = 0; i < N0; ++i) total0 += i;
    auto m0 = sw.elapsed_ns().count();
    
    int total1 = 0;
    const int N1 = 10000;
    for (int i = 0; i < N1; ++i) total1 += i;
    auto m1 = sw.elapsed_ns().count();
    
    long total2 = 0;
    const int N2 = 10000000;
    for (int i = 0; i < N2; ++i) total2 += i;
    auto m2 = sw.elapsed_ns().count();
    
    std::cout << "Elapsed time N = " << N0 << " total = " << total0 << " is " << m0 << " nanoseconds.\n";
    std::cout << "Elapsed time N = " << N1 << " total = " << total1 << " is " << m1 << " nanoseconds.\n";
    std::cout << "Elapsed time N = " << N2 << " total = " << total2 << " is " << m2 << " nanoseconds.\n";
    
    std::cout << "Hello, World!\n";
    auto m3 = sw.elapsed_us().count();
    std::cout << "Elapsed time is " << m3 << " microseconds.\n";
    
    sw.restart();
    
    const int N4 = 1000;
    for (int i = 0; i < N4 - 1; ++i) std::cout << "Simply C++ ";
    std::cout << "Hello, World!\n";
    auto m4 = sw.elapsed_ms().count();
    std::cout << "Elapsed time is " << m4 << " milliseconds.\n";
    
    return 0;
}
