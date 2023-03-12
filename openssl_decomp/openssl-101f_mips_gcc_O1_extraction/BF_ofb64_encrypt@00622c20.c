
void BF_ofb64_encrypt(uchar *in,uchar *out,long length,BF_KEY *schedule,uchar *ivec,int *num)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint **ppuVar4;
  int iVar5;
  uint **ppuVar6;
  uint **ppuVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  long unaff_s1;
  uint uVar16;
  uint *unaff_s3;
  undefined *puVar17;
  uint *puVar18;
  uint *unaff_s8;
  uint uStack_124;
  uint uStack_120;
  byte abStack_11c [4];
  undefined uStack_118;
  undefined uStack_117;
  undefined uStack_116;
  undefined uStack_115;
  int iStack_114;
  uint uStack_110;
  uint *puStack_10c;
  byte *pbStack_108;
  uint *puStack_104;
  undefined *puStack_100;
  uint uStack_fc;
  byte *pbStack_f8;
  byte *pbStack_f4;
  uint *puStack_f0;
  code *pcStack_ec;
  uint *puStack_d8;
  uint *puStack_d4;
  uint uStack_cc;
  uint uStack_c8;
  int iStack_c4;
  undefined *puStack_c0;
  undefined *puStack_bc;
  BF_KEY *pBStack_b8;
  uint *puStack_b4;
  undefined *puStack_b0;
  byte *pbStack_ac;
  byte *pbStack_a8;
  uchar *puStack_a4;
  uint *puStack_a0;
  undefined4 uStack_9c;
  uint *puStack_88;
  uint *puStack_84;
  int iStack_80;
  uint uStack_7c;
  uint uStack_78;
  byte *pbStack_74;
  uint uStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  undefined *local_50;
  uint *local_44;
  uint local_3c;
  uint local_38;
  byte local_34 [4];
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  int local_2c;
  
  puStack_b0 = PTR___stack_chk_guard_006aabf0;
  puVar17 = &_gp;
  local_50 = &_gp;
  local_3c = *(uint *)ivec;
  local_44 = (uint *)num;
  local_38 = *(uint *)(ivec + 4);
  uStack_6c = *num;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_34[3] = (char)local_3c;
  local_34[0] = (byte)(local_3c >> 0x18);
  pbStack_108 = (byte *)(local_38 >> 0x18);
  local_34[1] = (char)(local_3c >> 0x10);
  puStack_c0 = (undefined *)(local_38 >> 0x10);
  local_34[2] = (char)(local_3c >> 8);
  local_30 = (char)(local_38 >> 0x18);
  local_2f = (char)(local_38 >> 0x10);
  local_2e = (char)(local_38 >> 8);
  local_2d = (char)local_38;
  if (length != 0) {
    unaff_s8 = (uint *)0x0;
    unaff_s3 = &local_3c;
    unaff_s1 = length;
    pbVar11 = out;
    do {
      if (uStack_6c == 0) {
        unaff_s8 = (uint *)((int)unaff_s8 + 1);
        (**(code **)(puVar17 + -0x68d4))(unaff_s3,schedule);
        length = local_3c >> 0x10;
        local_34[3] = (char)local_3c;
        puStack_c0 = (undefined *)(local_38 >> 0x18);
        local_2d = (char)local_38;
        local_34[0] = (byte)(local_3c >> 0x18);
        local_34[1] = (char)(local_3c >> 0x10);
        local_30 = (char)(local_38 >> 0x18);
        local_34[2] = (char)(local_3c >> 8);
        local_2f = (char)(local_38 >> 0x10);
        local_2e = (char)(local_38 >> 8);
        puVar17 = local_50;
      }
      out = pbVar11 + 1;
      bVar2 = *in;
      unaff_s1 = unaff_s1 + -1;
      pbVar10 = local_34 + uStack_6c;
      in = in + 1;
      uStack_6c = uStack_6c + 1 & 7;
      *pbVar11 = bVar2 ^ *pbVar10;
      pbVar11 = out;
    } while (unaff_s1 != 0);
    if (unaff_s8 != (uint *)0x0) {
      length = local_3c >> 0x10;
      ivec[3] = (uchar)local_3c;
      puStack_c0 = (undefined *)(local_38 >> 0x18);
      ivec[7] = (uchar)local_38;
      *ivec = (uchar)(local_3c >> 0x18);
      ivec[1] = (uchar)(local_3c >> 0x10);
      ivec[4] = (uchar)(local_38 >> 0x18);
      ivec[2] = (uchar)(local_3c >> 8);
      ivec[5] = (uchar)(local_38 >> 0x10);
      ivec[6] = (uchar)(local_38 >> 8);
    }
  }
  iVar5 = *(int *)puStack_b0;
  *local_44 = uStack_6c;
  if (local_2c == iVar5) {
    return;
  }
  uStack_64 = 0x622e08;
  puVar18 = local_44;
  (**(code **)(puVar17 + -0x5328))();
  puStack_bc = PTR___stack_chk_guard_006aabf0;
  puStack_88 = (uint *)&_gp;
  uStack_7c = *puVar18;
  uStack_78 = puVar18[1];
  pbStack_74 = *(byte **)PTR___stack_chk_guard_006aabf0;
  iStack_68 = unaff_s1;
  if (pbStack_108 == (byte *)0x0) {
    (*(code *)PTR_CAST_decrypt_006aa9d8)(&uStack_7c);
  }
  else {
    (*(code *)PTR_CAST_encrypt_006aa9dc)(&uStack_7c,length);
  }
  puStack_c0[3] = (char)uStack_7c;
  puStack_c0[7] = (char)uStack_78;
  *puStack_c0 = (char)(uStack_7c >> 0x18);
  uVar13 = uStack_78 >> 0x18;
  puStack_c0[1] = (char)(uStack_7c >> 0x10);
  pbVar11 = (byte *)(uStack_78 >> 0x10);
  puStack_c0[2] = (char)(uStack_7c >> 8);
  puStack_c0[4] = (char)(uStack_78 >> 0x18);
  puStack_c0[5] = (char)(uStack_78 >> 0x10);
  puStack_c0[6] = (char)(uStack_78 >> 8);
  if (pbStack_74 == *(byte **)puStack_bc) {
    return;
  }
  uStack_9c = 0x622eec;
  pbVar10 = pbStack_74;
  (*(code *)puStack_88[-0x14ca])();
  puStack_10c = puStack_88;
  puStack_100 = PTR___stack_chk_guard_006aabf0;
  puVar18 = (uint *)&_gp;
  puStack_a4 = ivec;
  puStack_d8 = (uint *)&_gp;
  iStack_c4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_110 = *puStack_84;
  pbVar14 = pbStack_108;
  uStack_fc = uVar13;
  pbStack_f8 = pbVar10;
  pbStack_f4 = pbVar11;
  pBStack_b8 = schedule;
  puStack_b4 = unaff_s3;
  pbStack_ac = in;
  pbStack_a8 = out;
  puStack_a0 = unaff_s8;
  if (iStack_80 == 0) {
    for (; puStack_f0 = &uStack_cc, uStack_fc != 0; uStack_fc = uStack_fc - 1) {
      pbVar11 = pbStack_108;
      if (uStack_110 == 0) {
        uStack_cc = *puStack_10c;
        uStack_c8 = puStack_10c[1];
        (**(code **)((int)puVar18 + -0x5504))(&uStack_cc);
        uVar13 = uStack_cc >> 0x10;
        *(char *)((int)puStack_10c + 3) = (char)uStack_cc;
        pbVar11 = (byte *)(uStack_c8 >> 0x18);
        *(char *)((int)puStack_10c + 7) = (char)uStack_c8;
        *(char *)puStack_10c = (char)(uStack_cc >> 0x18);
        *(char *)((int)puStack_10c + 1) = (char)(uStack_cc >> 0x10);
        *(char *)(puStack_10c + 1) = (char)(uStack_c8 >> 0x18);
        *(char *)((int)puStack_10c + 2) = (char)(uStack_cc >> 8);
        *(char *)((int)puStack_10c + 5) = (char)(uStack_c8 >> 0x10);
        *(char *)((int)puStack_10c + 6) = (char)(uStack_c8 >> 8);
        puVar18 = puStack_d8;
      }
      bVar2 = *pbStack_f8;
      bVar3 = *(byte *)((int)puStack_10c + uStack_110);
      pbVar10 = (byte *)(uint)bVar3;
      *(byte *)((int)puStack_10c + uStack_110) = bVar2;
      pbStack_f8 = pbStack_f8 + 1;
      uStack_110 = uStack_110 + 1 & 7;
      *pbStack_f4 = bVar2 ^ bVar3;
      pbStack_f4 = pbStack_f4 + 1;
    }
  }
  else {
    puStack_f0 = unaff_s8;
    if (uVar13 != 0) {
      puStack_f0 = &uStack_cc;
      pbVar1 = pbVar11;
      do {
        if (uStack_110 == 0) {
          uStack_cc = *puStack_10c;
          uStack_c8 = puStack_10c[1];
          (*(code *)puStack_d8[-0x1541])(puStack_f0,pbStack_108);
          uVar13 = uStack_cc >> 0x10;
          *(char *)((int)puStack_10c + 3) = (char)uStack_cc;
          pbVar11 = (byte *)(uStack_c8 >> 0x18);
          *(char *)((int)puStack_10c + 7) = (char)uStack_c8;
          *(char *)puStack_10c = (char)(uStack_cc >> 0x18);
          *(char *)((int)puStack_10c + 1) = (char)(uStack_cc >> 0x10);
          *(char *)(puStack_10c + 1) = (char)(uStack_c8 >> 0x18);
          *(char *)((int)puStack_10c + 2) = (char)(uStack_cc >> 8);
          *(char *)((int)puStack_10c + 5) = (char)(uStack_c8 >> 0x10);
          *(char *)((int)puStack_10c + 6) = (char)(uStack_c8 >> 8);
        }
        pbVar9 = (byte *)((int)puStack_10c + uStack_110);
        bVar2 = *pbStack_f8;
        pbStack_f4 = pbVar1 + 1;
        bVar3 = *pbVar9;
        pbVar10 = (byte *)(uint)bVar3;
        uStack_fc = uStack_fc - 1;
        pbStack_f8 = pbStack_f8 + 1;
        uStack_110 = uStack_110 + 1 & 7;
        bVar2 = bVar2 ^ bVar3;
        *pbVar1 = bVar2;
        *pbVar9 = bVar2;
        puVar18 = puStack_d8;
        pbVar1 = pbStack_f4;
      } while (uStack_fc != 0);
    }
  }
  iVar5 = *(int *)puStack_100;
  *puStack_84 = uStack_110;
  if (iStack_c4 == iVar5) {
    return;
  }
  pcStack_ec = CAST_ofb64_encrypt;
  (*(code *)puVar18[-0x14ca])();
  puVar18 = puStack_d8;
  puVar17 = PTR___stack_chk_guard_006aabf0;
  puStack_104 = puStack_84;
  uStack_124 = *puStack_d8;
  uStack_120 = puStack_d8[1];
  uVar15 = *puStack_d4;
  iStack_114 = *(int *)PTR___stack_chk_guard_006aabf0;
  abStack_11c[3] = (char)uStack_124;
  abStack_11c[0] = (byte)(uStack_124 >> 0x18);
  abStack_11c[1] = (char)(uStack_124 >> 0x10);
  uVar12 = uStack_120 >> 0x10;
  abStack_11c[2] = (char)(uStack_124 >> 8);
  uStack_118 = (char)(uStack_120 >> 0x18);
  uStack_117 = (char)(uStack_120 >> 0x10);
  uStack_116 = (char)(uStack_120 >> 8);
  uStack_115 = (char)uStack_120;
  if (uVar13 != 0) {
    iVar5 = 0;
    uVar16 = uVar13;
    do {
      if (uVar15 == 0) {
        iVar5 = iVar5 + 1;
        (*(code *)PTR_CAST_encrypt_006aa9dc)(&uStack_124,pbVar14);
        uVar13 = uStack_124 >> 0x10;
        abStack_11c[3] = (char)uStack_124;
        uVar12 = uStack_120 >> 0x18;
        uStack_115 = (char)uStack_120;
        abStack_11c[0] = (byte)(uStack_124 >> 0x18);
        abStack_11c[1] = (char)(uStack_124 >> 0x10);
        uStack_118 = (char)(uStack_120 >> 0x18);
        abStack_11c[2] = (char)(uStack_124 >> 8);
        uStack_117 = (char)(uStack_120 >> 0x10);
        uStack_116 = (char)(uStack_120 >> 8);
      }
      bVar2 = *pbVar10;
      uVar16 = uVar16 - 1;
      pbVar1 = abStack_11c + uVar15;
      pbVar10 = pbVar10 + 1;
      uVar15 = uVar15 + 1 & 7;
      *pbVar11 = bVar2 ^ *pbVar1;
      pbVar11 = pbVar11 + 1;
    } while (uVar16 != 0);
    if (iVar5 != 0) {
      uVar13 = uStack_124 >> 0x10;
      *(char *)((int)puVar18 + 3) = (char)uStack_124;
      uVar12 = uStack_120 >> 0x18;
      *(char *)((int)puVar18 + 7) = (char)uStack_120;
      *(char *)puVar18 = (char)(uStack_124 >> 0x18);
      *(char *)((int)puVar18 + 1) = (char)(uStack_124 >> 0x10);
      *(char *)(puVar18 + 1) = (char)(uStack_120 >> 0x18);
      *(char *)((int)puVar18 + 2) = (char)(uStack_124 >> 8);
      *(char *)((int)puVar18 + 5) = (char)(uStack_120 >> 0x10);
      *(char *)((int)puVar18 + 6) = (char)(uStack_120 >> 8);
    }
  }
  iVar5 = *(int *)puVar17;
  *puStack_d4 = uVar15;
  if (iStack_114 == iVar5) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar13);
  ppuVar6 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
  ppuVar7 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
  if (ppuVar7 == (uint **)0x0) {
    (*(code *)PTR_BN_CTX_end_006a9654)(uVar13);
    return;
  }
  iVar5 = (*(code *)PTR_BN_copy_006a9570)(ppuVar6,puStack_d4);
  if (iVar5 == 0) {
LAB_00623404:
    (*(code *)PTR_BN_CTX_end_006a9654)(uVar13);
    return;
  }
  iVar5 = (*(code *)PTR_BN_copy_006a9570)(ppuVar7,uVar12);
  if (iVar5 != 0) {
    if (ppuVar7[1] != (uint *)0x0) {
      if (((int)ppuVar6[1] < 1) || (iVar5 = 0, (**ppuVar6 & 1) == 0)) {
        if (((int)ppuVar7[1] < 1) || ((**ppuVar7 & 1) == 0)) goto LAB_006233cc;
        iVar5 = 0;
      }
      while (iVar8 = (*(code *)PTR_BN_is_bit_set_006a9650)(ppuVar7,iVar5), iVar8 == 0) {
        iVar5 = iVar5 + 1;
      }
      iVar5 = (*(code *)PTR_BN_rshift_006a96f8)(ppuVar7,ppuVar7,iVar5);
      if (iVar5 != 0) {
        puVar18 = ppuVar6[1];
        if (ppuVar7[3] != (uint *)0x0) {
          ppuVar7[3] = (uint *)0x0;
        }
        while (ppuVar4 = ppuVar6, puVar18 != (uint *)0x0) {
          iVar5 = 0;
          while (iVar8 = (*(code *)PTR_BN_is_bit_set_006a9650)(ppuVar4,iVar5), iVar8 == 0) {
            iVar5 = iVar5 + 1;
          }
          iVar5 = (*(code *)PTR_BN_rshift_006a96f8)(ppuVar4,ppuVar4,iVar5);
          if (iVar5 == 0) goto LAB_00623404;
          iVar5 = (*(code *)PTR_BN_nnmod_006a9664)(ppuVar7,ppuVar7,ppuVar4,uVar13);
          if (iVar5 == 0) break;
          puVar18 = ppuVar7[1];
          ppuVar4[3] = (uint *)0x0;
          ppuVar6 = ppuVar7;
          ppuVar7 = ppuVar4;
        }
      }
    }
  }
LAB_006233cc:
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar13);
  return;
}

