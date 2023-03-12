
EVP_PKEY * b2i_PublicKey(uchar **in,long length)

{
  undefined uVar1;
  undefined *puVar2;
  BN_MONT_CTX *pBVar3;
  EVP_PKEY *pEVar4;
  int iVar5;
  rsa_st *prVar6;
  rsa_st *prVar7;
  uint uVar8;
  undefined *puVar9;
  rsa_st *prVar10;
  int iVar11;
  BIGNUM **ppBVar12;
  undefined *puVar13;
  BIGNUM **ppBVar14;
  undefined *puVar15;
  BIGNUM *pBVar16;
  undefined4 uVar17;
  rsa_st *prVar18;
  ENGINE *pEVar19;
  uint uVar20;
  BIGNUM *pBVar21;
  int iVar22;
  int iVar23;
  rsa_st *prVar24;
  RSA_METHOD *unaff_s1;
  BIGNUM *unaff_s2;
  rsa_st *prVar25;
  rsa_st *unaff_s4;
  BIGNUM *unaff_s5;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar26;
  undefined *puVar27;
  undefined *puVar28;
  code *pcVar29;
  int iStack_118;
  int iStack_114;
  rsa_st *prStack_110;
  rsa_st *prStack_10c;
  BIGNUM *pBStack_108;
  BIGNUM *pBStack_104;
  rsa_st *prStack_100;
  BIGNUM *pBStack_fc;
  rsa_st *prStack_f8;
  rsa_st *prStack_c8;
  char cStack_c4;
  char cStack_c3;
  RSA_METHOD *pRStack_bc;
  ENGINE *pEStack_b8;
  undefined auStack_b4 [68];
  rsa_st *prStack_70;
  char cStack_6c;
  char cStack_6b;
  BN_BLINDING *pBStack_64;
  BN_BLINDING *pBStack_60;
  BIGNUM *pBStack_5c;
  undefined *puStack_58;
  RSA_METHOD *pRStack_54;
  BN_MONT_CTX *local_18;
  BN_MONT_CTX *local_14;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  pBVar3 = (BN_MONT_CTX *)*in;
  local_14 = *(BN_MONT_CTX **)PTR___stack_chk_guard_006aabf0;
  local_18 = pBVar3;
  if ((uint)length < 0x10) {
LAB_0057680c:
    unaff_s1 = (RSA_METHOD *)0x670000;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7a,FUN_0066ce6c);
    pEVar4 = (EVP_PKEY *)0x0;
  }
  else {
    if (*(uchar *)&pBVar3->ri != '\x06') {
      if (*(uchar *)&pBVar3->ri == '\a') {
        uVar17 = 0x78;
        goto LAB_00576914;
      }
      goto LAB_0057680c;
    }
    if (*(uchar *)((int)&pBVar3->ri + 1) != '\x02') {
      uVar17 = 0x75;
LAB_00576914:
      local_18 = pBVar3;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,uVar17,FUN_0066ce6c);
      goto LAB_0057680c;
    }
    local_18 = (BN_MONT_CTX *)&(pBVar3->RR).neg;
    uVar8 = (uint)*(byte *)((int)&(pBVar3->RR).top + 1) << 8 |
            (uint)*(byte *)((int)&(pBVar3->RR).top + 2) << 0x10 | (uint)*(byte *)&(pBVar3->RR).top |
            (uint)*(byte *)((int)&(pBVar3->RR).top + 3) << 0x18;
    uVar20 = (uint)*(byte *)((int)&(pBVar3->RR).dmax + 1) << 8 |
             (uint)*(byte *)((int)&(pBVar3->RR).dmax + 2) << 0x10 |
             (uint)*(byte *)&(pBVar3->RR).dmax |
             (uint)*(byte *)((int)&(pBVar3->RR).dmax + 3) << 0x18;
    if (uVar8 != 0x31535344) {
      if (uVar8 < 0x31535345) {
        if (uVar8 == 0x31415352) {
          if (length - 0x10U < (uVar20 + 7 >> 3) + 4) goto LAB_005769d4;
          pEVar4 = (EVP_PKEY *)b2i_rsa_isra_1(&local_18,uVar20,1);
          goto LAB_00576834;
        }
      }
      else if ((uVar8 == 0x32415352) || (uVar8 == 0x32535344)) {
        uVar17 = 0x78;
        goto LAB_00576914;
      }
      uVar17 = 0x74;
      goto LAB_00576914;
    }
    if (length - 0x10U < (uVar20 + 7 >> 3) * 3 + 0x2c) {
LAB_005769d4:
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7b,FUN_0066ce6c);
      pEVar4 = (EVP_PKEY *)0x0;
    }
    else {
      pEVar4 = (EVP_PKEY *)b2i_dss_isra_0(&local_18,uVar20,1);
    }
  }
