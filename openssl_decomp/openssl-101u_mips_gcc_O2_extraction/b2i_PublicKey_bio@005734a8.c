
EVP_PKEY * b2i_PublicKey_bio(BIO *in)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  rsa_st *prVar4;
  uint uVar5;
  rsa_st *prVar6;
  int iVar7;
  BIGNUM **ppBVar8;
  undefined *puVar9;
  undefined *puVar10;
  BIGNUM **ppBVar11;
  BIGNUM *pBVar12;
  rsa_st *prVar13;
  ENGINE *pEVar14;
  BIGNUM *pBVar15;
  int iVar16;
  int iVar17;
  rsa_st *prVar18;
  rsa_st *unaff_s2;
  rsa_st *prVar19;
  rsa_st *prVar20;
  BIGNUM *unaff_s4;
  rsa_st *unaff_s5;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar21;
  undefined *puVar22;
  undefined *puVar23;
  int iStack_88;
  int iStack_84;
  rsa_st *prStack_80;
  ENGINE *pEStack_7c;
  rsa_st *prStack_78;
  BIO *pBStack_74;
  BIGNUM *pBStack_70;
  rsa_st *prStack_6c;
  rsa_st *prStack_68;
  rsa_st *local_38;
  char local_34;
  char local_33;
  RSA_METHOD *local_2c;
  ENGINE *local_28;
  BIGNUM *local_24;
  
  prVar20 = (rsa_st *)PTR___stack_chk_guard_006a9ae8;
  prVar13 = (rsa_st *)&SUB_00000010;
  prVar6 = (rsa_st *)&local_34;
  local_24 = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  prVar19 = prVar6;
  iVar3 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar3 == 0x10) {
    local_38 = prVar6;
    if (local_34 != '\x06') {
      if (local_34 == '\a') {
        prVar13 = (rsa_st *)&DAT_00000078;
        goto LAB_005735cc;
      }
      goto LAB_00573528;
    }
    if (local_33 != '\x02') {
      prVar13 = (rsa_st *)0x75;
LAB_005735cc:
      prVar19 = (rsa_st *)0x86;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,prVar13,FUN_0066c47c);
      goto LAB_00573528;
    }
    uVar5 = ((((uint)local_2c >> 0x10) << 0x18 | ((uint)local_2c >> 0x18) << 0x10) >> 0x10) +
            (((uint)local_2c & 0xff) << 8 | (uint)local_2c >> 8 & 0xff) * 0x10000;
    unaff_s2 = (rsa_st *)
               (((((uint)local_28 >> 0x10) << 0x18 | ((uint)local_28 >> 0x18) << 0x10) >> 0x10) +
               (((uint)local_28 & 0xff) << 8 | (uint)local_28 >> 8 & 0xff) * 0x10000);
    if (uVar5 != 0x31535344) {
      if (uVar5 < 0x31535345) {
        unaff_s4 = (BIGNUM *)0x0;
        if (uVar5 == 0x31415352) {
          prVar6 = (rsa_st *)(((uint)((int)&unaff_s2->version + 3) >> 3) + 4);
          goto LAB_00573630;
        }
      }
      else if ((uVar5 == 0x32415352) || (uVar5 == 0x32535344)) {
        prVar13 = (rsa_st *)&DAT_00000078;
        goto LAB_005735cc;
      }
      prVar13 = (rsa_st *)&DAT_00000074;
      goto LAB_005735cc;
    }
    unaff_s4 = (BIGNUM *)0x1;
    prVar6 = (rsa_st *)(((uint)((int)&unaff_s2->version + 3) >> 3) * 3 + 0x2c);
