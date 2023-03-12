
SSL_METHOD *
ssl3_cbc_digest_record
          (undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
          int param_5,int param_6,uint param_7,undefined4 param_8,uint param_9,char param_10)

{
  bool bVar1;
  byte bVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  SSL_METHOD *pSVar7;
  byte bVar8;
  int iVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  byte *pbVar16;
  byte *pbVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  byte *pbVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  undefined *local_350;
  code *local_34c;
  int local_344;
  code *local_33c;
  uint local_330;
  uint local_32c;
  int local_324;
  int local_318;
  undefined4 local_2f4;
  undefined auStack_2f0 [24];
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
  uint local_1ac [32];
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
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (0xfffff < param_7) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)
              ("s3_cbc.c",0x1c7,"data_plus_mac_plus_padding_size < 1024 * 1024");
  }
  uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1);
  iVar5 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar4);
  if (iVar5 == 0x2a0) {
    iVar5 = (*(code *)PTR_SHA256_Init_006a816c)(auStack_2d8);
    if (0 < iVar5) {
      local_34c = (code *)PTR_SHA256_Transform_006a814c;
      uVar4 = 0x33;
      iVar9 = 0x200;
      bVar1 = true;
      iVar21 = 8;
      iVar5 = 0x27;
      local_318 = 0x28;
      uVar19 = 0x40;
      local_324 = 0x20;
      local_33c = tls1_sha256_final_raw;
      goto LAB_0048e820;
    }
  }
  else if (iVar5 < 0x2a1) {
    if (iVar5 == 4) {
      iVar5 = (*(code *)PTR_MD5_Init_006a8160)(auStack_2d8);
      if (0 < iVar5) {
        local_34c = (code *)PTR_MD5_Transform_006a8164;
        uVar4 = 0x33;
        bVar1 = false;
        iVar9 = 0x200;
        local_318 = 0x30;
        iVar21 = 8;
        iVar5 = 0x37;
        local_324 = 0x10;
        uVar19 = 0x40;
        local_33c = tls1_md5_final_raw;
        goto LAB_0048e820;
      }
    }
    else if (iVar5 == 0x40) {
      iVar5 = (*(code *)PTR_SHA1_Init_006a8150)(auStack_2d8);
      if (0 < iVar5) {
        local_34c = (code *)PTR_SHA1_Transform_006a8154;
        uVar4 = 0x33;
        iVar9 = 0x200;
        bVar1 = true;
        iVar21 = 8;
        iVar5 = 0x33;
        local_318 = 0x28;
        uVar19 = 0x40;
        local_324 = 0x14;
        local_33c = tls1_sha1_final_raw;
        goto LAB_0048e820;
      }
    }
    else {
LAB_0048ec0c:
      (*(code *)PTR_OpenSSLDie_006a7c5c)("s3_cbc.c",0x209,"0");
      if (param_3 != (undefined4 *)0x0) {
        pSVar7 = (SSL_METHOD *)0x0;
        *param_3 = 0xffffffff;
        goto LAB_0048e774;
      }
    }
  }
  else if (iVar5 == 0x2a2) {
    iVar5 = (*(code *)PTR_SHA512_Init_006a8158)(auStack_2d8);
    if (0 < iVar5) {
      local_34c = (code *)PTR_SHA512_Transform_006a815c;
      uVar4 = 0x73;
      iVar9 = 0x400;
      bVar1 = true;
      iVar21 = 0x10;
      iVar5 = 0x4f;
      local_318 = 0x28;
      uVar19 = 0x80;
      local_324 = 0x40;
      local_33c = tls1_sha512_final_raw;
LAB_0048e820:
      if (param_10 == '\0') goto LAB_0048e5f8;
LAB_0048e82c:
      uVar20 = param_9 + 0xb + local_318;
      param_7 = param_7 + uVar20;
      local_344 = 2;
      if (uVar19 == 0) {
        trap(7);
      }
      uVar28 = (param_7 + iVar5) / uVar19;
      uVar18 = (uVar20 - local_324) + param_6;
      if (uVar19 == 0) {
        trap(7);
      }
      local_330 = uVar18 / uVar19;
      uVar27 = uVar18 % uVar19;
      if (uVar19 == 0) {
        trap(7);
      }
      local_32c = (iVar21 + uVar18) / uVar19;
      if (3 < uVar28) goto LAB_0048e898;
LAB_0048e660:
      uVar26 = 0;
      uVar28 = 0;
      iVar5 = uVar18 << 3;
      if (param_10 == '\0') goto LAB_0048e674;
LAB_0048e8b0:
      if (bVar1) goto LAB_0048e8bc;
LAB_0048e718:
      (*(code *)PTR_memset_006a99f4)(abStack_204 + 8,0,iVar21);
      abStack_204[iVar21 + 3] = (byte)((uint)iVar5 >> 0x18);
      abStack_204[iVar21 + 2] = (byte)((uint)iVar5 >> 0x10);
      abStack_204[iVar21 + 1] = (byte)((uint)iVar5 >> 8);
      abStack_204[iVar21] = (byte)iVar5;
      goto LAB_0048e758;
    }
  }
  else {
    if (0x2a1 < iVar5) {
      if (iVar5 != 0x2a3) goto LAB_0048ec0c;
      iVar5 = (*(code *)PTR_SHA224_Init_006a8148)(auStack_2d8);
      if (iVar5 < 1) goto LAB_0048e770;
      local_34c = (code *)PTR_SHA256_Transform_006a814c;
      uVar4 = 0x33;
      iVar9 = 0x200;
      bVar1 = true;
      iVar21 = 8;
      iVar5 = 0x2b;
      local_318 = 0x28;
      local_324 = 0x1c;
      local_33c = tls1_sha256_final_raw;
      uVar19 = 0x40;
      if (param_10 != '\0') goto LAB_0048e82c;
LAB_0048e5f8:
      uVar18 = (param_6 + 0xd) - local_324;
      if (uVar19 == 0) {
        trap(7);
      }
      uVar28 = ((param_7 + 0xc + uVar19 + iVar21) - local_324) / uVar19;
      local_344 = 6;
      param_7 = param_7 + 0xd;
      uVar20 = 0xd;
      if (uVar19 == 0) {
        trap(7);
      }
      local_330 = uVar18 / uVar19;
      uVar27 = uVar18 % uVar19;
      if (uVar19 == 0) {
        trap(7);
      }
      local_32c = (iVar21 + uVar18) / uVar19;
      if (uVar28 < 7) goto LAB_0048e660;
LAB_0048e898:
      iVar5 = uVar18 << 3;
      uVar28 = uVar28 - local_344;
      uVar26 = uVar19 * uVar28;
      if (param_10 != '\0') goto LAB_0048e8b0;
LAB_0048e674:
      local_350 = auStack_2d8;
      iVar5 = iVar5 + iVar9;
      (*(code *)PTR_memset_006a99f4)(local_1ac,0,uVar19);
      if (0x80 < param_9) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("s3_cbc.c",0x271,"mac_secret_length <= sizeof(hmac_pad)")
        ;
      }
      puVar6 = (uint *)(*(code *)PTR___memcpy_chk_006a9a48)(local_1ac,param_8,param_9,0x80);
      uVar18 = 0;
      puVar15 = puVar6;
      do {
        uVar18 = uVar18 + 1;
        *puVar15 = *puVar15 ^ 0x36363636;
        puVar15 = puVar15 + 1;
      } while (uVar18 < (uVar19 - 4 >> 2) + 1);
      (*local_34c)(local_350,puVar6);
      if (!bVar1) goto LAB_0048e718;
LAB_0048e8bc:
      (*(code *)PTR___memset_chk_006a998c)(abStack_204 + 8,0,iVar21 + -4,0x10);
      abStack_204[iVar21 + 4] = (byte)((uint)iVar5 >> 0x18);
      abStack_204[iVar21 + 5] = (byte)((uint)iVar5 >> 0x10);
      abStack_204[iVar21 + 6] = (byte)((uint)iVar5 >> 8);
      abStack_204[iVar21 + 7] = (byte)iVar5;
LAB_0048e758:
      local_350 = auStack_2d8;
      if (uVar26 != 0) {
        if (param_10 == '\0') {
          local_12c[0] = *param_4;
          local_12c[1] = param_4[1];
          local_12c[2] = param_4[2];
          local_120 = *(undefined *)(param_4 + 3);
          (*(code *)PTR_memcpy_006a9aec)(auStack_11f,param_5,uVar4);
          (*local_34c)(local_350,local_12c);
          if (uVar19 == 0) {
            trap(7);
          }
          if (1 < uVar26 / uVar19) {
            uVar18 = 1;
            iVar5 = param_5 + (uVar19 - 0xd);
            do {
              uVar18 = uVar18 + 1;
              (*local_34c)(local_350,iVar5);
              iVar5 = iVar5 + uVar19;
            } while (uVar26 / uVar19 != uVar18);
          }
        }
        else {
          if (uVar20 <= uVar19) goto LAB_0048e770;
          (*local_34c)(local_350,param_4);
          iVar5 = uVar20 - uVar19;
          (*(code *)PTR___memcpy_chk_006a9a48)(local_12c,(int)param_4 + uVar19,iVar5,0x80);
          (*(code *)PTR_memcpy_006a9aec)((int)local_12c + iVar5,param_5,uVar19 - iVar5);
          (*local_34c)(local_350,local_12c);
          if (uVar19 == 0) {
            trap(7);
          }
          uVar18 = uVar26 / uVar19 - 1;
          if (1 < uVar18) {
            uVar22 = 1;
            iVar5 = param_5 + (uVar19 - iVar5);
            do {
              uVar22 = uVar22 + 1;
              (*local_34c)(local_350,iVar5);
              iVar5 = iVar5 + uVar19;
            } while (uVar18 != uVar22);
          }
        }
      }
      uVar18 = uVar28 + local_344;
      (*(code *)PTR_memset_006a99f4)(&local_1ec,0,0x40);
      if (uVar28 <= uVar18) {
        uVar22 = local_324 - 4U >> 2;
        do {
          uVar13 = 0;
          uVar23 = ~(local_32c ^ uVar28) & (local_32c ^ uVar28) - 1;
          pbVar17 = abStack_204 + (iVar21 - uVar19) + 8;
          bVar2 = (char)(~(byte)((local_330 ^ uVar28) >> 0x18) &
                        (byte)((local_330 ^ uVar28) - 1 >> 0x18)) >> 7;
          pbVar16 = (byte *)((int)param_4 + uVar26);
          uVar24 = (int)uVar23 >> 0x1f & 0xff;
          pbVar25 = (byte *)(param_5 + (uVar26 - uVar20));
          uVar14 = uVar26;
          puVar15 = &local_ac;
          do {
            if (uVar14 < uVar20) {
              bVar8 = *pbVar16;
              bVar10 = bVar8 ^ 0x80;
            }
            else if (uVar14 < param_7) {
              bVar8 = *pbVar25;
              bVar10 = bVar8 ^ 0x80;
            }
            else {
              bVar10 = 0x80;
              bVar8 = 0;
            }
            bVar11 = bVar2;
            if ((int)((~uVar27 + uVar13 ^ uVar27 + 1 | uVar13 ^ uVar27 + 1) ^ uVar13) < 0) {
              bVar11 = 0;
            }
            uVar14 = uVar14 + 1;
            bVar12 = bVar2;
            if ((int)((uVar13 - uVar27 ^ uVar27 | uVar13 ^ uVar27) ^ uVar13) < 0) {
              bVar12 = 0;
            }
            bVar8 = (~(byte)((int)uVar23 >> 0x1f) | bVar2) & ~bVar11 & (bVar8 ^ bVar10 & bVar12);
            if (uVar19 - iVar21 <= uVar13) {
              bVar8 = bVar8 ^ (byte)uVar24 & (bVar8 ^ *pbVar17);
            }
            uVar13 = uVar13 + 1;
            *(byte *)puVar15 = bVar8;
            pbVar17 = pbVar17 + 1;
            puVar15 = (uint *)((int)puVar15 + 1);
            pbVar16 = pbVar16 + 1;
            pbVar25 = pbVar25 + 1;
          } while (uVar19 != uVar13);
          (*local_34c)(local_350,&local_ac);
          (*local_33c)(local_350,&local_ac);
          uVar26 = uVar26 + uVar19;
          uVar24 = uVar24 << 0x18 | uVar24 << 0x10 | uVar24 << 8 | uVar24;
          local_1ec = uVar24 & local_ac | local_1ec;
          local_1e8 = uVar24 & local_a8 | local_1e8;
          local_1e0 = uVar24 & local_a0 | local_1e0;
          local_1e4 = uVar24 & local_a4 | local_1e4;
          if ((((((uVar22 != 3) && (local_1dc = uVar24 & local_9c | local_1dc, uVar22 != 4)) &&
                (local_1d8 = uVar24 & local_98 | local_1d8, uVar22 != 5)) &&
               (((local_1d4 = uVar24 & local_94 | local_1d4, uVar22 != 6 &&
                 (local_1d0 = uVar24 & local_90 | local_1d0, uVar22 != 7)) &&
                ((local_1cc = uVar24 & local_8c | local_1cc, uVar22 != 8 &&
                 ((local_1c8 = uVar24 & local_88 | local_1c8, uVar22 != 9 &&
                  (local_1c4 = uVar24 & local_84 | local_1c4, uVar22 != 10)))))))) &&
              (local_1c0 = uVar24 & local_80 | local_1c0, uVar22 != 0xb)) &&
             (((local_1bc = uVar24 & local_7c | local_1bc, uVar22 != 0xc &&
               (local_1b8 = uVar24 & local_78 | local_1b8, uVar22 != 0xd)) &&
              (local_1b4 = uVar24 & local_74 | local_1b4, uVar22 == 0xf)))) {
            local_1b0 = uVar24 & local_70 | local_1b0;
          }
          uVar28 = uVar28 + 1;
        } while (uVar28 <= uVar18);
      }
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_2f0);
      iVar5 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_2f0,*param_1,0);
      if (0 < iVar5) {
        if (param_10 == '\0') {
          uVar20 = 0;
          puVar15 = local_1ac;
          do {
            uVar20 = uVar20 + 1;
            *puVar15 = *puVar15 ^ 0x6a6a6a6a;
            puVar15 = puVar15 + 1;
          } while (uVar20 < (uVar19 - 4 >> 2) + 1);
          iVar5 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_2f0,local_1ac,uVar19);
        }
        else {
          (*(code *)PTR_memset_006a99f4)(local_1ac,0x5c,local_318);
          iVar5 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_2f0,param_8,param_9);
          if (iVar5 < 1) goto LAB_0048efa8;
          iVar5 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_2f0,local_1ac,local_318);
        }
        if ((0 < iVar5) &&
           (iVar5 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_2f0,&local_1ec,local_324),
           0 < iVar5)) {
          (*(code *)PTR_EVP_DigestFinal_006a7e44)(auStack_2f0,param_2,&local_2f4);
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = local_2f4;
          }
          (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_2f0);
          pSVar7 = (SSL_METHOD *)0x1;
          goto LAB_0048e774;
        }
      }
