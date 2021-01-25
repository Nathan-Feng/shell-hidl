#define LOG_NDEBUG 0

#include "utils/Log.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <cutils/sockets.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <utils/threads.h>
#include <cutils/properties.h>
#include "jni.h"
#include <utils/Log.h>
#include "JNIHelp.h"
#include "HiStbcmdserviceManagerClient.h"
#include <android_runtime/AndroidRuntime.h>
#include "utils/Errors.h"  // for status_t
#include "utils/KeyedVector.h"
#include "utils/String8.h"
#include <binder/Parcel.h>
#define HI_SUCCESS       0
#define HI_FAILURE       (-1)
// ----------------------------------------------------------------------------

using namespace android;

static jstring charToJstring(JNIEnv *env, const char *pat) {
    jclass strClass = (env)->FindClass("java/lang/String");
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>","([BLjava/lang/String;)V");
    jbyteArray bytes = (env)->NewByteArray(strlen(pat));
    (env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte *) pat);
    jstring encoding = (env)->NewStringUTF("utf-8");
    return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
}


static char *jstringToChar(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = (env)->FindClass("java/lang/String");
    jstring strencode = (env)->NewStringUTF("utf-8");
    jmethodID mid = (env)->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) (env)->CallObjectMethod(jstr, mid, strencode);
    jsize alen = (env)->GetArrayLength(barr);
    jbyte *ba = (env)->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (env)->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

JNIEXPORT jstring JNICALL Java_hsInvokeJni(JNIEnv *env, jobject thiz,jstring request,jint type)
{
	ALOGE("zyf JNI Java_hsInvokeJni request %s type= %d  \n",request,type);
	const char* tmp = env->GetStringUTFChars(request, NULL);
	if (tmp == NULL)
	{
		// Out of memory
		return (env)->NewStringUTF("error");
	}
	//String8 requestStr(tmp);
	//env->ReleaseStringUTFChars(request, tmp);
	//tmp = NULL;
	char* requestStr = jstringToChar(env,request);
	char* reply = HiStbcmdserviceManagerClient().hsInvokeHalClient(requestStr,type);
	ALOGE("zyf JNI Java_hsInvokeJni reply %s \n",reply);
	return (env)->NewStringUTF(reply);
}

static JNINativeMethod gMethods[] = {
	{"hsInvokeJni", "(Ljava/lang/String;I)Ljava/lang/String;", (void *)Java_hsInvokeJni},
};

static int register_android_histbcmdservicemanage_common(JNIEnv *env)
{
    return AndroidRuntime::registerNativeMethods(env, "com/nathan/shellcmd/ShellCmd", gMethods, NELEM(gMethods));
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env = NULL;
    jint result = -1;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    if(register_android_histbcmdservicemanage_common(env) < 0) {
        return result;
    }

    /* success -- return valid version number */
    result = JNI_VERSION_1_4;
    return result;
}
