#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "log.h"

cLog::cLog( const char * filename )
{
 bLogging = true;
 if (!(logfile=fopen(filename, "a"))) {
   printf("SYSERR: failed to turn on logging.\n");
   bLogging = false;
 }
}

cLog::~cLog()
{
 fclose(logfile); 
}
 
void cLog::Write (const char *format, ...)
{
 if (!bLogging) return;

 va_list args;
 time_t ctime = time(nullptr);
 char *time_s = asctime(localtime(&ctime));

 if (format == NULL)
   format = "SYSERR: log() received a NULL format.";

 time_s[strlen(time_s) - 1] = '\0';

 fprintf(logfile, "%-15.15s :: ", time_s + 4); // skip day of the week

 va_start(args, format);
 vfprintf(logfile, format, args);
 va_end(args);

 fprintf(logfile, "\n");
 fflush(logfile);
}