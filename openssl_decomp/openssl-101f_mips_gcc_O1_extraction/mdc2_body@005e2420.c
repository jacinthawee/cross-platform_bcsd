
void mdc2_body(undefined4 *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined *puVar9;
  undefined *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  byte *pbVar16;
  byte *pbVar17;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  undefined auStack_ac [128];
  int local_2c;
  
  puVar10 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar14 = param_1;
  if (param_3 != 0) {
    uVar12 = (uint)*(byte *)(param_1 + 3);
    uVar11 = (uint)*(byte *)(param_1 + 5);
    pbVar16 = param_2;
    do {
      puVar9 = PTR_DES_set_odd_parity_006a9ad8;
      bVar1 = *pbVar16;
      pbVar17 = pbVar16 + 8;
      bVar2 = pbVar16[1];
      bVar3 = pbVar16[2];
      bVar4 = pbVar16[5];
      bVar5 = pbVar16[6];
      bVar6 = pbVar16[3];
      bVar7 = pbVar16[7];
      bVar8 = pbVar16[4];
      *(byte *)(param_1 + 3) = (byte)uVar12 & 0x9f | 0x40;
      *(byte *)(param_1 + 5) = (byte)uVar11 & 0x9f | 0x20;
      uVar12 = (uint)bVar6 << 0x18 | (uint)bVar2 << 8 | (uint)bVar3 << 0x10 | (uint)bVar1;
      uVar15 = (uint)bVar7 << 0x18 | (uint)bVar4 << 8 | (uint)bVar5 << 0x10 | (uint)bVar8;
      local_bc = uVar12;
      local_b8 = uVar15;
      local_b4 = uVar12;
      local_b0 = uVar15;
      (*(code *)puVar9)(param_1 + 3);
      (*(code *)PTR_DES_set_key_unchecked_006a8ad8)(param_1 + 3,auStack_ac);
      (*(code *)PTR_DES_encrypt1_006a95e8)(&local_bc,auStack_ac,1);
      (*(code *)PTR_DES_set_odd_parity_006a9ad8)(param_1 + 5);
      (*(code *)PTR_DES_set_key_unchecked_006a8ad8)(param_1 + 5,auStack_ac);
      (*(code *)PTR_DES_encrypt1_006a95e8)(&local_b4,auStack_ac,1);
      uVar13 = uVar15 ^ local_b0;
      *(char *)(param_1 + 4) = (char)uVar13;
      uVar11 = uVar12 ^ local_b4;
      uVar12 = uVar12 ^ local_bc;
      *(char *)((int)param_1 + 0x11) = (char)(uVar13 >> 8);
      uVar15 = uVar15 ^ local_b8;
      *(char *)((int)param_1 + 0xe) = (char)(uVar12 >> 0x10);
      *(char *)(param_1 + 6) = (char)uVar15;
      *(char *)((int)param_1 + 0xf) = (char)(uVar12 >> 0x18);
      *(char *)((int)param_1 + 0xd) = (char)(uVar12 >> 8);
      *(char *)((int)param_1 + 0x19) = (char)(uVar15 >> 8);
      *(char *)((int)param_1 + 0x15) = (char)(uVar11 >> 8);
      *(char *)((int)param_1 + 0x12) = (char)(uVar13 >> 0x10);
      *(char *)((int)param_1 + 0x13) = (char)(uVar13 >> 0x18);
      puVar14 = (undefined4 *)(uVar15 >> 0x10);
      *(char *)((int)param_1 + 0x16) = (char)(uVar11 >> 0x10);
      *(char *)((int)param_1 + 0x17) = (char)(uVar11 >> 0x18);
      uVar11 = uVar11 & 0xff;
      uVar12 = uVar12 & 0xff;
      *(char *)((int)param_1 + 0x1a) = (char)(uVar15 >> 0x10);
      *(char *)(param_1 + 5) = (char)uVar11;
      *(char *)(param_1 + 3) = (char)uVar12;
      *(char *)((int)param_1 + 0x1b) = (char)(uVar15 >> 0x18);
      pbVar16 = pbVar17;
    } while ((uint)((int)pbVar17 - (int)param_2) < param_3);
  }
  if (local_2c != *(int *)puVar10) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    *puVar14 = 0;
    *(undefined *)(puVar14 + 3) = 0x52;
    *(undefined *)((int)puVar14 + 0xd) = 0x52;
    puVar14[7] = 1;
    *(undefined *)((int)puVar14 + 0xe) = 0x52;
    *(undefined *)((int)puVar14 + 0xf) = 0x52;
    *(undefined *)(puVar14 + 4) = 0x52;
    *(undefined *)((int)puVar14 + 0x11) = 0x52;
    *(undefined *)((int)puVar14 + 0x12) = 0x52;
    *(undefined *)((int)puVar14 + 0x13) = 0x52;
    *(undefined *)(puVar14 + 5) = 0x25;
    *(undefined *)((int)puVar14 + 0x15) = 0x25;
    *(undefined *)((int)puVar14 + 0x16) = 0x25;
    *(undefined *)((int)puVar14 + 0x17) = 0x25;
    *(undefined *)(puVar14 + 6) = 0x25;
    *(undefined *)((int)puVar14 + 0x19) = 0x25;
    *(undefined *)((int)puVar14 + 0x1a) = 0x25;
    *(undefined *)((int)puVar14 + 0x1b) = 0x25;
    return;
  }
  return;
}

