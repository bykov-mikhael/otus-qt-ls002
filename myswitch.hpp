#pragma once

#include <QBrush>
#include <QObject>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QPushButton>
#include <QTimeLine>
#include <QWidget>

class MySwitch : public QPushButton {
  Q_OBJECT

 private:
  QTimeLine m_timeLine;

 public:
  MySwitch(QWidget *parent = nullptr) : QPushButton(parent) {
    setCheckable(true);
    m_timeLine.setDirection(QTimeLine::Forward);
    m_timeLine.setDuration(1000);
    m_timeLine.setFrameRange(0, 100);
    //    m_timeLine.setEasingCurve();
    connect(this, &QAbstractButton::clicked, [this]() {
      m_timeLine.setDirection(m_timeLine.direction() == QTimeLine::Forward
                              ? QTimeLine::Backward
                              : QTimeLine::Forward);
      m_timeLine.start();
    });

    connect(&m_timeLine, &QTimeLine::valueChanged, [this](qreal) { update(); });
  }

  void paintEvent(QPaintEvent *event) {
    QPainter p(this);
    int lmargin = 1;
    int rmargin = 1;
    int tmargin = 1;
    int bmargin = 1;

    int r =
    qMin(height() / 2 - (tmargin + bmargin), width() / 2 - (lmargin + rmargin));

    QPoint p1(lmargin + r, height() / 2);
    QPoint p2(width() - r - rmargin, height() / 2);

    {
      p.save();

      p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::PenCapStyle::RoundCap));
      p.drawRect(rect().adjusted(0, 0, 0, 0));

      p.restore();
    }

    {
      p.save();
      p.setPen(QPen(Qt::green, height() * 3 / 4, Qt::SolidLine,
                    Qt::PenCapStyle::RoundCap));
      p.drawLine(p1, p2);
      p.restore();
    }

    p.setPen(Qt::NoPen);
    p.setBrush(Qt::gray);

    auto tpos = m_timeLine.currentValue();
    auto dx = (p2.x() - p1.x()) * tpos;

    QPoint rCenter = QPoint(p1.x() + dx, p1.y());

    //    QPoint rCenter = isChecked() ? p2 : p1;

    p.drawEllipse(rCenter, r, r);
  }
};
