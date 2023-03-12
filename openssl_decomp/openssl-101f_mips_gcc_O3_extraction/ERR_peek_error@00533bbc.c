
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong ERR_peek_error(void)

{
  ERR_STATE *pEVar1;
  uint uVar2;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom != pEVar1->top) {
    uVar2 = pEVar1->bottom + 1U & 0x8000000f;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff0) + 1;
    }
    return pEVar1->err_buffer[uVar2];
  }
  return 0;
}

