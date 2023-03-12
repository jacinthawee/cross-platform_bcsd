
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong ERR_get_error(void)

{
  ulong uVar1;
  ERR_STATE *pEVar2;
  int iVar3;
  
  pEVar2 = ERR_get_state();
  if (pEVar2->bottom != pEVar2->top) {
    iVar3 = (pEVar2->bottom + 1) % 0x10;
    uVar1 = pEVar2->err_buffer[iVar3];
    pEVar2->bottom = iVar3;
    pEVar2->err_buffer[iVar3] = 0;
    if ((pEVar2->err_data[iVar3] != (char *)0x0) &&
       ((*(byte *)(pEVar2->err_data_flags + iVar3) & 1) != 0)) {
      CRYPTO_free(pEVar2->err_data[iVar3]);
      pEVar2->err_data[iVar3] = (char *)0x0;
    }
    pEVar2->err_data_flags[iVar3] = 0;
    return uVar1;
  }
  return 0;
}

