
EVP_PKEY * b2i_PublicKey_bio(BIO *in)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  rsa_st *prVar4;
  uint uVar5;
  undefined *puVar6;
  rsa_st *prVar7;
  int iVar8;
  BIGNUM **ppBVar9;
  undefined *puVar10;
  BIGNUM **ppBVar11;
  undefined *puVar12;
  rsa_st *prVar13;
  rsa_st *prVar14;
  BIGNUM *pBVar15;
  rsa_st *prVar16;
  ENGINE *pEVar17;
  BIGNUM *pBVar18;
  int iVar19;
  int iVar20;
  rsa_st *unaff_s1;
  rsa_st *prVar21;
  rsa_st *unaff_s4;
  BIGNUM *unaff_s5;
  rsa_st *unaff_s6;
  rsa_st *unaff_s7;
  BIGNUM **ppBVar22;
  undefined *puVar23;
  undefined *puVar24;
  int iStack_88;
  int iStack_84;
  rsa_st *prStack_80;
  rsa_st *prStack_7c;
  BIGNUM *pBStack_78;
  BIO *pBStack_74;
  rsa_st *prStack_70;
  BIGNUM *pBStack_6c;
  rsa_st *prStack_68;
  rsa_st *local_38;
  char local_34;
  char local_33;
  RSA_METHOD *local_2c;
  ENGINE *local_28;
  BIGNUM *local_24;
  
  puVar6 = PTR___stack_chk_guard_006aabf0;
  prVar16 = (rsa_st *)&SUB_00000010;
  prVar7 = (rsa_st *)&local_34;
  local_24 = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  prVar21 = prVar7;
  iVar3 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar3 == 0x10) {
    local_38 = prVar7;
    if (local_34 == '\x06') {
      if (local_33 == '\x02') {
        uVar5 = ((((uint)local_2c >> 0x10) << 0x18 | ((uint)local_2c >> 0x18) << 0x10) >> 0x10) +
                (((uint)local_2c & 0xff) << 8 | (uint)local_2c >> 8 & 0xff) * 0x10000;
        unaff_s4 = (rsa_st *)
                   (((((uint)local_28 >> 0x10) << 0x18 | ((uint)local_28 >> 0x18) << 0x10) >> 0x10)
                   + (((uint)local_28 & 0xff) << 8 | (uint)local_28 >> 8 & 0xff) * 0x10000);
        if (uVar5 == 0x31535344) {
          unaff_s5 = (BIGNUM *)0x1;
          prVar7 = (rsa_st *)(((uint)((int)&unaff_s4->version + 3) >> 3) * 3 + 0x2c);
LAB_00576e9c:
          local_38 = (rsa_st *)&local_24;
          unaff_s6 = (rsa_st *)0x670000;
          unaff_s1 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(prVar7,FUN_0066ce4c,0x11f);
          if (unaff_s1 == (rsa_st *)0x0) {
            prVar16 = (rsa_st *)&DAT_00000041;
            prVar21 = (rsa_st *)0x85;
            (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x41,FUN_0066ce4c);
            prVar4 = (rsa_st *)0x0;
          }
          else {
            local_38 = unaff_s1;
            prVar21 = (rsa_st *)(*(code *)PTR_BIO_read_006a85bc)(in,unaff_s1,prVar7);
            if (prVar7 == prVar21) {
              prVar16 = (rsa_st *)0x1;
              prVar21 = unaff_s4;
              if (unaff_s5 == (BIGNUM *)0x0) {
                prVar4 = (rsa_st *)b2i_rsa_isra_1(&local_38);
              }
              else {
                prVar4 = (rsa_st *)b2i_dss_isra_0();
              }
            }
            else {
              prVar16 = (rsa_st *)0x7b;
              prVar21 = (rsa_st *)0x85;
              prVar4 = (rsa_st *)0x0;
              (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x7b,FUN_0066ce4c);
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s1);
            prVar7 = prVar4;
          }
          goto LAB_00576d94;
        }
        if (uVar5 < 0x31535345) {
          unaff_s5 = (BIGNUM *)0x0;
          if (uVar5 == 0x31415352) {
            prVar7 = (rsa_st *)(((uint)((int)&unaff_s4->version + 3) >> 3) + 4);
            goto LAB_00576e9c;
          }
        }
        else if ((uVar5 == 0x32415352) || (uVar5 == 0x32535344)) {
          prVar16 = (rsa_st *)&DAT_00000078;
          goto LAB_00576e34;
        }
        prVar16 = (rsa_st *)&DAT_00000074;
      }
      else {
        prVar16 = (rsa_st *)0x75;
      }
LAB_00576e34:
      prVar21 = (rsa_st *)0x86;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,prVar16,FUN_0066ce4c);
    }
    else if (local_34 == '\a') {
      prVar16 = (rsa_st *)&DAT_00000078;
      goto LAB_00576e34;
    }
    prVar4 = (rsa_st *)0x0;
  }
  else {
    prVar16 = (rsa_st *)0x7b;
    prVar21 = (rsa_st *)0x85;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x85,0x7b,FUN_0066ce4c);
    prVar4 = (rsa_st *)0x0;
  }
