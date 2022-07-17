//
// Created by Marcel Vilalta i Soler on 14/7/22.
//

#ifndef OWLIES_OWLYRENDERED_H
#define OWLIES_OWLYRENDERED_H


#include <QOpenGLWidget>
// #include <GL/glew.h>

class OwlyRendered : public QOpenGLWidget {

public:
    explicit OwlyRendered(QWidget* parent = nullptr) : QOpenGLWidget(parent) {

    };

    ~OwlyRendered() {

    }

protected:
    /*
    void initializeGL();

    void resizeGL(int w, int h);


protected slots:
    void paintGL();

    */
};


#endif //OWLIES_OWLYRENDERED_H
