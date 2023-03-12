
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
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_4c = *(DH **)(param_2 + 0x14);
  pBStack_54 = (BIGNUM *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  puVar2 = (ulong *)i2d_DHparams(pDStack_4c,(uchar **)&pBStack_54->dmax);
  pBStack_54->d = puVar2;
  if ((int)puVar2 < 1) {
    uVar9 = 0x6d;
    ERR_put_error(5,0x6d,0x41,"dh_ameth.c",0x91);
    if (local_20 == 0) goto LAB_00518e24;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    uVar5 = 0;
  }
  else {
    uVar9 = 0;
    pDVar3 = (DH *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(pDStack_4c->pub_key);
    pDStack_4c = pDVar3;
    if (pDVar3 != (DH *)0x0) {
      pDStack_4c = (DH *)(*(code *)PTR_i2d_ASN1_INTEGER_006a94f4)(pDVar3,&local_20);
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(pDVar3);
      if ((int)pDStack_4c < 1) {
        uVar9 = 0x6d;
        ERR_put_error(5,0x6d,0x41,"dh_ameth.c",0xa1);
      }
      else {
        uVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x1c);
        iVar4 = (*(code *)PTR_X509_PUBKEY_set0_param_006a98c8)(param_1,uVar9,0x10,pBStack_54);
        if (iVar4 != 0) {
          uVar5 = 1;
          goto LAB_00518e28;
        }
      }
    }
    if (local_20 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(pBStack_54);
LAB_00518e24:
    uVar5 = 0;
  }
LAB_00518e28:
  if (local_1c == *(int *)puStack_50) {
    return uVar5;
  }
  pcStack_44 = dh_pub_decode;
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pDVar3 = (DH *)&iStack_6c;
  pBStack_5c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  puVar10 = auStack_74;
  pBStack_48 = param_1;
  iVar6 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)(0,auStack_74,pDVar3,&pBStack_60,uVar9);
  if (iVar6 == 0) {
LAB_00518f38:
    uVar9 = 0;
  }
  else {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&iStack_68,&pBStack_64,pBStack_60);
    if (iStack_68 != 0x10) {
      pDVar3 = (DH *)&DAT_00000069;
      iVar4 = 0x59;
LAB_00518fa0:
      puVar10 = &DAT_0000006c;
      ERR_put_error(5,0x6c,(int)pDVar3,"dh_ameth.c",iVar4);
      goto LAB_00518f38;
    }
    puStack_70 = (uchar *)pBStack_64->dmax;
    dh = d2i_DHparams((DH **)0x0,&puStack_70,(long)pBStack_64->d);
    if (dh == (DH *)0x0) {
      pDVar3 = (DH *)&DAT_00000068;
      iVar4 = 99;
      goto LAB_00518fa0;
    }
    iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(0,auStack_74,iStack_6c);
    if (iVar6 == 0) {
      pDVar3 = (DH *)&DAT_00000068;
      puVar10 = &DAT_0000006c;
      ERR_put_error(5,0x6c,0x68,"dh_ameth.c",0x69);
LAB_00519088:
      DH_free(dh);
      uVar9 = 0;
    }
    else {
      pBVar7 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar6,0);
      dh->pub_key = pBVar7;
      if (pBVar7 == (BIGNUM *)0x0) {
        pDVar3 = (DH *)&DAT_0000006d;
        puVar10 = &DAT_0000006c;
        ERR_put_error(5,0x6c,0x6d,"dh_ameth.c",0x70);
        (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar6);
        goto LAB_00519088;
      }
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar6);
      puVar10 = (undefined *)0x1c;
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar4);
      uVar9 = 1;
      pDVar3 = dh;
    }
  }
  if (pBStack_5c == *(BIO **)puVar1) {
    return uVar9;
  }
  b = pBStack_5c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = *(int *)(puVar10 + 0x14);
  if (*(int *)(iVar4 + 8) != 0) {
    iVar12 = *(int *)(iVar4 + 0x18);
    iVar13 = *(int *)(iVar4 + 0x14);
    iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar6 = iVar8 + 7;
    if (iVar8 + 7 < 0) {
      iVar6 = iVar8 + 0xe;
    }
    uVar11 = iVar6 >> 3;
    if (uVar11 != 0) {
      if (*(int *)(iVar4 + 0xc) != 0) {
        iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)();
        iVar6 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar6 = iVar8 + 0xe;
        }
        if (uVar11 < (uint)(iVar6 >> 3)) {
          uVar11 = iVar6 >> 3;
        }
      }
      if (iVar13 != 0) {
        iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar13);
        iVar6 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar6 = iVar8 + 0xe;
        }
        if (uVar11 < (uint)(iVar6 >> 3)) {
          uVar11 = iVar6 >> 3;
        }
      }
      if (iVar12 != 0) {
        iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar12);
        iVar6 = iVar8 + 7;
        if (iVar8 + 7 < 0) {
          iVar6 = iVar8 + 0xe;
        }
        if (uVar11 < (uint)(iVar6 >> 3)) {
          uVar11 = iVar6 >> 3;
        }
      }
      iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar11 + 10,"dh_ameth.c",0x164);
      if (iVar6 != 0) {
        BIO_indent(b,(int)pDVar3,0x80);
        uVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar4 + 8));
        iVar8 = BIO_printf(b,"%s: (%d bit)\n","PKCS#3 DH Private-Key",uVar9);
        if (0 < iVar8) {
          indent = &pDVar3->version;
          iVar8 = (*(code *)PTR_ASN1_bn_print_006a97dc)(b,"private-key:",iVar12,iVar6,indent);
          if (iVar8 != 0) {
            iVar8 = (*(code *)PTR_ASN1_bn_print_006a97dc)(b,"public-key:",iVar13,iVar6,indent);
            if (iVar8 != 0) {
              iVar8 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                                (b,"prime:",*(undefined4 *)(iVar4 + 8),iVar6,indent);
              if (iVar8 != 0) {
                iVar8 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                                  (b,"generator:",*(undefined4 *)(iVar4 + 0xc),iVar6,indent);
                if (iVar8 != 0) {
                  if (*(int *)(iVar4 + 0x10) == 0) {
                    uVar9 = 1;
                    goto LAB_00519310;
                  }
                  BIO_indent(b,(int)indent,0x80);
                  iVar4 = BIO_printf(b,"recommended-private-length: %d bits\n",
                                     *(undefined4 *)(iVar4 + 0x10));
                  if (0 < iVar4) {
                    uVar9 = 1;
                    goto LAB_00519310;
                  }
                }
              }
            }
          }
        }
        uVar9 = 0;
        ERR_put_error(5,100,7,"dh_ameth.c",0x181);
LAB_00519310:
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
        return uVar9;
      }
      iVar4 = 0x41;
      goto LAB_00519168;
    }
  }
  iVar4 = 0x43;
LAB_00519168:
  ERR_put_error(5,100,iVar4,"dh_ameth.c",0x181);
  return 0;
}

