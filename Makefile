#
project_name=Digital_Inputs
all:
	blechc ${project_name}.blc
	cp blech/${project_name}.* .
	sed -i "s|blech/${project_name}.h|${project_name}.h|g" ${project_name}.c
