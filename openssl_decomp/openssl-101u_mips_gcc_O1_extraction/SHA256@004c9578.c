
uchar * SHA256(uchar *d,size_t n,uchar *md)

{
  undefined *puVar1;
  uint uVar2;
  uchar uVar3;
  uchar uVar4;
  undefined *puVar5;
  uchar uVar7;
  undefined *puVar6;
  uchar uVar8;
  int iVar10;
  uchar uVar11;
  uchar uVar13;
  uchar uVar15;
  uchar uVar18;
  uchar uVar21;
  uchar uVar24;
  uchar uVar27;
  uchar uVar29;
  uchar uVar31;
  uchar uVar33;
  undefined1 *puVar34;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  uint local_70;
  undefined local_6c [56];
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  size_t local_2c;
  uint local_28;
  int local_24;
  uchar uVar9;
  uchar uVar12;
  uchar uVar14;
  uchar uVar16;
  uchar uVar17;
  uchar uVar19;
  uchar uVar20;
  uchar uVar22;
  uchar uVar23;
  uchar uVar25;
  uchar uVar26;
  uchar uVar28;
  uchar uVar30;
  uchar uVar32;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar34 = md;
  if (md == (uchar *)0x0) {
    puVar34 = m_3952;
  }
  (*(code *)PTR_memset_006a99f4)(&local_94,0,0x70);
  local_84 = 0x510e527f;
  local_80 = 0x9b05688c;
  local_94 = 0x6a09e667;
  local_90 = 0xbb67ae85;
  local_8c = 0x3c6ef372;
  local_88 = 0xa54ff53a;
  local_7c = 0x1f83d9ab;
  local_78 = 0x5be0cd19;
  local_28 = 0x20;
  if (n != 0) {
    local_70 = n >> 0x1d;
    local_74 = n << 3;
    uVar2 = n >> 6;
    if (uVar2 == 0) goto LAB_004c9984;
    puVar6 = (undefined *)(n & 0xffffffc0);
    n = n - (int)puVar6;
    sha256_block_data_order(&local_94,d,uVar2);
    if (n != 0) goto LAB_004c9b28;
    puVar6 = local_6c + local_2c;
    goto LAB_004c99b4;
  }
  uVar2 = 1;
  local_6c[0] = 0x80;
LAB_004c965c:
  puVar5 = local_6c + uVar2;
  iVar10 = 0x38 - uVar2;
  do {
    puVar6 = local_6c;
    (*(code *)PTR_memset_006a99f4)(puVar5,0,iVar10);
    local_31 = (undefined)local_70;
    local_2d = (undefined)local_74;
    local_34 = (undefined)(local_70 >> 0x18);
    local_33 = (undefined)(local_70 >> 0x10);
    local_30 = (undefined)((uint)local_74 >> 0x18);
    local_32 = (undefined)(local_70 >> 8);
    local_2f = (undefined)((uint)local_74 >> 0x10);
    local_2e = (undefined)((uint)local_74 >> 8);
    sha256_block_data_order(&local_94,puVar6,1);
    local_2c = 0;
    OPENSSL_cleanse(puVar6,0x40);
    uVar15 = (uchar)local_94;
    uVar18 = (uchar)((uint)local_94 >> 8);
    uVar21 = (uchar)((uint)local_94 >> 0x10);
    uVar24 = (uchar)((uint)local_94 >> 0x18);
    uVar13 = (uchar)local_90;
    uVar27 = (uchar)((uint)local_90 >> 8);
    uVar29 = (uchar)((uint)local_90 >> 0x10);
    uVar31 = (uchar)((uint)local_90 >> 0x18);
    uVar11 = (uchar)local_8c;
    uVar19 = (uchar)((uint)local_8c >> 8);
    uVar22 = (uchar)((uint)local_8c >> 0x10);
    uVar25 = (uchar)((uint)local_8c >> 0x18);
    uVar8 = (uchar)local_88;
    uVar32 = (uchar)((uint)local_88 >> 8);
    uVar33 = (uchar)((uint)local_88 >> 0x10);
    uVar16 = (uchar)((uint)local_88 >> 0x18);
    uVar7 = (uchar)local_84;
    uVar26 = (uchar)((uint)local_84 >> 8);
    uVar28 = (uchar)((uint)local_84 >> 0x10);
    uVar30 = (uchar)((uint)local_84 >> 0x18);
    uVar4 = (uchar)local_80;
    uVar17 = (uchar)((uint)local_80 >> 8);
    uVar20 = (uchar)((uint)local_80 >> 0x10);
    uVar23 = (uchar)((uint)local_80 >> 0x18);
    uVar3 = (uchar)local_7c;
    uVar9 = (uchar)((uint)local_7c >> 8);
    uVar12 = (uchar)((uint)local_7c >> 0x10);
    uVar14 = (uchar)((uint)local_7c >> 0x18);
    if (local_28 == 0x1c) {
      *puVar34 = uVar24;
      puVar34[1] = uVar21;
      puVar34[2] = uVar18;
      puVar34[3] = uVar15;
      puVar34[4] = uVar31;
      puVar34[5] = uVar29;
      puVar34[6] = uVar27;
      puVar34[7] = uVar13;
      puVar34[8] = uVar25;
      puVar34[9] = uVar22;
      puVar34[10] = uVar19;
      puVar34[0xb] = uVar11;
      puVar34[0xc] = uVar16;
      puVar34[0xf] = uVar8;
      puVar34[0xd] = uVar33;
      puVar34[0xe] = uVar32;
      puVar34[0x10] = uVar30;
      puVar34[0x11] = uVar28;
      puVar34[0x12] = uVar26;
      puVar34[0x13] = uVar7;
      puVar34[0x14] = uVar23;
      puVar34[0x15] = uVar20;
      puVar34[0x16] = uVar17;
      puVar34[0x17] = uVar4;
      puVar34[0x18] = uVar14;
      puVar34[0x19] = uVar12;
      puVar34[0x1a] = uVar9;
      puVar34[0x1b] = uVar3;
    }
    else if (local_28 == 0x20) {
      *puVar34 = uVar24;
      puVar34[1] = uVar21;
      puVar34[2] = uVar18;
      puVar34[3] = uVar15;
      puVar34[4] = uVar31;
      puVar34[5] = uVar29;
      puVar34[6] = uVar27;
      puVar34[7] = uVar13;
      puVar34[8] = uVar25;
      puVar34[9] = uVar22;
      puVar34[10] = uVar19;
      puVar34[0xb] = uVar11;
      puVar34[0xc] = uVar16;
      puVar34[0xf] = uVar8;
      puVar34[0x17] = uVar4;
      puVar34[0xd] = uVar33;
      puVar34[0xe] = uVar32;
      puVar34[0x10] = uVar30;
      puVar34[0x11] = uVar28;
      puVar34[0x12] = uVar26;
      puVar34[0x13] = uVar7;
      puVar34[0x14] = uVar23;
      puVar34[0x15] = uVar20;
      puVar34[0x16] = uVar17;
      puVar34[0x18] = uVar14;
      puVar34[0x19] = uVar12;
      puVar34[0x1a] = uVar9;
      puVar34[0x1b] = uVar3;
LAB_004c97dc:
      puVar34[0x1f] = (uchar)local_78;
      puVar34[0x1c] = (uchar)((uint)local_78 >> 0x18);
      puVar34[0x1d] = (uchar)((uint)local_78 >> 0x10);
      puVar34[0x1e] = (uchar)((uint)local_78 >> 8);
    }
    else {
      uVar2 = local_28 >> 2;
      if ((local_28 < 0x21) && (uVar2 != 0)) {
        puVar34[3] = uVar15;
        *puVar34 = uVar24;
        puVar34[1] = uVar21;
        puVar34[2] = uVar18;
        if (uVar2 != 1) {
          puVar34[7] = uVar13;
          puVar34[4] = uVar31;
          puVar34[5] = uVar29;
          puVar34[6] = uVar27;
          if (uVar2 != 2) {
            puVar34[0xb] = uVar11;
            puVar34[8] = uVar25;
            puVar34[9] = uVar22;
            puVar34[10] = uVar19;
            if (uVar2 != 3) {
              puVar34[0xf] = uVar8;
              puVar34[0xc] = uVar16;
              puVar34[0xd] = uVar33;
              puVar34[0xe] = uVar32;
              if (uVar2 != 4) {
                puVar34[0x13] = uVar7;
                puVar34[0x10] = uVar30;
                puVar34[0x11] = uVar28;
                puVar34[0x12] = uVar26;
                if (uVar2 != 5) {
                  puVar34[0x17] = uVar4;
                  puVar34[0x14] = uVar23;
                  puVar34[0x15] = uVar20;
                  puVar34[0x16] = uVar17;
                  if (uVar2 != 6) {
                    puVar34[0x1b] = uVar3;
                    puVar34[0x18] = uVar14;
                    puVar34[0x19] = uVar12;
                    puVar34[0x1a] = uVar9;
                    if (uVar2 == 8) goto LAB_004c97dc;
                  }
                }
              }
            }
          }
        }
      }
    }
    OPENSSL_cleanse(&local_94,0x70);
    if (local_24 == *(int *)puVar1) {
      return puVar34;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004c9b28:
    d = d + (int)puVar6;
LAB_004c9984:
    local_2c = n;
    (*(code *)PTR___memcpy_chk_006a9a48)(local_6c,d,n,0x48);
    puVar6 = local_6c + local_2c;
LAB_004c99b4:
    puVar5 = local_6c;
    uVar2 = local_2c + 1;
    *puVar6 = 0x80;
    if (uVar2 < 0x39) goto LAB_004c965c;
    (*(code *)PTR_memset_006a99f4)(puVar5 + uVar2,0,0x40 - uVar2);
    sha256_block_data_order(&local_94,puVar5,1);
    iVar10 = 0x38;
  } while( true );
}

