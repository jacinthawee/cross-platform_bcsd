
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint verify_cookie_callback(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined *puVar18;
  uint uVar19;
  undefined4 uVar20;
  undefined *puVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  uint uVar28;
  uint in_t0;
  undefined1 *puVar29;
  int iVar30;
  undefined4 uVar31;
  int local_84;
  short local_80;
  undefined local_7e;
  undefined local_7d;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined auStack_64 [64];
  uint local_24;
  
  puVar18 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if (cookie_initialized != 0) {
    uVar20 = (*(code *)PTR_SSL_get_rbio_006a7838)();
    (*(code *)PTR_BIO_ctrl_006a6e18)(uVar20,0x2e,0,&local_80);
    if (local_80 == 2) {
      uVar20 = 6;
      uVar31 = 6;
    }
    else {
      uVar20 = 0x12;
      if (local_80 == 10) {
        uVar31 = 0x12;
      }
      else {
        uVar31 = 0;
        (*(code *)PTR_OpenSSLDie_006a7c5c)("s_cb.c",0x350,"0");
        uVar20 = 0;
      }
    }
    puVar21 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar20,"s_cb.c",0x353);
    if (puVar21 == (undefined *)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"out of memory\n");
      uVar19 = 0;
      goto LAB_00460238;
    }
    if (local_80 == 2) {
      *puVar21 = local_7e;
      puVar21[1] = local_7d;
      puVar1 = puVar21 + 2;
      uVar19 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar19) =
           *(uint *)(puVar1 + -uVar19) & -1 << (4 - uVar19) * 8 | local_7c >> uVar19 * 8;
      puVar1 = puVar21 + 5;
      uVar19 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar19) =
           *(uint *)(puVar1 + -uVar19) & 0xffffffffU >> (uVar19 + 1) * 8 |
           local_7c << (3 - uVar19) * 8;
    }
    else if (local_80 == 10) {
      *puVar21 = local_7e;
      puVar21[1] = local_7d;
      *(undefined4 *)(puVar21 + 2) = local_78;
      *(undefined4 *)(puVar21 + 6) = local_74;
      *(undefined4 *)(puVar21 + 10) = local_70;
      *(undefined4 *)(puVar21 + 0xe) = local_6c;
    }
    else {
      (*(code *)PTR_OpenSSLDie_006a7c5c)("s_cb.c",0x368,"0");
    }
    uVar20 = (*(code *)PTR_EVP_sha1_006a75d0)();
    (*(code *)PTR_HMAC_006a7c60)
              (uVar20,PTR_cookie_secret_006a7c58,0x10,puVar21,uVar31,auStack_64,&local_84);
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar21);
    if ((local_84 == param_3) &&
       (iVar22 = (*(code *)PTR_memcmp_006a9ad0)(auStack_64,param_2,param_3), iVar22 == 0)) {
      uVar19 = 1;
      goto LAB_00460238;
    }
  }
  uVar19 = 0;
