import filecmp
import os

# constants
dir_input = "test/input/"
dir_output = "test/output/"
exec_name = "./TestScriptAssemb.sh -c "
input_ext = '.c'
output_name = '_out.txt'
expect_name = '_exp.txt'

input_files = os.listdir(dir_input)
file_names = []
for input_file in input_files:
	file_names.append(input_file[:-2])

# execute input files
for in_name in file_names :
	os.system("rm -f "+dir_output+in_name+expect_name)
	os.system("gcc -o " + dir_output+in_name + "_exec " + dir_input+ in_name+input_ext)
	os.system("./"+dir_output+"/"+in_name + "_exec ; echo $? >> "+dir_output+in_name+expect_name)
	os.system(exec_name+" "+dir_input+in_name+input_ext + " > "+dir_output+in_name+output_name)

# compare output files with expected output
for name in file_names :
	print name + ": " + str(filecmp.cmp(dir_output+name+output_name, dir_output+name+expect_name))
