package com.nathan.shellcmd;

import android.util.Log;

/**
 * this class works with Android TV 10.0
 * this class can do high level cmds
 * please do use this class as less as possible
 * @author nathan
 *
 */
public class ShellCmd {        

		
        public static final String OK = "success";
		public static final String FAILED = "error";
        private String TAG = "ShellCmd";
        
        public ShellCmd() {

        } 
		
		static {
           System.loadLibrary("histbcmdservice_jni");		
		}
	
	
		public native String hsInvokeJni(String cmd, int type);
    
} 