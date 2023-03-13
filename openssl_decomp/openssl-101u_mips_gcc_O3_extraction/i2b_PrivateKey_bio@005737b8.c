
int i2b_PrivateKey_bio(BIO *out,EVP_PKEY *pk)

{
  undefined uVar1;
  undefined *puVar2;
  rsa_st *prVar3;
  int iVar4;
  BIGNUM **ppBVar5;
  undefined *puVar6;
  undefined *puVar7;
  BIGNUM **ppBVar8;
  rsa_st *prVar9;
  rsa_st *in_a2;
  ENGINE *pEVar10;
  BIGNUM *pBVar11;
  int iVar12;
  int iVar13;
  rsa_st *unaff_s0;
  rsa_st *unaff_s1;
  int iVar14;
  undefined *unaff_s2;
  rsa_st *prVar15;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar16;
  undefined *puVar17;
  undefined *puVar18;
  rsa_st *prVar19;
  int local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pk->type == 0x74) {
    unaff_s0 = (pk->pkey).rsa;
    unaff_s2 = (undefined *)(*(code *)PTR_BN_num_bits_006a71f4)(unaff_s0->engine);
    if ((((((uint)unaff_s2 & 7) != 0) ||
         (iVar14 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s0->n), iVar14 != 0xa0)) ||
        (iVar14 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s0->e), (int)unaff_s2 < iVar14)) ||
       (iVar14 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s0->p), 0xa0 < iVar14)) {
      in_a2 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x82,0x7e,FUN_0066c47c,0x222);
      goto LAB_00573fe8;
    }
    local_30 = 0x32535344;
    if (unaff_s2 == (undefined *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar14 = (((uint)(unaff_s2 + 7) >> 3) + 0x20) * 2;
  }
  else {
    prVar3 = (rsa_st *)0xffffffff;
    if (pk->type != 6) goto LAB_00573f4c;
    in_a2 = (rsa_st *)&local_30;
    unaff_s2 = (undefined *)check_bitlen_rsa((pk->pkey).ptr,0);
    if (unaff_s2 == (undefined *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar14 = (((uint)(unaff_s2 + 7) >> 3) + 2) * 2 + ((uint)(unaff_s2 + 0xf) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar3 = (rsa_st *)(iVar14 + 0x10);
  in_a2 = (rsa_st *)0x1e8;
  unaff_s0 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar3,FUN_0066c47c);
  unaff_s1 = prVar3;
  if (unaff_s0 == (rsa_st *)0x0) goto LAB_00573fe8;
  *(undefined *)((int)&unaff_s0->pad + 2) = 0;
  *(undefined *)((int)&unaff_s0->pad + 3) = 0;
  *(undefined *)&unaff_s0->version = 0;
  *(char *)((int)&unaff_s0->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&unaff_s0->version + 2) = 0;
  *(undefined *)&unaff_s0->pad = 7;
  ppBVar16 = &unaff_s0->n;
  *(undefined *)((int)&unaff_s0->version + 3) = 0;
  *(char *)&unaff_s0->engine = (char)unaff_s2;
  *(undefined *)((int)&unaff_s0->pad + 1) = 2;
  *(char *)((int)&unaff_s0->engine + 1) = (char)((uint)unaff_s2 >> 8);
  *(char *)((int)&unaff_s0->engine + 2) = (char)((uint)unaff_s2 >> 0x10);
  *(char *)((int)&unaff_s0->engine + 3) = (char)((uint)unaff_s2 >> 0x18);
  *(char *)&unaff_s0->meth = (char)local_30;
  *(char *)((int)&unaff_s0->meth + 1) = (char)((uint)local_30 >> 8);
  *(char *)((int)&unaff_s0->meth + 2) = (char)((uint)local_30 >> 0x10);
  *(char *)((int)&unaff_s0->meth + 3) = (char)((uint)local_30 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar15 = (pk->pkey).rsa;
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar15->engine);
    pEVar10 = prVar15->engine;
    iVar14 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar14 = iVar4 + 0xe;
    }
    iVar14 = iVar14 >> 3;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pEVar10);
    iVar13 = iVar12 + 7;
    iVar4 = iVar12 + 0xe;
    if (-1 < iVar13) {
      iVar4 = iVar13;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pEVar10,ppBVar16);
    iVar4 = iVar4 >> 3;
    iVar12 = iVar12 + 0x16;
    if (-1 < iVar13) {
      iVar12 = iVar13;
    }
    if (0 < iVar12 >> 4) {
      ppBVar8 = ppBVar16;
      puVar18 = (undefined *)((int)ppBVar16 + iVar4 + -1);
      do {
        uVar1 = *(undefined *)ppBVar8;
        ppBVar5 = (BIGNUM **)((int)ppBVar8 + 1);
        *(undefined *)ppBVar8 = *puVar18;
        *puVar18 = uVar1;
        ppBVar8 = ppBVar5;
        puVar18 = puVar18 + -1;
      } while ((BIGNUM **)((int)ppBVar16 + (iVar12 >> 4)) != ppBVar5);
    }
    puVar17 = (undefined *)((int)ppBVar16 + iVar4);
    puVar18 = puVar17;
    if ((0 < iVar14) && (0 < iVar14 - iVar4)) {
      puVar18 = puVar17 + (iVar14 - iVar4);
      (*(code *)PTR_memset_006a99f4)(puVar17,0);
    }
    pBVar11 = prVar15->n;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar13 = iVar12 + 7;
    iVar4 = iVar12 + 0xe;
    if (-1 < iVar13) {
      iVar4 = iVar13;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
    iVar4 = iVar4 >> 3;
    iVar12 = iVar12 + 0x16;
    if (-1 < iVar13) {
      iVar12 = iVar13;
    }
    if (0 < iVar12 >> 4) {
      puVar17 = puVar18;
      puVar7 = puVar18 + iVar4 + -1;
      do {
        uVar1 = *puVar17;
        puVar6 = puVar17 + 1;
        *puVar17 = *puVar7;
        *puVar7 = uVar1;
        puVar17 = puVar6;
        puVar7 = puVar7 + -1;
      } while (puVar18 + (iVar12 >> 4) != puVar6);
    }
    puVar18 = puVar18 + iVar4;
    puVar17 = puVar18;
    if (0 < 0x14 - iVar4) {
      puVar17 = puVar18 + (0x14 - iVar4);
      (*(code *)PTR_memset_006a99f4)(puVar18,0);
    }
    pBVar11 = prVar15->e;
    iVar13 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar12 = iVar13 + 7;
    iVar4 = iVar13 + 0xe;
    if (-1 < iVar12) {
      iVar4 = iVar12;
    }
    iVar4 = iVar4 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar17);
    if (-1 >= iVar12) {
      iVar12 = iVar13 + 0x16;
    }
    if (0 < iVar12 >> 4) {
      puVar18 = puVar17;
      puVar7 = puVar17 + iVar4 + -1;
      do {
        uVar1 = *puVar18;
        puVar6 = puVar18 + 1;
        *puVar18 = *puVar7;
        *puVar7 = uVar1;
        puVar18 = puVar6;
        puVar7 = puVar7 + -1;
      } while (puVar6 != puVar17 + (iVar12 >> 4));
    }
    prVar19 = (rsa_st *)(puVar17 + iVar4);
    unaff_s7 = prVar19;
    if ((0 < iVar14) && (0 < iVar14 - iVar4)) {
      unaff_s7 = (rsa_st *)((int)prVar19 + (iVar14 - iVar4));
      (*(code *)PTR_memset_006a99f4)(prVar19,0);
    }
    pBVar11 = prVar15->p;
    iVar14 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    prVar15 = (rsa_st *)(iVar14 + 7);
    prVar19 = (rsa_st *)(iVar14 + 0xe);
    if (-1 < (int)prVar15) {
      prVar19 = prVar15;
    }
    unaff_s6 = (rsa_st *)(iVar14 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,unaff_s7);
    if (-1 >= (int)prVar15) {
      prVar15 = unaff_s6;
    }
    pk = (EVP_PKEY *)((int)prVar19 >> 3);
    if (0 < (int)prVar15 >> 4) {
      prVar19 = unaff_s7;
      puVar18 = (undefined *)((int)&pk[-1].attributes + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar19->pad;
        prVar9 = (rsa_st *)((int)&prVar19->pad + 1);
        *(undefined *)&prVar19->pad = *puVar18;
        *puVar18 = uVar1;
        prVar19 = prVar9;
        puVar18 = puVar18 + -1;
      } while (prVar9 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar15 >> 4)));
    }
    puVar18 = (undefined *)((int)&pk->type + (int)&unaff_s7->pad);
    unaff_s2 = puVar18;
    if (0 < 0x14 - (int)pk) {
      unaff_s2 = puVar18 + (0x14 - (int)pk);
      (*(code *)PTR_memset_006a99f4)(puVar18,0);
    }
    in_a2 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006a99f4)(unaff_s2,0xff);
    prVar15 = unaff_s0;
    goto LAB_00573f14;
  }
  unaff_s6 = (pk->pkey).rsa;
  iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  iVar14 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar14 = iVar4 + 0xe;
  }
  pk = (EVP_PKEY *)(iVar14 >> 3);
  iVar14 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  pBVar11 = unaff_s6->e;
  unaff_s2 = (undefined *)(iVar14 + 0xf >> 4);
  iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
  iVar12 = iVar4 + 7;
  iVar14 = iVar4 + 0xe;
  if (-1 < iVar12) {
    iVar14 = iVar12;
  }
  iVar14 = iVar14 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,ppBVar16);
  iVar4 = iVar4 + 0x16;
  if (-1 < iVar12) {
    iVar4 = iVar12;
  }
  if (0 < iVar4 >> 4) {
    ppBVar8 = ppBVar16;
    puVar18 = (undefined *)((int)ppBVar16 + iVar14 + -1);
    do {
      uVar1 = *(undefined *)ppBVar8;
      ppBVar5 = (BIGNUM **)((int)ppBVar8 + 1);
      *(undefined *)ppBVar8 = *puVar18;
      *puVar18 = uVar1;
      ppBVar8 = ppBVar5;
      puVar18 = puVar18 + -1;
    } while ((BIGNUM **)((int)ppBVar16 + (iVar4 >> 4)) != ppBVar5);
  }
  puVar17 = (undefined *)((int)ppBVar16 + iVar14);
  puVar18 = puVar17;
  if (0 < 4 - iVar14) {
    puVar18 = puVar17 + (4 - iVar14);
    (*(code *)PTR_memset_006a99f4)(puVar17,0);
  }
  pBVar11 = unaff_s6->n;
  iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
  iVar4 = iVar12 + 7;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
  iVar14 = iVar4;
  if (iVar4 < 0) {
    iVar4 = iVar12 + 0x16;
    iVar14 = iVar12 + 0xe;
  }
  if (0 < iVar4 >> 4) {
    puVar17 = puVar18;
    puVar7 = puVar18 + (iVar14 >> 3) + -1;
    do {
      uVar1 = *puVar17;
      puVar6 = puVar17 + 1;
      *puVar17 = *puVar7;
      *puVar7 = uVar1;
      puVar17 = puVar6;
      puVar7 = puVar7 + -1;
    } while (puVar6 != puVar18 + (iVar4 >> 4));
  }
  pBVar11 = unaff_s6->p;
  puVar18 = puVar18 + (iVar14 >> 3);
  iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
  iVar12 = iVar4 + 7;
  iVar14 = iVar4 + 0xe;
  if (-1 < iVar12) {
    iVar14 = iVar12;
  }
  iVar14 = iVar14 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
  iVar4 = iVar4 + 0x16;
  if (-1 < iVar12) {
    iVar4 = iVar12;
  }
  if (0 < iVar4 >> 4) {
    puVar17 = puVar18;
    puVar7 = puVar18 + iVar14 + -1;
    do {
      uVar1 = *puVar17;
      puVar6 = puVar17 + 1;
      *puVar17 = *puVar7;
      *puVar7 = uVar1;
      puVar17 = puVar6;
      puVar7 = puVar7 + -1;
    } while (puVar18 + (iVar4 >> 4) != puVar6);
  }
  puVar18 = puVar18 + iVar14;
  if ((int)unaff_s2 < 1) {
    pBVar11 = unaff_s6->q;
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar12 = iVar4 + 7;
    iVar14 = iVar4 + 0xe;
    if (-1 < iVar12) {
      iVar14 = iVar12;
    }
    iVar14 = iVar14 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
    iVar4 = iVar4 + 0x16;
    if (-1 < iVar12) {
      iVar4 = iVar12;
    }
    iVar4 = iVar4 >> 4;
    puVar17 = puVar18 + iVar14 + -1;
    if (0 < iVar4) goto LAB_00573bc8;
    puVar18 = puVar18 + iVar14;
LAB_00574388:
    pBVar11 = unaff_s6->dmp1;
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar12 = iVar4 + 7;
    iVar14 = iVar4 + 0xe;
    if (-1 < iVar12) {
      iVar14 = iVar12;
    }
    iVar14 = iVar14 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
    iVar4 = iVar4 + 0x16;
    if (-1 < iVar12) {
      iVar4 = iVar12;
    }
    iVar4 = iVar4 >> 4;
    puVar17 = puVar18 + iVar14 + -1;
    if (0 < iVar4) goto LAB_00573c8c;
    puVar18 = puVar18 + iVar14;
LAB_00574400:
    pBVar11 = unaff_s6->dmq1;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar14 = iVar12 + 7;
    iVar4 = iVar12 + 0xe;
    if (-1 < iVar14) {
      iVar4 = iVar14;
    }
    iVar4 = iVar4 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
    if (-1 >= iVar14) {
      iVar14 = iVar12 + 0x16;
    }
    iVar14 = iVar14 >> 4;
    puVar17 = puVar18 + iVar4 + -1;
    if (0 < iVar14) goto LAB_00573d50;
LAB_00573d74:
    unaff_s7 = (rsa_st *)(puVar18 + iVar4);
    if ((int)unaff_s2 < 1) {
      pBVar11 = unaff_s6->iqmp;
      iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
      iVar4 = iVar12 + 7;
      iVar14 = iVar12 + 0xe;
      if (-1 < iVar4) {
        iVar14 = iVar4;
      }
      in_a2 = (rsa_st *)(iVar14 >> 3);
      (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,unaff_s7);
      if (-1 >= iVar4) {
        iVar4 = iVar12 + 0x16;
      }
      iVar4 = iVar4 >> 4;
      puVar18 = (undefined *)((int)&in_a2[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar4 < 1) {
        unaff_s7 = (rsa_st *)((int)&in_a2->pad + (int)&unaff_s7->pad);
        goto LAB_00573e60;
      }
      goto LAB_00573e14;
    }
  }
  else {
    iVar14 = (int)unaff_s2 - iVar14;
    if (0 < iVar14) {
      (*(code *)PTR_memset_006a99f4)(puVar18,0,iVar14);
      puVar18 = puVar18 + iVar14;
    }
    pBVar11 = unaff_s6->q;
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar12 = iVar4 + 7;
    iVar14 = iVar4 + 0xe;
    if (-1 < iVar12) {
      iVar14 = iVar12;
    }
    iVar14 = iVar14 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
    iVar4 = iVar4 + 0x16;
    if (-1 < iVar12) {
      iVar4 = iVar12;
    }
    iVar4 = iVar4 >> 4;
    puVar17 = puVar18 + iVar14 + -1;
    if (iVar4 < 1) {
      puVar18 = puVar18 + iVar14;
    }
    else {
LAB_00573bc8:
      puVar7 = puVar18;
      do {
        uVar1 = *puVar7;
        puVar6 = puVar7 + 1;
        *puVar7 = *puVar17;
        *puVar17 = uVar1;
        puVar7 = puVar6;
        puVar17 = puVar17 + -1;
      } while (puVar18 + iVar4 != puVar6);
      puVar18 = puVar18 + iVar14;
      if ((int)unaff_s2 < 1) goto LAB_00574388;
    }
    iVar14 = (int)unaff_s2 - iVar14;
    if (0 < iVar14) {
      (*(code *)PTR_memset_006a99f4)(puVar18,0,iVar14);
      puVar18 = puVar18 + iVar14;
    }
    pBVar11 = unaff_s6->dmp1;
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar12 = iVar4 + 7;
    iVar14 = iVar4 + 0xe;
    if (-1 < iVar12) {
      iVar14 = iVar12;
    }
    iVar14 = iVar14 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
    iVar4 = iVar4 + 0x16;
    if (-1 < iVar12) {
      iVar4 = iVar12;
    }
    iVar4 = iVar4 >> 4;
    puVar17 = puVar18 + iVar14 + -1;
    if (iVar4 < 1) {
      puVar18 = puVar18 + iVar14;
    }
    else {
LAB_00573c8c:
      puVar7 = puVar18;
      do {
        uVar1 = *puVar7;
        puVar6 = puVar7 + 1;
        *puVar7 = *puVar17;
        *puVar17 = uVar1;
        puVar7 = puVar6;
        puVar17 = puVar17 + -1;
      } while (puVar18 + iVar4 != puVar6);
      puVar18 = puVar18 + iVar14;
      if ((int)unaff_s2 < 1) goto LAB_00574400;
    }
    iVar14 = (int)unaff_s2 - iVar14;
    if (0 < iVar14) {
      (*(code *)PTR_memset_006a99f4)(puVar18,0,iVar14);
      puVar18 = puVar18 + iVar14;
    }
    pBVar11 = unaff_s6->dmq1;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar14 = iVar12 + 7;
    iVar4 = iVar12 + 0xe;
    if (-1 < iVar14) {
      iVar4 = iVar14;
    }
    iVar4 = iVar4 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,puVar18);
    if (-1 >= iVar14) {
      iVar14 = iVar12 + 0x16;
    }
    iVar14 = iVar14 >> 4;
    puVar17 = puVar18 + iVar4 + -1;
    if (0 < iVar14) {
LAB_00573d50:
      puVar7 = puVar18;
      do {
        uVar1 = *puVar7;
        puVar6 = puVar7 + 1;
        *puVar7 = *puVar17;
        *puVar17 = uVar1;
        puVar17 = puVar17 + -1;
        puVar7 = puVar6;
      } while (puVar18 + iVar14 != puVar6);
      goto LAB_00573d74;
    }
    unaff_s7 = (rsa_st *)(puVar18 + iVar4);
  }
  iVar4 = (int)unaff_s2 - iVar4;
  if (0 < iVar4) {
    (*(code *)PTR_memset_006a99f4)(unaff_s7,0,iVar4);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar4);
  }
  pBVar11 = unaff_s6->iqmp;
  iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
  iVar4 = iVar12 + 7;
  iVar14 = iVar12 + 0xe;
  if (-1 < iVar4) {
    iVar14 = iVar4;
  }
  in_a2 = (rsa_st *)(iVar14 >> 3);
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,unaff_s7);
  if (-1 >= iVar4) {
    iVar4 = iVar12 + 0x16;
  }
  iVar4 = iVar4 >> 4;
  puVar18 = (undefined *)((int)&in_a2[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar4 < 1) goto LAB_00574578;
LAB_00573e14:
  prVar15 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar15->pad;
    prVar19 = (rsa_st *)((int)&prVar15->pad + 1);
    *(undefined *)&prVar15->pad = *puVar18;
    *puVar18 = uVar1;
    puVar18 = puVar18 + -1;
    prVar15 = prVar19;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar4) != prVar19);
  prVar15 = (rsa_st *)((int)&in_a2->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar15;
  if ((int)unaff_s2 < 1) goto LAB_00573e60;
  do {
    unaff_s7 = prVar15;
    if (0 < (int)unaff_s2 - (int)in_a2) {
      unaff_s7 = (rsa_st *)((int)prVar15 + ((int)unaff_s2 - (int)in_a2));
      (*(code *)PTR_memset_006a99f4)(prVar15,0);
    }
LAB_00573e60:
    pBVar11 = unaff_s6->d;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar11);
    iVar14 = iVar12 + 7;
    unaff_s2 = (undefined *)(uint)(iVar14 < 0);
    iVar4 = iVar12 + 0xe;
    if (unaff_s2 == (undefined *)0x0) {
      iVar4 = iVar14;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar11,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar4 >> 3);
    if (unaff_s2 != (undefined *)0x0) {
      iVar14 = iVar12 + 0x16;
    }
    in_a2 = (rsa_st *)(iVar14 >> 4);
    if (0 < (int)in_a2) {
      in_a2 = (rsa_st *)((int)&in_a2->pad + (int)&unaff_s7->pad);
      puVar18 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar15 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar15->pad;
        prVar19 = (rsa_st *)((int)&prVar15->pad + 1);
        *(undefined *)&prVar15->pad = *puVar18;
        *puVar18 = uVar1;
        puVar18 = puVar18 + -1;
        prVar15 = prVar19;
      } while (in_a2 != prVar19);
    }
    prVar15 = unaff_s0;
    if ((0 < (int)pk) && (in_a2 = (rsa_st *)((int)pk - (int)unaff_s6), 0 < (int)in_a2)) {
      (*(code *)PTR_memset_006a99f4)((undefined *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00573f14:
    unaff_s0 = prVar15;
    unaff_s1 = prVar3;
    if ((int)prVar3 < 0) {
LAB_00573fe8:
      prVar3 = (rsa_st *)0xffffffff;
    }
    else {
      in_a2 = prVar3;
      unaff_s0 = (rsa_st *)(*(code *)PTR_BIO_write_006a6e14)(out,prVar15);
      (*(code *)PTR_CRYPTO_free_006a6e88)(prVar15);
      if (unaff_s0 != prVar3) goto LAB_00573fe8;
    }
LAB_00573f4c:
    if (local_2c == *(int *)puVar2) {
      return (int)prVar3;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    prVar3 = unaff_s1;
LAB_00574578:
    prVar15 = (rsa_st *)((int)&in_a2->pad + (int)&unaff_s7->pad);
  } while( true );
}

