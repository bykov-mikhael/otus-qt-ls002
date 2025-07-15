#pragma once

#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <array>

constexpr int ICON_T = 4;

class MyStar : public QPushButton {
  Q_OBJECT
 public:
  MyStar(QWidget *parent = nullptr);

 private:
  int _val{0};

  // QWidget interface
 protected:
  void mouseMoveEvent(QMouseEvent *event);
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent *event);
};
