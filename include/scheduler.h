#ifndef SCHEDULER
#define SCHEDULER
#include <iostream>
#include <vector>
#include <queue>
class Job {
    public:
        Job() {
            weight_ = 1.0f;
            length_ = 1.0f;
        }
        Job(float w, float l) {
            weight_ = w;
            length_ = l;
        }
        float getLength() const;
        float getWeight() const;
        friend std::ostream & operator<<(std::ostream &os, const Job &j);
        bool operator==(const Job &j) const;
    private:
        float length_;
        float weight_;
};
//a job with the highest priority has the highest weight/length ratio
//intuitively, jobs with equal lengths, but different weights, the highest weights go first
//this means the largest w/constant goes first
class JobComparator {
    public:
        bool operator()(Job a, Job b) {
            return a.getWeight() / a.getLength() < b.getWeight() / b.getLength();
        }
};
class Scheduler {
    //for the pqueue, if compare(a,b) is true, a goes to the bottom of the heap
    //in this case, the job with the smaller w/l ratio goes to the bottom,
    //making this a max heap for w/l ratios
    private:
        typedef std::priority_queue<Job, std::vector<Job>, JobComparator> max_heap;
        max_heap queue_;
    public:
        void addJob(Job j);
        Job getJob();
};
#endif // SCHEDULER
