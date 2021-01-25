/******************************************************************************

  Copyright (C), 2001-2020, nathan Tech. Co., Ltd.

 ******************************************************************************
  File Name     : nathan_hal.c
  Version       : Initial Draft
  Author        : nathan
  Created       : 2020/08/26
  Description   :
  History       :
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#include <assert.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <utils/Log.h>
#include <cutils/sockets.h>

#define LOG_TAG "hicmdservice_hal"
#define printf ALOGE

#define BUFFER_MAX    4096  /* input buffer for commands */
#define TOKEN_MAX     24     /* max number of arguments in buffer */
#define REPLY_MAX     256   /* largest reply allowed */
#define READ_ERROR    -1   /*read error*/


static int do_system_cmd(const char *arg, char *reply,bool isNeedRet){

	FILE *fpRead = NULL;
	char cmd[1024]={0};
	char buf[1024]={0};
	memset(buf,0,sizeof(buf));
		fpRead = popen(arg,"r");
		if(fpRead == NULL){
			ALOGE("configServer run system error!");
			return -1;	
		}
		printf("zyf do_system_cmd isNeedRet :%d\n", isNeedRet);
		if(!isNeedRet){
			printf("zyf do_system_cmd before pclose\n");
			pclose(fpRead);
			printf("zyf do_system_cmd after  pclose\n");
			fpRead = NULL;
			return 0;
		}
		while(fgets(buf,1024-1,fpRead) != NULL && strlen(reply) < BUFFER_MAX){
			ALOGE("fgets strlen buf : %d,replay len : %d   BUFFER_MAX:%d",strlen(buf), strlen(reply), BUFFER_MAX);
			if(BUFFER_MAX > (strlen(buf) + strlen(reply))){
				strncat(reply,buf,strlen(buf));
			}				
			else{			
				strncat(reply,buf,BUFFER_MAX - strlen(reply));
			}
		}
		ALOGE("after execute  reply strlen %d",strlen(reply));		
		pclose(fpRead);
		fpRead = NULL;

	return 0;
}


char* hsInvokeNative(const char* request, int type)
{
	printf("zyf hsInvokeNative enter %s  type:%d\n",request, type);
	bool flag = false;
	if(type == 1){
		flag = true;
	}
	static char reply[BUFFER_MAX];
	reply[0] = 0;
	int ret = do_system_cmd(request,reply,flag);
	printf("zyf hsInvokeNative ret: %d  type:%d\n", ret ,type);
	if (ret == -1){
		strcpy(reply,"error");
	}
	if ((type == 0) && (ret == 0)) {
		strcpy(reply,"success");
	}
	if ((type == 1) && (ret == 0) && (strlen(reply) == 0)) {
		strcpy(reply,"success no reply");
	}
	return reply;
}
