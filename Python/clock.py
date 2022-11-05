# Jäi kesken, aivot loppuu ja dedikset lähenee

class Clock:
    def __init__(self):
        self.seconds = 0
        self.ticker()

    def getTime(self):
        return self.seconds

    def ticker(self):
        import threading
        self.timer = threading.Timer(1,self.ticker())
        
    def increment(self):
        self.seconds =+ 1

class AlarmClock(Clock):
    def setAlarm(self,seconds):
        self.seconds = seconds
        

kello1 = Clock()
kello2 = AlarmClock()

while True:
    print(kello1.getTime())