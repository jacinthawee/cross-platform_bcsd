
undefined4 dh_pub_encode(BIGNUM *param_1,int param_2)

{
  undefined *puVar1;
  ulong *puVar2;
  DH *pDVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  DH *dh;
  BIGNUM *pBVar7;
  int iVar8;
  BIO *b;
  undefined4 uVar9;
  undefined *puVar10;
  BIGNUM *unaff_s0;
  uint uVar11;
  int *indent;
  int iVar12;
  int iVar13;
  undefined auStack_74 [4];
  uchar *puStack_70;
  int iStack_6c;
  int iStack_68;
  BIGNUM *pBStack_64;
  BIGNUM *pBStack_60;
  BIO *pBStack_5c;
  BIGNUM *pBStack_54;
  undefined *puStack_50;
  DH *pDStack_4c;
  BIGNUM *pBStack_48;
  code *pcStack_44;
  int local_20;
  int local_1c;
  
  puStack_50 = PTR___stack_chk_guard_006a9ae8;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pDStack_4c = *(DH **)(param_2 + 0x14);
  pBStack_54 = (BIGNUM *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
  if (pBStack_54 == (BIGNUM *)0x0) {
    uVar9 = 0x6d;
    ERR_put_error(5,0x6d,0x41,"dh_ameth.c",0x8b);
    if (local_20 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
LAB_00516eec:
    uVar5 = 0;
    pBStack_54 = unaff_s0;
  }
  else {
    puVar2 = (ulong *)i2d_DHparams(pDStack_4c,(uchar **)&pBStack_54->dmax);
    pBStack_54->d = puVar2;
    if ((int)puVar2 < 1) {
      iVar4 = 0x90;
LAB_00516f2c:
      uVar9 = 0x6d;
      ERR_put_error(5,0x6d,0x41,"dh_ameth.c",iVar4);
joined_r0x00516f40:
      if (local_20 != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pBStack_54);
      unaff_s0 = pBStack_54;
      goto LAB_00516eec;
    }
    uVar9 = 0;
    pDVar3 = (DH *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(pDStack_4c->pub_key);
    pDStack_4c = pDVar3;
    if (pDVar3 == (DH *)0x0) goto joined_r0x00516f40;
    pDStack_4c = (DH *)(*(code *)PTR_i2d_ASN1_INTEGER_006a83dc)(pDVar3,&local_20);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(pDVar3);
    if ((int)pDStack_4c < 1) {
      iVar4 = 0x9e;
      goto LAB_00516f2c;
    }
    uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x1c);
    iVar4 = (*(code *)PTR_X509_PUBKEY_set0_param_006a87a8)(param_1,uVar9,0x10,pBStack_54);
    if (iVar4 == 0) goto joined_r0x00516f40;
    uVar5 = 1;
  }
  if (local_1c == *(int *)puStack_50) {
    return uVar5;
  }
  pcStack_44 = dh_pub_decode;
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pDVar3 = (DH *)&iStack_6c;
  pBStack_5c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  puVar10 = auStack_74;
  pBStack_48 = param_1;
  iVar6 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)(0,auStack_74,pDVar3,&pBStack_60,uVar9);
  if (iVar6 == 0) {
LAB_00517020:
    uVar9 = 0;
  }
  else {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&iStack_68,&pBStack_64,pBStack_60);
    if (iStack_68 != 0x10) {
      pDVar3 = (DH *)&DAT_00000069;
      iVar4 = 0x59;
LAB_00517088:
      puVar10 = &DAT_0000006c;
      ERR_put_error(5,0x6c,(int)pDVar3,"dh_ameth.c",iVar4);
      goto LAB_00517020;
    }
    puStack_70 = (uchar *)pBStack_64->dmax;
    dh = d2i_DHparams((DH **)0x0,&puStack_70,(long)pBStack_64->d);
    if (dh == (DH *)0x0) {
      pDVar3 = (DH *)&DAT_00000068;
      iVar4 = 0x62;
      goto LAB_00517088;
    }
    iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,auStack_74,iStack_6c);
    if (iVar6 == 0) {
      pDVar3 = (DH *)&DAT_00000068;
      puVar10 = &DAT_0000006c;
      ERR_put_error(5,0x6c,0x68,"dh_ameth.c",0x67);
LAB_00517170:
      DH_free(dh);
      uVar9 = 0;
    }
    else {
      pBVar7 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar6,0);
      dh->pub_key = pBVar7;
      if (pBVar7 == (BIGNUM *)0x0) {
        pDVar3 = (DH *)&DAT_0000006d;
        puVar10 = &DAT_0000006c;
        ERR_put_error(5,0x6c,0x6d,"dh_ameth.c",0x6d);
        (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar6);
        goto LAB_00517170;
      }
      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar6);
      puVar10 = (undefined *)0x1c;
      (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar4);
      uVar9 = 1;
      pDVar3 = dh;
    }
  }
  if (pBStack_5c == *(BIO **)puVar1) {
    return uVar9;
  }
  b = pBStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = *(int *)(puVar10 + 0x14);
  if (*(int *)(iVar4 + 8) != 0) {
    iVar12 = *(int *)(iVar4 + 0x18);
    iVar13 = *(int *)(iVar4 + 0x14);
    iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar6 = iVar8 + 7;
    if (iVar8 + 7 < 0) {
      iVar6 = iVar8 + 0xe;
    }
    uVar11 = iVar6 >> 3;
    if (uVar11 != 0) {
      if (*(int *)(iVar4 + 0xc) != 0) {
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
        BIO_indent(b,(int)pDVar3,0x80);
        uVar9 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar4 + 8));
        iVar8 = BIO_printf(b,"%s: (%d bit)\n","PKCS#3 DH Private-Key",uVar9);
        if (0 < iVar8) {
          indent = &pDVar3->version;
          iVar8 = (*(code *)PTR_ASN1_bn_print_006a86b8)(b,"private-key:",iVar12,iVar6,indent);
          if ((((iVar8 != 0) &&
               (iVar8 = (*(code *)PTR_ASN1_bn_print_006a86b8)(b,"public-key:",iVar13,iVar6,indent),
               iVar8 != 0)) &&
              (iVar8 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                 (b,"prime:",*(undefined4 *)(iVar4 + 8),iVar6,indent), iVar8 != 0))
             && (iVar8 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                   (b,"generator:",*(undefined4 *)(iVar4 + 0xc),iVar6,indent),
                iVar8 != 0)) {
            if (*(int *)(iVar4 + 0x10) == 0) {
              uVar9 = 1;
              goto LAB_005173f8;
            }
            BIO_indent(b,(int)indent,0x80);
            iVar4 = BIO_printf(b,"recommended-private-length: %d bits\n",
                               *(undefined4 *)(iVar4 + 0x10));
            if (0 < iVar4) {
              uVar9 = 1;
              goto LAB_005173f8;
            }
          }
        }
        uVar9 = 0;
        ERR_put_error(5,100,7,"dh_ameth.c",0x179);
LAB_005173f8:
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
        return uVar9;
      }
      iVar4 = 0x41;
      goto LAB_00517250;
    }
  }
  iVar4 = 0x43;
LAB_00517250:
  ERR_put_error(5,100,iVar4,"dh_ameth.c",0x179);
  return 0;
}

