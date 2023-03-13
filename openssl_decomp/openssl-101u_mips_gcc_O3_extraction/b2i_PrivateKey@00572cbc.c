
EVP_PKEY * b2i_PrivateKey(uchar **in,long length)

{
  undefined uVar1;
  undefined *puVar2;
  uchar *puVar3;
  EVP_PKEY *pEVar4;
  char *pcVar5;
  int iVar6;
  BN_MONT_CTX *pBVar7;
  rsa_st *prVar8;
  uint uVar9;
  rsa_st *prVar10;
  rsa_st *prVar11;
  int iVar12;
  BIGNUM **ppBVar13;
  undefined *puVar14;
  undefined *puVar15;
  BIGNUM **ppBVar16;
  char **ppcVar17;
  BIGNUM *pBVar18;
  uint uVar19;
  undefined4 uVar20;
  rsa_st *prVar21;
  ENGINE *pEVar22;
  uint uVar23;
  BIGNUM *pBVar24;
  int iVar25;
  int iVar26;
  rsa_st *prVar27;
  char *unaff_s1;
  BIGNUM *unaff_s3;
  rsa_st *prVar28;
  BN_MONT_CTX *unaff_s4;
  rsa_st *unaff_s5;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar29;
  undefined *puVar30;
  undefined *puVar31;
  rsa_st *prVar32;
  code *pcVar33;
  int iStack_150;
  int iStack_14c;
  rsa_st *prStack_148;
  ENGINE *pEStack_144;
  rsa_st *prStack_140;
  BIGNUM *pBStack_13c;
  BN_MONT_CTX *pBStack_138;
  rsa_st *prStack_134;
  rsa_st *prStack_130;
  rsa_st *prStack_100;
  char cStack_fc;
  char cStack_fb;
  RSA_METHOD *pRStack_f4;
  ENGINE *pEStack_f0;
  undefined auStack_ec [68];
  BN_MONT_CTX *pBStack_a8;
  char cStack_a4;
  char cStack_a3;
  BN_BLINDING *pBStack_9c;
  BN_BLINDING *pBStack_98;
  BIGNUM *pBStack_94;
  undefined *puStack_90;
  char *pcStack_8c;
  char *pcStack_50;
  rsa_st *prStack_4c;
  undefined *puStack_44;
  char *pcStack_40;
  code *pcStack_3c;
  undefined4 local_28;
  undefined *local_20;
  uchar *local_18;
  char **local_14;
  
  puStack_44 = PTR___stack_chk_guard_006a9ae8;
  puVar3 = *in;
  local_20 = &_gp;
  local_14 = *(char ***)PTR___stack_chk_guard_006a9ae8;
  local_18 = puVar3;
  if ((uint)length < 0x10) {
LAB_00572d10:
    unaff_s1 = "encrypt";
    uVar19 = 0x84;
    local_28 = 0xf8;
    (**(code **)(local_20 + -0x6eac))(9,0x84,0x7a,FUN_0066c47c);
    pEVar4 = (EVP_PKEY *)0x0;
  }
  else {
    if (*puVar3 == '\x06') {
      uVar20 = 0x77;
      local_28 = 0x9d;
LAB_00572e30:
      local_18 = puVar3;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,uVar20,FUN_0066c47c);
      goto LAB_00572d10;
    }
    if (*puVar3 != '\a') goto LAB_00572d10;
    if (puVar3[1] != '\x02') {
      uVar20 = 0x75;
      local_28 = 0xac;
      goto LAB_00572e30;
    }
    local_18 = puVar3 + 0x10;
    uVar9 = (uint)puVar3[9] << 8 | (uint)puVar3[10] << 0x10 | (uint)puVar3[8] |
            (uint)puVar3[0xb] << 0x18;
    uVar19 = (uint)puVar3[0xd] << 8 | (uint)puVar3[0xe] << 0x10 | (uint)puVar3[0xc] |
             (uint)puVar3[0xf] << 0x18;
    if (uVar9 == 0x31535344) {
LAB_00572ea4:
      uVar20 = 0x77;
      local_28 = 0xba;
      goto LAB_00572e30;
    }
    if (uVar9 < 0x31535345) {
      if (uVar9 != 0x31415352) {
LAB_00572ed4:
        uVar20 = 0x74;
        local_28 = 0xc9;
        goto LAB_00572e30;
      }
      goto LAB_00572ea4;
    }
    if (uVar9 == 0x32415352) {
      if (length - 0x10U < ((uVar19 + 7 >> 3) + 2) * 2 + (uVar19 + 0xf >> 4) * 5) {
LAB_00572eec:
        local_28 = 0xfd;
        uVar19 = 0x84;
        (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7b,FUN_0066c47c);
        pEVar4 = (EVP_PKEY *)0x0;
      }
      else {
        pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1(&local_18,uVar19,0);
      }
    }
    else {
      if (uVar9 != 0x32535344) goto LAB_00572ed4;
      if (length - 0x10U < ((uVar19 + 7 >> 3) + 0x20) * 2) goto LAB_00572eec;
      pEVar4 = (EVP_PKEY *)b2i_dss_isra_0(&local_18,uVar19,0);
    }
  }
  if (local_14 == *(char ***)puStack_44) {
    return pEVar4;
  }
  pcStack_3c = b2i_PublicKey;
  ppcVar17 = local_14;
  (**(code **)(local_20 + -0x5330))();
  puStack_90 = PTR___stack_chk_guard_006a9ae8;
  pcVar5 = *ppcVar17;
  prStack_4c = *(rsa_st **)PTR___stack_chk_guard_006a9ae8;
  pcStack_50 = pcVar5;
  pcStack_40 = unaff_s1;
  if (uVar19 < 0x10) {
LAB_00572f80:
    unaff_s1 = "encrypt";
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7a,FUN_0066c47c);
    pEVar4 = (EVP_PKEY *)0x0;
  }
  else {
    if (*pcVar5 != '\x06') {
      if (*pcVar5 == '\a') {
        uVar20 = 0x78;
        goto LAB_00573088;
      }
      goto LAB_00572f80;
    }
    if (pcVar5[1] != '\x02') {
      uVar20 = 0x75;
LAB_00573088:
      pcStack_50 = pcVar5;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,uVar20,FUN_0066c47c);
      goto LAB_00572f80;
    }
    pcStack_50 = pcVar5 + 0x10;
    uVar9 = (uint)(byte)pcVar5[9] << 8 | (uint)(byte)pcVar5[10] << 0x10 | (uint)(byte)pcVar5[8] |
            (uint)(byte)pcVar5[0xb] << 0x18;
    uVar23 = (uint)(byte)pcVar5[0xd] << 8 | (uint)(byte)pcVar5[0xe] << 0x10 |
             (uint)(byte)pcVar5[0xc] | (uint)(byte)pcVar5[0xf] << 0x18;
    if (uVar9 != 0x31535344) {
      if (uVar9 < 0x31535345) {
        if (uVar9 == 0x31415352) {
          if (uVar19 - 0x10 < (uVar23 + 7 >> 3) + 4) goto LAB_00573148;
          pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1(&pcStack_50,uVar23,1);
          goto LAB_00572fa8;
        }
      }
      else if ((uVar9 == 0x32415352) || (uVar9 == 0x32535344)) {
        uVar20 = 0x78;
        goto LAB_00573088;
      }
      uVar20 = 0x74;
      goto LAB_00573088;
    }
    if (uVar19 - 0x10 < (uVar23 + 7 >> 3) * 3 + 0x2c) {
LAB_00573148:
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7b,FUN_0066c47c);
      pEVar4 = (EVP_PKEY *)0x0;
    }
    else {
      pEVar4 = (EVP_PKEY *)b2i_dss_isra_0(&pcStack_50,uVar23,1);
    }
  }
