
void ssl2_write_error(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int in_GS_OFFSET;
  undefined local_13;
  undefined local_12;
  undefined local_11;
  int local_10;
  
  local_13 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = param_1[0x35];
  param_1[0x35] = 0;
  local_11 = (undefined)param_1[0x36];
  local_12 = (undefined)((uint)param_1[0x36] >> 8);
  if (3 < uVar1) {
    OpenSSLDie("s2_lib.c",0x210,"error >= 0 && error <= (int)sizeof(buf)");
  }
  iVar2 = ssl2_write(param_1,(int)&local_10 - uVar1,uVar1);
  if (iVar2 < 0) {
    param_1[0x35] = uVar1;
  }
  else {
    param_1[0x35] = uVar1 - iVar2;
    if ((uVar1 - iVar2 == 0) && ((code *)param_1[0x19] != (code *)0x0)) {
      (*(code *)param_1[0x19])(1,*param_1,0,&local_13,3,param_1,param_1[0x1a]);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

