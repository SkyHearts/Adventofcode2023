import sys

# bag = {"red": 12, "green": 13, "blue": 14}

def main():
	"""Count and return the number and their type"""

	file = open('input.txt', 'r')
	gameSum = 0
	while True:
		line = file.readline()
		flag = True
		if not line:
			break
		game = line.split(sep = ":")
		# gameNum = int(game[0].split()[1])
		gamePwr = 0
		gameSet = game[1].split(sep = ";")
		d = {"red": 0, "green": 0, "blue": 0}
		for x in gameSet:
			y = x.split(sep = ",")
			for col in y:
				colNum = col.split()
				if colNum[1] == "red":
					if d["red"] < int(colNum[0]):
						d["red"] = int(colNum[0])
						# print(d["red"])
				elif colNum[1] == "green":
					if d["green"] < int(colNum[0]):
						d["green"] = int(colNum[0])
						# print(d["green"])
				elif colNum[1] == "blue":
					if d["blue"] < int(colNum[0]):
						d["blue"] = int(colNum[0])
						# print(d["blue"])
		gamePwr = d["red"] * d["green"] * d["blue"]
		if flag is True:
			gameSum += gamePwr
	print(gameSum)


# your tests and your error handling
if __name__ == "__main__":
	main()
