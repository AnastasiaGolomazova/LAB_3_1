#ifndef GROUPINGPATTERN_H
#define GROUPINGPATTERN_H

#include "unitInformation.h"

class GroupingPattern
{
public:
    virtual ~GroupingPattern() = default;
    virtual std::unique_ptr<QList<UnitInformation>> GetDirectoryInfo(const QString &path)=0;
};
#endif // GROUPINGPATTERN_H
