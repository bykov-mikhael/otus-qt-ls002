#include "mystar.hpp"

#include <QDebug>
#include <QObject>
#include <QPainter>
#include <QPushButton>
#include <QWidget>
#include <QtMath>

MyStar::MyStar(QWidget *parent) : QPushButton(parent) { _val = 0; }

void MyStar::mouseMoveEvent(QMouseEvent *event) {}

void MyStar::mousePressEvent(QMouseEvent *event) {
  qDebug() << _val;
  _val == 3 ? _val = 0 : _val++;
}

void MyStar::paintEvent(QPaintEvent *event) {
  QPainter p(this);

  switch (_val) {
    case 0: {  // без места - пусто
      break;
    }
    case 1: {  // 1 место - золото
      p.setPen(Qt::NoPen);
      p.setBrush(QColor(255, 215, 0));
      p.drawRect(width() / 2, height() / 2, 25, 25);
      break;
    }
    case 2: {  // 2 место - серебро
      p.setPen(Qt::NoPen);
      p.setBrush(QColor(192, 192, 192));
      int centerX = width() / 2;
      int centerY = height() / 2;
      int side = 20;  // сторона квадрата
      p.translate(centerX, centerY);  // перемещаем начало координат в центр
      p.rotate(45);  // поворачиваем на 45 градусов
      p.drawRect(10, 10, side, side);  // рисуем квадрат
      break;
    }
    case 3: {  // 3 место - бронза
      p.setPen(Qt::NoPen);
      p.setBrush(QColor(205, 127, 50));
      p.drawEllipse(QPoint(height() / 2, width() / 2), 20, 20);
      break;
    }
    default:
      break;
  }
}
