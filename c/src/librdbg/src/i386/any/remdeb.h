/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _REMDEB_H_RPCGEN
#define _REMDEB_H_RPCGEN

#include <rpc/rpc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RTEMS_PORT 2071
#define RTEMS_BACK_PORT 2073
#ifndef REMDEB_H
#define RPCGENSRVNAME(a)     a

  enum rpc_type {
    SUNRPC = 0,
    BADRPCTYPE = 25,
  };
  typedef enum rpc_type rpc_type;
#define NET_SAFE 1400

  struct UDP_MSG {
    u_char type;
    u_char msg_num;
    u_short spec;
    long pid;
    u_long context;
  };
  typedef struct UDP_MSG UDP_MSG;
/*
 * Sun request values for the remote ptrace system call
 */

  enum ptracereq {
    RPT_TRACEME = 0,
    RPT_CHILDDONE = 0,
    RPT_PEEKTEXT = 0 + 1,
    RPT_PEEKDATA = 0 + 2,
    RPT_PEEKUSER = 0 + 3,
    RPT_POKETEXT = 0 + 4,
    RPT_POKEDATA = 0 + 5,
    RPT_POKEUSER = 0 + 6,
    RPT_CONT = 0 + 7,
    RPT_KILL = 0 + 8,
    RPT_SINGLESTEP = 0 + 9,
    RPT_ATTACH = 0 + 10,
    RPT_DETACH = 0 + 11,
    RPT_GETREGS = 0 + 12,
    RPT_SETREGS = 0 + 13,
    RPT_GETFPREGS = 0 + 14,
    RPT_SETFPREGS = 0 + 15,
    RPT_READDATA = 0 + 16,
    RPT_WRITEDATA = 0 + 17,
    RPT_READTEXT = 0 + 18,
    RPT_WRITETEXT = 0 + 19,
    RPT_GETFPAREGS = 0 + 20,
    RPT_SETFPAREGS = 0 + 21,
    RPT_22 = 0 + 22,
    RPT_23 = 0 + 23,
    RPT_SYSCALL = 0 + 24,
    RPT_DUMPCORE = 0 + 25,
    RPT_26 = 0 + 26,
    RPT_27 = 0 + 27,
    RPT_28 = 0 + 28,
    RPT_GETUCODE = 0 + 29,
    RPT_GETTARGETTHREAD = 50,
    RPT_SETTARGETTHREAD = 51,
    RPT_THREADSUSPEND = 52,
    RPT_THREADRESUME = 53,
    RPT_THREADLIST = 54,
    RPT_GETTHREADNAME = 55,
    RPT_SETTHREADNAME = 56,
    RPT_SETTHREADREGS = 57,
    RPT_GETTHREADREGS = 58,
    RPT_STEPRANGE = 75,
    RPT_CONTTO = 76,
    RPT_SETBREAK = 77,
    RPT_CLRBREAK = 78,
    RPT_GETBREAK = 79,
    RPT_GETNAME = 80,
    RPT_STOP = 81,
    RPT_PGETREGS = 82,
    RPT_PSETREGS = 83,
    RPT_PSETTHREADREGS = 84,
    RPT_PGETTHREADREGS = 85,
  };
  typedef enum ptracereq ptracereq;

  struct xdr_regs {
    u_int tabreg[19];
  };
  typedef struct xdr_regs xdr_regs;
/* now define register macros to apply to xdr_reg struct */

#define GS     0
#define FS     1
#define ES     2
#define DS     3
#define EDI    4
#define ESI    5
#define EBP    6
#define ESP    7
#define EBX    8
#define EDX    9
#define ECX    10
#define EAX    11
#define TRAPNO 12
#define ERR    13
#define EIP    14
#define CS     15
#define EFL    16
#define UESP   17
#define SS     18

