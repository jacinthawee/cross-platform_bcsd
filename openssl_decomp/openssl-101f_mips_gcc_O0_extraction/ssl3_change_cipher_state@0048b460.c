
uint ssl3_change_cipher_state(int param_1,uint param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  char cVar11;
  uint uVar12;
  undefined *puVar13;
  code *pcVar14;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined auStack_158 [24];
  undefined auStack_140 [24];
  char cStack_128;
  char cStack_127;
  char cStack_126;
  char cStack_125;
  char cStack_124;
  char cStack_123;
  char cStack_122;
  char cStack_121;
  char cStack_120;
  char cStack_11f;
  char cStack_11e;
  char cStack_11d;
  char cStack_11c;
  char cStack_11b;
  char cStack_11a;
  char cStack_119;
  undefined auStack_118 [20];
  int iStack_104;
  int iStack_100;
  int iStack_fc;
  uint uStack_f8;
  undefined *puStack_f4;
  uint uStack_f0;
  undefined *puStack_ec;
  undefined4 uStack_e8;
  undefined *puStack_e4;
  int iStack_e0;
  code *pcStack_dc;
  undefined *local_c8;
  uint local_c4;
  undefined *local_c0;
  uint local_b4;
  char *local_b0;
  int local_ac;
  undefined *local_a8;
  char *local_a4;
  undefined *local_a0;
  char *local_9c;
  undefined auStack_94 [24];
  undefined auStack_7c [16];
  char acStack_6c [64];
  int local_2c;
  
  puStack_f4 = PTR___stack_chk_guard_006aabf0;
  iVar2 = *(int *)(param_1 + 0x58);
  local_c0 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_b4 = *(uint *)(*(int *)(iVar2 + 0x344) + 0x20);
  puStack_ec = *(undefined **)(iVar2 + 0x380);
  uStack_e8 = *(undefined4 *)(iVar2 + 0x37c);
  if (puStack_ec == (undefined *)0x0) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("s3_enc.c",0xec,&DAT_0067a410);
    iVar2 = *(int *)(param_1 + 0x58);
  }
  puStack_e4 = (undefined *)0x0;
  if (*(int *)(iVar2 + 0x38c) != 0) {
    puStack_e4 = *(undefined **)(*(int *)(iVar2 + 0x38c) + 8);
  }
  uStack_f0 = param_2 & 1;
  if (uStack_f0 == 0) {
    iStack_fc = *(int *)(param_1 + 0x8c);
    iStack_e0 = 1;
    if (iStack_fc == 0) {
      local_b0 = "s\n";
      iVar2 = (**(code **)(local_c0 + -0x7dd8))(0x8c,"s3_enc.c",0x11d);
      *(int *)(param_1 + 0x8c) = iVar2;
      if (iVar2 == 0) goto LAB_0048ba70;
      iStack_e0 = 0;
      (**(code **)(local_c0 + -0x7390))(iVar2);
      iStack_fc = *(int *)(param_1 + 0x8c);
    }
    (**(code **)(local_c0 + -0x6e38))(param_1 + 0x90,puStack_ec);
    if (*(int *)(param_1 + 0x94) != 0) {
      (**(code **)(local_c0 + -0x6cd0))();
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    if (puStack_e4 != (undefined *)0x0) {
      iVar2 = (**(code **)(local_c0 + -0x6ccc))(puStack_e4);
      *(int *)(param_1 + 0x94) = iVar2;
      if (iVar2 == 0) {
        local_c8 = (undefined *)0x130;
        (**(code **)(local_c0 + -0x6eb0))(0x14,0x81,0x8e,"s3_enc.c");
        goto LAB_0048b70c;
      }
    }
    iVar2 = *(int *)(param_1 + 0x58);
    *(undefined *)(iVar2 + 0x54) = 0;
    *(undefined *)(iVar2 + 0x55) = 0;
    *(undefined *)(iVar2 + 0x56) = 0;
    *(undefined *)(iVar2 + 0x57) = 0;
    *(undefined *)(iVar2 + 0x58) = 0;
    *(undefined *)(iVar2 + 0x59) = 0;
    *(undefined *)(iVar2 + 0x5a) = 0;
    *(undefined *)(iVar2 + 0x5b) = 0;
    iVar2 = *(int *)(param_1 + 0x58);
    local_b0 = (char *)(iVar2 + 0x60);
    if (iStack_e0 == 0) {
LAB_0048b57c:
      puVar13 = *(undefined **)(iVar2 + 0x378);
      puStack_e4 = (undefined *)(**(code **)(local_c0 + -0x6fb4))(puStack_ec);
      puStack_ec = puVar13;
    }
    else {
LAB_0048b7d8:
      (**(code **)(local_c0 + -0x7380))(iStack_fc);
      puVar13 = *(undefined **)(*(int *)(param_1 + 0x58) + 0x378);
      puStack_e4 = (undefined *)(**(code **)(local_c0 + -0x6fb4))(puStack_ec);
      puStack_ec = puVar13;
    }
    if ((int)puStack_e4 < 0) {
      uStack_f0 = 0;
      goto LAB_0048b70c;
    }
    uVar12 = local_b4 & 2;
    iStack_e0 = (**(code **)(local_c0 + -0x6ea4))(uStack_e8);
    if (uVar12 != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
      if ((*(uint *)(iVar2 + 0x20) & 8) == 0) {
        iVar3 = 8;
        if (*(int *)(iVar2 + 0x14) != 1) {
          iVar3 = 7;
        }
        if (iVar3 < iStack_e0) {
          iStack_e0 = iVar3;
        }
      }
      else if (5 < iStack_e0) {
        iStack_e0 = 5;
      }
    }
    pcVar4 = (char *)(**(code **)(local_c0 + -0x7884))(uStack_e8);
    if ((param_2 == 0x12) || (iVar2 = iStack_e0 + (int)puStack_e4 * 2, param_2 == 0x21)) {
      iVar2 = (int)puStack_e4 * 2;
      iVar3 = *(int *)(param_1 + 0x58);
      pcVar5 = (char *)(iStack_e0 * 2 + iVar2);
      local_b4 = iVar3 + 0xc0;
      local_ac = iVar3 + 0xa0;
      puVar13 = puStack_ec;
      if (*(int *)(iVar3 + 0x374) < (int)(pcVar5 + (int)pcVar4 * 2)) goto LAB_0048b850;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x58);
      local_b4 = iVar3 + 0xa0;
      pcVar5 = pcVar4 + iVar2 + iStack_e0;
      local_ac = iVar3 + 0xc0;
      puVar13 = puStack_ec + (int)puStack_e4;
      if (*(int *)(iVar3 + 0x374) < (int)(pcVar4 + (int)pcVar5)) {
LAB_0048b850:
        pcVar14 = *(code **)(local_c0 + -0x6eb0);
        uVar9 = 0x44;
        local_c8 = (undefined *)0x15a;
        goto LAB_0048b864;
      }
    }
    local_a4 = puStack_ec + iVar2;
    local_a0 = puStack_ec + (int)pcVar5;
    puStack_ec = auStack_94;
    local_a8 = puVar13;
    local_9c = pcVar4;
    (**(code **)(local_c0 + -0x7fc4))(puStack_ec);
    (**(code **)(local_c0 + -0x52ec))(local_b0,local_a8,puStack_e4);
    pcVar4 = local_a4;
    local_c8 = local_a0;
    if (uVar12 != 0) {
      local_a4 = local_9c;
      local_a8 = local_a0;
      local_b0 = pcVar4;
      uVar9 = (**(code **)(local_c0 + -0x7d18))();
      (**(code **)(local_c0 + -0x7870))(puStack_ec,uVar9,0);
      (**(code **)(local_c0 + -0x786c))(puStack_ec,local_b0,iStack_e0);
      (**(code **)(local_c0 + -0x786c))(puStack_ec,local_b4,0x20);
      iStack_e0 = local_ac;
      (**(code **)(local_c0 + -0x786c))(puStack_ec,local_ac,0x20);
      (**(code **)(local_c0 + -0x7868))(puStack_ec,acStack_6c,0);
      local_c8 = local_a8;
      pcVar4 = acStack_6c;
      if (0 < (int)local_a4) {
        uVar9 = (**(code **)(local_c0 + -0x7d18))();
        (**(code **)(local_c0 + -0x7870))(puStack_ec,uVar9,0);
        (**(code **)(local_c0 + -0x786c))(puStack_ec,local_b4,0x20);
        (**(code **)(local_c0 + -0x786c))(puStack_ec,iStack_e0,0x20);
        (**(code **)(local_c0 + -0x7868))(puStack_ec,auStack_7c,0);
        local_c8 = auStack_7c;
      }
    }
    puStack_e4 = auStack_7c;
    param_2 = param_2 & 2;
    pcVar14 = *(code **)(local_c0 + -0x7894);
    *(undefined4 *)(*(int *)(param_1 + 0xc0) + 4) = 0;
    local_c4 = param_2;
    (*pcVar14)(iStack_fc,uStack_e8,0,pcVar4);
    uStack_f0 = 1;
    (**(code **)(local_c0 + -0x7d6c))(acStack_6c,0x40);
    (**(code **)(local_c0 + -0x7d6c))(puStack_e4,0x10);
    (**(code **)(local_c0 + -0x7fac))(puStack_ec);
  }
  else {
    iStack_fc = *(int *)(param_1 + 0x80);
    iStack_e0 = 1;
    if (iStack_fc == 0) {
      local_b0 = "s\n";
      iVar2 = (**(code **)(local_c0 + -0x7dd8))(0x8c,"s3_enc.c",0xf8);
      *(int *)(param_1 + 0x80) = iVar2;
      if (iVar2 != 0) {
        iStack_e0 = 0;
        (**(code **)(local_c0 + -0x7390))(iVar2);
        iStack_fc = *(int *)(param_1 + 0x80);
        goto LAB_0048b4f0;
      }
LAB_0048ba70:
      local_c8 = (undefined *)0x17f;
      uStack_f0 = 0;
      (**(code **)(local_c0 + -0x6eb0))(0x14,0x81,0x41,local_b0 + 0x7800);
      goto LAB_0048b70c;
    }
LAB_0048b4f0:
    (**(code **)(local_c0 + -0x6e38))(param_1 + 0x84,puStack_ec);
    if (*(int *)(param_1 + 0x88) != 0) {
      (**(code **)(local_c0 + -0x6cd0))();
      *(undefined4 *)(param_1 + 0x88) = 0;
    }
    if (puStack_e4 == (undefined *)0x0) {
      puStack_e4 = *(undefined **)(param_1 + 0x58);
LAB_0048b54c:
      puStack_e4[8] = 0;
      puStack_e4[9] = 0;
      puStack_e4[10] = 0;
      puStack_e4[0xb] = 0;
      puStack_e4[0xc] = 0;
      puStack_e4[0xd] = 0;
      puStack_e4[0xe] = 0;
      puStack_e4[0xf] = 0;
      iVar2 = *(int *)(param_1 + 0x58);
      local_b0 = (char *)(iVar2 + 0x14);
      if (iStack_e0 != 0) goto LAB_0048b7d8;
      goto LAB_0048b57c;
    }
    iVar2 = (**(code **)(local_c0 + -0x6ccc))(puStack_e4);
    *(int *)(param_1 + 0x88) = iVar2;
    if (iVar2 != 0) {
      puStack_e4 = *(undefined **)(param_1 + 0x58);
      if (*(int *)(puStack_e4 + 0x120) == 0) {
        local_b0 = "s\n";
        uVar9 = (**(code **)(local_c0 + -0x7dd8))(0x4000,"s3_enc.c",0x111);
        *(undefined4 *)(puStack_e4 + 0x120) = uVar9;
        puStack_e4 = *(undefined **)(param_1 + 0x58);
        if (*(int *)(puStack_e4 + 0x120) == 0) goto LAB_0048ba70;
      }
      goto LAB_0048b54c;
    }
    pcVar14 = *(code **)(local_c0 + -0x6eb0);
    uVar9 = 0x8e;
    local_c8 = (undefined *)0x10c;
LAB_0048b864:
    uStack_f0 = 0;
    (*pcVar14)(0x14,0x81,uVar9,"s3_enc.c");
  }
