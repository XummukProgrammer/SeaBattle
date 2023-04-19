#ifndef IAPPRUNNERDELEGATE_H
#define IAPPRUNNERDELEGATE_H


class IAppRunnerDelegate
{
public:
    IAppRunnerDelegate();
    virtual ~IAppRunnerDelegate();

public:
    virtual void Run() = 0;
};

#endif // IAPPRUNNERDELEGATE_H
