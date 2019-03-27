import filecmp
import os

# constants
dir_input = "test/input_normal/"
dir_output = "test/output_normal/"
dir_input_erwarn = "test/input_warn_errors/"
dir_output_erwarn = "test/output_warn_errors/"
exec_name = "./TestScriptAssemb.sh -a -c -o"
input_ext = '.c'
output_name = '_out.txt'
expect_name = '_exp.txt'

# execute normal input files
input_files = os.listdir(dir_input)
file_names = []
for input_file in input_files:
	file_names.append(input_file[:-2])

for in_name in file_names :
	os.system("rm -f "+dir_output+in_name+expect_name)
	os.system("gcc -o " + dir_output+in_name + "_exec " + dir_input+ in_name+input_ext)
	os.system("./"+dir_output+"/"+in_name + "_exec ; echo $? >> "+dir_output+in_name+expect_name)
	os.system(exec_name+" "+dir_input+in_name+input_ext + " > "+dir_output+in_name+output_name)

# compare output files with expected output
for name in file_names :
	print name + ": " + str(filecmp.cmp(dir_output+name+output_name, dir_output+name+expect_name))

# execute input files containing warnings and errors
input_files_erwarn = os.listdir(dir_input_erwarn)
file_names_erwarn = []
for input_file in input_files_erwarn:
	file_names_erwarn.append(input_file[:-2])

for in_name in file_names_erwarn :
	os.system(exec_name+" "+dir_input_erwarn+in_name+input_ext + " > "+dir_output_erwarn+in_name+output_name)

for name in file_names_erwarn :
	print name + ": " + str(filecmp.cmp(dir_output_erwarn+name+output_name, dir_output_erwarn+name+expect_name))