LAB_00572fa8:
  if (prStack_4c == *(rsa_st **)puStack_90) {
    return pEVar4;
  }
  prVar10 = prStack_4c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  auStack_ec._8_4_ = (RSA_METHOD *)PTR___stack_chk_guard_006a9ae8;
  auStack_ec._4_4_ = (BN_MONT_CTX *)(auStack_ec + 0x48);
  auStack_ec._60_4_ = &_gp;
  pBStack_94 = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pcStack_8c = unaff_s1;
  iVar6 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar6 == 0x10) {
    pBStack_a8 = auStack_ec._4_4_;
    if (cStack_a4 == '\x06') {
      pcVar33 = *(code **)(auStack_ec._60_4_ + -0x6eac);
      uVar20 = 0x77;
      auStack_ec._52_4_ = (BN_MONT_CTX *)0x9d;
LAB_0057338c:
      (*pcVar33)(9,0x86,uVar20,FUN_0066c47c);
      goto LAB_00573204;
    }
    if (cStack_a4 != '\a') goto LAB_00573204;
    if (cStack_a3 != '\x02') {
      pcVar33 = *(code **)(auStack_ec._60_4_ + -0x6eac);
      uVar20 = 0x75;
      auStack_ec._52_4_ = (BN_MONT_CTX *)&DAT_000000ac;
      goto LAB_0057338c;
    }
    uVar9 = ((((uint)pBStack_9c >> 0x10) << 0x18 | ((uint)pBStack_9c >> 0x18) << 0x10) >> 0x10) +
            (((uint)pBStack_9c & 0xff) << 8 | (uint)pBStack_9c >> 8 & 0xff) * 0x10000;
    unaff_s5 = (rsa_st *)
               (((((uint)pBStack_98 >> 0x10) << 0x18 | ((uint)pBStack_98 >> 0x18) << 0x10) >> 0x10)
               + (((uint)pBStack_98 & 0xff) << 8 | (uint)pBStack_98 >> 8 & 0xff) * 0x10000);
    if (uVar9 == 0x31535344) {
LAB_00573378:
      pcVar33 = *(code **)(auStack_ec._60_4_ + -0x6eac);
      uVar20 = 0x77;
      auStack_ec._52_4_ = (BN_MONT_CTX *)0xba;
      goto LAB_0057338c;
    }
    if (uVar9 < 0x31535345) {
      if (uVar9 != 0x31415352) {
LAB_00573470:
        pcVar33 = *(code **)(auStack_ec._60_4_ + -0x6eac);
        uVar20 = 0x74;
        auStack_ec._52_4_ = (BN_MONT_CTX *)0xc9;
        goto LAB_0057338c;
      }
      goto LAB_00573378;
    }
    if (uVar9 == 0x32415352) {
      unaff_s3 = (BIGNUM *)0x0;
      auStack_ec._4_4_ =
           (BN_MONT_CTX *)
           ((((uint)((int)&unaff_s5->version + 3U) >> 3) + 2) * 2 +
           ((uint)((int)&unaff_s5->engine + 3) >> 4) * 5);
    }
    else {
      unaff_s3 = (BIGNUM *)0x1;
      if (uVar9 != 0x32535344) goto LAB_00573470;
      auStack_ec._4_4_ = (BN_MONT_CTX *)((((uint)((int)&unaff_s5->version + 3) >> 3) + 0x20) * 2);
    }
    pBStack_a8 = (BN_MONT_CTX *)&pBStack_94;
    unaff_s6 = (rsa_st *)0x670000;
    if ((BN_MONT_CTX *)0x19000 < auStack_ec._4_4_) {
      pcVar33 = *(code **)(auStack_ec._60_4_ + -0x6eac);
      uVar20 = 0x80;
      auStack_ec._52_4_ = (BN_MONT_CTX *)0x117;
      goto LAB_00573350;
    }
    unaff_s4 = (BN_MONT_CTX *)
               (**(code **)(auStack_ec._60_4_ + -0x7dd8))(auStack_ec._4_4_,FUN_0066c47c,0x11a);
    if (unaff_s4 == (BN_MONT_CTX *)0x0) {
      auStack_ec._52_4_ = (BN_MONT_CTX *)0x11c;
      (**(code **)(auStack_ec._60_4_ + -0x6eac))(9,0x85,0x41,FUN_0066c47c);
      pBVar7 = (BN_MONT_CTX *)0x0;
    }
    else {
      pBStack_a8 = unaff_s4;
      pBVar7 = (BN_MONT_CTX *)
               (**(code **)(auStack_ec._60_4_ + -0x7920))(prVar10,unaff_s4,auStack_ec._4_4_);
      if (auStack_ec._4_4_ == pBVar7) {
        if (unaff_s3 == (BIGNUM *)0x0) {
          pBVar7 = (BN_MONT_CTX *)b2i_rsa_isra_1(auStack_ec + 0x44,unaff_s5,0);
        }
        else {
          pBVar7 = (BN_MONT_CTX *)b2i_dss_isra_0();
        }
      }
      else {
        auStack_ec._52_4_ = (BN_MONT_CTX *)0x121;
        pBVar7 = (BN_MONT_CTX *)0x0;
        (**(code **)(auStack_ec._60_4_ + -0x6eac))(9,0x85,0x7b,FUN_0066c47c);
      }
      (**(code **)(auStack_ec._60_4_ + -0x7f58))(unaff_s4);
      auStack_ec._4_4_ = pBVar7;
    }
  }
  else {
    pcVar33 = *(code **)(auStack_ec._60_4_ + -0x6eac);
    uVar20 = 0x7b;
    auStack_ec._52_4_ = (BN_MONT_CTX *)0x10e;
LAB_00573350:
    (*pcVar33)(9,0x85,uVar20,FUN_0066c47c);
LAB_00573204:
    pBVar7 = (BN_MONT_CTX *)0x0;
  }
  if (pBStack_94 == *(BIGNUM **)auStack_ec._8_4_) {
    return (EVP_PKEY *)pBVar7;
  }
  auStack_ec._32_4_ = b2i_PublicKey_bio;
  pBStack_13c = pBStack_94;
  (**(code **)(auStack_ec._60_4_ + -0x5330))();
  prVar32 = (rsa_st *)PTR___stack_chk_guard_006a9ae8;
  prVar21 = (rsa_st *)&SUB_00000010;
  prVar11 = (rsa_st *)&cStack_fc;
  auStack_ec._0_4_ = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  prVar28 = prVar11;
  auStack_ec._12_4_ = prVar10;
  auStack_ec._16_4_ = unaff_s3;
  auStack_ec._20_4_ = unaff_s4;
  auStack_ec._24_4_ = unaff_s5;
  auStack_ec._28_4_ = unaff_s6;
  iVar6 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar6 == 0x10) {
    prStack_100 = prVar11;
    if (cStack_fc != '\x06') {
      if (cStack_fc == '\a') {
        prVar21 = (rsa_st *)&DAT_00000078;
        goto LAB_005735cc;
      }
      goto LAB_00573528;
    }
    if (cStack_fb != '\x02') {
      prVar21 = (rsa_st *)0x75;
LAB_005735cc:
      prVar28 = (rsa_st *)0x86;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,prVar21,FUN_0066c47c);
      goto LAB_00573528;
    }
    uVar9 = ((((uint)pRStack_f4 >> 0x10) << 0x18 | ((uint)pRStack_f4 >> 0x18) << 0x10) >> 0x10) +
            (((uint)pRStack_f4 & 0xff) << 8 | (uint)pRStack_f4 >> 8 & 0xff) * 0x10000;
    prVar10 = (rsa_st *)
              (((((uint)pEStack_f0 >> 0x10) << 0x18 | ((uint)pEStack_f0 >> 0x18) << 0x10) >> 0x10) +
              (((uint)pEStack_f0 & 0xff) << 8 | (uint)pEStack_f0 >> 8 & 0xff) * 0x10000);
    if (uVar9 != 0x31535344) {
      if (uVar9 < 0x31535345) {
        unaff_s4 = (BN_MONT_CTX *)0x0;
        if (uVar9 == 0x31415352) {
          prVar11 = (rsa_st *)(((uint)((int)&prVar10->version + 3) >> 3) + 4);
          goto LAB_00573630;
        }
      }
      else if ((uVar9 == 0x32415352) || (uVar9 == 0x32535344)) {
        prVar21 = (rsa_st *)&DAT_00000078;
        goto LAB_005735cc;
      }
      prVar21 = (rsa_st *)&DAT_00000074;
      goto LAB_005735cc;
    }
    unaff_s4 = (BN_MONT_CTX *)0x1;
    prVar11 = (rsa_st *)(((uint)((int)&prVar10->version + 3) >> 3) * 3 + 0x2c);
