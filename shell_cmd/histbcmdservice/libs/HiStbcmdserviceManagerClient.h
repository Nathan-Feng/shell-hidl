#ifndef _HISERVICEMANAGERCLIENT_H_
#define _HISERVICEMANAGERCLIENT_H_

#include <utils/RefBase.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

namespace android
{
class HiStbcmdserviceManagerClient: public RefBase
{
public:
	char* hsInvokeHalClient(char* request, int type);
};
};
#endif