LAB_0048b70c:
  if (local_2c == *(int *)puStack_f4) {
    return uStack_f0;
  }
  pcStack_dc = ssl3_setup_key_block;
  iVar2 = local_2c;
  (**(code **)(local_c0 + -0x5328))();
  puVar13 = PTR___stack_chk_guard_006aabf0;
  uVar12 = *(uint *)(*(int *)(iVar2 + 0x58) + 0x374);
  iStack_104 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_100 = param_1;
  uStack_f8 = param_2;
  if (uVar12 == 0) {
    iVar3 = (*(code *)PTR_ssl_cipher_get_evp_006a9038)
                      (*(undefined4 *)(iVar2 + 0xc0),&uStack_164,&uStack_160,0,0,&uStack_15c);
    puVar1 = PTR_EVP_MD_size_006a8f2c;
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9d,0x8a,"s3_enc.c",0x192);
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x58);
      *(undefined4 *)(iVar3 + 0x380) = uStack_160;
      *(undefined4 *)(iVar3 + 0x37c) = uStack_164;
      *(undefined4 *)(iVar3 + 0x38c) = uStack_15c;
      iVar3 = (*(code *)puVar1)(uStack_160);
      if (-1 < iVar3) {
        iVar6 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(uStack_164);
        iVar7 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(uStack_164);
        iVar10 = *(int *)(iVar2 + 0x58);
        iVar3 = (iVar3 + iVar6 + iVar7) * 2;
        if (*(int *)(iVar10 + 0x378) != 0) {
          (*(code *)PTR_OPENSSL_cleanse_006a8174)
                    (*(int *)(iVar10 + 0x378),*(undefined4 *)(iVar10 + 0x374));
          (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(*(int *)(iVar2 + 0x58) + 0x378));
          iVar10 = *(int *)(iVar2 + 0x58);
          *(undefined4 *)(iVar10 + 0x378) = 0;
        }
        puVar1 = PTR_CRYPTO_malloc_006a8108;
        *(undefined4 *)(iVar10 + 0x374) = 0;
        iVar6 = (*(code *)puVar1)(iVar3,"s3_enc.c",0x1a7);
        puVar1 = PTR_EVP_MD_CTX_init_006a7f1c;
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9d,0x41,"s3_enc.c",0x1c5);
        }
        else {
          iVar7 = *(int *)(iVar2 + 0x58);
          *(int *)(iVar7 + 0x374) = iVar3;
          *(int *)(iVar7 + 0x378) = iVar6;
          (*(code *)puVar1)(auStack_158);
          (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_158,8);
          (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_140);
          if (iVar3 < 1) {
LAB_0048c010:
            uVar12 = 1;
            (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_118,0x14);
            (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_158);
            (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_140);
          }
          else {
            iVar10 = 1;
            cStack_128 = 'A';
            iVar7 = 0;
            while( true ) {
              cVar11 = cStack_128 + '\x01';
              iVar8 = iVar6 + iVar7;
              iVar7 = iVar7 + 0x10;
              uVar9 = (*(code *)PTR_EVP_sha1_006a86c4)();
              (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_140,uVar9,0);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_140,&cStack_128,iVar10);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)
                        (auStack_140,*(int *)(iVar2 + 0xc0) + 0x14,
                         *(undefined4 *)(*(int *)(iVar2 + 0xc0) + 0x10));
              (*(code *)PTR_EVP_DigestUpdate_006a8674)
                        (auStack_140,*(int *)(iVar2 + 0x58) + 0xa0,0x20);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)
                        (auStack_140,*(int *)(iVar2 + 0x58) + 0xc0,0x20);
              (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_140,auStack_118,0);
              uVar9 = (*(code *)PTR_EVP_md5_006a81c8)();
              (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_158,uVar9,0);
              (*(code *)PTR_EVP_DigestUpdate_006a8674)
                        (auStack_158,*(int *)(iVar2 + 0xc0) + 0x14,
                         *(undefined4 *)(*(int *)(iVar2 + 0xc0) + 0x10));
              (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_158,auStack_118,0x14);
              if (iVar3 < iVar7) {
                (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_158,auStack_118,0);
                (*(code *)PTR_memcpy_006aabf4)(iVar8,auStack_118,(iVar3 + 0x10) - iVar7);
              }
              else {
                (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_158,iVar8);
              }
              if (iVar3 <= iVar7) goto LAB_0048c010;
              iVar10 = iVar10 + 1;
              if (iVar7 == 0x100) break;
              cStack_128 = cVar11;
              cStack_127 = cVar11;
              if (((((iVar10 != 2) && (cStack_126 = cVar11, iVar10 != 3)) &&
                   (cStack_125 = cVar11, iVar10 != 4)) &&
                  ((((cStack_124 = cVar11, iVar10 != 5 && (cStack_123 = cVar11, iVar10 != 6)) &&
                    ((cStack_122 = cVar11, iVar10 != 7 &&
                     ((cStack_121 = cVar11, iVar10 != 8 && (cStack_120 = cVar11, iVar10 != 9))))))
                   && (cStack_11f = cVar11, iVar10 != 10)))) &&
                 ((((cStack_11e = cVar11, iVar10 != 0xb && (cStack_11d = cVar11, iVar10 != 0xc)) &&
                   (cStack_11c = cVar11, iVar10 != 0xd)) &&
                  ((cStack_11b = cVar11, iVar10 != 0xe && (cStack_11a = cVar11, iVar10 == 0x10))))))
              {
                cStack_119 = cVar11;
              }
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xee,0x44,"s3_enc.c",0xb5);
          }
          if ((*(uint *)(iVar2 + 0x100) & 0x800) == 0) {
            iVar3 = *(int *)(iVar2 + 0x58);
            iVar2 = *(int *)(*(int *)(iVar2 + 0xc0) + 0xb4);
            *(undefined4 *)(iVar3 + 0xe0) = 1;
            if ((iVar2 != 0) && ((iVar2 = *(int *)(iVar2 + 0x14), iVar2 == 0x20 || (iVar2 == 4)))) {
              *(undefined4 *)(iVar3 + 0xe0) = 0;
            }
          }
        }
      }
    }
  }
  else {
    uVar12 = 1;
  }
  if (iStack_104 == *(int *)puVar13) {
    return uVar12;
  }
  iVar2 = iStack_104;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar12 = *(uint *)(iVar2 + 0x58);
  if (*(int *)(uVar12 + 0x378) != 0) {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)
              (*(int *)(uVar12 + 0x378),*(undefined4 *)(uVar12 + 0x374));
    (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(*(int *)(iVar2 + 0x58) + 0x378));
    uVar12 = *(uint *)(iVar2 + 0x58);
    *(undefined4 *)(uVar12 + 0x378) = 0;
    *(undefined4 *)(uVar12 + 0x374) = 0;
    return uVar12;
  }
  *(undefined4 *)(uVar12 + 0x374) = 0;
  return uVar12;
}

