#ifndef STEPS_H
#define STEPS_H

class Step {
public:
    int id_;
};

class Dispatch_Step : public Step {
public:
    int number_of_troops_;
};

#endif // STEPS_H
