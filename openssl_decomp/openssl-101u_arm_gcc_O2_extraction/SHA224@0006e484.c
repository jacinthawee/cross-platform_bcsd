
uchar * SHA224(uchar *d,size_t n,uchar *md)

{
  uchar uVar1;
  uchar uVar15;
  undefined *__s;
  undefined *puVar29;
  size_t sVar30;
  uint uVar31;
  uchar *puVar32;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  uint local_74;
  undefined local_70 [56];
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  size_t local_30;
  uint local_2c;
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
  uchar uVar16;
  uchar uVar17;
  uchar uVar18;
  uchar uVar19;
  uchar uVar20;
  uchar uVar21;
  uchar uVar22;
  uchar uVar23;
  uchar uVar24;
  uchar uVar25;
  uchar uVar26;
  uchar uVar27;
  uchar uVar28;
  
  puVar32 = &m_6579;
  if (md != (uchar *)0x0) {
    puVar32 = md;
  }
  memset(&local_98,0,0x70);
  local_7c = 0xbefa4fa4;
  local_98 = 0xc1059ed8;
  local_94 = 0x367cd507;
  local_90 = 0x3070dd17;
  local_8c = 0xf70e5939;
  local_88 = 0xffc00b31;
  local_84 = 0x68581511;
  local_80 = 0x64f98fa7;
  local_2c = 0x1c;
  if (n == 0) {
    uVar31 = 1;
    local_70[0] = 0x80;
LAB_0006e50c:
    __s = local_70 + uVar31;
    sVar30 = 0x38 - uVar31;
  }
  else {
    local_74 = n >> 0x1d;
    local_78 = n << 3;
    if (n >> 6 == 0) {
LAB_0006e704:
      local_30 = n;
      __memcpy_chk(local_70,d,n,0x48);
      puVar29 = local_70 + local_30;
    }
    else {
      uVar31 = n & 0xffffffc0;
      sha256_block_data_order(&local_98,d,n >> 6);
      n = n - uVar31;
      if (n != 0) {
        d = d + uVar31;
        goto LAB_0006e704;
      }
      puVar29 = local_70 + local_30;
    }
    sVar30 = local_30;
    __s = local_70;
    uVar31 = local_30 + 1;
    *puVar29 = 0x80;
    if (uVar31 < 0x39) goto LAB_0006e50c;
    memset(__s + uVar31,0,0x3f - sVar30);
    sha256_block_data_order(&local_98,__s,1);
    sVar30 = 0x38;
  }
  memset(__s,0,sVar30);
  local_35 = (undefined)local_74;
  local_38 = (undefined)(local_74 >> 0x18);
  local_37 = (undefined)(local_74 >> 0x10);
  local_31 = (undefined)local_78;
  local_36 = (undefined)(local_74 >> 8);
  local_34 = (undefined)((uint)local_78 >> 0x18);
  local_33 = (undefined)((uint)local_78 >> 0x10);
  local_32 = (undefined)((uint)local_78 >> 8);
  sha256_block_data_order(&local_98,local_70,1);
  local_30 = 0;
  OPENSSL_cleanse(local_70,0x40);
  uVar1 = (uchar)local_98;
  uVar15 = (uchar)((uint)local_98 >> 8);
  uVar16 = (uchar)((uint)local_98 >> 0x10);
  uVar17 = (uchar)((uint)local_98 >> 0x18);
  uVar2 = (uchar)local_94;
  uVar18 = (uchar)((uint)local_94 >> 8);
  uVar19 = (uchar)((uint)local_94 >> 0x10);
  uVar20 = (uchar)((uint)local_94 >> 0x18);
  uVar3 = (uchar)local_90;
  uVar4 = (uchar)((uint)local_90 >> 8);
  uVar21 = (uchar)((uint)local_90 >> 0x10);
  uVar22 = (uchar)((uint)local_90 >> 0x18);
  uVar5 = (uchar)local_8c;
  uVar23 = (uchar)((uint)local_8c >> 8);
  uVar24 = (uchar)((uint)local_8c >> 0x10);
  uVar6 = (uchar)((uint)local_8c >> 0x18);
  uVar7 = (uchar)local_88;
  uVar25 = (uchar)((uint)local_88 >> 8);
  uVar26 = (uchar)((uint)local_88 >> 0x10);
  uVar27 = (uchar)((uint)local_88 >> 0x18);
  uVar8 = (uchar)local_84;
  uVar9 = (uchar)((uint)local_84 >> 8);
  uVar10 = (uchar)((uint)local_84 >> 0x10);
  uVar28 = (uchar)((uint)local_84 >> 0x18);
  uVar11 = (uchar)local_80;
  uVar12 = (uchar)((uint)local_80 >> 8);
  uVar13 = (uchar)((uint)local_80 >> 0x10);
  uVar14 = (uchar)((uint)local_80 >> 0x18);
  if (local_2c == 0x1c) {
    puVar32[3] = uVar1;
    *puVar32 = uVar17;
    puVar32[1] = uVar16;
    puVar32[2] = uVar15;
    puVar32[7] = uVar2;
    puVar32[4] = uVar20;
    puVar32[5] = uVar19;
    puVar32[6] = uVar18;
    puVar32[0xb] = uVar3;
    puVar32[8] = uVar22;
    puVar32[9] = uVar21;
    puVar32[10] = uVar4;
    puVar32[0xf] = uVar5;
    puVar32[0xc] = uVar6;
    puVar32[0x13] = uVar7;
    puVar32[0xd] = uVar24;
    puVar32[0xe] = uVar23;
    puVar32[0x10] = uVar27;
    puVar32[0x11] = uVar26;
    puVar32[0x12] = uVar25;
    puVar32[0x17] = uVar8;
    puVar32[0x14] = uVar28;
    puVar32[0x15] = uVar10;
    puVar32[0x16] = uVar9;
    puVar32[0x18] = uVar14;
    puVar32[0x19] = uVar13;
    puVar32[0x1a] = uVar12;
    puVar32[0x1b] = uVar11;
    goto LAB_0006e624;
  }
  if (local_2c == 0x20) {
    puVar32[3] = uVar1;
    *puVar32 = uVar17;
    puVar32[1] = uVar16;
    puVar32[2] = uVar15;
    puVar32[7] = uVar2;
    puVar32[4] = uVar20;
    puVar32[5] = uVar19;
    puVar32[6] = uVar18;
    puVar32[0xb] = uVar3;
    puVar32[8] = uVar22;
    puVar32[9] = uVar21;
    puVar32[10] = uVar4;
    puVar32[0xf] = uVar5;
    puVar32[0xc] = uVar6;
    puVar32[0x13] = uVar7;
    puVar32[0x17] = uVar8;
    puVar32[0xd] = uVar24;
    puVar32[0xe] = uVar23;
    puVar32[0x10] = uVar27;
    puVar32[0x11] = uVar26;
    puVar32[0x12] = uVar25;
    puVar32[0x14] = uVar28;
    puVar32[0x15] = uVar10;
    puVar32[0x16] = uVar9;
    puVar32[0x18] = uVar14;
    puVar32[0x19] = uVar13;
    puVar32[0x1a] = uVar12;
    puVar32[0x1b] = uVar11;
  }
  else {
    if ((0x20 < local_2c) || (uVar31 = local_2c >> 2, uVar31 == 0)) goto LAB_0006e624;
    puVar32[3] = uVar1;
    *puVar32 = uVar17;
    puVar32[1] = uVar16;
    puVar32[2] = uVar15;
    if (uVar31 < 2) goto LAB_0006e624;
    puVar32[7] = uVar2;
    puVar32[4] = uVar20;
    puVar32[5] = uVar19;
    puVar32[6] = uVar18;
    if (uVar31 < 3) goto LAB_0006e624;
    puVar32[0xb] = uVar3;
    puVar32[8] = uVar22;
    puVar32[9] = uVar21;
    puVar32[10] = uVar4;
    if (uVar31 < 4) goto LAB_0006e624;
    puVar32[0xf] = uVar5;
    puVar32[0xc] = uVar6;
    puVar32[0xd] = uVar24;
    puVar32[0xe] = uVar23;
    if (uVar31 < 5) goto LAB_0006e624;
    puVar32[0x13] = uVar7;
    puVar32[0x10] = uVar27;
    puVar32[0x11] = uVar26;
    puVar32[0x12] = uVar25;
    if (uVar31 < 6) goto LAB_0006e624;
    puVar32[0x17] = uVar8;
    puVar32[0x14] = uVar28;
    puVar32[0x15] = uVar10;
    puVar32[0x16] = uVar9;
    if (uVar31 < 7) goto LAB_0006e624;
    puVar32[0x1b] = uVar11;
    puVar32[0x18] = uVar14;
    puVar32[0x19] = uVar13;
    puVar32[0x1a] = uVar12;
    if (uVar31 < 8) goto LAB_0006e624;
  }
  puVar32[0x1f] = (uchar)local_7c;
  puVar32[0x1c] = (uchar)((uint)local_7c >> 0x18);
  puVar32[0x1d] = (uchar)((uint)local_7c >> 0x10);
  puVar32[0x1e] = (uchar)((uint)local_7c >> 8);
LAB_0006e624:
  OPENSSL_cleanse(&local_98,0x70);
  return puVar32;
}

