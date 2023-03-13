
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_set_mark(void)

{
  ERR_STATE *pEVar1;
  
  pEVar1 = ERR_get_state();
  if (pEVar1->bottom != pEVar1->top) {
    pEVar1->err_flags[pEVar1->top] = pEVar1->err_flags[pEVar1->top] | 1;
    return 1;
  }
  return 0;
}

