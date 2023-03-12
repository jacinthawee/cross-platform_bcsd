
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ssl_load_ciphers(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  int *piVar10;
  int **ppiVar11;
  int **ppiVar12;
  int *in_a3;
  int aiStack_80 [3];
  uint uStack_74;
  char *pcStack_70;
  undefined *puStack_6c;
  undefined1 *puStack_68;
  undefined1 *puStack_64;
  undefined4 *local_38;
  undefined4 *local_34;
  int local_24;
  int local_20;
  int *local_1c;
  
  puStack_6c = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int **)PTR___stack_chk_guard_006a9ae8;
  ssl_cipher_methods._0_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("DES-CBC");
  ssl_cipher_methods._4_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("DES-EDE3-CBC");
  ssl_cipher_methods._8_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("RC4");
  ssl_cipher_methods._12_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("RC2-CBC");
  ssl_cipher_methods._16_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("IDEA-CBC");
  ssl_cipher_methods._24_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("AES-128-CBC");
  ssl_cipher_methods._28_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("AES-256-CBC");
  ssl_cipher_methods._32_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("CAMELLIA-128-CBC");
  ssl_cipher_methods._36_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("CAMELLIA-256-CBC");
  ssl_cipher_methods._40_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("gost89-cnt");
  ssl_cipher_methods._44_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("SEED-CBC");
  ssl_cipher_methods._48_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("id-aes128-GCM");
  ssl_cipher_methods._52_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("id-aes256-GCM");
  ssl_digest_methods._0_4_ = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(&DAT_006463d0);
  ssl_mac_secret_size._0_4_ = (*(code *)PTR_EVP_MD_size_006a7e3c)(ssl_digest_methods._0_4_);
  if (ssl_mac_secret_size._0_4_ < 0) {
    OpenSSLDie("ssl_ciph.c",0x1a1,"ssl_mac_secret_size[SSL_MD_MD5_IDX] >= 0");
  }
  ssl_digest_methods._4_4_ = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(&DAT_0064d80c);
  ssl_mac_secret_size._4_4_ = (*(code *)PTR_EVP_MD_size_006a7e3c)(ssl_digest_methods._4_4_);
  if (ssl_mac_secret_size._4_4_ < 0) {
    OpenSSLDie("ssl_ciph.c",0x1a5,"ssl_mac_secret_size[SSL_MD_SHA1_IDX] >= 0");
  }
  ssl_digest_methods._8_4_ = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)("md_gost94");
  if ((ssl_digest_methods._8_4_ != 0) &&
     (ssl_mac_secret_size._8_4_ = (*(code *)PTR_EVP_MD_size_006a7e3c)(ssl_digest_methods._8_4_),
     ssl_mac_secret_size._8_4_ < 0)) {
    OpenSSLDie("ssl_ciph.c",0x1ab,"ssl_mac_secret_size[SSL_MD_GOST94_IDX] >= 0");
  }
  ssl_digest_methods._12_4_ = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)("gost-mac");
  ppiVar11 = (int **)0xffffffff;
  pcVar9 = "gost-mac";
  local_24 = 0;
  local_20 = 0;
  puVar2 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_str_006a6fbc)(&local_24);
  if (puVar2 == (undefined4 *)0x0) {
LAB_004b1108:
    if (local_24 != 0) {
LAB_004b1114:
      (*(code *)PTR_ENGINE_finish_006a6fc4)();
    }
    if (local_20 != 0) {
      ssl_mac_secret_size._12_4_ = 0x20;
    }
  }
  else {
    in_a3 = (int *)0x0;
    ppiVar11 = (int **)0x0;
    pcVar9 = (char *)0x0;
    local_38 = (undefined4 *)0x0;
    iVar3 = (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a6fc0)(&local_20);
    local_34 = puVar2;
    if (0 < iVar3) goto LAB_004b1108;
    local_20 = 0;
    if (local_24 != 0) goto LAB_004b1114;
  }
  ssl_mac_pkey_id._12_4_ = local_20;
  ssl_digest_methods._16_4_ = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)("SHA256");
  ssl_mac_secret_size._16_4_ = (*(code *)PTR_EVP_MD_size_006a7e3c)(ssl_digest_methods._16_4_);
  ssl_digest_methods._20_4_ = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)("SHA384");
  ssl_mac_secret_size._20_4_ = (*(code *)PTR_EVP_MD_size_006a7e3c)(ssl_digest_methods._20_4_);
  if (local_1c == *(int **)puStack_6c) {
    return ssl_mac_secret_size._20_4_;
  }
  piVar8 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar3 = piVar8[0x2d];
  puStack_64 = ssl_mac_secret_size;
  puStack_68 = ssl_digest_methods;
  pcStack_70 = "-check_ss_sig";
  uStack_74 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  uVar4 = 0;
  piVar10 = (int *)pcVar9;
  ppiVar12 = ppiVar11;
  if (iVar3 == 0) goto LAB_004b1438;
  if (local_34 != (undefined4 *)0x0) {
    load_builtin_compressions();
    iVar7 = ssl_comp_methods;
    aiStack_80[0] = piVar8[0x2c];
    *local_34 = 0;
    if (iVar7 != 0) {
      piVar10 = aiStack_80;
      piVar5 = (int *)(*(code *)PTR_sk_find_006a8044)();
      if ((int)piVar5 < 0) {
        *local_34 = 0;
      }
      else {
        uVar4 = (*(code *)PTR_sk_value_006a6e24)(ssl_comp_methods);
        *local_34 = uVar4;
        piVar10 = piVar5;
      }
    }
  }
  uVar4 = 0;
  if (((int *)pcVar9 == (int *)0x0) || (ppiVar11 == (int **)0x0)) goto LAB_004b1438;
  uVar6 = *(uint *)(iVar3 + 0x14);
  if (uVar6 == 0x40) {
    iVar7 = 6;
LAB_004b14ec:
    *(int *)pcVar9 = *(int *)(ssl_cipher_methods + iVar7 * 4);
  }
  else {
    if (0x40 < uVar6) {
      if (uVar6 == 0x400) {
        iVar7 = 10;
      }
      else if (uVar6 < 0x401) {
        if (uVar6 == 0x100) {
          iVar7 = 8;
        }
        else if (uVar6 == 0x200) {
          iVar7 = 9;
        }
        else {
          iVar7 = 7;
          if (uVar6 != 0x80) goto LAB_004b1350;
        }
      }
      else if (uVar6 == 0x1000) {
        iVar7 = 0xc;
      }
      else if (uVar6 == 0x2000) {
        iVar7 = 0xd;
      }
      else {
        iVar7 = 0xb;
        if (uVar6 != 0x800) goto LAB_004b1350;
      }
      goto LAB_004b14ec;
    }
    if (uVar6 == 4) {
      iVar7 = 2;
      goto LAB_004b14ec;
    }
    if (uVar6 < 5) {
      if (uVar6 == 1) {
        iVar7 = 0;
      }
      else {
        iVar7 = 1;
        if (uVar6 != 2) {
LAB_004b1350:
          *(int *)pcVar9 = 0;
          goto LAB_004b1354;
        }
      }
      goto LAB_004b14ec;
    }
    if (uVar6 == 0x10) {
      iVar7 = 4;
      goto LAB_004b14ec;
    }
    if (uVar6 != 0x20) {
      iVar7 = 3;
      if (uVar6 != 8) goto LAB_004b1350;
      goto LAB_004b14ec;
    }
    iVar7 = (*(code *)PTR_EVP_enc_null_006a83c0)();
    *(int *)pcVar9 = iVar7;
  }
