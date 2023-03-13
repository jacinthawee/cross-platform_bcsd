
EVP_PKEY * b2i_PublicKey(uchar **in,long length)

{
  undefined uVar1;
  undefined *puVar2;
  uchar *puVar3;
  EVP_PKEY *pEVar4;
  int iVar5;
  BN_MONT_CTX *pBVar6;
  rsa_st *prVar7;
  uint uVar8;
  rsa_st *prVar9;
  rsa_st *prVar10;
  int iVar11;
  BIGNUM **ppBVar12;
  undefined *puVar13;
  undefined *puVar14;
  BIGNUM **ppBVar15;
  BIGNUM *pBVar16;
  undefined4 uVar17;
  rsa_st *prVar18;
  ENGINE *pEVar19;
  uint uVar20;
  BIGNUM *pBVar21;
  int iVar22;
  int iVar23;
  rsa_st *prVar24;
  char *unaff_s1;
  BIGNUM *unaff_s3;
  rsa_st *prVar25;
  BN_MONT_CTX *unaff_s4;
  rsa_st *unaff_s5;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar26;
  undefined *puVar27;
  undefined *puVar28;
  rsa_st *prVar29;
  code *pcVar30;
  int iStack_118;
  int iStack_114;
  rsa_st *prStack_110;
  ENGINE *pEStack_10c;
  rsa_st *prStack_108;
  BIGNUM *pBStack_104;
  BN_MONT_CTX *pBStack_100;
  rsa_st *prStack_fc;
  rsa_st *prStack_f8;
  rsa_st *prStack_c8;
  char cStack_c4;
  char cStack_c3;
  RSA_METHOD *pRStack_bc;
  ENGINE *pEStack_b8;
  undefined auStack_b4 [68];
  BN_MONT_CTX *pBStack_70;
  char cStack_6c;
  char cStack_6b;
  BN_BLINDING *pBStack_64;
  BN_BLINDING *pBStack_60;
  BIGNUM *pBStack_5c;
  undefined *puStack_58;
  char *pcStack_54;
  uchar *local_18;
  rsa_st *local_14;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  puVar3 = *in;
  local_14 = *(rsa_st **)PTR___stack_chk_guard_006a9ae8;
  local_18 = puVar3;
  if ((uint)length < 0x10) {
LAB_00572f80:
    unaff_s1 = "encrypt";
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7a,FUN_0066c47c);
    pEVar4 = (EVP_PKEY *)0x0;
  }
  else {
    if (*puVar3 != '\x06') {
      if (*puVar3 == '\a') {
        uVar17 = 0x78;
        goto LAB_00573088;
      }
      goto LAB_00572f80;
    }
    if (puVar3[1] != '\x02') {
      uVar17 = 0x75;
LAB_00573088:
      local_18 = puVar3;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,uVar17,FUN_0066c47c);
      goto LAB_00572f80;
    }
    local_18 = puVar3 + 0x10;
    uVar8 = (uint)puVar3[9] << 8 | (uint)puVar3[10] << 0x10 | (uint)puVar3[8] |
            (uint)puVar3[0xb] << 0x18;
    uVar20 = (uint)puVar3[0xd] << 8 | (uint)puVar3[0xe] << 0x10 | (uint)puVar3[0xc] |
             (uint)puVar3[0xf] << 0x18;
    if (uVar8 != 0x31535344) {
      if (uVar8 < 0x31535345) {
        if (uVar8 == 0x31415352) {
          if (length - 0x10U < (uVar20 + 7 >> 3) + 4) goto LAB_00573148;
          pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1(&local_18,uVar20,1);
          goto LAB_00572fa8;
        }
      }
      else if ((uVar8 == 0x32415352) || (uVar8 == 0x32535344)) {
        uVar17 = 0x78;
        goto LAB_00573088;
      }
      uVar17 = 0x74;
      goto LAB_00573088;
    }
    if (length - 0x10U < (uVar20 + 7 >> 3) * 3 + 0x2c) {
LAB_00573148:
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7b,FUN_0066c47c);
      pEVar4 = (EVP_PKEY *)0x0;
    }
    else {
      pEVar4 = (EVP_PKEY *)b2i_dss_isra_0(&local_18,uVar20,1);
    }
  }
