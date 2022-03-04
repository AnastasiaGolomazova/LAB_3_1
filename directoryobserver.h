#ifndef DIRECTORYOBSERVER_H
#define DIRECTORYOBSERVER_H

#include "unitInformation.h"

class directoryObserver
{
public:
    virtual ~directoryObserver() = default;

    virtual void Update(std::unique_ptr<QList<UnitInformation>> &items) const = 0;
};

#endif // DIRECTORYOBSERVER_H
