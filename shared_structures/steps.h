#ifndef STEPS_H
#define STEPS_H

class Step {
public:
    int id_;
};

class DispatchStep : public Step {
public:
    int number_of_troops_;
};

#endif // STEPS_H
