
uchar * SHA512(uchar *d,size_t n,uchar *md)

{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uchar uVar6;
  uchar uVar7;
  uchar uVar8;
  uchar uVar9;
  uchar uVar10;
  uchar uVar11;
  uchar uVar12;
  uchar uVar13;
  uchar uVar14;
  uchar uVar15;
  uchar uVar16;
  uchar uVar17;
  uchar uVar18;
  uint uVar19;
  uchar uVar20;
  size_t sVar38;
  undefined4 *puVar39;
  uint uVar40;
  int in_GS_OFFSET;
  byte bVar41;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  uint local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined local_a8;
  undefined4 auStack_a7 [27];
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  uint local_28;
  int local_24;
  int local_20;
  uchar uVar21;
  uchar uVar22;
  uchar uVar23;
  uchar uVar24;
  uchar uVar25;
  uchar uVar26;
  uchar uVar27;
  uchar uVar28;
  uchar uVar29;
  uchar uVar30;
  uchar uVar31;
  uchar uVar32;
  uchar uVar33;
  uchar uVar34;
  uchar uVar35;
  uchar uVar36;
  uchar uVar37;
  
  bVar41 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_f8 = 0xf3bcc908;
  local_f4 = 0x6a09e667;
  local_f0 = 0x84caa73b;
  if (md == (uchar *)0x0) {
    md = m_5408;
  }
  local_ec = 0xbb67ae85;
  local_e8 = 0xfe94f82b;
  local_e4 = 0x3c6ef372;
  local_e0 = 0x5f1d36f1;
  local_dc = 0xa54ff53a;
  local_d8 = 0xade682d1;
  local_d4 = 0x510e527f;
  local_d0 = 0x2b3e6c1f;
  local_cc = 0x9b05688c;
  local_c8 = 0xfb41bd6b;
  local_c4 = 0x1f83d9ab;
  local_c0 = 0x137e2179;
  local_bc = 0x5be0cd19;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_28 = 0;
  local_24 = 0x40;
  if (n == 0) {
    puVar39 = (undefined4 *)(&local_a8 + 1);
    local_a8 = 0x80;
    uVar40 = 0x6f;
LAB_080df052:
    if (uVar40 < 4) {
      if ((uVar40 != 0) && (*(undefined *)puVar39 = 0, (uVar40 & 2) != 0)) {
        *(undefined2 *)((int)puVar39 + (uVar40 - 2)) = 0;
      }
      goto LAB_080dece2;
    }
  }
  else {
    local_b4 = n >> 0x1d;
    local_b8 = n << 3;
    sVar38 = n;
    if (n < 0x80) {
LAB_080dec56:
      __memcpy_chk(&local_a8,d,sVar38,0x88);
      local_28 = sVar38;
    }
    else {
      sha512_block_data_order();
      sVar38 = n & 0x7f;
      if (sVar38 != 0) {
        d = d + (n - sVar38);
        goto LAB_080dec56;
      }
    }
    uVar19 = local_28;
    (&local_a8)[local_28] = 0x80;
    uVar40 = uVar19 + 1;
    if (uVar40 < 0x71) {
      uVar40 = 0x70 - uVar40;
      puVar39 = (undefined4 *)(&local_a8 + uVar19 + 1);
      goto LAB_080df052;
    }
    memset(&local_a8 + uVar19 + 1,0,0x80 - uVar40);
    sha512_block_data_order_constprop_1();
    puVar39 = (undefined4 *)&local_a8;
    uVar40 = 0x70;
  }
  *puVar39 = 0;
  *(undefined4 *)((int)puVar39 + (uVar40 - 4)) = 0;
  uVar40 = (uint)((int)puVar39 + (uVar40 - (int)(undefined4 *)((uint)(puVar39 + 1) & 0xfffffffc)))
           >> 2;
  puVar39 = (undefined4 *)((uint)(puVar39 + 1) & 0xfffffffc);
  for (; uVar40 != 0; uVar40 = uVar40 - 1) {
    *puVar39 = 0;
    puVar39 = puVar39 + (uint)bVar41 * -2 + 1;
  }
LAB_080dece2:
  local_29 = (undefined)local_b8;
  local_2a = (undefined)((uint)local_b8 >> 8);
  local_2d = (undefined)local_b4;
  local_2b = (undefined)((uint)local_b8 >> 0x10);
  local_2c = (undefined)((uint)local_b8 >> 0x18);
  local_2f = (undefined)(local_b4 >> 0x10);
  local_30 = (undefined)(local_b4 >> 0x18);
  local_2e = (undefined)(local_b4 >> 8);
  local_31 = (undefined)local_b0;
  local_32 = (undefined)((uint)local_b0 >> 8);
  local_35 = (undefined)local_ac;
  local_33 = (undefined)((uint)local_b0 >> 0x10);
  local_34 = (undefined)((uint)local_b0 >> 0x18);
  local_37 = (undefined)((uint)local_ac >> 0x10);
  local_38 = (undefined)((uint)local_ac >> 0x18);
  local_36 = (undefined)((uint)local_ac >> 8);
  sha512_block_data_order_constprop_1();
  uVar20 = (uchar)((uint)local_f4 >> 8);
  uVar21 = (uchar)((uint)local_f4 >> 0x10);
  uVar22 = (uchar)((uint)local_f4 >> 0x18);
  uVar3 = (uchar)((uint)local_f8 >> 8);
  uVar2 = (uchar)((uint)local_f8 >> 0x10);
  uVar1 = (uchar)((uint)local_f8 >> 0x18);
  uVar23 = (uchar)((uint)local_ec >> 8);
  uVar24 = (uchar)((uint)local_ec >> 0x10);
  uVar25 = (uchar)((uint)local_ec >> 0x18);
  uVar6 = (uchar)((uint)local_f0 >> 8);
  uVar5 = (uchar)((uint)local_f0 >> 0x10);
  uVar4 = (uchar)((uint)local_f0 >> 0x18);
  uVar26 = (uchar)((uint)local_e4 >> 8);
  uVar27 = (uchar)((uint)local_e4 >> 0x10);
  uVar28 = (uchar)((uint)local_e4 >> 0x18);
  uVar9 = (uchar)((uint)local_e8 >> 8);
  uVar8 = (uchar)((uint)local_e8 >> 0x10);
  uVar7 = (uchar)((uint)local_e8 >> 0x18);
  uVar29 = (uchar)((uint)local_dc >> 8);
  uVar30 = (uchar)((uint)local_dc >> 0x10);
  uVar31 = (uchar)((uint)local_dc >> 0x18);
  uVar12 = (uchar)((uint)local_e0 >> 8);
  uVar11 = (uchar)((uint)local_e0 >> 0x10);
  uVar10 = (uchar)((uint)local_e0 >> 0x18);
  uVar32 = (uchar)((uint)local_d4 >> 8);
  uVar33 = (uchar)((uint)local_d4 >> 0x10);
  uVar34 = (uchar)((uint)local_d4 >> 0x18);
  uVar15 = (uchar)((uint)local_d8 >> 8);
  uVar14 = (uchar)((uint)local_d8 >> 0x10);
  uVar13 = (uchar)((uint)local_d8 >> 0x18);
  uVar35 = (uchar)((uint)local_cc >> 8);
  uVar36 = (uchar)((uint)local_cc >> 0x10);
  uVar37 = (uchar)((uint)local_cc >> 0x18);
  uVar18 = (uchar)((uint)local_d0 >> 8);
  uVar17 = (uchar)((uint)local_d0 >> 0x10);
  uVar16 = (uchar)((uint)local_d0 >> 0x18);
  if (local_24 == 0x30) {
    *md = uVar22;
    md[1] = uVar21;
    md[2] = uVar20;
    md[3] = (uchar)local_f4;
    md[4] = uVar1;
    md[5] = uVar2;
    md[6] = uVar3;
    md[7] = (uchar)local_f8;
    md[8] = uVar25;
    md[9] = uVar24;
    md[10] = uVar23;
    md[0xb] = (uchar)local_ec;
    md[0xc] = uVar4;
    md[0xd] = uVar5;
    md[0xe] = uVar6;
    md[0xf] = (uchar)local_f0;
    md[0x10] = uVar28;
    md[0x11] = uVar27;
    md[0x12] = uVar26;
    md[0x13] = (uchar)local_e4;
    md[0x14] = uVar7;
    md[0x15] = uVar8;
    md[0x16] = uVar9;
    md[0x17] = (uchar)local_e8;
    md[0x18] = uVar31;
    md[0x19] = uVar30;
    md[0x1a] = uVar29;
    md[0x1b] = (uchar)local_dc;
    md[0x1c] = uVar10;
    md[0x1d] = uVar11;
    md[0x1e] = uVar12;
    md[0x1f] = (uchar)local_e0;
    md[0x20] = uVar34;
    md[0x21] = uVar33;
    md[0x22] = uVar32;
    md[0x23] = (uchar)local_d4;
    md[0x24] = uVar13;
    md[0x25] = uVar14;
    md[0x26] = uVar15;
    md[0x27] = (uchar)local_d8;
    md[0x28] = uVar37;
    md[0x29] = uVar36;
    md[0x2a] = uVar35;
    md[0x2b] = (uchar)local_cc;
    md[0x2c] = uVar16;
    md[0x2d] = uVar17;
    md[0x2e] = uVar18;
    md[0x2f] = (uchar)local_d0;
  }
  else if (local_24 == 0x40) {
    *md = uVar22;
    md[1] = uVar21;
    md[2] = uVar20;
    md[3] = (uchar)local_f4;
    md[4] = uVar1;
    md[5] = uVar2;
    md[6] = uVar3;
    md[7] = (uchar)local_f8;
    md[8] = uVar25;
    md[9] = uVar24;
    md[10] = uVar23;
    md[0xb] = (uchar)local_ec;
    md[0xc] = uVar4;
    md[0xd] = uVar5;
    md[0xe] = uVar6;
    md[0xf] = (uchar)local_f0;
    md[0x10] = uVar28;
    md[0x11] = uVar27;
    md[0x12] = uVar26;
    md[0x13] = (uchar)local_e4;
    md[0x14] = uVar7;
    md[0x15] = uVar8;
    md[0x16] = uVar9;
    md[0x17] = (uchar)local_e8;
    md[0x18] = uVar31;
    md[0x19] = uVar30;
    md[0x1a] = uVar29;
    md[0x1b] = (uchar)local_dc;
    md[0x1c] = uVar10;
    md[0x1d] = uVar11;
    md[0x1e] = uVar12;
    md[0x1f] = (uchar)local_e0;
    md[0x20] = uVar34;
    md[0x21] = uVar33;
    md[0x22] = uVar32;
    md[0x23] = (uchar)local_d4;
    md[0x24] = uVar13;
    md[0x25] = uVar14;
    md[0x26] = uVar15;
    md[0x27] = (uchar)local_d8;
    md[0x28] = uVar37;
    md[0x29] = uVar36;
    md[0x2a] = uVar35;
    md[0x2b] = (uchar)local_cc;
    md[0x2c] = uVar16;
    md[0x2d] = uVar17;
    md[0x2e] = uVar18;
    md[0x2f] = (uchar)local_d0;
    md[0x30] = (uchar)((uint)local_c4 >> 0x18);
    md[0x31] = (uchar)((uint)local_c4 >> 0x10);
    md[0x32] = (uchar)((uint)local_c4 >> 8);
    md[0x33] = (uchar)local_c4;
    md[0x34] = (uchar)((uint)local_c8 >> 0x18);
    md[0x35] = (uchar)((uint)local_c8 >> 0x10);
    md[0x36] = (uchar)((uint)local_c8 >> 8);
    md[0x37] = (uchar)local_c8;
    md[0x38] = (uchar)((uint)local_bc >> 0x18);
    md[0x39] = (uchar)((uint)local_bc >> 0x10);
    md[0x3a] = (uchar)((uint)local_bc >> 8);
    md[0x3b] = (uchar)local_bc;
    md[0x3c] = (uchar)((uint)local_c0 >> 0x18);
    md[0x3d] = (uchar)((uint)local_c0 >> 0x10);
    md[0x3e] = (uchar)((uint)local_c0 >> 8);
    md[0x3f] = (uchar)local_c0;
  }
  OPENSSL_cleanse(&local_f8,0xd8);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return md;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

