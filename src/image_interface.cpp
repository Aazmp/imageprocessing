#include "image_interface.h"
#include <QLabel>
#include <QImage>
#include <QFileDialog>
#include <QString>
#include <iostream>

image_interface::image_interface(QLabel *const srclbl, QLabel *const dstlbl,
                                 QImage *const srcimg, QImage *const dstimg,
                                 QObject *parent) : QObject(parent)
{
    srcLabel = srclbl;
    srcImage = srcimg;
    dstLabel = dstlbl;
    dstImage = dstimg;
    newWidth = 640;
    newHeight = 480;
}

void image_interface::load()
{
    QString filename = QFileDialog::getOpenFileName(0, "Load", "", "Images (*.png *.bmp *.jpg *.jpeg *.gif)");
    if (!filename.isEmpty())
    {
        srcImage->load(filename);
        emit print_message(QString("loaded image ") + QString::number(srcImage->height()) + QString("x") + QString::number(srcImage->width()));
        updateSrcImage();
    }
    return;
}

void image_interface::copy()
{
    *srcImage = *dstImage;
    updateSrcImage();
    return;
}

void image_interface::rescaleSrcImage()
{
    *srcImage = srcImage->scaled(newWidth, newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    updateSrcImage();
    return;
}

void image_interface::updateSrcImage()
{
    srcLabel->setPixmap(QPixmap::fromImage(*srcImage));
    srcLabel->resize(srcImage->width(), srcImage->height());
    srcLabel->show();
    return;
}

void image_interface::updateDstImage()
{
    dstLabel->setPixmap(QPixmap::fromImage(*dstImage));
    dstLabel->resize(dstImage->width(), dstImage->height());
    dstLabel->show();
    return;
}

void image_interface::updateWidth(const QString& w)
{
    bool ok;
    newWidth = w.toUInt(&ok);
    if (!ok)
        emit print_message(QString("error reading newWidth"));
    else
        emit print_message(QString("newWidth updated to ") + QString::number(newWidth));
    return;
}

void image_interface::updateHeight(const QString& h)
{
    bool ok;
    newHeight = h.toUInt(&ok);
    if (!ok)
        emit print_message(QString("error reading newHeight"));
    else
        emit print_message(QString("newHeight updated to ") + QString::number(newHeight));
    return;
}
