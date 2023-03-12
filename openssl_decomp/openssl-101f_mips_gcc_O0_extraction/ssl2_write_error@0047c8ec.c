
int ssl2_write_error(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined local_20 [4];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar4 = param_1[0x35];
  local_20[0] = 0;
  param_1[0x35] = 0;
  local_20[2] = (undefined)param_1[0x36];
  local_20[1] = (undefined)((uint)param_1[0x36] >> 8);
  local_1c = *(int *)puVar1;
  if (3 < uVar4) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("s2_lib.c",0x210,"error >= 0 && error <= (int)sizeof(buf)");
  }
  puVar3 = param_1;
  iVar2 = ssl2_write(param_1,local_20 + (3 - uVar4),uVar4);
  if (iVar2 < 0) {
    param_1[0x35] = uVar4;
  }
  else {
    param_1[0x35] = uVar4 - iVar2;
    if ((uVar4 - iVar2 == 0) && ((code *)param_1[0x19] != (code *)0x0)) {
      puVar3 = (undefined4 *)0x1;
      (*(code *)param_1[0x19])(1,*param_1,0,local_20,3,param_1,param_1[0x1a]);
    }
  }
  iVar2 = *(int *)puVar1;
  if (local_1c == iVar2) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3[0xc] = 3;
  return 1;
}

