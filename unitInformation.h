#ifndef UNITINFORMATION_H
#define UNITINFORMATION_H

#include <QString>
#include <QLocale>

class UnitInformation
{
public:
    UnitInformation(const QString &name, const qint64 size, const qint64 full_size = 0): name_(name), size_byte_(size), full_size_byte_(full_size){};
    void SetName(const QString &name) { name_ = name; }
    void SetSizeByte(const qint64 size) { size_byte_ = size; }
    void SetFullSizeByte(const qint64 full_size) { full_size_byte_ = full_size; }

    const QString &GetName() const { return name_; }
    float GetSizeKb() const { return size_byte_/1024.0f; }
    float GetFullSizeKb() const { return full_size_byte_/1024.0f;}

    QString CalculatePercentage() const
    {
        if (size_byte_ == 0) { return "0.00 %"; }
        float percentage_size = (double)size_byte_ / full_size_byte_ * 100;
        if (percentage_size < 0.01f) { return "< 0.01 %"; }
        return QString::number(percentage_size, 'f', 2) + " %";
    }
    bool operator>(const UnitInformation &obj) const
    {
        return size_byte_ > obj.GetSizeKb();
    }

private:
    static const QLocale locale_;
    QString name_;
    qint64 size_byte_;
    qint64 full_size_byte_;
};

const QLocale locale_(QLocale::English, QLocale::UnitedStates);


#endif // UNITINFORMATION_H

