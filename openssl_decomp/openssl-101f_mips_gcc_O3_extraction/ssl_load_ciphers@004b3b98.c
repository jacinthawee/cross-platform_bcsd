
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ssl_load_ciphers(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  int *piVar9;
  int **ppiVar10;
  int **ppiVar11;
  int *in_a3;
  int iVar12;
  int aiStack_80 [3];
  uint uStack_74;
  undefined1 *puStack_70;
  undefined1 *puStack_6c;
  undefined *puStack_68;
  char *pcStack_64;
  undefined4 *local_38;
  undefined4 *local_34;
  int local_24;
  int local_20;
  int *local_1c;
  
  puStack_68 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int **)PTR___stack_chk_guard_006aabf0;
  ssl_cipher_methods._0_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("DES-CBC");
  ssl_cipher_methods._4_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("DES-EDE3-CBC");
  ssl_cipher_methods._8_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("RC4");
  ssl_cipher_methods._12_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("RC2-CBC");
  ssl_cipher_methods._16_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("IDEA-CBC");
  ssl_cipher_methods._24_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("AES-128-CBC");
  ssl_cipher_methods._28_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("AES-256-CBC");
  ssl_cipher_methods._32_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("CAMELLIA-128-CBC");
  ssl_cipher_methods._36_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("CAMELLIA-256-CBC");
  ssl_cipher_methods._40_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("gost89-cnt");
  ssl_cipher_methods._44_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("SEED-CBC");
  ssl_cipher_methods._48_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("id-aes128-GCM");
  ssl_cipher_methods._52_4_ = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("id-aes256-GCM");
  ssl_digest_methods._0_4_ = (*(code *)PTR_EVP_get_digestbyname_006a802c)(&DAT_00646a70);
  ssl_mac_secret_size._0_4_ = (*(code *)PTR_EVP_MD_size_006a8f2c)(ssl_digest_methods._0_4_);
  if (ssl_mac_secret_size._0_4_ < 0) {
    OpenSSLDie("ssl_ciph.c",0x193,"ssl_mac_secret_size[SSL_MD_MD5_IDX] >= 0");
  }
  ssl_digest_methods._4_4_ = (*(code *)PTR_EVP_get_digestbyname_006a802c)(&DAT_0064e1a8);
  ssl_mac_secret_size._4_4_ = (*(code *)PTR_EVP_MD_size_006a8f2c)(ssl_digest_methods._4_4_);
  if (ssl_mac_secret_size._4_4_ < 0) {
    OpenSSLDie("ssl_ciph.c",0x198,"ssl_mac_secret_size[SSL_MD_SHA1_IDX] >= 0");
  }
  ssl_digest_methods._8_4_ = (*(code *)PTR_EVP_get_digestbyname_006a802c)("md_gost94");
  if ((ssl_digest_methods._8_4_ != 0) &&
     (ssl_mac_secret_size._8_4_ = (*(code *)PTR_EVP_MD_size_006a8f2c)(ssl_digest_methods._8_4_),
     ssl_mac_secret_size._8_4_ < 0)) {
    OpenSSLDie("ssl_ciph.c",0x19f,"ssl_mac_secret_size[SSL_MD_GOST94_IDX] >= 0");
  }
  ssl_digest_methods._12_4_ = (*(code *)PTR_EVP_get_digestbyname_006a802c)("gost-mac");
  ppiVar10 = (int **)0xffffffff;
  pcVar8 = "gost-mac";
  local_24 = 0;
  local_20 = 0;
  puVar2 = (undefined4 *)(*(code *)PTR_EVP_PKEY_asn1_find_str_006a80bc)(&local_24);
  if (puVar2 != (undefined4 *)0x0) {
    in_a3 = (int *)0x0;
    ppiVar10 = (int **)0x0;
    pcVar8 = (char *)0x0;
    local_38 = (undefined4 *)0x0;
    (*(code *)PTR_EVP_PKEY_asn1_get0_info_006a80c0)(&local_20);
    local_34 = puVar2;
  }
  if (local_24 != 0) {
    (*(code *)PTR_ENGINE_finish_006a80c4)();
  }
  ssl_mac_pkey_id._12_4_ = local_20;
  if (local_20 != 0) {
    ssl_mac_secret_size._12_4_ = 0x20;
  }
  ssl_digest_methods._16_4_ = (*(code *)PTR_EVP_get_digestbyname_006a802c)("SHA256");
  ssl_mac_secret_size._16_4_ = (*(code *)PTR_EVP_MD_size_006a8f2c)(ssl_digest_methods._16_4_);
  ssl_digest_methods._20_4_ = (*(code *)PTR_EVP_get_digestbyname_006a802c)("SHA384");
  ssl_mac_secret_size._20_4_ = (*(code *)PTR_EVP_MD_size_006a8f2c)(ssl_digest_methods._20_4_);
  if (local_1c == *(int **)puStack_68) {
    return ssl_mac_secret_size._20_4_;
  }
  piVar7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puStack_6c = ssl_mac_secret_size;
  iVar12 = piVar7[0x2d];
  pcStack_64 = "x";
  puStack_70 = ssl_digest_methods;
  uStack_74 = *(uint *)PTR___stack_chk_guard_006aabf0;
  uVar3 = 0;
  piVar9 = (int *)pcVar8;
  ppiVar11 = ppiVar10;
  if (iVar12 == 0) goto LAB_004b4124;
  if (local_34 != (undefined4 *)0x0) {
    load_builtin_compressions();
    iVar6 = ssl_comp_methods;
    aiStack_80[0] = piVar7[0x2c];
    *local_34 = 0;
    if (iVar6 != 0) {
      piVar9 = aiStack_80;
      piVar4 = (int *)(*(code *)PTR_sk_find_006a906c)();
      if ((int)piVar4 < 0) {
        *local_34 = 0;
      }
      else {
        uVar3 = (*(code *)PTR_sk_value_006a7f24)(ssl_comp_methods);
        *local_34 = uVar3;
        piVar9 = piVar4;
      }
    }
  }
  uVar3 = 0;
  if (((int *)pcVar8 == (int *)0x0) || (ppiVar10 == (int **)0x0)) goto LAB_004b4124;
  uVar5 = *(uint *)(iVar12 + 0x14);
  if (uVar5 == 0x40) {
    iVar6 = 6;
LAB_004b41d8:
    *(int *)pcVar8 = *(int *)(ssl_cipher_methods + iVar6 * 4);
  }
  else {
    if (0x40 < uVar5) {
      if (uVar5 == 0x400) {
        iVar6 = 10;
      }
      else if (uVar5 < 0x401) {
        if (uVar5 == 0x100) {
          iVar6 = 8;
        }
        else if (uVar5 == 0x200) {
          iVar6 = 9;
        }
        else {
          iVar6 = 7;
          if (uVar5 != 0x80) goto LAB_004b403c;
        }
      }
      else if (uVar5 == 0x1000) {
        iVar6 = 0xc;
      }
      else if (uVar5 == 0x2000) {
        iVar6 = 0xd;
      }
      else {
        iVar6 = 0xb;
        if (uVar5 != 0x800) goto LAB_004b403c;
      }
      goto LAB_004b41d8;
    }
    if (uVar5 == 4) {
      iVar6 = 2;
      goto LAB_004b41d8;
    }
    if (uVar5 < 5) {
      if (uVar5 == 1) {
        iVar6 = 0;
      }
      else {
        iVar6 = 1;
        if (uVar5 != 2) {
LAB_004b403c:
          *(int *)pcVar8 = 0;
          goto LAB_004b4040;
        }
      }
      goto LAB_004b41d8;
    }
    if (uVar5 == 0x10) {
      iVar6 = 4;
      goto LAB_004b41d8;
    }
    if (uVar5 != 0x20) {
      iVar6 = 3;
      if (uVar5 != 8) goto LAB_004b403c;
      goto LAB_004b41d8;
    }
    iVar6 = (*(code *)PTR_EVP_enc_null_006a94dc)();
    *(int *)pcVar8 = iVar6;
  }
