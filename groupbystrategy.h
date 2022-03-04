#ifndef GROUPBYSTRATEGY_H
#define GROUPBYSTRATEGY_H

#include <QList>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

#include "unitInformation.h"
#include "directoryobserver.h"

class GroupByStrategy
{
public:
    virtual ~GroupByStrategy() = default;

    virtual void Explore(const QString &path) const = 0;

    void Attach(directoryObserver *observer);

    void OnFinish(std::unique_ptr<QList<UnitInformation>> &items) const;

private:
    directoryObserver *observer_;
};

class GroupByFolder : public GroupByStrategy
{
public:
    void Explore(const QString &path) const;
};

class GroupByType : public GroupByStrategy
{
public:
    void Explore(const QString &path) const;
};

#endif // GROUPBYSTRATEGY_H
