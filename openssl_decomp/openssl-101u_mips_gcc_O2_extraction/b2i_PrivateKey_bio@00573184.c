
EVP_PKEY * b2i_PrivateKey_bio(BIO *in)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  BN_MONT_CTX *pBVar4;
  rsa_st *prVar5;
  uint uVar6;
  rsa_st *prVar7;
  int iVar8;
  BIGNUM **ppBVar9;
  undefined *puVar10;
  undefined *puVar11;
  BIGNUM **ppBVar12;
  BIGNUM *pBVar13;
  undefined4 uVar14;
  rsa_st *prVar15;
  ENGINE *pEVar16;
  BIGNUM *pBVar17;
  int iVar18;
  int iVar19;
  rsa_st *prVar20;
  BIGNUM *unaff_s3;
  rsa_st *prVar21;
  rsa_st *prVar22;
  BN_MONT_CTX *unaff_s4;
  rsa_st *unaff_s5;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar23;
  undefined *puVar24;
  undefined *puVar25;
  code *pcVar26;
  int iStack_e0;
  int iStack_dc;
  rsa_st *prStack_d8;
  ENGINE *pEStack_d4;
  rsa_st *prStack_d0;
  BIGNUM *pBStack_cc;
  BN_MONT_CTX *pBStack_c8;
  rsa_st *prStack_c4;
  rsa_st *prStack_c0;
  rsa_st *prStack_90;
  char cStack_8c;
  char cStack_8b;
  RSA_METHOD *pRStack_84;
  ENGINE *pEStack_80;
  undefined auStack_7c [68];
  BN_MONT_CTX *local_38;
  char local_34;
  char local_33;
  BN_BLINDING *local_2c;
  BN_BLINDING *local_28;
  BIGNUM *local_24;
  
  auStack_7c._8_4_ = (RSA_METHOD *)PTR___stack_chk_guard_006a9ae8;
  auStack_7c._4_4_ = (BN_MONT_CTX *)(auStack_7c + 0x48);
  auStack_7c._60_4_ = &_gp;
  local_24 = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_BIO_read_006a74c0)(in,auStack_7c._4_4_,0x10);
  if (iVar3 == 0x10) {
    local_38 = auStack_7c._4_4_;
    if (local_34 == '\x06') {
      pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eac);
      uVar14 = 0x77;
      auStack_7c._52_4_ = (BN_MONT_CTX *)0x9d;
LAB_0057338c:
      (*pcVar26)(9,0x86,uVar14,FUN_0066c47c);
      goto LAB_00573204;
    }
    if (local_34 != '\a') goto LAB_00573204;
    if (local_33 != '\x02') {
      pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eac);
      uVar14 = 0x75;
      auStack_7c._52_4_ = (BN_MONT_CTX *)&DAT_000000ac;
      goto LAB_0057338c;
    }
    uVar6 = ((((uint)local_2c >> 0x10) << 0x18 | ((uint)local_2c >> 0x18) << 0x10) >> 0x10) +
            (((uint)local_2c & 0xff) << 8 | (uint)local_2c >> 8 & 0xff) * 0x10000;
    unaff_s5 = (rsa_st *)
               (((((uint)local_28 >> 0x10) << 0x18 | ((uint)local_28 >> 0x18) << 0x10) >> 0x10) +
               (((uint)local_28 & 0xff) << 8 | (uint)local_28 >> 8 & 0xff) * 0x10000);
    if (uVar6 == 0x31535344) {
LAB_00573378:
      pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eac);
      uVar14 = 0x77;
      auStack_7c._52_4_ = (BN_MONT_CTX *)0xba;
      goto LAB_0057338c;
    }
    if (uVar6 < 0x31535345) {
      if (uVar6 != 0x31415352) {
LAB_00573470:
        pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eac);
        uVar14 = 0x74;
        auStack_7c._52_4_ = (BN_MONT_CTX *)0xc9;
        goto LAB_0057338c;
      }
      goto LAB_00573378;
    }
    if (uVar6 == 0x32415352) {
      unaff_s3 = (BIGNUM *)0x0;
      auStack_7c._4_4_ =
           (BN_MONT_CTX *)
           ((((uint)((int)&unaff_s5->version + 3U) >> 3) + 2) * 2 +
           ((uint)((int)&unaff_s5->engine + 3) >> 4) * 5);
    }
    else {
      unaff_s3 = (BIGNUM *)0x1;
      if (uVar6 != 0x32535344) goto LAB_00573470;
      auStack_7c._4_4_ = (BN_MONT_CTX *)((((uint)((int)&unaff_s5->version + 3) >> 3) + 0x20) * 2);
    }
    local_38 = (BN_MONT_CTX *)&local_24;
    unaff_s6 = (rsa_st *)0x670000;
    if ((BN_MONT_CTX *)0x19000 < auStack_7c._4_4_) {
      pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eac);
      uVar14 = 0x80;
      auStack_7c._52_4_ = (BN_MONT_CTX *)0x117;
      goto LAB_00573350;
    }
    unaff_s4 = (BN_MONT_CTX *)
               (**(code **)(auStack_7c._60_4_ + -0x7dd8))(auStack_7c._4_4_,FUN_0066c47c,0x11a);
    if (unaff_s4 == (BN_MONT_CTX *)0x0) {
      auStack_7c._52_4_ = (BN_MONT_CTX *)0x11c;
      (**(code **)(auStack_7c._60_4_ + -0x6eac))(9,0x85,0x41,FUN_0066c47c);
      pBVar4 = (BN_MONT_CTX *)0x0;
    }
    else {
      local_38 = unaff_s4;
      pBVar4 = (BN_MONT_CTX *)
               (**(code **)(auStack_7c._60_4_ + -0x7920))(in,unaff_s4,auStack_7c._4_4_);
      if (auStack_7c._4_4_ == pBVar4) {
        if (unaff_s3 == (BIGNUM *)0x0) {
          pBVar4 = (BN_MONT_CTX *)b2i_rsa_isra_1(auStack_7c + 0x44,unaff_s5,0);
        }
        else {
          pBVar4 = (BN_MONT_CTX *)b2i_dss_isra_0();
        }
      }
      else {
        auStack_7c._52_4_ = (BN_MONT_CTX *)0x121;
        pBVar4 = (BN_MONT_CTX *)0x0;
        (**(code **)(auStack_7c._60_4_ + -0x6eac))(9,0x85,0x7b,FUN_0066c47c);
      }
      (**(code **)(auStack_7c._60_4_ + -0x7f58))(unaff_s4);
      auStack_7c._4_4_ = pBVar4;
    }
  }
  else {
    pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eac);
    uVar14 = 0x7b;
    auStack_7c._52_4_ = (BN_MONT_CTX *)0x10e;