LAB_00460238:
  if (local_24 == *(uint *)puVar18) {
    return uVar19;
  }
  uVar27 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar19 = ghbn_cache._148_4_;
  if (((ghbn_cache._148_4_ == 0xffffffff) || (ghbn_cache._148_4_ != 0)) &&
     (iVar22 = (*(code *)PTR_strncmp_006a9970)(uVar27,ghbn_cache,0x80), iVar22 == 0)) {
    iVar22 = 0;
  }
  else {
    uVar23 = uVar19;
    if (ghbn_cache._300_4_ < uVar19) {
      uVar23 = ghbn_cache._300_4_;
    }
    uVar19 = (uint)(ghbn_cache._300_4_ < uVar19);
    if ((ghbn_cache._300_4_ == 0) ||
       (iVar22 = (*(code *)PTR_strncmp_006a9970)(uVar27,0x6aa9b0,0x80), iVar22 != 0)) {
      uVar24 = uVar23;
      if (ghbn_cache._452_4_ < uVar23) {
        uVar24 = ghbn_cache._452_4_;
      }
      if (ghbn_cache._452_4_ < uVar23) {
        uVar19 = 2;
      }
      if ((ghbn_cache._452_4_ == 0) ||
         (iVar22 = (*(code *)PTR_strncmp_006a9970)(uVar27,0x6aaa48,0x80), iVar22 != 0)) {
        if (ghbn_cache._604_4_ < uVar24) {
          uVar19 = 3;
        }
        if ((ghbn_cache._604_4_ == 0) ||
           (iVar22 = (*(code *)PTR_strncmp_006a9970)(uVar27,0x6aaae0,0x80), iVar22 != 0)) {
          ghbn_miss = ghbn_miss + 1;
          uVar23 = (*(code *)PTR_gethostbyname_006a9960)(uVar27);
          if (uVar23 == 0) {
            uVar23 = 0;
          }
          else {
            uVar24 = (*(code *)PTR_strlen_006a9a24)(uVar27);
            if (uVar24 < 0x80) {
              uVar28 = 0x80;
              uVar24 = uVar24 + 1;
              iVar30 = uVar19 * 0x98;
              puVar29 = ghbn_cache + iVar30;
              iVar25 = (*(code *)PTR___memcpy_chk_006a9a48)();
              uVar19 = uVar23 & 3;
              uVar2 = uVar23 + 4 & 3;
              iVar22 = *(int *)((uVar23 + 4) - uVar2);
              uVar3 = uVar23 + 8 & 3;
              iVar6 = *(int *)((uVar23 + 8) - uVar3);
              uVar4 = uVar23 + 0xc & 3;
              iVar7 = *(int *)((uVar23 + 0xc) - uVar4);
              uVar5 = uVar23 + 0x10 & 3;
              iVar8 = *(int *)((uVar23 + 0x10) - uVar5);
              uVar9 = uVar23 + 3 & 3;
              uVar10 = uVar23 + 7 & 3;
              uVar14 = *(uint *)((uVar23 + 7) - uVar10);
              uVar11 = uVar23 + 0xb & 3;
              uVar15 = *(uint *)((uVar23 + 0xb) - uVar11);
              iVar26 = ghbn_miss + ghbn_hits;
              uVar12 = uVar23 + 0xf & 3;
              uVar16 = *(uint *)((uVar23 + 0xf) - uVar12);
              uVar13 = uVar23 + 0x13 & 3;
              uVar17 = *(uint *)((uVar23 + 0x13) - uVar13);
              *(uint *)(ghbn_cache + iVar30 + 0x80) =
                   (*(int *)(uVar23 - uVar19) << uVar19 * 8 |
                   in_t0 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar9 + 1) * 8 |
                   *(uint *)((uVar23 + 3) - uVar9) >> (3 - uVar9) * 8;
              *(uint *)(ghbn_cache + iVar30 + 0x84) =
                   (iVar22 << uVar2 * 8 | uVar28 & 0xffffffffU >> (4 - uVar2) * 8) &
                   -1 << (uVar10 + 1) * 8 | uVar14 >> (3 - uVar10) * 8;
              *(uint *)(ghbn_cache + iVar30 + 0x88) =
                   (iVar6 << uVar3 * 8 | uVar24 & 0xffffffffU >> (4 - uVar3) * 8) &
                   -1 << (uVar11 + 1) * 8 | uVar15 >> (3 - uVar11) * 8;
              *(uint *)(ghbn_cache + iVar30 + 0x8c) =
                   (iVar7 << uVar4 * 8 | uVar27 & 0xffffffffU >> (4 - uVar4) * 8) &
                   -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
              *(uint *)(ghbn_cache + iVar30 + 0x90) =
                   (iVar8 << uVar5 * 8 | (uint)puVar29 & 0xffffffffU >> (4 - uVar5) * 8) &
                   -1 << (uVar13 + 1) * 8 | uVar17 >> (3 - uVar13) * 8;
              *(int *)(iVar25 + 0x94) = iVar26;
            }
          }
          return uVar23;
        }
        iVar22 = 3;
      }
      else {
        iVar22 = 2;
      }
    }
    else {
      iVar22 = 1;
    }
  }
  ghbn_hits = ghbn_hits + 1;
  *(int *)(ghbn_cache + iVar22 * 0x98 + 0x94) = ghbn_miss + ghbn_hits;
  return iVar22 * 0x98 + 0x6aa998;
}

