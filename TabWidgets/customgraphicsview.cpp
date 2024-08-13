#include "customgraphicsview.h"
#include <QWheelEvent>
#include <QGraphicsScene>
#include <QResizeEvent>
#include <QWidget>

CustomGraphicsView::CustomGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
    , scene(new QGraphicsScene(this))
{
    setScene(scene);
    setRenderHints(QPainter::HighQualityAntialiasing);

    setFixedSizeAndScene(QSize(600, 400));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void CustomGraphicsView::setFixedSizeAndScene(const QSize& size)
{
    setFixedSize(size);
    scene->setSceneRect(0, 0, size.width(), size.height());
}

void CustomGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    scene->setSceneRect(0, 0, event->size().width(), event->size().height());
}

void CustomGraphicsView::wheelEvent(QWheelEvent *event)
{
    qreal factor = zoomFactor;
    if (event->angleDelta().y() < 0)
        factor = 1.0 / zoomFactor;

    currentZoom *= factor;
    scale(factor, factor);

   QWidget *parentWidget = qobject_cast<QWidget*>(parent());
    if (parentWidget) {
        QSize newSize = parentWidget->size() * factor;
        parentWidget->resize(newSize);
    }

    QGraphicsView::wheelEvent(event);
}
