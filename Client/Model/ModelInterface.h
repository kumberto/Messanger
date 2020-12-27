#ifndef MODELINTERFACE_H
#define MODELINTERFACE_H

#include <string>

class ModelInterface
{
public:
    virtual void singIn(std::string nickName, std::string password) = 0;
};

#endif // MODELINTERFACE_H