LAB_00573630:
    local_38 = (rsa_st *)&local_24;
    unaff_s6 = (rsa_st *)0x670000;
    if ((rsa_st *)0x19000 < prVar6) {
      prVar13 = (rsa_st *)&DAT_00000080;
      goto LAB_005735f8;
    }
    unaff_s5 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar6,FUN_0066c47c,0x11a);
    if (unaff_s5 == (rsa_st *)0x0) {
      prVar13 = (rsa_st *)&DAT_00000041;
      prVar19 = (rsa_st *)0x85;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,0x41,FUN_0066c47c);
      prVar4 = (rsa_st *)0x0;
    }
    else {
      local_38 = unaff_s5;
      prVar19 = (rsa_st *)(*(code *)PTR_BIO_read_006a74c0)(in,unaff_s5,prVar6);
      if (prVar6 == prVar19) {
        prVar13 = (rsa_st *)0x1;
        prVar19 = unaff_s2;
        if (unaff_s4 == (BIGNUM *)0x0) {
          prVar4 = (rsa_st *)b2i_rsa_isra_1(&local_38);
        }
        else {
          prVar4 = (rsa_st *)b2i_dss_isra_0();
        }
      }
      else {
        prVar13 = (rsa_st *)0x7b;
        prVar19 = (rsa_st *)0x85;
        prVar4 = (rsa_st *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,0x7b,FUN_0066c47c);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s5);
      prVar6 = prVar4;
    }
  }
  else {
    prVar13 = (rsa_st *)0x7b;
LAB_005735f8:
    prVar19 = (rsa_st *)0x85;
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,prVar13,FUN_0066c47c);
LAB_00573528:
    prVar4 = (rsa_st *)0x0;
  }
  if (local_24 == *(BIGNUM **)prVar20) {
    return (EVP_PKEY *)prVar4;
  }
  pBVar12 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pEStack_7c = (ENGINE *)prVar20;
  iStack_88 = 0;
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  prStack_80 = prVar6;
  prStack_78 = unaff_s2;
  pBStack_74 = in;
  pBStack_70 = unaff_s4;
  prStack_6c = unaff_s5;
  prStack_68 = unaff_s6;
  if (prVar19->pad == 0x74) {
    prVar6 = ((_union_271 *)&prVar19->e)->rsa;
    unaff_s2 = (rsa_st *)(*(code *)PTR_BN_num_bits_006a71f4)((EVP_PKEY_ASN1_METHOD *)prVar6->engine)
    ;
    if ((((((uint)unaff_s2 & 7) != 0) ||
         (iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar6->n), iVar3 != 0xa0)) ||
        (iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(((_union_271 *)&prVar6->e)->ptr),
        (int)unaff_s2 < iVar3)) ||
       (iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar6->p), 0xa0 < iVar3)) {
      prVar13 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x82,0x7e,FUN_0066c47c,0x222);
      goto LAB_00573fe8;
    }
    iStack_88 = 0x32535344;
    if (unaff_s2 == (rsa_st *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar3 = (((uint)((int)&unaff_s2->version + 3) >> 3) + 0x20) * 2;
  }
  else {
    prVar4 = (rsa_st *)0xffffffff;
    if (prVar19->pad != 6) goto LAB_00573f4c;
    prVar13 = (rsa_st *)&iStack_88;
    unaff_s2 = (rsa_st *)check_bitlen_rsa(((_union_271 *)&prVar19->e)->ptr,0);
    if (unaff_s2 == (rsa_st *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar3 = (((uint)((int)&unaff_s2->version + 3) >> 3) + 2) * 2 +
            ((uint)((int)&unaff_s2->engine + 3) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar4 = (rsa_st *)(iVar3 + 0x10);
  prVar13 = (rsa_st *)0x1e8;
  prVar6 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar4,FUN_0066c47c);
  prVar20 = prVar4;
  if (prVar6 == (rsa_st *)0x0) goto LAB_00573fe8;
  *(undefined *)((int)&prVar6->pad + 2) = 0;
  *(undefined *)((int)&prVar6->pad + 3) = 0;
  *(undefined *)&prVar6->version = 0;
  *(char *)((int)&prVar6->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&prVar6->version + 2) = 0;
  *(undefined *)&prVar6->pad = 7;
  ppBVar21 = &prVar6->n;
  *(undefined *)((int)&prVar6->version + 3) = 0;
  *(char *)&prVar6->engine = (char)unaff_s2;
  *(undefined *)((int)&prVar6->pad + 1) = 2;
  *(char *)((int)&prVar6->engine + 1) = (char)((uint)unaff_s2 >> 8);
  *(char *)((int)&prVar6->engine + 2) = (char)((uint)unaff_s2 >> 0x10);
  *(char *)((int)&prVar6->engine + 3) = (char)((uint)unaff_s2 >> 0x18);
  *(char *)&prVar6->meth = (char)iStack_88;
  *(char *)((int)&prVar6->meth + 1) = (char)((uint)iStack_88 >> 8);
  *(char *)((int)&prVar6->meth + 2) = (char)((uint)iStack_88 >> 0x10);
  *(char *)((int)&prVar6->meth + 3) = (char)((uint)iStack_88 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar20 = ((_union_271 *)&prVar19->e)->rsa;
    iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar20->engine);
    pEVar14 = prVar20->engine;
    iVar3 = iVar7 + 7;
    if (iVar7 + 7 < 0) {
      iVar3 = iVar7 + 0xe;
    }
    iVar3 = iVar3 >> 3;
    iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(pEVar14);
    iVar17 = iVar16 + 7;
    iVar7 = iVar16 + 0xe;
    if (-1 < iVar17) {
      iVar7 = iVar17;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pEVar14,ppBVar21);
    iVar7 = iVar7 >> 3;
    iVar16 = iVar16 + 0x16;
    if (-1 < iVar17) {
      iVar16 = iVar17;
    }
    if (0 < iVar16 >> 4) {
      ppBVar11 = ppBVar21;
      puVar23 = (undefined *)((int)ppBVar21 + iVar7 + -1);
      do {
        uVar1 = *(undefined *)ppBVar11;
        ppBVar8 = (BIGNUM **)((int)ppBVar11 + 1);
        *(undefined *)ppBVar11 = *puVar23;
        *puVar23 = uVar1;
        ppBVar11 = ppBVar8;
        puVar23 = puVar23 + -1;
      } while ((BIGNUM **)((int)ppBVar21 + (iVar16 >> 4)) != ppBVar8);
    }
    puVar22 = (undefined *)((int)ppBVar21 + iVar7);
    puVar23 = puVar22;
    if ((0 < iVar3) && (0 < iVar3 - iVar7)) {
      puVar23 = puVar22 + (iVar3 - iVar7);
      (*(code *)PTR_memset_006a99f4)(puVar22,0);
    }
    pBVar15 = prVar20->n;
    iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar17 = iVar16 + 7;
    iVar7 = iVar16 + 0xe;
    if (-1 < iVar17) {
      iVar7 = iVar17;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
    iVar7 = iVar7 >> 3;
    iVar16 = iVar16 + 0x16;
    if (-1 < iVar17) {
      iVar16 = iVar17;
    }
    if (0 < iVar16 >> 4) {
      puVar22 = puVar23;
      puVar10 = puVar23 + iVar7 + -1;
      do {
        uVar1 = *puVar22;
        puVar9 = puVar22 + 1;
        *puVar22 = *puVar10;
        *puVar10 = uVar1;
        puVar22 = puVar9;
        puVar10 = puVar10 + -1;
      } while (puVar23 + (iVar16 >> 4) != puVar9);
    }
    puVar23 = puVar23 + iVar7;
    puVar22 = puVar23;
    if (0 < 0x14 - iVar7) {
      puVar22 = puVar23 + (0x14 - iVar7);
      (*(code *)PTR_memset_006a99f4)(puVar23,0);
    }
    pBVar15 = prVar20->e;
    iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar16 = iVar17 + 7;
    iVar7 = iVar17 + 0xe;
    if (-1 < iVar16) {
      iVar7 = iVar16;
    }
    iVar7 = iVar7 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar22);
    if (-1 >= iVar16) {
      iVar16 = iVar17 + 0x16;
    }
    if (0 < iVar16 >> 4) {
      puVar23 = puVar22;
      puVar10 = puVar22 + iVar7 + -1;
      do {
        uVar1 = *puVar23;
        puVar9 = puVar23 + 1;
        *puVar23 = *puVar10;
        *puVar10 = uVar1;
        puVar23 = puVar9;
        puVar10 = puVar10 + -1;
      } while (puVar9 != puVar22 + (iVar16 >> 4));
    }
    prVar19 = (rsa_st *)(puVar22 + iVar7);
    unaff_s7 = prVar19;
    if ((0 < iVar3) && (0 < iVar3 - iVar7)) {
      unaff_s7 = (rsa_st *)((int)prVar19 + (iVar3 - iVar7));
      (*(code *)PTR_memset_006a99f4)(prVar19,0);
    }
    pBVar15 = prVar20->p;
    iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    prVar20 = (rsa_st *)(iVar3 + 7);
    prVar19 = (rsa_st *)(iVar3 + 0xe);
    if (-1 < (int)prVar20) {
      prVar19 = prVar20;
    }
    unaff_s6 = (rsa_st *)(iVar3 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,unaff_s7);
    if (-1 >= (int)prVar20) {
      prVar20 = unaff_s6;
    }
    prVar19 = (rsa_st *)((int)prVar19 >> 3);
    if (0 < (int)prVar20 >> 4) {
      prVar13 = unaff_s7;
      puVar23 = (undefined *)((int)&prVar19[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar13->pad;
        prVar18 = (rsa_st *)((int)&prVar13->pad + 1);
        *(undefined *)&prVar13->pad = *puVar23;
        *puVar23 = uVar1;
        prVar13 = prVar18;
        puVar23 = puVar23 + -1;
      } while (prVar18 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar20 >> 4)));
    }
    prVar20 = (rsa_st *)((int)&prVar19->pad + (int)&unaff_s7->pad);
    unaff_s2 = prVar20;
    if (0 < 0x14 - (int)prVar19) {
      unaff_s2 = (rsa_st *)((int)prVar20 + (0x14 - (int)prVar19));
      (*(code *)PTR_memset_006a99f4)(prVar20,0);
    }
    prVar13 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006a99f4)(unaff_s2,0xff);
    prVar18 = prVar6;
    goto LAB_00573f14;
  }
  unaff_s6 = ((_union_271 *)&prVar19->e)->rsa;
  iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  iVar3 = iVar7 + 7;
  if (iVar7 + 7 < 0) {
    iVar3 = iVar7 + 0xe;
  }
  prVar19 = (rsa_st *)(iVar3 >> 3);
  iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  pBVar15 = unaff_s6->e;
  unaff_s2 = (rsa_st *)(iVar3 + 0xf >> 4);
  iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
  iVar16 = iVar7 + 7;
  iVar3 = iVar7 + 0xe;
  if (-1 < iVar16) {
    iVar3 = iVar16;
  }
  iVar3 = iVar3 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,ppBVar21);
  iVar7 = iVar7 + 0x16;
  if (-1 < iVar16) {
    iVar7 = iVar16;
  }
  if (0 < iVar7 >> 4) {
    ppBVar11 = ppBVar21;
    puVar23 = (undefined *)((int)ppBVar21 + iVar3 + -1);
    do {
      uVar1 = *(undefined *)ppBVar11;
      ppBVar8 = (BIGNUM **)((int)ppBVar11 + 1);
      *(undefined *)ppBVar11 = *puVar23;
      *puVar23 = uVar1;
      ppBVar11 = ppBVar8;
      puVar23 = puVar23 + -1;
    } while ((BIGNUM **)((int)ppBVar21 + (iVar7 >> 4)) != ppBVar8);
  }
  puVar22 = (undefined *)((int)ppBVar21 + iVar3);
  puVar23 = puVar22;
  if (0 < 4 - iVar3) {
    puVar23 = puVar22 + (4 - iVar3);
    (*(code *)PTR_memset_006a99f4)(puVar22,0);
  }
  pBVar15 = unaff_s6->n;
  iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
  iVar7 = iVar16 + 7;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
  iVar3 = iVar7;
  if (iVar7 < 0) {
    iVar7 = iVar16 + 0x16;
    iVar3 = iVar16 + 0xe;
  }
  if (0 < iVar7 >> 4) {
    puVar22 = puVar23;
    puVar10 = puVar23 + (iVar3 >> 3) + -1;
    do {
      uVar1 = *puVar22;
      puVar9 = puVar22 + 1;
      *puVar22 = *puVar10;
      *puVar10 = uVar1;
      puVar22 = puVar9;
      puVar10 = puVar10 + -1;
    } while (puVar9 != puVar23 + (iVar7 >> 4));
  }
  pBVar15 = unaff_s6->p;
  puVar23 = puVar23 + (iVar3 >> 3);
  iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
  iVar16 = iVar7 + 7;
  iVar3 = iVar7 + 0xe;
  if (-1 < iVar16) {
    iVar3 = iVar16;
  }
  iVar3 = iVar3 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
  iVar7 = iVar7 + 0x16;
  if (-1 < iVar16) {
    iVar7 = iVar16;
  }
  if (0 < iVar7 >> 4) {
    puVar22 = puVar23;
    puVar10 = puVar23 + iVar3 + -1;
    do {
      uVar1 = *puVar22;
      puVar9 = puVar22 + 1;
      *puVar22 = *puVar10;
      *puVar10 = uVar1;
      puVar22 = puVar9;
      puVar10 = puVar10 + -1;
    } while (puVar23 + (iVar7 >> 4) != puVar9);
  }
  puVar23 = puVar23 + iVar3;
  if ((int)unaff_s2 < 1) {
    pBVar15 = unaff_s6->q;
    iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar16 = iVar7 + 7;
    iVar3 = iVar7 + 0xe;
    if (-1 < iVar16) {
      iVar3 = iVar16;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
    iVar7 = iVar7 + 0x16;
    if (-1 < iVar16) {
      iVar7 = iVar16;
    }
    iVar7 = iVar7 >> 4;
    puVar22 = puVar23 + iVar3 + -1;
    if (0 < iVar7) goto LAB_00573bc8;
    puVar23 = puVar23 + iVar3;
LAB_00574388:
    pBVar15 = unaff_s6->dmp1;
    iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar16 = iVar7 + 7;
    iVar3 = iVar7 + 0xe;
    if (-1 < iVar16) {
      iVar3 = iVar16;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
    iVar7 = iVar7 + 0x16;
    if (-1 < iVar16) {
      iVar7 = iVar16;
    }
    iVar7 = iVar7 >> 4;
    puVar22 = puVar23 + iVar3 + -1;
    if (0 < iVar7) goto LAB_00573c8c;
    puVar23 = puVar23 + iVar3;
LAB_00574400:
    pBVar15 = unaff_s6->dmq1;
    iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar3 = iVar16 + 7;
    iVar7 = iVar16 + 0xe;
    if (-1 < iVar3) {
      iVar7 = iVar3;
    }
    iVar7 = iVar7 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
    if (-1 >= iVar3) {
      iVar3 = iVar16 + 0x16;
    }
    iVar3 = iVar3 >> 4;
    puVar22 = puVar23 + iVar7 + -1;
    if (0 < iVar3) goto LAB_00573d50;
LAB_00573d74:
    unaff_s7 = (rsa_st *)(puVar23 + iVar7);
    if ((int)unaff_s2 < 1) {
      pBVar15 = unaff_s6->iqmp;
      iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
      iVar7 = iVar16 + 7;
      iVar3 = iVar16 + 0xe;
      if (-1 < iVar7) {
        iVar3 = iVar7;
      }
      prVar13 = (rsa_st *)(iVar3 >> 3);
      (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,unaff_s7);
      if (-1 >= iVar7) {
        iVar7 = iVar16 + 0x16;
      }
      iVar7 = iVar7 >> 4;
      puVar23 = (undefined *)((int)&prVar13[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar7 < 1) {
        unaff_s7 = (rsa_st *)((int)&prVar13->pad + (int)&unaff_s7->pad);
        goto LAB_00573e60;
      }
      goto LAB_00573e14;
    }
  }
  else {
    iVar3 = (int)unaff_s2 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006a99f4)(puVar23,0,iVar3);
      puVar23 = puVar23 + iVar3;
    }
    pBVar15 = unaff_s6->q;
    iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar16 = iVar7 + 7;
    iVar3 = iVar7 + 0xe;
    if (-1 < iVar16) {
      iVar3 = iVar16;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
    iVar7 = iVar7 + 0x16;
    if (-1 < iVar16) {
      iVar7 = iVar16;
    }
    iVar7 = iVar7 >> 4;
    puVar22 = puVar23 + iVar3 + -1;
    if (iVar7 < 1) {
      puVar23 = puVar23 + iVar3;
    }
    else {
LAB_00573bc8:
      puVar10 = puVar23;
      do {
        uVar1 = *puVar10;
        puVar9 = puVar10 + 1;
        *puVar10 = *puVar22;
        *puVar22 = uVar1;
        puVar10 = puVar9;
        puVar22 = puVar22 + -1;
      } while (puVar23 + iVar7 != puVar9);
      puVar23 = puVar23 + iVar3;
      if ((int)unaff_s2 < 1) goto LAB_00574388;
    }
    iVar3 = (int)unaff_s2 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006a99f4)(puVar23,0,iVar3);
      puVar23 = puVar23 + iVar3;
    }
    pBVar15 = unaff_s6->dmp1;
    iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar16 = iVar7 + 7;
    iVar3 = iVar7 + 0xe;
    if (-1 < iVar16) {
      iVar3 = iVar16;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
    iVar7 = iVar7 + 0x16;
    if (-1 < iVar16) {
      iVar7 = iVar16;
    }
    iVar7 = iVar7 >> 4;
    puVar22 = puVar23 + iVar3 + -1;
    if (iVar7 < 1) {
      puVar23 = puVar23 + iVar3;
    }
    else {
LAB_00573c8c:
      puVar10 = puVar23;
      do {
        uVar1 = *puVar10;
        puVar9 = puVar10 + 1;
        *puVar10 = *puVar22;
        *puVar22 = uVar1;
        puVar10 = puVar9;
        puVar22 = puVar22 + -1;
      } while (puVar23 + iVar7 != puVar9);
      puVar23 = puVar23 + iVar3;
      if ((int)unaff_s2 < 1) goto LAB_00574400;
    }
    iVar3 = (int)unaff_s2 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006a99f4)(puVar23,0,iVar3);
      puVar23 = puVar23 + iVar3;
    }
    pBVar15 = unaff_s6->dmq1;
    iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar3 = iVar16 + 7;
    iVar7 = iVar16 + 0xe;
    if (-1 < iVar3) {
      iVar7 = iVar3;
    }
    iVar7 = iVar7 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,puVar23);
    if (-1 >= iVar3) {
      iVar3 = iVar16 + 0x16;
    }
    iVar3 = iVar3 >> 4;
    puVar22 = puVar23 + iVar7 + -1;
    if (0 < iVar3) {
LAB_00573d50:
      puVar10 = puVar23;
      do {
        uVar1 = *puVar10;
        puVar9 = puVar10 + 1;
        *puVar10 = *puVar22;
        *puVar22 = uVar1;
        puVar22 = puVar22 + -1;
        puVar10 = puVar9;
      } while (puVar23 + iVar3 != puVar9);
      goto LAB_00573d74;
    }
    unaff_s7 = (rsa_st *)(puVar23 + iVar7);
  }
  iVar7 = (int)unaff_s2 - iVar7;
  if (0 < iVar7) {
    (*(code *)PTR_memset_006a99f4)(unaff_s7,0,iVar7);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar7);
  }
  pBVar15 = unaff_s6->iqmp;
  iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
  iVar7 = iVar16 + 7;
  iVar3 = iVar16 + 0xe;
  if (-1 < iVar7) {
    iVar3 = iVar7;
  }
  prVar13 = (rsa_st *)(iVar3 >> 3);
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,unaff_s7);
  if (-1 >= iVar7) {
    iVar7 = iVar16 + 0x16;
  }
  iVar7 = iVar7 >> 4;
  puVar23 = (undefined *)((int)&prVar13[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar7 < 1) goto LAB_00574578;
LAB_00573e14:
  prVar20 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar20->pad;
    prVar18 = (rsa_st *)((int)&prVar20->pad + 1);
    *(undefined *)&prVar20->pad = *puVar23;
    *puVar23 = uVar1;
    puVar23 = puVar23 + -1;
    prVar20 = prVar18;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar7) != prVar18);
  prVar20 = (rsa_st *)((int)&prVar13->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar20;
  if ((int)unaff_s2 < 1) goto LAB_00573e60;
  do {
    unaff_s7 = prVar20;
    if (0 < (int)unaff_s2 - (int)prVar13) {
      unaff_s7 = (rsa_st *)((int)prVar20 + ((int)unaff_s2 - (int)prVar13));
      (*(code *)PTR_memset_006a99f4)(prVar20,0);
    }
LAB_00573e60:
    pBVar15 = unaff_s6->d;
    iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar15);
    iVar3 = iVar16 + 7;
    unaff_s2 = (rsa_st *)(uint)(iVar3 < 0);
    iVar7 = iVar16 + 0xe;
    if (unaff_s2 == (rsa_st *)0x0) {
      iVar7 = iVar3;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar15,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar7 >> 3);
    if (unaff_s2 != (rsa_st *)0x0) {
      iVar3 = iVar16 + 0x16;
    }
    prVar13 = (rsa_st *)(iVar3 >> 4);
    if (0 < (int)prVar13) {
      prVar13 = (rsa_st *)((int)&prVar13->pad + (int)&unaff_s7->pad);
      puVar23 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar20 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar20->pad;
        prVar18 = (rsa_st *)((int)&prVar20->pad + 1);
        *(undefined *)&prVar20->pad = *puVar23;
        *puVar23 = uVar1;
        puVar23 = puVar23 + -1;
        prVar20 = prVar18;
      } while (prVar13 != prVar18);
    }
    prVar18 = prVar6;
    if ((0 < (int)prVar19) && (prVar13 = (rsa_st *)((int)prVar19 - (int)unaff_s6), 0 < (int)prVar13)
       ) {
      (*(code *)PTR_memset_006a99f4)((char *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00573f14:
    prVar6 = prVar18;
    prVar20 = prVar4;
    if ((int)prVar4 < 0) {
LAB_00573fe8:
      prVar4 = (rsa_st *)0xffffffff;
    }
    else {
      prVar13 = prVar4;
      prVar6 = (rsa_st *)(*(code *)PTR_BIO_write_006a6e14)(pBVar12,prVar18);
      (*(code *)PTR_CRYPTO_free_006a6e88)(prVar18);
      if (prVar6 != prVar4) goto LAB_00573fe8;
    }
LAB_00573f4c:
    if (iStack_84 == *(int *)puVar2) {
      return (EVP_PKEY *)prVar4;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    prVar4 = prVar20;
LAB_00574578:
    prVar20 = (rsa_st *)((int)&prVar13->pad + (int)&unaff_s7->pad);
  } while( true );
}

