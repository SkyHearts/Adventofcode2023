import sys

bag = {"red": 12, "green": 13, "blue": 14}

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
		gameNum = int(game[0].split()[1])
		gameSet = game[1].split(sep = ";")
		for x in gameSet:
			y = x.split(sep = ",")
			d = {"red": 0, "green": 0, "blue": 0}
			for col in y:
				colNum = col.split()
				if colNum[1] == "red":
					d["red"] += int(colNum[0])
				elif colNum[1] == "green":
					d["green"] += int(colNum[0])
				elif colNum[1] == "blue":
					d["blue"] += int(colNum[0])
				if d["red"] > bag["red"] or d["green"] > bag["green"] or d["blue"] > bag["blue"]:
					flag = False
					break
		if flag is True:
			gameSum += gameNum
	print(gameSum)


# your tests and your error handling
if __name__ == "__main__":
	main()
