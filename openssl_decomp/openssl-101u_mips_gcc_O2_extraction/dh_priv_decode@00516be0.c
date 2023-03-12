
int dh_priv_decode(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  BIGNUM *pBVar3;
  ulong *puVar4;
  DH *pDVar5;
  int iVar6;
  DH *dh;
  BIGNUM *pBVar7;
  int iVar8;
  BIO *b;
  undefined4 uVar9;
  undefined *puVar10;
  uint uVar11;
  int *indent;
  int unaff_s3;
  int iVar12;
  int iVar13;
  undefined auStack_cc [4];
  uchar *puStack_c8;
  int iStack_c4;
  int iStack_c0;
  BIGNUM *pBStack_bc;
  BIGNUM *pBStack_b8;
  BIO *pBStack_b4;
  BIGNUM *pBStack_ac;
  undefined *puStack_a8;
  DH *pDStack_a4;
  BIGNUM *pBStack_a0;
  code *pcStack_9c;
  int iStack_78;
  int iStack_74;
  undefined *puStack_6c;
  DH *pDStack_68;
  undefined4 uStack_64;
  int iStack_60;
  code *pcStack_5c;
  uchar *local_30;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  long *local_24;
  BIGNUM *local_20;
  BIGNUM *local_1c;
  
  pBVar7 = (BIGNUM *)PTR___stack_chk_guard_006a9ae8;
  pDStack_68 = (DH *)&stack0xffffffcc;
  local_1c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pDVar5 = pDStack_68;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a87a0)(0,pDStack_68,&local_2c,&local_20);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&local_28,&local_24,local_20);
    if ((local_28 == (BIGNUM *)&SUB_00000010) &&
       (unaff_s3 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,pDStack_68,local_2c), unaff_s3 != 0))
    {
      local_30 = (uchar *)local_24[2];
      pDStack_68 = d2i_DHparams((DH **)0x0,&local_30,*local_24);
      if (pDStack_68 == (DH *)0x0) goto LAB_00516c94;
      pDVar5 = (DH *)0x0;
      pBVar3 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(unaff_s3);
      pDStack_68->priv_key = pBVar3;
      if (pBVar3 == (BIGNUM *)0x0) {
        pDVar5 = (DH *)&DAT_0000006e;
        ERR_put_error(5,0x6e,0x6a,"dh_ameth.c",0xd3);
      }
      else {
        iVar2 = DH_generate_key(pDStack_68);
        if (iVar2 != 0) {
          pDVar5 = (DH *)0x1c;
          (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x1c,pDStack_68);
          (*(code *)PTR_ASN1_STRING_clear_free_006a8794)(unaff_s3);
          iVar2 = 1;
          goto LAB_00516c40;
        }
      }
    }
    else {
      unaff_s3 = 0;
LAB_00516c94:
      pDVar5 = (DH *)&DAT_0000006e;
      pDStack_68 = (DH *)0x0;
      ERR_put_error(5,0x6e,0x72,"dh_ameth.c",0xe1);
    }
    DH_free(pDStack_68);
    (*(code *)PTR_ASN1_STRING_clear_free_006a8794)(unaff_s3);
    iVar2 = 0;
  }