LAB_00576d94:
  if (local_24 == *(BIGNUM **)puVar6) {
    return (EVP_PKEY *)prVar4;
  }
  pBVar15 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pBStack_78 = (BIGNUM *)puVar6;
  iStack_88 = 0;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  prStack_80 = prVar7;
  prStack_7c = unaff_s1;
  pBStack_74 = in;
  prStack_70 = unaff_s4;
  pBStack_6c = unaff_s5;
  prStack_68 = unaff_s6;
  if (prVar21->pad == 0x74) {
    prVar7 = ((_union_271 *)&prVar21->e)->rsa;
    puVar6 = (undefined *)(*(code *)PTR_BN_num_bits_006a82f4)(prVar7->engine);
    if ((((((uint)puVar6 & 7) != 0) ||
         (iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar7->n), iVar3 != 0xa0)) ||
        (iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar7->e), (int)puVar6 < iVar3)) ||
       (iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar7->p), 0xa0 < iVar3)) {
      prVar16 = (rsa_st *)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce4c,0x23c);
      goto LAB_0057782c;
    }
    iStack_88 = 0x32535344;
    if (puVar6 == (undefined *)0x0) goto LAB_0057782c;
    unaff_s7 = (rsa_st *)0x22;
    unaff_s6 = (rsa_st *)0x2200;
    iVar3 = (((uint)(puVar6 + 7) >> 3) + 0x20) * 2;
  }
  else {
    prVar4 = (rsa_st *)0xffffffff;
    if (prVar21->pad != 6) goto LAB_00577790;
    prVar16 = (rsa_st *)&iStack_88;
    puVar6 = (undefined *)check_bitlen_rsa(((_union_271 *)&prVar21->e)->ptr,0);
    if (puVar6 == (undefined *)0x0) goto LAB_0057782c;
    unaff_s7 = (rsa_st *)&DAT_000000a4;
    iVar3 = (((uint)(puVar6 + 7) >> 3) + 2) * 2 + ((uint)(puVar6 + 0xf) >> 4) * 5;
    unaff_s6 = (rsa_st *)0xa400;
  }
  prVar4 = (rsa_st *)(iVar3 + 0x10);
  prVar16 = (rsa_st *)0x1ff;
  prVar7 = (rsa_st *)(*(code *)PTR_CRYPTO_malloc_006a8108)(prVar4,FUN_0066ce4c);
  unaff_s1 = prVar4;
  if (prVar7 == (rsa_st *)0x0) goto LAB_0057782c;
  *(undefined *)((int)&prVar7->pad + 2) = 0;
  *(undefined *)((int)&prVar7->pad + 3) = 0;
  *(undefined *)&prVar7->version = 0;
  *(char *)((int)&prVar7->version + 1) = (char)unaff_s7;
  *(undefined *)((int)&prVar7->version + 2) = 0;
  *(undefined *)&prVar7->pad = 7;
  ppBVar22 = &prVar7->n;
  *(undefined *)((int)&prVar7->version + 3) = 0;
  *(char *)&prVar7->engine = (char)puVar6;
  *(undefined *)((int)&prVar7->pad + 1) = 2;
  *(char *)((int)&prVar7->engine + 1) = (char)((uint)puVar6 >> 8);
  *(char *)((int)&prVar7->engine + 2) = (char)((uint)puVar6 >> 0x10);
  *(char *)((int)&prVar7->engine + 3) = (char)((uint)puVar6 >> 0x18);
  *(char *)&prVar7->meth = (char)iStack_88;
  *(char *)((int)&prVar7->meth + 1) = (char)((uint)iStack_88 >> 8);
  *(char *)((int)&prVar7->meth + 2) = (char)((uint)iStack_88 >> 0x10);
  *(char *)((int)&prVar7->meth + 3) = (char)((uint)iStack_88 >> 0x18);
  if (unaff_s6 == (rsa_st *)0x2200) {
    prVar21 = ((_union_271 *)&prVar21->e)->rsa;
    iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar21->engine);
    pEVar17 = prVar21->engine;
    iVar3 = iVar8 + 7;
    if (iVar8 + 7 < 0) {
      iVar3 = iVar8 + 0xe;
    }
    iVar3 = iVar3 >> 3;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pEVar17);
    iVar20 = iVar19 + 7;
    iVar8 = iVar19 + 0xe;
    if (-1 < iVar20) {
      iVar8 = iVar20;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pEVar17,ppBVar22);
    iVar8 = iVar8 >> 3;
    iVar19 = iVar19 + 0x16;
    if (-1 < iVar20) {
      iVar19 = iVar20;
    }
    if (0 < iVar19 >> 4) {
      ppBVar11 = ppBVar22;
      puVar6 = (undefined *)((int)ppBVar22 + iVar8 + -1);
      do {
        uVar1 = *(undefined *)ppBVar11;
        ppBVar9 = (BIGNUM **)((int)ppBVar11 + 1);
        *(undefined *)ppBVar11 = *puVar6;
        *puVar6 = uVar1;
        ppBVar11 = ppBVar9;
        puVar6 = puVar6 + -1;
      } while ((BIGNUM **)((int)ppBVar22 + (iVar19 >> 4)) != ppBVar9);
    }
    puVar24 = (undefined *)((int)ppBVar22 + iVar8);
    puVar6 = puVar24;
    if ((0 < iVar3) && (0 < iVar3 - iVar8)) {
      puVar6 = puVar24 + (iVar3 - iVar8);
      (*(code *)PTR_memset_006aab00)(puVar24,0);
    }
    pBVar18 = prVar21->n;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar20 = iVar19 + 7;
    iVar8 = iVar19 + 0xe;
    if (-1 < iVar20) {
      iVar8 = iVar20;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar6);
    iVar8 = iVar8 >> 3;
    iVar19 = iVar19 + 0x16;
    if (-1 < iVar20) {
      iVar19 = iVar20;
    }
    if (0 < iVar19 >> 4) {
      puVar24 = puVar6;
      puVar23 = puVar6 + iVar8 + -1;
      do {
        uVar1 = *puVar24;
        puVar12 = puVar24 + 1;
        *puVar24 = *puVar23;
        *puVar23 = uVar1;
        puVar24 = puVar12;
        puVar23 = puVar23 + -1;
      } while (puVar6 + (iVar19 >> 4) != puVar12);
    }
    puVar6 = puVar6 + iVar8;
    puVar24 = puVar6;
    if (0 < 0x14 - iVar8) {
      puVar24 = puVar6 + (0x14 - iVar8);
      (*(code *)PTR_memset_006aab00)(puVar6,0);
    }
    pBVar18 = prVar21->e;
    iVar20 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar20 + 7;
    iVar8 = iVar20 + 0xe;
    if (-1 < iVar19) {
      iVar8 = iVar19;
    }
    iVar8 = iVar8 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
    if (-1 >= iVar19) {
      iVar19 = iVar20 + 0x16;
    }
    if (0 < iVar19 >> 4) {
      puVar6 = puVar24;
      puVar23 = puVar24 + iVar8 + -1;
      do {
        uVar1 = *puVar6;
        puVar12 = puVar6 + 1;
        *puVar6 = *puVar23;
        *puVar23 = uVar1;
        puVar6 = puVar12;
        puVar23 = puVar23 + -1;
      } while (puVar12 != puVar24 + (iVar19 >> 4));
    }
    prVar16 = (rsa_st *)(puVar24 + iVar8);
    unaff_s7 = prVar16;
    if ((0 < iVar3) && (0 < iVar3 - iVar8)) {
      unaff_s7 = (rsa_st *)((int)prVar16 + (iVar3 - iVar8));
      (*(code *)PTR_memset_006aab00)(prVar16,0);
    }
    pBVar18 = prVar21->p;
    iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    prVar16 = (rsa_st *)(iVar3 + 7);
    prVar21 = (rsa_st *)(iVar3 + 0xe);
    if (-1 < (int)prVar16) {
      prVar21 = prVar16;
    }
    unaff_s6 = (rsa_st *)(iVar3 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,unaff_s7);
    if (-1 >= (int)prVar16) {
      prVar16 = unaff_s6;
    }
    prVar21 = (rsa_st *)((int)prVar21 >> 3);
    if (0 < (int)prVar16 >> 4) {
      prVar13 = unaff_s7;
      puVar6 = (undefined *)((int)&prVar21[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      do {
        uVar1 = *(undefined *)&prVar13->pad;
        prVar14 = (rsa_st *)((int)&prVar13->pad + 1);
        *(undefined *)&prVar13->pad = *puVar6;
        *puVar6 = uVar1;
        prVar13 = prVar14;
        puVar6 = puVar6 + -1;
      } while (prVar14 != (rsa_st *)((int)&unaff_s7->pad + ((int)prVar16 >> 4)));
    }
    puVar24 = (undefined *)((int)&prVar21->pad + (int)&unaff_s7->pad);
    puVar6 = puVar24;
    if (0 < 0x14 - (int)prVar21) {
      puVar6 = puVar24 + (0x14 - (int)prVar21);
      (*(code *)PTR_memset_006aab00)(puVar24,0);
    }
    prVar16 = (rsa_st *)&DAT_00000018;
    (*(code *)PTR_memset_006aab00)(puVar6,0xff);
    prVar13 = prVar7;
    goto LAB_00577758;
  }
  unaff_s6 = ((_union_271 *)&prVar21->e)->rsa;
  iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s6->n);
  iVar3 = iVar8 + 7;
  if (iVar8 + 7 < 0) {
    iVar3 = iVar8 + 0xe;
  }
  prVar21 = (rsa_st *)(iVar3 >> 3);
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(unaff_s6->n);
  pBVar18 = unaff_s6->e;
  puVar6 = (undefined *)(iVar3 + 0xf >> 4);
  iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
  iVar19 = iVar8 + 7;
  iVar3 = iVar8 + 0xe;
  if (-1 < iVar19) {
    iVar3 = iVar19;
  }
  iVar3 = iVar3 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,ppBVar22);
  iVar8 = iVar8 + 0x16;
  if (-1 < iVar19) {
    iVar8 = iVar19;
  }
  if (0 < iVar8 >> 4) {
    ppBVar11 = ppBVar22;
    puVar24 = (undefined *)((int)ppBVar22 + iVar3 + -1);
    do {
      uVar1 = *(undefined *)ppBVar11;
      ppBVar9 = (BIGNUM **)((int)ppBVar11 + 1);
      *(undefined *)ppBVar11 = *puVar24;
      *puVar24 = uVar1;
      ppBVar11 = ppBVar9;
      puVar24 = puVar24 + -1;
    } while ((BIGNUM **)((int)ppBVar22 + (iVar8 >> 4)) != ppBVar9);
  }
  puVar23 = (undefined *)((int)ppBVar22 + iVar3);
  puVar24 = puVar23;
  if (0 < 4 - iVar3) {
    puVar24 = puVar23 + (4 - iVar3);
    (*(code *)PTR_memset_006aab00)(puVar23,0);
  }
  pBVar18 = unaff_s6->n;
  iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
  iVar8 = iVar19 + 7;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
  iVar3 = iVar8;
  if (iVar8 < 0) {
    iVar8 = iVar19 + 0x16;
    iVar3 = iVar19 + 0xe;
  }
  if (0 < iVar8 >> 4) {
    puVar23 = puVar24;
    puVar12 = puVar24 + (iVar3 >> 3) + -1;
    do {
      uVar1 = *puVar23;
      puVar10 = puVar23 + 1;
      *puVar23 = *puVar12;
      *puVar12 = uVar1;
      puVar23 = puVar10;
      puVar12 = puVar12 + -1;
    } while (puVar10 != puVar24 + (iVar8 >> 4));
  }
  pBVar18 = unaff_s6->p;
  puVar24 = puVar24 + (iVar3 >> 3);
  iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
  iVar19 = iVar8 + 7;
  iVar3 = iVar8 + 0xe;
  if (-1 < iVar19) {
    iVar3 = iVar19;
  }
  iVar3 = iVar3 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
  iVar8 = iVar8 + 0x16;
  if (-1 < iVar19) {
    iVar8 = iVar19;
  }
  if (0 < iVar8 >> 4) {
    puVar23 = puVar24;
    puVar12 = puVar24 + iVar3 + -1;
    do {
      uVar1 = *puVar23;
      puVar10 = puVar23 + 1;
      *puVar23 = *puVar12;
      *puVar12 = uVar1;
      puVar23 = puVar10;
      puVar12 = puVar12 + -1;
    } while (puVar24 + (iVar8 >> 4) != puVar10);
  }
  puVar24 = puVar24 + iVar3;
  if ((int)puVar6 < 1) {
    pBVar18 = unaff_s6->q;
    iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar8 + 7;
    iVar3 = iVar8 + 0xe;
    if (-1 < iVar19) {
      iVar3 = iVar19;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
    iVar8 = iVar8 + 0x16;
    if (-1 < iVar19) {
      iVar8 = iVar19;
    }
    iVar8 = iVar8 >> 4;
    puVar23 = puVar24 + iVar3 + -1;
    if (0 < iVar8) goto LAB_0057740c;
    puVar24 = puVar24 + iVar3;
LAB_00577bcc:
    pBVar18 = unaff_s6->dmp1;
    iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar8 + 7;
    iVar3 = iVar8 + 0xe;
    if (-1 < iVar19) {
      iVar3 = iVar19;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
    iVar8 = iVar8 + 0x16;
    if (-1 < iVar19) {
      iVar8 = iVar19;
    }
    iVar8 = iVar8 >> 4;
    puVar23 = puVar24 + iVar3 + -1;
    if (0 < iVar8) goto LAB_005774d0;
    puVar24 = puVar24 + iVar3;
LAB_00577c44:
    pBVar18 = unaff_s6->dmq1;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar3 = iVar19 + 7;
    iVar8 = iVar19 + 0xe;
    if (-1 < iVar3) {
      iVar8 = iVar3;
    }
    iVar8 = iVar8 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
    if (-1 >= iVar3) {
      iVar3 = iVar19 + 0x16;
    }
    iVar3 = iVar3 >> 4;
    puVar23 = puVar24 + iVar8 + -1;
    if (0 < iVar3) goto LAB_00577594;
LAB_005775b8:
    unaff_s7 = (rsa_st *)(puVar24 + iVar8);
    if ((int)puVar6 < 1) {
      pBVar18 = unaff_s6->iqmp;
      iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
      iVar8 = iVar19 + 7;
      iVar3 = iVar19 + 0xe;
      if (-1 < iVar8) {
        iVar3 = iVar8;
      }
      prVar16 = (rsa_st *)(iVar3 >> 3);
      (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,unaff_s7);
      if (-1 >= iVar8) {
        iVar8 = iVar19 + 0x16;
      }
      iVar8 = iVar8 >> 4;
      puVar24 = (undefined *)((int)&prVar16[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      if (iVar8 < 1) {
        unaff_s7 = (rsa_st *)((int)&prVar16->pad + (int)&unaff_s7->pad);
        goto LAB_005776a4;
      }
      goto LAB_00577658;
    }
  }
  else {
    iVar3 = (int)puVar6 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006aab00)(puVar24,0,iVar3);
      puVar24 = puVar24 + iVar3;
    }
    pBVar18 = unaff_s6->q;
    iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar8 + 7;
    iVar3 = iVar8 + 0xe;
    if (-1 < iVar19) {
      iVar3 = iVar19;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
    iVar8 = iVar8 + 0x16;
    if (-1 < iVar19) {
      iVar8 = iVar19;
    }
    iVar8 = iVar8 >> 4;
    puVar23 = puVar24 + iVar3 + -1;
    if (iVar8 < 1) {
      puVar24 = puVar24 + iVar3;
    }
    else {
LAB_0057740c:
      puVar12 = puVar24;
      do {
        uVar1 = *puVar12;
        puVar10 = puVar12 + 1;
        *puVar12 = *puVar23;
        *puVar23 = uVar1;
        puVar12 = puVar10;
        puVar23 = puVar23 + -1;
      } while (puVar24 + iVar8 != puVar10);
      puVar24 = puVar24 + iVar3;
      if ((int)puVar6 < 1) goto LAB_00577bcc;
    }
    iVar3 = (int)puVar6 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006aab00)(puVar24,0,iVar3);
      puVar24 = puVar24 + iVar3;
    }
    pBVar18 = unaff_s6->dmp1;
    iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar19 = iVar8 + 7;
    iVar3 = iVar8 + 0xe;
    if (-1 < iVar19) {
      iVar3 = iVar19;
    }
    iVar3 = iVar3 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
    iVar8 = iVar8 + 0x16;
    if (-1 < iVar19) {
      iVar8 = iVar19;
    }
    iVar8 = iVar8 >> 4;
    puVar23 = puVar24 + iVar3 + -1;
    if (iVar8 < 1) {
      puVar24 = puVar24 + iVar3;
    }
    else {
LAB_005774d0:
      puVar12 = puVar24;
      do {
        uVar1 = *puVar12;
        puVar10 = puVar12 + 1;
        *puVar12 = *puVar23;
        *puVar23 = uVar1;
        puVar12 = puVar10;
        puVar23 = puVar23 + -1;
      } while (puVar24 + iVar8 != puVar10);
      puVar24 = puVar24 + iVar3;
      if ((int)puVar6 < 1) goto LAB_00577c44;
    }
    iVar3 = (int)puVar6 - iVar3;
    if (0 < iVar3) {
      (*(code *)PTR_memset_006aab00)(puVar24,0,iVar3);
      puVar24 = puVar24 + iVar3;
    }
    pBVar18 = unaff_s6->dmq1;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar3 = iVar19 + 7;
    iVar8 = iVar19 + 0xe;
    if (-1 < iVar3) {
      iVar8 = iVar3;
    }
    iVar8 = iVar8 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,puVar24);
    if (-1 >= iVar3) {
      iVar3 = iVar19 + 0x16;
    }
    iVar3 = iVar3 >> 4;
    puVar23 = puVar24 + iVar8 + -1;
    if (0 < iVar3) {
LAB_00577594:
      puVar12 = puVar24;
      do {
        uVar1 = *puVar12;
        puVar10 = puVar12 + 1;
        *puVar12 = *puVar23;
        *puVar23 = uVar1;
        puVar23 = puVar23 + -1;
        puVar12 = puVar10;
      } while (puVar24 + iVar3 != puVar10);
      goto LAB_005775b8;
    }
    unaff_s7 = (rsa_st *)(puVar24 + iVar8);
  }
  iVar8 = (int)puVar6 - iVar8;
  if (0 < iVar8) {
    (*(code *)PTR_memset_006aab00)(unaff_s7,0,iVar8);
    unaff_s7 = (rsa_st *)((int)unaff_s7 + iVar8);
  }
  pBVar18 = unaff_s6->iqmp;
  iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
  iVar8 = iVar19 + 7;
  iVar3 = iVar19 + 0xe;
  if (-1 < iVar8) {
    iVar3 = iVar8;
  }
  prVar16 = (rsa_st *)(iVar3 >> 3);
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,unaff_s7);
  if (-1 >= iVar8) {
    iVar8 = iVar19 + 0x16;
  }
  iVar8 = iVar8 >> 4;
  puVar24 = (undefined *)((int)&prVar16[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
  if (iVar8 < 1) goto LAB_00577dbc;
LAB_00577658:
  prVar13 = unaff_s7;
  do {
    uVar1 = *(undefined *)&prVar13->pad;
    prVar14 = (rsa_st *)((int)&prVar13->pad + 1);
    *(undefined *)&prVar13->pad = *puVar24;
    *puVar24 = uVar1;
    puVar24 = puVar24 + -1;
    prVar13 = prVar14;
  } while ((rsa_st *)((int)&unaff_s7->pad + iVar8) != prVar14);
  prVar13 = (rsa_st *)((int)&prVar16->pad + (int)&unaff_s7->pad);
  unaff_s7 = prVar13;
  if ((int)puVar6 < 1) goto LAB_005776a4;
  do {
    unaff_s7 = prVar13;
    if (0 < (int)puVar6 - (int)prVar16) {
      unaff_s7 = (rsa_st *)((int)prVar13 + ((int)puVar6 - (int)prVar16));
      (*(code *)PTR_memset_006aab00)(prVar13,0);
    }
LAB_005776a4:
    pBVar18 = unaff_s6->d;
    iVar19 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar18);
    iVar3 = iVar19 + 7;
    puVar6 = (undefined *)(uint)(iVar3 < 0);
    iVar8 = iVar19 + 0xe;
    if (puVar6 == (undefined *)0x0) {
      iVar8 = iVar3;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar18,unaff_s7);
    unaff_s6 = (rsa_st *)(iVar8 >> 3);
    if (puVar6 != (undefined *)0x0) {
      iVar3 = iVar19 + 0x16;
    }
    prVar16 = (rsa_st *)(iVar3 >> 4);
    if (0 < (int)prVar16) {
      prVar16 = (rsa_st *)((int)&prVar16->pad + (int)&unaff_s7->pad);
      puVar24 = (undefined *)((int)&unaff_s6[-1].mt_blinding + 3) + (int)&unaff_s7->pad;
      prVar13 = unaff_s7;
      do {
        uVar1 = *(undefined *)&prVar13->pad;
        prVar14 = (rsa_st *)((int)&prVar13->pad + 1);
        *(undefined *)&prVar13->pad = *puVar24;
        *puVar24 = uVar1;
        puVar24 = puVar24 + -1;
        prVar13 = prVar14;
      } while (prVar16 != prVar14);
    }
    prVar13 = prVar7;
    if ((0 < (int)prVar21) && (prVar16 = (rsa_st *)((int)prVar21 - (int)unaff_s6), 0 < (int)prVar16)
       ) {
      (*(code *)PTR_memset_006aab00)((char *)((int)&unaff_s6->pad + (int)&unaff_s7->pad),0);
    }
LAB_00577758:
    prVar7 = prVar13;
    unaff_s1 = prVar4;
    if ((int)prVar4 < 0) {
LAB_0057782c:
      prVar4 = (rsa_st *)0xffffffff;
    }
    else {
      prVar16 = prVar4;
      prVar7 = (rsa_st *)(*(code *)PTR_BIO_write_006a7f14)(pBVar15,prVar13);
      (*(code *)PTR_CRYPTO_free_006a7f88)(prVar13);
      if (prVar7 != prVar4) goto LAB_0057782c;
    }
LAB_00577790:
    if (iStack_84 == *(int *)puVar2) {
      return (EVP_PKEY *)prVar4;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    prVar4 = unaff_s1;
LAB_00577dbc:
    prVar13 = (rsa_st *)((int)&prVar16->pad + (int)&unaff_s7->pad);
  } while( true );
}

