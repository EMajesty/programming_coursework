class Book:
    def __init__(self, name, Author):
        self.name = name
        self.Author = Author

class Author:
    def __init__(self, name):
        self.name = name

    def writeBook(self, bName):
        self.bName = Book(bName, self)

teppo = Author("teppo")
teppo.writeBook("kirja1")