LAB_00576834:
  if (local_14 == *(BN_MONT_CTX **)puStack_58) {
    return pEVar4;
  }
  auStack_b4._16_4_ = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  prVar25 = (rsa_st *)PTR___stack_chk_guard_006aabf0;
  auStack_b4._4_4_ = (rsa_st *)(auStack_b4 + 0x48);
  auStack_b4._60_4_ = &_gp;
  pBStack_5c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  pRStack_54 = unaff_s1;
  iVar5 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar5 == 0x10) {
    prStack_70 = auStack_b4._4_4_;
    if (cStack_6c == '\x06') {
      pcVar29 = *(code **)(auStack_b4._60_4_ + -0x6eb0);
      uVar17 = 0x77;
      auStack_b4._52_4_ = (BN_MONT_CTX *)&DAT_00000098;
LAB_00576c0c:
      (*pcVar29)(9,0x86,uVar17,FUN_0066ce6c);
    }
    else if (cStack_6c == '\a') {
      if (cStack_6b == '\x02') {
        uVar8 = ((((uint)pBStack_64 >> 0x10) << 0x18 | ((uint)pBStack_64 >> 0x18) << 0x10) >> 0x10)
                + (((uint)pBStack_64 & 0xff) << 8 | (uint)pBStack_64 >> 8 & 0xff) * 0x10000;
        unaff_s2 = (BIGNUM *)
                   (((((uint)pBStack_60 >> 0x10) << 0x18 | ((uint)pBStack_60 >> 0x18) << 0x10) >>
                    0x10) + (((uint)pBStack_60 & 0xff) << 8 | (uint)pBStack_60 >> 8 & 0xff) *
                            0x10000);
        if (uVar8 != 0x31535344) {
          if (0x31535344 < uVar8) {
            if (uVar8 == 0x32415352) {
              unaff_s5 = (BIGNUM *)0x0;
              auStack_b4._4_4_ =
                   (rsa_st *)
                   ((((uint)((int)&unaff_s2->top + 3U) >> 3) + 2) * 2 +
                   ((uint)((int)&unaff_s2->neg + 3U) >> 4) * 5);
            }
            else {
              unaff_s5 = (BIGNUM *)0x1;
              if (uVar8 != 0x32535344) goto LAB_00576cd8;
              auStack_b4._4_4_ = (rsa_st *)((((uint)((int)&unaff_s2->top + 3U) >> 3) + 0x20) * 2);
            }
            prStack_70 = (rsa_st *)&pBStack_5c;
            unaff_s6 = (rsa_st *)0x670000;
            unaff_s4 = (rsa_st *)
                       (**(code **)(auStack_b4._60_4_ + -0x7dd8))
                                 (auStack_b4._4_4_,FUN_0066ce6c,0x11f);
            if (unaff_s4 == (rsa_st *)0x0) {
              auStack_b4._52_4_ = (BN_MONT_CTX *)0x122;
              (**(code **)(auStack_b4._60_4_ + -0x6eb0))(9,0x85,0x41,FUN_0066ce6c);
              prVar6 = (rsa_st *)0x0;
            }
            else {
              prStack_70 = unaff_s4;
              prVar6 = (rsa_st *)
                       (**(code **)(auStack_b4._60_4_ + -0x7924))
                                 (auStack_b4._16_4_,unaff_s4,auStack_b4._4_4_);
              if (auStack_b4._4_4_ == prVar6) {
                if (unaff_s5 == (BIGNUM *)0x0) {
                  prVar6 = (rsa_st *)b2i_rsa_isra_1(auStack_b4 + 0x44,unaff_s2,0);
                }
                else {
                  prVar6 = (rsa_st *)b2i_dss_isra_0();
                }
              }
              else {
                auStack_b4._52_4_ = (BN_MONT_CTX *)0x128;
                prVar6 = (rsa_st *)0x0;
                (**(code **)(auStack_b4._60_4_ + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
              }
              (**(code **)(auStack_b4._60_4_ + -0x7f58))(unaff_s4);
              auStack_b4._4_4_ = prVar6;
            }
            goto LAB_00576a94;
          }
          if (uVar8 != 0x31415352) {
LAB_00576cd8:
            pcVar29 = *(code **)(auStack_b4._60_4_ + -0x6eb0);
            uVar17 = 0x74;
            auStack_b4._52_4_ = (BN_MONT_CTX *)0xcf;
            goto LAB_00576c0c;
          }
        }
        pcVar29 = *(code **)(auStack_b4._60_4_ + -0x6eb0);
        uVar17 = 0x77;
        auStack_b4._52_4_ = (BN_MONT_CTX *)0xbe;
      }
      else {
        pcVar29 = *(code **)(auStack_b4._60_4_ + -0x6eb0);
        uVar17 = 0x75;
        auStack_b4._52_4_ = (BN_MONT_CTX *)0xad;
      }
      goto LAB_00576c0c;
    }
    prVar6 = (rsa_st *)0x0;
  }
  else {
    auStack_b4._52_4_ = (BN_MONT_CTX *)0x117;
    (**(code **)(auStack_b4._60_4_ + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
    prVar6 = (rsa_st *)0x0;
  }
LAB_00576a94:
  if (pBStack_5c == *(BIGNUM **)prVar25) {
    return (EVP_PKEY *)prVar6;
  }
  auStack_b4._32_4_ = b2i_PublicKey_bio;
  pBStack_104 = pBStack_5c;
  (**(code **)(auStack_b4._60_4_ + -0x5328))();
  puVar9 = PTR___stack_chk_guard_006aabf0;
  prVar18 = (rsa_st *)&SUB_00000010;
  prVar10 = (rsa_st *)&cStack_c4;
  auStack_b4._8_4_ = (RSA_METHOD *)prVar25;
  auStack_b4._0_4_ = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  prVar6 = prVar10;
  auStack_b4._12_4_ = unaff_s2;
  auStack_b4._20_4_ = unaff_s4;
  auStack_b4._24_4_ = unaff_s5;
  auStack_b4._28_4_ = unaff_s6;
  iVar5 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar5 == 0x10) {
    prStack_c8 = prVar10;
    if (cStack_c4 == '\x06') {
      if (cStack_c3 == '\x02') {
        uVar8 = ((((uint)pRStack_bc >> 0x10) << 0x18 | ((uint)pRStack_bc >> 0x18) << 0x10) >> 0x10)
                + (((uint)pRStack_bc & 0xff) << 8 | (uint)pRStack_bc >> 8 & 0xff) * 0x10000;
        unaff_s4 = (rsa_st *)
                   (((((uint)pEStack_b8 >> 0x10) << 0x18 | ((uint)pEStack_b8 >> 0x18) << 0x10) >>
                    0x10) + (((uint)pEStack_b8 & 0xff) << 8 | (uint)pEStack_b8 >> 8 & 0xff) *
                            0x10000);
        if (uVar8 == 0x31535344) {
          unaff_s5 = (BIGNUM *)0x1;
          prVar10 = (rsa_st *)(((uint)((int)&unaff_s4->version + 3) >> 3) * 3 + 0x2c);
LAB_00576e9c:
          prStack_c8 = (rsa_st *)auStack_b4;
          unaff_s6 = (rsa_st *)0x670000;
          prVar25 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(prVar10,FUN_0066ce6c,0x11f);
          if (prVar25 == (rsa_st *)0x0) {
            prVar18 = (rsa_st *)&DAT_00000041;
            prVar6 = (rsa_st *)0x85;
            (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x41,FUN_0066ce6c);
            prVar7 = (rsa_st *)0x0;
          }
          else {
            prStack_c8 = prVar25;
            prVar6 = (rsa_st *)(*(code *)PTR_BIO_read_006a85bc)(pBStack_104,prVar25,prVar10);
            if (prVar10 == prVar6) {
              prVar18 = (rsa_st *)0x1;
              prVar6 = unaff_s4;
              if (unaff_s5 == (BIGNUM *)0x0) {
                prVar7 = (rsa_st *)b2i_rsa_isra_1(&prStack_c8);
              }
              else {
                prVar7 = (rsa_st *)b2i_dss_isra_0();
              }
            }
            else {
              prVar18 = (rsa_st *)0x7b;
              prVar6 = (rsa_st *)0x85;
              prVar7 = (rsa_st *)0x0;
              (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x7b,FUN_0066ce6c);
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(prVar25);
            prVar10 = prVar7;
          }
          goto LAB_00576d94;
        }
        if (uVar8 < 0x31535345) {
          unaff_s5 = (BIGNUM *)0x0;
          if (uVar8 == 0x31415352) {
            prVar10 = (rsa_st *)(((uint)((int)&unaff_s4->version + 3) >> 3) + 4);
            goto LAB_00576e9c;
          }
        }
        else if ((uVar8 == 0x32415352) || (uVar8 == 0x32535344)) {
          prVar18 = (rsa_st *)&DAT_00000078;
          goto LAB_00576e34;
        }
        prVar18 = (rsa_st *)&DAT_00000074;
      }
      else {
        prVar18 = (rsa_st *)0x75;
      }
LAB_00576e34:
      prVar6 = (rsa_st *)0x86;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,prVar18,FUN_0066ce6c);
    }
    else if (cStack_c4 == '\a') {
      prVar18 = (rsa_st *)&DAT_00000078;
      goto LAB_00576e34;
    }
    prVar7 = (rsa_st *)0x0;
  }
  else {
    prVar18 = (rsa_st *)0x7b;
    prVar6 = (rsa_st *)0x85;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x7b,FUN_0066ce6c);
    prVar7 = (rsa_st *)0x0;
  }
LAB_00576d94:
  if (auStack_b4._0_4_ == *(BIGNUM **)puVar9) {
    return (EVP_PKEY *)prVar7;
  }
  pBVar16 = auStack_b4._0_4_;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pBStack_108 = (BIGNUM *)puVar9;
  iStack_118 = 0;
  iStack_114 = *(int *)PTR___stack_chk_guard_006aabf0;
  prStack_110 = prVar10;
  prStack_10c = prVar25;
  prStack_100 = unaff_s4;
  pBStack_fc = unaff_s5;
  prStack_f8 = unaff_s6;
  if (prVar6->pad == 0x74) {
    prVar10 = ((_union_271 *)&prVar6->e)->rsa;
    puVar9 = (undefined *)(*(code *)PTR_BN_num_bits_006a82f4)(prVar10->engine);
    if ((((((uint)puVar9 & 7) != 0) ||
         (iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->n), iVar5 != 0xa0)) ||
        (iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->e), (int)puVar9 < iVar5)) ||
       (iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->p), 0xa0 < iVar5)) {
      prVar18 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce6c,0x23c);
      goto LAB_0057782c;
    }
    iStack_118 = 0x32535344;
    if (puVar9 == (undefined *)0x0) goto LAB_0057782c;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar5 = (((uint)(puVar9 + 7) >> 3) + 0x20) * 2;
  }
  else {
    prVar7 = (rsa_st *)0xffffffff;
    if (prVar6->pad != 6) goto LAB_00577790;
    prVar18 = (rsa_st *)&iStack_118;
    puVar9 = (undefined *)check_bitlen_rsa(((_union_271 *)&prVar6->e)->ptr,0);
    if (puVar9 == (undefined *)0x0) goto LAB_0057782c;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar5 = (((uint)(puVar9 + 7) >> 3) + 2) * 2 + ((uint)(puVar9 + 0xf) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar7 = (rsa_st *)(iVar5 + 0x10);
  prVar18 = (rsa_st *)0x1ff;
  prVar10 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(prVar7,FUN_0066ce6c);
  prVar25 = prVar7;
  if (prVar10 == (rsa_st *)0x0) goto LAB_0057782c;
  *(undefined *)((int)&prVar10->pad + 2) = 0;
  *(undefined *)((int)&prVar10->pad + 3) = 0;
  *(undefined *)&prVar10->version = 0;
  *(char *)((int)&prVar10->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&prVar10->version + 2) = 0;
  *(undefined *)&prVar10->pad = 7;
  ppBVar26 = &prVar10->n;
  *(undefined *)((int)&prVar10->version + 3) = 0;
  *(char *)&prVar10->engine = (char)puVar9;
  *(undefined *)((int)&prVar10->pad + 1) = 2;
  *(char *)((int)&prVar10->engine + 1) = (char)((uint)puVar9 >> 8);
  *(char *)((int)&prVar10->engine + 2) = (char)((uint)puVar9 >> 0x10);
  *(char *)((int)&prVar10->engine + 3) = (char)((uint)puVar9 >> 0x18);
  *(char *)&prVar10->meth = (char)iStack_118;
  *(char *)((int)&prVar10->meth + 1) = (char)((uint)iStack_118 >> 8);
  *(char *)((int)&prVar10->meth + 2) = (char)((uint)iStack_118 >> 0x10);
  *(char *)((int)&prVar10->meth + 3) = (char)((uint)iStack_118 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar25 = ((_union_271 *)&prVar6->e)->rsa;
    iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar25->engine);
    pEVar19 = prVar25->engine;
    iVar5 = iVar11 + 7;
    if (iVar11 + 7 < 0) {
      iVar5 = iVar11 + 0xe;
    }
    iVar5 = iVar5 >> 3;
    iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(pEVar19);
    iVar23 = iVar22 + 7;
    iVar11 = iVar22 + 0xe;
    if (-1 < iVar23) {
      iVar11 = iVar23;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pEVar19,ppBVar26);
    iVar11 = iVar11 >> 3;
    iVar22 = iVar22 + 0x16;
    if (-1 < iVar23) {
      iVar22 = iVar23;
    }
    if (0 < iVar22 >> 4) {
      ppBVar14 = ppBVar26;
      puVar9 = (undefined *)((int)ppBVar26 + iVar11 + -1);
      do {
        uVar1 = *(undefined *)ppBVar14;
        ppBVar12 = (BIGNUM **)((int)ppBVar14 + 1);
        *(undefined *)ppBVar14 = *puVar9;
        *puVar9 = uVar1;
        ppBVar14 = ppBVar12;
        puVar9 = puVar9 + -1;
      } while ((BIGNUM **)((int)ppBVar26 + (iVar22 >> 4)) != ppBVar12);
    }
    puVar28 = (undefined *)((int)ppBVar26 + iVar11);
    puVar9 = puVar28;
    if ((0 < iVar5) && (0 < iVar5 - iVar11)) {
      puVar9 = puVar28 + (iVar5 - iVar11);
      (*(code *)PTR_memset_006aab00)(puVar28,0);
    }
    pBVar21 = prVar25->n;
    iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar23 = iVar22 + 7;
    iVar11 = iVar22 + 0xe;
    if (-1 < iVar23) {
      iVar11 = iVar23;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar9);
    iVar11 = iVar11 >> 3;
    iVar22 = iVar22 + 0x16;
    if (-1 < iVar23) {
      iVar22 = iVar23;
    }
    if (0 < iVar22 >> 4) {
      puVar28 = puVar9;
      puVar27 = puVar9 + iVar11 + -1;
      do {
        uVar1 = *puVar28;
        puVar15 = puVar28 + 1;
        *puVar28 = *puVar27;
        *puVar27 = uVar1;
        puVar28 = puVar15;
        puVar27 = puVar27 + -1;
      } while (puVar9 + (iVar22 >> 4) != puVar15);
    }
    puVar9 = puVar9 + iVar11;
    puVar28 = puVar9;
    if (0 < 0x14 - iVar11) {
      puVar28 = puVar9 + (0x14 - iVar11);
      (*(code *)PTR_memset_006aab00)(puVar9,0);
    }
    pBVar21 = prVar25->e;
    iVar23 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar22 = iVar23 + 7;
    iVar11 = iVar23 + 0xe;
    if (-1 < iVar22) {
      iVar11 = iVar22;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
    if (-1 >= iVar22) {
      iVar22 = iVar23 + 0x16;
    }
    if (0 < iVar22 >> 4) {
      puVar9 = puVar28;
      puVar27 = puVar28 + iVar11 + -1;
      do {
        uVar1 = *puVar9;
        puVar15 = puVar9 + 1;
        *puVar9 = *puVar27;
        *puVar27 = uVar1;
        puVar9 = puVar15;
        puVar27 = puVar27 + -1;
      } while (puVar15 != puVar28 + (iVar22 >> 4));
    }
    prVar6 = (rsa_st *)(puVar28 + iVar11);
    unaff_s7 = prVar6;
    if ((0 < iVar5) && (0 < iVar5 - iVar11)) {
      unaff_s7 = (rsa_st *)((int)prVar6 + (iVar5 - iVar11));
      (*(code *)PTR_memset_006aab00)(prVar6,0);
    }
    pBVar21 = prVar25->p;
    iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    prVar25 = (rsa_st *)(iVar5 + 7);
    prVar6 = (rsa_st *)(iVar5 + 0xe);
    if (-1 < (int)prVar25) {
      prVar6 = prVar25;
    }
    unaff_s6 = (rsa_st *)(iVar5 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,unaff_s7);
    if (-1 >= (int)prVar25) {
      prVar25 = unaff_s6;
    }
    prVar6 = (rsa_st *)((int)prVar6 >> 3);
    if (0 < (int)prVar25 >> 4) {
      prVar18 = unaff_s7;
      puVar9 = (undefined *)((int)&prVar6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar18->pad;
        prVar24 = (rsa_st *)((int)&prVar18->pad + 1);
        *(undefined *)&prVar18->pad = *puVar9;
        *puVar9 = uVar1;
        prVar18 = prVar24;
        puVar9 = puVar9 + -1;
      } while (prVar24 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar25 >> 4)));
    }
    puVar28 = (undefined *)((int)&prVar6->pad + (int)&unaff_s7->pad);
    puVar9 = puVar28;
    if (0 < 0x14 - (int)prVar6) {
      puVar9 = puVar28 + (0x14 - (int)prVar6);
      (*(code *)PTR_memset_006aab00)(puVar28,0);
    }
    prVar18 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006aab00)(puVar9,0xff);
    prVar24 = prVar10;
    goto LAB_00577758;
  }
  unaff_s6 = ((_union_271 *)&prVar6->e)->rsa;
  iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s6->n);
  iVar5 = iVar11 + 7;
  if (iVar11 + 7 < 0) {
    iVar5 = iVar11 + 0xe;
  }
  prVar6 = (rsa_st *)(iVar5 >> 3);
  iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s6->n);
  pBVar21 = unaff_s6->e;
  puVar9 = (undefined *)(iVar5 + 0xf >> 4);
  iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
  iVar22 = iVar11 + 7;
  iVar5 = iVar11 + 0xe;
  if (-1 < iVar22) {
    iVar5 = iVar22;
  }
  iVar5 = iVar5 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,ppBVar26);
  iVar11 = iVar11 + 0x16;
  if (-1 < iVar22) {
    iVar11 = iVar22;
  }
  if (0 < iVar11 >> 4) {
    ppBVar14 = ppBVar26;
    puVar28 = (undefined *)((int)ppBVar26 + iVar5 + -1);
    do {
      uVar1 = *(undefined *)ppBVar14;
      ppBVar12 = (BIGNUM **)((int)ppBVar14 + 1);
      *(undefined *)ppBVar14 = *puVar28;
      *puVar28 = uVar1;
      ppBVar14 = ppBVar12;
      puVar28 = puVar28 + -1;
    } while ((BIGNUM **)((int)ppBVar26 + (iVar11 >> 4)) != ppBVar12);
  }
  puVar27 = (undefined *)((int)ppBVar26 + iVar5);
  puVar28 = puVar27;
  if (0 < 4 - iVar5) {
    puVar28 = puVar27 + (4 - iVar5);
    (*(code *)PTR_memset_006aab00)(puVar27,0);
  }
  pBVar21 = unaff_s6->n;
  iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
  iVar11 = iVar22 + 7;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
  iVar5 = iVar11;
  if (iVar11 < 0) {
    iVar11 = iVar22 + 0x16;
    iVar5 = iVar22 + 0xe;
  }
  if (0 < iVar11 >> 4) {
    puVar27 = puVar28;
    puVar15 = puVar28 + (iVar5 >> 3) + -1;
    do {
      uVar1 = *puVar27;
      puVar13 = puVar27 + 1;
      *puVar27 = *puVar15;
      *puVar15 = uVar1;
      puVar27 = puVar13;
      puVar15 = puVar15 + -1;
    } while (puVar13 != puVar28 + (iVar11 >> 4));
  }
  pBVar21 = unaff_s6->p;
  puVar28 = puVar28 + (iVar5 >> 3);
  iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
  iVar22 = iVar11 + 7;
  iVar5 = iVar11 + 0xe;
  if (-1 < iVar22) {
    iVar5 = iVar22;
  }
  iVar5 = iVar5 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
  iVar11 = iVar11 + 0x16;
  if (-1 < iVar22) {
    iVar11 = iVar22;
  }
  if (0 < iVar11 >> 4) {
    puVar27 = puVar28;
    puVar15 = puVar28 + iVar5 + -1;
    do {
      uVar1 = *puVar27;
      puVar13 = puVar27 + 1;
      *puVar27 = *puVar15;
      *puVar15 = uVar1;
      puVar27 = puVar13;
      puVar15 = puVar15 + -1;
    } while (puVar28 + (iVar11 >> 4) != puVar13);
  }
  puVar28 = puVar28 + iVar5;
  if ((int)puVar9 < 1) {
    pBVar21 = unaff_s6->q;
    iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar22 = iVar11 + 7;
    iVar5 = iVar11 + 0xe;
    if (-1 < iVar22) {
      iVar5 = iVar22;
    }
    iVar5 = iVar5 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar22) {
      iVar11 = iVar22;
    }
    iVar11 = iVar11 >> 4;
    puVar27 = puVar28 + iVar5 + -1;
    if (0 < iVar11) goto LAB_0057740c;
    puVar28 = puVar28 + iVar5;
