
ulong ERR_peek_error_line(char **file,int *line)

{
  ERR_STATE *pEVar1;
  ulong uVar2;
  uint uVar3;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom != pEVar1->top) {
    uVar3 = pEVar1->bottom + 1U & 0x8000000f;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff0) + 1;
    }
    uVar2 = pEVar1->err_buffer[uVar3];
    if ((file != (char **)0x0) && (line != (int *)0x0)) {
      if (pEVar1->err_file[uVar3] == (char *)0x0) {
        *file = "NA";
        *line = 0;
      }
      else {
        *file = pEVar1->err_file[uVar3];
        *line = pEVar1->err_line[uVar3];
      }
    }
    return uVar2;
  }
  return 0;
}

