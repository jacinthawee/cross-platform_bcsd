
void RC2_cbc_encrypt(uchar *in,uchar *out,long length,RC2_KEY *ks,uchar *iv,int enc)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  uchar uVar7;
  byte bVar8;
  uchar uVar9;
  byte *pbVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uchar uVar15;
  byte bVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uchar uVar23;
  uint uVar22;
  int iVar24;
  uint uVar25;
  uint *puVar26;
  uint uVar27;
  uchar *puVar28;
  uint uVar29;
  byte *local_48;
  uchar *local_44;
  uint local_34;
  uint local_30;
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_48 = in;
  local_44 = out;
  if (enc == 0) {
    uVar5 = length - 8;
    puVar14 = (uint *)((uint)iv[3] << 0x18);
    puVar11 = (uint *)((uint)iv[7] << 0x18);
    uVar21 = (uint)puVar14 | (uint)iv[1] << 8 | (uint)iv[2] << 0x10 | (uint)*iv;
    uVar17 = (uint)puVar11 | (uint)iv[5] << 8 | (uint)iv[6] << 0x10 | (uint)iv[4];
    if (-1 < (int)uVar5) {
      uVar19 = uVar17;
      puVar28 = out;
      uVar20 = uVar5;
      uVar22 = uVar21;
      pbVar10 = in;
      do {
        uVar20 = uVar20 - 8;
        uVar21 = (uint)pbVar10[1] << 8 | (uint)pbVar10[2] << 0x10 | (uint)*pbVar10 |
                 (uint)pbVar10[3] << 0x18;
        uVar17 = (uint)pbVar10[7] << 0x18 |
                 (uint)pbVar10[5] << 8 | (uint)pbVar10[6] << 0x10 | (uint)pbVar10[4];
        local_34 = uVar21;
        local_30 = uVar17;
        RC2_decrypt(&local_34,ks);
        uVar22 = uVar22 ^ local_34;
        uVar19 = uVar19 ^ local_30;
        *puVar28 = (uchar)uVar22;
        puVar14 = (uint *)(uVar22 >> 0x10);
        puVar11 = (uint *)(uVar19 >> 8);
        puVar28[4] = (uchar)uVar19;
        puVar28[1] = (uchar)(uVar22 >> 8);
        puVar28[2] = (uchar)(uVar22 >> 0x10);
        puVar28[5] = (uchar)(uVar19 >> 8);
        puVar28[3] = (uchar)(uVar22 >> 0x18);
        puVar28[6] = (uchar)(uVar19 >> 0x10);
        puVar28[7] = (uchar)(uVar19 >> 0x18);
        uVar19 = uVar17;
        puVar28 = puVar28 + 8;
        uVar22 = uVar21;
        pbVar10 = pbVar10 + 8;
      } while (-1 < (int)uVar20);
      iVar6 = ((uVar5 >> 3) + 1) * 8;
      uVar5 = (length + -0x10) - (uVar5 & 0xfffffff8);
      local_48 = in + iVar6;
      local_44 = out + iVar6;
    }
    uVar20 = uVar21;
    uVar19 = uVar17;
    if (uVar5 != 0xfffffff8) {
      puVar14 = (uint *)((uint)local_48[1] << 8 | (uint)local_48[2] << 0x10 | (uint)*local_48);
      uVar19 = (uint)local_48[5] << 8 | (uint)local_48[6] << 0x10 | (uint)local_48[4] |
               (uint)local_48[7] << 0x18;
      uVar20 = (uint)puVar14 | (uint)local_48[3] << 0x18;
      local_34 = uVar20;
      local_30 = uVar19;
      RC2_decrypt(&local_34,ks);
      local_44 = local_44 + uVar5 + 8;
      uVar21 = uVar21 ^ local_34;
      uVar17 = uVar17 ^ local_30;
      puVar11 = ks->data;
      if (7 < uVar5 + 8) goto LAB_004e480c;
      puVar28 = local_44;
      switch(uVar5) {
      case 0xfffffff9:
        goto LAB_004e4800;
      case 0xfffffffa:
        goto switchD_004e47c8_caseD_fffffffa;
      case 0xfffffffb:
        goto LAB_004e47e8;
      case 0xfffffffd:
        puVar28 = local_44 + -1;
        local_44[-1] = (uchar)uVar17;
        break;
      case 0xffffffff:
        local_44 = local_44 + -1;
        *local_44 = (uchar)(uVar17 >> 0x10);
      case 0xfffffffe:
        local_44[-1] = (uchar)(uVar17 >> 8);
        puVar28 = local_44 + -2;
        local_44[-2] = (uchar)uVar17;
      }
      local_44 = puVar28 + -1;
      puVar28[-1] = (uchar)(uVar21 >> 0x18);
LAB_004e47e8:
      puVar28 = local_44 + -1;
      local_44[-1] = (uchar)(uVar21 >> 0x10);
switchD_004e47c8_caseD_fffffffa:
      local_44 = puVar28 + -1;
      puVar28[-1] = (uchar)(uVar21 >> 8);
LAB_004e4800:
      local_44[-1] = (uchar)uVar21;
    }
LAB_004e480c:
    *iv = (uchar)uVar20;
    pbVar10 = (byte *)(uVar20 >> 0x10);
    iv[4] = (uchar)uVar19;
    iv[1] = (uchar)(uVar20 >> 8);
    iv[2] = (uchar)(uVar20 >> 0x10);
    iv[3] = (uchar)(uVar20 >> 0x18);
    iv[5] = (uchar)(uVar19 >> 8);
    iv[7] = (uchar)(uVar19 >> 0x18);
    iv[6] = (uchar)(uVar19 >> 0x10);
  }
  else {
    uVar5 = length - 8;
    uVar21 = (uint)iv[3] << 0x18 | (uint)iv[1] << 8 | (uint)iv[2] << 0x10 | (uint)*iv;
    uVar17 = (uint)iv[7] << 0x18 | (uint)iv[5] << 8 | (uint)iv[6] << 0x10 | (uint)iv[4];
    if (-1 < (int)uVar5) {
      local_30 = uVar17;
      local_34 = uVar21;
      pbVar10 = in;
      uVar17 = uVar5;
      puVar28 = out;
      do {
        uVar17 = uVar17 - 8;
        local_30 = ((uint)pbVar10[7] << 0x18 |
                   (uint)pbVar10[5] << 8 | (uint)pbVar10[6] << 0x10 | (uint)pbVar10[4]) ^ local_30;
        local_34 = ((uint)pbVar10[3] << 0x18 |
                   (uint)pbVar10[1] << 8 | (uint)pbVar10[2] << 0x10 | (uint)*pbVar10) ^ local_34;
        RC2_encrypt(&local_34,ks);
        *puVar28 = (uchar)local_34;
        puVar28[4] = (uchar)local_30;
        puVar28[1] = (uchar)(local_34 >> 8);
        puVar28[2] = (uchar)(local_34 >> 0x10);
        puVar28[3] = (uchar)(local_34 >> 0x18);
        puVar28[5] = (uchar)(local_30 >> 8);
        puVar28[6] = (uchar)(local_30 >> 0x10);
        puVar28[7] = (uchar)(local_30 >> 0x18);
        pbVar10 = pbVar10 + 8;
        puVar28 = puVar28 + 8;
      } while (-1 < (int)uVar17);
      iVar6 = ((uVar5 >> 3) + 1) * 8;
      uVar5 = (length + -0x10) - (uVar5 & 0xfffffff8);
      local_48 = in + iVar6;
      local_44 = out + iVar6;
      uVar17 = local_30;
      uVar21 = local_34;
    }
    if (uVar5 == 0xfffffff8) {
      pbVar10 = (byte *)(uVar21 & 0xff);
      uVar15 = (uchar)(uVar21 >> 8);
      uVar23 = (uchar)(uVar21 >> 0x18);
      uVar7 = (uchar)(uVar17 >> 0x18);
      uVar9 = (uchar)uVar17;
    }
    else {
      puVar28 = local_48 + uVar5 + 8;
      switch(uVar5) {
      default:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e4924;
      case 0xfffffff9:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e491c;
      case 0xfffffffa:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e490c;
      case 0xfffffffb:
        local_30 = 0;
        local_34 = 0;
        goto LAB_004e48fc;
      case 0xfffffffc:
        local_30 = 0;
        goto LAB_004e48f0;
      case 0xfffffffd:
        local_30 = 0;
        goto LAB_004e48e4;
      case 0xfffffffe:
        local_30 = 0;
        break;
      case 0xffffffff:
        pbVar10 = puVar28 + -1;
        puVar28 = puVar28 + -1;
        local_30 = (uint)*pbVar10 << 0x10;
      }
      pbVar10 = puVar28 + -1;
      puVar28 = puVar28 + -1;
      local_30 = (uint)*pbVar10 << 8 | local_30;
LAB_004e48e4:
      pbVar10 = puVar28 + -1;
      puVar28 = puVar28 + -1;
      local_30 = *pbVar10 | local_30;
LAB_004e48f0:
      pbVar10 = puVar28 + -1;
      puVar28 = puVar28 + -1;
      local_34 = (uint)*pbVar10 << 0x18;
LAB_004e48fc:
      pbVar10 = puVar28 + -1;
      puVar28 = puVar28 + -1;
      local_34 = (uint)*pbVar10 << 0x10 | local_34;
LAB_004e490c:
      pbVar10 = puVar28 + -1;
      puVar28 = puVar28 + -1;
      local_34 = (uint)*pbVar10 << 8 | local_34;
LAB_004e491c:
      local_34 = puVar28[-1] | local_34;
LAB_004e4924:
      local_34 = local_34 ^ uVar21;
      local_30 = local_30 ^ uVar17;
      RC2_encrypt(&local_34,ks);
      uVar15 = (uchar)(local_34 >> 8);
      local_44[1] = uVar15;
      local_44[2] = (uchar)(local_34 >> 0x10);
      uVar23 = (uchar)(local_34 >> 0x18);
      local_44[3] = uVar23;
      pbVar10 = (byte *)(local_34 & 0xff);
      local_44[5] = (uchar)(local_30 >> 8);
      uVar9 = (uchar)local_30;
      local_44[6] = (uchar)(local_30 >> 0x10);
      *local_44 = (uchar)pbVar10;
      local_44[4] = uVar9;
      uVar7 = (uchar)(local_30 >> 0x18);
      local_44[7] = uVar7;
      uVar17 = local_30;
      uVar21 = local_34;
    }
    uVar19 = uVar17 << 0x10;
    puVar14 = (uint *)((uVar21 << 8) >> 0x18);
    puVar11 = (uint *)((uVar17 << 8) >> 0x18);
    *iv = (uchar)pbVar10;
    iv[1] = uVar15;
    iv[2] = (uchar)(uVar21 >> 0x10);
    iv[3] = uVar23;
    iv[4] = uVar9;
    iv[5] = (uchar)(uVar17 >> 8);
    iv[6] = (uchar)(uVar17 >> 0x10);
    iv[7] = uVar7;
  }
  puVar12 = (uint *)(uVar19 >> 0x18);
  if (local_2c == *(int *)puVar4) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar5 = (uint)*pbVar10;
  uVar21 = (uint)pbVar10[1];
  uVar17 = uVar5;
  if ((((uint)puVar12 | (uint)puVar14) & 3) == 0) {
    for (; ((uint)puVar11 & 0xfffffffc) != 0; puVar11 = ((RC2_KEY *)(puVar11 + -0x40))->data + 0x3f)
    {
      uVar19 = *puVar12;
      bVar8 = pbVar10[(uVar17 + 1 & 0xff) + 2];
      uVar21 = uVar21 + bVar8 & 0xff;
      uVar5 = uVar17 + 4 & 0xff;
      bVar16 = pbVar10[uVar21 + 2];
      pbVar10[uVar21 + 2] = bVar8;
      pbVar10[(uVar17 + 1 & 0xff) + 2] = bVar16;
      puVar12 = puVar12 + 1;
      bVar1 = pbVar10[(uVar17 + 2 & 0xff) + 2];
      bVar8 = pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2];
      uVar21 = uVar21 + bVar1 & 0xff;
      bVar16 = pbVar10[uVar21 + 2];
      pbVar10[uVar21 + 2] = bVar1;
      pbVar10[(uVar17 + 2 & 0xff) + 2] = bVar16;
      bVar2 = pbVar10[(uVar17 + 3 & 0xff) + 2];
      bVar16 = pbVar10[((uint)bVar1 + (uint)bVar16 & 0xff) + 2];
      uVar21 = uVar21 + bVar2 & 0xff;
      bVar1 = pbVar10[uVar21 + 2];
      pbVar10[uVar21 + 2] = bVar2;
      pbVar10[(uVar17 + 3 & 0xff) + 2] = bVar1;
      bVar3 = pbVar10[uVar5 + 2];
      bVar1 = pbVar10[((uint)bVar2 + (uint)bVar1 & 0xff) + 2];
      uVar21 = uVar21 + bVar3 & 0xff;
      bVar2 = pbVar10[uVar21 + 2];
      pbVar10[uVar21 + 2] = bVar3;
      pbVar10[uVar5 + 2] = bVar2;
      *puVar14 = ((uint)pbVar10[((uint)bVar3 + (uint)bVar2 & 0xff) + 2] |
                 (uint)bVar1 << 8 | (uint)bVar16 << 0x10 | (uint)bVar8 << 0x18) ^ uVar19;
      uVar17 = uVar5;
      puVar14 = puVar14 + 1;
    }
    if ((RC2_KEY *)puVar11 != (RC2_KEY *)0x0) {
      uVar5 = *puVar12;
      uVar19 = *puVar14;
      if ((RC2_KEY *)puVar11 == (RC2_KEY *)&SUB_00000002) {
        iVar24 = 0x10;
        uVar20 = 0;
        iVar6 = 0x18;
LAB_004e4c1c:
        uVar17 = uVar17 + 1 & 0xff;
        bVar8 = pbVar10[uVar17 + 2];
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[uVar21 + 2] = bVar8;
        pbVar10[uVar17 + 2] = bVar16;
        uVar20 = (uint)pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] << iVar6 | uVar20;
      }
      else {
        uVar20 = 0;
        if ((RC2_KEY *)puVar11 == (RC2_KEY *)0x3) {
          iVar24 = 8;
          uVar17 = uVar17 + 1 & 0xff;
          iVar6 = 0x10;
          bVar8 = pbVar10[uVar17 + 2];
          uVar21 = bVar8 + uVar21 & 0xff;
          bVar16 = pbVar10[uVar21 + 2];
          pbVar10[uVar21 + 2] = bVar8;
          pbVar10[uVar17 + 2] = bVar16;
          uVar20 = (uint)pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] << 0x18;
          goto LAB_004e4c1c;
        }
        iVar24 = 0x18;
      }
      uVar17 = uVar17 + 1 & 0xff;
      bVar8 = pbVar10[uVar17 + 2];
      uVar21 = uVar21 + bVar8 & 0xff;
      bVar16 = pbVar10[uVar21 + 2];
      pbVar10[uVar21 + 2] = bVar8;
      pbVar10[uVar17 + 2] = bVar16;
      *puVar14 = uVar19 ^ (((uint)pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] << iVar24 |
                           uVar20) ^ uVar5 ^ uVar19) & -1 << ((4 - (int)puVar11) * 8 & 0x1fU);
    }
  }
  else {
    if ((uint)puVar11 >> 3 != 0) {
      puVar26 = (uint *)((int)puVar12 + ((uint)puVar11 & 0xfffffff8));
      puVar13 = puVar12;
      puVar18 = puVar14;
      do {
        uVar29 = uVar17 + 2;
        bVar8 = pbVar10[(uVar17 + 1 & 0xff) + 2];
        puVar12 = puVar13 + 2;
        uVar27 = uVar17 + 3;
        uVar21 = uVar21 + bVar8 & 0xff;
        uVar25 = uVar17 + 4;
        bVar16 = pbVar10[uVar21 + 2];
        uVar22 = uVar17 + 5;
        pbVar10[(uVar17 + 1 & 0xff) + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        uVar20 = uVar17 + 6;
        uVar19 = uVar17 + 7;
        *(byte *)puVar18 = pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)puVar13;
        bVar8 = pbVar10[(uVar29 & 0xff) + 2];
        uVar17 = uVar17 + 8 & 0xff;
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[(uVar29 & 0xff) + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        *(byte *)((int)puVar18 + 1) =
             pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar13 + 1);
        bVar8 = pbVar10[(uVar27 & 0xff) + 2];
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[(uVar27 & 0xff) + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        *(byte *)((int)puVar18 + 2) =
             pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar13 + 2);
        bVar8 = pbVar10[(uVar25 & 0xff) + 2];
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[(uVar25 & 0xff) + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        *(byte *)((int)puVar18 + 3) =
             pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar13 + 3);
        bVar8 = pbVar10[(uVar22 & 0xff) + 2];
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[(uVar22 & 0xff) + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        *(byte *)(puVar18 + 1) =
             pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)(puVar13 + 1);
        bVar8 = pbVar10[(uVar20 & 0xff) + 2];
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[(uVar20 & 0xff) + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        *(byte *)((int)puVar18 + 5) =
             pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar13 + 5);
        bVar8 = pbVar10[(uVar19 & 0xff) + 2];
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[(uVar19 & 0xff) + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        *(byte *)((int)puVar18 + 6) =
             pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar13 + 6);
        bVar8 = pbVar10[uVar17 + 2];
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[uVar17 + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        *(byte *)((int)puVar18 + 7) =
             pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar13 + 7);
        puVar13 = puVar12;
        puVar18 = puVar18 + 2;
      } while (puVar12 != puVar26);
      puVar14 = (uint *)((int)puVar14 + ((uint)puVar11 & 0xfffffff8));
      uVar5 = ((uint)puVar11 & 0xfffffff8) + uVar5 & 0xff;
    }
    bVar8 = (byte)uVar21;
    bVar16 = (byte)uVar5;
    uVar19 = (uint)puVar11 & 7;
    if (uVar19 == 0) goto LAB_004e4cb4;
    uVar17 = uVar5 + 1 & 0xff;
    bVar8 = pbVar10[uVar17 + 2];
    uVar21 = uVar21 + bVar8 & 0xff;
    bVar16 = pbVar10[uVar21 + 2];
    pbVar10[uVar17 + 2] = bVar16;
    pbVar10[uVar21 + 2] = bVar8;
    *(byte *)puVar14 = pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)puVar12;
    if (uVar19 != 1) {
      uVar17 = uVar5 + 2 & 0xff;
      bVar8 = pbVar10[uVar17 + 2];
      uVar21 = uVar21 + bVar8 & 0xff;
      bVar16 = pbVar10[uVar21 + 2];
      pbVar10[uVar17 + 2] = bVar16;
      pbVar10[uVar21 + 2] = bVar8;
      *(byte *)((int)puVar14 + 1) =
           pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar12 + 1);
      if (uVar19 != 2) {
        uVar17 = uVar5 + 3 & 0xff;
        bVar8 = pbVar10[uVar17 + 2];
        uVar21 = uVar21 + bVar8 & 0xff;
        bVar16 = pbVar10[uVar21 + 2];
        pbVar10[uVar17 + 2] = bVar16;
        pbVar10[uVar21 + 2] = bVar8;
        *(byte *)((int)puVar14 + 2) =
             pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar12 + 2);
        if (uVar19 != 3) {
          uVar17 = uVar5 + 4 & 0xff;
          bVar8 = pbVar10[uVar17 + 2];
          uVar21 = uVar21 + bVar8 & 0xff;
          bVar16 = pbVar10[uVar21 + 2];
          pbVar10[uVar17 + 2] = bVar16;
          pbVar10[uVar21 + 2] = bVar8;
          *(byte *)((int)puVar14 + 3) =
               pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar12 + 3);
          if (uVar19 != 4) {
            uVar17 = uVar5 + 5 & 0xff;
            bVar8 = pbVar10[uVar17 + 2];
            uVar21 = uVar21 + bVar8 & 0xff;
            bVar16 = pbVar10[uVar21 + 2];
            pbVar10[uVar17 + 2] = bVar16;
            pbVar10[uVar21 + 2] = bVar8;
            *(byte *)(puVar14 + 1) =
                 pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)(puVar12 + 1);
            if (uVar19 != 5) {
              uVar17 = uVar5 + 6 & 0xff;
              bVar8 = pbVar10[uVar17 + 2];
              uVar21 = uVar21 + bVar8 & 0xff;
              bVar16 = pbVar10[uVar21 + 2];
              pbVar10[uVar17 + 2] = bVar16;
              pbVar10[uVar21 + 2] = bVar8;
              *(byte *)((int)puVar14 + 5) =
                   pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar12 + 5);
              if (uVar19 != 6) {
                uVar5 = uVar5 + 7 & 0xff;
                bVar8 = pbVar10[uVar5 + 2];
                uVar17 = uVar21 + bVar8 & 0xff;
                bVar16 = pbVar10[uVar17 + 2];
                pbVar10[uVar5 + 2] = bVar16;
                pbVar10[uVar17 + 2] = bVar8;
                *(byte *)((int)puVar14 + 6) =
                     pbVar10[((uint)bVar8 + (uint)bVar16 & 0xff) + 2] ^ *(byte *)((int)puVar12 + 6);
                *pbVar10 = (byte)uVar5;
                pbVar10[1] = (byte)uVar17;
                return;
              }
            }
          }
        }
      }
    }
  }
  bVar8 = (byte)uVar21;
  bVar16 = (byte)uVar17;
LAB_004e4cb4:
  *pbVar10 = bVar16;
  pbVar10[1] = bVar8;
  return;
}

