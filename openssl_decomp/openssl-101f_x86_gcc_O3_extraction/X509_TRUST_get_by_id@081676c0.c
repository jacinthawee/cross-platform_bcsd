
int X509_TRUST_get_by_id(int id)

{
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  int local_28 [6];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = id - 1;
  if (7 < uVar2) {
    local_28[0] = id;
    if (trtable != (_STACK *)0x0) {
      iVar1 = sk_find(trtable,local_28);
      if (iVar1 != -1) {
        uVar2 = iVar1 + 8;
        goto LAB_08167701;
      }
    }
    uVar2 = 0xffffffff;
  }
LAB_08167701:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

