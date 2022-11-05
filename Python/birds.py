class Bird:
    def __init__(self,name,eggs):
        self.name = name
        if 1 <= eggs <= 10:
            self.eggs = eggs

class Migratory(Bird):
    def __init__(self,country,month):
        if 5 <= len(country) <= 20:
            self.country = country.capitalize()

        if 1 <= month <= 12:
            self.month = month