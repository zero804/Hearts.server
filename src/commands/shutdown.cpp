#include "../define.h"
#include "../comm.h"
#include "shutdown.h"

extern bool server_shutdown;
extern class cDescList * descriptor_list;

void cShutdown::Execute( cDescriptor & d, cParam & param )
{
  descriptor_list->send_to_all("%s", "Shuting down now...");
  server_shutdown = true;
}
