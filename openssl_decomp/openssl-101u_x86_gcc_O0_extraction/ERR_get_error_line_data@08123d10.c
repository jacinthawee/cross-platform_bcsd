
ulong ERR_get_error_line_data(char **file,int *line,char **data,int *flags)

{
  ulong uVar1;
  char *ptr;
  ERR_STATE *pEVar2;
  int iVar3;
  
  pEVar2 = ERR_get_state();
  if (pEVar2->bottom != pEVar2->top) {
    iVar3 = (pEVar2->bottom + 1) % 0x10;
    uVar1 = pEVar2->err_buffer[iVar3];
    pEVar2->bottom = iVar3;
    pEVar2->err_buffer[iVar3] = 0;
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
    ptr = pEVar2->err_data[iVar3];
    if (data == (char **)0x0) {
      if ((ptr != (char *)0x0) && ((*(byte *)(pEVar2->err_data_flags + iVar3) & 1) != 0)) {
        CRYPTO_free(ptr);
        pEVar2->err_data[iVar3] = (char *)0x0;
      }
      pEVar2->err_data_flags[iVar3] = 0;
    }
    else if (ptr == (char *)0x0) {
      *data = "";
      if (flags != (int *)0x0) {
        *flags = 0;
      }
    }
    else {
      *data = ptr;
      if (flags != (int *)0x0) {
        *flags = pEVar2->err_data_flags[iVar3];
      }
    }
    return uVar1;
  }
  return 0;
}