#define REG_PC tabreg[EIP]      /* PC (eip) register offset */
#define REG_SP tabreg[UESP]     /* SP (uesp) register offset */
#define REG_FP tabreg[EBP]      /* FP (ebp) register offset */
/* now define the BREAKPOINT mask technique to a long word */
#define SET_BREAK(l)   ((l&0xFFFFFF00) | 0xCC)
#define IS_BREAK(l)    (((l) & 0xFF) == 0xCC)
#define ORG_BREAK(c,p) (((c) & 0xFFFFFF00) | ((p) & 0xFF))
#define IS_STEP(regs)  (regs.tabreg[TRAPNO] == 1)   /* was step and not break */
#define BREAK_ADJ      1        /* must subtract one from address after bp */
#define BREAK_SIZE     1        /* Breakpoint occupies one byte */
#define TARGET_PROC_TYPE  0
#define MAXDEBUGGEE 150
#define NAMEMAX 17
  /*
   * Memory data for read/write text or data. The size is in data. The target
   * addr is in the addr field.
   * Be careful before modifying because this value goes into internal
   * pipes and is allocated on stack too. Pipes and/or the stack could
   * become too small if this value gets incremented.
   */
#define MEM_DATA_MAX 256

  struct xdr_mem {
    u_long addr;
    u_int dataNb;
    u_char data[MEM_DATA_MAX];
  };
  typedef struct xdr_mem xdr_mem;

  enum break_type {
    BRKT_NONE = 0,
    BRKT_INSTR = 1,
    BRKT_READ = 2,
    BRKT_WRITE = 3,
    BRKT_ACCESS = 4,
    BRKT_EXEC = 5,
    BRKT_OS_CALL = 6,
    BRKT_OS_SWITCH = 7,
    BRKT_STEPEMUL = 8,
  };
  typedef enum break_type break_type;
#define MAX_THRD_BRK 4

  struct xdr_break {
    u_char type;
    u_char thread_spec;
    u_short handle;
    u_long ee_loc;
    u_long ee_type;
    u_short length;
    u_char pass_count;
    u_char curr_pass;
    u_long thread_list[MAX_THRD_BRK];
  };
  typedef struct xdr_break xdr_break;
#define UTHREAD_MAX 64
#define THREADNAMEMAX 16

  typedef char *thread_name;

  struct KernThread {
    u_int threadLi;
  };
  typedef struct KernThread KernThread;
  typedef KernThread *ptThreadList;

  struct thread_list {
    u_int nbThread;
    ptThreadList threads;
  };
  typedef struct thread_list thread_list;

  struct ptrace_addr_data_in {
    ptracereq req;
    union {
      xdr_regs regs;
      struct {
        u_int pregs_len;
        u_int *pregs_val;
      } pregs;
      thread_name name;
      xdr_mem mem;
      xdr_break breakp;
      u_int address;
    } ptrace_addr_data_in_u;
  };
  typedef struct ptrace_addr_data_in ptrace_addr_data_in;

  struct ptrace_addr_data_out {
    ptracereq req;
    union {
      xdr_regs regs;
      struct {
        u_int pregs_len;
        u_int *pregs_val;
      } pregs;
      thread_list threads;
      thread_name name;
      xdr_mem mem;
      xdr_break breakp;
      u_int addr;
    } ptrace_addr_data_out_u;
  };
  typedef struct ptrace_addr_data_out ptrace_addr_data_out;

  typedef struct {
    u_int CHAR_DATA_len;
    char *CHAR_DATA_val;
  } CHAR_DATA;
#define XRY_MAX_INST_BUFF 128
#define XRY_MAX_INSTANCES 16
#ifndef XRY_MAX_CMD_STR
#define XRY_MAX_CMD_STR 320
#endif                          /* REMDEB_H */

  struct xry_inst {
    u_char flags;
    u_char type;
    u_char sub_type;
    u_char res_type;
    u_long value;
    u_long value2;
  };
  typedef struct xry_inst xry_inst;

  struct instance {
    struct xry_inst instances[XRY_MAX_INSTANCES];
    u_char buffer[XRY_MAX_INST_BUFF];
  };
  typedef struct instance instance;

  struct instance_union {
    bool_t instances;
    union {
      instance inst;
      char *buffer;
    } instance_union_u;
  };
  typedef struct instance_union instance_union;

  typedef char *one_arg;
