#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PhyleasFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PhyleasFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=TimerFunctions.c TimeDelay.c Explorer16.c Explore.c CANFunctions.c DmaPhyleas.c Encoder.c Decoder.c LCDlib.c LCDBlocking.c AffichAppDemo.c Xbee.c mywi.c Bluetooth.c Main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/TimerFunctions.o ${OBJECTDIR}/TimeDelay.o ${OBJECTDIR}/Explorer16.o ${OBJECTDIR}/Explore.o ${OBJECTDIR}/CANFunctions.o ${OBJECTDIR}/DmaPhyleas.o ${OBJECTDIR}/Encoder.o ${OBJECTDIR}/Decoder.o ${OBJECTDIR}/LCDlib.o ${OBJECTDIR}/LCDBlocking.o ${OBJECTDIR}/AffichAppDemo.o ${OBJECTDIR}/Xbee.o ${OBJECTDIR}/mywi.o ${OBJECTDIR}/Bluetooth.o ${OBJECTDIR}/Main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/TimerFunctions.o.d ${OBJECTDIR}/TimeDelay.o.d ${OBJECTDIR}/Explorer16.o.d ${OBJECTDIR}/Explore.o.d ${OBJECTDIR}/CANFunctions.o.d ${OBJECTDIR}/DmaPhyleas.o.d ${OBJECTDIR}/Encoder.o.d ${OBJECTDIR}/Decoder.o.d ${OBJECTDIR}/LCDlib.o.d ${OBJECTDIR}/LCDBlocking.o.d ${OBJECTDIR}/AffichAppDemo.o.d ${OBJECTDIR}/Xbee.o.d ${OBJECTDIR}/mywi.o.d ${OBJECTDIR}/Bluetooth.o.d ${OBJECTDIR}/Main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/TimerFunctions.o ${OBJECTDIR}/TimeDelay.o ${OBJECTDIR}/Explorer16.o ${OBJECTDIR}/Explore.o ${OBJECTDIR}/CANFunctions.o ${OBJECTDIR}/DmaPhyleas.o ${OBJECTDIR}/Encoder.o ${OBJECTDIR}/Decoder.o ${OBJECTDIR}/LCDlib.o ${OBJECTDIR}/LCDBlocking.o ${OBJECTDIR}/AffichAppDemo.o ${OBJECTDIR}/Xbee.o ${OBJECTDIR}/mywi.o ${OBJECTDIR}/Bluetooth.o ${OBJECTDIR}/Main.o

# Source Files
SOURCEFILES=TimerFunctions.c TimeDelay.c Explorer16.c Explore.c CANFunctions.c DmaPhyleas.c Encoder.c Decoder.c LCDlib.c LCDBlocking.c AffichAppDemo.c Xbee.c mywi.c Bluetooth.c Main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PhyleasFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/TimerFunctions.o: TimerFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/TimerFunctions.o.d 
	@${RM} ${OBJECTDIR}/TimerFunctions.o 
	@${FIXDEPS} "${OBJECTDIR}/TimerFunctions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TimerFunctions.o.d" -o ${OBJECTDIR}/TimerFunctions.o TimerFunctions.c   
	
${OBJECTDIR}/TimeDelay.o: TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/TimeDelay.o 
	@${FIXDEPS} "${OBJECTDIR}/TimeDelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TimeDelay.o.d" -o ${OBJECTDIR}/TimeDelay.o TimeDelay.c   
	
${OBJECTDIR}/Explorer16.o: Explorer16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Explorer16.o.d 
	@${RM} ${OBJECTDIR}/Explorer16.o 
	@${FIXDEPS} "${OBJECTDIR}/Explorer16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Explorer16.o.d" -o ${OBJECTDIR}/Explorer16.o Explorer16.c   
	
${OBJECTDIR}/Explore.o: Explore.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Explore.o.d 
	@${RM} ${OBJECTDIR}/Explore.o 
	@${FIXDEPS} "${OBJECTDIR}/Explore.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Explore.o.d" -o ${OBJECTDIR}/Explore.o Explore.c   
	
