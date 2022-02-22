#ifndef GROUPINGBYFOLDER_H
#define GROUPINGBYFOLDER_H

#include "unitInformation.h"
#include "groupingpattern.h"


class GroupingByFolder : public GroupingPattern
{
public:
    GroupingByFolder();
    std::unique_ptr<QList<UnitInformation>> GetDirectoryInfo(const QString &path) override;
};

#endif // GROUPINGBYFOLDER_H
