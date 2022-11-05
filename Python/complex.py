# Amispohjalta en ymmärrä matikkaa

class Complex:

    # Attribute
    matikka = 'en tiiä'

    # Init constructor thing
    def __init__(self, a, b):
        self.a = a
        self.b = b
    
    # Setters
    def setI(self, i):
        self.i = i
    
    def setA(self, a):
        self.a = a

    def setB(self, b):
        self.b = b

    # Getters
    def getI(self):
        return self.i
    
    def getA(self):
        return self.a
    
    def getB(self):
        return self.b