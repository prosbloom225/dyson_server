#ifndef IACTION_H
#define IACTION_H

class IAction {
    protected:
        int ticks;
    public:
        virtual ~IAction();
        virtual void execute() = 0;
        virtual void onTick() = 0;
};


#endif