LAB_00572fa8:
  if (local_14 == *(rsa_st **)puStack_58) {
    return pEVar4;
  }
  prVar9 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  auStack_b4._8_4_ = (RSA_METHOD *)PTR___stack_chk_guard_006a9ae8;
  auStack_b4._4_4_ = (BN_MONT_CTX *)(auStack_b4 + 0x48);
  auStack_b4._60_4_ = &_gp;
  pBStack_5c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pcStack_54 = unaff_s1;
  iVar5 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar5 == 0x10) {
    pBStack_70 = auStack_b4._4_4_;
    if (cStack_6c == '\x06') {
      pcVar30 = *(code **)(auStack_b4._60_4_ + -0x6eac);
      uVar17 = 0x77;
      auStack_b4._52_4_ = (BN_MONT_CTX *)0x9d;
LAB_0057338c:
      (*pcVar30)(9,0x86,uVar17,FUN_0066c47c);
      goto LAB_00573204;
    }
    if (cStack_6c != '\a') goto LAB_00573204;
    if (cStack_6b != '\x02') {
      pcVar30 = *(code **)(auStack_b4._60_4_ + -0x6eac);
      uVar17 = 0x75;
      auStack_b4._52_4_ = (BN_MONT_CTX *)&DAT_000000ac;
      goto LAB_0057338c;
    }
    uVar8 = ((((uint)pBStack_64 >> 0x10) << 0x18 | ((uint)pBStack_64 >> 0x18) << 0x10) >> 0x10) +
            (((uint)pBStack_64 & 0xff) << 8 | (uint)pBStack_64 >> 8 & 0xff) * 0x10000;
    unaff_s5 = (rsa_st *)
               (((((uint)pBStack_60 >> 0x10) << 0x18 | ((uint)pBStack_60 >> 0x18) << 0x10) >> 0x10)
               + (((uint)pBStack_60 & 0xff) << 8 | (uint)pBStack_60 >> 8 & 0xff) * 0x10000);
    if (uVar8 == 0x31535344) {
LAB_00573378:
      pcVar30 = *(code **)(auStack_b4._60_4_ + -0x6eac);
      uVar17 = 0x77;
      auStack_b4._52_4_ = (BN_MONT_CTX *)0xba;
      goto LAB_0057338c;
    }
    if (uVar8 < 0x31535345) {
      if (uVar8 != 0x31415352) {
LAB_00573470:
        pcVar30 = *(code **)(auStack_b4._60_4_ + -0x6eac);
        uVar17 = 0x74;
        auStack_b4._52_4_ = (BN_MONT_CTX *)0xc9;
        goto LAB_0057338c;
      }
      goto LAB_00573378;
    }
    if (uVar8 == 0x32415352) {
      unaff_s3 = (BIGNUM *)0x0;
      auStack_b4._4_4_ =
           (BN_MONT_CTX *)
           ((((uint)((int)&unaff_s5->version + 3U) >> 3) + 2) * 2 +
           ((uint)((int)&unaff_s5->engine + 3) >> 4) * 5);
    }
    else {
      unaff_s3 = (BIGNUM *)0x1;
      if (uVar8 != 0x32535344) goto LAB_00573470;
      auStack_b4._4_4_ = (BN_MONT_CTX *)((((uint)((int)&unaff_s5->version + 3) >> 3) + 0x20) * 2);
    }
    pBStack_70 = (BN_MONT_CTX *)&pBStack_5c;
    unaff_s6 = (rsa_st *)0x670000;
    if ((BN_MONT_CTX *)0x19000 < auStack_b4._4_4_) {
      pcVar30 = *(code **)(auStack_b4._60_4_ + -0x6eac);
      uVar17 = 0x80;
      auStack_b4._52_4_ = (BN_MONT_CTX *)0x117;
      goto LAB_00573350;
    }
    unaff_s4 = (BN_MONT_CTX *)
               (**(code **)(auStack_b4._60_4_ + -0x7dd8))(auStack_b4._4_4_,FUN_0066c47c,0x11a);
    if (unaff_s4 == (BN_MONT_CTX *)0x0) {
      auStack_b4._52_4_ = (BN_MONT_CTX *)0x11c;
      (**(code **)(auStack_b4._60_4_ + -0x6eac))(9,0x85,0x41,FUN_0066c47c);
      pBVar6 = (BN_MONT_CTX *)0x0;
    }
    else {
      pBStack_70 = unaff_s4;
      pBVar6 = (BN_MONT_CTX *)
               (**(code **)(auStack_b4._60_4_ + -0x7920))(prVar9,unaff_s4,auStack_b4._4_4_);
      if (auStack_b4._4_4_ == pBVar6) {
        if (unaff_s3 == (BIGNUM *)0x0) {
          pBVar6 = (BN_MONT_CTX *)b2i_rsa_isra_1(auStack_b4 + 0x44,unaff_s5,0);
        }
        else {
          pBVar6 = (BN_MONT_CTX *)b2i_dss_isra_0();
        }
      }
      else {
        auStack_b4._52_4_ = (BN_MONT_CTX *)0x121;
        pBVar6 = (BN_MONT_CTX *)0x0;
        (**(code **)(auStack_b4._60_4_ + -0x6eac))(9,0x85,0x7b,FUN_0066c47c);
      }
      (**(code **)(auStack_b4._60_4_ + -0x7f58))(unaff_s4);
      auStack_b4._4_4_ = pBVar6;
    }
  }
  else {
    pcVar30 = *(code **)(auStack_b4._60_4_ + -0x6eac);
    uVar17 = 0x7b;
    auStack_b4._52_4_ = (BN_MONT_CTX *)0x10e;
LAB_00573350:
    (*pcVar30)(9,0x85,uVar17,FUN_0066c47c);
LAB_00573204:
    pBVar6 = (BN_MONT_CTX *)0x0;
  }
  if (pBStack_5c == *(BIGNUM **)auStack_b4._8_4_) {
    return (EVP_PKEY *)pBVar6;
  }
  auStack_b4._32_4_ = b2i_PublicKey_bio;
  pBStack_104 = pBStack_5c;
  (**(code **)(auStack_b4._60_4_ + -0x5330))();
  prVar29 = (rsa_st *)PTR___stack_chk_guard_006a9ae8;
  prVar18 = (rsa_st *)&SUB_00000010;
  prVar10 = (rsa_st *)&cStack_c4;
  auStack_b4._0_4_ = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  prVar25 = prVar10;
  auStack_b4._12_4_ = prVar9;
  auStack_b4._16_4_ = unaff_s3;
  auStack_b4._20_4_ = unaff_s4;
  auStack_b4._24_4_ = unaff_s5;
  auStack_b4._28_4_ = unaff_s6;
  iVar5 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar5 == 0x10) {
    prStack_c8 = prVar10;
    if (cStack_c4 != '\x06') {
      if (cStack_c4 == '\a') {
        prVar18 = (rsa_st *)&DAT_00000078;
        goto LAB_005735cc;
      }
      goto LAB_00573528;
    }
    if (cStack_c3 != '\x02') {
      prVar18 = (rsa_st *)0x75;
LAB_005735cc:
      prVar25 = (rsa_st *)0x86;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,prVar18,FUN_0066c47c);
      goto LAB_00573528;
    }
    uVar8 = ((((uint)pRStack_bc >> 0x10) << 0x18 | ((uint)pRStack_bc >> 0x18) << 0x10) >> 0x10) +
            (((uint)pRStack_bc & 0xff) << 8 | (uint)pRStack_bc >> 8 & 0xff) * 0x10000;
    prVar9 = (rsa_st *)
             (((((uint)pEStack_b8 >> 0x10) << 0x18 | ((uint)pEStack_b8 >> 0x18) << 0x10) >> 0x10) +
             (((uint)pEStack_b8 & 0xff) << 8 | (uint)pEStack_b8 >> 8 & 0xff) * 0x10000);
    if (uVar8 != 0x31535344) {
      if (uVar8 < 0x31535345) {
        unaff_s4 = (BN_MONT_CTX *)0x0;
        if (uVar8 == 0x31415352) {
          prVar10 = (rsa_st *)(((uint)((int)&prVar9->version + 3) >> 3) + 4);
          goto LAB_00573630;
        }
      }
      else if ((uVar8 == 0x32415352) || (uVar8 == 0x32535344)) {
        prVar18 = (rsa_st *)&DAT_00000078;
        goto LAB_005735cc;
      }
      prVar18 = (rsa_st *)&DAT_00000074;
      goto LAB_005735cc;
    }
    unaff_s4 = (BN_MONT_CTX *)0x1;
    prVar10 = (rsa_st *)(((uint)((int)&prVar9->version + 3) >> 3) * 3 + 0x2c);
