/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "remdeb.h"
#define RTEMS_PORT 2071
#define RTEMS_BACK_PORT 2073

bool_t
xdr_rpc_type (XDR * xdrs, rpc_type * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_UDP_MSG (XDR * xdrs, UDP_MSG * objp)
{
  register int32_t *buf;

  if (!xdr_u_char (xdrs, &objp->type))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->msg_num))
    return FALSE;
  if (!xdr_u_short (xdrs, &objp->spec))
    return FALSE;
  if (!xdr_long (xdrs, &objp->pid))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->context))
    return FALSE;
  return TRUE;
}

/*
 * Sun request values for the remote ptrace system call
 */

bool_t
xdr_ptracereq (XDR * xdrs, ptracereq * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_xdr_regs (XDR * xdrs, xdr_regs * objp)
{
  register int32_t *buf;

  int i;

  if (xdrs->x_op == XDR_ENCODE) {
    buf = XDR_INLINE (xdrs, (3 + 8 + 8) * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_vector (xdrs, (char *) objp->r_dreg, 8,
                       sizeof (int), (xdrproc_t) xdr_int))
        return FALSE;
      if (!xdr_vector (xdrs, (char *) objp->r_areg, 8,
                       sizeof (int), (xdrproc_t) xdr_int))
        return FALSE;
      if (!xdr_int (xdrs, &objp->r_sr))
        return FALSE;
      if (!xdr_int (xdrs, &objp->r_pc))
        return FALSE;
      if (!xdr_int (xdrs, &objp->r_vec))
        return FALSE;
    } else {
      {
        register int *genp;

        for (i = 0, genp = objp->r_dreg; i < 8; ++i) {
          IXDR_PUT_LONG (buf, *genp++);
        }
      }
      {
        register int *genp;

        for (i = 0, genp = objp->r_areg; i < 8; ++i) {
          IXDR_PUT_LONG (buf, *genp++);
        }
      }
      IXDR_PUT_LONG (buf, objp->r_sr);
      IXDR_PUT_LONG (buf, objp->r_pc);
      IXDR_PUT_LONG (buf, objp->r_vec);
    }
    return TRUE;
  } else if (xdrs->x_op == XDR_DECODE) {
    buf = XDR_INLINE (xdrs, (3 + 8 + 8) * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_vector (xdrs, (char *) objp->r_dreg, 8,
                       sizeof (int), (xdrproc_t) xdr_int))
        return FALSE;
      if (!xdr_vector (xdrs, (char *) objp->r_areg, 8,
                       sizeof (int), (xdrproc_t) xdr_int))
        return FALSE;
      if (!xdr_int (xdrs, &objp->r_sr))
        return FALSE;
      if (!xdr_int (xdrs, &objp->r_pc))
        return FALSE;
      if (!xdr_int (xdrs, &objp->r_vec))
        return FALSE;
    } else {
      {
        register int *genp;

        for (i = 0, genp = objp->r_dreg; i < 8; ++i) {
          *genp++ = IXDR_GET_LONG (buf);
        }
      }
      {
        register int *genp;

        for (i = 0, genp = objp->r_areg; i < 8; ++i) {
          *genp++ = IXDR_GET_LONG (buf);
        }
      }
      objp->r_sr = IXDR_GET_LONG (buf);
      objp->r_pc = IXDR_GET_LONG (buf);
      objp->r_vec = IXDR_GET_LONG (buf);
    }
    return TRUE;
  }

  if (!xdr_vector (xdrs, (char *) objp->r_dreg, 8,
                   sizeof (int), (xdrproc_t) xdr_int))
    return FALSE;
  if (!xdr_vector (xdrs, (char *) objp->r_areg, 8,
                   sizeof (int), (xdrproc_t) xdr_int))
    return FALSE;
  if (!xdr_int (xdrs, &objp->r_sr))
    return FALSE;
  if (!xdr_int (xdrs, &objp->r_pc))
    return FALSE;
  if (!xdr_int (xdrs, &objp->r_vec))
    return FALSE;
  return TRUE;
}

  /*
   * Memory data for read/write text or data. The size is in data. The target
   * addr is in the addr field.
   * Be careful before modifying because this value goes into internal
   * pipes and is allocated on stack too. Pipes and/or the stack could
   * become too small if this value gets incremented.
   */
