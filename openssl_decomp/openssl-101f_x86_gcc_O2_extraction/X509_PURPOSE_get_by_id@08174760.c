
int X509_PURPOSE_get_by_id(int id)

{
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  int local_2c [7];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = id - 1;
  if (8 < uVar2) {
    local_2c[0] = id;
    if (xptable != (_STACK *)0x0) {
      iVar1 = sk_find(xptable,local_2c);
      if (iVar1 != -1) {
        uVar2 = iVar1 + 9;
        goto LAB_081747a0;
      }
    }
    uVar2 = 0xffffffff;
  }
LAB_081747a0:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

