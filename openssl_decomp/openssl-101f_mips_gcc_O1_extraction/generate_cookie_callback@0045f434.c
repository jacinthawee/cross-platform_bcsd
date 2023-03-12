
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined * generate_cookie_callback(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined *puVar18;
  int iVar19;
  undefined *puVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  char *pcVar25;
  undefined4 *puVar26;
  uint uVar27;
  uint in_t0;
  undefined1 *puVar28;
  uint uVar29;
  uint uVar30;
  int iVar31;
  undefined4 uVar32;
  code *pcVar33;
  undefined4 *puStack_134;
  short sStack_130;
  undefined uStack_12e;
  undefined uStack_12d;
  uint uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined auStack_114 [64];
  uint uStack_d4;
  undefined *puStack_cc;
  undefined4 *puStack_c8;
  undefined *puStack_c4;
  undefined4 *puStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  code *pcStack_b4;
  undefined4 local_a0;
  char *local_9c;
  undefined4 **local_98;
  undefined *local_90;
  undefined4 *local_84;
  short local_80;
  undefined local_7e;
  undefined local_7d;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  char acStack_64 [64];
  int local_24;
  
  puStack_c4 = PTR___stack_chk_guard_006aabf0;
  puStack_c8 = (undefined4 *)&_ITM_registerTMCloneTable;
  local_90 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar33 = (code *)PTR_SSL_get_rbio_006a8924;
  if (cookie_initialized == 0) {
    puVar26 = param_3;
    puStack_cc = (undefined *)(*(code *)PTR_RAND_bytes_006a8d44)(PTR_cookie_secret_006a8d48,0x10);
    if (puStack_cc != (undefined *)0x0) {
      cookie_initialized = 1;
      pcVar33 = *(code **)(local_90 + -0x75bc);
      goto LAB_0045f4b0;
    }
    pcVar25 = "error setting random cookie secret\n";
    (**(code **)(local_90 + -0x7fa8))(**(undefined4 **)(local_90 + -0x7fa4));
  }
  else {
LAB_0045f4b0:
    uVar17 = (*pcVar33)(param_1);
    (**(code **)(local_90 + -0x7fc8))(uVar17,0x2e,0,&local_80);
    if (local_80 == 2) {
      uVar17 = 6;
      param_1 = 6;
    }
    else {
      uVar17 = 0x12;
      if (local_80 == 10) {
        param_1 = 0x12;
      }
      else {
        param_1 = 0;
        (**(code **)(local_90 + -0x7194))("s_cb.c",0x324,"0");
        uVar17 = 0;
      }
    }
    puStack_c8 = (undefined4 *)0x640000;
    puVar26 = (undefined4 *)0x327;
    puStack_cc = (undefined *)(**(code **)(local_90 + -0x7dd8))(uVar17,"s_cb.c");
    if (puStack_cc == (undefined *)0x0) {
      pcVar25 = "out of memory\n";
      (**(code **)(local_90 + -0x7fa8))(**(undefined4 **)(local_90 + -0x7fa4));
    }
    else {
      if (local_80 == 2) {
        *puStack_cc = local_7e;
        puStack_cc[1] = local_7d;
        puVar20 = puStack_cc + 2;
        uVar30 = (uint)puVar20 & 3;
        *(uint *)(puVar20 + -uVar30) =
             *(uint *)(puVar20 + -uVar30) & -1 << (4 - uVar30) * 8 | local_7c >> uVar30 * 8;
        puVar20 = puStack_cc + 5;
        uVar30 = (uint)puVar20 & 3;
        *(uint *)(puVar20 + -uVar30) =
             *(uint *)(puVar20 + -uVar30) & 0xffffffffU >> (uVar30 + 1) * 8 |
             local_7c << (3 - uVar30) * 8;
      }
      else if (local_80 == 10) {
        *puStack_cc = local_7e;
        puStack_cc[1] = local_7d;
        *(undefined4 *)(puStack_cc + 2) = local_78;
        *(undefined4 *)(puStack_cc + 6) = local_74;
        *(undefined4 *)(puStack_cc + 10) = local_70;
        *(undefined4 *)(puStack_cc + 0xe) = local_6c;
      }
      else {
        (**(code **)(local_90 + -0x7194))("s_cb.c",0x344,"0");
      }
      pcVar25 = acStack_64;
      uVar17 = (**(code **)(local_90 + -0x781c))();
      local_98 = &local_84;
      local_a0 = param_1;
      local_9c = pcVar25;
      (**(code **)(local_90 + -0x7190))(uVar17,*(undefined4 *)(local_90 + -0x7198),0x10,puStack_cc);
      (**(code **)(local_90 + -0x7f58))(puStack_cc);
      puVar26 = local_84;
      (**(code **)(local_90 + -0x52ec))(param_2);
      *param_3 = local_84;
      puStack_cc = (undefined *)0x1;
      puStack_c8 = local_84;
    }
  }
  if (local_24 == *(int *)puStack_c4) {
    return puStack_cc;
  }
  pcStack_b4 = verify_cookie_callback;
  (**(code **)(local_90 + -0x5328))();
  puVar20 = PTR___stack_chk_guard_006aabf0;
  uStack_d4 = *(uint *)PTR___stack_chk_guard_006aabf0;
  puStack_c0 = param_3;
  uStack_bc = param_2;
  uStack_b8 = param_1;
  if (cookie_initialized != 0) {
    uVar17 = (*(code *)PTR_SSL_get_rbio_006a8924)();
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar17,0x2e,0,&sStack_130);
    if (sStack_130 == 2) {
      uVar17 = 6;
      uVar32 = 6;
    }
    else {
      uVar17 = 0x12;
      if (sStack_130 == 10) {
        uVar32 = 0x12;
      }
      else {
        uVar32 = 0;
        (*(code *)PTR_OpenSSLDie_006a8d4c)("s_cb.c",0x375,"0");
        uVar17 = 0;
      }
    }
    puVar18 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar17,"s_cb.c",0x378);
    if (puVar18 == (undefined *)0x0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,"out of memory\n");
      puVar18 = (undefined *)0x0;
      goto LAB_0045f728;
    }
    if (sStack_130 == 2) {
      *puVar18 = uStack_12e;
      puVar18[1] = uStack_12d;
      puVar1 = puVar18 + 2;
      uVar30 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar30) =
           *(uint *)(puVar1 + -uVar30) & -1 << (4 - uVar30) * 8 | uStack_12c >> uVar30 * 8;
      puVar1 = puVar18 + 5;
      uVar30 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar30) =
           *(uint *)(puVar1 + -uVar30) & 0xffffffffU >> (uVar30 + 1) * 8 |
           uStack_12c << (3 - uVar30) * 8;
    }
    else if (sStack_130 == 10) {
      *puVar18 = uStack_12e;
      puVar18[1] = uStack_12d;
      *(undefined4 *)(puVar18 + 2) = uStack_128;
      *(undefined4 *)(puVar18 + 6) = uStack_124;
      *(undefined4 *)(puVar18 + 10) = uStack_120;
      *(undefined4 *)(puVar18 + 0xe) = uStack_11c;
    }
    else {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("s_cb.c",0x395,"0");
    }
    uVar17 = (*(code *)PTR_EVP_sha1_006a86c4)();
    (*(code *)PTR_HMAC_006a8d50)
              (uVar17,PTR_cookie_secret_006a8d48,0x10,puVar18,uVar32,auStack_114,&puStack_134);
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar18);
    if ((puStack_134 == puVar26) &&
       (iVar19 = (*(code *)PTR_memcmp_006aabd8)(auStack_114,pcVar25,puVar26), iVar19 == 0)) {
      puVar18 = (undefined *)0x1;
      goto LAB_0045f728;
    }
  }
  puVar18 = (undefined *)0x0;
