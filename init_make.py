#python3

import sys
import os
import re

#all src dirs
dirs = ". base"
temp_dir = "temp"
target = "icongenerator"
cpp_flags = os.popen("sdl2-config --cflags").read().replace("\n","")+" -Wall -g2 -ggdb -O0 -I. -Ibase"

cpp_libs = os.popen("sdl2-config --libs").read().replace("\n","")+" -lfreetype -lSDL2_ttf -lSDL2_mixer -lSDL2_image -lm -lstdc++"

############################
#create tempdir
if not os.path.exists(temp_dir):
	os.mkdir(temp_dir)
	
#########################################
#split line
cpp_files = []
for one_dir in dirs.split(' '):
	cpp_files = cpp_files + [one_dir+"/"+cpp for cpp in os.listdir(one_dir) if cpp.endswith('.cpp') or cpp.endswith('.c')]

get_temp_o = lambda cpp:temp_dir+"/"+cpp.replace("./","").replace(".cpp",".o").replace("/",".")

objs = list(map(get_temp_o, cpp_files))

#print(cpp_files)
#print(objs)
#sys.exit()


phony = """
.PHONY: clean all
all:$(TARGET)
""".replace("$(TARGET)", target)

flags = """
CPPFLAGS := $(cpp_flags)
CPPLIBS := $(cpp_libs)

""".replace("$(cpp_flags)", cpp_flags).replace("$(cpp_libs)", cpp_libs)

def get_gen_temp_o(cpp):
	cmd = "g++ -MM $(CPPFLAGS) "+cpp
	return os.popen(cmd.replace("$(CPPFLAGS)", cpp_flags)).read()+"\tg++ -c $< -o $@ $(CPPFLAGS)\n".replace("$(CPPFLAGS)", cpp_flags)
	
def write_temp_o(make_file, cpp_files):
	for cpp in cpp_files:		
		temp_o = get_temp_o(cpp)		
		make_file.write(re.sub(r'^.*\.o\s*:', temp_o+":", get_gen_temp_o(cpp)))
		make_file.write("\n")
		print(temp_o+":"+cpp)
	
target_cmd = """
$(TARGET):$(OBJS)
	g++ $(OBJS) -o $@ $(CPPLIBS)
""".replace("$(TARGET)", target).replace("$(OBJS)", " ".join(objs))

clean_cmd = """
clean:
	rm -f *.d; \
	rm -f *.o; \
	rm -f $(TARGET) \
	rm -rf $(TEMP_DIR)
""".replace("$(TARGET)", target).replace("$(TEMP_DIR)", temp_dir)

with open("Makefile", "w") as make_file:
	print("start write makefile")
	make_file.write(phony)
	print(phony)
	make_file.write(flags)
	print(flags)
	write_temp_o(make_file, cpp_files)
	make_file.write(target_cmd)
	print(target_cmd)
	make_file.write(clean_cmd)
	print(clean_cmd)
	print("end write makefile")
