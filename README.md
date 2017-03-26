This is a program built to help students practice on the GATE Virtual Calculator without the hassle of opening up a browser.  
It is simple to use and tailor made for the IIT provided Virtual Calculator.  
  
![alt tag](https://github.com/samadritakarmakar/GATE_calculator/blob/master/GATE_Calc.png)
  
How to Use:  
  
Windows Users:  
Pre-built application for 64 bit system is provided under releases tab.  
https://github.com/samadritakarmakar/GATE_calculator/releases  
If you are using 32 bit system, , you will need to build the application. Please see 'How to Build' section below.  
  
Download, 'GATE_calc_WIN_x64.zip'.  
Extract all the contents of the zip file.  
Go into the folder 'Browser-CMake-Build'  
Right click on 'GATE_calc.exe'. Click 'Create Shortcut'. Copy the shortcut to your preferred location.  
  
Linux Users:  
Pre-built application for 64 bit system is provided under releases tab.  
https://github.com/samadritakarmakar/GATE_calculator/releases  
If you are using 32 bit system, you will need to build the application. Please see 'How to Build' section below.  
  
Downlaod, 'GATE_calc_Linux_x64.zip'.  
Extract all the contents of the zip file.  
Click 'GATE_calc.sh' to use.  
You will need libqt5webkit5, libqt5gui5, libqt5core5a, libstdc++6, libc6,  	libgcc1, libc6 to be installed in your system.  
Packages were build against Qt 5.7 and may be a prerequisite. Please try out he pre-build application before to decide to build them yourself.  
  
  
  
How to Build:  
For those who wish to build it themselves.  
  
Clone the Repo by using git  
git clone https://github.com/samadritakarmakar/GATE_calculator.git  
or download the zip file  
https://github.com/samadritakarmakar/GATE_calculator/archive/master.zip  
  
Windows Users:  
Download MSYS2 and install mingw, qtcreator, cmake and make. Architecture may be 64 or 32 as you may like.  
For more info on how to do this see,  
http://www.msys2.org/  
&  
https://wiki.qt.io/MSYS2  
  
Open CMakeLists.txt in 'GATE_calculator' folder, and make sure there are lines as the following:  
  
#Comment out if building on UNIX  
    set(CMAKE_CXX_FLAGS "-O2 -mwindows")        ## Optimize  
#Uncomment if building on UNIX  
\#    set(CMAKE_CXX_FLAGS "-O2")  
  
add '#' in the start of the line to comment or uncomment.  
  
  
create folder 'GATE_calculator_build' in the same folder you have 'GATE_calculator' folder.  
  
type the following commands  
  
export CC=/c/msys64/usr/bin/gcc  
export CXX=/c/msys64/usr/bin/g++  
cmake ../GATE_calculator  
make  

msys64 will be replaced by msys32 if you are using 32 bit binaries.  
  
copy .dll files to folder 'GATE_calculator_build' as mentioned in file win_depends.md  
  
The executable(.exe) must now be ready to use.  
  
Linux Users:  
Download install gcc, qtcreator, cmake and make. Architecture may be 64 or 32 as you may like.  
  
Open CMakeLists.txt in 'GATE_calculator' folder, and make sure there are lines as the following:  
  
#Comment out if building on UNIX  
  
\#    set(CMAKE_CXX_FLAGS "-O2 -mwindows")        ## Optimize  
  
#Uncomment if building on UNIX  
  
set(CMAKE_CXX_FLAGS "-O2")  
  
  
add '#' in the start of the line to comment or uncomment.  
  
  
create folder 'GATE_calculator_build' in the same folder you have where 'GATE_calculator' folder.  
  
type the following commands  
  
cmake ../GATE_calculator  
make  
  
the executable should be ready to use.  
  
  
NOTE: Although the program is licensed under GPL, the html file and its dependencies ARE NOT LICENSED UNDER GPL. They are under copyright of IITs and not under purview of GPL.  
  
