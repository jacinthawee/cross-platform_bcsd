
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_set_mark(void)

{
  ERR_STATE *pEVar1;
  int iVar2;
  
  pEVar1 = ERR_get_state();
  iVar2 = pEVar1->top;
  if (pEVar1->bottom != iVar2) {
    pEVar1->err_flags[iVar2] = pEVar1->err_flags[iVar2] | 1;
    return 1;
  }
  return 0;
}

