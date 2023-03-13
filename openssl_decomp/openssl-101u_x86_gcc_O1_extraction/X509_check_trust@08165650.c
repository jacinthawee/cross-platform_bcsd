
int X509_check_trust(X509 *x,int id,int flags)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  int in_GS_OFFSET;
  int local_28 [6];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (id == -1) {
    iVar1 = 1;
  }
  else {
    uVar2 = id - 1;
    if (7 < uVar2) {
      local_28[0] = id;
      if (((trtable == (_STACK *)0x0) || (iVar1 = sk_find(trtable,local_28), iVar1 == -1)) ||
         (uVar2 = iVar1 + 8, uVar2 == 0xffffffff)) {
        iVar1 = (*(code *)default_trust)(id,x,flags);
        goto LAB_08165698;
      }
      if ((int)uVar2 < 0) {
        do {
          invalidInstructionException();
        } while( true );
      }
    }
    if ((int)uVar2 < 8) {
      puVar3 = trstandard + uVar2 * 0x18;
    }
    else {
      puVar3 = (undefined1 *)sk_value(trtable,uVar2 - 8);
    }
    iVar1 = (**(code **)(puVar3 + 8))(puVar3,x,flags);
  }
LAB_08165698:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

