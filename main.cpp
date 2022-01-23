#include <QCoreApplication>
#include <QVector>
#include <iostream>
#include "groupingpattern.h"
#include "groupingbyfolder.h"
#include "groupingbytype.h"
#include "unitInformation.h"

void Foo (std::shared_ptr<GroupingPattern> pattern, QString path){

    auto m = pattern->GetDirectoryInfo(path);
    for (UnitInformation &item : m)
    {
        std::cout << item.GetName().toLocal8Bit().constData()<< std::endl;
        std::cout << item.GetSizeKb()<< std::endl;
        std::cout << item.CalculatePercentage().toLocal8Bit().data()<< std::endl;
    }
}


int main()
{
    try
    {
        QList <QString> path = {"TEST/1_empty_folder",
                               "C:/SPPO/LAB_3_1/TEST/2_files_without_subfolders",
                               "C:/SPPO/LAB_3_1/TEST/3_files_with_subfolders",
                               "C:/SPPO/LAB_3_1/TEST/4_only_subfolders",
                               "TEST/5_three_levels_of_difficulty"};
        for (QString &iter : path)
        {
            std::cout << iter.toLocal8Bit().constData() << std::endl;
            std::cout << "by TIPE"<< std::endl;
            auto derived = std::shared_ptr<GroupingPattern>(new GroupingByType);

            Foo(derived, iter);


            std::cout << "by FOLDER"<< std::endl;
            auto derived2 = std::shared_ptr<GroupingByFolder>(new GroupingByFolder);
            Foo(derived, iter);

        }

    }
    catch (const std::runtime_error &error)
    {
        std::cout << error.what() << std::endl;
    }



    return 0;
}