#define XRY_MAX_OBJ_NAME 32
  /*
   * now open_connex() routine which establishes a connection to server 
   */

  enum debug_type {
    DEBTYP_PROCESS = 0,
    DEBTYP_C_ACTOR = 1,
    DEBTYP_KERNEL = 2,
    DEBTYP_OTHER = 3,
  };
  typedef enum debug_type debug_type;
#define DEBUGGER_IS_GDB 0x2     /* */

  struct open_in {
    u_char back_port[16];
    u_short debug_type;
    u_short flags;
    u_char destination[16];
    one_arg user_name;
  };
  typedef struct open_in open_in;

  struct open_out {
    u_long port;
    u_int pad[4];
    u_int fp;
    u_char cmd_table_num;
    u_char cmd_table_vers;
    u_short server_vers;
  };
  typedef struct open_out open_out;
  /*
   * now close_connex() routine which detaches from server 
   */

  enum close_control {
    CLOSE_IGNORE = 0,
    CLOSE_KILL = 1,
    CLOSE_DETACH = 2,
  };
  typedef enum close_control close_control;

  struct close_in {
    close_control control;
  };
  typedef struct close_in close_in;
  /*
   * now send_signal() routine which sends signals to processes like kill(2) 
   */

  struct signal_in {
    int pid;
    int sig;
  };
  typedef struct signal_in signal_in;

  struct signal_out {
    int kill_return;
    int errNo;
  };
  typedef struct signal_out signal_out;
  /*
   * now wait_info() routine which returns results of polling the wait status
   * of a process/actor. It may return 0 if running, else pid or -1 
   */

  enum stop_code {
    STOP_ERROR = 0,
    STOP_NONE = 1,
    STOP_UNKNOWN = 2,
    STOP_BREAK = 3,
    STOP_STEP = 4,
    STOP_SIGNAL = 5,
    STOP_TERM_EXIT = 6,
    STOP_TERM_SIG = 7,
    STOP_DETACHED = 8,
    STOP_KILLED = 9,
    STOP_SPAWN_FAILED = 10,
  };
  typedef enum stop_code stop_code;

  struct wait_in {
    int pid;
  };
  typedef struct wait_in wait_in;

  struct wait_out {
    int wait_return;
    int errNo;
    int status;
    stop_code reason;
    int handle;
    u_long PC;
    u_long SP;
    u_long FP;
    u_long thread;
  };
  typedef struct wait_out wait_out;
  /*
   * now ptrace() routine. This matches the Sun UNIX ptrace as well as
   * some additions 
   */
#define PTRFLG_FORCE 1
#define PTRFLG_NON_OWNER 2
#define PTRFLG_FREE 4
#define PTRDET_UNOWN 0x100

  struct ptrace_in {
    int pid;
    ptrace_addr_data_in addr;
    u_int data;
    u_int flags;
  };
  typedef struct ptrace_in ptrace_in;

  struct ptrace_out {
    ptrace_addr_data_out addr;
    int result;
    int errNo;
  };
  typedef struct ptrace_out ptrace_out;

  struct one_symbol {
    char *symbolName;
    long symbolValue;
  };
  typedef struct one_symbol one_symbol;

  typedef struct {
    u_int all_symbols_len;
    one_symbol *all_symbols_val;
  } all_symbols;

  struct get_global_symbols_out {
    all_symbols symbols;
  };
  typedef struct get_global_symbols_out get_global_symbols_out;

  struct get_text_data_in {
    int pid;
    char *actorName;
  };
  typedef struct get_text_data_in get_text_data_in;

  struct get_text_data_out {
    int result;
    int errNo;
    u_long textStart;
    u_long textSize;
    u_long dataStart;
    u_long dataSize;
  };
  typedef struct get_text_data_out get_text_data_out;

  struct one_signal {
    u_int number;
    char *name;
  };
  typedef struct one_signal one_signal;

  typedef struct {
    u_int all_signals_len;
    one_signal *all_signals_val;
  } all_signals;

  struct get_signal_names_out {
    all_signals signals;
  };
  typedef struct get_signal_names_out get_signal_names_out;
  /*
   * now define the actual calls we support 
   */