bool_t
xdr_xdr_mem (xdrs, objp)
     XDR *xdrs;
     struct xdr_mem *objp;
{
  if (!xdr_u_long (xdrs, &objp->addr)) {
    return (FALSE);
  }
  if (!xdr_u_int (xdrs, &objp->dataNb)) {
    return (FALSE);
  }
  return (xdr_opaque (xdrs, objp->data, objp->dataNb));
}

bool_t
xdr_break_type (XDR * xdrs, break_type * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_xdr_break (XDR * xdrs, xdr_break * objp)
{
  register int32_t *buf;

  int i;

  if (xdrs->x_op == XDR_ENCODE) {
    if (!xdr_u_char (xdrs, &objp->type))
      return FALSE;
    if (!xdr_u_char (xdrs, &objp->thread_spec))
      return FALSE;
    buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_u_short (xdrs, &objp->handle))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->ee_loc))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->ee_type))
        return FALSE;
      if (!xdr_u_short (xdrs, &objp->length))
        return FALSE;

    } else {
      IXDR_PUT_U_SHORT (buf, objp->handle);
      IXDR_PUT_U_LONG (buf, objp->ee_loc);
      IXDR_PUT_U_LONG (buf, objp->ee_type);
      IXDR_PUT_U_SHORT (buf, objp->length);
    }
    if (!xdr_u_char (xdrs, &objp->pass_count))
      return FALSE;
    if (!xdr_u_char (xdrs, &objp->curr_pass))
      return FALSE;
    buf = XDR_INLINE (xdrs, MAX_THRD_BRK * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_vector (xdrs, (char *) objp->thread_list, MAX_THRD_BRK,
                       sizeof (u_long), (xdrproc_t) xdr_u_long))
        return FALSE;
    } else {
      {
        register u_long *genp;

        for (i = 0, genp = objp->thread_list; i < MAX_THRD_BRK; ++i) {
          IXDR_PUT_U_LONG (buf, *genp++);
        }
      }
    }
    return TRUE;
  } else if (xdrs->x_op == XDR_DECODE) {
    if (!xdr_u_char (xdrs, &objp->type))
      return FALSE;
    if (!xdr_u_char (xdrs, &objp->thread_spec))
      return FALSE;
    buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_u_short (xdrs, &objp->handle))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->ee_loc))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->ee_type))
        return FALSE;
      if (!xdr_u_short (xdrs, &objp->length))
        return FALSE;

    } else {
      objp->handle = IXDR_GET_U_SHORT (buf);
      objp->ee_loc = IXDR_GET_U_LONG (buf);
      objp->ee_type = IXDR_GET_U_LONG (buf);
      objp->length = IXDR_GET_U_SHORT (buf);
    }
    if (!xdr_u_char (xdrs, &objp->pass_count))
      return FALSE;
    if (!xdr_u_char (xdrs, &objp->curr_pass))
      return FALSE;
    buf = XDR_INLINE (xdrs, MAX_THRD_BRK * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_vector (xdrs, (char *) objp->thread_list, MAX_THRD_BRK,
                       sizeof (u_long), (xdrproc_t) xdr_u_long))
        return FALSE;
    } else {
      {
        register u_long *genp;

        for (i = 0, genp = objp->thread_list; i < MAX_THRD_BRK; ++i) {
          *genp++ = IXDR_GET_U_LONG (buf);
        }
      }
    }
    return TRUE;
  }

  if (!xdr_u_char (xdrs, &objp->type))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->thread_spec))
    return FALSE;
  if (!xdr_u_short (xdrs, &objp->handle))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->ee_loc))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->ee_type))
    return FALSE;
  if (!xdr_u_short (xdrs, &objp->length))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->pass_count))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->curr_pass))
    return FALSE;
  if (!xdr_vector (xdrs, (char *) objp->thread_list, MAX_THRD_BRK,
                   sizeof (u_long), (xdrproc_t) xdr_u_long))
    return FALSE;
  return TRUE;
}

