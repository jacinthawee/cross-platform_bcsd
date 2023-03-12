
EVP_PKEY * b2i_PrivateKey(uchar **in,long length)

{
  undefined uVar1;
  undefined *puVar2;
  uchar *puVar3;
  EVP_PKEY *pEVar4;
  BN_MONT_CTX *pBVar5;
  int iVar6;
  rsa_st *prVar7;
  rsa_st *prVar8;
  uint uVar9;
  undefined *puVar10;
  rsa_st *prVar11;
  int iVar12;
  BIGNUM **ppBVar13;
  undefined *puVar14;
  BIGNUM **ppBVar15;
  undefined *puVar16;
  BN_MONT_CTX **ppBVar17;
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
  RSA_METHOD *unaff_s1;
  BIGNUM *unaff_s2;
  rsa_st *prVar28;
  rsa_st *unaff_s4;
  BIGNUM *unaff_s5;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar29;
  undefined *puVar30;
  undefined *puVar31;
  code *pcVar32;
  int iStack_150;
  int iStack_14c;
  rsa_st *prStack_148;
  rsa_st *prStack_144;
  BIGNUM *pBStack_140;
  BIGNUM *pBStack_13c;
  rsa_st *prStack_138;
  BIGNUM *pBStack_134;
  rsa_st *prStack_130;
  rsa_st *prStack_100;
  char cStack_fc;
  char cStack_fb;
  RSA_METHOD *pRStack_f4;
  ENGINE *pEStack_f0;
  undefined auStack_ec [68];
  rsa_st *prStack_a8;
  char cStack_a4;
  char cStack_a3;
  BN_BLINDING *pBStack_9c;
  BN_BLINDING *pBStack_98;
  BIGNUM *pBStack_94;
  undefined *puStack_90;
  RSA_METHOD *pRStack_8c;
  BN_MONT_CTX *pBStack_50;
  BN_MONT_CTX *pBStack_4c;
  BN_BLINDING *pBStack_44;
  RSA_METHOD *pRStack_40;
  code *pcStack_3c;
  undefined4 local_28;
  undefined *local_20;
  uchar *local_18;
  BN_MONT_CTX **local_14;
  
  pBStack_44 = (BN_BLINDING *)PTR___stack_chk_guard_006aabf0;
  puVar3 = *in;
  local_20 = &_gp;
  local_14 = *(BN_MONT_CTX ***)PTR___stack_chk_guard_006aabf0;
  local_18 = puVar3;
  if ((uint)length < 0x10) {
LAB_0057659c:
    unaff_s1 = (RSA_METHOD *)0x670000;
    uVar19 = 0x84;
    local_28 = 0xff;
    (**(code **)(local_20 + -0x6eb0))(9,0x84,0x7a,FUN_0066ce6c);
    pEVar4 = (EVP_PKEY *)0x0;
  }
  else {
    if (*puVar3 == '\x06') {
      uVar20 = 0x77;
      local_28 = 0x98;
LAB_005766bc:
      local_18 = puVar3;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,uVar20,FUN_0066ce6c);
      goto LAB_0057659c;
    }
    if (*puVar3 != '\a') goto LAB_0057659c;
    if (puVar3[1] != '\x02') {
      uVar20 = 0x75;
      local_28 = 0xad;
      goto LAB_005766bc;
    }
    local_18 = puVar3 + 0x10;
    uVar9 = (uint)puVar3[9] << 8 | (uint)puVar3[10] << 0x10 | (uint)puVar3[8] |
            (uint)puVar3[0xb] << 0x18;
    uVar19 = (uint)puVar3[0xd] << 8 | (uint)puVar3[0xe] << 0x10 | (uint)puVar3[0xc] |
             (uint)puVar3[0xf] << 0x18;
    if (uVar9 == 0x31535344) {
LAB_00576730:
      uVar20 = 0x77;
      local_28 = 0xbe;
      goto LAB_005766bc;
    }
    if (uVar9 < 0x31535345) {
      if (uVar9 != 0x31415352) {
LAB_00576760:
        uVar20 = 0x74;
        local_28 = 0xcf;
        goto LAB_005766bc;
      }
      goto LAB_00576730;
    }
    if (uVar9 == 0x32415352) {
      if (length - 0x10U < ((uVar19 + 7 >> 3) + 2) * 2 + (uVar19 + 0xf >> 4) * 5) {
LAB_00576778:
        local_28 = 0x105;
        uVar19 = 0x84;
        (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7b,FUN_0066ce6c);
        pEVar4 = (EVP_PKEY *)0x0;
      }
      else {
        pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1(&local_18,uVar19,0);
      }
    }
    else {
      if (uVar9 != 0x32535344) goto LAB_00576760;
      if (length - 0x10U < ((uVar19 + 7 >> 3) + 0x20) * 2) goto LAB_00576778;
      pEVar4 = (EVP_PKEY *)b2i_dss_isra_0(&local_18,uVar19,0);
    }
  }
  if (local_14 == *(BN_MONT_CTX ***)pBStack_44) {
    return pEVar4;
  }
  pcStack_3c = b2i_PublicKey;
  ppBVar17 = local_14;
  (**(code **)(local_20 + -0x5328))();
  puStack_90 = PTR___stack_chk_guard_006aabf0;
  pBVar5 = *ppBVar17;
  pBStack_4c = *(BN_MONT_CTX **)PTR___stack_chk_guard_006aabf0;
  pBStack_50 = pBVar5;
  pRStack_40 = unaff_s1;
  if (uVar19 < 0x10) {
LAB_0057680c:
    unaff_s1 = (RSA_METHOD *)0x670000;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7a,FUN_0066ce6c);
    pEVar4 = (EVP_PKEY *)0x0;
  }
  else {
    if (*(char *)&pBVar5->ri != '\x06') {
      if (*(char *)&pBVar5->ri == '\a') {
        uVar20 = 0x78;
        goto LAB_00576914;
      }
      goto LAB_0057680c;
    }
    if (*(char *)((int)&pBVar5->ri + 1) != '\x02') {
      uVar20 = 0x75;
LAB_00576914:
      pBStack_50 = pBVar5;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,uVar20,FUN_0066ce6c);
      goto LAB_0057680c;
    }
    pBStack_50 = (BN_MONT_CTX *)&(pBVar5->RR).neg;
    uVar9 = (uint)*(byte *)((int)&(pBVar5->RR).top + 1) << 8 |
            (uint)*(byte *)((int)&(pBVar5->RR).top + 2) << 0x10 | (uint)*(byte *)&(pBVar5->RR).top |
            (uint)*(byte *)((int)&(pBVar5->RR).top + 3) << 0x18;
    uVar23 = (uint)*(byte *)((int)&(pBVar5->RR).dmax + 1) << 8 |
             (uint)*(byte *)((int)&(pBVar5->RR).dmax + 2) << 0x10 |
             (uint)*(byte *)&(pBVar5->RR).dmax |
             (uint)*(byte *)((int)&(pBVar5->RR).dmax + 3) << 0x18;
    if (uVar9 != 0x31535344) {
      if (uVar9 < 0x31535345) {
        if (uVar9 == 0x31415352) {
          if (uVar19 - 0x10 < (uVar23 + 7 >> 3) + 4) goto LAB_005769d4;
          pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1(&pBStack_50,uVar23,1);
          goto LAB_00576834;
        }
      }
      else if ((uVar9 == 0x32415352) || (uVar9 == 0x32535344)) {
        uVar20 = 0x78;
        goto LAB_00576914;
      }
      uVar20 = 0x74;
      goto LAB_00576914;
    }
    if (uVar19 - 0x10 < (uVar23 + 7 >> 3) * 3 + 0x2c) {
LAB_005769d4:
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7b,FUN_0066ce6c);
      pEVar4 = (EVP_PKEY *)0x0;
    }
    else {
      pEVar4 = (EVP_PKEY *)b2i_dss_isra_0(&pBStack_50,uVar23,1);
    }
  }
