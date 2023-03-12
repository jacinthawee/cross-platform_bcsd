
undefined4 des_ede3_cfb1_cipher(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  undefined local_34 [4];
  byte local_30 [4];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar5 = param_2;
  iVar4 = param_3;
  uVar6 = param_4;
  if (param_4 != 0) {
    uVar8 = 0;
    do {
      iVar4 = *(int *)(param_1 + 0x60);
      uVar6 = 1;
      pbVar9 = (byte *)(param_2 + (uVar8 >> 3));
      local_34[0] = 0x80;
      if (((int)(uint)*(byte *)(param_3 + (uVar8 >> 3)) >> (~uVar8 & 7) & 1U) == 0) {
        local_34[0] = 0;
      }
      (*(code *)PTR_DES_ede3_cfb_encrypt_006a9b08)
                (local_34,local_30,1,1,iVar4,iVar4 + 0x80,iVar4 + 0x100,param_1 + 0x20,
                 *(undefined4 *)(param_1 + 8));
      uVar5 = uVar8 & 7;
      iVar4 = -0x80;
      uVar8 = uVar8 + 1;
      *pbVar9 = ~(byte)(0x80 >> uVar5) & *pbVar9 | (byte)((int)(local_30[0] & 0xffffff80) >> uVar5);
    } while (param_4 != uVar8);
  }
  if (local_2c == *(int *)puVar1) {
    return 1;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (0x3fffffff < uVar6) {
    uVar8 = uVar5;
    iVar7 = iVar4;
    uVar10 = uVar6;
    do {
      iVar2 = *(int *)(iVar3 + 0x60);
      uVar10 = uVar10 + 0xc0000000;
      (*(code *)PTR_DES_ede3_cfb_encrypt_006a9b08)
                (iVar7,uVar8,8,0x40000000,iVar2,iVar2 + 0x80,iVar2 + 0x100,iVar3 + 0x20,
                 *(undefined4 *)(iVar3 + 8));
      iVar7 = iVar7 + 0x40000000;
      uVar8 = uVar8 + 0x40000000;
    } while (0x3fffffff < uVar10);
    uVar8 = uVar6 + 0xc0000000;
    uVar6 = uVar6 & 0x3fffffff;
    iVar3 = ((uVar8 >> 0x1e) + 1) * 0x40000000;
    iVar4 = iVar4 + iVar3;
    uVar5 = uVar5 + iVar3;
  }
  if (uVar6 != 0) {
    (*(code *)PTR_DES_ede3_cfb_encrypt_006a9b08)(iVar4,uVar5,8);
  }
  return 1;
}

