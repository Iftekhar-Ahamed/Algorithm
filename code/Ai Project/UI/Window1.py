from PyQt5 import QtWidgets, uic
from PyQt5.QtGui import QPixmap
import sys

class Ui(QtWidgets.QMainWindow):
    def __init__(self):
        super(Ui, self).__init__()
        uic.loadUi('Window1.ui', self)
        
        self.button_select = self.findChild(QtWidgets.QPushButton,'pushButton_select')
        self.button_quit = self.findChild(QtWidgets.QPushButton,'pushButton_Quit')
        self.label_image = self.findChild(QtWidgets.QLabel,"selectedImage")
        self.button_select.clicked.connect(self.ButtonPressed_select)
        self.button_quit.clicked.connect(self.ButtonPressed_quit)
        self.show()
    def ButtonPressed_select(self):
        fname = QtWidgets.QFileDialog.getOpenFileName()
        self.pixmap = QPixmap(fname[0])
        self.label_image.setPixmap(self.pixmap.scaled(911,481,aspectRatioMode=1))
    def ButtonPressed_quit(self):
        sys.exit()

app = QtWidgets.QApplication(sys.argv)
window = Ui()
app.exec_()
