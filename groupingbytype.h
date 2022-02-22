#ifndef GROUPINGBYTYPE_H
#define GROUPINGBYTYPE_H

#include "unitInformation.h"
#include "groupingpattern.h"


class GroupingByType : public GroupingPattern
{
public:
    GroupingByType();
    std::unique_ptr<QList<UnitInformation>>  GetDirectoryInfo(const QString &path) override;
};

#endif // GROUPINGBYTYPE_H