LAB_00573630:
    prStack_100 = (rsa_st *)auStack_ec;
    unaff_s6 = (rsa_st *)0x670000;
    if ((rsa_st *)0x19000 < prVar11) {
      prVar21 = (rsa_st *)&DAT_00000080;
      goto LAB_005735f8;
    }
    unaff_s5 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar11,FUN_0066c47c,0x11a);
    if (unaff_s5 == (rsa_st *)0x0) {
      prVar21 = (rsa_st *)&DAT_00000041;
      prVar28 = (rsa_st *)0x85;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,0x41,FUN_0066c47c);
      prVar8 = (rsa_st *)0x0;
    }
    else {
      prStack_100 = unaff_s5;
      prVar28 = (rsa_st *)(*(code *)PTR_BIO_read_006a74c0)(pBStack_13c,unaff_s5,prVar11);
      if (prVar11 == prVar28) {
        prVar21 = (rsa_st *)0x1;
        prVar28 = prVar10;
        if (unaff_s4 == (BN_MONT_CTX *)0x0) {
          prVar8 = (rsa_st *)b2i_rsa_isra_1(&prStack_100);
        }
        else {
          prVar8 = (rsa_st *)b2i_dss_isra_0();
        }
      }
      else {
        prVar21 = (rsa_st *)0x7b;
        prVar28 = (rsa_st *)0x85;
        prVar8 = (rsa_st *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,0x7b,FUN_0066c47c);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s5);
      prVar11 = prVar8;
    }
  }
  else {
    prVar21 = (rsa_st *)0x7b;
LAB_005735f8:
    prVar28 = (rsa_st *)0x85;
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x85,prVar21,FUN_0066c47c);
LAB_00573528:
    prVar8 = (rsa_st *)0x0;
  }
  if (auStack_ec._0_4_ == *(BIGNUM **)prVar32) {
    return (EVP_PKEY *)prVar8;
  }
  pBVar18 = auStack_ec._0_4_;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pEStack_144 = (ENGINE *)prVar32;
  iStack_150 = 0;
  iStack_14c = *(int *)PTR___stack_chk_guard_006a9ae8;
  prStack_148 = prVar11;
  prStack_140 = prVar10;
  pBStack_138 = unaff_s4;
  prStack_134 = unaff_s5;
  prStack_130 = unaff_s6;
  if (prVar28->pad == 0x74) {
    prVar11 = ((_union_271 *)&prVar28->e)->rsa;
    prVar10 = (rsa_st *)(*(code *)PTR_BN_num_bits_006a71f4)((EVP_PKEY_ASN1_METHOD *)prVar11->engine)
    ;
    if ((((((uint)prVar10 & 7) != 0) ||
         (iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar11->n), iVar6 != 0xa0)) ||
        (iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(((_union_271 *)&prVar11->e)->ptr),
        (int)prVar10 < iVar6)) ||
       (iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar11->p), 0xa0 < iVar6)) {
      prVar21 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x82,0x7e,FUN_0066c47c,0x222);
      goto LAB_00573fe8;
    }
    iStack_150 = 0x32535344;
    if (prVar10 == (rsa_st *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar6 = (((uint)((int)&prVar10->version + 3) >> 3) + 0x20) * 2;
  }
  else {
    prVar8 = (rsa_st *)0xffffffff;
    if (prVar28->pad != 6) goto LAB_00573f4c;
    prVar21 = (rsa_st *)&iStack_150;
    prVar10 = (rsa_st *)check_bitlen_rsa(((_union_271 *)&prVar28->e)->ptr,0);
    if (prVar10 == (rsa_st *)0x0) goto LAB_00573fe8;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar6 = (((uint)((int)&prVar10->version + 3) >> 3) + 2) * 2 +
            ((uint)((int)&prVar10->engine + 3) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar8 = (rsa_st *)(iVar6 + 0x10);
  prVar21 = (rsa_st *)0x1e8;
  prVar11 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a7008)(prVar8,FUN_0066c47c);
  prVar32 = prVar8;
  if (prVar11 == (rsa_st *)0x0) goto LAB_00573fe8;
  *(undefined *)((int)&prVar11->pad + 2) = 0;
  *(undefined *)((int)&prVar11->pad + 3) = 0;
  *(undefined *)&prVar11->version = 0;
  *(char *)((int)&prVar11->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&prVar11->version + 2) = 0;
  *(undefined *)&prVar11->pad = 7;
  ppBVar29 = &prVar11->n;
  *(undefined *)((int)&prVar11->version + 3) = 0;
  *(char *)&prVar11->engine = (char)prVar10;
  *(undefined *)((int)&prVar11->pad + 1) = 2;
  *(char *)((int)&prVar11->engine + 1) = (char)((uint)prVar10 >> 8);
  *(char *)((int)&prVar11->engine + 2) = (char)((uint)prVar10 >> 0x10);
  *(char *)((int)&prVar11->engine + 3) = (char)((uint)prVar10 >> 0x18);
  *(char *)&prVar11->meth = (char)iStack_150;
  *(char *)((int)&prVar11->meth + 1) = (char)((uint)iStack_150 >> 8);
  *(char *)((int)&prVar11->meth + 2) = (char)((uint)iStack_150 >> 0x10);
  *(char *)((int)&prVar11->meth + 3) = (char)((uint)iStack_150 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar10 = ((_union_271 *)&prVar28->e)->rsa;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(prVar10->engine);
    pEVar22 = prVar10->engine;
    iVar6 = iVar12 + 7;
    if (iVar12 + 7 < 0) {
      iVar6 = iVar12 + 0xe;
    }
    iVar6 = iVar6 >> 3;
    iVar25 = (*(code *)PTR_BN_num_bits_006a71f4)(pEVar22);
    iVar26 = iVar25 + 7;
    iVar12 = iVar25 + 0xe;
    if (-1 < iVar26) {
      iVar12 = iVar26;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pEVar22,ppBVar29);
    iVar12 = iVar12 >> 3;
    iVar25 = iVar25 + 0x16;
    if (-1 < iVar26) {
      iVar25 = iVar26;
    }
    if (0 < iVar25 >> 4) {
      ppBVar16 = ppBVar29;
      puVar31 = (undefined *)((int)ppBVar29 + iVar12 + -1);
      do {
        uVar1 = *(undefined *)ppBVar16;
        ppBVar13 = (BIGNUM **)((int)ppBVar16 + 1);
        *(undefined *)ppBVar16 = *puVar31;
        *puVar31 = uVar1;
        ppBVar16 = ppBVar13;
        puVar31 = puVar31 + -1;
      } while ((BIGNUM **)((int)ppBVar29 + (iVar25 >> 4)) != ppBVar13);
    }
    puVar30 = (undefined *)((int)ppBVar29 + iVar12);
    puVar31 = puVar30;
    if ((0 < iVar6) && (0 < iVar6 - iVar12)) {
      puVar31 = puVar30 + (iVar6 - iVar12);
      (*(code *)PTR_memset_006a99f4)(puVar30,0);
    }
    pBVar24 = prVar10->n;
    iVar25 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar26 = iVar25 + 7;
    iVar12 = iVar25 + 0xe;
    if (-1 < iVar26) {
      iVar12 = iVar26;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
    iVar12 = iVar12 >> 3;
    iVar25 = iVar25 + 0x16;
    if (-1 < iVar26) {
      iVar25 = iVar26;
    }
    if (0 < iVar25 >> 4) {
      puVar30 = puVar31;
      puVar15 = puVar31 + iVar12 + -1;
      do {
        uVar1 = *puVar30;
        puVar14 = puVar30 + 1;
        *puVar30 = *puVar15;
        *puVar15 = uVar1;
        puVar30 = puVar14;
        puVar15 = puVar15 + -1;
      } while (puVar31 + (iVar25 >> 4) != puVar14);
    }
    puVar31 = puVar31 + iVar12;
    puVar30 = puVar31;
    if (0 < 0x14 - iVar12) {
      puVar30 = puVar31 + (0x14 - iVar12);
      (*(code *)PTR_memset_006a99f4)(puVar31,0);
    }
    pBVar24 = prVar10->e;
    iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar25 = iVar26 + 7;
    iVar12 = iVar26 + 0xe;
    if (-1 < iVar25) {
      iVar12 = iVar25;
    }
    iVar12 = iVar12 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar30);
    if (-1 >= iVar25) {
      iVar25 = iVar26 + 0x16;
    }
    if (0 < iVar25 >> 4) {
      puVar31 = puVar30;
      puVar15 = puVar30 + iVar12 + -1;
      do {
        uVar1 = *puVar31;
        puVar14 = puVar31 + 1;
        *puVar31 = *puVar15;
        *puVar15 = uVar1;
        puVar31 = puVar14;
        puVar15 = puVar15 + -1;
      } while (puVar14 != puVar30 + (iVar25 >> 4));
    }
    prVar32 = (rsa_st *)(puVar30 + iVar12);
    unaff_s7 = prVar32;
    if ((0 < iVar6) && (0 < iVar6 - iVar12)) {
      unaff_s7 = (rsa_st *)((int)prVar32 + (iVar6 - iVar12));
      (*(code *)PTR_memset_006a99f4)(prVar32,0);
    }
    pBVar24 = prVar10->p;
    iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    prVar10 = (rsa_st *)(iVar6 + 7);
    prVar28 = (rsa_st *)(iVar6 + 0xe);
    if (-1 < (int)prVar10) {
      prVar28 = prVar10;
    }
    unaff_s6 = (rsa_st *)(iVar6 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,unaff_s7);
    if (-1 >= (int)prVar10) {
      prVar10 = unaff_s6;
    }
    prVar28 = (rsa_st *)((int)prVar28 >> 3);
    if (0 < (int)prVar10 >> 4) {
      prVar32 = unaff_s7;
      puVar31 = (undefined *)((int)&prVar28[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar32->pad;
        prVar21 = (rsa_st *)((int)&prVar32->pad + 1);
        *(undefined *)&prVar32->pad = *puVar31;
        *puVar31 = uVar1;
        prVar32 = prVar21;
        puVar31 = puVar31 + -1;
      } while (prVar21 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar10 >> 4)));
    }
    prVar32 = (rsa_st *)((int)&prVar28->pad + (int)&unaff_s7->pad);
    prVar10 = prVar32;
    if (0 < 0x14 - (int)prVar28) {
      prVar10 = (rsa_st *)((int)prVar32 + (0x14 - (int)prVar28));
      (*(code *)PTR_memset_006a99f4)(prVar32,0);
    }
    prVar21 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006a99f4)(prVar10,0xff);
    prVar27 = prVar11;
    goto LAB_00573f14;
  }
  unaff_s6 = ((_union_271 *)&prVar28->e)->rsa;
  iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  iVar6 = iVar12 + 7;
  if (iVar12 + 7 < 0) {
    iVar6 = iVar12 + 0xe;
  }
  prVar28 = (rsa_st *)(iVar6 >> 3);
  iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(unaff_s6->n);
  pBVar24 = unaff_s6->e;
  prVar10 = (rsa_st *)(iVar6 + 0xf >> 4);
  iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
  iVar25 = iVar12 + 7;
  iVar6 = iVar12 + 0xe;
  if (-1 < iVar25) {
    iVar6 = iVar25;
  }
  iVar6 = iVar6 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,ppBVar29);
  iVar12 = iVar12 + 0x16;
  if (-1 < iVar25) {
    iVar12 = iVar25;
  }
  if (0 < iVar12 >> 4) {
    ppBVar16 = ppBVar29;
    puVar31 = (undefined *)((int)ppBVar29 + iVar6 + -1);
    do {
      uVar1 = *(undefined *)ppBVar16;
      ppBVar13 = (BIGNUM **)((int)ppBVar16 + 1);
      *(undefined *)ppBVar16 = *puVar31;
      *puVar31 = uVar1;
      ppBVar16 = ppBVar13;
      puVar31 = puVar31 + -1;
    } while ((BIGNUM **)((int)ppBVar29 + (iVar12 >> 4)) != ppBVar13);
  }
  puVar30 = (undefined *)((int)ppBVar29 + iVar6);
  puVar31 = puVar30;
  if (0 < 4 - iVar6) {
    puVar31 = puVar30 + (4 - iVar6);
    (*(code *)PTR_memset_006a99f4)(puVar30,0);
  }
  pBVar24 = unaff_s6->n;
  iVar25 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
  iVar12 = iVar25 + 7;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
  iVar6 = iVar12;
  if (iVar12 < 0) {
    iVar12 = iVar25 + 0x16;
    iVar6 = iVar25 + 0xe;
  }
  if (0 < iVar12 >> 4) {
    puVar30 = puVar31;
    puVar15 = puVar31 + (iVar6 >> 3) + -1;
    do {
      uVar1 = *puVar30;
      puVar14 = puVar30 + 1;
      *puVar30 = *puVar15;
      *puVar15 = uVar1;
      puVar30 = puVar14;
      puVar15 = puVar15 + -1;
    } while (puVar14 != puVar31 + (iVar12 >> 4));
  }
  pBVar24 = unaff_s6->p;
  puVar31 = puVar31 + (iVar6 >> 3);
  iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
  iVar25 = iVar12 + 7;
  iVar6 = iVar12 + 0xe;
  if (-1 < iVar25) {
    iVar6 = iVar25;
  }
  iVar6 = iVar6 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
  iVar12 = iVar12 + 0x16;
  if (-1 < iVar25) {
    iVar12 = iVar25;
  }
  if (0 < iVar12 >> 4) {
    puVar30 = puVar31;
    puVar15 = puVar31 + iVar6 + -1;
    do {
      uVar1 = *puVar30;
      puVar14 = puVar30 + 1;
      *puVar30 = *puVar15;
      *puVar15 = uVar1;
      puVar30 = puVar14;
      puVar15 = puVar15 + -1;
    } while (puVar31 + (iVar12 >> 4) != puVar14);
  }
  puVar31 = puVar31 + iVar6;
  if ((int)prVar10 < 1) {
    pBVar24 = unaff_s6->q;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar25 = iVar12 + 7;
    iVar6 = iVar12 + 0xe;
    if (-1 < iVar25) {
      iVar6 = iVar25;
    }
    iVar6 = iVar6 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
    iVar12 = iVar12 + 0x16;
    if (-1 < iVar25) {
      iVar12 = iVar25;
    }
    iVar12 = iVar12 >> 4;
    puVar30 = puVar31 + iVar6 + -1;
    if (0 < iVar12) goto LAB_00573bc8;
    puVar31 = puVar31 + iVar6;
LAB_00574388:
    pBVar24 = unaff_s6->dmp1;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar25 = iVar12 + 7;
    iVar6 = iVar12 + 0xe;
    if (-1 < iVar25) {
      iVar6 = iVar25;
    }
    iVar6 = iVar6 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
    iVar12 = iVar12 + 0x16;
    if (-1 < iVar25) {
      iVar12 = iVar25;
    }
    iVar12 = iVar12 >> 4;
    puVar30 = puVar31 + iVar6 + -1;
    if (0 < iVar12) goto LAB_00573c8c;
    puVar31 = puVar31 + iVar6;
LAB_00574400:
    pBVar24 = unaff_s6->dmq1;
    iVar25 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar6 = iVar25 + 7;
    iVar12 = iVar25 + 0xe;
    if (-1 < iVar6) {
      iVar12 = iVar6;
    }
    iVar12 = iVar12 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
    if (-1 >= iVar6) {
      iVar6 = iVar25 + 0x16;
    }
    iVar6 = iVar6 >> 4;
    puVar30 = puVar31 + iVar12 + -1;
    if (0 < iVar6) goto LAB_00573d50;
LAB_00573d74:
    unaff_s7 = (rsa_st *)(puVar31 + iVar12);
    if ((int)prVar10 < 1) {
      pBVar24 = unaff_s6->iqmp;
      iVar25 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
      iVar12 = iVar25 + 7;
      iVar6 = iVar25 + 0xe;
      if (-1 < iVar12) {
        iVar6 = iVar12;
      }
      prVar21 = (rsa_st *)(iVar6 >> 3);
      (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,unaff_s7);
      if (-1 >= iVar12) {
        iVar12 = iVar25 + 0x16;
      }
      iVar12 = iVar12 >> 4;
      puVar31 = (undefined *)((int)&prVar21[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar12 < 1) {
        unaff_s7 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
        goto LAB_00573e60;
      }
      goto LAB_00573e14;
    }
  }
  else {
    iVar6 = (int)prVar10 - iVar6;
    if (0 < iVar6) {
      (*(code *)PTR_memset_006a99f4)(puVar31,0,iVar6);
      puVar31 = puVar31 + iVar6;
    }
    pBVar24 = unaff_s6->q;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar25 = iVar12 + 7;
    iVar6 = iVar12 + 0xe;
    if (-1 < iVar25) {
      iVar6 = iVar25;
    }
    iVar6 = iVar6 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
    iVar12 = iVar12 + 0x16;
    if (-1 < iVar25) {
      iVar12 = iVar25;
    }
    iVar12 = iVar12 >> 4;
    puVar30 = puVar31 + iVar6 + -1;
    if (iVar12 < 1) {
      puVar31 = puVar31 + iVar6;
    }
    else {
LAB_00573bc8:
      puVar15 = puVar31;
      do {
        uVar1 = *puVar15;
        puVar14 = puVar15 + 1;
        *puVar15 = *puVar30;
        *puVar30 = uVar1;
        puVar15 = puVar14;
        puVar30 = puVar30 + -1;
      } while (puVar31 + iVar12 != puVar14);
      puVar31 = puVar31 + iVar6;
      if ((int)prVar10 < 1) goto LAB_00574388;
    }
    iVar6 = (int)prVar10 - iVar6;
    if (0 < iVar6) {
      (*(code *)PTR_memset_006a99f4)(puVar31,0,iVar6);
      puVar31 = puVar31 + iVar6;
    }
    pBVar24 = unaff_s6->dmp1;
    iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar25 = iVar12 + 7;
    iVar6 = iVar12 + 0xe;
    if (-1 < iVar25) {
      iVar6 = iVar25;
    }
    iVar6 = iVar6 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
    iVar12 = iVar12 + 0x16;
    if (-1 < iVar25) {
      iVar12 = iVar25;
    }
    iVar12 = iVar12 >> 4;
    puVar30 = puVar31 + iVar6 + -1;
    if (iVar12 < 1) {
      puVar31 = puVar31 + iVar6;
    }
    else {
LAB_00573c8c:
      puVar15 = puVar31;
      do {
        uVar1 = *puVar15;
        puVar14 = puVar15 + 1;
        *puVar15 = *puVar30;
        *puVar30 = uVar1;
        puVar15 = puVar14;
        puVar30 = puVar30 + -1;
      } while (puVar31 + iVar12 != puVar14);
      puVar31 = puVar31 + iVar6;
      if ((int)prVar10 < 1) goto LAB_00574400;
    }
    iVar6 = (int)prVar10 - iVar6;
    if (0 < iVar6) {
      (*(code *)PTR_memset_006a99f4)(puVar31,0,iVar6);
      puVar31 = puVar31 + iVar6;
    }
    pBVar24 = unaff_s6->dmq1;
    iVar25 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar6 = iVar25 + 7;
    iVar12 = iVar25 + 0xe;
    if (-1 < iVar6) {
      iVar12 = iVar6;
    }
    iVar12 = iVar12 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,puVar31);
    if (-1 >= iVar6) {
      iVar6 = iVar25 + 0x16;
    }
    iVar6 = iVar6 >> 4;
    puVar30 = puVar31 + iVar12 + -1;
    if (0 < iVar6) {
LAB_00573d50:
      puVar15 = puVar31;
      do {
        uVar1 = *puVar15;
        puVar14 = puVar15 + 1;
        *puVar15 = *puVar30;
        *puVar30 = uVar1;
        puVar30 = puVar30 + -1;
        puVar15 = puVar14;
      } while (puVar31 + iVar6 != puVar14);
      goto LAB_00573d74;
    }
    unaff_s7 = (rsa_st *)(puVar31 + iVar12);
  }
  iVar12 = (int)prVar10 - iVar12;
  if (0 < iVar12) {
    (*(code *)PTR_memset_006a99f4)(unaff_s7,0,iVar12);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar12);
  }
  pBVar24 = unaff_s6->iqmp;
  iVar25 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
  iVar12 = iVar25 + 7;
  iVar6 = iVar25 + 0xe;
  if (-1 < iVar12) {
    iVar6 = iVar12;
  }
  prVar21 = (rsa_st *)(iVar6 >> 3);
  (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,unaff_s7);
  if (-1 >= iVar12) {
    iVar12 = iVar25 + 0x16;
  }
  iVar12 = iVar12 >> 4;
  puVar31 = (undefined *)((int)&prVar21[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar12 < 1) goto LAB_00574578;
LAB_00573e14:
  prVar32 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar32->pad;
    prVar27 = (rsa_st *)((int)&prVar32->pad + 1);
    *(undefined *)&prVar32->pad = *puVar31;
    *puVar31 = uVar1;
    puVar31 = puVar31 + -1;
    prVar32 = prVar27;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar12) != prVar27);
  prVar32 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar32;
  if ((int)prVar10 < 1) goto LAB_00573e60;
  do {
    unaff_s7 = prVar32;
    if (0 < (int)prVar10 - (int)prVar21) {
      unaff_s7 = (rsa_st *)((int)prVar32 + ((int)prVar10 - (int)prVar21));
      (*(code *)PTR_memset_006a99f4)(prVar32,0);
    }
LAB_00573e60:
    pBVar24 = unaff_s6->d;
    iVar25 = (*(code *)PTR_BN_num_bits_006a71f4)(pBVar24);
    iVar6 = iVar25 + 7;
    prVar10 = (rsa_st *)(uint)(iVar6 < 0);
    iVar12 = iVar25 + 0xe;
    if (prVar10 == (rsa_st *)0x0) {
      iVar12 = iVar6;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(pBVar24,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar12 >> 3);
    if (prVar10 != (rsa_st *)0x0) {
      iVar6 = iVar25 + 0x16;
    }
    prVar21 = (rsa_st *)(iVar6 >> 4);
    if (0 < (int)prVar21) {
      prVar21 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
      puVar31 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar32 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar32->pad;
        prVar27 = (rsa_st *)((int)&prVar32->pad + 1);
        *(undefined *)&prVar32->pad = *puVar31;
        *puVar31 = uVar1;
        puVar31 = puVar31 + -1;
        prVar32 = prVar27;
      } while (prVar21 != prVar27);
    }
    prVar27 = prVar11;
    if ((0 < (int)prVar28) && (prVar21 = (rsa_st *)((int)prVar28 - (int)unaff_s6), 0 < (int)prVar21)
       ) {
      (*(code *)PTR_memset_006a99f4)((char *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00573f14:
    prVar11 = prVar27;
    prVar32 = prVar8;
    if ((int)prVar8 < 0) {
LAB_00573fe8:
      prVar8 = (rsa_st *)0xffffffff;
    }
    else {
      prVar21 = prVar8;
      prVar11 = (rsa_st *)(*(code *)PTR_BIO_write_006a6e14)(pBVar18,prVar27);
      (*(code *)PTR_CRYPTO_free_006a6e88)(prVar27);
      if (prVar11 != prVar8) goto LAB_00573fe8;
    }
LAB_00573f4c:
    if (iStack_14c == *(int *)puVar2) {
      return (EVP_PKEY *)prVar8;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    prVar8 = prVar32;
LAB_00574578:
    prVar32 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
  } while( true );
}

