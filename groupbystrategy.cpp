#include "groupbystrategy.h"
#include <QDebug>

void GroupByStrategy::Attach(directoryObserver *observer)
{
    qDebug() << "DEBUGGG!!!";
    if (observer == nullptr)
    {
        throw std::runtime_error("The observer is nullptr.");
    }
    observer_ = observer;
}

void GroupByStrategy::OnFinish(std::unique_ptr<QList<UnitInformation>> &items) const
{
    observer_->Update(items);
}

void GroupByFolder::Explore(const QString &path) const
{
    QFileInfo directory_info(path);

    if (!directory_info.isDir())
    {
        throw std::runtime_error("The directory is invalid.");
    }

    std::unique_ptr<QList<UnitInformation>> item_list = std::make_unique<QList<UnitInformation>>();

    qint64 total_size = 0;

    QDir directory(directory_info.absoluteFilePath());

    for (const QFileInfo &file_info : directory.entryInfoList(QDir::Files))
    {
        total_size += file_info.size();
    }

    item_list->append(UnitInformation("(Current Directory)", total_size));

    for (const QFileInfo &file_info : directory.entryInfoList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDir::Name))
    {
        qint64 size = 0;

        QDirIterator it(file_info.absoluteFilePath(), QDir::Files, QDirIterator::Subdirectories);

        while (it.hasNext())
        {
            it.next();

            size += it.fileInfo().size();
        }
        total_size += size;

        item_list->append(UnitInformation(file_info.fileName(), size)); // добавляем папку в массив
    }

    for (auto &item : *item_list)
    {
        item.SetFullSizeByte(total_size);
    }
    OnFinish(item_list);
}

void GroupByType::Explore(const QString &path) const
{
    QFileInfo directory_info(path);

    if (!directory_info.isDir())
    {
        throw std::runtime_error("The directory is invalid.");
    }

    qint64 total_size = 0;

    QHash<QString, qint64> hash;

    QDirIterator it(directory_info.absoluteFilePath(), QDir::Files, QDirIterator::Subdirectories);

    while (it.hasNext())
    {
        it.next();

        const QFileInfo &file_info = it.fileInfo();

        qint64 size = file_info.size();

        hash[file_info.suffix()] += size;

        total_size += size;
    }

    std::unique_ptr<QList<UnitInformation>> item_list = std::make_unique<QList<UnitInformation>>();

    QHashIterator hash_it(hash);

    while (hash_it.hasNext())
    {
        hash_it.next();

        item_list->append(UnitInformation("*." + hash_it.key(), hash_it.value(), total_size));
    }

    OnFinish(item_list);
}
