#include "groupingbytype.h"
#include "unitInformation.h"
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

GroupingByType::GroupingByType(){

}
std::unique_ptr<QList<UnitInformation>> GroupingByType::GetDirectoryInfo(const QString &path)
{
    QHash<QString, qint64> hash;
    QFileInfo dir_info(path);
    qint64 full_size = 0;

    if (!dir_info.isDir()) { throw std::runtime_error("Invalid path. No such file or directory"); }

    QDirIterator dir_iterator(dir_info.absoluteFilePath(), QDir::Files, QDirIterator::Subdirectories);

    while (dir_iterator.hasNext())
    {
        dir_iterator.next();
        const QFileInfo &file_info = dir_iterator.fileInfo();
        qint64 size = file_info.size();
        hash[file_info.suffix()] += size;
        full_size += size;
    }
    std::unique_ptr<QList<UnitInformation>> result_list = std::make_unique<QList<UnitInformation>>();
    QHashIterator hash_iterator(hash);

    while (hash_iterator.hasNext())
    {
        hash_iterator.next();
        result_list->append(UnitInformation("*." + hash_iterator.key(), hash_iterator.value(), full_size));
    }

    return result_list;
}