LAB_00573350:
    (*pcVar26)(9,0x85,uVar14,FUN_0066c47c);
LAB_00573204:
    pBVar4 = (BN_MONT_CTX *)0x0;
  }
  if (local_24 == *(BIGNUM **)auStack_7c._8_4_) {
    return (EVP_PKEY *)pBVar4;
  }
  auStack_7c._32_4_ = b2i_PublicKey_bio;
  pBStack_cc = local_24;
  (**(code **)(auStack_7c._60_4_ + -0x5330))();
  prVar22 = (rsa_st *)PTR___stack_chk_guard_006a9ae8;
  prVar15 = (rsa_st *)&SUB_00000010;
  prVar7 = (rsa_st *)&cStack_8c;
  auStack_7c._0_4_ = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  prVar21 = prVar7;
  auStack_7c._12_4_ = in;
  auStack_7c._16_4_ = unaff_s3;
  auStack_7c._20_4_ = unaff_s4;
  auStack_7c._24_4_ = unaff_s5;
  auStack_7c._28_4_ = unaff_s6;
  iVar3 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar3 == 0x10) {
    prStack_90 = prVar7;
    if (cStack_8c != '\x06') {
      if (cStack_8c == '\a') {
        prVar15 = (rsa_st *)&DAT_00000078;
        goto LAB_005735cc;
      }
      goto LAB_00573528;
    }
    if (cStack_8b != '\x02') {
      prVar15 = (rsa_st *)0x75;
LAB_005735cc:
      prVar21 = (rsa_st *)0x86;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,prVar15,FUN_0066c47c);
      goto LAB_00573528;
    }
    uVar6 = ((((uint)pRStack_84 >> 0x10) << 0x18 | ((uint)pRStack_84 >> 0x18) << 0x10) >> 0x10) +
            (((uint)pRStack_84 & 0xff) << 8 | (uint)pRStack_84 >> 8 & 0xff) * 0x10000;
    in = (BIO *)(((((uint)pEStack_80 >> 0x10) << 0x18 | ((uint)pEStack_80 >> 0x18) << 0x10) >> 0x10)
                + (((uint)pEStack_80 & 0xff) << 8 | (uint)pEStack_80 >> 8 & 0xff) * 0x10000);
    if (uVar6 != 0x31535344) {
      if (uVar6 < 0x31535345) {
        unaff_s4 = (BN_MONT_CTX *)0x0;
        if (uVar6 == 0x31415352) {
          prVar7 = (rsa_st *)(((uint)((int)&((rsa_st *)in)->version + 3) >> 3) + 4);
          goto LAB_00573630;
        }
      }
      else if ((uVar6 == 0x32415352) || (uVar6 == 0x32535344)) {
        prVar15 = (rsa_st *)&DAT_00000078;
        goto LAB_005735cc;
      }
      prVar15 = (rsa_st *)&DAT_00000074;
      goto LAB_005735cc;
    }
    unaff_s4 = (BN_MONT_CTX *)0x1;
    prVar7 = (rsa_st *)(((uint)((int)&((rsa_st *)in)->version + 3) >> 3) * 3 + 0x2c);
