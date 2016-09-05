#include "scheduler.h"
long Job::getLength() const {
    return this->length_;
}
long Job::getWeight() const {
    return this->weight_;
}
std::ostream & operator<<(std::ostream & os, const Job &j) {
    os << "Job(" << j.weight_ << "," << j.length_ << ")";
    return os;
}
bool Job::operator==(const Job &j) const {
    return length_ == j.getLength() && weight_ == j.getWeight();
}
void Scheduler::addJob(Job j) {
    this->queue_.push(j);
}
Job Scheduler::getJob() {
    Job j =this->queue_.top();
    queue_.pop();
    return j;
}
