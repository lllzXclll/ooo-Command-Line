**C Command-Line - ooo**


example usage:
ooo> <command> [options] <arguments>


commands:
help - shows all commands or explains a specific command

copy - copy source.txt dest.txt
	creates dest.txt if doesn't exists
	overwrites if it does exist
	
count - count file.txt
	counts lines, words and characters in the file
	
search - search file.txt "word"
	returns the lines with the "word" (with the line number)

cf - create file - cf file.txt ["content"]
	create a file.txt with content optional
	
cdir - create directory - cdir folder
	creates a folder named folder
	
rf - remove file - rf file.txt
	deletes file.txt

rdir - remove directory - rdir folder
	deletes folder. if not empty ask to confirm the action

