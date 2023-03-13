
ulong ERR_peek_last_error_line(char **file,int *line)

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
    return uVar2;
  }
  return 0;
}