bool_t
xdr_thread_name (XDR * xdrs, thread_name * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, objp, THREADNAMEMAX))
    return FALSE;
  return TRUE;
}

bool_t
xdr_KernThread (XDR * xdrs, KernThread * objp)
{
  register int32_t *buf;

  if (!xdr_u_int (xdrs, &objp->threadLi))
    return FALSE;
  return TRUE;
}

bool_t
xdr_thread_list (xdrs, objp)
     XDR *xdrs;
     struct thread_list *objp;
{
  return (xdr_array (xdrs, (char **) &objp->threads, &objp->nbThread,
                     UTHREAD_MAX, sizeof (KernThread), xdr_KernThread));
}

bool_t
xdr_ptrace_addr_data_in (XDR * xdrs, ptrace_addr_data_in * objp)
{
  register int32_t *buf;

  if (!xdr_ptracereq (xdrs, &objp->req))
    return FALSE;
  switch (objp->req) {
  case RPT_SETTHREADREGS:
    if (!xdr_xdr_regs (xdrs, &objp->ptrace_addr_data_in_u.regs))
      return FALSE;
    break;
  case RPT_SETREGS:
    if (!xdr_xdr_regs (xdrs, &objp->ptrace_addr_data_in_u.regs))
      return FALSE;
    break;
  case RPT_PSETTHREADREGS:
    if (!xdr_array
        (xdrs, (char **) &objp->ptrace_addr_data_in_u.pregs.pregs_val,
         (u_int *) & objp->ptrace_addr_data_in_u.pregs.pregs_len, ~0,
         sizeof (u_int), (xdrproc_t) xdr_u_int))
      return FALSE;
    break;
  case RPT_PSETREGS:
    if (!xdr_array
        (xdrs, (char **) &objp->ptrace_addr_data_in_u.pregs.pregs_val,
         (u_int *) & objp->ptrace_addr_data_in_u.pregs.pregs_len, ~0,
         sizeof (u_int), (xdrproc_t) xdr_u_int))
      return FALSE;
    break;
  case RPT_SETTHREADNAME:
    if (!xdr_thread_name (xdrs, &objp->ptrace_addr_data_in_u.name))
      return FALSE;
    break;
  case RPT_WRITETEXT:
    if (!xdr_xdr_mem (xdrs, &objp->ptrace_addr_data_in_u.mem))
      return FALSE;
    break;
  case RPT_WRITEDATA:
    if (!xdr_xdr_mem (xdrs, &objp->ptrace_addr_data_in_u.mem))
      return FALSE;
    break;
  case RPT_SETBREAK:
    if (!xdr_xdr_break (xdrs, &objp->ptrace_addr_data_in_u.breakp))
      return FALSE;
    break;
  default:
    if (!xdr_u_int (xdrs, &objp->ptrace_addr_data_in_u.address))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_ptrace_addr_data_out (XDR * xdrs, ptrace_addr_data_out * objp)
{
  register int32_t *buf;

  if (!xdr_ptracereq (xdrs, &objp->req))
    return FALSE;
  switch (objp->req) {
  case RPT_GETREGS:
    if (!xdr_xdr_regs (xdrs, &objp->ptrace_addr_data_out_u.regs))
      return FALSE;
    break;
  case RPT_GETTHREADREGS:
    if (!xdr_xdr_regs (xdrs, &objp->ptrace_addr_data_out_u.regs))
      return FALSE;
    break;
  case RPT_PGETREGS:
    if (!xdr_array
        (xdrs, (char **) &objp->ptrace_addr_data_out_u.pregs.pregs_val,
         (u_int *) & objp->ptrace_addr_data_out_u.pregs.pregs_len, ~0,
         sizeof (u_int), (xdrproc_t) xdr_u_int))
      return FALSE;
    break;
  case RPT_PGETTHREADREGS:
    if (!xdr_array
        (xdrs, (char **) &objp->ptrace_addr_data_out_u.pregs.pregs_val,
         (u_int *) & objp->ptrace_addr_data_out_u.pregs.pregs_len, ~0,
         sizeof (u_int), (xdrproc_t) xdr_u_int))
      return FALSE;
    break;
  case RPT_THREADLIST:
    if (!xdr_thread_list (xdrs, &objp->ptrace_addr_data_out_u.threads))
      return FALSE;
    break;
  case RPT_GETTHREADNAME:
    if (!xdr_thread_name (xdrs, &objp->ptrace_addr_data_out_u.name))
      return FALSE;
    break;
  case RPT_READTEXT:
    if (!xdr_xdr_mem (xdrs, &objp->ptrace_addr_data_out_u.mem))
      return FALSE;
    break;
  case RPT_GETNAME:
    if (!xdr_xdr_mem (xdrs, &objp->ptrace_addr_data_out_u.mem))
      return FALSE;
    break;
  case RPT_READDATA:
    if (!xdr_xdr_mem (xdrs, &objp->ptrace_addr_data_out_u.mem))
      return FALSE;
    break;
  case RPT_GETBREAK:
    if (!xdr_xdr_break (xdrs, &objp->ptrace_addr_data_out_u.breakp))
      return FALSE;
    break;
  default:
    if (!xdr_u_int (xdrs, &objp->ptrace_addr_data_out_u.addr))
      return FALSE;
    break;
  }
  return TRUE;
}

bool_t
xdr_CHAR_DATA (XDR * xdrs, CHAR_DATA * objp)
{
  register int32_t *buf;

  if (!xdr_bytes
      (xdrs, (char **) &objp->CHAR_DATA_val, (u_int *) & objp->CHAR_DATA_len,
       NET_SAFE))
    return FALSE;
  return TRUE;
}

#ifndef XRY_MAX_CMD_STR
#endif /* REMDEB_H */

bool_t
xdr_xry_inst (XDR * xdrs, xry_inst * objp)
{
  register int32_t *buf;

  if (!xdr_u_char (xdrs, &objp->flags))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->type))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->sub_type))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->res_type))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->value))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->value2))
    return FALSE;
  return TRUE;
}

