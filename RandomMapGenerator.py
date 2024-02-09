import random

game = input("game: ")
numberOfPlayers = int(input("number of players: "))

m = open(game + "/maps.txt", "r")
c = open(game + "/civs.txt", "r")

maps = []
civs = []

for line in m:
    if line[0] != "/":
        maps.append(line)
        
for line in c:
    if line[0] != "/":
        civs.append(line)
        
mapToPlay = random.choice(maps)
civsToPlay = []

for n in range(101 + 1):
    civsToPlay.append(random.choice(civs))
    
print(f"Map: {mapToPlay}")

for civ in civsToPlay:
    print(civ)
