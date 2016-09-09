#include "scheduler.h"
#include <iostream>
int main() {
    int N;
    std::cin >> N;
    Scheduler s;
    long w;
    long l;
    for (int i = 0; i < N; i++) {
        std::cin >> w >> l;
        s.addJob(Job(w, l));
    }
    long time = 0;
    long score = 0;
    for (int i = 0; i < N; i++) {
        Job next = s.getJob();
        time += next.getLength();
        score += next.getWeight() * time;
    }
    std::cout << score << std::endl;
}
