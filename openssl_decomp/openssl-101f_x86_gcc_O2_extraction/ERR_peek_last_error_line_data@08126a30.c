
ulong ERR_peek_last_error_line_data(char **file,int *line,char **data,int *flags)

{
  int iVar1;
  ulong uVar2;
  ERR_STATE *pEVar3;
  
  pEVar3 = ERR_get_state();
  iVar1 = pEVar3->top;
  if (pEVar3->bottom != iVar1) {
    uVar2 = pEVar3->err_buffer[iVar1];
    if ((file != (char **)0x0) && (line != (int *)0x0)) {
      if (pEVar3->err_file[iVar1] == (char *)0x0) {
        *file = "NA";
        *line = 0;
      }
      else {
        *file = pEVar3->err_file[iVar1];
        *line = pEVar3->err_line[iVar1];
      }
    }
    if (data != (char **)0x0) {
      if (pEVar3->err_data[iVar1] == (char *)0x0) {
        *data = "";
        if (flags != (int *)0x0) {
          *flags = 0;
        }
      }
      else {
        *data = pEVar3->err_data[iVar1];
        if (flags != (int *)0x0) {
          *flags = pEVar3->err_data_flags[iVar1];
        }
      }
    }
    return uVar2;
  }
  return 0;
}