${OBJECTDIR}/CANFunctions.o: CANFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CANFunctions.o.d 
	@${RM} ${OBJECTDIR}/CANFunctions.o 
	@${FIXDEPS} "${OBJECTDIR}/CANFunctions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CANFunctions.o.d" -o ${OBJECTDIR}/CANFunctions.o CANFunctions.c   
	
${OBJECTDIR}/DmaPhyleas.o: DmaPhyleas.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/DmaPhyleas.o.d 
	@${RM} ${OBJECTDIR}/DmaPhyleas.o 
	@${FIXDEPS} "${OBJECTDIR}/DmaPhyleas.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/DmaPhyleas.o.d" -o ${OBJECTDIR}/DmaPhyleas.o DmaPhyleas.c   
	
${OBJECTDIR}/Encoder.o: Encoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Encoder.o.d 
	@${RM} ${OBJECTDIR}/Encoder.o 
	@${FIXDEPS} "${OBJECTDIR}/Encoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Encoder.o.d" -o ${OBJECTDIR}/Encoder.o Encoder.c   
	
${OBJECTDIR}/Decoder.o: Decoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Decoder.o.d 
	@${RM} ${OBJECTDIR}/Decoder.o 
	@${FIXDEPS} "${OBJECTDIR}/Decoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Decoder.o.d" -o ${OBJECTDIR}/Decoder.o Decoder.c   
	
${OBJECTDIR}/LCDlib.o: LCDlib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDlib.o.d 
	@${RM} ${OBJECTDIR}/LCDlib.o 
	@${FIXDEPS} "${OBJECTDIR}/LCDlib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDlib.o.d" -o ${OBJECTDIR}/LCDlib.o LCDlib.c   
	
${OBJECTDIR}/LCDBlocking.o: LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDBlocking.o.d 
	@${RM} ${OBJECTDIR}/LCDBlocking.o 
	@${FIXDEPS} "${OBJECTDIR}/LCDBlocking.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDBlocking.o.d" -o ${OBJECTDIR}/LCDBlocking.o LCDBlocking.c   
	
${OBJECTDIR}/AffichAppDemo.o: AffichAppDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AffichAppDemo.o.d 
	@${RM} ${OBJECTDIR}/AffichAppDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/AffichAppDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/AffichAppDemo.o.d" -o ${OBJECTDIR}/AffichAppDemo.o AffichAppDemo.c   
	
${OBJECTDIR}/Xbee.o: Xbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Xbee.o.d 
	@${RM} ${OBJECTDIR}/Xbee.o 
	@${FIXDEPS} "${OBJECTDIR}/Xbee.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Xbee.o.d" -o ${OBJECTDIR}/Xbee.o Xbee.c   
	
${OBJECTDIR}/mywi.o: mywi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/mywi.o.d 
	@${RM} ${OBJECTDIR}/mywi.o 
	@${FIXDEPS} "${OBJECTDIR}/mywi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mywi.o.d" -o ${OBJECTDIR}/mywi.o mywi.c   
	
${OBJECTDIR}/Bluetooth.o: Bluetooth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Bluetooth.o.d 
	@${RM} ${OBJECTDIR}/Bluetooth.o 
	@${FIXDEPS} "${OBJECTDIR}/Bluetooth.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Bluetooth.o.d" -o ${OBJECTDIR}/Bluetooth.o Bluetooth.c   
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o 
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d" -o ${OBJECTDIR}/Main.o Main.c   
	
else
${OBJECTDIR}/TimerFunctions.o: TimerFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/TimerFunctions.o.d 
	@${RM} ${OBJECTDIR}/TimerFunctions.o 
	@${FIXDEPS} "${OBJECTDIR}/TimerFunctions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TimerFunctions.o.d" -o ${OBJECTDIR}/TimerFunctions.o TimerFunctions.c   
	
${OBJECTDIR}/TimeDelay.o: TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/TimeDelay.o 
	@${FIXDEPS} "${OBJECTDIR}/TimeDelay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TimeDelay.o.d" -o ${OBJECTDIR}/TimeDelay.o TimeDelay.c   
	
${OBJECTDIR}/Explorer16.o: Explorer16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Explorer16.o.d 
	@${RM} ${OBJECTDIR}/Explorer16.o 
	@${FIXDEPS} "${OBJECTDIR}/Explorer16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Explorer16.o.d" -o ${OBJECTDIR}/Explorer16.o Explorer16.c   
	
