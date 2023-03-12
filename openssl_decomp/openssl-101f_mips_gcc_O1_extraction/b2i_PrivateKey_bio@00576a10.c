
EVP_PKEY * b2i_PrivateKey_bio(BIO *in)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  rsa_st *prVar4;
  rsa_st *prVar5;
  uint uVar6;
  undefined *puVar7;
  rsa_st *prVar8;
  int iVar9;
  BIGNUM **ppBVar10;
  undefined *puVar11;
  BIGNUM **ppBVar12;
  undefined *puVar13;
  BIGNUM *pBVar14;
  undefined4 uVar15;
  rsa_st *prVar16;
  ENGINE *pEVar17;
  BIGNUM *pBVar18;
  int iVar19;
  int iVar20;
  rsa_st *prVar21;
  BIGNUM *unaff_s2;
  rsa_st *prVar22;
  rsa_st *unaff_s4;
  BIGNUM *unaff_s5;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar23;
  undefined *puVar24;
  undefined *puVar25;
  code *pcVar26;
  int iStack_e0;
  int iStack_dc;
  rsa_st *prStack_d8;
  rsa_st *prStack_d4;
  BIGNUM *pBStack_d0;
  BIGNUM *pBStack_cc;
  rsa_st *prStack_c8;
  BIGNUM *pBStack_c4;
  rsa_st *prStack_c0;
  rsa_st *prStack_90;
  char cStack_8c;
  char cStack_8b;
  RSA_METHOD *pRStack_84;
  ENGINE *pEStack_80;
  undefined auStack_7c [68];
  rsa_st *local_38;
  char local_34;
  char local_33;
  BN_BLINDING *local_2c;
  BN_BLINDING *local_28;
  BIGNUM *local_24;
  
  prVar22 = (rsa_st *)PTR___stack_chk_guard_006aabf0;
  auStack_7c._4_4_ = (rsa_st *)(auStack_7c + 0x48);
  auStack_7c._60_4_ = &_gp;
  local_24 = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BIO_read_006a85bc)(in,auStack_7c._4_4_,0x10);
  if (iVar3 == 0x10) {
    local_38 = auStack_7c._4_4_;
    if (local_34 == '\x06') {
      pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eb0);
      uVar15 = 0x77;
      auStack_7c._52_4_ = (BN_MONT_CTX *)&DAT_00000098;
LAB_00576c0c:
      (*pcVar26)(9,0x86,uVar15,FUN_0066ce6c);
    }
    else if (local_34 == '\a') {
      if (local_33 == '\x02') {
        uVar6 = ((((uint)local_2c >> 0x10) << 0x18 | ((uint)local_2c >> 0x18) << 0x10) >> 0x10) +
                (((uint)local_2c & 0xff) << 8 | (uint)local_2c >> 8 & 0xff) * 0x10000;
        unaff_s2 = (BIGNUM *)
                   (((((uint)local_28 >> 0x10) << 0x18 | ((uint)local_28 >> 0x18) << 0x10) >> 0x10)
                   + (((uint)local_28 & 0xff) << 8 | (uint)local_28 >> 8 & 0xff) * 0x10000);
        if (uVar6 != 0x31535344) {
          if (0x31535344 < uVar6) {
            if (uVar6 == 0x32415352) {
              unaff_s5 = (BIGNUM *)0x0;
              auStack_7c._4_4_ =
                   (rsa_st *)
                   ((((uint)((int)&unaff_s2->top + 3U) >> 3) + 2) * 2 +
                   ((uint)((int)&unaff_s2->neg + 3U) >> 4) * 5);
            }
            else {
              unaff_s5 = (BIGNUM *)0x1;
              if (uVar6 != 0x32535344) goto LAB_00576cd8;
              auStack_7c._4_4_ = (rsa_st *)((((uint)((int)&unaff_s2->top + 3U) >> 3) + 0x20) * 2);
            }
            local_38 = (rsa_st *)&local_24;
            unaff_s6 = (rsa_st *)0x670000;
            unaff_s4 = (rsa_st *)
                       (**(code **)(auStack_7c._60_4_ + -0x7dd8))
                                 (auStack_7c._4_4_,FUN_0066ce6c,0x11f);
            if (unaff_s4 == (rsa_st *)0x0) {
              auStack_7c._52_4_ = (BN_MONT_CTX *)0x122;
              (**(code **)(auStack_7c._60_4_ + -0x6eb0))(9,0x85,0x41,FUN_0066ce6c);
              prVar4 = (rsa_st *)0x0;
            }
            else {
              local_38 = unaff_s4;
              prVar4 = (rsa_st *)
                       (**(code **)(auStack_7c._60_4_ + -0x7924))(in,unaff_s4,auStack_7c._4_4_);
              if (auStack_7c._4_4_ == prVar4) {
                if (unaff_s5 == (BIGNUM *)0x0) {
                  prVar4 = (rsa_st *)b2i_rsa_isra_1(auStack_7c + 0x44,unaff_s2,0);
                }
                else {
                  prVar4 = (rsa_st *)b2i_dss_isra_0();
                }
              }
              else {
                auStack_7c._52_4_ = (BN_MONT_CTX *)0x128;
                prVar4 = (rsa_st *)0x0;
                (**(code **)(auStack_7c._60_4_ + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
              }
              (**(code **)(auStack_7c._60_4_ + -0x7f58))(unaff_s4);
              auStack_7c._4_4_ = prVar4;
            }
            goto LAB_00576a94;
          }
          if (uVar6 != 0x31415352) {
LAB_00576cd8:
            pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eb0);
            uVar15 = 0x74;
            auStack_7c._52_4_ = (BN_MONT_CTX *)0xcf;
            goto LAB_00576c0c;
          }
        }
        pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eb0);
        uVar15 = 0x77;
        auStack_7c._52_4_ = (BN_MONT_CTX *)0xbe;
      }
      else {
        pcVar26 = *(code **)(auStack_7c._60_4_ + -0x6eb0);
        uVar15 = 0x75;
        auStack_7c._52_4_ = (BN_MONT_CTX *)0xad;
      }
      goto LAB_00576c0c;
    }
    prVar4 = (rsa_st *)0x0;
  }
  else {
    auStack_7c._52_4_ = (BN_MONT_CTX *)0x117;
    (**(code **)(auStack_7c._60_4_ + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
    prVar4 = (rsa_st *)0x0;
  }
LAB_00576a94:
  if (local_24 == *(BIGNUM **)prVar22) {
    return (EVP_PKEY *)prVar4;
  }
  auStack_7c._32_4_ = b2i_PublicKey_bio;
  pBStack_cc = local_24;
  (**(code **)(auStack_7c._60_4_ + -0x5328))();
  puVar7 = PTR___stack_chk_guard_006aabf0;
  prVar16 = (rsa_st *)&SUB_00000010;
  prVar8 = (rsa_st *)&cStack_8c;
  auStack_7c._8_4_ = (RSA_METHOD *)prVar22;
  auStack_7c._0_4_ = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  prVar4 = prVar8;
  auStack_7c._12_4_ = unaff_s2;
  auStack_7c._16_4_ = in;
  auStack_7c._20_4_ = unaff_s4;
  auStack_7c._24_4_ = unaff_s5;
  auStack_7c._28_4_ = unaff_s6;
  iVar3 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar3 == 0x10) {
    prStack_90 = prVar8;
    if (cStack_8c == '\x06') {
      if (cStack_8b == '\x02') {
        uVar6 = ((((uint)pRStack_84 >> 0x10) << 0x18 | ((uint)pRStack_84 >> 0x18) << 0x10) >> 0x10)
                + (((uint)pRStack_84 & 0xff) << 8 | (uint)pRStack_84 >> 8 & 0xff) * 0x10000;
        unaff_s4 = (rsa_st *)
                   (((((uint)pEStack_80 >> 0x10) << 0x18 | ((uint)pEStack_80 >> 0x18) << 0x10) >>
                    0x10) + (((uint)pEStack_80 & 0xff) << 8 | (uint)pEStack_80 >> 8 & 0xff) *
                            0x10000);
        if (uVar6 == 0x31535344) {
          unaff_s5 = (BIGNUM *)0x1;
          prVar8 = (rsa_st *)(((uint)((int)&unaff_s4->version + 3) >> 3) * 3 + 0x2c);
LAB_00576e9c:
          prStack_90 = (rsa_st *)auStack_7c;
          unaff_s6 = (rsa_st *)0x670000;
          prVar22 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(prVar8,FUN_0066ce6c,0x11f);
          if (prVar22 == (rsa_st *)0x0) {
            prVar16 = (rsa_st *)&DAT_00000041;
            prVar4 = (rsa_st *)0x85;
            (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x41,FUN_0066ce6c);
            prVar5 = (rsa_st *)0x0;
          }
          else {
            prStack_90 = prVar22;
            prVar4 = (rsa_st *)(*(code *)PTR_BIO_read_006a85bc)(pBStack_cc,prVar22,prVar8);
            if (prVar8 == prVar4) {
              prVar16 = (rsa_st *)0x1;
              prVar4 = unaff_s4;
              if (unaff_s5 == (BIGNUM *)0x0) {
                prVar5 = (rsa_st *)b2i_rsa_isra_1(&prStack_90);
              }
              else {
                prVar5 = (rsa_st *)b2i_dss_isra_0();
              }
            }
            else {
              prVar16 = (rsa_st *)0x7b;
              prVar4 = (rsa_st *)0x85;
              prVar5 = (rsa_st *)0x0;
              (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x7b,FUN_0066ce6c);
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(prVar22);
            prVar8 = prVar5;
          }
          goto LAB_00576d94;
        }
        if (uVar6 < 0x31535345) {
          unaff_s5 = (BIGNUM *)0x0;
          if (uVar6 == 0x31415352) {
            prVar8 = (rsa_st *)(((uint)((int)&unaff_s4->version + 3) >> 3) + 4);
            goto LAB_00576e9c;
          }
        }
        else if ((uVar6 == 0x32415352) || (uVar6 == 0x32535344)) {
          prVar16 = (rsa_st *)&DAT_00000078;
          goto LAB_00576e34;
        }
        prVar16 = (rsa_st *)&DAT_00000074;
      }
      else {
        prVar16 = (rsa_st *)0x75;
      }
LAB_00576e34:
      prVar4 = (rsa_st *)0x86;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,prVar16,FUN_0066ce6c);
    }
    else if (cStack_8c == '\a') {
      prVar16 = (rsa_st *)&DAT_00000078;
      goto LAB_00576e34;
    }
    prVar5 = (rsa_st *)0x0;
  }
  else {
    prVar16 = (rsa_st *)0x7b;
    prVar4 = (rsa_st *)0x85;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x7b,FUN_0066ce6c);
    prVar5 = (rsa_st *)0x0;
  }
