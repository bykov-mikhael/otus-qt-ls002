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
  _val == 3 ? _val = 0 : _val++;
  qDebug() << _val;
}

void MyStar::paintEvent(QPaintEvent *event) {
  QPainter p(this);

  int lmargin = 1;
  int tmargin = 1;

  switch (_val) {
    case 0: {  // без места - пусто
      break;
    }
    case 1: {  // 1 место - золото
               // Цвет текста

      p.setPen(Qt::NoPen);
      p.setBrush(QColor(255, 215, 0));
      int side = 24;
      p.drawRect(lmargin, tmargin, side, side);

      QFont font = p.font();
      font.setPointSize(10);  // Размер шрифта
      font.setBold(true);     // Жирный шрифт
      p.setFont(font);
      p.setPen(Qt::black);

      p.drawText(height() / 2.5, width() / 1.5, "1");
      break;
    }
    case 2: {  // 2 место - серебро

      p.drawText(height() / 2.5, width() / 1.5, "2");
      p.setPen(Qt::NoPen);
      p.setBrush(QColor(192, 192, 192));
      int centerX = width() / 2;
      int side = 16;
      p.translate(centerX, tmargin);
      p.rotate(45);
      p.drawRect(lmargin, tmargin, side, side);

      p.rotate(-45);

      QFont font = p.font();
      font.setPointSize(10);  // Размер шрифта
      font.setBold(true);     // Жирный шрифт
      p.setFont(font);
      p.setPen(Qt::black);

      p.drawText(-3, tmargin + 15, "2");

      break;
    }
    case 3: {  // 3 место - бронза
      p.setPen(Qt::NoPen);
      p.setBrush(QColor(205, 127, 50));
      int radius = 12;
      p.drawEllipse(QPoint(height() / 2, width() / 2), radius, radius);
      QFont font = p.font();
      font.setPointSize(10);  // Размер шрифта
      font.setBold(true);     // Жирный шрифт
      p.setFont(font);
      p.setPen(Qt::black);

      p.drawText(height() / 2.5, width() / 1.5, "3");

      break;
    }
    default:
      break;
  }
}
