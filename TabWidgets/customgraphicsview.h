#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit CustomGraphicsView(QWidget *parent = nullptr);

    void setFixedSizeAndScene(const QSize& size);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
private:
    QGraphicsScene *scene;
    qreal zoomFactor = 1.5;
    qreal currentZoom = 1.0;
};

#endif // CUSTOMGRAPHICSVIEW_H