${OBJECTDIR}/Explore.o: Explore.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Explore.o.d 
	@${RM} ${OBJECTDIR}/Explore.o 
	@${FIXDEPS} "${OBJECTDIR}/Explore.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Explore.o.d" -o ${OBJECTDIR}/Explore.o Explore.c   
	
${OBJECTDIR}/CANFunctions.o: CANFunctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/CANFunctions.o.d 
	@${RM} ${OBJECTDIR}/CANFunctions.o 
	@${FIXDEPS} "${OBJECTDIR}/CANFunctions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/CANFunctions.o.d" -o ${OBJECTDIR}/CANFunctions.o CANFunctions.c   
	
${OBJECTDIR}/DmaPhyleas.o: DmaPhyleas.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/DmaPhyleas.o.d 
	@${RM} ${OBJECTDIR}/DmaPhyleas.o 
	@${FIXDEPS} "${OBJECTDIR}/DmaPhyleas.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/DmaPhyleas.o.d" -o ${OBJECTDIR}/DmaPhyleas.o DmaPhyleas.c   
	
${OBJECTDIR}/Encoder.o: Encoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Encoder.o.d 
	@${RM} ${OBJECTDIR}/Encoder.o 
	@${FIXDEPS} "${OBJECTDIR}/Encoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Encoder.o.d" -o ${OBJECTDIR}/Encoder.o Encoder.c   
	
${OBJECTDIR}/Decoder.o: Decoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Decoder.o.d 
	@${RM} ${OBJECTDIR}/Decoder.o 
	@${FIXDEPS} "${OBJECTDIR}/Decoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Decoder.o.d" -o ${OBJECTDIR}/Decoder.o Decoder.c   
	
${OBJECTDIR}/LCDlib.o: LCDlib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDlib.o.d 
	@${RM} ${OBJECTDIR}/LCDlib.o 
	@${FIXDEPS} "${OBJECTDIR}/LCDlib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDlib.o.d" -o ${OBJECTDIR}/LCDlib.o LCDlib.c   
	
${OBJECTDIR}/LCDBlocking.o: LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCDBlocking.o.d 
	@${RM} ${OBJECTDIR}/LCDBlocking.o 
	@${FIXDEPS} "${OBJECTDIR}/LCDBlocking.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/LCDBlocking.o.d" -o ${OBJECTDIR}/LCDBlocking.o LCDBlocking.c   
	
${OBJECTDIR}/AffichAppDemo.o: AffichAppDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AffichAppDemo.o.d 
	@${RM} ${OBJECTDIR}/AffichAppDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/AffichAppDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/AffichAppDemo.o.d" -o ${OBJECTDIR}/AffichAppDemo.o AffichAppDemo.c   
	
${OBJECTDIR}/Xbee.o: Xbee.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Xbee.o.d 
	@${RM} ${OBJECTDIR}/Xbee.o 
	@${FIXDEPS} "${OBJECTDIR}/Xbee.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Xbee.o.d" -o ${OBJECTDIR}/Xbee.o Xbee.c   
	
${OBJECTDIR}/mywi.o: mywi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/mywi.o.d 
	@${RM} ${OBJECTDIR}/mywi.o 
	@${FIXDEPS} "${OBJECTDIR}/mywi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mywi.o.d" -o ${OBJECTDIR}/mywi.o mywi.c   
	
${OBJECTDIR}/Bluetooth.o: Bluetooth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Bluetooth.o.d 
	@${RM} ${OBJECTDIR}/Bluetooth.o 
	@${FIXDEPS} "${OBJECTDIR}/Bluetooth.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Bluetooth.o.d" -o ${OBJECTDIR}/Bluetooth.o Bluetooth.c   
	
${OBJECTDIR}/Main.o: Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Main.o.d 
	@${RM} ${OBJECTDIR}/Main.o 
	@${FIXDEPS} "${OBJECTDIR}/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Main.o.d" -o ${OBJECTDIR}/Main.o Main.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PhyleasFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_REAL_ICE=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PhyleasFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PhyleasFinal.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PhyleasFinal.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PhyleasFinal.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