LAB_00573630:
    prStack_c8 = (rsa_st *)auStack_b4;
    unaff_s6 = (rsa_st *)0x670000;
    if ((rsa_st *)0x19000 < prVar10) {
      prVar18 = (rsa_st *)&DAT_00000080;
      goto LAB_005735f8;
    }
    unaff_s5 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar10,FUN_0066c47c,0x11a);
    if (unaff_s5 == (rsa_st *)0x0) {
      prVar18 = (rsa_st *)&DAT_00000041;
      prVar25 = (rsa_st *)0x85;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,0x41,FUN_0066c47c);
      prVar7 = (rsa_st *)0x0;
    }
    else {
      prStack_c8 = unaff_s5;
      prVar25 = (rsa_st *)(*(code *)PTR_BIO_read_006a74c0)(pBStack_104,unaff_s5,prVar10);
      if (prVar10 == prVar25) {
        prVar18 = (rsa_st *)0x1;
        prVar25 = prVar9;
        if (unaff_s4 == (BN_MONT_CTX *)0x0) {
          prVar7 = (rsa_st *)b2i_rsa_isra_1(&prStack_c8);
        }
        else {
          prVar7 = (rsa_st *)b2i_dss_isra_0();
        }
      }
      else {
        prVar18 = (rsa_st *)0x7b;
        prVar25 = (rsa_st *)0x85;
        prVar7 = (rsa_st *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,0x7b,FUN_0066c47c);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s5);
      prVar10 = prVar7;
    }
  }
  else {
    prVar18 = (rsa_st *)0x7b;
LAB_005735f8:
    prVar25 = (rsa_st *)0x85;
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,prVar18,FUN_0066c47c);
LAB_00573528:
    prVar7 = (rsa_st *)0x0;
  }
  if (auStack_b4._0_4_ == *(BIGNUM **)prVar29) {
    return (EVP_PKEY *)prVar7;
  }
  pBVar16 = auStack_b4._0_4_;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pEStack_10c = (ENGINE *)prVar29;
  iStack_118 = 0;
  iStack_114 = *(int *)PTR___stack_chk_guard_006a9ae8;
  prStack_110 = prVar10;
  prStack_108 = prVar9;
  pBStack_100 = unaff_s4;
  prStack_fc = unaff_s5;
  prStack_f8 = unaff_s6;
  if (prVar25->pad == 0x74) {
    prVar10 = ((_union_271 *)&prVar25->e)->rsa;
    prVar9 = (rsa_st *)(*(code *)PTR_BN_num_bits_006a71f4)((EVP_PKEY_ASN1_METHOD *)prVar10->engine);
    if ((((((uint)prVar9 & 7) != 0) ||
         (iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar10->n), iVar5 != 0xa0)) ||
        (iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(((_union_271 *)&prVar10->e)->ptr),
        (int)prVar9 < iVar5)) ||
       (iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar10->p), 0xa0 < iVar5)) {
      prVar18 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x82,0x7e,FUN_0066c47c,0x222);
      goto LAB_00573fe8;
    }
    iStack_118 = 0x32535344;
    if (prVar9 == (rsa_st *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar5 = (((uint)((int)&prVar9->version + 3) >> 3) + 0x20) * 2;
  }
  else {
    prVar7 = (rsa_st *)0xffffffff;
    if (prVar25->pad != 6) goto LAB_00573f4c;
    prVar18 = (rsa_st *)&iStack_118;
    prVar9 = (rsa_st *)check_bitlen_rsa(((_union_271 *)&prVar25->e)->ptr,0);
    if (prVar9 == (rsa_st *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar5 = (((uint)((int)&prVar9->version + 3) >> 3) + 2) * 2 +
            ((uint)((int)&prVar9->engine + 3) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar7 = (rsa_st *)(iVar5 + 0x10);
  prVar18 = (rsa_st *)0x1e8;
  prVar10 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar7,FUN_0066c47c);
  prVar29 = prVar7;
  if (prVar10 == (rsa_st *)0x0) goto LAB_00573fe8;
  *(undefined *)((int)&prVar10->pad + 2) = 0;
  *(undefined *)((int)&prVar10->pad + 3) = 0;
  *(undefined *)&prVar10->version = 0;
  *(char *)((int)&prVar10->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&prVar10->version + 2) = 0;
  *(undefined *)&prVar10->pad = 7;
  ppBVar26 = &prVar10->n;
  *(undefined *)((int)&prVar10->version + 3) = 0;
  *(char *)&prVar10->engine = (char)prVar9;
  *(undefined *)((int)&prVar10->pad + 1) = 2;
  *(char *)((int)&prVar10->engine + 1) = (char)((uint)prVar9 >> 8);
  *(char *)((int)&prVar10->engine + 2) = (char)((uint)prVar9 >> 0x10);
  *(char *)((int)&prVar10->engine + 3) = (char)((uint)prVar9 >> 0x18);
  *(char *)&prVar10->meth = (char)iStack_118;
  *(char *)((int)&prVar10->meth + 1) = (char)((uint)iStack_118 >> 8);
  *(char *)((int)&prVar10->meth + 2) = (char)((uint)iStack_118 >> 0x10);
  *(char *)((int)&prVar10->meth + 3) = (char)((uint)iStack_118 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar9 = ((_union_271 *)&prVar25->e)->rsa;
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar9->engine);
    pEVar19 = prVar9->engine;
    iVar5 = iVar11 + 7;
    if (iVar11 + 7 < 0) {
      iVar5 = iVar11 + 0xe;
    }
    iVar5 = iVar5 >> 3;
    iVar22 = (*(code *)PTR_BN_num_bits_006a71f4)(pEVar19);
    iVar23 = iVar22 + 7;
    iVar11 = iVar22 + 0xe;
    if (-1 < iVar23) {
      iVar11 = iVar23;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pEVar19,ppBVar26);
    iVar11 = iVar11 >> 3;
    iVar22 = iVar22 + 0x16;
    if (-1 < iVar23) {
      iVar22 = iVar23;
    }
    if (0 < iVar22 >> 4) {
      ppBVar15 = ppBVar26;
      puVar28 = (undefined *)((int)ppBVar26 + iVar11 + -1);
      do {
        uVar1 = *(undefined *)ppBVar15;
        ppBVar12 = (BIGNUM **)((int)ppBVar15 + 1);
        *(undefined *)ppBVar15 = *puVar28;
        *puVar28 = uVar1;
        ppBVar15 = ppBVar12;
        puVar28 = puVar28 + -1;
      } while ((BIGNUM **)((int)ppBVar26 + (iVar22 >> 4)) != ppBVar12);
    }
    puVar27 = (undefined *)((int)ppBVar26 + iVar11);
    puVar28 = puVar27;
    if ((0 < iVar5) && (0 < iVar5 - iVar11)) {
      puVar28 = puVar27 + (iVar5 - iVar11);
      (*(code *)PTR_memset_006a99f4)(puVar27,0);
    }
    pBVar21 = prVar9->n;
    iVar22 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar23 = iVar22 + 7;
    iVar11 = iVar22 + 0xe;
    if (-1 < iVar23) {
      iVar11 = iVar23;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
    iVar11 = iVar11 >> 3;
    iVar22 = iVar22 + 0x16;
    if (-1 < iVar23) {
      iVar22 = iVar23;
    }
    if (0 < iVar22 >> 4) {
      puVar27 = puVar28;
      puVar14 = puVar28 + iVar11 + -1;
      do {
        uVar1 = *puVar27;
        puVar13 = puVar27 + 1;
        *puVar27 = *puVar14;
        *puVar14 = uVar1;
        puVar27 = puVar13;
        puVar14 = puVar14 + -1;
      } while (puVar28 + (iVar22 >> 4) != puVar13);
    }
    puVar28 = puVar28 + iVar11;
    puVar27 = puVar28;
    if (0 < 0x14 - iVar11) {
      puVar27 = puVar28 + (0x14 - iVar11);
      (*(code *)PTR_memset_006a99f4)(puVar28,0);
    }
    pBVar21 = prVar9->e;
    iVar23 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar22 = iVar23 + 7;
    iVar11 = iVar23 + 0xe;
    if (-1 < iVar22) {
      iVar11 = iVar22;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar27);
    if (-1 >= iVar22) {
      iVar22 = iVar23 + 0x16;
    }
    if (0 < iVar22 >> 4) {
      puVar28 = puVar27;
      puVar14 = puVar27 + iVar11 + -1;
      do {
        uVar1 = *puVar28;
        puVar13 = puVar28 + 1;
        *puVar28 = *puVar14;
        *puVar14 = uVar1;
        puVar28 = puVar13;
        puVar14 = puVar14 + -1;
      } while (puVar13 != puVar27 + (iVar22 >> 4));
    }
    prVar29 = (rsa_st *)(puVar27 + iVar11);
    unaff_s7 = prVar29;
    if ((0 < iVar5) && (0 < iVar5 - iVar11)) {
      unaff_s7 = (rsa_st *)((int)prVar29 + (iVar5 - iVar11));
      (*(code *)PTR_memset_006a99f4)(prVar29,0);
    }
    pBVar21 = prVar9->p;
    iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    prVar9 = (rsa_st *)(iVar5 + 7);
    prVar25 = (rsa_st *)(iVar5 + 0xe);
    if (-1 < (int)prVar9) {
      prVar25 = prVar9;
    }
    unaff_s6 = (rsa_st *)(iVar5 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,unaff_s7);
    if (-1 >= (int)prVar9) {
      prVar9 = unaff_s6;
    }
    prVar25 = (rsa_st *)((int)prVar25 >> 3);
    if (0 < (int)prVar9 >> 4) {
      prVar29 = unaff_s7;
      puVar28 = (undefined *)((int)&prVar25[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar29->pad;
        prVar18 = (rsa_st *)((int)&prVar29->pad + 1);
        *(undefined *)&prVar29->pad = *puVar28;
        *puVar28 = uVar1;
        prVar29 = prVar18;
        puVar28 = puVar28 + -1;
      } while (prVar18 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar9 >> 4)));
    }
    prVar29 = (rsa_st *)((int)&prVar25->pad + (int)&unaff_s7->pad);
    prVar9 = prVar29;
    if (0 < 0x14 - (int)prVar25) {
      prVar9 = (rsa_st *)((int)prVar29 + (0x14 - (int)prVar25));
      (*(code *)PTR_memset_006a99f4)(prVar29,0);
    }
    prVar18 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006a99f4)(prVar9,0xff);
    prVar24 = prVar10;
    goto LAB_00573f14;
  }
  unaff_s6 = ((_union_271 *)&prVar25->e)->rsa;
  iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  iVar5 = iVar11 + 7;
  if (iVar11 + 7 < 0) {
    iVar5 = iVar11 + 0xe;
  }
  prVar25 = (rsa_st *)(iVar5 >> 3);
  iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  pBVar21 = unaff_s6->e;
  prVar9 = (rsa_st *)(iVar5 + 0xf >> 4);
  iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
  iVar22 = iVar11 + 7;
  iVar5 = iVar11 + 0xe;
  if (-1 < iVar22) {
    iVar5 = iVar22;
  }
  iVar5 = iVar5 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,ppBVar26);
  iVar11 = iVar11 + 0x16;
  if (-1 < iVar22) {
    iVar11 = iVar22;
  }
  if (0 < iVar11 >> 4) {
    ppBVar15 = ppBVar26;
    puVar28 = (undefined *)((int)ppBVar26 + iVar5 + -1);
    do {
      uVar1 = *(undefined *)ppBVar15;
      ppBVar12 = (BIGNUM **)((int)ppBVar15 + 1);
      *(undefined *)ppBVar15 = *puVar28;
      *puVar28 = uVar1;
      ppBVar15 = ppBVar12;
      puVar28 = puVar28 + -1;
    } while ((BIGNUM **)((int)ppBVar26 + (iVar11 >> 4)) != ppBVar12);
  }
  puVar27 = (undefined *)((int)ppBVar26 + iVar5);
  puVar28 = puVar27;
  if (0 < 4 - iVar5) {
    puVar28 = puVar27 + (4 - iVar5);
    (*(code *)PTR_memset_006a99f4)(puVar27,0);
  }
  pBVar21 = unaff_s6->n;
  iVar22 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
  iVar11 = iVar22 + 7;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
  iVar5 = iVar11;
  if (iVar11 < 0) {
    iVar11 = iVar22 + 0x16;
    iVar5 = iVar22 + 0xe;
  }
  if (0 < iVar11 >> 4) {
    puVar27 = puVar28;
    puVar14 = puVar28 + (iVar5 >> 3) + -1;
    do {
      uVar1 = *puVar27;
      puVar13 = puVar27 + 1;
      *puVar27 = *puVar14;
      *puVar14 = uVar1;
      puVar27 = puVar13;
      puVar14 = puVar14 + -1;
    } while (puVar13 != puVar28 + (iVar11 >> 4));
  }
  pBVar21 = unaff_s6->p;
  puVar28 = puVar28 + (iVar5 >> 3);
  iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
  iVar22 = iVar11 + 7;
  iVar5 = iVar11 + 0xe;
  if (-1 < iVar22) {
    iVar5 = iVar22;
  }
  iVar5 = iVar5 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
  iVar11 = iVar11 + 0x16;
  if (-1 < iVar22) {
    iVar11 = iVar22;
  }
  if (0 < iVar11 >> 4) {
    puVar27 = puVar28;
    puVar14 = puVar28 + iVar5 + -1;
    do {
      uVar1 = *puVar27;
      puVar13 = puVar27 + 1;
      *puVar27 = *puVar14;
      *puVar14 = uVar1;
      puVar27 = puVar13;
      puVar14 = puVar14 + -1;
    } while (puVar28 + (iVar11 >> 4) != puVar13);
  }
  puVar28 = puVar28 + iVar5;
  if ((int)prVar9 < 1) {
    pBVar21 = unaff_s6->q;
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar22 = iVar11 + 7;
    iVar5 = iVar11 + 0xe;
    if (-1 < iVar22) {
      iVar5 = iVar22;
    }
    iVar5 = iVar5 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar22) {
      iVar11 = iVar22;
    }
    iVar11 = iVar11 >> 4;
    puVar27 = puVar28 + iVar5 + -1;
    if (0 < iVar11) goto LAB_00573bc8;
    puVar28 = puVar28 + iVar5;
LAB_00574388:
    pBVar21 = unaff_s6->dmp1;
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar22 = iVar11 + 7;
    iVar5 = iVar11 + 0xe;
    if (-1 < iVar22) {
      iVar5 = iVar22;
    }
    iVar5 = iVar5 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar22) {
      iVar11 = iVar22;
    }
    iVar11 = iVar11 >> 4;
    puVar27 = puVar28 + iVar5 + -1;
    if (0 < iVar11) goto LAB_00573c8c;
    puVar28 = puVar28 + iVar5;
