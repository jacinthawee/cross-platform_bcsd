
ulong ERR_get_error_line(char **file,int *line)

{
  ERR_STATE *pEVar1;
  uint uVar2;
  ulong uVar3;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom == pEVar1->top) {
    return 0;
  }
  uVar2 = pEVar1->bottom + 1U & 0x8000000f;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff0) + 1;
  }
  uVar3 = pEVar1->err_buffer[uVar2];
  pEVar1->bottom = uVar2;
  pEVar1->err_buffer[uVar2] = 0;
  if ((file != (char **)0x0) && (line != (int *)0x0)) {
    if (pEVar1->err_file[uVar2] == (char *)0x0) {
      *file = "NA";
      *line = 0;
    }
    else {
      *file = pEVar1->err_file[uVar2];
      *line = pEVar1->err_line[uVar2];
    }
  }
  if ((pEVar1->err_data[uVar2] != (char *)0x0) && ((pEVar1->err_data_flags[uVar2] & 1U) != 0)) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    pEVar1->err_data[uVar2] = (char *)0x0;
  }
  pEVar1->err_data_flags[uVar2] = 0;
  return uVar3;
}

