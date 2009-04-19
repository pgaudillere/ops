mkdir C++

mkdir C++\include
mkdir C++\include\xml
mkdir C++\lib


copy "..\C++\include\*.*" "C++\include"
copy "..\C++\include\xml\*.*" "C++\include\xml"

copy "..\C++\lib\*.*" "C++\lib"
copy "..\C:\Program Files\boost\boost_1_38\lib\*.*" "C++\lib"


jar cvf OPS_Core_Cpp.jar C++
rename OPS_Core_Cpp.jar OPS_Core_Cpp.zip
