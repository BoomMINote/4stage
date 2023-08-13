#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int check_rep_part(int* p, int n, int start, int end) {
    int* hash = new int[n / 32 + 1];
    for (int i = start; i < end; i++) {
        int array_index = p[i] / 32;
        int shift_index = p[i] % 32;
        int bit = (hash[array_index] >> shift_index) & 0x01;
        if (bit) return 1;
        hash[array_index] ^= 1 << shift_index;
    }
    delete[] hash;
    return 0;
}

int check_rep_multi(int* p, int n, int num_threads) {
    vector<thread> threads;
    vector<int> results(num_threads, 0);
    int chunk_size = n / num_threads;
    for (int i = 0; i < num_threads; i++) {
        int start = i * chunk_size;
        int end = (i == num_threads - 1) ? n : (i + 1) * chunk_size;
        threads.emplace_back(check_rep_part, p, n, start, end);
    }
    for (auto& t : threads) {
        t.join();
    }
    for (int i = 0; i < num_threads; i++) {
        if (results[i]) return 1;
    }
    return 0;
}

int main() {
    int num = 2'000'000'000;
    int* arr = new int[num];
    for (int i = 0; i < num; i++) arr[i] = i;
    //arr[num - 1] = arr[num - 2];
    int num_threads = 16; // Change this to the desired number of threads
    int ret = check_rep_multi(arr, num, num_threads);
    if (ret)
        cout << "repeat" << endl;
    else
        cout << "non repeat" << endl;
    delete[] arr;
    return 0;
}
