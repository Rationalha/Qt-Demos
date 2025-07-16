#ifndef TREEDATA_H
#define TREEDATA_H

#include <QObject>
#include <QVector>

enum Type
{
    UNKNOWN = -1,
    PROVINCE,
    PERSON
};

// person信息
typedef struct Person_t{
    QString name;   // 姓名
    QString sex;    // 性别
    int age;     // 年龄
    QString phone;  // 电话号码
    Person_t()
    {
        age = 0;
    }
} Person;

// 省份信息
typedef struct Province_t{
    QString name;
    QVector<Person*> people;
} Province;


#endif // TREEDATA_H