bool_t
xdr_instance (XDR * xdrs, instance * objp)
{
  register int32_t *buf;

  int i;
  if (!xdr_vector (xdrs, (char *) objp->instances, XRY_MAX_INSTANCES,
                   sizeof (xry_inst), (xdrproc_t) xdr_xry_inst))
    return FALSE;
  if (!xdr_vector (xdrs, (char *) objp->buffer, XRY_MAX_INST_BUFF,
                   sizeof (u_char), (xdrproc_t) xdr_u_char))
    return FALSE;
  return TRUE;
}

bool_t
xdr_instance_union (XDR * xdrs, instance_union * objp)
{
  register int32_t *buf;

  if (!xdr_bool (xdrs, &objp->instances))
    return FALSE;
  switch (objp->instances) {
  case TRUE:
    if (!xdr_instance (xdrs, &objp->instance_union_u.inst))
      return FALSE;
    break;
  case FALSE:
    if (!xdr_string (xdrs, &objp->instance_union_u.buffer, XRY_MAX_CMD_STR))
      return FALSE;
    break;
  default:
    return FALSE;
  }
  return TRUE;
}

bool_t
xdr_one_arg (XDR * xdrs, one_arg * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, objp, NET_SAFE))
    return FALSE;
  return TRUE;
}

  /*
   * now open_connex() routine which establishes a connection to server 
   */