#define REMDEB_H
#endif

#define REMOTEDEB 0x20000fff
#define REMOTEVERS 2

#if defined(__STDC__) || defined(__cplusplus)
#define OPEN_CONNEX 1
  extern open_out *open_connex_2 (open_in *, CLIENT *);
  extern open_out *open_connex_2_svc (open_in *, struct svc_req *);
#define SEND_SIGNAL 2
  extern signal_out *send_signal_2 (signal_in *, CLIENT *);
  extern signal_out *send_signal_2_svc (signal_in *, struct svc_req *);
#define CLOSE_CONNEX 10
  extern void *close_connex_2 (close_in *, CLIENT *);
  extern void *close_connex_2_svc (close_in *, struct svc_req *);
#define PTRACE 11
  extern ptrace_out *ptrace_2 (ptrace_in *, CLIENT *);
  extern ptrace_out *ptrace_2_svc (ptrace_in *, struct svc_req *);
#define WAIT_INFO 13
  extern wait_out *wait_info_2 (wait_in *, CLIENT *);
  extern wait_out *wait_info_2_svc (wait_in *, struct svc_req *);
#define GET_SIGNAL_NAMES 17
  extern get_signal_names_out *get_signal_names_2 (void *, CLIENT *);
  extern get_signal_names_out *get_signal_names_2_svc (void *,
                                                       struct svc_req *);
  extern int remotedeb_2_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else                           /* K&R C */
#define OPEN_CONNEX 1
  extern open_out *open_connex_2 ();
  extern open_out *open_connex_2_svc ();
#define SEND_SIGNAL 2
  extern signal_out *send_signal_2 ();
  extern signal_out *send_signal_2_svc ();
#define CLOSE_CONNEX 10
  extern void *close_connex_2 ();
  extern void *close_connex_2_svc ();
#define PTRACE 11
  extern ptrace_out *ptrace_2 ();
  extern ptrace_out *ptrace_2_svc ();
#define WAIT_INFO 13
  extern wait_out *wait_info_2 ();
  extern wait_out *wait_info_2_svc ();
#define GET_SIGNAL_NAMES 17
  extern get_signal_names_out *get_signal_names_2 ();
  extern get_signal_names_out *get_signal_names_2_svc ();
  extern int remotedeb_2_freeresult ();