LAB_00576834:
  if (pBStack_4c == *(BN_MONT_CTX **)puStack_90) {
    return pEVar4;
  }
  auStack_ec._16_4_ = pBStack_4c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  prVar28 = (rsa_st *)PTR___stack_chk_guard_006aabf0;
  auStack_ec._4_4_ = (rsa_st *)(auStack_ec + 0x48);
  auStack_ec._60_4_ = &_gp;
  pBStack_94 = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  pRStack_8c = unaff_s1;
  iVar6 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar6 == 0x10) {
    prStack_a8 = auStack_ec._4_4_;
    if (cStack_a4 == '\x06') {
      pcVar32 = *(code **)(auStack_ec._60_4_ + -0x6eb0);
      uVar20 = 0x77;
      auStack_ec._52_4_ = (BN_MONT_CTX *)&DAT_00000098;
LAB_00576c0c:
      (*pcVar32)(9,0x86,uVar20,FUN_0066ce6c);
    }
    else if (cStack_a4 == '\a') {
      if (cStack_a3 == '\x02') {
        uVar9 = ((((uint)pBStack_9c >> 0x10) << 0x18 | ((uint)pBStack_9c >> 0x18) << 0x10) >> 0x10)
                + (((uint)pBStack_9c & 0xff) << 8 | (uint)pBStack_9c >> 8 & 0xff) * 0x10000;
        unaff_s2 = (BIGNUM *)
                   (((((uint)pBStack_98 >> 0x10) << 0x18 | ((uint)pBStack_98 >> 0x18) << 0x10) >>
                    0x10) + (((uint)pBStack_98 & 0xff) << 8 | (uint)pBStack_98 >> 8 & 0xff) *
                            0x10000);
        if (uVar9 != 0x31535344) {
          if (0x31535344 < uVar9) {
            if (uVar9 == 0x32415352) {
              unaff_s5 = (BIGNUM *)0x0;
              auStack_ec._4_4_ =
                   (rsa_st *)
                   ((((uint)((int)&unaff_s2->top + 3U) >> 3) + 2) * 2 +
                   ((uint)((int)&unaff_s2->neg + 3U) >> 4) * 5);
            }
            else {
              unaff_s5 = (BIGNUM *)0x1;
              if (uVar9 != 0x32535344) goto LAB_00576cd8;
              auStack_ec._4_4_ = (rsa_st *)((((uint)((int)&unaff_s2->top + 3U) >> 3) + 0x20) * 2);
            }
            prStack_a8 = (rsa_st *)&pBStack_94;
            unaff_s6 = (rsa_st *)0x670000;
            unaff_s4 = (rsa_st *)
                       (**(code **)(auStack_ec._60_4_ + -0x7dd8))
                                 (auStack_ec._4_4_,FUN_0066ce6c,0x11f);
            if (unaff_s4 == (rsa_st *)0x0) {
              auStack_ec._52_4_ = (BN_MONT_CTX *)0x122;
              (**(code **)(auStack_ec._60_4_ + -0x6eb0))(9,0x85,0x41,FUN_0066ce6c);
              prVar7 = (rsa_st *)0x0;
            }
            else {
              prStack_a8 = unaff_s4;
              prVar7 = (rsa_st *)
                       (**(code **)(auStack_ec._60_4_ + -0x7924))
                                 (auStack_ec._16_4_,unaff_s4,auStack_ec._4_4_);
              if (auStack_ec._4_4_ == prVar7) {
                if (unaff_s5 == (BIGNUM *)0x0) {
                  prVar7 = (rsa_st *)b2i_rsa_isra_1(auStack_ec + 0x44,unaff_s2,0);
                }
                else {
                  prVar7 = (rsa_st *)b2i_dss_isra_0();
                }
              }
              else {
                auStack_ec._52_4_ = (BN_MONT_CTX *)0x128;
                prVar7 = (rsa_st *)0x0;
                (**(code **)(auStack_ec._60_4_ + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
              }
              (**(code **)(auStack_ec._60_4_ + -0x7f58))(unaff_s4);
              auStack_ec._4_4_ = prVar7;
            }
            goto LAB_00576a94;
          }
          if (uVar9 != 0x31415352) {
LAB_00576cd8:
            pcVar32 = *(code **)(auStack_ec._60_4_ + -0x6eb0);
            uVar20 = 0x74;
            auStack_ec._52_4_ = (BN_MONT_CTX *)0xcf;
            goto LAB_00576c0c;
          }
        }
        pcVar32 = *(code **)(auStack_ec._60_4_ + -0x6eb0);
        uVar20 = 0x77;
        auStack_ec._52_4_ = (BN_MONT_CTX *)0xbe;
      }
      else {
        pcVar32 = *(code **)(auStack_ec._60_4_ + -0x6eb0);
        uVar20 = 0x75;
        auStack_ec._52_4_ = (BN_MONT_CTX *)0xad;
      }
      goto LAB_00576c0c;
    }
    prVar7 = (rsa_st *)0x0;
  }
  else {
    auStack_ec._52_4_ = (BN_MONT_CTX *)0x117;
    (**(code **)(auStack_ec._60_4_ + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
    prVar7 = (rsa_st *)0x0;
  }
LAB_00576a94:
  if (pBStack_94 == *(BIGNUM **)prVar28) {
    return (EVP_PKEY *)prVar7;
  }
  auStack_ec._32_4_ = b2i_PublicKey_bio;
  pBStack_13c = pBStack_94;
  (**(code **)(auStack_ec._60_4_ + -0x5328))();
  puVar10 = PTR___stack_chk_guard_006aabf0;
  prVar21 = (rsa_st *)&SUB_00000010;
  prVar11 = (rsa_st *)&cStack_fc;
  auStack_ec._8_4_ = (RSA_METHOD *)prVar28;
  auStack_ec._0_4_ = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  prVar7 = prVar11;
  auStack_ec._12_4_ = unaff_s2;
  auStack_ec._20_4_ = unaff_s4;
  auStack_ec._24_4_ = unaff_s5;
  auStack_ec._28_4_ = unaff_s6;
  iVar6 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar6 == 0x10) {
    prStack_100 = prVar11;
    if (cStack_fc == '\x06') {
      if (cStack_fb == '\x02') {
        uVar9 = ((((uint)pRStack_f4 >> 0x10) << 0x18 | ((uint)pRStack_f4 >> 0x18) << 0x10) >> 0x10)
                + (((uint)pRStack_f4 & 0xff) << 8 | (uint)pRStack_f4 >> 8 & 0xff) * 0x10000;
        unaff_s4 = (rsa_st *)
                   (((((uint)pEStack_f0 >> 0x10) << 0x18 | ((uint)pEStack_f0 >> 0x18) << 0x10) >>
                    0x10) + (((uint)pEStack_f0 & 0xff) << 8 | (uint)pEStack_f0 >> 8 & 0xff) *
                            0x10000);
        if (uVar9 == 0x31535344) {
          unaff_s5 = (BIGNUM *)0x1;
          prVar11 = (rsa_st *)(((uint)((int)&unaff_s4->version + 3) >> 3) * 3 + 0x2c);
LAB_00576e9c:
          prStack_100 = (rsa_st *)auStack_ec;
          unaff_s6 = (rsa_st *)0x670000;
          prVar28 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(prVar11,FUN_0066ce6c,0x11f);
          if (prVar28 == (rsa_st *)0x0) {
            prVar21 = (rsa_st *)&DAT_00000041;
            prVar7 = (rsa_st *)0x85;
            (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x41,FUN_0066ce6c);
            prVar8 = (rsa_st *)0x0;
          }
          else {
            prStack_100 = prVar28;
            prVar7 = (rsa_st *)(*(code *)PTR_BIO_read_006a85bc)(pBStack_13c,prVar28,prVar11);
            if (prVar11 == prVar7) {
              prVar21 = (rsa_st *)0x1;
              prVar7 = unaff_s4;
              if (unaff_s5 == (BIGNUM *)0x0) {
                prVar8 = (rsa_st *)b2i_rsa_isra_1(&prStack_100);
              }
              else {
                prVar8 = (rsa_st *)b2i_dss_isra_0();
              }
            }
            else {
              prVar21 = (rsa_st *)0x7b;
              prVar7 = (rsa_st *)0x85;
              prVar8 = (rsa_st *)0x0;
              (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x7b,FUN_0066ce6c);
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(prVar28);
            prVar11 = prVar8;
          }
          goto LAB_00576d94;
        }
        if (uVar9 < 0x31535345) {
          unaff_s5 = (BIGNUM *)0x0;
          if (uVar9 == 0x31415352) {
            prVar11 = (rsa_st *)(((uint)((int)&unaff_s4->version + 3) >> 3) + 4);
            goto LAB_00576e9c;
          }
        }
        else if ((uVar9 == 0x32415352) || (uVar9 == 0x32535344)) {
          prVar21 = (rsa_st *)&DAT_00000078;
          goto LAB_00576e34;
        }
        prVar21 = (rsa_st *)&DAT_00000074;
      }
      else {
        prVar21 = (rsa_st *)0x75;
      }
LAB_00576e34:
      prVar7 = (rsa_st *)0x86;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,prVar21,FUN_0066ce6c);
    }
    else if (cStack_fc == '\a') {
      prVar21 = (rsa_st *)&DAT_00000078;
      goto LAB_00576e34;
    }
    prVar8 = (rsa_st *)0x0;
  }
  else {
    prVar21 = (rsa_st *)0x7b;
    prVar7 = (rsa_st *)0x85;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x7b,FUN_0066ce6c);
    prVar8 = (rsa_st *)0x0;
  }
LAB_00576d94:
  if (auStack_ec._0_4_ == *(BIGNUM **)puVar10) {
    return (EVP_PKEY *)prVar8;
  }
  pBVar18 = auStack_ec._0_4_;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pBStack_140 = (BIGNUM *)puVar10;
  iStack_150 = 0;
  iStack_14c = *(int *)PTR___stack_chk_guard_006aabf0;
  prStack_148 = prVar11;
  prStack_144 = prVar28;
  prStack_138 = unaff_s4;
  pBStack_134 = unaff_s5;
  prStack_130 = unaff_s6;
  if (prVar7->pad == 0x74) {
    prVar11 = ((_union_271 *)&prVar7->e)->rsa;
    puVar10 = (undefined *)(*(code *)PTR_BN_num_bits_006a82f4)(prVar11->engine);
    if ((((((uint)puVar10 & 7) != 0) ||
         (iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar11->n), iVar6 != 0xa0)) ||
        (iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar11->e), (int)puVar10 < iVar6)) ||
       (iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar11->p), 0xa0 < iVar6)) {
      prVar21 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce6c,0x23c);
      goto LAB_0057782c;
    }
    iStack_150 = 0x32535344;
    if (puVar10 == (undefined *)0x0) goto LAB_0057782c;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar6 = (((uint)(puVar10 + 7) >> 3) + 0x20) * 2;
  }
  else {
    prVar8 = (rsa_st *)0xffffffff;
    if (prVar7->pad != 6) goto LAB_00577790;
    prVar21 = (rsa_st *)&iStack_150;
    puVar10 = (undefined *)check_bitlen_rsa(((_union_271 *)&prVar7->e)->ptr,0);
    if (puVar10 == (undefined *)0x0) goto LAB_0057782c;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar6 = (((uint)(puVar10 + 7) >> 3) + 2) * 2 + ((uint)(puVar10 + 0xf) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar8 = (rsa_st *)(iVar6 + 0x10);
  prVar21 = (rsa_st *)0x1ff;
  prVar11 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(prVar8,FUN_0066ce6c);
  prVar28 = prVar8;
  if (prVar11 == (rsa_st *)0x0) goto LAB_0057782c;
  *(undefined *)((int)&prVar11->pad + 2) = 0;
  *(undefined *)((int)&prVar11->pad + 3) = 0;
  *(undefined *)&prVar11->version = 0;
  *(char *)((int)&prVar11->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&prVar11->version + 2) = 0;
  *(undefined *)&prVar11->pad = 7;
  ppBVar29 = &prVar11->n;
  *(undefined *)((int)&prVar11->version + 3) = 0;
  *(char *)&prVar11->engine = (char)puVar10;
  *(undefined *)((int)&prVar11->pad + 1) = 2;
  *(char *)((int)&prVar11->engine + 1) = (char)((uint)puVar10 >> 8);
  *(char *)((int)&prVar11->engine + 2) = (char)((uint)puVar10 >> 0x10);
  *(char *)((int)&prVar11->engine + 3) = (char)((uint)puVar10 >> 0x18);
  *(char *)&prVar11->meth = (char)iStack_150;
  *(char *)((int)&prVar11->meth + 1) = (char)((uint)iStack_150 >> 8);
  *(char *)((int)&prVar11->meth + 2) = (char)((uint)iStack_150 >> 0x10);
  *(char *)((int)&prVar11->meth + 3) = (char)((uint)iStack_150 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar28 = ((_union_271 *)&prVar7->e)->rsa;
    iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar28->engine);
    pEVar22 = prVar28->engine;
    iVar6 = iVar12 + 7;
    if (iVar12 + 7 < 0) {
      iVar6 = iVar12 + 0xe;
    }
    iVar6 = iVar6 >> 3;
    iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(pEVar22);
    iVar26 = iVar25 + 7;
    iVar12 = iVar25 + 0xe;
    if (-1 < iVar26) {
      iVar12 = iVar26;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pEVar22,ppBVar29);
    iVar12 = iVar12 >> 3;
    iVar25 = iVar25 + 0x16;
    if (-1 < iVar26) {
      iVar25 = iVar26;
    }
    if (0 < iVar25 >> 4) {
      ppBVar15 = ppBVar29;
      puVar10 = (undefined *)((int)ppBVar29 + iVar12 + -1);
      do {
        uVar1 = *(undefined *)ppBVar15;
        ppBVar13 = (BIGNUM **)((int)ppBVar15 + 1);
        *(undefined *)ppBVar15 = *puVar10;
        *puVar10 = uVar1;
        ppBVar15 = ppBVar13;
        puVar10 = puVar10 + -1;
      } while ((BIGNUM **)((int)ppBVar29 + (iVar25 >> 4)) != ppBVar13);
    }
    puVar31 = (undefined *)((int)ppBVar29 + iVar12);
    puVar10 = puVar31;
    if ((0 < iVar6) && (0 < iVar6 - iVar12)) {
      puVar10 = puVar31 + (iVar6 - iVar12);
      (*(code *)PTR_memset_006aab00)(puVar31,0);
    }
    pBVar24 = prVar28->n;
    iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar26 = iVar25 + 7;
    iVar12 = iVar25 + 0xe;
    if (-1 < iVar26) {
      iVar12 = iVar26;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar10);
    iVar12 = iVar12 >> 3;
    iVar25 = iVar25 + 0x16;
    if (-1 < iVar26) {
      iVar25 = iVar26;
    }
    if (0 < iVar25 >> 4) {
      puVar31 = puVar10;
      puVar30 = puVar10 + iVar12 + -1;
      do {
        uVar1 = *puVar31;
        puVar16 = puVar31 + 1;
        *puVar31 = *puVar30;
        *puVar30 = uVar1;
        puVar31 = puVar16;
        puVar30 = puVar30 + -1;
      } while (puVar10 + (iVar25 >> 4) != puVar16);
    }
    puVar10 = puVar10 + iVar12;
    puVar31 = puVar10;
    if (0 < 0x14 - iVar12) {
      puVar31 = puVar10 + (0x14 - iVar12);
      (*(code *)PTR_memset_006aab00)(puVar10,0);
    }
    pBVar24 = prVar28->e;
    iVar26 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar25 = iVar26 + 7;
    iVar12 = iVar26 + 0xe;
    if (-1 < iVar25) {
      iVar12 = iVar25;
    }
    iVar12 = iVar12 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
    if (-1 >= iVar25) {
      iVar25 = iVar26 + 0x16;
    }
    if (0 < iVar25 >> 4) {
      puVar10 = puVar31;
      puVar30 = puVar31 + iVar12 + -1;
      do {
        uVar1 = *puVar10;
        puVar16 = puVar10 + 1;
        *puVar10 = *puVar30;
        *puVar30 = uVar1;
        puVar10 = puVar16;
        puVar30 = puVar30 + -1;
      } while (puVar16 != puVar31 + (iVar25 >> 4));
    }
    prVar7 = (rsa_st *)(puVar31 + iVar12);
    unaff_s7 = prVar7;
    if ((0 < iVar6) && (0 < iVar6 - iVar12)) {
      unaff_s7 = (rsa_st *)((int)prVar7 + (iVar6 - iVar12));
      (*(code *)PTR_memset_006aab00)(prVar7,0);
    }
    pBVar24 = prVar28->p;
    iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    prVar28 = (rsa_st *)(iVar6 + 7);
    prVar7 = (rsa_st *)(iVar6 + 0xe);
    if (-1 < (int)prVar28) {
      prVar7 = prVar28;
    }
    unaff_s6 = (rsa_st *)(iVar6 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,unaff_s7);
    if (-1 >= (int)prVar28) {
      prVar28 = unaff_s6;
    }
    prVar7 = (rsa_st *)((int)prVar7 >> 3);
    if (0 < (int)prVar28 >> 4) {
      prVar21 = unaff_s7;
      puVar10 = (undefined *)((int)&prVar7[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar21->pad;
        prVar27 = (rsa_st *)((int)&prVar21->pad + 1);
        *(undefined *)&prVar21->pad = *puVar10;
        *puVar10 = uVar1;
        prVar21 = prVar27;
        puVar10 = puVar10 + -1;
      } while (prVar27 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar28 >> 4)));
    }
    puVar31 = (undefined *)((int)&prVar7->pad + (int)&unaff_s7->pad);
    puVar10 = puVar31;
    if (0 < 0x14 - (int)prVar7) {
      puVar10 = puVar31 + (0x14 - (int)prVar7);
      (*(code *)PTR_memset_006aab00)(puVar31,0);
    }
    prVar21 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006aab00)(puVar10,0xff);
    prVar27 = prVar11;
    goto LAB_00577758;
  }
  unaff_s6 = ((_union_271 *)&prVar7->e)->rsa;
  iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s6->n);
  iVar6 = iVar12 + 7;
  if (iVar12 + 7 < 0) {
    iVar6 = iVar12 + 0xe;
  }
  prVar7 = (rsa_st *)(iVar6 >> 3);
  iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s6->n);
  pBVar24 = unaff_s6->e;
  puVar10 = (undefined *)(iVar6 + 0xf >> 4);
  iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
  iVar25 = iVar12 + 7;
  iVar6 = iVar12 + 0xe;
  if (-1 < iVar25) {
    iVar6 = iVar25;
  }
  iVar6 = iVar6 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,ppBVar29);
  iVar12 = iVar12 + 0x16;
  if (-1 < iVar25) {
    iVar12 = iVar25;
  }
  if (0 < iVar12 >> 4) {
    ppBVar15 = ppBVar29;
    puVar31 = (undefined *)((int)ppBVar29 + iVar6 + -1);
    do {
      uVar1 = *(undefined *)ppBVar15;
      ppBVar13 = (BIGNUM **)((int)ppBVar15 + 1);
      *(undefined *)ppBVar15 = *puVar31;
      *puVar31 = uVar1;
      ppBVar15 = ppBVar13;
      puVar31 = puVar31 + -1;
    } while ((BIGNUM **)((int)ppBVar29 + (iVar12 >> 4)) != ppBVar13);
  }
  puVar30 = (undefined *)((int)ppBVar29 + iVar6);
  puVar31 = puVar30;
  if (0 < 4 - iVar6) {
    puVar31 = puVar30 + (4 - iVar6);
    (*(code *)PTR_memset_006aab00)(puVar30,0);
  }
  pBVar24 = unaff_s6->n;
  iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
  iVar12 = iVar25 + 7;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
  iVar6 = iVar12;
  if (iVar12 < 0) {
    iVar12 = iVar25 + 0x16;
    iVar6 = iVar25 + 0xe;
  }
  if (0 < iVar12 >> 4) {
    puVar30 = puVar31;
    puVar16 = puVar31 + (iVar6 >> 3) + -1;
    do {
      uVar1 = *puVar30;
      puVar14 = puVar30 + 1;
      *puVar30 = *puVar16;
      *puVar16 = uVar1;
      puVar30 = puVar14;
      puVar16 = puVar16 + -1;
    } while (puVar14 != puVar31 + (iVar12 >> 4));
  }
  pBVar24 = unaff_s6->p;
  puVar31 = puVar31 + (iVar6 >> 3);
  iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
  iVar25 = iVar12 + 7;
  iVar6 = iVar12 + 0xe;
  if (-1 < iVar25) {
    iVar6 = iVar25;
  }
  iVar6 = iVar6 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
  iVar12 = iVar12 + 0x16;
  if (-1 < iVar25) {
    iVar12 = iVar25;
  }
  if (0 < iVar12 >> 4) {
    puVar30 = puVar31;
    puVar16 = puVar31 + iVar6 + -1;
    do {
      uVar1 = *puVar30;
      puVar14 = puVar30 + 1;
      *puVar30 = *puVar16;
      *puVar16 = uVar1;
      puVar30 = puVar14;
      puVar16 = puVar16 + -1;
    } while (puVar31 + (iVar12 >> 4) != puVar14);
  }
  puVar31 = puVar31 + iVar6;
  if ((int)puVar10 < 1) {
    pBVar24 = unaff_s6->q;
    iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar25 = iVar12 + 7;
    iVar6 = iVar12 + 0xe;
    if (-1 < iVar25) {
      iVar6 = iVar25;
    }
    iVar6 = iVar6 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
    iVar12 = iVar12 + 0x16;
    if (-1 < iVar25) {
      iVar12 = iVar25;
    }
    iVar12 = iVar12 >> 4;
    puVar30 = puVar31 + iVar6 + -1;
    if (0 < iVar12) goto LAB_0057740c;
    puVar31 = puVar31 + iVar6;
LAB_00577bcc:
    pBVar24 = unaff_s6->dmp1;
    iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar25 = iVar12 + 7;
    iVar6 = iVar12 + 0xe;
    if (-1 < iVar25) {
      iVar6 = iVar25;
    }
    iVar6 = iVar6 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
    iVar12 = iVar12 + 0x16;
    if (-1 < iVar25) {
      iVar12 = iVar25;
    }
    iVar12 = iVar12 >> 4;
    puVar30 = puVar31 + iVar6 + -1;
    if (0 < iVar12) goto LAB_005774d0;
    puVar31 = puVar31 + iVar6;
LAB_00577c44:
    pBVar24 = unaff_s6->dmq1;
    iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar6 = iVar25 + 7;
    iVar12 = iVar25 + 0xe;
    if (-1 < iVar6) {
      iVar12 = iVar6;
    }
    iVar12 = iVar12 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
    if (-1 >= iVar6) {
      iVar6 = iVar25 + 0x16;
    }
    iVar6 = iVar6 >> 4;
    puVar30 = puVar31 + iVar12 + -1;
    if (0 < iVar6) goto LAB_00577594;
LAB_005775b8:
    unaff_s7 = (rsa_st *)(puVar31 + iVar12);
    if ((int)puVar10 < 1) {
      pBVar24 = unaff_s6->iqmp;
      iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
      iVar12 = iVar25 + 7;
      iVar6 = iVar25 + 0xe;
      if (-1 < iVar12) {
        iVar6 = iVar12;
      }
      prVar21 = (rsa_st *)(iVar6 >> 3);
      (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,unaff_s7);
      if (-1 >= iVar12) {
        iVar12 = iVar25 + 0x16;
      }
      iVar12 = iVar12 >> 4;
      puVar31 = (undefined *)((int)&prVar21[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar12 < 1) {
        unaff_s7 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
        goto LAB_005776a4;
      }
      goto LAB_00577658;
    }
  }
  else {
    iVar6 = (int)puVar10 - iVar6;
    if (0 < iVar6) {
      (*(code *)PTR_memset_006aab00)(puVar31,0,iVar6);
      puVar31 = puVar31 + iVar6;
    }
    pBVar24 = unaff_s6->q;
    iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar25 = iVar12 + 7;
    iVar6 = iVar12 + 0xe;
    if (-1 < iVar25) {
      iVar6 = iVar25;
    }
    iVar6 = iVar6 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
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
LAB_0057740c:
      puVar16 = puVar31;
      do {
        uVar1 = *puVar16;
        puVar14 = puVar16 + 1;
        *puVar16 = *puVar30;
        *puVar30 = uVar1;
        puVar16 = puVar14;
        puVar30 = puVar30 + -1;
      } while (puVar31 + iVar12 != puVar14);
      puVar31 = puVar31 + iVar6;
      if ((int)puVar10 < 1) goto LAB_00577bcc;
    }
    iVar6 = (int)puVar10 - iVar6;
    if (0 < iVar6) {
      (*(code *)PTR_memset_006aab00)(puVar31,0,iVar6);
      puVar31 = puVar31 + iVar6;
    }
    pBVar24 = unaff_s6->dmp1;
    iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar25 = iVar12 + 7;
    iVar6 = iVar12 + 0xe;
    if (-1 < iVar25) {
      iVar6 = iVar25;
    }
    iVar6 = iVar6 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
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
LAB_005774d0:
      puVar16 = puVar31;
      do {
        uVar1 = *puVar16;
        puVar14 = puVar16 + 1;
        *puVar16 = *puVar30;
        *puVar30 = uVar1;
        puVar16 = puVar14;
        puVar30 = puVar30 + -1;
      } while (puVar31 + iVar12 != puVar14);
      puVar31 = puVar31 + iVar6;
      if ((int)puVar10 < 1) goto LAB_00577c44;
    }
    iVar6 = (int)puVar10 - iVar6;
    if (0 < iVar6) {
      (*(code *)PTR_memset_006aab00)(puVar31,0,iVar6);
      puVar31 = puVar31 + iVar6;
    }
    pBVar24 = unaff_s6->dmq1;
    iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar6 = iVar25 + 7;
    iVar12 = iVar25 + 0xe;
    if (-1 < iVar6) {
      iVar12 = iVar6;
    }
    iVar12 = iVar12 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,puVar31);
    if (-1 >= iVar6) {
      iVar6 = iVar25 + 0x16;
    }
    iVar6 = iVar6 >> 4;
    puVar30 = puVar31 + iVar12 + -1;
    if (0 < iVar6) {
LAB_00577594:
      puVar16 = puVar31;
      do {
        uVar1 = *puVar16;
        puVar14 = puVar16 + 1;
        *puVar16 = *puVar30;
        *puVar30 = uVar1;
        puVar30 = puVar30 + -1;
        puVar16 = puVar14;
      } while (puVar31 + iVar6 != puVar14);
      goto LAB_005775b8;
    }
    unaff_s7 = (rsa_st *)(puVar31 + iVar12);
  }
  iVar12 = (int)puVar10 - iVar12;
  if (0 < iVar12) {
    (*(code *)PTR_memset_006aab00)(unaff_s7,0,iVar12);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar12);
  }
  pBVar24 = unaff_s6->iqmp;
  iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
  iVar12 = iVar25 + 7;
  iVar6 = iVar25 + 0xe;
  if (-1 < iVar12) {
    iVar6 = iVar12;
  }
  prVar21 = (rsa_st *)(iVar6 >> 3);
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,unaff_s7);
  if (-1 >= iVar12) {
    iVar12 = iVar25 + 0x16;
  }
  iVar12 = iVar12 >> 4;
  puVar31 = (undefined *)((int)&prVar21[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar12 < 1) goto LAB_00577dbc;
LAB_00577658:
  prVar28 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar28->pad;
    prVar27 = (rsa_st *)((int)&prVar28->pad + 1);
    *(undefined *)&prVar28->pad = *puVar31;
    *puVar31 = uVar1;
    puVar31 = puVar31 + -1;
    prVar28 = prVar27;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar12) != prVar27);
  prVar28 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar28;
  if ((int)puVar10 < 1) goto LAB_005776a4;
  do {
    unaff_s7 = prVar28;
    if (0 < (int)puVar10 - (int)prVar21) {
      unaff_s7 = (rsa_st *)((int)prVar28 + ((int)puVar10 - (int)prVar21));
      (*(code *)PTR_memset_006aab00)(prVar28,0);
    }
LAB_005776a4:
    pBVar24 = unaff_s6->d;
    iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar24);
    iVar6 = iVar25 + 7;
    puVar10 = (undefined *)(uint)(iVar6 < 0);
    iVar12 = iVar25 + 0xe;
    if (puVar10 == (undefined *)0x0) {
      iVar12 = iVar6;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar24,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar12 >> 3);
    if (puVar10 != (undefined *)0x0) {
      iVar6 = iVar25 + 0x16;
    }
    prVar21 = (rsa_st *)(iVar6 >> 4);
    if (0 < (int)prVar21) {
      prVar21 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
      puVar31 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar28 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar28->pad;
        prVar27 = (rsa_st *)((int)&prVar28->pad + 1);
        *(undefined *)&prVar28->pad = *puVar31;
        *puVar31 = uVar1;
        puVar31 = puVar31 + -1;
        prVar28 = prVar27;
      } while (prVar21 != prVar27);
    }
    prVar27 = prVar11;
    if ((0 < (int)prVar7) && (prVar21 = (rsa_st *)((int)prVar7 - (int)unaff_s6), 0 < (int)prVar21))
    {
      (*(code *)PTR_memset_006aab00)((char *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00577758:
    prVar11 = prVar27;
    prVar28 = prVar8;
    if ((int)prVar8 < 0) {
LAB_0057782c:
      prVar8 = (rsa_st *)0xffffffff;
    }
    else {
      prVar21 = prVar8;
      prVar11 = (rsa_st *)(*(code *)PTR_BIO_write_006a7f14)(pBVar18,prVar27);
      (*(code *)PTR_CRYPTO_free_006a7f88)(prVar27);
      if (prVar11 != prVar8) goto LAB_0057782c;
    }
LAB_00577790:
    if (iStack_14c == *(int *)puVar2) {
      return (EVP_PKEY *)prVar8;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    prVar8 = prVar28;
LAB_00577dbc:
    prVar28 = (rsa_st *)((int)&prVar21->pad + (int)&unaff_s7->pad);
  } while( true );
}

