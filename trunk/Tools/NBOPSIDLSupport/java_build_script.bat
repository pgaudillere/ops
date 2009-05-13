@echo off
echo Building Java...
javac -cp lib/OPSJLib.jar;lib/ConfigurationLib.jar  @"C:/code home/OPS4/Examples/TestAll/Generated/debugger_buildinfo.ops_tmp"
jar cfm "C:/code home/OPS4/Examples/TestAll/Generated///TestAll.jar" "C:/code home/OPS4/Examples/TestAll/Generated//manifest_adds.ops_tmp" -C "C:/code home/OPS4/Examples/TestAll/Generated/Java" . 
echo done.
pause
exit
