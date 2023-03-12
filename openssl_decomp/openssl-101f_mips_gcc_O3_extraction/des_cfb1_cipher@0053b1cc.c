
undefined4 des_cfb1_cipher(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined *puVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_resc;
  uint local_40;
  undefined local_34 [4];
  byte local_30 [4];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_4 < 0x8000000) {
    local_40 = param_4;
    if (param_4 == 0) goto LAB_0053b33c;
  }
  else {
    local_40 = 0x8000000;
  }
  uVar3 = param_2;
  iVar4 = param_3;
  local_resc = param_4;
  do {
    if (local_40 << 3 != 0) {
      uVar6 = 0;
      do {
        param_4 = 1;
        local_34[0] = 0x80;
        if (((int)(uint)*(byte *)(iVar4 + (uVar6 >> 3)) >> (~uVar6 & 7) & 1U) == 0) {
          local_34[0] = 0;
        }
        (*(code *)PTR_DES_cfb_encrypt_006a9ae8)
                  (local_34,local_30,1,1,*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,
                   *(undefined4 *)(param_1 + 8));
        pbVar2 = (byte *)(uVar3 + (uVar6 >> 3));
        param_2 = uVar6 & 7;
        param_3 = -0x80;
        uVar6 = uVar6 + 1;
        *pbVar2 = ~(byte)(0x80 >> param_2) & *pbVar2 |
                  (byte)((int)(local_30[0] & 0xffffff80) >> param_2);
      } while (local_40 << 3 != uVar6);
    }
    iVar4 = iVar4 + local_40;
    local_resc = local_resc - local_40;
    uVar3 = uVar3 + local_40;
    if (local_resc < local_40) {
      local_40 = local_resc;
    }
  } while ((local_resc != 0) && (local_40 <= local_resc));
LAB_0053b33c:
  if (local_2c != *(int *)puVar1) {
    iVar4 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (0x3fffffff < param_4) {
      uVar3 = param_2;
      iVar5 = param_3;
      uVar6 = param_4;
      do {
        uVar6 = uVar6 + 0xc0000000;
        (*(code *)PTR_DES_cfb_encrypt_006a9ae8)
                  (iVar5,uVar3,8,0x40000000,*(undefined4 *)(iVar4 + 0x60),iVar4 + 0x20,
                   *(undefined4 *)(iVar4 + 8));
        iVar5 = iVar5 + 0x40000000;
        uVar3 = uVar3 + 0x40000000;
      } while (0x3fffffff < uVar6);
      uVar3 = param_4 + 0xc0000000;
      param_4 = param_4 & 0x3fffffff;
      iVar4 = ((uVar3 >> 0x1e) + 1) * 0x40000000;
      param_3 = param_3 + iVar4;
      param_2 = param_2 + iVar4;
    }
    if (param_4 != 0) {
      (*(code *)PTR_DES_cfb_encrypt_006a9ae8)(param_3,param_2,8);
    }
    return 1;
  }
  return 1;
}

