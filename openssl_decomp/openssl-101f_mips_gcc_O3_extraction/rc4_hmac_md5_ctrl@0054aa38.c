
undefined1 * rc4_hmac_md5_ctrl(int param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar13 = *(int *)(param_1 + 0x60);
  if (param_2 == 0x16) {
    puVar9 = (undefined *)(param_4 + param_3 + -2);
    puVar7 = (undefined *)(param_4 + param_3 + -1);
    uVar4 = (uint)CONCAT11(*puVar9,*puVar7);
    if (*(int *)(param_1 + 8) == 0) {
      uVar4 = uVar4 - 0x10;
      *puVar9 = (char)(uVar4 >> 8);
      *puVar7 = (char)uVar4;
    }
    *(uint *)(iVar13 + 0x218) = uVar4;
    puVar6 = (undefined4 *)(iVar13 + 0x104);
    puVar2 = (undefined4 *)(iVar13 + 0x1bc);
    do {
      puVar8 = puVar2;
      puVar5 = puVar6;
      puVar6 = puVar5 + 4;
      uVar12 = puVar5[1];
      uVar11 = puVar5[2];
      uVar10 = puVar5[3];
      *puVar8 = *puVar5;
      puVar8[1] = uVar12;
      puVar8[2] = uVar11;
      puVar8[3] = uVar10;
      puVar7 = PTR_MD5_Update_006a9bcc;
      puVar2 = puVar8 + 4;
    } while (puVar6 != (undefined4 *)(iVar13 + 0x154));
    uVar11 = puVar5[5];
    uVar10 = puVar5[6];
    puVar8[4] = *puVar6;
    puVar8[5] = uVar11;
    puVar8[6] = uVar10;
    (*(code *)puVar7)((undefined4 *)(iVar13 + 0x1bc),param_4,param_3);
    puVar3 = (undefined1 *)0x10;
  }
  else if (param_2 == 0x17) {
    (*(code *)PTR_memset_006aab00)(&local_64,0,0x40);
    if (param_3 < 0x41) {
      (*(code *)PTR___memcpy_chk_006aab54)(&local_64,param_4,param_3,0x40);
    }
    else {
      iVar14 = iVar13 + 0x104;
      (*(code *)PTR_MD5_Init_006a9294)(iVar14);
      (*(code *)PTR_MD5_Update_006a9bcc)(iVar14,param_4,param_3);
      (*(code *)PTR_MD5_Final_006a9bc8)(&local_64,iVar14);
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
    (*(code *)PTR_MD5_Init_006a9294)(iVar13 + 0x104);
    (*(code *)PTR_MD5_Update_006a9bcc)(iVar13 + 0x104,&local_64,0x40);
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
    (*(code *)PTR_MD5_Init_006a9294)(iVar13 + 0x160);
    (*(code *)PTR_MD5_Update_006a9bcc)(iVar13 + 0x160,&local_64,0x40);
    puVar3 = (undefined1 *)0x1;
  }
  else {
    puVar3 = (undefined1 *)0xffffffff;
  }
  if (local_24 == *(int *)puVar1) {
    return puVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return r4_hmac_md5_cipher;
}

