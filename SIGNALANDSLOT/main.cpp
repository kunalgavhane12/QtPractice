#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QWidget>

#include "b.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    B b1;

    // Main container widget
    QWidget window;
    window.setWindowTitle("Side-by-Side Image and Text Example");

    // Create the horizontal layout
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setSpacing(0); // Remove space between widgets
    layout->setContentsMargins(0, 0, 0, 0); // Remove margins around the layout

    // QLabel for image
    QLabel *lblpix = new QLabel();
    QPixmap pix("/home/kunal/Downloads/photo.jpeg");

    if (!pix.isNull()) {  // Ensure the image is loaded
        lblpix->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        lblpix->setText("Image not found.");
    }

    // QLabel for text
    QLabel *label = new QLabel("THIS IS ME!");
    label->setAlignment(Qt::AlignVCenter); // Center text vertically

    // Add the labels to the layout with no gap
    layout->addWidget(lblpix, 0); // Image on the left
    layout->addWidget(label, 0);  // Text on the right
    layout->addStretch();

    // Set the layout to the main window
    window.setLayout(layout);
    window.resize(200, 60); // Adjust window size for compact view
    window.show();

    return app.exec();
}
