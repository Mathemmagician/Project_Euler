

def createTest():
	n = 100
	l = 5

	with open(f"pytest{l}", "w") as f:
	    f.write(str(n-l) +"\n")
	    for i in range(l+1,n + 1):
	        f.write(str(l) + " " + str(i) + "\n")


def createBigTest():
	R = 20 # from L to 20
	L = 20 # from 3 to 20

	with open("bigtest", "w") as f:
		for l in range(3, L+1):
			for r in range(l, R+1):
				f.write(str(l) + " " + str(r) + "\n")

def analyzeBigTest():
	R = 20 # from L to 20
	L = 20 # from 3 to 20
	with open("bigtest.txt", "r") as out:
		with open("bigtest", "r") as inp:
			inps = inp.readlines()[1:]
			outs = out.readlines()
			matrix = [[0 for i in range(R)] for j in range(L)]
			print(len(inps), len(outs))
			assert(len(inps) == len(outs))
			for i in range(len(inps)):
				l, r = list(map(int, inps[i].split()))
				value = int(outs[i])
				matrix[l-1][r-1] = value
	print("\n".join(map(lambda x: "\t".join(map(str,x)), matrix[2:])))

analyzeBigTest()
		

				




#createBigTest()




def printNicely():
	with open("data.txt", "r") as f:
		db = f.readlines()
		answers = []
		for line in db:
			l = line.split()
			answers.append(int(l[0]))

	print("L=3, R=?, Ans")
	for i, each in enumerate(answers):
		print(3, "\t", (i+4), "\t", each)

	print(" ".join(map(str, answers)))






