
ulong ERR_peek_error_line(char **file,int *line)

{
  ulong uVar1;
  ERR_STATE *pEVar2;
  int iVar3;
  
  pEVar2 = ERR_get_state();
  if (pEVar2->bottom != pEVar2->top) {
    iVar3 = (pEVar2->bottom + 1) % 0x10;
    uVar1 = pEVar2->err_buffer[iVar3];
    if ((file != (char **)0x0) && (line != (int *)0x0)) {
      if (pEVar2->err_file[iVar3] == (char *)0x0) {
        *file = "NA";
        *line = 0;
      }
      else {
        *file = pEVar2->err_file[iVar3];
        *line = pEVar2->err_line[iVar3];
      }
    }
    return uVar1;
  }
  return 0;
}