LAB_0045f728:
  if (uStack_d4 == *(uint *)puVar20) {
    return puVar18;
  }
  uVar24 = uStack_d4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar30 = ghbn_cache._148_4_;
  if (((ghbn_cache._148_4_ == 0xffffffff) || (ghbn_cache._148_4_ != 0)) &&
     (iVar19 = (*(code *)PTR_strncmp_006aaa7c)(uVar24,ghbn_cache,0x80), iVar19 == 0)) {
    iVar19 = 0;
  }
  else {
    uVar21 = uVar30;
    if (ghbn_cache._300_4_ < uVar30) {
      uVar21 = ghbn_cache._300_4_;
    }
    uVar30 = (uint)(ghbn_cache._300_4_ < uVar30);
    if ((ghbn_cache._300_4_ == 0) ||
       (iVar19 = (*(code *)PTR_strncmp_006aaa7c)(uVar24,0x6abac0,0x80), iVar19 != 0)) {
      uVar29 = uVar21;
      if (ghbn_cache._452_4_ < uVar21) {
        uVar29 = ghbn_cache._452_4_;
      }
      if (ghbn_cache._452_4_ < uVar21) {
        uVar30 = 2;
      }
      if ((ghbn_cache._452_4_ == 0) ||
         (iVar19 = (*(code *)PTR_strncmp_006aaa7c)(uVar24,0x6abb58,0x80), iVar19 != 0)) {
        if (ghbn_cache._604_4_ < uVar29) {
          uVar30 = 3;
        }
        if ((ghbn_cache._604_4_ == 0) ||
           (iVar19 = (*(code *)PTR_strncmp_006aaa7c)(uVar24,0x6abbf0,0x80), iVar19 != 0)) {
          ghbn_miss = ghbn_miss + 1;
          puVar20 = (undefined *)(*(code *)PTR_gethostbyname_006aaa70)(uVar24);
          if (puVar20 == (undefined *)0x0) {
            puVar20 = (undefined *)0x0;
          }
          else {
            uVar21 = (*(code *)PTR_strlen_006aab30)(uVar24);
            if (uVar21 < 0x80) {
              uVar27 = 0x80;
              uVar21 = uVar21 + 1;
              iVar31 = uVar30 * 0x98;
              puVar28 = ghbn_cache + iVar31;
              iVar22 = (*(code *)PTR___memcpy_chk_006aab54)();
              uVar30 = (uint)puVar20 & 3;
              uVar29 = (uint)(puVar20 + 4) & 3;
              iVar19 = *(int *)(puVar20 + 4 + -uVar29);
              uVar2 = (uint)(puVar20 + 8) & 3;
              iVar5 = *(int *)(puVar20 + 8 + -uVar2);
              uVar3 = (uint)(puVar20 + 0xc) & 3;
              iVar6 = *(int *)(puVar20 + 0xc + -uVar3);
              uVar4 = (uint)(puVar20 + 0x10) & 3;
              iVar7 = *(int *)(puVar20 + 0x10 + -uVar4);
              uVar8 = (uint)(puVar20 + 3) & 3;
              uVar9 = (uint)(puVar20 + 7) & 3;
              uVar13 = *(uint *)(puVar20 + 7 + -uVar9);
              uVar10 = (uint)(puVar20 + 0xb) & 3;
              uVar14 = *(uint *)(puVar20 + 0xb + -uVar10);
              iVar23 = ghbn_miss + ghbn_hits;
              uVar11 = (uint)(puVar20 + 0xf) & 3;
              uVar15 = *(uint *)(puVar20 + 0xf + -uVar11);
              uVar12 = (uint)(puVar20 + 0x13) & 3;
              uVar16 = *(uint *)(puVar20 + 0x13 + -uVar12);
              *(uint *)(ghbn_cache + iVar31 + 0x80) =
                   (*(int *)(puVar20 + -uVar30) << uVar30 * 8 |
                   in_t0 & 0xffffffffU >> (4 - uVar30) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)(puVar20 + 3 + -uVar8) >> (3 - uVar8) * 8;
              *(uint *)(ghbn_cache + iVar31 + 0x84) =
                   (iVar19 << uVar29 * 8 | uVar27 & 0xffffffffU >> (4 - uVar29) * 8) &
                   -1 << (uVar9 + 1) * 8 | uVar13 >> (3 - uVar9) * 8;
              *(uint *)(ghbn_cache + iVar31 + 0x88) =
                   (iVar5 << uVar2 * 8 | uVar21 & 0xffffffffU >> (4 - uVar2) * 8) &
                   -1 << (uVar10 + 1) * 8 | uVar14 >> (3 - uVar10) * 8;
              *(uint *)(ghbn_cache + iVar31 + 0x8c) =
                   (iVar6 << uVar3 * 8 | uVar24 & 0xffffffffU >> (4 - uVar3) * 8) &
                   -1 << (uVar11 + 1) * 8 | uVar15 >> (3 - uVar11) * 8;
              *(uint *)(ghbn_cache + iVar31 + 0x90) =
                   (iVar7 << uVar4 * 8 | (uint)puVar28 & 0xffffffffU >> (4 - uVar4) * 8) &
                   -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
              *(int *)(iVar22 + 0x94) = iVar23;
            }
          }
          return puVar20;
        }
        iVar19 = 3;
      }
      else {
        iVar19 = 2;
      }
    }
    else {
      iVar19 = 1;
    }
  }
  ghbn_hits = ghbn_hits + 1;
  *(int *)(ghbn_cache + iVar19 * 0x98 + 0x94) = ghbn_miss + ghbn_hits;
  return ghbn_cache + iVar19 * 0x98 + 0x80;
}

