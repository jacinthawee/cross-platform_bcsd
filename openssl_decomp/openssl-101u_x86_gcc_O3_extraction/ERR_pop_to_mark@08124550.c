
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_pop_to_mark(void)

{
  ERR_STATE *pEVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  pEVar1 = ERR_get_state();
  iVar3 = pEVar1->top;
  iVar4 = pEVar1->bottom;
  while( true ) {
    if (iVar4 == iVar3) {
      return 0;
    }
    if ((pEVar1->err_flags[iVar3] & 1U) != 0) break;
    pEVar1->err_flags[iVar3] = 0;
    pEVar1->err_buffer[iVar3] = 0;
    iVar2 = iVar3;
    if ((pEVar1->err_data[iVar3] != (char *)0x0) &&
       ((*(byte *)(pEVar1->err_data_flags + iVar3) & 1) != 0)) {
      CRYPTO_free(pEVar1->err_data[iVar3]);
      iVar2 = pEVar1->top;
      iVar4 = pEVar1->bottom;
      pEVar1->err_data[iVar2] = (char *)0x0;
    }
    iVar3 = iVar2 + -1;
    pEVar1->err_data_flags[iVar2] = 0;
    pEVar1->err_file[iVar2] = (char *)0x0;
    pEVar1->err_line[iVar2] = -1;
    pEVar1->top = iVar3;
    if (iVar3 == -1) {
      pEVar1->top = 0xf;
      iVar3 = 0xf;
    }
  }
  pEVar1->err_flags[iVar3] = pEVar1->err_flags[iVar3] & 0xfffffffe;
  return 1;
}

