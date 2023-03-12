
int X509_PURPOSE_set(int *p,int purpose)

{
  int iVar1;
  int in_GS_OFFSET;
  int local_2c [7];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (purpose - 1U < 9) {
LAB_081745d1:
    *p = purpose;
    iVar1 = 1;
  }
  else {
    local_2c[0] = purpose;
    if (xptable != (_STACK *)0x0) {
      iVar1 = sk_find(xptable,local_2c);
      if ((iVar1 != -1) && (iVar1 != -10)) goto LAB_081745d1;
    }
    ERR_put_error(0x22,0x8d,0x92,"v3_purp.c",0x80);
    iVar1 = 0;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

