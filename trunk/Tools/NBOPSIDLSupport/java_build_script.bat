@echo off
echo Building Java...
javac -cp lib/OPSJLib.jar;lib/ConfigurationLib.jar  @"C:/code/SDS/SDSIDL/Generated/debugger_buildinfo.ops_tmp"
jar cfm "C:/code/SDS/SDSIDL/Generated///SDSIDL.jar" "C:/code/SDS/SDSIDL/Generated//manifest_adds.ops_tmp" -C "C:/code/SDS/SDSIDL/Generated/Java" . 
echo done.
pause
exit
