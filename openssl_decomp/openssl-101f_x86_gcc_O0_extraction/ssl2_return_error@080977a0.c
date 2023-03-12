
void ssl2_return_error(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1[0x35] == 0) {
    local_13 = 0;
    local_11 = (undefined)param_2;
    param_1[0x36] = param_2;
    local_12 = (undefined)((uint)param_2 >> 8);
    param_1[0x35] = 0;
    iVar1 = ssl2_write(param_1,&local_13,3);
    if (iVar1 < 0) {
      param_1[0x35] = 3;
    }
    else {
      param_1[0x35] = 3 - iVar1;
      if ((3 - iVar1 == 0) && ((code *)param_1[0x19] != (code *)0x0)) {
        (*(code *)param_1[0x19])(1,*param_1,0,&local_13,3,param_1,param_1[0x1a]);
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