LAB_00574400:
    pBVar21 = unaff_s6->dmq1;
    iVar22 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar5 = iVar22 + 7;
    iVar11 = iVar22 + 0xe;
    if (-1 < iVar5) {
      iVar11 = iVar5;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
    if (-1 >= iVar5) {
      iVar5 = iVar22 + 0x16;
    }
    iVar5 = iVar5 >> 4;
    puVar27 = puVar28 + iVar11 + -1;
    if (0 < iVar5) goto LAB_00573d50;
LAB_00573d74:
    unaff_s7 = (rsa_st *)(puVar28 + iVar11);
    if ((int)prVar9 < 1) {
      pBVar21 = unaff_s6->iqmp;
      iVar22 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
      iVar11 = iVar22 + 7;
      iVar5 = iVar22 + 0xe;
      if (-1 < iVar11) {
        iVar5 = iVar11;
      }
      prVar18 = (rsa_st *)(iVar5 >> 3);
      (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,unaff_s7);
      if (-1 >= iVar11) {
        iVar11 = iVar22 + 0x16;
      }
      iVar11 = iVar11 >> 4;
      puVar28 = (undefined *)((int)&prVar18[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar11 < 1) {
        unaff_s7 = (rsa_st *)((int)&prVar18->pad + (int)&unaff_s7->pad);
        goto LAB_00573e60;
      }
      goto LAB_00573e14;
    }
  }
  else {
    iVar5 = (int)prVar9 - iVar5;
    if (0 < iVar5) {
      (*(code *)PTR_memset_006a99f4)(puVar28,0,iVar5);
      puVar28 = puVar28 + iVar5;
    }
    pBVar21 = unaff_s6->q;
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar22 = iVar11 + 7;
    iVar5 = iVar11 + 0xe;
    if (-1 < iVar22) {
      iVar5 = iVar22;
    }
    iVar5 = iVar5 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar22) {
      iVar11 = iVar22;
    }
    iVar11 = iVar11 >> 4;
    puVar27 = puVar28 + iVar5 + -1;
    if (iVar11 < 1) {
      puVar28 = puVar28 + iVar5;
    }
    else {
LAB_00573bc8:
      puVar14 = puVar28;
      do {
        uVar1 = *puVar14;
        puVar13 = puVar14 + 1;
        *puVar14 = *puVar27;
        *puVar27 = uVar1;
        puVar14 = puVar13;
        puVar27 = puVar27 + -1;
      } while (puVar28 + iVar11 != puVar13);
      puVar28 = puVar28 + iVar5;
      if ((int)prVar9 < 1) goto LAB_00574388;
    }
    iVar5 = (int)prVar9 - iVar5;
    if (0 < iVar5) {
      (*(code *)PTR_memset_006a99f4)(puVar28,0,iVar5);
      puVar28 = puVar28 + iVar5;
    }
    pBVar21 = unaff_s6->dmp1;
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar22 = iVar11 + 7;
    iVar5 = iVar11 + 0xe;
    if (-1 < iVar22) {
      iVar5 = iVar22;
    }
    iVar5 = iVar5 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar22) {
      iVar11 = iVar22;
    }
    iVar11 = iVar11 >> 4;
    puVar27 = puVar28 + iVar5 + -1;
    if (iVar11 < 1) {
      puVar28 = puVar28 + iVar5;
    }
    else {
LAB_00573c8c:
      puVar14 = puVar28;
      do {
        uVar1 = *puVar14;
        puVar13 = puVar14 + 1;
        *puVar14 = *puVar27;
        *puVar27 = uVar1;
        puVar14 = puVar13;
        puVar27 = puVar27 + -1;
      } while (puVar28 + iVar11 != puVar13);
      puVar28 = puVar28 + iVar5;
      if ((int)prVar9 < 1) goto LAB_00574400;
    }
    iVar5 = (int)prVar9 - iVar5;
    if (0 < iVar5) {
      (*(code *)PTR_memset_006a99f4)(puVar28,0,iVar5);
      puVar28 = puVar28 + iVar5;
    }
    pBVar21 = unaff_s6->dmq1;
    iVar22 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar5 = iVar22 + 7;
    iVar11 = iVar22 + 0xe;
    if (-1 < iVar5) {
      iVar11 = iVar5;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,puVar28);
    if (-1 >= iVar5) {
      iVar5 = iVar22 + 0x16;
    }
    iVar5 = iVar5 >> 4;
    puVar27 = puVar28 + iVar11 + -1;
    if (0 < iVar5) {
LAB_00573d50:
      puVar14 = puVar28;
      do {
        uVar1 = *puVar14;
        puVar13 = puVar14 + 1;
        *puVar14 = *puVar27;
        *puVar27 = uVar1;
        puVar27 = puVar27 + -1;
        puVar14 = puVar13;
      } while (puVar28 + iVar5 != puVar13);
      goto LAB_00573d74;
    }
    unaff_s7 = (rsa_st *)(puVar28 + iVar11);
  }
  iVar11 = (int)prVar9 - iVar11;
  if (0 < iVar11) {
    (*(code *)PTR_memset_006a99f4)(unaff_s7,0,iVar11);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar11);
  }
  pBVar21 = unaff_s6->iqmp;
  iVar22 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
  iVar11 = iVar22 + 7;
  iVar5 = iVar22 + 0xe;
  if (-1 < iVar11) {
    iVar5 = iVar11;
  }
  prVar18 = (rsa_st *)(iVar5 >> 3);
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,unaff_s7);
  if (-1 >= iVar11) {
    iVar11 = iVar22 + 0x16;
  }
  iVar11 = iVar11 >> 4;
  puVar28 = (undefined *)((int)&prVar18[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar11 < 1) goto LAB_00574578;
LAB_00573e14:
  prVar29 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar29->pad;
    prVar24 = (rsa_st *)((int)&prVar29->pad + 1);
    *(undefined *)&prVar29->pad = *puVar28;
    *puVar28 = uVar1;
    puVar28 = puVar28 + -1;
    prVar29 = prVar24;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar11) != prVar24);
  prVar29 = (rsa_st *)((int)&prVar18->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar29;
  if ((int)prVar9 < 1) goto LAB_00573e60;
  do {
    unaff_s7 = prVar29;
    if (0 < (int)prVar9 - (int)prVar18) {
      unaff_s7 = (rsa_st *)((int)prVar29 + ((int)prVar9 - (int)prVar18));
      (*(code *)PTR_memset_006a99f4)(prVar29,0);
    }
LAB_00573e60:
    pBVar21 = unaff_s6->d;
    iVar22 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar21);
    iVar5 = iVar22 + 7;
    prVar9 = (rsa_st *)(uint)(iVar5 < 0);
    iVar11 = iVar22 + 0xe;
    if (prVar9 == (rsa_st *)0x0) {
      iVar11 = iVar5;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar21,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar11 >> 3);
    if (prVar9 != (rsa_st *)0x0) {
      iVar5 = iVar22 + 0x16;
    }
    prVar18 = (rsa_st *)(iVar5 >> 4);
    if (0 < (int)prVar18) {
      prVar18 = (rsa_st *)((int)&prVar18->pad + (int)&unaff_s7->pad);
      puVar28 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar29 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar29->pad;
        prVar24 = (rsa_st *)((int)&prVar29->pad + 1);
        *(undefined *)&prVar29->pad = *puVar28;
        *puVar28 = uVar1;
        puVar28 = puVar28 + -1;
        prVar29 = prVar24;
      } while (prVar18 != prVar24);
    }
    prVar24 = prVar10;
    if ((0 < (int)prVar25) && (prVar18 = (rsa_st *)((int)prVar25 - (int)unaff_s6), 0 < (int)prVar18)
       ) {
      (*(code *)PTR_memset_006a99f4)((char *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00573f14:
    prVar10 = prVar24;
    prVar29 = prVar7;
    if ((int)prVar7 < 0) {
LAB_00573fe8:
      prVar7 = (rsa_st *)0xffffffff;
    }
    else {
      prVar18 = prVar7;
      prVar10 = (rsa_st *)(*(code *)PTR_BIO_write_006a6e14)(pBVar16,prVar24);
      (*(code *)PTR_CRYPTO_free_006a6e88)(prVar24);
      if (prVar10 != prVar7) goto LAB_00573fe8;
    }
LAB_00573f4c:
    if (iStack_114 == *(int *)puVar2) {
      return (EVP_PKEY *)prVar7;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    prVar7 = prVar29;
LAB_00574578:
    prVar29 = (rsa_st *)((int)&prVar18->pad + (int)&unaff_s7->pad);
  } while( true );
}