LAB_00516c40:
  if (local_1c == *(BIGNUM **)pBVar7) {
    return iVar2;
  }
  pcStack_5c = dh_pub_encode;
  pBStack_a0 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_a8 = PTR___stack_chk_guard_006a9ae8;
  iStack_60 = unaff_s3;
  uStack_64 = param_1;
  puStack_6c = (undefined *)pBVar7;
  iStack_78 = 0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pDStack_a4 = (DH *)pDVar5->pub_key;
  pBStack_ac = (BIGNUM *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
  if (pBStack_ac == (BIGNUM *)0x0) {
    uVar9 = 0x6d;
    ERR_put_error(5,0x6d,0x41,"dh_ameth.c",0x8b);
    if (iStack_78 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
LAB_00516eec:
    iVar2 = 0;
    pBStack_ac = pBVar7;
  }
  else {
    puVar4 = (ulong *)i2d_DHparams(pDStack_a4,(uchar **)&pBStack_ac->dmax);
    pBStack_ac->d = puVar4;
    if ((int)puVar4 < 1) {
      iVar2 = 0x90;
LAB_00516f2c:
      uVar9 = 0x6d;
      ERR_put_error(5,0x6d,0x41,"dh_ameth.c",iVar2);
joined_r0x00516f40:
      if (iStack_78 != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pBStack_ac);
      pBVar7 = pBStack_ac;
      goto LAB_00516eec;
    }
    uVar9 = 0;
    pDVar5 = (DH *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(pDStack_a4->pub_key);
    pDStack_a4 = pDVar5;
    if (pDVar5 == (DH *)0x0) goto joined_r0x00516f40;
    pDStack_a4 = (DH *)(*(code *)PTR_i2d_ASN1_INTEGER_006a83dc)(pDVar5,&iStack_78);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(pDVar5);
    if ((int)pDStack_a4 < 1) {
      iVar2 = 0x9e;
      goto LAB_00516f2c;
    }
    uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x1c);
    iVar2 = (*(code *)PTR_X509_PUBKEY_set0_param_006a87a8)(pBStack_a0,uVar9,0x10,pBStack_ac);
    if (iVar2 == 0) goto joined_r0x00516f40;
    iVar2 = 1;
  }
  if (iStack_74 == *(int *)puStack_a8) {
    return iVar2;
  }
  pcStack_9c = dh_pub_decode;
  iVar2 = iStack_74;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pDVar5 = (DH *)&iStack_c4;
  pBStack_b4 = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  puVar10 = auStack_cc;
  iVar6 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)(0,auStack_cc,pDVar5,&pBStack_b8,uVar9);
  if (iVar6 == 0) {
LAB_00517020:
    iVar2 = 0;
  }
  else {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&iStack_c0,&pBStack_bc,pBStack_b8);
    if (iStack_c0 != 0x10) {
      pDVar5 = (DH *)&DAT_00000069;
      iVar2 = 0x59;
LAB_00517088:
      puVar10 = &DAT_0000006c;
      ERR_put_error(5,0x6c,(int)pDVar5,"dh_ameth.c",iVar2);
      goto LAB_00517020;
    }
    puStack_c8 = (uchar *)pBStack_bc->dmax;
    dh = d2i_DHparams((DH **)0x0,&puStack_c8,(long)pBStack_bc->d);
    if (dh == (DH *)0x0) {
      pDVar5 = (DH *)&DAT_00000068;
      iVar2 = 0x62;
      goto LAB_00517088;
    }
    iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,auStack_cc,iStack_c4);
    if (iVar6 == 0) {
      pDVar5 = (DH *)&DAT_00000068;
      puVar10 = &DAT_0000006c;
      ERR_put_error(5,0x6c,0x68,"dh_ameth.c",0x67);
LAB_00517170:
      DH_free(dh);
      iVar2 = 0;
    }
    else {
      pBVar7 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar6,0);
      dh->pub_key = pBVar7;
      if (pBVar7 == (BIGNUM *)0x0) {
        pDVar5 = (DH *)&DAT_0000006d;
        puVar10 = &DAT_0000006c;
        ERR_put_error(5,0x6c,0x6d,"dh_ameth.c",0x6d);
        (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar6);
        goto LAB_00517170;
      }
      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar6);
      puVar10 = (undefined *)0x1c;
      (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar2);
      iVar2 = 1;
      pDVar5 = dh;
    }
  }
  if (pBStack_b4 == *(BIO **)puVar1) {
    return iVar2;
  }
  b = pBStack_b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = *(int *)(puVar10 + 0x14);
  if (*(int *)(iVar2 + 8) != 0) {
    iVar12 = *(int *)(iVar2 + 0x18);
    iVar13 = *(int *)(iVar2 + 0x14);
    iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar6 = iVar8 + 7;
    if (iVar8 + 7 < 0) {
      iVar6 = iVar8 + 0xe;
    }
    uVar11 = iVar6 >> 3;
    if (uVar11 != 0) {
      if (*(int *)(iVar2 + 0xc) != 0) {
        iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)();
        iVar6 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar6 = iVar8 + 0xe;
        }
        if (uVar11 < (uint)(iVar6 >> 3)) {
          uVar11 = iVar6 >> 3;
        }
      }
      if (iVar13 != 0) {
        iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar13);
        iVar6 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar6 = iVar8 + 0xe;
        }
        if (uVar11 < (uint)(iVar6 >> 3)) {
          uVar11 = iVar6 >> 3;
        }
      }
      if (iVar12 != 0) {
        iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar12);
        iVar6 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar6 = iVar8 + 0xe;
        }
        if (uVar11 < (uint)(iVar6 >> 3)) {
          uVar11 = iVar6 >> 3;
        }
      }
      iVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar11 + 10,"dh_ameth.c",0x15b);
      if (iVar6 != 0) {
        BIO_indent(b,(int)pDVar5,0x80);
        uVar9 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar2 + 8));
        iVar8 = BIO_printf(b,"%s: (%d bit)\n","PKCS#3 DH Private-Key",uVar9);
        if (0 < iVar8) {
          indent = &pDVar5->version;
          iVar8 = (*(code *)PTR_ASN1_bn_print_006a86b8)(b,"private-key:",iVar12,iVar6,indent);
          if ((((iVar8 != 0) &&
               (iVar8 = (*(code *)PTR_ASN1_bn_print_006a86b8)(b,"public-key:",iVar13,iVar6,indent),
               iVar8 != 0)) &&
              (iVar8 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                 (b,"prime:",*(undefined4 *)(iVar2 + 8),iVar6,indent), iVar8 != 0))
             && (iVar8 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                   (b,"generator:",*(undefined4 *)(iVar2 + 0xc),iVar6,indent),
                iVar8 != 0)) {
            if (*(int *)(iVar2 + 0x10) == 0) {
              iVar2 = 1;
              goto LAB_005173f8;
            }
            BIO_indent(b,(int)indent,0x80);
            iVar2 = BIO_printf(b,"recommended-private-length: %d bits\n",
                               *(undefined4 *)(iVar2 + 0x10));
            if (0 < iVar2) {
              iVar2 = 1;
              goto LAB_005173f8;
            }
          }
        }
        iVar2 = 0;
        ERR_put_error(5,100,7,"dh_ameth.c",0x179);
LAB_005173f8:
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
        return iVar2;
      }
      iVar2 = 0x41;
      goto LAB_00517250;
    }
  }
  iVar2 = 0x43;
LAB_00517250:
  ERR_put_error(5,100,iVar2,"dh_ameth.c",0x179);
  return 0;
}

