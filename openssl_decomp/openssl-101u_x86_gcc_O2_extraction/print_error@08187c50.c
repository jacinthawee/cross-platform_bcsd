
int print_error(undefined4 param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int in_GS_OFFSET;
  undefined4 local_30 [8];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)local_30 + uVar1) = 0;
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x20);
  local_30[1] = param_1;
  local_30[0] = 5;
  iVar2 = 0;
  if (*(code **)(*param_3 + 8) != (code *)0x0) {
    iVar2 = (**(code **)(*param_3 + 8))(param_3,local_30);
    iVar2 = -(uint)(iVar2 == 0);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