bool_t
xdr_debug_type (XDR * xdrs, debug_type * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

#define DEBUGGER_IS_GDB 0x2     /* */

bool_t
xdr_open_in (XDR * xdrs, open_in * objp)
{
  register int32_t *buf;

  int i;
  if (!xdr_vector (xdrs, (char *) objp->back_port, 16,
                   sizeof (u_char), (xdrproc_t) xdr_u_char))
    return FALSE;
  if (!xdr_u_short (xdrs, &objp->debug_type))
    return FALSE;
  if (!xdr_u_short (xdrs, &objp->flags))
    return FALSE;
  if (!xdr_vector (xdrs, (char *) objp->destination, 16,
                   sizeof (u_char), (xdrproc_t) xdr_u_char))
    return FALSE;
  if (!xdr_one_arg (xdrs, &objp->user_name))
    return FALSE;
  return TRUE;
}

bool_t
xdr_open_out (XDR * xdrs, open_out * objp)
{
  register int32_t *buf;

  int i;

  if (xdrs->x_op == XDR_ENCODE) {
    buf = XDR_INLINE (xdrs, (2 + (4)) * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_u_long (xdrs, &objp->port))
        return FALSE;
      if (!xdr_vector (xdrs, (char *) objp->pad, 4,
                       sizeof (u_int), (xdrproc_t) xdr_u_int))
        return FALSE;
      if (!xdr_u_int (xdrs, &objp->fp))
        return FALSE;

    } else {
      IXDR_PUT_U_LONG (buf, objp->port);
      {
        register u_int *genp;

        for (i = 0, genp = objp->pad; i < 4; ++i) {
          IXDR_PUT_U_LONG (buf, *genp++);
        }
      }
      IXDR_PUT_U_LONG (buf, objp->fp);
    }
    if (!xdr_u_char (xdrs, &objp->cmd_table_num))
      return FALSE;
    if (!xdr_u_char (xdrs, &objp->cmd_table_vers))
      return FALSE;
    if (!xdr_u_short (xdrs, &objp->server_vers))
      return FALSE;
    return TRUE;
  } else if (xdrs->x_op == XDR_DECODE) {
    buf = XDR_INLINE (xdrs, (2 + (4)) * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_u_long (xdrs, &objp->port))
        return FALSE;
      if (!xdr_vector (xdrs, (char *) objp->pad, 4,
                       sizeof (u_int), (xdrproc_t) xdr_u_int))
        return FALSE;
      if (!xdr_u_int (xdrs, &objp->fp))
        return FALSE;

    } else {
      objp->port = IXDR_GET_U_LONG (buf);
      {
        register u_int *genp;

        for (i = 0, genp = objp->pad; i < 4; ++i) {
          *genp++ = IXDR_GET_U_LONG (buf);
        }
      }
      objp->fp = IXDR_GET_U_LONG (buf);
    }
    if (!xdr_u_char (xdrs, &objp->cmd_table_num))
      return FALSE;
    if (!xdr_u_char (xdrs, &objp->cmd_table_vers))
      return FALSE;
    if (!xdr_u_short (xdrs, &objp->server_vers))
      return FALSE;
    return TRUE;
  }

  if (!xdr_u_long (xdrs, &objp->port))
    return FALSE;
  if (!xdr_vector (xdrs, (char *) objp->pad, 4,
                   sizeof (u_int), (xdrproc_t) xdr_u_int))
    return FALSE;
  if (!xdr_u_int (xdrs, &objp->fp))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->cmd_table_num))
    return FALSE;
  if (!xdr_u_char (xdrs, &objp->cmd_table_vers))
    return FALSE;
  if (!xdr_u_short (xdrs, &objp->server_vers))
    return FALSE;
  return TRUE;
}

  /*
   * now close_connex() routine which detaches from server 
   */

bool_t
xdr_close_control (XDR * xdrs, close_control * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_close_in (XDR * xdrs, close_in * objp)
{
  register int32_t *buf;

  if (!xdr_close_control (xdrs, &objp->control))
    return FALSE;
  return TRUE;
}

  /*
   * now send_signal() routine which sends signals to processes like kill(2) 
   */

bool_t
xdr_signal_in (XDR * xdrs, signal_in * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->pid))
    return FALSE;
  if (!xdr_int (xdrs, &objp->sig))
    return FALSE;
  return TRUE;
}

bool_t
xdr_signal_out (XDR * xdrs, signal_out * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->kill_return))
    return FALSE;
  if (!xdr_int (xdrs, &objp->errNo))
    return FALSE;
  return TRUE;
}

  /*
   * now wait_info() routine which returns results of polling the wait status
   * of a process/actor. It may return 0 if running, else pid or -1 
   */

