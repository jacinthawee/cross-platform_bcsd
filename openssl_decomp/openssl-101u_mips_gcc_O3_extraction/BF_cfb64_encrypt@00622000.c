
void BF_cfb64_encrypt(uchar *in,uchar *out,long length,BF_KEY *schedule,uchar *ivec,int *num,int enc
                     )

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
  uint uVar16;
  BF_KEY *pBVar17;
  uint *puVar18;
  undefined *puVar19;
  uint *unaff_s8;
  uint uStack_174;
  uint uStack_170;
  byte abStack_16c [4];
  undefined uStack_168;
  undefined uStack_167;
  undefined uStack_166;
  undefined uStack_165;
  int iStack_164;
  uint uStack_160;
  uint *puStack_15c;
  byte *pbStack_158;
  uint *puStack_154;
  undefined *puStack_150;
  uint uStack_14c;
  byte *pbStack_148;
  byte *pbStack_144;
  uint *puStack_140;
  code *pcStack_13c;
  uint *puStack_128;
  uint *puStack_124;
  uint uStack_11c;
  uint uStack_118;
  int iStack_114;
  undefined *puStack_110;
  undefined *puStack_10c;
  BF_KEY *pBStack_108;
  uint *puStack_104;
  undefined *puStack_100;
  byte *pbStack_fc;
  BF_KEY *pBStack_f8;
  uint *puStack_f4;
  uint *puStack_f0;
  undefined4 uStack_ec;
  uint *puStack_d8;
  uint *puStack_d4;
  int iStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  byte *pbStack_c4;
  uint uStack_bc;
  uchar *puStack_b8;
  undefined4 uStack_b4;
  undefined *puStack_a0;
  uint *puStack_94;
  uint uStack_8c;
  uint uStack_88;
  byte abStack_84 [4];
  undefined uStack_80;
  undefined uStack_7f;
  undefined uStack_7e;
  undefined uStack_7d;
  int iStack_7c;
  uint uStack_78;
  uchar *puStack_74;
  BF_KEY *pBStack_70;
  int *piStack_6c;
  undefined *puStack_68;
  long lStack_64;
  byte *pbStack_60;
  byte *pbStack_5c;
  uint *puStack_58;
  code *pcStack_54;
  uint *local_40;
  uint *puStack_3c;
  uint local_34;
  uint local_30;
  int local_2c;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  puVar18 = (uint *)&_gp;
  local_40 = (uint *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_78 = *num;
  pBStack_108 = schedule;
  lStack_64 = length;
  pbStack_60 = in;
  pbStack_5c = out;
  if (enc == 0) {
    unaff_s8 = &local_34;
    pbVar11 = out;
    if (length != 0) {
      do {
        out = (uchar *)schedule;
        if (uStack_78 == 0) {
          local_34 = *(uint *)ivec;
          local_30 = *(uint *)(ivec + 4);
          (**(code **)((int)puVar18 + -0x68f4))(unaff_s8);
          length = local_34 >> 0x10;
          ivec[3] = (uchar)local_34;
          out = (uchar *)(local_30 >> 0x18);
          ivec[7] = (uchar)local_30;
          *ivec = (uchar)(local_34 >> 0x18);
          ivec[1] = (uchar)(local_34 >> 0x10);
          ivec[4] = (uchar)(local_30 >> 0x18);
          ivec[2] = (uchar)(local_34 >> 8);
          ivec[5] = (uchar)(local_30 >> 0x10);
          ivec[6] = (uchar)(local_30 >> 8);
          puVar18 = local_40;
        }
        bVar2 = *pbStack_60;
        bVar3 = ivec[uStack_78];
        in = (uchar *)(uint)bVar3;
        lStack_64 = lStack_64 + -1;
        ivec[uStack_78] = bVar2;
        pbStack_60 = pbStack_60 + 1;
        uStack_78 = uStack_78 + 1 & 7;
        *pbVar11 = bVar2 ^ bVar3;
        pbStack_5c = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
      } while (lStack_64 != 0);
    }
  }
  else if (length != 0) {
    unaff_s8 = &local_34;
    pbVar11 = out;
    do {
      if (uStack_78 == 0) {
        local_34 = *(uint *)ivec;
        local_30 = *(uint *)(ivec + 4);
        (*(code *)local_40[-0x1a3d])(unaff_s8,schedule);
        length = local_34 >> 0x10;
        ivec[3] = (uchar)local_34;
        out = (uchar *)(local_30 >> 0x18);
        ivec[7] = (uchar)local_30;
        *ivec = (uchar)(local_34 >> 0x18);
        ivec[1] = (uchar)(local_34 >> 0x10);
        ivec[4] = (uchar)(local_30 >> 0x18);
        ivec[2] = (uchar)(local_34 >> 8);
        ivec[5] = (uchar)(local_30 >> 0x10);
        ivec[6] = (uchar)(local_30 >> 8);
      }
      pbVar10 = ivec + uStack_78;
      bVar2 = *pbStack_60;
      pbStack_5c = pbVar11 + 1;
      bVar3 = *pbVar10;
      in = (uchar *)(uint)bVar3;
      lStack_64 = lStack_64 + -1;
      pbStack_60 = pbStack_60 + 1;
      uStack_78 = uStack_78 + 1 & 7;
      bVar2 = bVar2 ^ bVar3;
      *pbVar11 = bVar2;
      *pbVar10 = bVar2;
      puVar18 = local_40;
      pbVar11 = pbStack_5c;
    } while (lStack_64 != 0);
  }
  iVar5 = *(int *)puStack_68;
  *num = uStack_78;
  if (local_2c == iVar5) {
    return;
  }
  pcStack_54 = BF_ofb64_encrypt;
  (*(code *)puVar18[-0x14cc])();
  puStack_f4 = local_40;
  puStack_100 = PTR___stack_chk_guard_006a9ae8;
  puVar19 = &_gp;
  pBStack_70 = schedule;
  puStack_58 = unaff_s8;
  piStack_6c = num;
  puStack_74 = ivec;
  puStack_a0 = &_gp;
  uStack_8c = *local_40;
  puStack_94 = puStack_3c;
  uStack_88 = local_40[1];
  uStack_bc = *puStack_3c;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  abStack_84[3] = (char)uStack_8c;
  abStack_84[0] = (byte)(uStack_8c >> 0x18);
  pbStack_158 = (byte *)(uStack_88 >> 0x18);
  abStack_84[1] = (char)(uStack_8c >> 0x10);
  puStack_110 = (undefined *)(uStack_88 >> 0x10);
  abStack_84[2] = (char)(uStack_8c >> 8);
  uStack_80 = (char)(uStack_88 >> 0x18);
  uStack_7f = (char)(uStack_88 >> 0x10);
  uStack_7e = (char)(uStack_88 >> 8);
  uStack_7d = (char)uStack_88;
  if ((uchar *)length != (uchar *)0x0) {
    unaff_s8 = (uint *)0x0;
    num = (int *)&uStack_8c;
    ivec = (uchar *)length;
    pBVar17 = (BF_KEY *)out;
    do {
      if (uStack_bc == 0) {
        unaff_s8 = (uint *)((int)unaff_s8 + 1);
        (**(code **)(puVar19 + -0x68f4))(num,pBStack_108);
        length = uStack_8c >> 0x10;
        abStack_84[3] = (char)uStack_8c;
        puStack_110 = (undefined *)(uStack_88 >> 0x18);
        uStack_7d = (char)uStack_88;
        abStack_84[0] = (byte)(uStack_8c >> 0x18);
        abStack_84[1] = (char)(uStack_8c >> 0x10);
        uStack_80 = (char)(uStack_88 >> 0x18);
        abStack_84[2] = (char)(uStack_8c >> 8);
        uStack_7f = (char)(uStack_88 >> 0x10);
        uStack_7e = (char)(uStack_88 >> 8);
        puVar19 = puStack_a0;
      }
      out = (uchar *)((int)pBVar17->P + 1);
      bVar2 = *in;
      ivec = ivec + -1;
      pbVar11 = abStack_84 + uStack_bc;
      in = in + 1;
      uStack_bc = uStack_bc + 1 & 7;
      *(byte *)pBVar17->P = bVar2 ^ *pbVar11;
      pBVar17 = (BF_KEY *)out;
    } while (ivec != (uchar *)0x0);
    if (unaff_s8 != (uint *)0x0) {
      length = uStack_8c >> 0x10;
      *(char *)((int)puStack_f4 + 3) = (char)uStack_8c;
      puStack_110 = (undefined *)(uStack_88 >> 0x18);
      *(char *)((int)puStack_f4 + 7) = (char)uStack_88;
      *(char *)puStack_f4 = (char)(uStack_8c >> 0x18);
      *(char *)((int)puStack_f4 + 1) = (char)(uStack_8c >> 0x10);
      *(char *)(puStack_f4 + 1) = (char)(uStack_88 >> 0x18);
      *(char *)((int)puStack_f4 + 2) = (char)(uStack_8c >> 8);
      *(char *)((int)puStack_f4 + 5) = (char)(uStack_88 >> 0x10);
      *(char *)((int)puStack_f4 + 6) = (char)(uStack_88 >> 8);
    }
  }
  iVar5 = *(int *)puStack_100;
  *puStack_94 = uStack_bc;
  if (iStack_7c == iVar5) {
    return;
  }
  uStack_b4 = 0x622408;
  puVar18 = puStack_94;
  (**(code **)(puVar19 + -0x5330))();
  puStack_10c = PTR___stack_chk_guard_006a9ae8;
  puStack_d8 = (uint *)&_gp;
  uStack_cc = *puVar18;
  uStack_c8 = puVar18[1];
  pbStack_c4 = *(byte **)PTR___stack_chk_guard_006a9ae8;
  puStack_b8 = ivec;
  if (pbStack_158 == (byte *)0x0) {
    (*(code *)PTR_CAST_decrypt_006a98c8)(&uStack_cc);
  }
  else {
    (*(code *)PTR_CAST_encrypt_006a98cc)(&uStack_cc,length);
  }
  puStack_110[3] = (char)uStack_cc;
  puStack_110[7] = (char)uStack_c8;
  *puStack_110 = (char)(uStack_cc >> 0x18);
  uVar13 = uStack_c8 >> 0x18;
  puStack_110[1] = (char)(uStack_cc >> 0x10);
  pbVar11 = (byte *)(uStack_c8 >> 0x10);
  puStack_110[2] = (char)(uStack_cc >> 8);
  puStack_110[4] = (char)(uStack_c8 >> 0x18);
  puStack_110[5] = (char)(uStack_c8 >> 0x10);
  puStack_110[6] = (char)(uStack_c8 >> 8);
  if (pbStack_c4 == *(byte **)puStack_10c) {
    return;
  }
  uStack_ec = 0x6224ec;
  pbVar10 = pbStack_c4;
  (*(code *)puStack_d8[-0x14cc])();
  puStack_15c = puStack_d8;
  puStack_150 = PTR___stack_chk_guard_006a9ae8;
  puVar18 = (uint *)&_gp;
  puStack_128 = (uint *)&_gp;
  iStack_114 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_160 = *puStack_d4;
  pbVar14 = pbStack_158;
  uStack_14c = uVar13;
  pbStack_148 = pbVar10;
  pbStack_144 = pbVar11;
  puStack_104 = (uint *)num;
  pbStack_fc = in;
  pBStack_f8 = (BF_KEY *)out;
  puStack_f0 = unaff_s8;
  if (iStack_d0 == 0) {
    for (; puStack_140 = &uStack_11c, uStack_14c != 0; uStack_14c = uStack_14c - 1) {
      pbVar11 = pbStack_158;
      if (uStack_160 == 0) {
        uStack_11c = *puStack_15c;
        uStack_118 = puStack_15c[1];
        (**(code **)((int)puVar18 + -0x5514))(&uStack_11c);
        uVar13 = uStack_11c >> 0x10;
        *(char *)((int)puStack_15c + 3) = (char)uStack_11c;
        pbVar11 = (byte *)(uStack_118 >> 0x18);
        *(char *)((int)puStack_15c + 7) = (char)uStack_118;
        *(char *)puStack_15c = (char)(uStack_11c >> 0x18);
        *(char *)((int)puStack_15c + 1) = (char)(uStack_11c >> 0x10);
        *(char *)(puStack_15c + 1) = (char)(uStack_118 >> 0x18);
        *(char *)((int)puStack_15c + 2) = (char)(uStack_11c >> 8);
        *(char *)((int)puStack_15c + 5) = (char)(uStack_118 >> 0x10);
        *(char *)((int)puStack_15c + 6) = (char)(uStack_118 >> 8);
        puVar18 = puStack_128;
      }
      bVar2 = *pbStack_148;
      bVar3 = *(byte *)((int)puStack_15c + uStack_160);
      pbVar10 = (byte *)(uint)bVar3;
      *(byte *)((int)puStack_15c + uStack_160) = bVar2;
      pbStack_148 = pbStack_148 + 1;
      uStack_160 = uStack_160 + 1 & 7;
      *pbStack_144 = bVar2 ^ bVar3;
      pbStack_144 = pbStack_144 + 1;
    }
  }
  else {
    puStack_140 = unaff_s8;
    if (uVar13 != 0) {
      puStack_140 = &uStack_11c;
      pbVar1 = pbVar11;
      do {
        if (uStack_160 == 0) {
          uStack_11c = *puStack_15c;
          uStack_118 = puStack_15c[1];
          (*(code *)puStack_128[-0x1545])(puStack_140,pbStack_158);
          uVar13 = uStack_11c >> 0x10;
          *(char *)((int)puStack_15c + 3) = (char)uStack_11c;
          pbVar11 = (byte *)(uStack_118 >> 0x18);
          *(char *)((int)puStack_15c + 7) = (char)uStack_118;
          *(char *)puStack_15c = (char)(uStack_11c >> 0x18);
          *(char *)((int)puStack_15c + 1) = (char)(uStack_11c >> 0x10);
          *(char *)(puStack_15c + 1) = (char)(uStack_118 >> 0x18);
          *(char *)((int)puStack_15c + 2) = (char)(uStack_11c >> 8);
          *(char *)((int)puStack_15c + 5) = (char)(uStack_118 >> 0x10);
          *(char *)((int)puStack_15c + 6) = (char)(uStack_118 >> 8);
        }
        pbVar9 = (byte *)((int)puStack_15c + uStack_160);
        bVar2 = *pbStack_148;
        pbStack_144 = pbVar1 + 1;
        bVar3 = *pbVar9;
        pbVar10 = (byte *)(uint)bVar3;
        uStack_14c = uStack_14c - 1;
        pbStack_148 = pbStack_148 + 1;
        uStack_160 = uStack_160 + 1 & 7;
        bVar2 = bVar2 ^ bVar3;
        *pbVar1 = bVar2;
        *pbVar9 = bVar2;
        puVar18 = puStack_128;
        pbVar1 = pbStack_144;
      } while (uStack_14c != 0);
    }
  }
  iVar5 = *(int *)puStack_150;
  *puStack_d4 = uStack_160;
  if (iStack_114 == iVar5) {
    return;
  }
  pcStack_13c = CAST_ofb64_encrypt;
  (*(code *)puVar18[-0x14cc])();
  puVar18 = puStack_128;
  puVar19 = PTR___stack_chk_guard_006a9ae8;
  puStack_154 = puStack_d4;
  uStack_174 = *puStack_128;
  uStack_170 = puStack_128[1];
  uVar15 = *puStack_124;
  iStack_164 = *(int *)PTR___stack_chk_guard_006a9ae8;
  abStack_16c[3] = (char)uStack_174;
  abStack_16c[0] = (byte)(uStack_174 >> 0x18);
  abStack_16c[1] = (char)(uStack_174 >> 0x10);
  uVar12 = uStack_170 >> 0x10;
  abStack_16c[2] = (char)(uStack_174 >> 8);
  uStack_168 = (char)(uStack_170 >> 0x18);
  uStack_167 = (char)(uStack_170 >> 0x10);
  uStack_166 = (char)(uStack_170 >> 8);
  uStack_165 = (char)uStack_170;
  if (uVar13 != 0) {
    iVar5 = 0;
    uVar16 = uVar13;
    do {
      if (uVar15 == 0) {
        iVar5 = iVar5 + 1;
        (*(code *)PTR_CAST_encrypt_006a98cc)(&uStack_174,pbVar14);
        uVar13 = uStack_174 >> 0x10;
        abStack_16c[3] = (char)uStack_174;
        uVar12 = uStack_170 >> 0x18;
        uStack_165 = (char)uStack_170;
        abStack_16c[0] = (byte)(uStack_174 >> 0x18);
        abStack_16c[1] = (char)(uStack_174 >> 0x10);
        uStack_168 = (char)(uStack_170 >> 0x18);
        abStack_16c[2] = (char)(uStack_174 >> 8);
        uStack_167 = (char)(uStack_170 >> 0x10);
        uStack_166 = (char)(uStack_170 >> 8);
      }
      bVar2 = *pbVar10;
      uVar16 = uVar16 - 1;
      pbVar1 = abStack_16c + uVar15;
      pbVar10 = pbVar10 + 1;
      uVar15 = uVar15 + 1 & 7;
      *pbVar11 = bVar2 ^ *pbVar1;
      pbVar11 = pbVar11 + 1;
    } while (uVar16 != 0);
    if (iVar5 != 0) {
      uVar13 = uStack_174 >> 0x10;
      *(char *)((int)puVar18 + 3) = (char)uStack_174;
      uVar12 = uStack_170 >> 0x18;
      *(char *)((int)puVar18 + 7) = (char)uStack_170;
      *(char *)puVar18 = (char)(uStack_174 >> 0x18);
      *(char *)((int)puVar18 + 1) = (char)(uStack_174 >> 0x10);
      *(char *)(puVar18 + 1) = (char)(uStack_170 >> 0x18);
      *(char *)((int)puVar18 + 2) = (char)(uStack_174 >> 8);
      *(char *)((int)puVar18 + 5) = (char)(uStack_170 >> 0x10);
      *(char *)((int)puVar18 + 6) = (char)(uStack_170 >> 8);
    }
  }
  iVar5 = *(int *)puVar19;
  *puStack_124 = uVar15;
  if (iStack_164 == iVar5) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_BN_CTX_start_006a8528)(uVar13);
  ppuVar6 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(uVar13);
  ppuVar7 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(uVar13);
  if (ppuVar7 == (uint **)0x0) {
    (*(code *)PTR_BN_CTX_end_006a8530)(uVar13);
    return;
  }
  iVar5 = (*(code *)PTR_BN_copy_006a8450)(ppuVar6,puStack_124);
  if (iVar5 == 0) {
LAB_00622a04:
    (*(code *)PTR_BN_CTX_end_006a8530)(uVar13);
    return;
  }
  iVar5 = (*(code *)PTR_BN_copy_006a8450)(ppuVar7,uVar12);
  if (iVar5 != 0) {
    if (ppuVar7[1] != (uint *)0x0) {
      if (((int)ppuVar6[1] < 1) || (iVar5 = 0, (**ppuVar6 & 1) == 0)) {
        if (((int)ppuVar7[1] < 1) || ((**ppuVar7 & 1) == 0)) goto LAB_006229cc;
        iVar5 = 0;
      }
      while (iVar8 = (*(code *)PTR_BN_is_bit_set_006a8538)(ppuVar7,iVar5), iVar8 == 0) {
        iVar5 = iVar5 + 1;
      }
      iVar5 = (*(code *)PTR_BN_rshift_006a85d4)(ppuVar7,ppuVar7,iVar5);
      if (iVar5 != 0) {
        puVar18 = ppuVar6[1];
        if (ppuVar7[3] != (uint *)0x0) {
          ppuVar7[3] = (uint *)0x0;
        }
        while (ppuVar4 = ppuVar6, puVar18 != (uint *)0x0) {
          iVar5 = 0;
          while (iVar8 = (*(code *)PTR_BN_is_bit_set_006a8538)(ppuVar4,iVar5), iVar8 == 0) {
            iVar5 = iVar5 + 1;
          }
          iVar5 = (*(code *)PTR_BN_rshift_006a85d4)(ppuVar4,ppuVar4,iVar5);
          if (iVar5 == 0) goto LAB_00622a04;
          iVar5 = (*(code *)PTR_BN_nnmod_006a8548)(ppuVar7,ppuVar7,ppuVar4,uVar13);
          if (iVar5 == 0) break;
          puVar18 = ppuVar7[1];
          ppuVar4[3] = (uint *)0x0;
          ppuVar6 = ppuVar7;
          ppuVar7 = ppuVar4;
        }
      }
    }
  }
LAB_006229cc:
  (*(code *)PTR_BN_CTX_end_006a8530)(uVar13);
  return;
}

