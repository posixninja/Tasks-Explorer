/*-
 * Copyright 2010, Mac OS X Internals. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY Mac OS X Internals ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Mac OS X Internals OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of Mac OS X Internals.
 */

#import <Cocoa/Cocoa.h>
#import "tasks_explorer.h"


@interface DaemonDataSource : NSObject {
	CLIENT *client;
	int tasksCount;
	int *tasksPidList;
	BOOL inited;
	host_info_dynamic hostInfo;
}

-(void)restart_daemon;
-(void)updateProcessInfo;
-(int)processesCount;
-(int*)processesPIDCArray;
-(BOOL)processBaseInfo:(task_info_base*)taskInfo forPID:(int)pid;
-(host_info_dynamic*)hostInfoDynamic;
-(BOOL)processDynInfo:(task_info_dynamic*)dynInfo forPID:(int)pid;
-(NSString*)processDescription:(int)pid;
-(NSString*)commandLineForPID:(int)pid;
-(int)killProcess:(int)pid;
-(NSMutableArray*)createEnvList:(int)pid;
-(NSMutableArray*)createFilesList:(int)pid;
-(NSMutableArray*)createThreadsList:(int)pid;
-(BOOL)initDaemon;
-(NSMutableArray*)createCallStack:(int)pid withTid:(u_long)tid;

@end