bool_t
xdr_stop_code (XDR * xdrs, stop_code * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_wait_in (XDR * xdrs, wait_in * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->pid))
    return FALSE;
  return TRUE;
}

bool_t
xdr_wait_out (XDR * xdrs, wait_out * objp)
{
  register int32_t *buf;

  if (xdrs->x_op == XDR_ENCODE) {
    buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_int (xdrs, &objp->wait_return))
        return FALSE;
      if (!xdr_int (xdrs, &objp->errNo))
        return FALSE;
      if (!xdr_int (xdrs, &objp->status))
        return FALSE;

    } else {
      IXDR_PUT_LONG (buf, objp->wait_return);
      IXDR_PUT_LONG (buf, objp->errNo);
      IXDR_PUT_LONG (buf, objp->status);
    }
    if (!xdr_stop_code (xdrs, &objp->reason))
      return FALSE;
    buf = XDR_INLINE (xdrs, 5 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_int (xdrs, &objp->handle))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->PC))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->SP))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->FP))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->thread))
        return FALSE;
    } else {
      IXDR_PUT_LONG (buf, objp->handle);
      IXDR_PUT_U_LONG (buf, objp->PC);
      IXDR_PUT_U_LONG (buf, objp->SP);
      IXDR_PUT_U_LONG (buf, objp->FP);
      IXDR_PUT_U_LONG (buf, objp->thread);
    }
    return TRUE;
  } else if (xdrs->x_op == XDR_DECODE) {
    buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_int (xdrs, &objp->wait_return))
        return FALSE;
      if (!xdr_int (xdrs, &objp->errNo))
        return FALSE;
      if (!xdr_int (xdrs, &objp->status))
        return FALSE;

    } else {
      objp->wait_return = IXDR_GET_LONG (buf);
      objp->errNo = IXDR_GET_LONG (buf);
      objp->status = IXDR_GET_LONG (buf);
    }
    if (!xdr_stop_code (xdrs, &objp->reason))
      return FALSE;
    buf = XDR_INLINE (xdrs, 5 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_int (xdrs, &objp->handle))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->PC))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->SP))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->FP))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->thread))
        return FALSE;
    } else {
      objp->handle = IXDR_GET_LONG (buf);
      objp->PC = IXDR_GET_U_LONG (buf);
      objp->SP = IXDR_GET_U_LONG (buf);
      objp->FP = IXDR_GET_U_LONG (buf);
      objp->thread = IXDR_GET_U_LONG (buf);
    }
    return TRUE;
  }

  if (!xdr_int (xdrs, &objp->wait_return))
    return FALSE;
  if (!xdr_int (xdrs, &objp->errNo))
    return FALSE;
  if (!xdr_int (xdrs, &objp->status))
    return FALSE;
  if (!xdr_stop_code (xdrs, &objp->reason))
    return FALSE;
  if (!xdr_int (xdrs, &objp->handle))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->PC))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->SP))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->FP))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->thread))
    return FALSE;
  return TRUE;
}

  /*
   * now ptrace() routine. This matches the Sun UNIX ptrace as well as
   * some additions 
   */

bool_t
xdr_ptrace_in (XDR * xdrs, ptrace_in * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->pid))
    return FALSE;
  if (!xdr_ptrace_addr_data_in (xdrs, &objp->addr))
    return FALSE;
  if (!xdr_u_int (xdrs, &objp->data))
    return FALSE;
  if (!xdr_u_int (xdrs, &objp->flags))
    return FALSE;
  return TRUE;
}

bool_t
xdr_ptrace_out (XDR * xdrs, ptrace_out * objp)
{
  register int32_t *buf;

  if (!xdr_ptrace_addr_data_out (xdrs, &objp->addr))
    return FALSE;
  if (!xdr_int (xdrs, &objp->result))
    return FALSE;
  if (!xdr_int (xdrs, &objp->errNo))
    return FALSE;
  return TRUE;
}