LAB_00577bcc:
    pBVar21 = unaff_s6->dmp1;
    iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar22 = iVar11 + 7;
    iVar5 = iVar11 + 0xe;
    if (-1 < iVar22) {
      iVar5 = iVar22;
    }
    iVar5 = iVar5 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar22) {
      iVar11 = iVar22;
    }
    iVar11 = iVar11 >> 4;
    puVar27 = puVar28 + iVar5 + -1;
    if (0 < iVar11) goto LAB_005774d0;
    puVar28 = puVar28 + iVar5;
LAB_00577c44:
    pBVar21 = unaff_s6->dmq1;
    iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar5 = iVar22 + 7;
    iVar11 = iVar22 + 0xe;
    if (-1 < iVar5) {
      iVar11 = iVar5;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
    if (-1 >= iVar5) {
      iVar5 = iVar22 + 0x16;
    }
    iVar5 = iVar5 >> 4;
    puVar27 = puVar28 + iVar11 + -1;
    if (0 < iVar5) goto LAB_00577594;
LAB_005775b8:
    unaff_s7 = (rsa_st *)(puVar28 + iVar11);
    if ((int)puVar9 < 1) {
      pBVar21 = unaff_s6->iqmp;
      iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
      iVar11 = iVar22 + 7;
      iVar5 = iVar22 + 0xe;
      if (-1 < iVar11) {
        iVar5 = iVar11;
      }
      prVar18 = (rsa_st *)(iVar5 >> 3);
      (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,unaff_s7);
      if (-1 >= iVar11) {
        iVar11 = iVar22 + 0x16;
      }
      iVar11 = iVar11 >> 4;
      puVar28 = (undefined *)((int)&prVar18[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar11 < 1) {
        unaff_s7 = (rsa_st *)((int)&prVar18->pad + (int)&unaff_s7->pad);
        goto LAB_005776a4;
      }
      goto LAB_00577658;
    }
  }
  else {
    iVar5 = (int)puVar9 - iVar5;
    if (0 < iVar5) {
      (*(code *)PTR_memset_006aab00)(puVar28,0,iVar5);
      puVar28 = puVar28 + iVar5;
    }
    pBVar21 = unaff_s6->q;
    iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar22 = iVar11 + 7;
    iVar5 = iVar11 + 0xe;
    if (-1 < iVar22) {
      iVar5 = iVar22;
    }
    iVar5 = iVar5 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
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
LAB_0057740c:
      puVar15 = puVar28;
      do {
        uVar1 = *puVar15;
        puVar13 = puVar15 + 1;
        *puVar15 = *puVar27;
        *puVar27 = uVar1;
        puVar15 = puVar13;
        puVar27 = puVar27 + -1;
      } while (puVar28 + iVar11 != puVar13);
      puVar28 = puVar28 + iVar5;
      if ((int)puVar9 < 1) goto LAB_00577bcc;
    }
    iVar5 = (int)puVar9 - iVar5;
    if (0 < iVar5) {
      (*(code *)PTR_memset_006aab00)(puVar28,0,iVar5);
      puVar28 = puVar28 + iVar5;
    }
    pBVar21 = unaff_s6->dmp1;
    iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar22 = iVar11 + 7;
    iVar5 = iVar11 + 0xe;
    if (-1 < iVar22) {
      iVar5 = iVar22;
    }
    iVar5 = iVar5 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
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
LAB_005774d0:
      puVar15 = puVar28;
      do {
        uVar1 = *puVar15;
        puVar13 = puVar15 + 1;
        *puVar15 = *puVar27;
        *puVar27 = uVar1;
        puVar15 = puVar13;
        puVar27 = puVar27 + -1;
      } while (puVar28 + iVar11 != puVar13);
      puVar28 = puVar28 + iVar5;
      if ((int)puVar9 < 1) goto LAB_00577c44;
    }
    iVar5 = (int)puVar9 - iVar5;
    if (0 < iVar5) {
      (*(code *)PTR_memset_006aab00)(puVar28,0,iVar5);
      puVar28 = puVar28 + iVar5;
    }
    pBVar21 = unaff_s6->dmq1;
    iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar5 = iVar22 + 7;
    iVar11 = iVar22 + 0xe;
    if (-1 < iVar5) {
      iVar11 = iVar5;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,puVar28);
    if (-1 >= iVar5) {
      iVar5 = iVar22 + 0x16;
    }
    iVar5 = iVar5 >> 4;
    puVar27 = puVar28 + iVar11 + -1;
    if (0 < iVar5) {
LAB_00577594:
      puVar15 = puVar28;
      do {
        uVar1 = *puVar15;
        puVar13 = puVar15 + 1;
        *puVar15 = *puVar27;
        *puVar27 = uVar1;
        puVar27 = puVar27 + -1;
        puVar15 = puVar13;
      } while (puVar28 + iVar5 != puVar13);
      goto LAB_005775b8;
    }
    unaff_s7 = (rsa_st *)(puVar28 + iVar11);
  }
  iVar11 = (int)puVar9 - iVar11;
  if (0 < iVar11) {
    (*(code *)PTR_memset_006aab00)(unaff_s7,0,iVar11);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar11);
  }
  pBVar21 = unaff_s6->iqmp;
  iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
  iVar11 = iVar22 + 7;
  iVar5 = iVar22 + 0xe;
  if (-1 < iVar11) {
    iVar5 = iVar11;
  }
  prVar18 = (rsa_st *)(iVar5 >> 3);
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,unaff_s7);
  if (-1 >= iVar11) {
    iVar11 = iVar22 + 0x16;
  }
  iVar11 = iVar11 >> 4;
  puVar28 = (undefined *)((int)&prVar18[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar11 < 1) goto LAB_00577dbc;
LAB_00577658:
  prVar25 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar25->pad;
    prVar24 = (rsa_st *)((int)&prVar25->pad + 1);
    *(undefined *)&prVar25->pad = *puVar28;
    *puVar28 = uVar1;
    puVar28 = puVar28 + -1;
    prVar25 = prVar24;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar11) != prVar24);
  prVar25 = (rsa_st *)((int)&prVar18->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar25;
  if ((int)puVar9 < 1) goto LAB_005776a4;
  do {
    unaff_s7 = prVar25;
    if (0 < (int)puVar9 - (int)prVar18) {
      unaff_s7 = (rsa_st *)((int)prVar25 + ((int)puVar9 - (int)prVar18));
      (*(code *)PTR_memset_006aab00)(prVar25,0);
    }
LAB_005776a4:
    pBVar21 = unaff_s6->d;
    iVar22 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar21);
    iVar5 = iVar22 + 7;
    puVar9 = (undefined *)(uint)(iVar5 < 0);
    iVar11 = iVar22 + 0xe;
    if (puVar9 == (undefined *)0x0) {
      iVar11 = iVar5;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar21,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar11 >> 3);
    if (puVar9 != (undefined *)0x0) {
      iVar5 = iVar22 + 0x16;
    }
    prVar18 = (rsa_st *)(iVar5 >> 4);
    if (0 < (int)prVar18) {
      prVar18 = (rsa_st *)((int)&prVar18->pad + (int)&unaff_s7->pad);
      puVar28 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar25 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar25->pad;
        prVar24 = (rsa_st *)((int)&prVar25->pad + 1);
        *(undefined *)&prVar25->pad = *puVar28;
        *puVar28 = uVar1;
        puVar28 = puVar28 + -1;
        prVar25 = prVar24;
      } while (prVar18 != prVar24);
    }
    prVar24 = prVar10;
    if ((0 < (int)prVar6) && (prVar18 = (rsa_st *)((int)prVar6 - (int)unaff_s6), 0 < (int)prVar18))
    {
      (*(code *)PTR_memset_006aab00)((char *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00577758:
    prVar10 = prVar24;
    prVar25 = prVar7;
    if ((int)prVar7 < 0) {
LAB_0057782c:
      prVar7 = (rsa_st *)0xffffffff;
    }
    else {
      prVar18 = prVar7;
      prVar10 = (rsa_st *)(*(code *)PTR_BIO_write_006a7f14)(pBVar16,prVar24);
      (*(code *)PTR_CRYPTO_free_006a7f88)(prVar24);
      if (prVar10 != prVar7) goto LAB_0057782c;
    }
LAB_00577790:
    if (iStack_114 == *(int *)puVar2) {
      return (EVP_PKEY *)prVar7;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    prVar7 = prVar25;
LAB_00577dbc:
    prVar25 = (rsa_st *)((int)&prVar18->pad + (int)&unaff_s7->pad);
  } while( true );
}

