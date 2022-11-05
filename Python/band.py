class Member:
    def __init__(self, name, instrument):
        self.name = name
        self.instrument = instrument
    
    def joinBand(self, Band):
        Band.members.append(self)

    def leaveBand(self):
        pass

class Band:

    def __init__(self, name, genre, website, email):
        self.name = name
        self.genre = genre
        self.website = website
        self.email = email
        self.members = []
    
    def playShow(self):
        pass

    def makeRecord(self):
        pass

    def hireMember(self, Member):
        self.members.append(Member)

    def fireMember(self):
        pass

    def printMembers(self):
        for i in range(len(self.members)):
            print(vars(self.members[i]))

    def disband(self):
        pass
    
teppo = Member("Teppo", "haitari")
james = Member("James", "poikkihuilu")

band1 = Band("Metallicats", "polka", "metallicats.com", "metallicats@aol.com")
band1.hireMember(teppo)

james.joinBand(band1)

#print(band1.members) # tulostaa muistiosoitteet eikä nimiä
print(band1.name)
band1.printMembers()