@echo off
echo Building Java...
javac -cp lib/OPSJLib.jar;lib/ConfigurationLib.jar  @"C:/code home/OPS4/Examples/PizzaProject/Generated/debugger_buildinfo.ops_tmp"
jar cfm "C:/code home/OPS4/Examples/PizzaProject/Generated///PizzaProject.jar" "C:/code home/OPS4/Examples/PizzaProject/Generated//manifest_adds.ops_tmp" -C "C:/code home/OPS4/Examples/PizzaProject/Generated/Java" . 
echo done.
pause
exit