LAB_00573630:
    prStack_90 = (rsa_st *)auStack_7c;
    unaff_s6 = (rsa_st *)0x670000;
    if ((rsa_st *)0x19000 < prVar7) {
      prVar15 = (rsa_st *)&DAT_00000080;
      goto LAB_005735f8;
    }
    unaff_s5 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar7,FUN_0066c47c,0x11a);
    if (unaff_s5 == (rsa_st *)0x0) {
      prVar15 = (rsa_st *)&DAT_00000041;
      prVar21 = (rsa_st *)0x85;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,0x41,FUN_0066c47c);
      prVar5 = (rsa_st *)0x0;
    }
    else {
      prStack_90 = unaff_s5;
      prVar21 = (rsa_st *)(*(code *)PTR_BIO_read_006a74c0)(pBStack_cc,unaff_s5,prVar7);
      if (prVar7 == prVar21) {
        prVar15 = (rsa_st *)0x1;
        prVar21 = (rsa_st *)in;
        if (unaff_s4 == (BN_MONT_CTX *)0x0) {
          prVar5 = (rsa_st *)b2i_rsa_isra_1(&prStack_90);
        }
        else {
          prVar5 = (rsa_st *)b2i_dss_isra_0();
        }
      }
      else {
        prVar15 = (rsa_st *)0x7b;
        prVar21 = (rsa_st *)0x85;
        prVar5 = (rsa_st *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,0x7b,FUN_0066c47c);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s5);
      prVar7 = prVar5;
    }
  }
  else {
    prVar15 = (rsa_st *)0x7b;
LAB_005735f8:
    prVar21 = (rsa_st *)0x85;
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,prVar15,FUN_0066c47c);
LAB_00573528:
    prVar5 = (rsa_st *)0x0;
  }
  if (auStack_7c._0_4_ == *(BIGNUM **)prVar22) {
    return (EVP_PKEY *)prVar5;
  }
  pBVar13 = auStack_7c._0_4_;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pEStack_d4 = (ENGINE *)prVar22;
  iStack_e0 = 0;
  iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
  prStack_d8 = prVar7;
  prStack_d0 = (rsa_st *)in;
  pBStack_c8 = unaff_s4;
  prStack_c4 = unaff_s5;
  prStack_c0 = unaff_s6;
  if (prVar21->pad == 0x74) {
    prVar7 = ((_union_271 *)&prVar21->e)->rsa;
    in = (BIO *)(*(code *)PTR_BN_num_bits_006a71f4)((EVP_PKEY_ASN1_METHOD *)prVar7->engine);
    if ((((((uint)in & 7) != 0) ||
         (iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar7->n), iVar3 != 0xa0)) ||
        (iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(((_union_271 *)&prVar7->e)->ptr),
        (int)in < iVar3)) || (iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar7->p), 0xa0 < iVar3))
    {
      prVar15 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x82,0x7e,FUN_0066c47c,0x222);
      goto LAB_00573fe8;
    }
    iStack_e0 = 0x32535344;
    if ((rsa_st *)in == (rsa_st *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar3 = (((uint)((int)&((rsa_st *)in)->version + 3) >> 3) + 0x20) * 2;
  }
  else {
    prVar5 = (rsa_st *)0xffffffff;
    if (prVar21->pad != 6) goto LAB_00573f4c;
    prVar15 = (rsa_st *)&iStack_e0;
    in = (BIO *)check_bitlen_rsa(((_union_271 *)&prVar21->e)->ptr,0);
    if ((rsa_st *)in == (rsa_st *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar3 = (((uint)((int)&((rsa_st *)in)->version + 3) >> 3) + 2) * 2 +
            ((uint)((int)&((rsa_st *)in)->engine + 3) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar5 = (rsa_st *)(iVar3 + 0x10);
  prVar15 = (rsa_st *)0x1e8;
  prVar7 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar5,FUN_0066c47c);
  prVar22 = prVar5;
  if (prVar7 == (rsa_st *)0x0) goto LAB_00573fe8;
  *(undefined *)((int)&prVar7->pad + 2) = 0;
  *(undefined *)((int)&prVar7->pad + 3) = 0;
  *(undefined *)&prVar7->version = 0;
  *(char *)((int)&prVar7->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&prVar7->version + 2) = 0;
  *(undefined *)&prVar7->pad = 7;
  ppBVar23 = &prVar7->n;
  *(undefined *)((int)&prVar7->version + 3) = 0;
  *(char *)&prVar7->engine = (char)in;
  *(undefined *)((int)&prVar7->pad + 1) = 2;
  *(char *)((int)&prVar7->engine + 1) = (char)((uint)in >> 8);
  *(char *)((int)&prVar7->engine + 2) = (char)((uint)in >> 0x10);
  *(char *)((int)&prVar7->engine + 3) = (char)((uint)in >> 0x18);
  *(char *)&prVar7->meth = (char)iStack_e0;
  *(char *)((int)&prVar7->meth + 1) = (char)((uint)iStack_e0 >> 8);
  *(char *)((int)&prVar7->meth + 2) = (char)((uint)iStack_e0 >> 0x10);
  *(char *)((int)&prVar7->meth + 3) = (char)((uint)iStack_e0 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar22 = ((_union_271 *)&prVar21->e)->rsa;
    iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar22->engine);
    pEVar16 = prVar22->engine;
    iVar3 = iVar8 + 7;
    if (iVar8 + 7 < 0) {
      iVar3 = iVar8 + 0xe;
    }
    iVar3 = iVar3 >> 3;
    iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(pEVar16);
    iVar19 = iVar18 + 7;
    iVar8 = iVar18 + 0xe;
    if (-1 < iVar19) {
      iVar8 = iVar19;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pEVar16,ppBVar23);
    iVar8 = iVar8 >> 3;
    iVar18 = iVar18 + 0x16;
    if (-1 < iVar19) {
      iVar18 = iVar19;
    }
    if (0 < iVar18 >> 4) {
      ppBVar12 = ppBVar23;
      puVar25 = (undefined *)((int)ppBVar23 + iVar8 + -1);
      do {
        uVar1 = *(undefined *)ppBVar12;
        ppBVar9 = (BIGNUM **)((int)ppBVar12 + 1);
        *(undefined *)ppBVar12 = *puVar25;
        *puVar25 = uVar1;
        ppBVar12 = ppBVar9;
        puVar25 = puVar25 + -1;
      } while ((BIGNUM **)((int)ppBVar23 + (iVar18 >> 4)) != ppBVar9);
    }
    puVar24 = (undefined *)((int)ppBVar23 + iVar8);
    puVar25 = puVar24;
    if ((0 < iVar3) && (0 < iVar3 - iVar8)) {
      puVar25 = puVar24 + (iVar3 - iVar8);
      (*(code *)PTR_memset_006a99f4)(puVar24,0);
    }
    pBVar17 = prVar22->n;
    iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar19 = iVar18 + 7;
    iVar8 = iVar18 + 0xe;
    if (-1 < iVar19) {
      iVar8 = iVar19;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
    iVar8 = iVar8 >> 3;
    iVar18 = iVar18 + 0x16;
    if (-1 < iVar19) {
      iVar18 = iVar19;
    }
    if (0 < iVar18 >> 4) {
      puVar24 = puVar25;
      puVar11 = puVar25 + iVar8 + -1;
      do {
        uVar1 = *puVar24;
        puVar10 = puVar24 + 1;
        *puVar24 = *puVar11;
        *puVar11 = uVar1;
        puVar24 = puVar10;
        puVar11 = puVar11 + -1;
      } while (puVar25 + (iVar18 >> 4) != puVar10);
    }
    puVar25 = puVar25 + iVar8;
    puVar24 = puVar25;
    if (0 < 0x14 - iVar8) {
      puVar24 = puVar25 + (0x14 - iVar8);
      (*(code *)PTR_memset_006a99f4)(puVar25,0);
    }
    pBVar17 = prVar22->e;
    iVar19 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar18 = iVar19 + 7;
    iVar8 = iVar19 + 0xe;
    if (-1 < iVar18) {
      iVar8 = iVar18;
    }
    iVar8 = iVar8 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar24);
    if (-1 >= iVar18) {
      iVar18 = iVar19 + 0x16;
    }
    if (0 < iVar18 >> 4) {
      puVar25 = puVar24;
      puVar11 = puVar24 + iVar8 + -1;
      do {
        uVar1 = *puVar25;
        puVar10 = puVar25 + 1;
        *puVar25 = *puVar11;
        *puVar11 = uVar1;
        puVar25 = puVar10;
        puVar11 = puVar11 + -1;
      } while (puVar10 != puVar24 + (iVar18 >> 4));
    }
    prVar21 = (rsa_st *)(puVar24 + iVar8);
    unaff_s7 = prVar21;
    if ((0 < iVar3) && (0 < iVar3 - iVar8)) {
      unaff_s7 = (rsa_st *)((int)prVar21 + (iVar3 - iVar8));
      (*(code *)PTR_memset_006a99f4)(prVar21,0);
    }
    pBVar17 = prVar22->p;
    iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    prVar22 = (rsa_st *)(iVar3 + 7);
    prVar21 = (rsa_st *)(iVar3 + 0xe);
    if (-1 < (int)prVar22) {
      prVar21 = prVar22;
    }
    unaff_s6 = (rsa_st *)(iVar3 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,unaff_s7);
    if (-1 >= (int)prVar22) {
      prVar22 = unaff_s6;
    }
    prVar21 = (rsa_st *)((int)prVar21 >> 3);
    if (0 < (int)prVar22 >> 4) {
      prVar15 = unaff_s7;
      puVar25 = (undefined *)((int)&prVar21[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar15->pad;
        prVar20 = (rsa_st *)((int)&prVar15->pad + 1);
        *(undefined *)&prVar15->pad = *puVar25;
        *puVar25 = uVar1;
        prVar15 = prVar20;
        puVar25 = puVar25 + -1;
      } while (prVar20 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar22 >> 4)));
    }
    prVar22 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
    in = (BIO *)prVar22;
    if (0 < 0x14 - (int)prVar21) {
      in = (BIO *)((int)prVar22 + (0x14 - (int)prVar21));
      (*(code *)PTR_memset_006a99f4)(prVar22,0);
    }
    prVar15 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006a99f4)(in,0xff);
    prVar20 = prVar7;
    goto LAB_00573f14;
  }
  unaff_s6 = ((_union_271 *)&prVar21->e)->rsa;
  iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  iVar3 = iVar8 + 7;
  if (iVar8 + 7 < 0) {
    iVar3 = iVar8 + 0xe;
  }
  prVar21 = (rsa_st *)(iVar3 >> 3);
  iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  pBVar17 = unaff_s6->e;
  in = (BIO *)(iVar3 + 0xf >> 4);
  iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
  iVar18 = iVar8 + 7;
  iVar3 = iVar8 + 0xe;
  if (-1 < iVar18) {
    iVar3 = iVar18;
  }
  iVar3 = iVar3 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,ppBVar23);
  iVar8 = iVar8 + 0x16;
  if (-1 < iVar18) {
    iVar8 = iVar18;
  }
  if (0 < iVar8 >> 4) {
    ppBVar12 = ppBVar23;
    puVar25 = (undefined *)((int)ppBVar23 + iVar3 + -1);
    do {
      uVar1 = *(undefined *)ppBVar12;
      ppBVar9 = (BIGNUM **)((int)ppBVar12 + 1);
      *(undefined *)ppBVar12 = *puVar25;
      *puVar25 = uVar1;
      ppBVar12 = ppBVar9;
      puVar25 = puVar25 + -1;
    } while ((BIGNUM **)((int)ppBVar23 + (iVar8 >> 4)) != ppBVar9);
  }
  puVar24 = (undefined *)((int)ppBVar23 + iVar3);
  puVar25 = puVar24;
  if (0 < 4 - iVar3) {
    puVar25 = puVar24 + (4 - iVar3);
    (*(code *)PTR_memset_006a99f4)(puVar24,0);
  }
  pBVar17 = unaff_s6->n;
  iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
  iVar8 = iVar18 + 7;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
  iVar3 = iVar8;
  if (iVar8 < 0) {
    iVar8 = iVar18 + 0x16;
    iVar3 = iVar18 + 0xe;
  }
  if (0 < iVar8 >> 4) {
    puVar24 = puVar25;
    puVar11 = puVar25 + (iVar3 >> 3) + -1;
    do {
      uVar1 = *puVar24;
      puVar10 = puVar24 + 1;
      *puVar24 = *puVar11;
      *puVar11 = uVar1;
      puVar24 = puVar10;
      puVar11 = puVar11 + -1;
    } while (puVar10 != puVar25 + (iVar8 >> 4));
  }
  pBVar17 = unaff_s6->p;
  puVar25 = puVar25 + (iVar3 >> 3);
  iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
  iVar18 = iVar8 + 7;
  iVar3 = iVar8 + 0xe;
  if (-1 < iVar18) {
    iVar3 = iVar18;
  }
  iVar3 = iVar3 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
  iVar8 = iVar8 + 0x16;
  if (-1 < iVar18) {
    iVar8 = iVar18;
  }
  if (0 < iVar8 >> 4) {
    puVar24 = puVar25;
    puVar11 = puVar25 + iVar3 + -1;
    do {
      uVar1 = *puVar24;
      puVar10 = puVar24 + 1;
      *puVar24 = *puVar11;
      *puVar11 = uVar1;
      puVar24 = puVar10;
      puVar11 = puVar11 + -1;
    } while (puVar25 + (iVar8 >> 4) != puVar10);
  }
  puVar25 = puVar25 + iVar3;
  if ((int)in < 1) {
    pBVar17 = unaff_s6->q;
    iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar18 = iVar8 + 7;
    iVar3 = iVar8 + 0xe;
    if (-1 < iVar18) {
      iVar3 = iVar18;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
    iVar8 = iVar8 + 0x16;
    if (-1 < iVar18) {
      iVar8 = iVar18;
    }
    iVar8 = iVar8 >> 4;
    puVar24 = puVar25 + iVar3 + -1;
    if (0 < iVar8) goto LAB_00573bc8;
    puVar25 = puVar25 + iVar3;
LAB_00574388:
    pBVar17 = unaff_s6->dmp1;
    iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar18 = iVar8 + 7;
    iVar3 = iVar8 + 0xe;
    if (-1 < iVar18) {
      iVar3 = iVar18;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
    iVar8 = iVar8 + 0x16;
    if (-1 < iVar18) {
      iVar8 = iVar18;
    }
    iVar8 = iVar8 >> 4;
    puVar24 = puVar25 + iVar3 + -1;
    if (0 < iVar8) goto LAB_00573c8c;
    puVar25 = puVar25 + iVar3;
LAB_00574400:
    pBVar17 = unaff_s6->dmq1;
    iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar3 = iVar18 + 7;
    iVar8 = iVar18 + 0xe;
    if (-1 < iVar3) {
      iVar8 = iVar3;
    }
    iVar8 = iVar8 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
    if (-1 >= iVar3) {
      iVar3 = iVar18 + 0x16;
    }
    iVar3 = iVar3 >> 4;
    puVar24 = puVar25 + iVar8 + -1;
    if (0 < iVar3) goto LAB_00573d50;
LAB_00573d74:
    unaff_s7 = (rsa_st *)(puVar25 + iVar8);
    if ((int)in < 1) {
      pBVar17 = unaff_s6->iqmp;
      iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
      iVar8 = iVar18 + 7;
      iVar3 = iVar18 + 0xe;
      if (-1 < iVar8) {
        iVar3 = iVar8;
      }
      prVar15 = (rsa_st *)(iVar3 >> 3);
      (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,unaff_s7);
      if (-1 >= iVar8) {
        iVar8 = iVar18 + 0x16;
      }
      iVar8 = iVar8 >> 4;
      puVar25 = (undefined *)((int)&prVar15[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar8 < 1) {
        unaff_s7 = (rsa_st *)((int)&prVar15->pad + (int)&unaff_s7->pad);
        goto LAB_00573e60;
      }
      goto LAB_00573e14;
    }
  }
  else {
    iVar3 = (int)in - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006a99f4)(puVar25,0,iVar3);
      puVar25 = puVar25 + iVar3;
    }
    pBVar17 = unaff_s6->q;
    iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar18 = iVar8 + 7;
    iVar3 = iVar8 + 0xe;
    if (-1 < iVar18) {
      iVar3 = iVar18;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
    iVar8 = iVar8 + 0x16;
    if (-1 < iVar18) {
      iVar8 = iVar18;
    }
    iVar8 = iVar8 >> 4;
    puVar24 = puVar25 + iVar3 + -1;
    if (iVar8 < 1) {
      puVar25 = puVar25 + iVar3;
    }
    else {
LAB_00573bc8:
      puVar11 = puVar25;
      do {
        uVar1 = *puVar11;
        puVar10 = puVar11 + 1;
        *puVar11 = *puVar24;
        *puVar24 = uVar1;
        puVar11 = puVar10;
        puVar24 = puVar24 + -1;
      } while (puVar25 + iVar8 != puVar10);
      puVar25 = puVar25 + iVar3;
      if ((int)in < 1) goto LAB_00574388;
    }
    iVar3 = (int)in - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006a99f4)(puVar25,0,iVar3);
      puVar25 = puVar25 + iVar3;
    }
    pBVar17 = unaff_s6->dmp1;
    iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar18 = iVar8 + 7;
    iVar3 = iVar8 + 0xe;
    if (-1 < iVar18) {
      iVar3 = iVar18;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
    iVar8 = iVar8 + 0x16;
    if (-1 < iVar18) {
      iVar8 = iVar18;
    }
    iVar8 = iVar8 >> 4;
    puVar24 = puVar25 + iVar3 + -1;
    if (iVar8 < 1) {
      puVar25 = puVar25 + iVar3;
    }
    else {
LAB_00573c8c:
      puVar11 = puVar25;
      do {
        uVar1 = *puVar11;
        puVar10 = puVar11 + 1;
        *puVar11 = *puVar24;
        *puVar24 = uVar1;
        puVar11 = puVar10;
        puVar24 = puVar24 + -1;
      } while (puVar25 + iVar8 != puVar10);
      puVar25 = puVar25 + iVar3;
      if ((int)in < 1) goto LAB_00574400;
    }
    iVar3 = (int)in - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006a99f4)(puVar25,0,iVar3);
      puVar25 = puVar25 + iVar3;
    }
    pBVar17 = unaff_s6->dmq1;
    iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar3 = iVar18 + 7;
    iVar8 = iVar18 + 0xe;
    if (-1 < iVar3) {
      iVar8 = iVar3;
    }
    iVar8 = iVar8 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,puVar25);
    if (-1 >= iVar3) {
      iVar3 = iVar18 + 0x16;
    }
    iVar3 = iVar3 >> 4;
    puVar24 = puVar25 + iVar8 + -1;
    if (0 < iVar3) {
LAB_00573d50:
      puVar11 = puVar25;
      do {
        uVar1 = *puVar11;
        puVar10 = puVar11 + 1;
        *puVar11 = *puVar24;
        *puVar24 = uVar1;
        puVar24 = puVar24 + -1;
        puVar11 = puVar10;
      } while (puVar25 + iVar3 != puVar10);
      goto LAB_00573d74;
    }
    unaff_s7 = (rsa_st *)(puVar25 + iVar8);
  }
  iVar8 = (int)in - iVar8;
  if (0 < iVar8) {
    (*(code *)PTR_memset_006a99f4)(unaff_s7,0,iVar8);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar8);
  }
  pBVar17 = unaff_s6->iqmp;
  iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
  iVar8 = iVar18 + 7;
  iVar3 = iVar18 + 0xe;
  if (-1 < iVar8) {
    iVar3 = iVar8;
  }
  prVar15 = (rsa_st *)(iVar3 >> 3);
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,unaff_s7);
  if (-1 >= iVar8) {
    iVar8 = iVar18 + 0x16;
  }
  iVar8 = iVar8 >> 4;
  puVar25 = (undefined *)((int)&prVar15[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar8 < 1) goto LAB_00574578;
LAB_00573e14:
  prVar22 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar22->pad;
    prVar20 = (rsa_st *)((int)&prVar22->pad + 1);
    *(undefined *)&prVar22->pad = *puVar25;
    *puVar25 = uVar1;
    puVar25 = puVar25 + -1;
    prVar22 = prVar20;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar8) != prVar20);
  prVar22 = (rsa_st *)((int)&prVar15->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar22;
  if ((int)in < 1) goto LAB_00573e60;
  do {
    unaff_s7 = prVar22;
    if (0 < (int)in - (int)prVar15) {
      unaff_s7 = (rsa_st *)((int)prVar22 + ((int)in - (int)prVar15));
      (*(code *)PTR_memset_006a99f4)(prVar22,0);
    }
LAB_00573e60:
    pBVar17 = unaff_s6->d;
    iVar18 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar17);
    iVar3 = iVar18 + 7;
    in = (BIO *)(uint)(iVar3 < 0);
    iVar8 = iVar18 + 0xe;
    if ((rsa_st *)in == (rsa_st *)0x0) {
      iVar8 = iVar3;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar17,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar8 >> 3);
    if ((rsa_st *)in != (rsa_st *)0x0) {
      iVar3 = iVar18 + 0x16;
    }
    prVar15 = (rsa_st *)(iVar3 >> 4);
    if (0 < (int)prVar15) {
      prVar15 = (rsa_st *)((int)&prVar15->pad + (int)&unaff_s7->pad);
      puVar25 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar22 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar22->pad;
        prVar20 = (rsa_st *)((int)&prVar22->pad + 1);
        *(undefined *)&prVar22->pad = *puVar25;
        *puVar25 = uVar1;
        puVar25 = puVar25 + -1;
        prVar22 = prVar20;
      } while (prVar15 != prVar20);
    }
    prVar20 = prVar7;
    if ((0 < (int)prVar21) && (prVar15 = (rsa_st *)((int)prVar21 - (int)unaff_s6), 0 < (int)prVar15)
       ) {
      (*(code *)PTR_memset_006a99f4)((char *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00573f14:
    prVar7 = prVar20;
    prVar22 = prVar5;
    if ((int)prVar5 < 0) {
LAB_00573fe8:
      prVar5 = (rsa_st *)0xffffffff;
    }
    else {
      prVar15 = prVar5;
      prVar7 = (rsa_st *)(*(code *)PTR_BIO_write_006a6e14)(pBVar13,prVar20);
      (*(code *)PTR_CRYPTO_free_006a6e88)(prVar20);
      if (prVar7 != prVar5) goto LAB_00573fe8;
    }
LAB_00573f4c:
    if (iStack_dc == *(int *)puVar2) {
      return (EVP_PKEY *)prVar5;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    prVar5 = prVar22;
LAB_00574578:
    prVar22 = (rsa_st *)((int)&prVar15->pad + (int)&unaff_s7->pad);
  } while( true );
}

