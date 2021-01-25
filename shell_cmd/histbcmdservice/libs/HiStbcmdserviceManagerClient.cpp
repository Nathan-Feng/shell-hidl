#include <utils/Log.h>
#include <utils/threads.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include "HiStbcmdserviceManagerClient.h"
#include <vendor/nathan/hwstbcmdservice/1.0/IHwstbcmdservice.h>

using vendor::nathan::hwstbcmdservice::V1_0::IHwstbcmdservice;
using ::android::hardware::hidl_string;

namespace android
{	
	char* HiStbcmdserviceManagerClient::hsInvokeHalClient(char* request, int type)
	{
		printf("zyf HiStbcmdserviceManagerClient hsInvoke %s  type:%d\n",request,type);
		char* result = new char[4096];
		//memset(result,0,sizeof(result));
		sp<IHwstbcmdservice> mHal = NULL;
		mHal = IHwstbcmdservice::getService();
		if(mHal != 0)
		{
			printf("zyf HiStbcmdserviceManagerClient getService != null \n");
			auto cbfun = [&](hidl_string strReply)
			{	
				//result = strReply.c_str();
				memcpy(result,strReply.c_str(),strReply.size()+1);
			};
			mHal->hsInvokeHal(request,type,cbfun);
			printf("zyf HiStbcmdserviceManagerClient hsInvoke result:%s\n",result);
		}
		return result;
	}
};
//end namespace