bool_t
xdr_one_symbol (XDR * xdrs, one_symbol * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->symbolName, ~0))
    return FALSE;
  if (!xdr_long (xdrs, &objp->symbolValue))
    return FALSE;
  return TRUE;
}

bool_t
xdr_all_symbols (XDR * xdrs, all_symbols * objp)
{
  register int32_t *buf;

  if (!xdr_array
      (xdrs, (char **) &objp->all_symbols_val,
       (u_int *) & objp->all_symbols_len, ~0, sizeof (one_symbol),
       (xdrproc_t) xdr_one_symbol))
    return FALSE;
  return TRUE;
}

bool_t
xdr_get_global_symbols_out (XDR * xdrs, get_global_symbols_out * objp)
{
  register int32_t *buf;

  if (!xdr_all_symbols (xdrs, &objp->symbols))
    return FALSE;
  return TRUE;
}

bool_t
xdr_get_text_data_in (XDR * xdrs, get_text_data_in * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->pid))
    return FALSE;
  if (!xdr_string (xdrs, &objp->actorName, 16))
    return FALSE;
  return TRUE;
}

bool_t
xdr_get_text_data_out (XDR * xdrs, get_text_data_out * objp)
{
  register int32_t *buf;

  if (xdrs->x_op == XDR_ENCODE) {
    buf = XDR_INLINE (xdrs, 6 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_int (xdrs, &objp->result))
        return FALSE;
      if (!xdr_int (xdrs, &objp->errNo))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->textStart))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->textSize))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->dataStart))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->dataSize))
        return FALSE;
    } else {
      IXDR_PUT_LONG (buf, objp->result);
      IXDR_PUT_LONG (buf, objp->errNo);
      IXDR_PUT_U_LONG (buf, objp->textStart);
      IXDR_PUT_U_LONG (buf, objp->textSize);
      IXDR_PUT_U_LONG (buf, objp->dataStart);
      IXDR_PUT_U_LONG (buf, objp->dataSize);
    }
    return TRUE;
  } else if (xdrs->x_op == XDR_DECODE) {
    buf = XDR_INLINE (xdrs, 6 * BYTES_PER_XDR_UNIT);
    if (buf == NULL) {
      if (!xdr_int (xdrs, &objp->result))
        return FALSE;
      if (!xdr_int (xdrs, &objp->errNo))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->textStart))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->textSize))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->dataStart))
        return FALSE;
      if (!xdr_u_long (xdrs, &objp->dataSize))
        return FALSE;
    } else {
      objp->result = IXDR_GET_LONG (buf);
      objp->errNo = IXDR_GET_LONG (buf);
      objp->textStart = IXDR_GET_U_LONG (buf);
      objp->textSize = IXDR_GET_U_LONG (buf);
      objp->dataStart = IXDR_GET_U_LONG (buf);
      objp->dataSize = IXDR_GET_U_LONG (buf);
    }
    return TRUE;
  }

  if (!xdr_int (xdrs, &objp->result))
    return FALSE;
  if (!xdr_int (xdrs, &objp->errNo))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->textStart))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->textSize))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->dataStart))
    return FALSE;
  if (!xdr_u_long (xdrs, &objp->dataSize))
    return FALSE;
  return TRUE;
}

bool_t
xdr_one_signal (XDR * xdrs, one_signal * objp)
{
  register int32_t *buf;

  if (!xdr_u_int (xdrs, &objp->number))
    return FALSE;
  if (!xdr_string (xdrs, &objp->name, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_all_signals (XDR * xdrs, all_signals * objp)
{
  register int32_t *buf;

  if (!xdr_array
      (xdrs, (char **) &objp->all_signals_val,
       (u_int *) & objp->all_signals_len, ~0, sizeof (one_signal),
       (xdrproc_t) xdr_one_signal))
    return FALSE;
  return TRUE;
}

bool_t
xdr_get_signal_names_out (XDR * xdrs, get_signal_names_out * objp)
{
  register int32_t *buf;

  if (!xdr_all_signals (xdrs, &objp->signals))
    return FALSE;
  return TRUE;
}

  /*
   * now define the actual calls we support 
   */
