#ifndef STEPS_H
#define STEPS_H

class Step : public Structure {
public:
    int id_;
};

class DispatchStep : public Step {
public:
    int number_of_troops_;
};

class EndStep : public Step {
public:
    Player * winner_;
};

#endif // STEPS_H