LAB_004b1354:
  iVar7 = *(int *)(iVar3 + 0x18);
  if ((iVar7 - 1U < 0x20) &&
     (uVar6 = (uint)*(char *)((int)&PTR_caseD_40_006483c0 + iVar7 + 3), uVar6 < 6)) {
    iVar7 = uVar6 * 4;
    piVar10 = *(int **)(ssl_digest_methods + iVar7);
    *ppiVar11 = piVar10;
    if (in_a3 != (int *)0x0) {
      *in_a3 = *(int *)(ssl_mac_pkey_id + iVar7);
    }
    if (local_38 != (undefined4 *)0x0) {
      *local_38 = *(undefined4 *)(ssl_mac_secret_size + iVar7);
    }
    uVar4 = 0;
    if (*(int *)pcVar9 == 0) goto LAB_004b1438;
    if (piVar10 == (int *)0x0) goto LAB_004b1570;
  }
  else {
    *ppiVar11 = (int *)0x0;
    if (in_a3 != (int *)0x0) {
      *in_a3 = 0;
    }
    if (local_38 != (undefined4 *)0x0) {
      *local_38 = 0;
    }
    if (iVar7 == 0x40) {
      in_a3 = (int *)0x0;
    }
    if (*(int *)pcVar9 == 0) {
      uVar4 = 0;
      goto LAB_004b1438;
    }
LAB_004b1570:
    iVar7 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)();
    if (-1 < iVar7 << 10) {
      uVar4 = 0;
      goto LAB_004b1438;
    }
  }
  if ((in_a3 != (int *)0x0) && (uVar4 = 0, *in_a3 == 0)) goto LAB_004b1438;
  if ((*piVar8 >> 8 == 3) && (*piVar8 != 0x300)) {
    iVar7 = *(int *)(iVar3 + 0x14);
    if (iVar7 == 4) {
      uVar4 = 1;
      if (*(int *)(iVar3 + 0x18) != 1) goto LAB_004b1438;
      iVar7 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("RC4-HMAC-MD5");
      if (iVar7 == 0) {
        iVar7 = *(int *)(iVar3 + 0x14);
        goto LAB_004b1518;
      }
LAB_004b15b4:
      *(int *)pcVar9 = iVar7;
      uVar4 = 1;
      *ppiVar11 = (int *)0x0;
      goto LAB_004b1438;
    }
LAB_004b1518:
    if (iVar7 == 0x40) {
      uVar4 = 1;
      if (*(int *)(iVar3 + 0x18) != 2) goto LAB_004b1438;
      iVar7 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("AES-128-CBC-HMAC-SHA1");
      if (iVar7 != 0) goto LAB_004b15b4;
      iVar7 = *(int *)(iVar3 + 0x14);
    }
    uVar4 = 1;
    if ((iVar7 != 0x80) || (uVar4 = 1, *(int *)(iVar3 + 0x18) != 2)) goto LAB_004b1438;
    iVar3 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)("AES-256-CBC-HMAC-SHA1");
    if (iVar3 != 0) {
      *(int *)pcVar9 = iVar3;
      uVar4 = 1;
      *ppiVar11 = (int *)0x0;
      goto LAB_004b1438;
    }
  }
  uVar4 = 1;
LAB_004b1438:
  if (uStack_74 == *(uint *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (5 < uStack_74) {
    return 0;
  }
  iVar3 = *(int *)(ssl_handshake_digest_flag + uStack_74 * 4);
  *piVar10 = iVar3;
  if (iVar3 != 0) {
    *ppiVar12 = *(int **)(ssl_digest_methods + uStack_74 * 4);
    return 1;
  }
  *ppiVar12 = (int *)0x0;
  return 1;
}

