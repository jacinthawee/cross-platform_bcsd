
undefined4 padlock_rand_bytes(undefined *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 < 8) {
LAB_081a76bb:
    for (; 0 < param_2; param_2 = param_2 + -1) {
      do {
        uVar1 = xstore_available(3,&local_14);
        if (((uVar1 & 0x40) == 0) || ((uVar1 & 0x7c00) != 0)) goto LAB_081a7700;
      } while ((uVar1 & 0x1f) == 0);
      if ((uVar1 & 0x1f) != 1) goto LAB_081a7700;
      *param_1 = (char)local_14;
      param_1 = param_1 + 1;
    }
    local_14 = 0;
    uVar2 = 1;
  }
  else {
    uVar1 = xstore_available(0,param_1);
    if (((uVar1 & 0x40) != 0) && ((uVar1 & 0x7c00) == 0)) {
      do {
        if ((uVar1 & 0x1f) != 0) {
          if ((uVar1 & 0x1f) != 8) break;
          param_2 = param_2 + -8;
          param_1 = param_1 + 8;
          if (param_2 < 8) goto LAB_081a76bb;
        }
        uVar1 = xstore_available(0,param_1);
        if (((uVar1 & 0x40) == 0) || ((uVar1 & 0x7c00) != 0)) break;
      } while( true );
    }
LAB_081a7700:
    uVar2 = 0;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