LAB_0048efa8:
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_2f0);
      pSVar7 = (SSL_METHOD *)0x0;
      goto LAB_0048e774;
    }
    iVar5 = (*(code *)PTR_SHA384_Init_006a8168)(auStack_2d8);
    if (0 < iVar5) {
      local_34c = (code *)PTR_SHA512_Transform_006a815c;
      uVar4 = 0x73;
      iVar9 = 0x400;
      bVar1 = true;
      iVar21 = 0x10;
      iVar5 = 0x5f;
      local_318 = 0x28;
      uVar19 = 0x80;
      local_324 = 0x30;
      local_33c = tls1_sha512_final_raw;
      goto LAB_0048e820;
    }
  }
LAB_0048e770:
  pSVar7 = (SSL_METHOD *)0x0;
LAB_0048e774:
  if (local_2c == *(int *)puVar3) {
    return pSVar7;
  }
  iVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar5 == 0x300) {
                    /* WARNING: Could not recover jumptable at 0x0048f210. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pSVar7 = (SSL_METHOD *)(*(code *)PTR_SSLv3_method_006a8174)();
    return pSVar7;
  }
  if (iVar5 == 0x301) {
    pSVar7 = TLSv1_method();
    return pSVar7;
  }
  if (iVar5 != 0x302) {
    if (iVar5 == 0x303) {
      pSVar7 = TLSv1_2_method();
      return pSVar7;
    }
    return (SSL_METHOD *)0x0;
  }
  pSVar7 = TLSv1_1_method();
  return pSVar7;
}

