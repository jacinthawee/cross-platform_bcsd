
ulong ERR_peek_error_line_data(char **file,int *line,char **data,int *flags)

{
  ERR_STATE *pEVar1;
  ulong uVar2;
  char *pcVar3;
  int iVar4;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom == pEVar1->top) {
    uVar2 = 0;
  }
  else {
    iVar4 = (pEVar1->bottom + 1) % 0x10;
    uVar2 = pEVar1->err_buffer[iVar4];
    if (file != (char **)0x0 && line != (int *)0x0) {
      if (pEVar1->err_file[iVar4] == (char *)0x0) {
        *file = "NA";
        *line = 0;
      }
      else {
        *file = pEVar1->err_file[iVar4];
        *line = pEVar1->err_line[iVar4];
      }
    }
    if (data != (char **)0x0) {
      pcVar3 = pEVar1->err_data[iVar4];
      if (pcVar3 == (char *)0x0) {
        *data = "";
        if (flags != (int *)0x0) goto LAB_000a52e2;
      }
      else {
        *data = pcVar3;
        if (flags != (int *)0x0) {
          pcVar3 = (char *)pEVar1->err_data_flags[iVar4];
LAB_000a52e2:
          *flags = (int)pcVar3;
          return uVar2;
        }
      }
    }
  }
  return uVar2;
}

