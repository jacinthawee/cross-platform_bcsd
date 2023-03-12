
SSL_METHOD *
ssl3_cbc_digest_record
          (undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
          int param_5,int param_6,uint param_7,undefined4 param_8,uint param_9,char param_10)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  byte bVar8;
  byte bVar9;
  SSL_METHOD *pSVar7;
  int iVar10;
  char *pcVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  byte bVar26;
  uint uVar27;
  code *local_350;
  undefined4 local_348;
  code *local_340;
  uint local_33c;
  uint local_330;
  uint local_32c;
  int local_324;
  uint local_31c;
  uint *local_318;
  uint *local_30c;
  undefined4 local_2f4;
  char acStack_2f0 [24];
  undefined auStack_2d8 [212];
  byte abStack_204 [24];
  uint local_1ec;
  uint local_1e8;
  uint local_1e4;
  uint local_1e0;
  uint local_1dc;
  uint local_1d8;
  uint local_1d4;
  uint local_1d0;
  uint local_1cc;
  uint local_1c8;
  uint local_1c4;
  uint local_1c0;
  uint local_1bc;
  uint local_1b8;
  uint local_1b4;
  uint local_1b0;
  uint auStack_1ac [32];
  undefined4 local_12c [3];
  undefined local_120;
  undefined auStack_11f [115];
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  SSL_METHOD *local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(SSL_METHOD **)PTR___stack_chk_guard_006aabf0;
  if (0xfffff < param_7) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)
              ("s3_cbc.c",0x1d7,"data_plus_mac_plus_padding_size < 1024*1024");
  }
  uVar5 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1);
  iVar6 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar5);
  if (iVar6 == 0x2a0) {
    local_350 = (code *)PTR_SHA256_Transform_006a9274;
    iVar21 = 8;
    uVar19 = 0x40;
    (*(code *)PTR_SHA256_Init_006a9298)(auStack_2d8);
    iVar6 = 0x27;
    bVar3 = true;
    local_348 = 0x33;
    iVar10 = 0x200;
    local_31c = 0x28;
    local_324 = 0x20;
    local_340 = tls1_sha256_final_raw;
LAB_004928d4:
    if (param_10 == '\0') goto LAB_00492494;
LAB_004928e0:
    uVar13 = 2;
    uVar20 = param_9 + 0xb + local_31c;
    param_7 = param_7 + uVar20;
    uVar22 = (uVar20 - local_324) + param_6;
    if (uVar19 == 0) {
      trap(7);
    }
    local_33c = (param_7 + iVar6) / uVar19;
    if (uVar19 == 0) {
      trap(7);
    }
    local_330 = uVar22 / uVar19;
    uVar27 = uVar22 % uVar19;
    if (uVar19 == 0) {
      trap(7);
    }
    local_32c = (iVar21 + uVar22) / uVar19;
    if (local_33c < 4) goto LAB_004924fc;
LAB_00492948:
    uVar25 = local_33c - uVar13;
    iVar6 = uVar22 << 3;
    uVar23 = uVar19 * uVar25;
    if (param_10 == '\0') goto LAB_00492514;
LAB_00492960:
    if (!bVar3) goto LAB_004925d4;
LAB_00492974:
    (*(code *)PTR___memset_chk_006aaa98)(abStack_204 + 8,0,iVar21 + -4,0x10);
    abStack_204[iVar21 + 4] = (byte)((uint)iVar6 >> 0x18);
    abStack_204[iVar21 + 5] = (byte)((uint)iVar6 >> 0x10);
    abStack_204[iVar21 + 6] = (byte)((uint)iVar6 >> 8);
    abStack_204[iVar21 + 7] = (byte)iVar6;
    if (uVar23 != 0) goto LAB_00492618;
LAB_004929d0:
    (*(code *)PTR_memset_006aab00)(&local_1ec,0,0x40);
    if (uVar25 <= local_33c) goto LAB_0049272c;
LAB_00492ca4:
    (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(acStack_2f0);
    (*(code *)PTR_EVP_DigestInit_ex_006a8670)(acStack_2f0,*param_1,0);
    if (param_10 == '\0') goto LAB_00492cd8;
LAB_00492e28:
    local_318 = auStack_1ac;
    (*(code *)PTR_memset_006aab00)(local_318,0x5c,local_31c);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(acStack_2f0,param_8,param_9);
  }
  else {
    if (iVar6 < 0x2a1) {
      if (iVar6 == 4) {
        local_350 = (code *)PTR_MD5_Transform_006a9290;
        iVar21 = 8;
        uVar19 = 0x40;
        (*(code *)PTR_MD5_Init_006a9294)(auStack_2d8);
        iVar6 = 0x37;
        bVar3 = false;
        local_31c = 0x30;
        local_348 = 0x33;
        iVar10 = 0x200;
        local_324 = 0x10;
        local_340 = tls1_md5_final_raw;
      }
      else {
        local_350 = (code *)PTR_SHA1_Transform_006a9284;
        if (iVar6 != 0x40) {
LAB_00492a1c:
          pcVar11 = "s3_cbc.c";
          (*(code *)PTR_OpenSSLDie_006a8d4c)("s3_cbc.c",0x20d,"0");
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = 0xffffffff;
          }
          goto LAB_00492a4c;
        }
        iVar21 = 8;
        uVar19 = 0x40;
        (*(code *)PTR_SHA1_Init_006a9288)(auStack_2d8);
        iVar6 = 0x33;
        bVar3 = true;
        local_348 = 0x33;
        iVar10 = 0x200;
        local_31c = 0x28;
        local_324 = 0x14;
        local_340 = tls1_sha1_final_raw;
      }
      goto LAB_004928d4;
    }
    if (iVar6 == 0x2a2) {
      local_350 = (code *)PTR_SHA512_Transform_006a927c;
      iVar21 = 0x10;
      uVar19 = 0x80;
      (*(code *)PTR_SHA512_Init_006a9280)(auStack_2d8);
      iVar6 = 0x4f;
      bVar3 = true;
      local_348 = 0x73;
      iVar10 = 0x400;
      local_31c = 0x28;
      local_324 = 0x40;
      local_340 = tls1_sha512_final_raw;
      goto LAB_004928d4;
    }
    if (iVar6 < 0x2a2) {
      local_350 = (code *)PTR_SHA512_Transform_006a927c;
      iVar21 = 0x10;
      uVar19 = 0x80;
      (*(code *)PTR_SHA384_Init_006a928c)(auStack_2d8);
      iVar6 = 0x5f;
      bVar3 = true;
      local_348 = 0x73;
      iVar10 = 0x400;
      local_31c = 0x28;
      local_324 = 0x30;
      local_340 = tls1_sha512_final_raw;
      goto LAB_004928d4;
    }
    local_350 = (code *)PTR_SHA256_Transform_006a9274;
    if (iVar6 != 0x2a3) goto LAB_00492a1c;
    iVar21 = 8;
    uVar19 = 0x40;
    (*(code *)PTR_SHA224_Init_006a9278)(auStack_2d8);
    iVar6 = 0x2b;
    bVar3 = true;
    local_348 = 0x33;
    local_31c = 0x28;
    local_324 = 0x1c;
    local_340 = tls1_sha256_final_raw;
    iVar10 = 0x200;
    if (param_10 != '\0') goto LAB_004928e0;
LAB_00492494:
    uVar22 = (param_6 + 0xd) - local_324;
    if (uVar19 == 0) {
      trap(7);
    }
    local_33c = ((param_7 + 0xc + uVar19 + iVar21) - local_324) / uVar19;
    param_7 = param_7 + 0xd;
    uVar13 = 6;
    uVar20 = 0xd;
    if (uVar19 == 0) {
      trap(7);
    }
    local_330 = uVar22 / uVar19;
    uVar27 = uVar22 % uVar19;
    if (uVar19 == 0) {
      trap(7);
    }
    local_32c = (iVar21 + uVar22) / uVar19;
    if (6 < local_33c) goto LAB_00492948;
LAB_004924fc:
    uVar23 = 0;
    uVar25 = 0;
    iVar6 = uVar22 << 3;
    local_33c = uVar13;
    if (param_10 != '\0') goto LAB_00492960;
LAB_00492514:
    iVar6 = iVar6 + iVar10;
    (*(code *)PTR_memset_006aab00)(auStack_1ac,0,uVar19);
    if (0x80 < param_9) {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("s3_cbc.c",0x266,"mac_secret_length <= sizeof(hmac_pad)");
    }
    (*(code *)PTR___memcpy_chk_006aab54)(auStack_1ac,param_8,param_9,0x80);
    uVar13 = 0;
    puVar15 = auStack_1ac;
    do {
      uVar13 = uVar13 + 1;
      *puVar15 = *puVar15 ^ 0x36363636;
      puVar15 = puVar15 + 1;
    } while (uVar13 < (uVar19 - 4 >> 2) + 1);
    (*local_350)(auStack_2d8,auStack_1ac);
    if (bVar3) goto LAB_00492974;
LAB_004925d4:
    (*(code *)PTR_memset_006aab00)(abStack_204 + 8,0,iVar21);
    abStack_204[iVar21 + 3] = (byte)((uint)iVar6 >> 0x18);
    abStack_204[iVar21 + 2] = (byte)((uint)iVar6 >> 0x10);
    abStack_204[iVar21 + 1] = (byte)((uint)iVar6 >> 8);
    abStack_204[iVar21] = (byte)iVar6;
    if (uVar23 == 0) goto LAB_004929d0;
LAB_00492618:
    if (param_10 != '\0') {
      (*local_350)(auStack_2d8,param_4);
      iVar6 = uVar20 - uVar19;
      (*(code *)PTR___memcpy_chk_006aab54)(local_12c,(int)param_4 + uVar19,iVar6,0x80);
      (*(code *)PTR_memcpy_006aabf4)((int)local_12c + iVar6,param_5,uVar19 - iVar6);
      (*local_350)(auStack_2d8,local_12c);
      if (uVar19 == 0) {
        trap(7);
      }
      uVar13 = uVar23 / uVar19 - 1;
      if (1 < uVar13) {
        iVar6 = param_5 + (uVar19 - iVar6);
        uVar22 = 1;
        do {
          uVar22 = uVar22 + 1;
          (*local_350)(auStack_2d8,iVar6);
          iVar6 = iVar6 + uVar19;
        } while (uVar13 != uVar22);
      }
      (*(code *)PTR_memset_006aab00)(&local_1ec,0,0x40);
      if (uVar25 <= local_33c) goto LAB_0049272c;
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(acStack_2f0);
      (*(code *)PTR_EVP_DigestInit_ex_006a8670)(acStack_2f0,*param_1,0);
      goto LAB_00492e28;
    }
    local_12c[0] = *param_4;
    local_12c[1] = param_4[1];
    local_12c[2] = param_4[2];
    local_120 = *(undefined *)(param_4 + 3);
    (*(code *)PTR_memcpy_006aabf4)(auStack_11f,param_5,local_348);
    (*local_350)(auStack_2d8,local_12c);
    if (uVar19 == 0) {
      trap(7);
    }
    if (1 < uVar23 / uVar19) {
      iVar6 = param_5 + (uVar19 - 0xd);
      uVar13 = 1;
      do {
        uVar13 = uVar13 + 1;
        (*local_350)(auStack_2d8,iVar6);
        iVar6 = iVar6 + uVar19;
      } while (uVar23 / uVar19 != uVar13);
    }
    (*(code *)PTR_memset_006aab00)(&local_1ec,0,0x40);
    if (uVar25 <= local_33c) {
LAB_0049272c:
      uVar13 = local_324 - 4U >> 2;
      do {
        uVar14 = 0;
        iVar6 = (uVar25 ^ local_32c) - 1;
        pbVar17 = abStack_204 + (iVar21 - uVar19) + 8;
        bVar26 = ~(byte)(iVar6 >> 0x1f);
        pbVar16 = (byte *)((int)param_4 + uVar23);
        bVar2 = (byte)((uVar25 ^ local_330) - 1 >> 0x18);
        bVar1 = (char)bVar2 >> 7;
        pbVar18 = (byte *)(param_5 + (uVar23 - uVar20));
        uVar24 = iVar6 >> 0x1f & 0xff;
        uVar22 = uVar23;
        puVar15 = &local_ac;
        do {
          bVar8 = 0x80;
          if (uVar22 < uVar20) {
            bVar9 = *pbVar16;
            bVar8 = bVar9 ^ 0x80;
          }
          else if (uVar22 < param_7) {
            bVar9 = *pbVar18;
            bVar8 = bVar9 ^ 0x80;
          }
          else {
            bVar9 = 0;
          }
          bVar12 = bVar1;
          if (-1 < (int)((uVar27 - 1) - uVar14)) {
            bVar12 = 0;
          }
          uVar22 = uVar22 + 1;
          bVar8 = (bVar26 | bVar1) & ~((char)(bVar2 & (byte)(uVar27 - uVar14 >> 0x18)) >> 7) &
                  (bVar9 ^ bVar8 & bVar12);
          if (uVar19 - iVar21 <= uVar14) {
            bVar8 = (byte)uVar24 & *pbVar17 | bVar8 & bVar26;
          }
          uVar14 = uVar14 + 1;
          *(byte *)puVar15 = bVar8;
          pbVar17 = pbVar17 + 1;
          puVar15 = (uint *)((int)puVar15 + 1);
          pbVar16 = pbVar16 + 1;
          pbVar18 = pbVar18 + 1;
        } while (uVar19 != uVar14);
        (*local_350)(auStack_2d8,&local_ac);
        (*local_340)(auStack_2d8,&local_ac);
        uVar23 = uVar23 + uVar19;
        uVar24 = uVar24 << 0x18 | uVar24 << 0x10 | uVar24 << 8 | uVar24;
        local_1ec = uVar24 & local_ac | local_1ec;
        local_1e8 = uVar24 & local_a8 | local_1e8;
        local_1e0 = uVar24 & local_a0 | local_1e0;
        local_1e4 = uVar24 & local_a4 | local_1e4;
        if (((((uVar13 != 3) && (local_1dc = uVar24 & local_9c | local_1dc, uVar13 != 4)) &&
             (local_1d8 = uVar24 & local_98 | local_1d8, uVar13 != 5)) &&
            ((((local_1d4 = uVar24 & local_94 | local_1d4, uVar13 != 6 &&
               (local_1d0 = uVar24 & local_90 | local_1d0, uVar13 != 7)) &&
              ((local_1cc = uVar24 & local_8c | local_1cc, uVar13 != 8 &&
               ((local_1c8 = uVar24 & local_88 | local_1c8, uVar13 != 9 &&
                (local_1c4 = uVar24 & local_84 | local_1c4, uVar13 != 10)))))) &&
             (local_1c0 = uVar24 & local_80 | local_1c0, uVar13 != 0xb)))) &&
           (((local_1bc = uVar24 & local_7c | local_1bc, uVar13 != 0xc &&
             (local_1b8 = uVar24 & local_78 | local_1b8, uVar13 != 0xd)) &&
            (local_1b4 = uVar24 & local_74 | local_1b4, uVar13 == 0xf)))) {
          local_1b0 = uVar24 & local_70 | local_1b0;
        }
        uVar25 = uVar25 + 1;
      } while (uVar25 <= local_33c);
      goto LAB_00492ca4;
    }
    (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(acStack_2f0);
    (*(code *)PTR_EVP_DigestInit_ex_006a8670)(acStack_2f0,*param_1,0);
LAB_00492cd8:
    local_31c = uVar19;
    local_318 = auStack_1ac;
    uVar19 = 0;
    do {
      uVar19 = uVar19 + 1;
      *local_318 = *local_318 ^ 0x6a6a6a6a;
      local_318 = local_318 + 1;
    } while (uVar19 < (local_31c - 4 >> 2) + 1);
  }
  local_30c = &local_1ec;
  pcVar11 = acStack_2f0;
  (*(code *)PTR_EVP_DigestUpdate_006a8674)(pcVar11,auStack_1ac,local_31c);
  (*(code *)PTR_EVP_DigestUpdate_006a8674)(pcVar11,local_30c,local_324);
  (*(code *)PTR_EVP_DigestFinal_006a8f34)(pcVar11,param_2,&local_2f4);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_2f4;
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)();
LAB_00492a4c:
  if (local_2c == *(SSL_METHOD **)puVar4) {
    return *(SSL_METHOD **)puVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (pcVar11 == &SUB_00000002) {
    pSVar7 = SSLv2_server_method();
    return pSVar7;
  }
  if (pcVar11 == (char *)0x300) {
    pSVar7 = SSLv3_server_method();
    return pSVar7;
  }
  if (pcVar11 == (char *)0x301) {
    pSVar7 = TLSv1_server_method();
    return pSVar7;
  }
  if (pcVar11 == (char *)0x302) {
    pSVar7 = TLSv1_1_server_method();
    return pSVar7;
  }
  if (pcVar11 != (char *)0x303) {
    return (SSL_METHOD *)0x0;
  }
  pSVar7 = TLSv1_2_server_method();
  return pSVar7;
}

