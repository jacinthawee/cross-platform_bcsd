
undefined1 * rc4_hmac_md5_ctrl(int param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar12 = *(int *)(param_1 + 0x60);
  if (param_2 == 0x16) {
    if (param_3 == 0xd) {
      uVar5 = (uint)*(ushort *)(param_4 + 0xb);
      if (*(int *)(param_1 + 8) == 0) {
        uVar5 = uVar5 - 0x10;
        *(char *)(param_4 + 0xc) = (char)uVar5;
        *(char *)(param_4 + 0xb) = (char)(uVar5 >> 8);
      }
      *(uint *)(iVar12 + 0x218) = uVar5;
      puVar7 = (undefined4 *)(iVar12 + 0x104);
      puVar3 = (undefined4 *)(iVar12 + 0x1bc);
      do {
        puVar8 = puVar3;
        puVar6 = puVar7;
        puVar7 = puVar6 + 4;
        uVar11 = puVar6[1];
        uVar10 = puVar6[2];
        uVar9 = puVar6[3];
        *puVar8 = *puVar6;
        puVar8[1] = uVar11;
        puVar8[2] = uVar10;
        puVar8[3] = uVar9;
        puVar1 = PTR_MD5_Update_006a8ab0;
        puVar3 = puVar8 + 4;
      } while (puVar7 != (undefined4 *)(iVar12 + 0x154));
      uVar10 = puVar6[5];
      uVar9 = puVar6[6];
      puVar8[4] = *puVar7;
      puVar8[5] = uVar10;
      puVar8[6] = uVar9;
      (*(code *)puVar1)((undefined4 *)(iVar12 + 0x1bc),param_4,0xd);
      puVar4 = (undefined1 *)0x10;
      goto LAB_00547804;
    }
  }
  else if (param_2 == 0x17) {
    (*(code *)PTR_memset_006a99f4)(&local_64,0,0x40);
    if (param_3 < 0x41) {
      (*(code *)PTR___memcpy_chk_006a9a48)(&local_64,param_4,param_3,0x40);
    }
    else {
      iVar13 = iVar12 + 0x104;
      (*(code *)PTR_MD5_Init_006a8160)(iVar13);
      (*(code *)PTR_MD5_Update_006a8ab0)(iVar13,param_4,param_3);
      (*(code *)PTR_MD5_Final_006a8aac)(&local_64,iVar13);
    }
    local_64 = local_64 ^ 0x36363636;
    local_60 = local_60 ^ 0x36363636;
    local_58 = local_58 ^ 0x36363636;
    local_54 = local_54 ^ 0x36363636;
    local_50 = local_50 ^ 0x36363636;
    local_4c = local_4c ^ 0x36363636;
    local_48 = local_48 ^ 0x36363636;
    local_44 = local_44 ^ 0x36363636;
    local_40 = local_40 ^ 0x36363636;
    local_3c = local_3c ^ 0x36363636;
    local_38 = local_38 ^ 0x36363636;
    local_34 = local_34 ^ 0x36363636;
    local_30 = local_30 ^ 0x36363636;
    local_5c = local_5c ^ 0x36363636;
    local_2c = local_2c ^ 0x36363636;
    local_28 = local_28 ^ 0x36363636;
    (*(code *)PTR_MD5_Init_006a8160)(iVar12 + 0x104);
    (*(code *)PTR_MD5_Update_006a8ab0)(iVar12 + 0x104,&local_64,0x40);
    local_64 = local_64 ^ 0x6a6a6a6a;
    local_60 = local_60 ^ 0x6a6a6a6a;
    local_5c = local_5c ^ 0x6a6a6a6a;
    local_58 = local_58 ^ 0x6a6a6a6a;
    local_54 = local_54 ^ 0x6a6a6a6a;
    local_50 = local_50 ^ 0x6a6a6a6a;
    local_4c = local_4c ^ 0x6a6a6a6a;
    local_48 = local_48 ^ 0x6a6a6a6a;
    local_44 = local_44 ^ 0x6a6a6a6a;
    local_40 = local_40 ^ 0x6a6a6a6a;
    local_3c = local_3c ^ 0x6a6a6a6a;
    local_38 = local_38 ^ 0x6a6a6a6a;
    local_34 = local_34 ^ 0x6a6a6a6a;
    local_30 = local_30 ^ 0x6a6a6a6a;
    local_2c = local_2c ^ 0x6a6a6a6a;
    local_28 = local_28 ^ 0x6a6a6a6a;
    (*(code *)PTR_MD5_Init_006a8160)(iVar12 + 0x160);
    (*(code *)PTR_MD5_Update_006a8ab0)(iVar12 + 0x160,&local_64,0x40);
    puVar4 = (undefined1 *)0x1;
    goto LAB_00547804;
  }
  puVar4 = (undefined1 *)0xffffffff;
LAB_00547804:
  if (local_24 == *(int *)puVar2) {
    return puVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return r4_hmac_md5_cipher;
}

