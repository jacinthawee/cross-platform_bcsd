
void RC2_ofb64_encrypt(uchar *in,uchar *out,long length,RC2_KEY *schedule,uchar *ivec,int *num)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined *puVar4;
  int iVar5;
  byte *pbVar6;
  uint *puVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  long unaff_s1;
  uint *unaff_s3;
  uint *puVar12;
  undefined4 *puVar13;
  uint *unaff_s8;
  undefined4 uStack_ec;
  uint uStack_e8;
  byte abStack_e4 [4];
  undefined uStack_e0;
  undefined uStack_df;
  undefined uStack_de;
  undefined uStack_dd;
  int iStack_dc;
  uint uStack_d8;
  uint *puStack_d4;
  byte *pbStack_d0;
  uint *puStack_cc;
  undefined *puStack_c8;
  uint uStack_c4;
  uint *puStack_c0;
  byte *pbStack_bc;
  uint *puStack_b8;
  code *pcStack_b4;
  undefined4 *puStack_a0;
  uint *puStack_9c;
  uint uStack_94;
  uint uStack_90;
  int iStack_8c;
  uint uStack_88;
  int iStack_84;
  RC2_KEY *pRStack_80;
  uint *puStack_7c;
  undefined *puStack_78;
  byte *pbStack_74;
  byte *pbStack_70;
  uchar *puStack_6c;
  uint *puStack_68;
  undefined4 uStack_64;
  uint *local_50;
  uint *puStack_4c;
  int iStack_48;
  uint *local_44;
  uint local_3c;
  uint local_38;
  byte local_34 [4];
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  int local_2c;
  
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  puVar12 = (uint *)&_gp;
  local_50 = (uint *)&_gp;
  pbStack_d0 = (byte *)(uint)ivec[3];
  local_44 = (uint *)num;
  uStack_88 = *num;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_3c = (int)pbStack_d0 << 0x18 | (uint)ivec[1] << 8 | (uint)ivec[2] << 0x10 | (uint)*ivec;
  local_38 = (uint)ivec[7] << 0x18 | (uint)ivec[5] << 8 | (uint)ivec[6] << 0x10 | (uint)ivec[4];
  local_34[0] = *ivec;
  local_34[2] = ivec[2];
  pbVar8 = (byte *)(local_38 >> 8);
  local_34[1] = ivec[1];
  local_34[3] = ivec[3];
  local_30 = ivec[4];
  local_2f = ivec[5];
  local_2e = ivec[6];
  local_2d = ivec[7];
  if (length != 0) {
    unaff_s8 = (uint *)0x0;
    unaff_s3 = &local_3c;
    unaff_s1 = length;
    pbVar9 = out;
    do {
      if (uStack_88 == 0) {
        unaff_s8 = (uint *)((int)unaff_s8 + 1);
        (**(code **)((int)puVar12 + -0x5764))(unaff_s3,schedule);
        length = local_3c >> 0x10;
        local_34[0] = (byte)local_3c;
        pbVar8 = (byte *)(local_38 >> 8);
        local_30 = (byte)local_38;
        local_34[1] = (byte)(local_3c >> 8);
        local_34[2] = (byte)(local_3c >> 0x10);
        local_2f = (byte)(local_38 >> 8);
        local_34[3] = (byte)(local_3c >> 0x18);
        local_2e = (byte)(local_38 >> 0x10);
        local_2d = (byte)(local_38 >> 0x18);
        puVar12 = local_50;
      }
      out = pbVar9 + 1;
      bVar2 = *in;
      unaff_s1 = unaff_s1 + -1;
      pbVar1 = local_34 + uStack_88;
      in = in + 1;
      uStack_88 = uStack_88 + 1 & 7;
      *pbVar9 = bVar2 ^ *pbVar1;
      pbVar9 = out;
    } while (unaff_s1 != 0);
    if (unaff_s8 != (uint *)0x0) {
      length = local_3c >> 0x10;
      *ivec = (uchar)local_3c;
      pbVar8 = (byte *)(local_38 >> 8);
      ivec[4] = (uchar)local_38;
      ivec[1] = (uchar)(local_3c >> 8);
      ivec[2] = (uchar)(local_3c >> 0x10);
      ivec[5] = (uchar)(local_38 >> 8);
      ivec[3] = (uchar)(local_3c >> 0x18);
      ivec[6] = (uchar)(local_38 >> 0x10);
      ivec[7] = (uchar)(local_38 >> 0x18);
    }
  }
  iVar5 = *(int *)puStack_78;
  *local_44 = uStack_88;
  if (local_2c == iVar5) {
    return;
  }
  uStack_64 = 0x5e6858;
  puVar7 = local_44;
  (**(code **)((int)puVar12 + -0x5330))();
  puStack_d4 = local_50;
  puStack_c8 = PTR___stack_chk_guard_006a9ae8;
  puVar13 = (undefined4 *)&_gp;
  puStack_6c = ivec;
  puStack_a0 = (undefined4 *)&_gp;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_d8 = *puStack_4c;
  pbVar9 = pbStack_d0;
  uStack_c4 = length;
  puStack_c0 = puVar7;
  pbStack_bc = pbVar8;
  iStack_84 = unaff_s1;
  pRStack_80 = schedule;
  puStack_7c = unaff_s3;
  pbStack_74 = in;
  pbStack_70 = out;
  puStack_68 = unaff_s8;
  if (iStack_48 == 0) {
    for (; puStack_b8 = &uStack_94, uStack_c4 != 0; uStack_c4 = uStack_c4 - 1) {
      pbVar8 = pbStack_d0;
      if (uStack_d8 == 0) {
        uStack_94 = *puStack_d4;
        uStack_90 = puStack_d4[1];
        (**(code **)((int)puVar13 + -0x68f8))(&uStack_94);
        length = uStack_94 >> 0x10;
        *(char *)((int)puStack_d4 + 3) = (char)uStack_94;
        pbVar8 = (byte *)(uStack_90 >> 0x18);
        *(char *)((int)puStack_d4 + 7) = (char)uStack_90;
        *(char *)puStack_d4 = (char)(uStack_94 >> 0x18);
        *(char *)((int)puStack_d4 + 1) = (char)(uStack_94 >> 0x10);
        *(char *)(puStack_d4 + 1) = (char)(uStack_90 >> 0x18);
        *(char *)((int)puStack_d4 + 2) = (char)(uStack_94 >> 8);
        *(char *)((int)puStack_d4 + 5) = (char)(uStack_90 >> 0x10);
        *(char *)((int)puStack_d4 + 6) = (char)(uStack_90 >> 8);
        puVar13 = puStack_a0;
      }
      bVar2 = *(byte *)puStack_c0;
      bVar3 = *(byte *)((int)puStack_d4 + uStack_d8);
      puVar7 = (uint *)(uint)bVar3;
      *(byte *)((int)puStack_d4 + uStack_d8) = bVar2;
      puStack_c0 = (uint *)((int)puStack_c0 + 1);
      uStack_d8 = uStack_d8 + 1 & 7;
      *pbStack_bc = bVar2 ^ bVar3;
      pbStack_bc = pbStack_bc + 1;
    }
  }
  else {
    puStack_b8 = unaff_s8;
    if (length != 0) {
      puStack_b8 = &uStack_94;
      pbVar1 = pbVar8;
      do {
        if (uStack_d8 == 0) {
          uStack_94 = *puStack_d4;
          uStack_90 = puStack_d4[1];
          (*(code *)puStack_a0[-0x1a3e])(puStack_b8,pbStack_d0);
          length = uStack_94 >> 0x10;
          *(char *)((int)puStack_d4 + 3) = (char)uStack_94;
          pbVar8 = (byte *)(uStack_90 >> 0x18);
          *(char *)((int)puStack_d4 + 7) = (char)uStack_90;
          *(char *)puStack_d4 = (char)(uStack_94 >> 0x18);
          *(char *)((int)puStack_d4 + 1) = (char)(uStack_94 >> 0x10);
          *(char *)(puStack_d4 + 1) = (char)(uStack_90 >> 0x18);
          *(char *)((int)puStack_d4 + 2) = (char)(uStack_94 >> 8);
          *(char *)((int)puStack_d4 + 5) = (char)(uStack_90 >> 0x10);
          *(char *)((int)puStack_d4 + 6) = (char)(uStack_90 >> 8);
        }
        pbVar6 = (byte *)((int)puStack_d4 + uStack_d8);
        bVar2 = *(byte *)puStack_c0;
        pbStack_bc = pbVar1 + 1;
        bVar3 = *pbVar6;
        puVar7 = (uint *)(uint)bVar3;
        uStack_c4 = uStack_c4 - 1;
        puStack_c0 = (uint *)((int)puStack_c0 + 1);
        uStack_d8 = uStack_d8 + 1 & 7;
        bVar2 = bVar2 ^ bVar3;
        *pbVar1 = bVar2;
        *pbVar6 = bVar2;
        puVar13 = puStack_a0;
        pbVar1 = pbStack_bc;
      } while (uStack_c4 != 0);
    }
  }
  iVar5 = *(int *)puStack_c8;
  *puStack_4c = uStack_d8;
  if (iStack_8c != iVar5) {
    pcStack_b4 = idea_ofb64_encrypt;
    (*(code *)puVar13[-0x14cc])();
    puVar13 = puStack_a0;
    puVar4 = PTR___stack_chk_guard_006a9ae8;
    puStack_cc = puStack_4c;
    uStack_ec = *puStack_a0;
    uStack_e8 = puStack_a0[1];
    uVar11 = *puStack_9c;
    iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
    abStack_e4[3] = (char)uStack_ec;
    abStack_e4[0] = (byte)((uint)uStack_ec >> 0x18);
    uVar10 = uStack_e8 >> 0x18;
    abStack_e4[1] = (char)((uint)uStack_ec >> 0x10);
    abStack_e4[2] = (char)((uint)uStack_ec >> 8);
    uStack_e0 = (char)(uStack_e8 >> 0x18);
    uStack_df = (char)(uStack_e8 >> 0x10);
    uStack_de = (char)(uStack_e8 >> 8);
    uStack_dd = (char)uStack_e8;
    if (length != 0) {
      iVar5 = 0;
      do {
        if (uVar11 == 0) {
          iVar5 = iVar5 + 1;
          (*(code *)PTR_idea_encrypt_006a84e8)(&uStack_ec,pbVar9);
          abStack_e4[3] = (char)uStack_ec;
          uStack_dd = (char)uStack_e8;
          abStack_e4[0] = (byte)((uint)uStack_ec >> 0x18);
          abStack_e4[1] = (char)((uint)uStack_ec >> 0x10);
          uStack_e0 = (char)(uStack_e8 >> 0x18);
          abStack_e4[2] = (char)((uint)uStack_ec >> 8);
          uStack_df = (char)(uStack_e8 >> 0x10);
          uStack_de = (char)(uStack_e8 >> 8);
        }
        bVar2 = *(byte *)puVar7;
        length = length - 1;
        pbVar1 = abStack_e4 + uVar11;
        puVar7 = (uint *)((int)puVar7 + 1);
        uVar11 = uVar11 + 1 & 7;
        *pbVar8 = bVar2 ^ *pbVar1;
        pbVar8 = pbVar8 + 1;
      } while (length != 0);
      if (iVar5 != 0) {
        *(char *)((int)puVar13 + 3) = (char)uStack_ec;
        *(char *)((int)puVar13 + 7) = (char)uStack_e8;
        *(char *)puVar13 = (char)((uint)uStack_ec >> 0x18);
        *(char *)((int)puVar13 + 1) = (char)((uint)uStack_ec >> 0x10);
        *(char *)(puVar13 + 1) = (char)(uStack_e8 >> 0x18);
        *(char *)((int)puVar13 + 2) = (char)((uint)uStack_ec >> 8);
        *(char *)((int)puVar13 + 5) = (char)(uStack_e8 >> 0x10);
        *(char *)((int)puVar13 + 6) = (char)(uStack_e8 >> 8);
      }
    }
    iVar5 = *(int *)puVar4;
    *puStack_9c = uVar11;
    if (iStack_dc == iVar5) {
      return;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (uVar10 != 1) {
                    /* WARNING: Could not recover jumptable at 0x005e6c84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_Camellia_decrypt_006a8514)();
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x005e6c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_Camellia_encrypt_006a8518)();
    return;
  }
  return;
}

