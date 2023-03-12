
void BF_cbc_encrypt(uchar *in,uchar *out,long length,BF_KEY *schedule,uchar *ivec,int enc)

{
  bool bVar1;
  int *piVar2;
  undefined *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar uVar7;
  BF_KEY *pBVar6;
  uchar uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  BF_KEY *pBVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  uint uVar16;
  uchar uVar18;
  uint uVar17;
  uchar *in_t0;
  uchar uVar19;
  uchar uVar22;
  uint uVar20;
  int iVar21;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  uint uVar30;
  uint uVar31;
  int iVar32;
  uint uVar33;
  int iVar34;
  uchar *unaff_s0;
  uchar *unaff_s1;
  uint uVar35;
  uchar **unaff_s4;
  int iVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  int iVar42;
  uchar *unaff_s6;
  int iVar43;
  uint uVar44;
  uchar *unaff_s7;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  uint uVar49;
  uint uVar50;
  uint uVar51;
  uint uVar52;
  uint uVar53;
  uchar *unaff_s8;
  uint *puStack_1ac;
  int iStack_1a4;
  int iStack_19c;
  uint uStack_198;
  uint uStack_194;
  uint uStack_154;
  uint uStack_150;
  uint uStack_14c;
  uint uStack_148;
  uint uStack_144;
  uint uStack_140;
  uint uStack_13c;
  uint uStack_138;
  uint uStack_134;
  uint uStack_130;
  uint uStack_12c;
  uint uStack_128;
  uint uStack_124;
  uint uStack_120;
  uint uStack_11c;
  uint uStack_118;
  uint uStack_114;
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  uint uStack_104;
  uint uStack_100;
  uint uStack_fc;
  uint uStack_f8;
  uint uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint uStack_e8;
  uint uStack_e4;
  int *piStack_e0;
  uint *puStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  int iStack_b4;
  int iStack_b0;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  int iStack_98;
  int iStack_94;
  uchar *puStack_90;
  uchar *puStack_8c;
  uchar *puStack_88;
  BF_KEY *pBStack_84;
  uchar **ppuStack_80;
  uchar *puStack_7c;
  uchar *puStack_78;
  uchar *puStack_74;
  uchar *puStack_70;
  code *pcStack_6c;
  undefined *local_58;
  uchar *local_4c;
  uchar **local_48;
  uchar *local_44;
  int *local_40;
  uchar *local_3c;
  uchar *local_34;
  uchar *local_30;
  int local_2c;
  
  local_40 = (int *)PTR___stack_chk_guard_006aabf0;
  local_58 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_7c = (uchar *)(length + -8);
  local_48 = (uchar **)in;
  local_44 = out;
  if (enc != 0) {
    puVar4 = *(uchar **)(ivec + 4);
    puVar5 = *(uchar **)ivec;
    puStack_90 = unaff_s0;
    local_3c = puStack_7c;
    if (-1 < (int)puStack_7c) {
      unaff_s4 = &local_34;
      local_30 = *(uchar **)(ivec + 4);
      local_34 = *(uchar **)ivec;
      do {
        uVar11 = (uint)in & 3;
        piVar2 = (int *)(in + -uVar11);
        puVar10 = (uint *)(in + 4);
        unaff_s1 = out + 8;
        puStack_7c = puStack_7c + -8;
        puVar4 = in + 3;
        uVar13 = (uint)puVar4 & 3;
        in = in + 8;
        local_34 = (uchar *)(((*piVar2 << uVar11 * 8 | (uint)in_t0 & 0xffffffffU >> (4 - uVar11) * 8
                              ) & -1 << (uVar13 + 1) * 8 |
                             *(uint *)(puVar4 + -uVar13) >> (3 - uVar13) * 8) ^ (uint)local_34);
        local_30 = (uchar *)(*puVar10 ^ (uint)local_30);
        BF_encrypt((uint *)unaff_s4,schedule);
        out[3] = (uchar)local_34;
        in_t0 = (uchar *)((uint)local_34 >> 8);
        out[7] = (uchar)local_30;
        *out = (uchar)((uint)local_34 >> 0x18);
        out[1] = (uchar)((uint)local_34 >> 0x10);
        out[2] = (uchar)((uint)local_34 >> 8);
        out[4] = (uchar)((uint)local_30 >> 0x18);
        out[5] = (uchar)((uint)local_30 >> 0x10);
        out[6] = (uchar)((uint)local_30 >> 8);
        out = unaff_s1;
      } while (-1 < (int)puStack_7c);
      unaff_s7 = (uchar *)(length + -0x10);
      unaff_s6 = (uchar *)((uint)local_3c & 0xfffffff8);
      iVar9 = (((uint)local_3c >> 3) + 1) * 8;
      puStack_7c = unaff_s7 + -(int)unaff_s6;
      local_48 = (uchar **)((int)local_48 + iVar9);
      local_44 = local_44 + iVar9;
      puVar4 = local_30;
      puVar5 = local_34;
      puStack_90 = in;
    }
    if (puStack_7c == (uchar *)0xfffffff8) {
      uVar22 = (uchar)((uint)puVar5 >> 0x18);
      uVar19 = (uchar)((uint)puVar5 >> 0x10);
      uVar18 = (uchar)((uint)puVar5 >> 8);
      uVar8 = (uchar)puVar5;
      uVar7 = (uchar)puVar4;
    }
    else {
      unaff_s4 = (uchar **)((int)local_48 + (int)(puStack_7c + 8));
      switch(puStack_7c) {
      default:
        uVar13 = 0;
        uVar11 = 0;
        goto LAB_004e7e78;
      case (uchar *)0xfffffff9:
        uVar13 = 0;
        uVar11 = 0;
        goto LAB_004e7e6c;
      case (uchar *)0xfffffffa:
        uVar13 = 0;
        uVar11 = 0;
        goto LAB_004e7e5c;
      case (uchar *)0xfffffffb:
        uVar13 = 0;
        uVar11 = 0;
        goto LAB_004e7e4c;
      case (uchar *)0xfffffffc:
        uVar13 = 0;
        goto LAB_004e7e44;
      case (uchar *)0xfffffffd:
        uVar13 = 0;
        goto LAB_004e7e34;
      case (uchar *)0xfffffffe:
        uVar13 = 0;
        break;
      case (uchar *)0xffffffff:
        pbVar15 = (byte *)((int)unaff_s4 + -1);
        unaff_s4 = (uchar **)((int)unaff_s4 + -1);
        uVar13 = (uint)*pbVar15 << 8;
      }
      pbVar15 = (byte *)((int)unaff_s4 + -1);
      unaff_s4 = (uchar **)((int)unaff_s4 + -1);
      uVar13 = (uint)*pbVar15 << 0x10 | uVar13;
LAB_004e7e34:
      pbVar15 = (byte *)((int)unaff_s4 + -1);
      unaff_s4 = (uchar **)((int)unaff_s4 + -1);
      uVar13 = (uint)*pbVar15 << 0x18 | uVar13;
LAB_004e7e44:
      uVar11 = (uint)*(byte *)((int)unaff_s4 + -1);
      unaff_s4 = (uchar **)((int)unaff_s4 + -1);
LAB_004e7e4c:
      pbVar15 = (byte *)((int)unaff_s4 + -1);
      unaff_s4 = (uchar **)((int)unaff_s4 + -1);
      uVar11 = (uint)*pbVar15 << 8 | uVar11;
LAB_004e7e5c:
      pbVar15 = (byte *)((int)unaff_s4 + -1);
      unaff_s4 = (uchar **)((int)unaff_s4 + -1);
      uVar11 = (uint)*pbVar15 << 0x10 | uVar11;
LAB_004e7e6c:
      uVar11 = (uint)*(byte *)((int)unaff_s4 + -1) << 0x18 | uVar11;
LAB_004e7e78:
      local_34 = (uchar *)(uVar11 ^ (uint)puVar5);
      local_30 = (uchar *)(uVar13 ^ (uint)puVar4);
      BF_encrypt((uint *)&local_34,schedule);
      uVar19 = (uchar)((uint)local_34 >> 0x10);
      uVar18 = (uchar)((uint)local_34 >> 8);
      uVar22 = (uchar)((uint)local_34 >> 0x18);
      *local_44 = uVar22;
      local_44[1] = uVar19;
      local_44[2] = uVar18;
      uVar8 = (uchar)local_34;
      local_44[4] = (uchar)((uint)local_30 >> 0x18);
      uVar7 = (uchar)local_30;
      local_44[5] = (uchar)((uint)local_30 >> 0x10);
      local_44[3] = uVar8;
      local_44[6] = (uchar)((uint)local_30 >> 8);
      local_44[7] = uVar7;
      puVar4 = local_30;
    }
    pBVar12 = (BF_KEY *)((uint)((int)puVar4 << 8) >> 0x18);
    puVar10 = (uint *)((uint)((int)puVar4 << 0x10) >> 0x18);
    pbVar15 = (byte *)((uint)puVar4 >> 0x18);
    *ivec = uVar22;
    ivec[1] = uVar19;
    ivec[2] = uVar18;
    ivec[3] = uVar8;
    ivec[4] = (uchar)((uint)puVar4 >> 0x18);
    ivec[5] = (uchar)((uint)puVar4 >> 0x10);
    ivec[6] = (uchar)((uint)puVar4 >> 8);
    ivec[7] = uVar7;
    puStack_74 = unaff_s7;
    puStack_70 = unaff_s8;
    goto LAB_004e7d94;
  }
  uVar11 = *(uint *)(ivec + 4);
  unaff_s6 = (uchar *)(length + -8);
  puVar4 = *(uchar **)ivec;
  local_3c = unaff_s6;
  if (-1 < (int)unaff_s6) {
    unaff_s4 = &local_34;
    puVar5 = puVar4;
    uVar13 = length;
    uVar41 = uVar11;
    do {
      uVar11 = (uint)in & 3;
      uVar20 = (uint)(in + 4) & 3;
      unaff_s6 = unaff_s6 + -8;
      uVar30 = (uint)(in + 3) & 3;
      puVar4 = (uchar *)((*(int *)(in + -uVar11) << uVar11 * 8 |
                         (uint)in_t0 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar30 + 1) * 8 |
                        *(uint *)(in + 3 + -uVar30) >> (3 - uVar30) * 8);
      uVar11 = (uint)(in + 7) & 3;
      uVar11 = (*(int *)(in + 4 + -uVar20) << uVar20 * 8 | uVar13 & 0xffffffffU >> (4 - uVar20) * 8)
               & -1 << (uVar11 + 1) * 8 | *(uint *)(in + 7 + -uVar11) >> (3 - uVar11) * 8;
      in = in + 8;
      uVar13 = uVar11;
      in_t0 = puVar4;
      local_4c = puVar5;
      local_34 = puVar4;
      local_30 = (uchar *)uVar11;
      BF_decrypt((uint *)unaff_s4,schedule);
      uVar20 = (uint)local_4c ^ (uint)local_34;
      out[3] = (uchar)uVar20;
      uVar41 = uVar41 ^ (uint)local_30;
      *out = (uchar)(uVar20 >> 0x18);
      out[1] = (uchar)(uVar20 >> 0x10);
      out[7] = (uchar)uVar41;
      out[2] = (uchar)(uVar20 >> 8);
      out[4] = (uchar)(uVar41 >> 0x18);
      out[5] = (uchar)(uVar41 >> 0x10);
      out[6] = (uchar)(uVar41 >> 8);
      puVar5 = puVar4;
      out = out + 8;
      uVar41 = uVar11;
    } while (-1 < (int)unaff_s6);
    iVar9 = (((uint)local_3c >> 3) + 1) * 8;
    unaff_s6 = (uchar *)((length + -0x10) - ((uint)local_3c & 0xfffffff8));
    local_48 = (uchar **)((int)local_48 + iVar9);
    local_44 = local_44 + iVar9;
  }
  puStack_90 = *local_48;
  unaff_s1 = local_48[1];
  pBVar12 = schedule;
  local_34 = puStack_90;
  local_30 = unaff_s1;
  BF_decrypt((uint *)&local_34,schedule);
  puStack_7c = local_44 + (int)(unaff_s6 + 8);
  uVar13 = (uint)puVar4 ^ (uint)local_34;
  uVar11 = uVar11 ^ (uint)local_30;
  puVar4 = puStack_7c;
  switch(unaff_s6) {
  default:
    goto switchD_004e7d00_caseD_7;
  case (uchar *)0xfffffff9:
    goto LAB_004e7d4c;
  case (uchar *)0xfffffffa:
    goto switchD_004e7d00_caseD_fffffffa;
  case (uchar *)0xfffffffb:
    goto LAB_004e7d34;
  case (uchar *)0xfffffffc:
    goto switchD_004e7d00_caseD_fffffffc;
  case (uchar *)0xfffffffd:
    break;
  case (uchar *)0xffffffff:
    puVar4 = puStack_7c + -1;
    *puVar4 = (uchar)(uVar11 >> 8);
  case (uchar *)0xfffffffe:
    puStack_7c = puVar4 + -1;
    puVar4[-1] = (uchar)(uVar11 >> 0x10);
  }
  puVar4 = puStack_7c + -1;
  puStack_7c[-1] = (uchar)(uVar11 >> 0x18);
switchD_004e7d00_caseD_fffffffc:
  puStack_7c = puVar4 + -1;
  puVar4[-1] = (uchar)uVar13;
LAB_004e7d34:
  puVar4 = puStack_7c + -1;
  puStack_7c[-1] = (uchar)(uVar13 >> 8);
switchD_004e7d00_caseD_fffffffa:
  puStack_7c = puVar4 + -1;
  puVar4[-1] = (uchar)(uVar13 >> 0x10);
LAB_004e7d4c:
  puStack_7c[-1] = (uchar)(uVar13 >> 0x18);
  puStack_7c = puVar4;
switchD_004e7d00_caseD_7:
  ivec[3] = (uchar)puStack_90;
  puVar10 = (uint *)((uint)puStack_90 >> 0x10);
  ivec[7] = (uchar)unaff_s1;
  *ivec = (uchar)((uint)puStack_90 >> 0x18);
  pbVar15 = (byte *)((uint)unaff_s1 >> 8);
  ivec[1] = (uchar)((uint)puStack_90 >> 0x10);
  ivec[2] = (uchar)((uint)puStack_90 >> 8);
  ivec[4] = (uchar)((uint)unaff_s1 >> 0x18);
  ivec[6] = (uchar)((uint)unaff_s1 >> 8);
  ivec[5] = (uchar)((uint)unaff_s1 >> 0x10);
  puStack_74 = unaff_s1;
  puStack_70 = puStack_90;
LAB_004e7d94:
  if (local_2c == *local_40) {
    return;
  }
  pcStack_6c = CAST_set_key;
  (**(code **)(local_58 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  puStack_88 = ivec;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_8c = unaff_s1;
  pBStack_84 = schedule;
  ppuStack_80 = unaff_s4;
  puStack_78 = unaff_s6;
  (*(code *)PTR_memset_006aab00)(&uStack_154,0,0x40);
  pBVar6 = (BF_KEY *)&SUB_00000010;
  if ((int)pBVar12 < 0x11) {
    pBVar6 = pBVar12;
  }
  if (((((0 < (int)pBVar6) && (uStack_154 = (uint)*pbVar15, pBVar6 != (BF_KEY *)0x1)) &&
       (uStack_150 = (uint)pbVar15[1], pBVar6 != (BF_KEY *)&SUB_00000002)) &&
      (((uStack_14c = (uint)pbVar15[2], pBVar6 != (BF_KEY *)0x3 &&
        (uStack_148 = (uint)pbVar15[3], pBVar6 != (BF_KEY *)&SUB_00000004)) &&
       ((uStack_144 = (uint)pbVar15[4], pBVar6 != (BF_KEY *)&DAT_00000005 &&
        ((uStack_140 = (uint)pbVar15[5], pBVar6 != (BF_KEY *)&DAT_00000006 &&
         (uStack_13c = (uint)pbVar15[6], pBVar6 != (BF_KEY *)&DAT_00000007)))))))) &&
     ((uStack_138 = (uint)pbVar15[7], pBVar6 != (BF_KEY *)&DAT_00000008 &&
      (((((uStack_134 = (uint)pbVar15[8], pBVar6 != (BF_KEY *)&DAT_00000009 &&
          (uStack_130 = (uint)pbVar15[9], pBVar6 != (BF_KEY *)&DAT_0000000a)) &&
         (uStack_12c = (uint)pbVar15[10], pBVar6 != (BF_KEY *)&DAT_0000000b)) &&
        ((uStack_128 = (uint)pbVar15[0xb], pBVar6 != (BF_KEY *)&SUB_0000000c &&
         (uStack_124 = (uint)pbVar15[0xc], pBVar6 != (BF_KEY *)&DAT_0000000d)))) &&
       ((uStack_120 = (uint)pbVar15[0xd], pBVar6 != (BF_KEY *)&DAT_0000000e &&
        (uStack_11c = (uint)pbVar15[0xe], pBVar6 == (BF_KEY *)&SUB_00000010)))))))) {
    uStack_118 = (uint)pbVar15[0xf];
  }
  uVar30 = *(uint *)(CAST_S_table6 + uStack_134 * 4);
  uVar11 = *(uint *)(CAST_S_table5 + uStack_128 * 4);
  puVar10[0x20] = (uint)((int)pBVar6 < 0xb);
  uVar20 = *(uint *)(CAST_S_table5 + uStack_118 * 4);
  uStack_198 = uStack_154 << 0x18 | uStack_150 << 0x10 | uStack_148 | uStack_14c << 8;
  uStack_194 = uStack_144 << 0x18 | uStack_140 << 0x10 | uStack_138 | uStack_13c << 8;
  uVar13 = uStack_124 << 0x18 | uStack_120 << 0x10 | uStack_118 | uStack_11c << 8;
  uVar41 = uStack_134 << 0x18 | uStack_130 << 0x10 | uStack_128 | uStack_12c << 8;
  iStack_19c = uStack_12c << 2;
  iVar9 = uStack_120 << 2;
  iVar43 = uStack_124 << 2;
  iStack_1a4 = uStack_130 << 2;
  iVar45 = uStack_11c << 2;
  puStack_1ac = &uStack_114;
  do {
    uVar30 = *(uint *)(CAST_S_table4 + iVar9) ^ *(uint *)(CAST_S_table6 + iVar43) ^
             *(uint *)(CAST_S_table7 + iVar45) ^ uStack_198 ^ uVar20 ^ uVar30;
    iVar21 = (uVar30 >> 0x18) * 4;
    iVar45 = (uVar30 & 0xff) * 4;
    iVar9 = ((uVar30 << 0x10) >> 0x18) * 4;
    iVar46 = ((uVar30 << 8) >> 0x18) * 4;
    uVar20 = *(uint *)(CAST_S_table4 + iVar9);
    uVar31 = *(uint *)(CAST_S_table6 + iVar46);
    uVar14 = *(uint *)(CAST_S_table7 + iVar9);
    uVar41 = *(uint *)(CAST_S_table4 + iVar21) ^ *(uint *)(CAST_S_table7 + iVar45) ^
             *(uint *)(CAST_S_table7 + iStack_19c) ^ *(uint *)(CAST_S_table5 + iVar9) ^ uVar31 ^
             uVar41;
    iVar23 = (uVar41 & 0xff) * 4;
    iVar9 = (uVar41 >> 0x18) * 4;
    iVar48 = ((uVar41 << 0x10) >> 0x18) * 4;
    iVar43 = ((uVar41 << 8) >> 0x18) * 4;
    uVar17 = *(uint *)(CAST_S_table6 + iVar23);
    uVar13 = *(uint *)(CAST_S_table7 + iVar9) ^ *(uint *)(CAST_S_table4 + iVar23) ^
             *(uint *)(CAST_S_table4 + iStack_1a4) ^ *(uint *)(CAST_S_table5 + iVar48) ^
             *(uint *)(CAST_S_table6 + iVar43) ^ uVar13;
    uVar16 = *(uint *)(CAST_S_table6 + iVar45);
    iVar36 = ((uVar13 << 8) >> 0x18) * 4;
    iVar26 = (uVar13 & 0xff) * 4;
    iVar32 = (uVar13 >> 0x18) * 4;
    uVar35 = *(uint *)(CAST_S_table5 + iVar36);
    uVar37 = *(uint *)(CAST_S_table6 + iVar36);
    uVar49 = *(uint *)(CAST_S_table7 + iVar48);
    uVar38 = *(uint *)(CAST_S_table4 + iVar32);
    uVar11 = *(uint *)(CAST_S_table6 + iVar26) ^ *(uint *)(CAST_S_table7 + iVar32) ^
             *(uint *)(CAST_S_table4 + ((uVar13 << 0x10) >> 0x18) * 4) ^ uVar35 ^ uStack_194 ^
             uVar11;
    iVar32 = (uVar11 >> 0x18) * 4;
    uVar39 = *(uint *)(CAST_S_table4 + iVar32);
    uVar33 = *(uint *)(CAST_S_table5 + ((uVar11 << 8) >> 0x18) * 4);
    uVar40 = *(uint *)(CAST_S_table5 + (uVar11 & 0xff) * 4);
    puStack_1ac[1] =
         *(uint *)(CAST_S_table5 + iVar48) ^ *(uint *)(CAST_S_table6 + iVar43) ^
         *(uint *)(CAST_S_table7 + iVar9) ^ *(uint *)(CAST_S_table5 + iVar26) ^
         *(uint *)(CAST_S_table4 + ((uVar13 << 0x10) >> 0x18) * 4);
    puStack_1ac[2] = uVar14 ^ uVar16 ^ uVar37 ^ uVar39 ^ uVar33;
    uVar39 = *(uint *)(CAST_S_table7 + iVar21);
    uVar16 = *(uint *)(CAST_S_table6 + iVar9);
    *puStack_1ac = uVar17 ^ uVar20 ^ uVar49 ^ uVar38 ^ uVar35;
    uVar13 = *(uint *)(CAST_S_table5 + iVar23) ^ uVar16 ^ *(uint *)(CAST_S_table6 + iVar21) ^ uVar49
             ^ *(uint *)(CAST_S_table4 + iVar43) ^ uVar13;
    iVar26 = (uVar13 >> 0x18) * 4;
    iVar43 = (uVar13 & 0xff) * 4;
    iVar9 = ((uVar13 << 8) >> 0x18) * 4;
    uVar50 = *(uint *)(CAST_S_table5 + ((uVar13 << 0x10) >> 0x18) * 4);
    uVar14 = uVar30 ^ uVar14 ^ *(uint *)(CAST_S_table4 + iVar26) ^ *(uint *)(CAST_S_table7 + iVar43)
             ^ uVar50 ^ *(uint *)(CAST_S_table6 + iVar9);
    iVar25 = (uVar14 & 0xff) * 4;
    iVar47 = (uVar14 >> 0x18) * 4;
    iVar21 = ((uVar14 << 8) >> 0x18) * 4;
    uVar51 = *(uint *)(CAST_S_table4 + iVar25);
    uVar33 = *(uint *)(CAST_S_table5 + ((uVar14 << 0x10) >> 0x18) * 4);
    uVar20 = uVar41 ^ *(uint *)(CAST_S_table4 + iVar46) ^ uVar51 ^ *(uint *)(CAST_S_table7 + iVar47)
             ^ uVar33 ^ *(uint *)(CAST_S_table6 + iVar21);
    uVar17 = *(uint *)(CAST_S_table4 + iVar9);
    iVar42 = (uVar20 & 0xff) * 4;
    iVar23 = ((uVar20 << 0x10) >> 0x18) * 4;
    iVar36 = (uVar20 >> 0x18) * 4;
    uVar16 = *(uint *)(CAST_S_table4 + iVar43);
    iVar27 = ((uVar20 << 8) >> 0x18) * 4;
    uVar30 = *(uint *)(CAST_S_table5 + iVar26);
    uVar41 = uVar11 ^ *(uint *)(CAST_S_table5 + iVar45) ^ *(uint *)(CAST_S_table6 + iVar42) ^
             *(uint *)(CAST_S_table7 + iVar36) ^ *(uint *)(CAST_S_table4 + iVar23) ^
             *(uint *)(CAST_S_table5 + iVar27);
    iVar26 = (uVar41 & 0xff) * 4;
    iVar45 = ((uVar41 << 0x10) >> 0x18) * 4;
    iVar9 = ((uVar41 << 8) >> 0x18) * 4;
    uVar37 = *(uint *)(CAST_S_table7 + iVar26);
    uVar35 = *(uint *)(CAST_S_table6 + iVar45);
    uVar38 = *(uint *)(CAST_S_table4 + iVar36);
    uVar49 = *(uint *)(CAST_S_table5 + iVar9);
    uVar52 = *(uint *)(CAST_S_table6 + (uVar41 >> 0x18) * 4);
    uVar44 = *(uint *)(CAST_S_table7 + iVar9);
    puStack_1ac[3] =
         uVar31 ^ uVar39 ^ uVar40 ^ *(uint *)(CAST_S_table7 + iVar32) ^
         *(uint *)(CAST_S_table4 + ((uVar11 << 0x10) >> 0x18) * 4);
    puStack_1ac[4] = uVar50 ^ uVar16 ^ uVar38 ^ uVar52 ^ uVar44;
    puStack_1ac[5] = uVar17 ^ uVar30 ^ uVar37 ^ uVar35 ^ uVar49;
    uVar31 = *(uint *)(CAST_S_table6 + iVar36);
    uVar16 = *(uint *)(CAST_S_table6 + iVar43);
    uVar39 = uVar13 ^ uVar31 ^ uVar52 ^ *(uint *)(CAST_S_table5 + iVar26) ^
             *(uint *)(CAST_S_table4 + iVar9) ^ *(uint *)(CAST_S_table7 + iVar45);
    iVar26 = (uVar39 >> 0x18) * 4;
    iVar36 = (uVar39 & 0xff) * 4;
    iVar48 = ((uVar39 << 0x10) >> 0x18) * 4;
    iVar28 = ((uVar39 << 8) >> 0x18) * 4;
    uVar17 = uVar20 ^ *(uint *)(CAST_S_table7 + iVar23) ^ *(uint *)(CAST_S_table4 + iVar26) ^
             *(uint *)(CAST_S_table7 + iVar36) ^ *(uint *)(CAST_S_table5 + iVar48) ^
             *(uint *)(CAST_S_table6 + iVar28);
    iVar34 = (uVar17 & 0xff) * 4;
    iVar9 = (uVar17 >> 0x18) * 4;
    uVar30 = *(uint *)(CAST_S_table4 + iVar34);
    iVar24 = ((uVar17 << 0x10) >> 0x18) * 4;
    iVar29 = ((uVar17 << 8) >> 0x18) * 4;
    uVar38 = *(uint *)(CAST_S_table5 + iVar24);
    uStack_198 = uVar41 ^ *(uint *)(CAST_S_table4 + iVar27) ^ uVar30 ^
                 *(uint *)(CAST_S_table7 + iVar9) ^ uVar38 ^ *(uint *)(CAST_S_table6 + iVar29);
    iVar43 = (uStack_198 & 0xff) * 4;
    iVar46 = (uStack_198 >> 0x18) * 4;
    iVar45 = ((uStack_198 << 0x10) >> 0x18) * 4;
    iVar32 = ((uStack_198 << 8) >> 0x18) * 4;
    uVar11 = uVar14 ^ *(uint *)(CAST_S_table5 + iVar42) ^ *(uint *)(CAST_S_table6 + iVar43) ^
             *(uint *)(CAST_S_table7 + iVar46) ^ *(uint *)(CAST_S_table4 + iVar45) ^
             *(uint *)(CAST_S_table5 + iVar32);
    uVar20 = *(uint *)(CAST_S_table5 + iVar47);
    iVar47 = (uVar11 >> 0x18) * 4;
    uVar35 = *(uint *)(CAST_S_table7 + iVar42);
    uVar13 = *(uint *)(CAST_S_table7 + iVar25);
    uVar41 = *(uint *)(CAST_S_table4 + iVar21);
    uVar14 = *(uint *)(CAST_S_table6 + iVar23);
    uVar37 = *(uint *)(CAST_S_table7 + iVar27);
    puStack_1ac[8] =
         *(uint *)(CAST_S_table5 + iVar48) ^ *(uint *)(CAST_S_table4 + iVar36) ^
         *(uint *)(CAST_S_table4 + iVar32) ^ *(uint *)(CAST_S_table6 + iVar47) ^
         *(uint *)(CAST_S_table7 + ((uVar11 << 8) >> 0x18) * 4);
    puStack_1ac[7] = uVar20 ^ uVar13 ^ uVar41 ^ uVar35 ^ uVar14;
    uVar41 = *(uint *)(CAST_S_table5 + iVar34);
    uVar14 = *(uint *)(CAST_S_table6 + iVar9);
    uVar20 = *(uint *)(CAST_S_table6 + iVar26);
    uVar44 = *(uint *)(CAST_S_table4 + iVar29);
    puStack_1ac[6] = uVar51 ^ uVar16 ^ uVar33 ^ uVar31 ^ uVar37;
    uVar13 = *(uint *)(CAST_S_table7 + iVar24);
    uStack_198 = uVar41 ^ uVar14 ^ uVar20 ^ uVar44 ^ uVar13 ^ uStack_198;
    iVar24 = (uStack_198 >> 0x18) * 4;
    iVar21 = (uStack_198 & 0xff) * 4;
    iVar25 = ((uStack_198 << 0x10) >> 0x18) * 4;
    uVar50 = *(uint *)(CAST_S_table6 + ((uStack_198 << 8) >> 0x18) * 4);
    uStack_194 = uVar39 ^ *(uint *)(CAST_S_table7 + iVar48) ^ *(uint *)(CAST_S_table4 + iVar24) ^
                 *(uint *)(CAST_S_table7 + iVar21) ^ *(uint *)(CAST_S_table5 + iVar25) ^ uVar50;
    iVar27 = ((uStack_194 << 0x10) >> 0x18) * 4;
    iVar23 = (uStack_194 & 0xff) * 4;
    uVar52 = *(uint *)(CAST_S_table7 + (uStack_194 >> 0x18) * 4);
    uVar39 = *(uint *)(CAST_S_table6 + ((uStack_194 << 8) >> 0x18) * 4);
    uVar49 = *(uint *)(CAST_S_table6 + iVar48);
    uVar51 = *(uint *)(CAST_S_table5 + iVar9);
    uVar41 = uVar17 ^ *(uint *)(CAST_S_table4 + iVar28) ^ *(uint *)(CAST_S_table4 + iVar23) ^ uVar52
             ^ *(uint *)(CAST_S_table5 + iVar27) ^ uVar39;
    uVar35 = *(uint *)(CAST_S_table6 + iVar46);
    uVar31 = *(uint *)(CAST_S_table7 + iVar43);
    uVar16 = *(uint *)(CAST_S_table7 + iVar32);
    uVar14 = *(uint *)(CAST_S_table6 + iVar45);
    iVar9 = (uVar41 & 0xff) * 4;
    iStack_1a4 = ((uVar41 << 8) >> 0x18) * 4;
    iVar32 = (uVar41 >> 0x18) * 4;
    iStack_19c = ((uVar41 << 0x10) >> 0x18) * 4;
    uVar40 = *(uint *)(CAST_S_table5 + iVar36);
    uVar37 = *(uint *)(CAST_S_table6 + iVar9);
    uVar33 = *(uint *)(CAST_S_table5 + iStack_1a4);
    uVar20 = *(uint *)(CAST_S_table7 + iVar32);
    uVar17 = *(uint *)(CAST_S_table4 + iStack_19c);
    puStack_1ac[9] =
         *(uint *)(CAST_S_table4 + iVar28) ^ *(uint *)(CAST_S_table5 + iVar26) ^
         *(uint *)(CAST_S_table7 + (uVar11 & 0xff) * 4) ^ *(uint *)(CAST_S_table5 + iVar47) ^
         *(uint *)(CAST_S_table6 + ((uVar11 << 0x10) >> 0x18) * 4);
    puStack_1ac[10] = uVar30 ^ uVar49 ^ uVar38 ^ uVar35 ^ uVar16;
    puStack_1ac[0xb] = uVar44 ^ uVar13 ^ uVar51 ^ uVar31 ^ uVar14;
    uVar13 = uVar11 ^ uVar40 ^ uVar37 ^ uVar20 ^ uVar17 ^ uVar33;
    uVar44 = *(uint *)(CAST_S_table6 + iVar23);
    uVar14 = *(uint *)(CAST_S_table4 + iVar21);
    uVar53 = *(uint *)(CAST_S_table7 + iVar24);
    uVar40 = *(uint *)(CAST_S_table6 + iVar21);
    iVar43 = (uVar13 >> 0x18) * 4;
    iVar45 = ((uVar13 << 0x10) >> 0x18) * 4;
    uVar30 = *(uint *)(CAST_S_table6 + iVar32);
    uVar51 = *(uint *)(CAST_S_table7 + iVar27);
    uVar20 = *(uint *)(CAST_S_table5 + (uVar13 & 0xff) * 4);
    uVar11 = *(uint *)(CAST_S_table5 + iVar9);
    uVar16 = *(uint *)(CAST_S_table7 + iVar25);
    uVar37 = *(uint *)(CAST_S_table4 + iVar32);
    uVar35 = *(uint *)(CAST_S_table4 + iVar43);
    uVar31 = *(uint *)(CAST_S_table4 + iVar45);
    iVar9 = ((uVar13 << 8) >> 0x18) * 4;
    uVar49 = *(uint *)(CAST_S_table5 + iVar9);
    uVar38 = *(uint *)(CAST_S_table7 + iVar9);
    puStack_1ac[0xd] = uVar52 ^ *(uint *)(CAST_S_table5 + iVar23) ^ uVar39 ^ uVar11 ^ uVar17;
    puStack_1ac[0xc] = uVar44 ^ uVar14 ^ uVar51 ^ uVar37 ^ uVar33;
    puStack_1ac[0xe] = uVar40 ^ uVar16 ^ uVar30 ^ uVar35 ^ uVar49;
    bVar1 = puStack_1ac == &uStack_114;
    puStack_1ac[0xf] = uVar50 ^ uVar53 ^ uVar20 ^ uVar31 ^ uVar38;
    puStack_1ac = &uStack_d4;
  } while (bVar1);
  puVar10[1] = uStack_d4 + 0x10 & 0x1f;
  puVar10[3] = iStack_d0 + 0x10U & 0x1f;
  puVar10[5] = iStack_cc + 0x10U & 0x1f;
  puVar10[7] = iStack_c8 + 0x10U & 0x1f;
  puVar10[9] = iStack_c4 + 0x10U & 0x1f;
  puVar10[0xb] = iStack_c0 + 0x10U & 0x1f;
  puVar10[0xd] = iStack_bc + 0x10U & 0x1f;
  *puVar10 = uStack_114;
  puVar10[2] = uStack_110;
  puVar10[4] = uStack_10c;
  puVar10[6] = uStack_108;
  puVar10[8] = uStack_104;
  puVar10[10] = uStack_100;
  puVar10[0xc] = uStack_fc;
  puVar10[0xe] = uStack_f8;
  puVar10[0xf] = iStack_b8 + 0x10U & 0x1f;
  puVar10[0x11] = iStack_b4 + 0x10U & 0x1f;
  puVar10[0x13] = iStack_b0 + 0x10U & 0x1f;
  puVar10[0x15] = iStack_ac + 0x10U & 0x1f;
  puVar10[0x17] = iStack_a8 + 0x10U & 0x1f;
  puVar10[0x19] = iStack_a4 + 0x10U & 0x1f;
  puVar10[0x1b] = iStack_a0 + 0x10U & 0x1f;
  puVar10[0x1d] = iStack_9c + 0x10U & 0x1f;
  puVar10[0x10] = uStack_f4;
  puVar10[0x1f] = iStack_98 + 0x10U & 0x1f;
  puVar10[0x12] = uStack_f0;
  puVar10[0x14] = uStack_ec;
  puVar10[0x16] = uStack_e8;
  puVar10[0x18] = uStack_e4;
  puVar10[0x1a] = (uint)piStack_e0;
  puVar10[0x1c] = (uint)puStack_dc;
  puVar10[0x1e] = uStack_d8;
  if (iStack_94 != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar11 = puStack_dc[1] + *piStack_e0;
    uVar11 = (uVar11 >> (-piStack_e0[1] & 0x1fU)) + (uVar11 << 0x20 - (-piStack_e0[1] & 0x1fU));
    uVar13 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar11 * 0x10000 >> 0x18) * 4) ^
             *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar11 & 0xff) * 4)) +
             (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar11 * 0x100 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar11 >> 0x18) * 4)) ^ *puStack_dc;
    uVar11 = uVar13 ^ piStack_e0[2];
    uVar11 = (uVar11 >> (-piStack_e0[3] & 0x1fU)) + (uVar11 << 0x20 - (-piStack_e0[3] & 0x1fU));
    uVar41 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar11 * 0x10000 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar11 & 0xff) * 4)) +
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar11 >> 0x18) * 4) ^
             puStack_dc[1] ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar11 * 0x100 >> 0x18) * 4);
    uVar11 = piStack_e0[4] - uVar41;
    uVar11 = (uVar11 >> (-piStack_e0[5] & 0x1fU)) + (uVar11 << 0x20 - (-piStack_e0[5] & 0x1fU));
    uVar13 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar11 * 0x10000 >> 0x18) * 4) +
              *(int *)(PTR_CAST_S_table1_006a9620 + (uVar11 & 0xff) * 4) ^
             *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar11 >> 0x18) * 4)) -
             *(int *)(PTR_CAST_S_table3_006a9614 + (uVar11 * 0x100 >> 0x18) * 4) ^ uVar13;
    uVar11 = uVar13 + piStack_e0[6];
    uVar11 = (uVar11 >> (-piStack_e0[7] & 0x1fU)) + (uVar11 << 0x20 - (-piStack_e0[7] & 0x1fU));
    uVar41 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar11 * 0x10000 >> 0x18) * 4) ^
             *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar11 & 0xff) * 4)) +
             (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar11 * 0x100 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar11 >> 0x18) * 4)) ^ uVar41;
    uVar11 = uVar41 ^ piStack_e0[8];
    uVar11 = (uVar11 >> (-piStack_e0[9] & 0x1fU)) + (uVar11 << 0x20 - (-piStack_e0[9] & 0x1fU));
    uVar11 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar11 * 0x10000 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar11 & 0xff) * 4)) +
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar11 >> 0x18) * 4) ^
             uVar13 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar11 * 0x100 >> 0x18) * 4);
    uVar13 = piStack_e0[10] - uVar11;
    uVar13 = (uVar13 >> (-piStack_e0[0xb] & 0x1fU)) + (uVar13 << 0x20 - (-piStack_e0[0xb] & 0x1fU));
    uVar41 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar13 * 0x10000 >> 0x18) * 4) +
              *(int *)(PTR_CAST_S_table1_006a9620 + (uVar13 & 0xff) * 4) ^
             *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar13 >> 0x18) * 4)) -
             *(int *)(PTR_CAST_S_table3_006a9614 + (uVar13 * 0x100 >> 0x18) * 4) ^ uVar41;
    uVar13 = uVar41 + piStack_e0[0xc];
    uVar13 = (uVar13 >> (-piStack_e0[0xd] & 0x1fU)) + (uVar13 << 0x20 - (-piStack_e0[0xd] & 0x1fU));
    uVar11 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar13 * 0x10000 >> 0x18) * 4) ^
             *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar13 & 0xff) * 4)) +
             (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar13 * 0x100 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar13 >> 0x18) * 4)) ^ uVar11;
    uVar13 = uVar11 ^ piStack_e0[0xe];
    uVar13 = (uVar13 >> (-piStack_e0[0xf] & 0x1fU)) + (uVar13 << 0x20 - (-piStack_e0[0xf] & 0x1fU));
    uVar13 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar13 * 0x10000 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar13 & 0xff) * 4)) +
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar13 >> 0x18) * 4) ^
             uVar41 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar13 * 0x100 >> 0x18) * 4);
    uVar41 = piStack_e0[0x10] - uVar13;
    uVar41 = (uVar41 >> (-piStack_e0[0x11] & 0x1fU)) +
             (uVar41 << 0x20 - (-piStack_e0[0x11] & 0x1fU));
    uVar11 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar41 * 0x10000 >> 0x18) * 4) +
              *(int *)(PTR_CAST_S_table1_006a9620 + (uVar41 & 0xff) * 4) ^
             *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar41 >> 0x18) * 4)) -
             *(int *)(PTR_CAST_S_table3_006a9614 + (uVar41 * 0x100 >> 0x18) * 4) ^ uVar11;
    uVar41 = uVar11 + piStack_e0[0x12];
    uVar41 = (uVar41 >> (-piStack_e0[0x13] & 0x1fU)) +
             (uVar41 << 0x20 - (-piStack_e0[0x13] & 0x1fU));
    uVar13 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar41 * 0x10000 >> 0x18) * 4) ^
             *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar41 & 0xff) * 4)) +
             (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar41 * 0x100 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar41 >> 0x18) * 4)) ^ uVar13;
    uVar41 = uVar13 ^ piStack_e0[0x14];
    uVar41 = (uVar41 >> (-piStack_e0[0x15] & 0x1fU)) +
             (uVar41 << 0x20 - (-piStack_e0[0x15] & 0x1fU));
    uVar11 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar41 * 0x10000 >> 0x18) * 4) -
             *(int *)(PTR_CAST_S_table1_006a9620 + (uVar41 & 0xff) * 4)) +
             *(int *)(PTR_CAST_S_table2_006a9618 + (uVar41 >> 0x18) * 4) ^
             uVar11 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar41 * 0x100 >> 0x18) * 4);
    uVar41 = (piStack_e0[0x16] - uVar11 >> (-piStack_e0[0x17] & 0x1fU)) +
             (piStack_e0[0x16] - uVar11 << 0x20 - (-piStack_e0[0x17] & 0x1fU));
    uVar13 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar41 * 0x10000 >> 0x18) * 4) +
              *(int *)(PTR_CAST_S_table1_006a9620 + (uVar41 & 0xff) * 4) ^
             *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar41 >> 0x18) * 4)) -
             *(int *)(PTR_CAST_S_table3_006a9614 + (uVar41 * 0x100 >> 0x18) * 4) ^ uVar13;
    if (piStack_e0[0x20] == 0) {
      uVar41 = (uVar13 + piStack_e0[0x18] >> (-piStack_e0[0x19] & 0x1fU)) +
               (uVar13 + piStack_e0[0x18] << 0x20 - (-piStack_e0[0x19] & 0x1fU));
      uVar11 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar41 * 0x10000 >> 0x18) * 4) ^
               *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar41 & 0xff) * 4)) +
               (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar41 * 0x100 >> 0x18) * 4) -
               *(int *)(PTR_CAST_S_table2_006a9618 + (uVar41 >> 0x18) * 4)) ^ uVar11;
      uVar41 = uVar11 ^ piStack_e0[0x1a];
      uVar41 = (uVar41 >> (-piStack_e0[0x1b] & 0x1fU)) +
               (uVar41 << 0x20 - (-piStack_e0[0x1b] & 0x1fU));
      uVar13 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar41 * 0x10000 >> 0x18) * 4) -
               *(int *)(PTR_CAST_S_table1_006a9620 + (uVar41 & 0xff) * 4)) +
               *(int *)(PTR_CAST_S_table2_006a9618 + (uVar41 >> 0x18) * 4) ^
               uVar13 ^ *(uint *)(PTR_CAST_S_table3_006a9614 + (uVar41 * 0x100 >> 0x18) * 4);
      uVar41 = piStack_e0[0x1c] - uVar13;
      uVar41 = (uVar41 >> (-piStack_e0[0x1d] & 0x1fU)) +
               (uVar41 << 0x20 - (-piStack_e0[0x1d] & 0x1fU));
      uVar11 = (*(int *)(PTR_CAST_S_table0_006a961c + (uVar41 * 0x10000 >> 0x18) * 4) +
                *(int *)(PTR_CAST_S_table1_006a9620 + (uVar41 & 0xff) * 4) ^
               *(uint *)(PTR_CAST_S_table2_006a9618 + (uVar41 >> 0x18) * 4)) -
               *(int *)(PTR_CAST_S_table3_006a9614 + (uVar41 * 0x100 >> 0x18) * 4) ^ uVar11;
      uVar41 = (uVar11 + piStack_e0[0x1e] >> (-piStack_e0[0x1f] & 0x1fU)) +
               (uVar11 + piStack_e0[0x1e] << 0x20 - (-piStack_e0[0x1f] & 0x1fU));
      uVar13 = (*(uint *)(PTR_CAST_S_table0_006a961c + (uVar41 * 0x10000 >> 0x18) * 4) ^
               *(uint *)(PTR_CAST_S_table1_006a9620 + (uVar41 & 0xff) * 4)) +
               (*(int *)(PTR_CAST_S_table3_006a9614 + (uVar41 * 0x100 >> 0x18) * 4) -
               *(int *)(PTR_CAST_S_table2_006a9618 + (uVar41 >> 0x18) * 4)) ^ uVar13;
    }
    puStack_dc[1] = uVar11;
    *puStack_dc = uVar13;
    return;
  }
  return;
}