#endif                          /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
  extern bool_t xdr_rpc_type (XDR *, rpc_type *);
  extern bool_t xdr_UDP_MSG (XDR *, UDP_MSG *);
  extern bool_t xdr_ptracereq (XDR *, ptracereq *);
  extern bool_t xdr_xdr_regs (XDR *, xdr_regs *);
  extern bool_t xdr_xdr_mem (XDR *, xdr_mem *);
  extern bool_t xdr_break_type (XDR *, break_type *);
  extern bool_t xdr_xdr_break (XDR *, xdr_break *);
  extern bool_t xdr_thread_name (XDR *, thread_name *);
  extern bool_t xdr_KernThread (XDR *, KernThread *);
  extern bool_t xdr_thread_list (XDR *, thread_list *);
  extern bool_t xdr_ptrace_addr_data_in (XDR *, ptrace_addr_data_in *);
  extern bool_t xdr_ptrace_addr_data_out (XDR *, ptrace_addr_data_out *);
  extern bool_t xdr_CHAR_DATA (XDR *, CHAR_DATA *);
  extern bool_t xdr_xry_inst (XDR *, xry_inst *);
  extern bool_t xdr_instance (XDR *, instance *);
  extern bool_t xdr_instance_union (XDR *, instance_union *);
  extern bool_t xdr_one_arg (XDR *, one_arg *);
  extern bool_t xdr_debug_type (XDR *, debug_type *);
  extern bool_t xdr_open_in (XDR *, open_in *);
  extern bool_t xdr_open_out (XDR *, open_out *);
  extern bool_t xdr_close_control (XDR *, close_control *);
  extern bool_t xdr_close_in (XDR *, close_in *);
  extern bool_t xdr_signal_in (XDR *, signal_in *);
  extern bool_t xdr_signal_out (XDR *, signal_out *);
  extern bool_t xdr_stop_code (XDR *, stop_code *);
  extern bool_t xdr_wait_in (XDR *, wait_in *);
  extern bool_t xdr_wait_out (XDR *, wait_out *);
  extern bool_t xdr_ptrace_in (XDR *, ptrace_in *);
  extern bool_t xdr_ptrace_out (XDR *, ptrace_out *);
  extern bool_t xdr_one_symbol (XDR *, one_symbol *);
  extern bool_t xdr_all_symbols (XDR *, all_symbols *);
  extern bool_t xdr_get_global_symbols_out (XDR *, get_global_symbols_out *);
  extern bool_t xdr_get_text_data_in (XDR *, get_text_data_in *);
  extern bool_t xdr_get_text_data_out (XDR *, get_text_data_out *);
  extern bool_t xdr_one_signal (XDR *, one_signal *);
  extern bool_t xdr_all_signals (XDR *, all_signals *);
  extern bool_t xdr_get_signal_names_out (XDR *, get_signal_names_out *);

#else                           /* K&R C */
  extern bool_t xdr_rpc_type ();
  extern bool_t xdr_UDP_MSG ();
  extern bool_t xdr_ptracereq ();
  extern bool_t xdr_xdr_regs ();
  extern bool_t xdr_xdr_mem ();
  extern bool_t xdr_break_type ();
  extern bool_t xdr_xdr_break ();
  extern bool_t xdr_thread_name ();
  extern bool_t xdr_KernThread ();
  extern bool_t xdr_thread_list ();
  extern bool_t xdr_ptrace_addr_data_in ();
  extern bool_t xdr_ptrace_addr_data_out ();
  extern bool_t xdr_CHAR_DATA ();
  extern bool_t xdr_xry_inst ();
  extern bool_t xdr_instance ();
  extern bool_t xdr_instance_union ();
  extern bool_t xdr_one_arg ();
  extern bool_t xdr_debug_type ();
  extern bool_t xdr_open_in ();
  extern bool_t xdr_open_out ();
  extern bool_t xdr_close_control ();
  extern bool_t xdr_close_in ();
  extern bool_t xdr_signal_in ();
  extern bool_t xdr_signal_out ();
  extern bool_t xdr_stop_code ();
  extern bool_t xdr_wait_in ();
  extern bool_t xdr_wait_out ();
  extern bool_t xdr_ptrace_in ();
  extern bool_t xdr_ptrace_out ();
  extern bool_t xdr_one_symbol ();
  extern bool_t xdr_all_symbols ();
  extern bool_t xdr_get_global_symbols_out ();
  extern bool_t xdr_get_text_data_in ();
  extern bool_t xdr_get_text_data_out ();
  extern bool_t xdr_one_signal ();
  extern bool_t xdr_all_signals ();
  extern bool_t xdr_get_signal_names_out ();

#endif                          /* K&R C */

#ifdef __cplusplus
}
#endif
#endif                          /* !_REMDEB_H_RPCGEN */
