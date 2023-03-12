
void RC2_cfb64_encrypt(uchar *in,uchar *out,long length,RC2_KEY *schedule,uchar *ivec,int *num,
                      int enc)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint *puVar8;
  byte *pbVar9;
  uint uVar10;
  RC2_KEY *pRVar11;
  byte *pbVar12;
  uint *puVar13;
  undefined4 *puVar14;
  uint *unaff_s8;
  undefined4 uStack_13c;
  uint uStack_138;
  byte abStack_134 [4];
  undefined uStack_130;
  undefined uStack_12f;
  undefined uStack_12e;
  undefined uStack_12d;
  int iStack_12c;
  uint uStack_128;
  uint *puStack_124;
  byte *pbStack_120;
  uint *puStack_11c;
  undefined *puStack_118;
  uchar *puStack_114;
  uint *puStack_110;
  byte *pbStack_10c;
  uint *puStack_108;
  code *pcStack_104;
  undefined4 *puStack_f0;
  uint *puStack_ec;
  uint uStack_e4;
  uint uStack_e0;
  int iStack_dc;
  uint uStack_d8;
  uchar *puStack_d4;
  RC2_KEY *pRStack_d0;
  RC2_KEY *pRStack_cc;
  undefined *puStack_c8;
  byte *pbStack_c4;
  RC2_KEY *pRStack_c0;
  byte *pbStack_bc;
  uint *puStack_b8;
  undefined4 uStack_b4;
  uint *puStack_a0;
  uint *puStack_9c;
  int iStack_98;
  uint *puStack_94;
  uint uStack_8c;
  uint uStack_88;
  byte abStack_84 [4];
  byte bStack_80;
  byte bStack_7f;
  byte bStack_7e;
  byte bStack_7d;
  uint uStack_7c;
  uint uStack_78;
  uchar *puStack_74;
  uint uStack_70;
  RC2_KEY *pRStack_6c;
  int *piStack_68;
  undefined *puStack_64;
  byte *pbStack_60;
  byte *pbStack_5c;
  uint *puStack_58;
  code *pcStack_54;
  byte *local_40;
  uint *puStack_3c;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  puStack_64 = PTR___stack_chk_guard_006a9ae8;
  pbVar12 = &_gp;
  local_40 = &_gp;
  local_2c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  uStack_78 = *num;
  pRStack_d0 = schedule;
  uStack_70 = length;
  pbStack_60 = in;
  pbStack_5c = out;
  if (enc == 0) {
    unaff_s8 = &local_34;
    pbVar9 = out;
    if (length != 0) {
      do {
        out = (uchar *)schedule;
        if (uStack_78 == 0) {
          pRStack_d0 = (RC2_KEY *)((uint)ivec[1] << 8 | (uint)ivec[2] << 0x10);
          local_34 = (uint)ivec[3] << 0x18 | (uint)pRStack_d0 | (uint)*ivec;
          local_30 = (uint)ivec[7] << 0x18 |
                     (uint)ivec[5] << 8 | (uint)ivec[6] << 0x10 | (uint)ivec[4];
          (**(code **)(pbVar12 + -0x5764))(unaff_s8);
          length = local_34 >> 0x10;
          *ivec = (uchar)local_34;
          out = (uchar *)(local_30 >> 8);
          ivec[4] = (uchar)local_30;
          ivec[1] = (uchar)(local_34 >> 8);
          ivec[2] = (uchar)(local_34 >> 0x10);
          ivec[5] = (uchar)(local_30 >> 8);
          ivec[3] = (uchar)(local_34 >> 0x18);
          ivec[6] = (uchar)(local_30 >> 0x10);
          ivec[7] = (uchar)(local_30 >> 0x18);
          pbVar12 = local_40;
        }
        bVar2 = *pbStack_60;
        bVar3 = ivec[uStack_78];
        in = (uchar *)(uint)bVar3;
        uStack_70 = uStack_70 - 1;
        ivec[uStack_78] = bVar2;
        pbStack_60 = pbStack_60 + 1;
        uStack_78 = uStack_78 + 1 & 7;
        *pbVar9 = bVar2 ^ bVar3;
        pbStack_5c = pbVar9 + 1;
        pbVar9 = pbVar9 + 1;
      } while (uStack_70 != 0);
    }
  }
  else if (length != 0) {
    unaff_s8 = &local_34;
    pbVar9 = out;
    do {
      if (uStack_78 == 0) {
        pRStack_d0 = (RC2_KEY *)((uint)ivec[1] << 8 | (uint)ivec[2] << 0x10);
        local_34 = (uint)ivec[3] << 0x18 | (uint)pRStack_d0 | (uint)*ivec;
        local_30 = (uint)ivec[7] << 0x18 |
                   (uint)ivec[5] << 8 | (uint)ivec[6] << 0x10 | (uint)ivec[4];
        (**(code **)(local_40 + -0x5764))(unaff_s8,schedule);
        length = local_34 >> 0x10;
        *ivec = (uchar)local_34;
        out = (uchar *)(local_30 >> 8);
        ivec[4] = (uchar)local_30;
        ivec[1] = (uchar)(local_34 >> 8);
        ivec[2] = (uchar)(local_34 >> 0x10);
        ivec[5] = (uchar)(local_30 >> 8);
        ivec[3] = (uchar)(local_34 >> 0x18);
        ivec[6] = (uchar)(local_30 >> 0x10);
        ivec[7] = (uchar)(local_30 >> 0x18);
      }
      pbVar12 = ivec + uStack_78;
      bVar2 = *pbStack_60;
      pbStack_5c = pbVar9 + 1;
      bVar3 = *pbVar12;
      in = (uchar *)(uint)bVar3;
      uStack_70 = uStack_70 - 1;
      pbStack_60 = pbStack_60 + 1;
      uStack_78 = uStack_78 + 1 & 7;
      bVar2 = bVar2 ^ bVar3;
      *pbVar9 = bVar2;
      *pbVar12 = bVar2;
      pbVar12 = local_40;
      pbVar9 = pbStack_5c;
    } while (uStack_70 != 0);
  }
  uVar5 = *(uint *)puStack_64;
  *num = uStack_78;
  if (local_2c == uVar5) {
    return;
  }
  pcStack_54 = RC2_ofb64_encrypt;
  (**(code **)(pbVar12 + -0x5330))();
  pbStack_bc = local_40;
  puStack_c8 = PTR___stack_chk_guard_006a9ae8;
  puVar13 = (uint *)&_gp;
  piStack_68 = num;
  puStack_58 = unaff_s8;
  pRStack_6c = schedule;
  puStack_74 = ivec;
  puStack_a0 = (uint *)&_gp;
  pbStack_120 = (byte *)(uint)local_40[3];
  puStack_94 = puStack_3c;
  uStack_d8 = *puStack_3c;
  uStack_7c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  uStack_8c = (int)pbStack_120 << 0x18 |
              (uint)local_40[1] << 8 | (uint)local_40[2] << 0x10 | (uint)*local_40;
  uStack_88 = (uint)local_40[7] << 0x18 |
              (uint)local_40[5] << 8 | (uint)local_40[6] << 0x10 | (uint)local_40[4];
  abStack_84[0] = *local_40;
  abStack_84[2] = local_40[2];
  pbVar12 = (byte *)(uStack_88 >> 8);
  abStack_84[1] = local_40[1];
  abStack_84[3] = local_40[3];
  bStack_80 = local_40[4];
  bStack_7f = local_40[5];
  bStack_7e = local_40[6];
  bStack_7d = local_40[7];
  if ((uchar *)length != (uchar *)0x0) {
    unaff_s8 = (uint *)0x0;
    schedule = (RC2_KEY *)&uStack_8c;
    ivec = (uchar *)length;
    pRVar11 = (RC2_KEY *)out;
    do {
      if (uStack_d8 == 0) {
        unaff_s8 = (uint *)((int)unaff_s8 + 1);
        (**(code **)((int)puVar13 + -0x5764))(schedule,pRStack_d0);
        length = uStack_8c >> 0x10;
        abStack_84[0] = (byte)uStack_8c;
        pbVar12 = (byte *)(uStack_88 >> 8);
        bStack_80 = (byte)uStack_88;
        abStack_84[1] = (byte)(uStack_8c >> 8);
        abStack_84[2] = (byte)(uStack_8c >> 0x10);
        bStack_7f = (byte)(uStack_88 >> 8);
        abStack_84[3] = (byte)(uStack_8c >> 0x18);
        bStack_7e = (byte)(uStack_88 >> 0x10);
        bStack_7d = (byte)(uStack_88 >> 0x18);
        puVar13 = puStack_a0;
      }
      out = (uchar *)((int)pRVar11->data + 1);
      bVar2 = *in;
      ivec = ivec + -1;
      pbVar9 = abStack_84 + uStack_d8;
      in = in + 1;
      uStack_d8 = uStack_d8 + 1 & 7;
      *(byte *)pRVar11->data = bVar2 ^ *pbVar9;
      pRVar11 = (RC2_KEY *)out;
    } while (ivec != (uchar *)0x0);
    if (unaff_s8 != (uint *)0x0) {
      length = uStack_8c >> 0x10;
      *pbStack_bc = (byte)uStack_8c;
      pbVar12 = (byte *)(uStack_88 >> 8);
      pbStack_bc[4] = (byte)uStack_88;
      pbStack_bc[1] = (byte)(uStack_8c >> 8);
      pbStack_bc[2] = (byte)(uStack_8c >> 0x10);
      pbStack_bc[5] = (byte)(uStack_88 >> 8);
      pbStack_bc[3] = (byte)(uStack_8c >> 0x18);
      pbStack_bc[6] = (byte)(uStack_88 >> 0x10);
      pbStack_bc[7] = (byte)(uStack_88 >> 0x18);
    }
  }
  uVar5 = *(uint *)puStack_c8;
  *puStack_94 = uStack_d8;
  if (uStack_7c != uVar5) {
    uStack_b4 = 0x5e6858;
    puVar8 = puStack_94;
    (**(code **)((int)puVar13 + -0x5330))();
    puStack_124 = puStack_a0;
    puStack_118 = PTR___stack_chk_guard_006a9ae8;
    puVar14 = (undefined4 *)&_gp;
    puStack_f0 = (undefined4 *)&_gp;
    iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
    uStack_128 = *puStack_9c;
    pbVar9 = pbStack_120;
    puStack_114 = (uchar *)length;
    puStack_110 = puVar8;
    pbStack_10c = pbVar12;
    puStack_d4 = ivec;
    pRStack_cc = schedule;
    pbStack_c4 = in;
    pRStack_c0 = (RC2_KEY *)out;
    puStack_b8 = unaff_s8;
    if (iStack_98 == 0) {
      for (; puStack_108 = &uStack_e4, puStack_114 != (uchar *)0x0; puStack_114 = puStack_114 + -1)
      {
        pbVar12 = pbStack_120;
        if (uStack_128 == 0) {
          uStack_e4 = *puStack_124;
          uStack_e0 = puStack_124[1];
          (**(code **)((int)puVar14 + -0x68f8))(&uStack_e4);
          length = uStack_e4 >> 0x10;
          *(char *)((int)puStack_124 + 3) = (char)uStack_e4;
          pbVar12 = (byte *)(uStack_e0 >> 0x18);
          *(char *)((int)puStack_124 + 7) = (char)uStack_e0;
          *(char *)puStack_124 = (char)(uStack_e4 >> 0x18);
          *(char *)((int)puStack_124 + 1) = (char)(uStack_e4 >> 0x10);
          *(char *)(puStack_124 + 1) = (char)(uStack_e0 >> 0x18);
          *(char *)((int)puStack_124 + 2) = (char)(uStack_e4 >> 8);
          *(char *)((int)puStack_124 + 5) = (char)(uStack_e0 >> 0x10);
          *(char *)((int)puStack_124 + 6) = (char)(uStack_e0 >> 8);
          puVar14 = puStack_f0;
        }
        bVar2 = *(byte *)puStack_110;
        bVar3 = *(byte *)((int)puStack_124 + uStack_128);
        puVar8 = (uint *)(uint)bVar3;
        *(byte *)((int)puStack_124 + uStack_128) = bVar2;
        puStack_110 = (uint *)((int)puStack_110 + 1);
        uStack_128 = uStack_128 + 1 & 7;
        *pbStack_10c = bVar2 ^ bVar3;
        pbStack_10c = pbStack_10c + 1;
      }
    }
    else {
      puStack_108 = unaff_s8;
      if ((uchar *)length != (uchar *)0x0) {
        puStack_108 = &uStack_e4;
        pbVar1 = pbVar12;
        do {
          if (uStack_128 == 0) {
            uStack_e4 = *puStack_124;
            uStack_e0 = puStack_124[1];
            (*(code *)puStack_f0[-0x1a3e])(puStack_108,pbStack_120);
            length = uStack_e4 >> 0x10;
            *(char *)((int)puStack_124 + 3) = (char)uStack_e4;
            pbVar12 = (byte *)(uStack_e0 >> 0x18);
            *(char *)((int)puStack_124 + 7) = (char)uStack_e0;
            *(char *)puStack_124 = (char)(uStack_e4 >> 0x18);
            *(char *)((int)puStack_124 + 1) = (char)(uStack_e4 >> 0x10);
            *(char *)(puStack_124 + 1) = (char)(uStack_e0 >> 0x18);
            *(char *)((int)puStack_124 + 2) = (char)(uStack_e4 >> 8);
            *(char *)((int)puStack_124 + 5) = (char)(uStack_e0 >> 0x10);
            *(char *)((int)puStack_124 + 6) = (char)(uStack_e0 >> 8);
          }
          pbVar7 = (byte *)((int)puStack_124 + uStack_128);
          bVar2 = *(byte *)puStack_110;
          pbStack_10c = pbVar1 + 1;
          bVar3 = *pbVar7;
          puVar8 = (uint *)(uint)bVar3;
          puStack_114 = puStack_114 + -1;
          puStack_110 = (uint *)((int)puStack_110 + 1);
          uStack_128 = uStack_128 + 1 & 7;
          bVar2 = bVar2 ^ bVar3;
          *pbVar1 = bVar2;
          *pbVar7 = bVar2;
          puVar14 = puStack_f0;
          pbVar1 = pbStack_10c;
        } while (puStack_114 != (uchar *)0x0);
      }
    }
    iVar6 = *(int *)puStack_118;
    *puStack_9c = uStack_128;
    if (iStack_dc != iVar6) {
      pcStack_104 = idea_ofb64_encrypt;
      (*(code *)puVar14[-0x14cc])();
      puVar14 = puStack_f0;
      puVar4 = PTR___stack_chk_guard_006a9ae8;
      puStack_11c = puStack_9c;
      uStack_13c = *puStack_f0;
      uStack_138 = puStack_f0[1];
      uVar10 = *puStack_ec;
      iStack_12c = *(int *)PTR___stack_chk_guard_006a9ae8;
      abStack_134[3] = (char)uStack_13c;
      abStack_134[0] = (byte)((uint)uStack_13c >> 0x18);
      uVar5 = uStack_138 >> 0x18;
      abStack_134[1] = (char)((uint)uStack_13c >> 0x10);
      abStack_134[2] = (char)((uint)uStack_13c >> 8);
      uStack_130 = (char)(uStack_138 >> 0x18);
      uStack_12f = (char)(uStack_138 >> 0x10);
      uStack_12e = (char)(uStack_138 >> 8);
      uStack_12d = (char)uStack_138;
      if ((uchar *)length != (uchar *)0x0) {
        iVar6 = 0;
        do {
          if (uVar10 == 0) {
            iVar6 = iVar6 + 1;
            (*(code *)PTR_idea_encrypt_006a84e8)(&uStack_13c,pbVar9);
            abStack_134[3] = (char)uStack_13c;
            uStack_12d = (char)uStack_138;
            abStack_134[0] = (byte)((uint)uStack_13c >> 0x18);
            abStack_134[1] = (char)((uint)uStack_13c >> 0x10);
            uStack_130 = (char)(uStack_138 >> 0x18);
            abStack_134[2] = (char)((uint)uStack_13c >> 8);
            uStack_12f = (char)(uStack_138 >> 0x10);
            uStack_12e = (char)(uStack_138 >> 8);
          }
          bVar2 = *(byte *)puVar8;
          length = length + -1;
          pbVar1 = abStack_134 + uVar10;
          puVar8 = (uint *)((int)puVar8 + 1);
          uVar10 = uVar10 + 1 & 7;
          *pbVar12 = bVar2 ^ *pbVar1;
          pbVar12 = pbVar12 + 1;
        } while ((uchar *)length != (uchar *)0x0);
        if (iVar6 != 0) {
          *(char *)((int)puVar14 + 3) = (char)uStack_13c;
          *(char *)((int)puVar14 + 7) = (char)uStack_138;
          *(char *)puVar14 = (char)((uint)uStack_13c >> 0x18);
          *(char *)((int)puVar14 + 1) = (char)((uint)uStack_13c >> 0x10);
          *(char *)(puVar14 + 1) = (char)(uStack_138 >> 0x18);
          *(char *)((int)puVar14 + 2) = (char)((uint)uStack_13c >> 8);
          *(char *)((int)puVar14 + 5) = (char)(uStack_138 >> 0x10);
          *(char *)((int)puVar14 + 6) = (char)(uStack_138 >> 8);
        }
      }
      iVar6 = *(int *)puVar4;
      *puStack_ec = uVar10;
      if (iStack_12c == iVar6) {
        return;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      if (uVar5 != 1) {
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
  return;
}

