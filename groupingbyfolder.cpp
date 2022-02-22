#include "groupingbyfolder.h"
#include "unitInformation.h"
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <iostream>

GroupingByFolder::GroupingByFolder(){

}
std::unique_ptr<QList<UnitInformation>> GroupingByFolder::GetDirectoryInfo(const QString &path)
{

    QFileInfo dir_info(path);
    qint64 full_size = 0;

    std::unique_ptr<QList<UnitInformation>> result_list = std::make_unique<QList<UnitInformation>>();

    if (!dir_info.isDir()) { throw std::runtime_error("Invalid path. No such file or directory"); }

    QDir dir(dir_info.absoluteFilePath());

    for (const QFileInfo &file_info : dir.entryInfoList(QDir::Files))
    {
        full_size += file_info.size();
    }

    result_list->append(UnitInformation("(Current Directory)", full_size));

    for (const QFileInfo &file_info : dir.entryInfoList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDir::Name))
    {      
        qint64 size = 0;
        QDirIterator current_dir_iterator(file_info.absoluteFilePath(), QDir::Files, QDirIterator::Subdirectories);

        while (current_dir_iterator.hasNext())
        {
            current_dir_iterator.next();
            size += current_dir_iterator.fileInfo().size();
        }

        full_size += size;        
        result_list->append(UnitInformation(file_info.fileName(), size));
    }   
    for (UnitInformation &item : *result_list)
    {        
        item.SetFullSizeByte(full_size);
    }

    return result_list;
}
