
int ssl2_return_error(undefined4 *param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *unaff_s0;
  uint uVar5;
  undefined *unaff_s2;
  undefined auStack_60 [4];
  int iStack_5c;
  undefined4 *puStack_58;
  undefined *puStack_54;
  undefined *puStack_50;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  int local_14;
  
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar3 = param_1;
  puStack_58 = unaff_s0;
  if (param_1[0x35] == 0) {
    unaff_s2 = &local_18;
    param_1[0x36] = param_2;
    param_1[0x35] = 0;
    local_18 = 0;
    local_17 = (undefined)((uint)param_2 >> 8);
    local_16 = (undefined)param_2;
    iVar2 = ssl2_write(param_1,unaff_s2,3);
    puStack_58 = param_1;
    if (iVar2 < 0) {
      param_1[0x35] = 3;
    }
    else {
      param_1[0x35] = 3 - iVar2;
      if ((3 - iVar2 == 0) && ((code *)param_1[0x19] != (code *)0x0)) {
        puVar3 = (undefined4 *)0x1;
        (*(code *)param_1[0x19])(1,*param_1,0,unaff_s2);
      }
    }
  }
  iVar2 = *(int *)puStack_54;
  if (local_14 == iVar2) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar5 = puVar3[0x35];
  auStack_60[0] = 0;
  puVar3[0x35] = 0;
  auStack_60[2] = (undefined)puVar3[0x36];
  auStack_60[1] = (undefined)((uint)puVar3[0x36] >> 8);
  iStack_5c = *(int *)puVar1;
  puStack_50 = unaff_s2;
  if (3 < uVar5) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("s2_lib.c",0x210,"error >= 0 && error <= (int)sizeof(buf)");
  }
  puVar4 = puVar3;
  iVar2 = ssl2_write(puVar3,auStack_60 + (3 - uVar5),uVar5);
  if (iVar2 < 0) {
    puVar3[0x35] = uVar5;
  }
  else {
    puVar3[0x35] = uVar5 - iVar2;
    if ((uVar5 - iVar2 == 0) && ((code *)puVar3[0x19] != (code *)0x0)) {
      puVar4 = (undefined4 *)0x1;
      (*(code *)puVar3[0x19])(1,*puVar3,0,auStack_60,3,puVar3,puVar3[0x1a]);
    }
  }
  iVar2 = *(int *)puVar1;
  if (iStack_5c == iVar2) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4[0xc] = 3;
  return 1;
}

