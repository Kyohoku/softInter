/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../queryWords/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[17];
    char stringdata0[379];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 26), // "on_toolButton_cet4_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 26), // "on_toolButton_cet6_clicked"
QT_MOC_LITERAL(4, 62, 27), // "on_pushButton_query_clicked"
QT_MOC_LITERAL(5, 90, 27), // "on_pushButton_study_clicked"
QT_MOC_LITERAL(6, 118, 28), // "on_pushButton_review_clicked"
QT_MOC_LITERAL(7, 147, 26), // "on_toolButton_user_clicked"
QT_MOC_LITERAL(8, 174, 26), // "on_toolButton_sent_clicked"
QT_MOC_LITERAL(9, 201, 27), // "on_lineEdit_word_textEdited"
QT_MOC_LITERAL(10, 229, 4), // "arg1"
QT_MOC_LITERAL(11, 234, 20), // "onCompleterActivated"
QT_MOC_LITERAL(12, 255, 7), // "content"
QT_MOC_LITERAL(13, 263, 22), // "onCompleterHighlighted"
QT_MOC_LITERAL(14, 286, 32), // "on_lineEdit_word_editingFinished"
QT_MOC_LITERAL(15, 319, 28), // "on_lineEdit_word_textChanged"
QT_MOC_LITERAL(16, 348, 30) // "on_lineEdit_word_returnPressed"

    },
    "Widget\0on_toolButton_cet4_clicked\0\0"
    "on_toolButton_cet6_clicked\0"
    "on_pushButton_query_clicked\0"
    "on_pushButton_study_clicked\0"
    "on_pushButton_review_clicked\0"
    "on_toolButton_user_clicked\0"
    "on_toolButton_sent_clicked\0"
    "on_lineEdit_word_textEdited\0arg1\0"
    "onCompleterActivated\0content\0"
    "onCompleterHighlighted\0"
    "on_lineEdit_word_editingFinished\0"
    "on_lineEdit_word_textChanged\0"
    "on_lineEdit_word_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    1,   86,    2, 0x08 /* Private */,
      11,    1,   89,    2, 0x08 /* Private */,
      13,    1,   92,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    1,   96,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_toolButton_cet4_clicked(); break;
        case 1: _t->on_toolButton_cet6_clicked(); break;
        case 2: _t->on_pushButton_query_clicked(); break;
        case 3: _t->on_pushButton_study_clicked(); break;
        case 4: _t->on_pushButton_review_clicked(); break;
        case 5: _t->on_toolButton_user_clicked(); break;
        case 6: _t->on_toolButton_sent_clicked(); break;
        case 7: _t->on_lineEdit_word_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onCompleterActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->onCompleterHighlighted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_lineEdit_word_editingFinished(); break;
        case 11: _t->on_lineEdit_word_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_lineEdit_word_returnPressed(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