LAB_00576d94:
  if (auStack_7c._0_4_ == *(BIGNUM **)puVar7) {
    return (EVP_PKEY *)prVar5;
  }
  pBVar14 = auStack_7c._0_4_;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pBStack_d0 = (BIGNUM *)puVar7;
  iStack_e0 = 0;
  iStack_dc = *(int *)PTR___stack_chk_guard_006aabf0;
  prStack_d8 = prVar8;
  prStack_d4 = prVar22;
  prStack_c8 = unaff_s4;
  pBStack_c4 = unaff_s5;
  prStack_c0 = unaff_s6;
  if (prVar4->pad == 0x74) {
    prVar8 = ((_union_271 *)&prVar4->e)->rsa;
    puVar7 = (undefined *)(*(code *)PTR_BN_num_bits_006a82f4)(prVar8->engine);
    if ((((((uint)puVar7 & 7) != 0) ||
         (iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar8->n), iVar3 != 0xa0)) ||
        (iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar8->e), (int)puVar7 < iVar3)) ||
       (iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar8->p), 0xa0 < iVar3)) {
      prVar16 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce6c,0x23c);
      goto LAB_0057782c;
    }
    iStack_e0 = 0x32535344;
    if (puVar7 == (undefined *)0x0) goto LAB_0057782c;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar3 = (((uint)(puVar7 + 7) >> 3) + 0x20) * 2;
  }
  else {
    prVar5 = (rsa_st *)0xffffffff;
    if (prVar4->pad != 6) goto LAB_00577790;
    prVar16 = (rsa_st *)&iStack_e0;
    puVar7 = (undefined *)check_bitlen_rsa(((_union_271 *)&prVar4->e)->ptr,0);
    if (puVar7 == (undefined *)0x0) goto LAB_0057782c;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar3 = (((uint)(puVar7 + 7) >> 3) + 2) * 2 + ((uint)(puVar7 + 0xf) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar5 = (rsa_st *)(iVar3 + 0x10);
  prVar16 = (rsa_st *)0x1ff;
  prVar8 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(prVar5,FUN_0066ce6c);
  prVar22 = prVar5;
  if (prVar8 == (rsa_st *)0x0) goto LAB_0057782c;
  *(undefined *)((int)&prVar8->pad + 2) = 0;
  *(undefined *)((int)&prVar8->pad + 3) = 0;
  *(undefined *)&prVar8->version = 0;
  *(char *)((int)&prVar8->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&prVar8->version + 2) = 0;
  *(undefined *)&prVar8->pad = 7;
  ppBVar23 = &prVar8->n;
  *(undefined *)((int)&prVar8->version + 3) = 0;
  *(char *)&prVar8->engine = (char)puVar7;
  *(undefined *)((int)&prVar8->pad + 1) = 2;
  *(char *)((int)&prVar8->engine + 1) = (char)((uint)puVar7 >> 8);
  *(char *)((int)&prVar8->engine + 2) = (char)((uint)puVar7 >> 0x10);
  *(char *)((int)&prVar8->engine + 3) = (char)((uint)puVar7 >> 0x18);
  *(char *)&prVar8->meth = (char)iStack_e0;
  *(char *)((int)&prVar8->meth + 1) = (char)((uint)iStack_e0 >> 8);
  *(char *)((int)&prVar8->meth + 2) = (char)((uint)iStack_e0 >> 0x10);
  *(char *)((int)&prVar8->meth + 3) = (char)((uint)iStack_e0 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar22 = ((_union_271 *)&prVar4->e)->rsa;
    iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar22->engine);
    pEVar17 = prVar22->engine;
    iVar3 = iVar9 + 7;
    if (iVar9 + 7 < 0) {
      iVar3 = iVar9 + 0xe;
    }
    iVar3 = iVar3 >> 3;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pEVar17);
    iVar20 = iVar19 + 7;
    iVar9 = iVar19 + 0xe;
    if (-1 < iVar20) {
      iVar9 = iVar20;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pEVar17,ppBVar23);
    iVar9 = iVar9 >> 3;
    iVar19 = iVar19 + 0x16;
    if (-1 < iVar20) {
      iVar19 = iVar20;
    }
    if (0 < iVar19 >> 4) {
      ppBVar12 = ppBVar23;
      puVar7 = (undefined *)((int)ppBVar23 + iVar9 + -1);
      do {
        uVar1 = *(undefined *)ppBVar12;
        ppBVar10 = (BIGNUM **)((int)ppBVar12 + 1);
        *(undefined *)ppBVar12 = *puVar7;
        *puVar7 = uVar1;
        ppBVar12 = ppBVar10;
        puVar7 = puVar7 + -1;
      } while ((BIGNUM **)((int)ppBVar23 + (iVar19 >> 4)) != ppBVar10);
    }
    puVar25 = (undefined *)((int)ppBVar23 + iVar9);
    puVar7 = puVar25;
    if ((0 < iVar3) && (0 < iVar3 - iVar9)) {
      puVar7 = puVar25 + (iVar3 - iVar9);
      (*(code *)PTR_memset_006aab00)(puVar25,0);
    }
    pBVar18 = prVar22->n;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar20 = iVar19 + 7;
    iVar9 = iVar19 + 0xe;
    if (-1 < iVar20) {
      iVar9 = iVar20;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar7);
    iVar9 = iVar9 >> 3;
    iVar19 = iVar19 + 0x16;
    if (-1 < iVar20) {
      iVar19 = iVar20;
    }
    if (0 < iVar19 >> 4) {
      puVar25 = puVar7;
      puVar24 = puVar7 + iVar9 + -1;
      do {
        uVar1 = *puVar25;
        puVar13 = puVar25 + 1;
        *puVar25 = *puVar24;
        *puVar24 = uVar1;
        puVar25 = puVar13;
        puVar24 = puVar24 + -1;
      } while (puVar7 + (iVar19 >> 4) != puVar13);
    }
    puVar7 = puVar7 + iVar9;
    puVar25 = puVar7;
    if (0 < 0x14 - iVar9) {
      puVar25 = puVar7 + (0x14 - iVar9);
      (*(code *)PTR_memset_006aab00)(puVar7,0);
    }
    pBVar18 = prVar22->e;
    iVar20 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar20 + 7;
    iVar9 = iVar20 + 0xe;
    if (-1 < iVar19) {
      iVar9 = iVar19;
    }
    iVar9 = iVar9 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
    if (-1 >= iVar19) {
      iVar19 = iVar20 + 0x16;
    }
    if (0 < iVar19 >> 4) {
      puVar7 = puVar25;
      puVar24 = puVar25 + iVar9 + -1;
      do {
        uVar1 = *puVar7;
        puVar13 = puVar7 + 1;
        *puVar7 = *puVar24;
        *puVar24 = uVar1;
        puVar7 = puVar13;
        puVar24 = puVar24 + -1;
      } while (puVar13 != puVar25 + (iVar19 >> 4));
    }
    prVar4 = (rsa_st *)(puVar25 + iVar9);
    unaff_s7 = prVar4;
    if ((0 < iVar3) && (0 < iVar3 - iVar9)) {
      unaff_s7 = (rsa_st *)((int)prVar4 + (iVar3 - iVar9));
      (*(code *)PTR_memset_006aab00)(prVar4,0);
    }
    pBVar18 = prVar22->p;
    iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    prVar22 = (rsa_st *)(iVar3 + 7);
    prVar4 = (rsa_st *)(iVar3 + 0xe);
    if (-1 < (int)prVar22) {
      prVar4 = prVar22;
    }
    unaff_s6 = (rsa_st *)(iVar3 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,unaff_s7);
    if (-1 >= (int)prVar22) {
      prVar22 = unaff_s6;
    }
    prVar4 = (rsa_st *)((int)prVar4 >> 3);
    if (0 < (int)prVar22 >> 4) {
      prVar16 = unaff_s7;
      puVar7 = (undefined *)((int)&prVar4[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar16->pad;
        prVar21 = (rsa_st *)((int)&prVar16->pad + 1);
        *(undefined *)&prVar16->pad = *puVar7;
        *puVar7 = uVar1;
        prVar16 = prVar21;
        puVar7 = puVar7 + -1;
      } while (prVar21 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar22 >> 4)));
    }
    puVar25 = (undefined *)((int)&prVar4->pad + (int)&unaff_s7->pad);
    puVar7 = puVar25;
    if (0 < 0x14 - (int)prVar4) {
      puVar7 = puVar25 + (0x14 - (int)prVar4);
      (*(code *)PTR_memset_006aab00)(puVar25,0);
    }
    prVar16 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006aab00)(puVar7,0xff);
    prVar21 = prVar8;
    goto LAB_00577758;
  }
  unaff_s6 = ((_union_271 *)&prVar4->e)->rsa;
  iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s6->n);
  iVar3 = iVar9 + 7;
  if (iVar9 + 7 < 0) {
    iVar3 = iVar9 + 0xe;
  }
  prVar4 = (rsa_st *)(iVar3 >> 3);
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s6->n);
  pBVar18 = unaff_s6->e;
  puVar7 = (undefined *)(iVar3 + 0xf >> 4);
  iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
  iVar19 = iVar9 + 7;
  iVar3 = iVar9 + 0xe;
  if (-1 < iVar19) {
    iVar3 = iVar19;
  }
  iVar3 = iVar3 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,ppBVar23);
  iVar9 = iVar9 + 0x16;
  if (-1 < iVar19) {
    iVar9 = iVar19;
  }
  if (0 < iVar9 >> 4) {
    ppBVar12 = ppBVar23;
    puVar25 = (undefined *)((int)ppBVar23 + iVar3 + -1);
    do {
      uVar1 = *(undefined *)ppBVar12;
      ppBVar10 = (BIGNUM **)((int)ppBVar12 + 1);
      *(undefined *)ppBVar12 = *puVar25;
      *puVar25 = uVar1;
      ppBVar12 = ppBVar10;
      puVar25 = puVar25 + -1;
    } while ((BIGNUM **)((int)ppBVar23 + (iVar9 >> 4)) != ppBVar10);
  }
  puVar24 = (undefined *)((int)ppBVar23 + iVar3);
  puVar25 = puVar24;
  if (0 < 4 - iVar3) {
    puVar25 = puVar24 + (4 - iVar3);
    (*(code *)PTR_memset_006aab00)(puVar24,0);
  }
  pBVar18 = unaff_s6->n;
  iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
  iVar9 = iVar19 + 7;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
  iVar3 = iVar9;
  if (iVar9 < 0) {
    iVar9 = iVar19 + 0x16;
    iVar3 = iVar19 + 0xe;
  }
  if (0 < iVar9 >> 4) {
    puVar24 = puVar25;
    puVar13 = puVar25 + (iVar3 >> 3) + -1;
    do {
      uVar1 = *puVar24;
      puVar11 = puVar24 + 1;
      *puVar24 = *puVar13;
      *puVar13 = uVar1;
      puVar24 = puVar11;
      puVar13 = puVar13 + -1;
    } while (puVar11 != puVar25 + (iVar9 >> 4));
  }
  pBVar18 = unaff_s6->p;
  puVar25 = puVar25 + (iVar3 >> 3);
  iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
  iVar19 = iVar9 + 7;
  iVar3 = iVar9 + 0xe;
  if (-1 < iVar19) {
    iVar3 = iVar19;
  }
  iVar3 = iVar3 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
  iVar9 = iVar9 + 0x16;
  if (-1 < iVar19) {
    iVar9 = iVar19;
  }
  if (0 < iVar9 >> 4) {
    puVar24 = puVar25;
    puVar13 = puVar25 + iVar3 + -1;
    do {
      uVar1 = *puVar24;
      puVar11 = puVar24 + 1;
      *puVar24 = *puVar13;
      *puVar13 = uVar1;
      puVar24 = puVar11;
      puVar13 = puVar13 + -1;
    } while (puVar25 + (iVar9 >> 4) != puVar11);
  }
  puVar25 = puVar25 + iVar3;
  if ((int)puVar7 < 1) {
    pBVar18 = unaff_s6->q;
    iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar9 + 7;
    iVar3 = iVar9 + 0xe;
    if (-1 < iVar19) {
      iVar3 = iVar19;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
    iVar9 = iVar9 + 0x16;
    if (-1 < iVar19) {
      iVar9 = iVar19;
    }
    iVar9 = iVar9 >> 4;
    puVar24 = puVar25 + iVar3 + -1;
    if (0 < iVar9) goto LAB_0057740c;
    puVar25 = puVar25 + iVar3;
LAB_00577bcc:
    pBVar18 = unaff_s6->dmp1;
    iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar9 + 7;
    iVar3 = iVar9 + 0xe;
    if (-1 < iVar19) {
      iVar3 = iVar19;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
    iVar9 = iVar9 + 0x16;
    if (-1 < iVar19) {
      iVar9 = iVar19;
    }
    iVar9 = iVar9 >> 4;
    puVar24 = puVar25 + iVar3 + -1;
    if (0 < iVar9) goto LAB_005774d0;
    puVar25 = puVar25 + iVar3;
LAB_00577c44:
    pBVar18 = unaff_s6->dmq1;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar3 = iVar19 + 7;
    iVar9 = iVar19 + 0xe;
    if (-1 < iVar3) {
      iVar9 = iVar3;
    }
    iVar9 = iVar9 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
    if (-1 >= iVar3) {
      iVar3 = iVar19 + 0x16;
    }
    iVar3 = iVar3 >> 4;
    puVar24 = puVar25 + iVar9 + -1;
    if (0 < iVar3) goto LAB_00577594;
LAB_005775b8:
    unaff_s7 = (rsa_st *)(puVar25 + iVar9);
    if ((int)puVar7 < 1) {
      pBVar18 = unaff_s6->iqmp;
      iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
      iVar9 = iVar19 + 7;
      iVar3 = iVar19 + 0xe;
      if (-1 < iVar9) {
        iVar3 = iVar9;
      }
      prVar16 = (rsa_st *)(iVar3 >> 3);
      (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,unaff_s7);
      if (-1 >= iVar9) {
        iVar9 = iVar19 + 0x16;
      }
      iVar9 = iVar9 >> 4;
      puVar25 = (undefined *)((int)&prVar16[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar9 < 1) {
        unaff_s7 = (rsa_st *)((int)&prVar16->pad + (int)&unaff_s7->pad);
        goto LAB_005776a4;
      }
      goto LAB_00577658;
    }
  }
  else {
    iVar3 = (int)puVar7 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006aab00)(puVar25,0,iVar3);
      puVar25 = puVar25 + iVar3;
    }
    pBVar18 = unaff_s6->q;
    iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar9 + 7;
    iVar3 = iVar9 + 0xe;
    if (-1 < iVar19) {
      iVar3 = iVar19;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
    iVar9 = iVar9 + 0x16;
    if (-1 < iVar19) {
      iVar9 = iVar19;
    }
    iVar9 = iVar9 >> 4;
    puVar24 = puVar25 + iVar3 + -1;
    if (iVar9 < 1) {
      puVar25 = puVar25 + iVar3;
    }
    else {
LAB_0057740c:
      puVar13 = puVar25;
      do {
        uVar1 = *puVar13;
        puVar11 = puVar13 + 1;
        *puVar13 = *puVar24;
        *puVar24 = uVar1;
        puVar13 = puVar11;
        puVar24 = puVar24 + -1;
      } while (puVar25 + iVar9 != puVar11);
      puVar25 = puVar25 + iVar3;
      if ((int)puVar7 < 1) goto LAB_00577bcc;
    }
    iVar3 = (int)puVar7 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006aab00)(puVar25,0,iVar3);
      puVar25 = puVar25 + iVar3;
    }
    pBVar18 = unaff_s6->dmp1;
    iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar9 + 7;
    iVar3 = iVar9 + 0xe;
    if (-1 < iVar19) {
      iVar3 = iVar19;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
    iVar9 = iVar9 + 0x16;
    if (-1 < iVar19) {
      iVar9 = iVar19;
    }
    iVar9 = iVar9 >> 4;
    puVar24 = puVar25 + iVar3 + -1;
    if (iVar9 < 1) {
      puVar25 = puVar25 + iVar3;
    }
    else {
LAB_005774d0:
      puVar13 = puVar25;
      do {
        uVar1 = *puVar13;
        puVar11 = puVar13 + 1;
        *puVar13 = *puVar24;
        *puVar24 = uVar1;
        puVar13 = puVar11;
        puVar24 = puVar24 + -1;
      } while (puVar25 + iVar9 != puVar11);
      puVar25 = puVar25 + iVar3;
      if ((int)puVar7 < 1) goto LAB_00577c44;
    }
    iVar3 = (int)puVar7 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006aab00)(puVar25,0,iVar3);
      puVar25 = puVar25 + iVar3;
    }
    pBVar18 = unaff_s6->dmq1;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar3 = iVar19 + 7;
    iVar9 = iVar19 + 0xe;
    if (-1 < iVar3) {
      iVar9 = iVar3;
    }
    iVar9 = iVar9 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar25);
    if (-1 >= iVar3) {
      iVar3 = iVar19 + 0x16;
    }
    iVar3 = iVar3 >> 4;
    puVar24 = puVar25 + iVar9 + -1;
    if (0 < iVar3) {
LAB_00577594:
      puVar13 = puVar25;
      do {
        uVar1 = *puVar13;
        puVar11 = puVar13 + 1;
        *puVar13 = *puVar24;
        *puVar24 = uVar1;
        puVar24 = puVar24 + -1;
        puVar13 = puVar11;
      } while (puVar25 + iVar3 != puVar11);
      goto LAB_005775b8;
    }
    unaff_s7 = (rsa_st *)(puVar25 + iVar9);
  }
  iVar9 = (int)puVar7 - iVar9;
  if (0 < iVar9) {
    (*(code *)PTR_memset_006aab00)(unaff_s7,0,iVar9);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar9);
  }
  pBVar18 = unaff_s6->iqmp;
  iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
  iVar9 = iVar19 + 7;
  iVar3 = iVar19 + 0xe;
  if (-1 < iVar9) {
    iVar3 = iVar9;
  }
  prVar16 = (rsa_st *)(iVar3 >> 3);
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,unaff_s7);
  if (-1 >= iVar9) {
    iVar9 = iVar19 + 0x16;
  }
  iVar9 = iVar9 >> 4;
  puVar25 = (undefined *)((int)&prVar16[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar9 < 1) goto LAB_00577dbc;
LAB_00577658:
  prVar22 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar22->pad;
    prVar21 = (rsa_st *)((int)&prVar22->pad + 1);
    *(undefined *)&prVar22->pad = *puVar25;
    *puVar25 = uVar1;
    puVar25 = puVar25 + -1;
    prVar22 = prVar21;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar9) != prVar21);
  prVar22 = (rsa_st *)((int)&prVar16->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar22;
  if ((int)puVar7 < 1) goto LAB_005776a4;
  do {
    unaff_s7 = prVar22;
    if (0 < (int)puVar7 - (int)prVar16) {
      unaff_s7 = (rsa_st *)((int)prVar22 + ((int)puVar7 - (int)prVar16));
      (*(code *)PTR_memset_006aab00)(prVar22,0);
    }
LAB_005776a4:
    pBVar18 = unaff_s6->d;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar3 = iVar19 + 7;
    puVar7 = (undefined *)(uint)(iVar3 < 0);
    iVar9 = iVar19 + 0xe;
    if (puVar7 == (undefined *)0x0) {
      iVar9 = iVar3;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar9 >> 3);
    if (puVar7 != (undefined *)0x0) {
      iVar3 = iVar19 + 0x16;
    }
    prVar16 = (rsa_st *)(iVar3 >> 4);
    if (0 < (int)prVar16) {
      prVar16 = (rsa_st *)((int)&prVar16->pad + (int)&unaff_s7->pad);
      puVar25 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar22 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar22->pad;
        prVar21 = (rsa_st *)((int)&prVar22->pad + 1);
        *(undefined *)&prVar22->pad = *puVar25;
        *puVar25 = uVar1;
        puVar25 = puVar25 + -1;
        prVar22 = prVar21;
      } while (prVar16 != prVar21);
    }
    prVar21 = prVar8;
    if ((0 < (int)prVar4) && (prVar16 = (rsa_st *)((int)prVar4 - (int)unaff_s6), 0 < (int)prVar16))
    {
      (*(code *)PTR_memset_006aab00)((char *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00577758:
    prVar8 = prVar21;
    prVar22 = prVar5;
    if ((int)prVar5 < 0) {
LAB_0057782c:
      prVar5 = (rsa_st *)0xffffffff;
    }
    else {
      prVar16 = prVar5;
      prVar8 = (rsa_st *)(*(code *)PTR_BIO_write_006a7f14)(pBVar14,prVar21);
      (*(code *)PTR_CRYPTO_free_006a7f88)(prVar21);
      if (prVar8 != prVar5) goto LAB_0057782c;
    }
LAB_00577790:
    if (iStack_dc == *(int *)puVar2) {
      return (EVP_PKEY *)prVar5;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    prVar5 = prVar22;
LAB_00577dbc:
    prVar22 = (rsa_st *)((int)&prVar16->pad + (int)&unaff_s7->pad);
  } while( true );
}

