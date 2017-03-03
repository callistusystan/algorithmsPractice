import os

first = True

THIS = "_merger.py"
OUTPUT = "_merged.py"

with open(OUTPUT, "w") as output:
	for filename in os.listdir("."):
		if filename.endswith(".py") and filename not in [THIS, OUTPUT]:
			if not first:
				output.write("\n\n")
			first = False
			output.write(filename + "\n")
			with open(filename, "r") as file:
				output.write(file.read())