LAB_004b4040:
  iVar6 = *(int *)(iVar12 + 0x18);
  if ((iVar6 - 1U < 0x20) && ((uint)(int)(char)(&DAT_0064886f)[iVar6] < 7)) {
    iVar6 = (char)(&DAT_0064886f)[iVar6] * 4;
    piVar9 = *(int **)(ssl_digest_methods + iVar6);
    *ppiVar10 = piVar9;
    if (in_a3 != (int *)0x0) {
      *in_a3 = *(int *)(ssl_mac_pkey_id + iVar6);
    }
    if (local_38 != (undefined4 *)0x0) {
      *local_38 = *(undefined4 *)(ssl_mac_secret_size + iVar6);
    }
    uVar3 = 0;
    if (*(int *)pcVar8 == 0) goto LAB_004b4124;
    if (piVar9 == (int *)0x0) goto LAB_004b425c;
  }
  else {
    *ppiVar10 = (int *)0x0;
    if (in_a3 != (int *)0x0) {
      *in_a3 = 0;
    }
    if (local_38 != (undefined4 *)0x0) {
      *local_38 = 0;
    }
    if (iVar6 == 0x40) {
      in_a3 = (int *)0x0;
    }
    if (*(int *)pcVar8 == 0) {
      uVar3 = 0;
      goto LAB_004b4124;
    }
LAB_004b425c:
    iVar6 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)();
    if (-1 < iVar6 << 10) {
      uVar3 = 0;
      goto LAB_004b4124;
    }
  }
  if ((in_a3 != (int *)0x0) && (uVar3 = 0, *in_a3 == 0)) goto LAB_004b4124;
  if ((*piVar7 >> 8 == 3) && (*piVar7 != 0x300)) {
    iVar6 = *(int *)(iVar12 + 0x14);
    if (iVar6 == 4) {
      uVar3 = 1;
      if (*(int *)(iVar12 + 0x18) != 1) goto LAB_004b4124;
      iVar6 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("RC4-HMAC-MD5");
      if (iVar6 == 0) {
        iVar6 = *(int *)(iVar12 + 0x14);
        goto LAB_004b4204;
      }
LAB_004b42a0:
      *(int *)pcVar8 = iVar6;
      uVar3 = 1;
      *ppiVar10 = (int *)0x0;
      goto LAB_004b4124;
    }
LAB_004b4204:
    if (iVar6 == 0x40) {
      uVar3 = 1;
      if (*(int *)(iVar12 + 0x18) != 2) goto LAB_004b4124;
      iVar6 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("AES-128-CBC-HMAC-SHA1");
      if (iVar6 != 0) goto LAB_004b42a0;
      iVar6 = *(int *)(iVar12 + 0x14);
    }
    uVar3 = 1;
    if ((iVar6 != 0x80) || (uVar3 = 1, *(int *)(iVar12 + 0x18) != 2)) goto LAB_004b4124;
    iVar12 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)("AES-256-CBC-HMAC-SHA1");
    if (iVar12 != 0) {
      *(int *)pcVar8 = iVar12;
      uVar3 = 1;
      *ppiVar10 = (int *)0x0;
      goto LAB_004b4124;
    }
  }
  uVar3 = 1;
LAB_004b4124:
  if (uStack_74 == *(uint *)puVar1) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (5 < uStack_74) {
    return 0;
  }
  iVar12 = *(int *)(ssl_handshake_digest_flag + uStack_74 * 4);
  *piVar9 = iVar12;
  if (iVar12 != 0) {
    *ppiVar11 = *(int **)(ssl_digest_methods + uStack_74 * 4);
    return 1;
  }
  *ppiVar11 = (int *)0x0;
  return 1;
}

