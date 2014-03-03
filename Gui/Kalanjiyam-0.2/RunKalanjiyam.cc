#include <iostream>  
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int a = system("cd /usr/share/applications/Kalanjiyam/Gui/Kalanjiyam-0.2/cde/ && ./cde python /usr/share/applications/Kalanjiyam/Gui/Kalanjiyam-0.2/cde/web.py");
  int b = system("rm -f -r /usr/share/applications/Kalanjiyam/Gui/Kalanjiyam-0.2/cde.full-environment");
  int c = system("cp -r /usr/share/applications/Kalanjiyam/Gui/Kalanjiyam-0.2/cde/cde-package/cde.full-environment /usr/share/applications/Kalanjiyam/Gui/Kalanjiyam-0.2/");
  std::string copy_syntax = "/usr/share/applications/Kalanjiyam/Gui/Kalanjiyam-0.2/./cde-exec /usr/share/applications/Kalanjiyam/Gui/Kalanjiyam-0.2/./Kalanjiyam";
  try
  {
    if(system(copy_syntax.c_str())!=0)
    {
    throw 1;
    }
  }
  catch(int e)
  {
  std::cout<<"Unable to Execute\n";
  }	 
 return 0;
}
