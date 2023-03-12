
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ERR_set_mark(void)

{
  ERR_STATE *pEVar1;
  undefined *puVar2;
  int *piVar3;
  bool bVar4;
  
  pEVar1 = ERR_get_state();
  piVar3 = (int *)pEVar1->top;
  puVar2 = (undefined *)pEVar1->bottom;
  bVar4 = (int *)puVar2 != piVar3;
  if (bVar4) {
    piVar3 = pEVar1->err_flags + (int)((int)piVar3 + -2);
    puVar2 = (undefined *)(piVar3[2] | 1);
  }
  if (bVar4) {
    piVar3[2] = (int)puVar2;
  }
  return (uint)bVar4;
}

