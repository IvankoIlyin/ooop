#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <QMainWindow>

namespace Ui {
class Archive;
}

class Archive : public QMainWindow
{
    Q_OBJECT

public:
    explicit Archive(QWidget *parent = nullptr);
    ~Archive();

private:
    Ui::Archive *ui;
};

#endif // ARCHIVE_H
