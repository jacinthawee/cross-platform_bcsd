
int dh_priv_decode(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  ulong *puVar3;
  DH *pDVar4;
  int iVar5;
  DH *dh;
  BIGNUM *pBVar6;
  int iVar7;
  BIO *b;
  undefined4 uVar8;
  undefined *puVar9;
  uint uVar10;
  int *indent;
  int unaff_s3;
  int iVar11;
  int iVar12;
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
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  pDStack_68 = (DH *)&stack0xffffffcc;
  local_1c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  pDVar4 = pDStack_68;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a98c0)(0,pDStack_68,&local_2c,&local_20);
  if (iVar2 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&local_28,&local_24,local_20);
    if ((local_28 == (BIGNUM *)&SUB_00000010) &&
       (unaff_s3 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(0,pDStack_68,local_2c), unaff_s3 != 0))
    {
      local_30 = (uchar *)local_24[2];
      pDStack_68 = d2i_DHparams((DH **)0x0,&local_30,*local_24);
      if (pDStack_68 == (DH *)0x0) goto LAB_00518be4;
      pDVar4 = (DH *)0x0;
      pBVar6 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(unaff_s3);
      pDStack_68->priv_key = pBVar6;
      if (pBVar6 == (BIGNUM *)0x0) {
        pDVar4 = (DH *)&DAT_0000006e;
        ERR_put_error(5,0x6e,0x6a,"dh_ameth.c",0xd8);
      }
      else {
        iVar2 = DH_generate_key(pDStack_68);
        if (iVar2 != 0) {
          pDVar4 = (DH *)0x1c;
          (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x1c,pDStack_68);
          (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(unaff_s3);
          iVar2 = 1;
          goto LAB_00518b94;
        }
      }
    }
    else {
LAB_00518be4:
      pDVar4 = (DH *)&DAT_0000006e;
      pDStack_68 = (DH *)0x0;
      ERR_put_error(5,0x6e,0x72,"dh_ameth.c",0xe6);
    }
    DH_free(pDStack_68);
    iVar2 = 0;
  }
LAB_00518b94:
  if (local_1c == *(BIGNUM **)puStack_6c) {
    return iVar2;
  }
  pcStack_5c = dh_pub_encode;
  pBStack_a0 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_a8 = PTR___stack_chk_guard_006aabf0;
  iStack_60 = unaff_s3;
  uStack_64 = param_1;
  iStack_78 = 0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_a4 = (DH *)pDVar4->pub_key;
  pBStack_ac = (BIGNUM *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  puVar3 = (ulong *)i2d_DHparams(pDStack_a4,(uchar **)&pBStack_ac->dmax);
  pBStack_ac->d = puVar3;
  if ((int)puVar3 < 1) {
    uVar8 = 0x6d;
    ERR_put_error(5,0x6d,0x41,"dh_ameth.c",0x91);
    if (iStack_78 == 0) goto LAB_00518e24;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    iVar2 = 0;
  }
  else {
    uVar8 = 0;
    pDVar4 = (DH *)(*(code *)PTR_BN_to_ASN1_INTEGER_006a81f4)(pDStack_a4->pub_key);
    pDStack_a4 = pDVar4;
    if (pDVar4 != (DH *)0x0) {
      pDStack_a4 = (DH *)(*(code *)PTR_i2d_ASN1_INTEGER_006a94f4)(pDVar4,&iStack_78);
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(pDVar4);
      if ((int)pDStack_a4 < 1) {
        uVar8 = 0x6d;
        ERR_put_error(5,0x6d,0x41,"dh_ameth.c",0xa1);
      }
      else {
        uVar8 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x1c);
        iVar2 = (*(code *)PTR_X509_PUBKEY_set0_param_006a98c8)(pBStack_a0,uVar8,0x10,pBStack_ac);
        if (iVar2 != 0) {
          iVar2 = 1;
          goto LAB_00518e28;
        }
      }
    }
    if (iStack_78 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_ASN1_STRING_free_006a98bc)(pBStack_ac);
LAB_00518e24:
    iVar2 = 0;
  }
LAB_00518e28:
  if (iStack_74 == *(int *)puStack_a8) {
    return iVar2;
  }
  pcStack_9c = dh_pub_decode;
  iVar2 = iStack_74;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pDVar4 = (DH *)&iStack_c4;
  pBStack_b4 = *(BIO **)PTR___stack_chk_guard_006aabf0;
  puVar9 = auStack_cc;
  iVar5 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)(0,auStack_cc,pDVar4,&pBStack_b8,uVar8);
  if (iVar5 == 0) {
LAB_00518f38:
    iVar2 = 0;
  }
  else {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&iStack_c0,&pBStack_bc,pBStack_b8);
    if (iStack_c0 != 0x10) {
      pDVar4 = (DH *)&DAT_00000069;
      iVar2 = 0x59;
LAB_00518fa0:
      puVar9 = &DAT_0000006c;
      ERR_put_error(5,0x6c,(int)pDVar4,"dh_ameth.c",iVar2);
      goto LAB_00518f38;
    }
    puStack_c8 = (uchar *)pBStack_bc->dmax;
    dh = d2i_DHparams((DH **)0x0,&puStack_c8,(long)pBStack_bc->d);
    if (dh == (DH *)0x0) {
      pDVar4 = (DH *)&DAT_00000068;
      iVar2 = 99;
      goto LAB_00518fa0;
    }
    iVar5 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(0,auStack_cc,iStack_c4);
    if (iVar5 == 0) {
      pDVar4 = (DH *)&DAT_00000068;
      puVar9 = &DAT_0000006c;
      ERR_put_error(5,0x6c,0x68,"dh_ameth.c",0x69);
LAB_00519088:
      DH_free(dh);
      iVar2 = 0;
    }
    else {
      pBVar6 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar5,0);
      dh->pub_key = pBVar6;
      if (pBVar6 == (BIGNUM *)0x0) {
        pDVar4 = (DH *)&DAT_0000006d;
        puVar9 = &DAT_0000006c;
        ERR_put_error(5,0x6c,0x6d,"dh_ameth.c",0x70);
        (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar5);
        goto LAB_00519088;
      }
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar5);
      puVar9 = (undefined *)0x1c;
      (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2);
      iVar2 = 1;
      pDVar4 = dh;
    }
  }
  if (pBStack_b4 == *(BIO **)puVar1) {
    return iVar2;
  }
  b = pBStack_b4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = *(int *)(puVar9 + 0x14);
  if (*(int *)(iVar2 + 8) != 0) {
    iVar11 = *(int *)(iVar2 + 0x18);
    iVar12 = *(int *)(iVar2 + 0x14);
    iVar7 = (*(code *)PTR_BN_num_bits_006a82f4)();
    iVar5 = iVar7 + 7;
    if (iVar7 + 7 < 0) {
      iVar5 = iVar7 + 0xe;
    }
    uVar10 = iVar5 >> 3;
    if (uVar10 != 0) {
      if (*(int *)(iVar2 + 0xc) != 0) {
        iVar7 = (*(code *)PTR_BN_num_bits_006a82f4)();
        iVar5 = iVar7 + 7;
        if (iVar7 + 7 < 0) {
          iVar5 = iVar7 + 0xe;
        }
        if (uVar10 < (uint)(iVar5 >> 3)) {
          uVar10 = iVar5 >> 3;
        }
      }
      if (iVar12 != 0) {
        iVar7 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar12);
        iVar5 = iVar7 + 7;
        if (iVar7 + 7 < 0) {
          iVar5 = iVar7 + 0xe;
        }
        if (uVar10 < (uint)(iVar5 >> 3)) {
          uVar10 = iVar5 >> 3;
        }
      }
      if (iVar11 != 0) {
        iVar7 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar11);
        iVar5 = iVar7 + 7;
        if (iVar7 + 7 < 0) {
          iVar5 = iVar7 + 0xe;
        }
        if (uVar10 < (uint)(iVar5 >> 3)) {
          uVar10 = iVar5 >> 3;
        }
      }
      iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar10 + 10,"dh_ameth.c",0x164);
      if (iVar5 != 0) {
        BIO_indent(b,(int)pDVar4,0x80);
        uVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar2 + 8));
        iVar7 = BIO_printf(b,"%s: (%d bit)\n","PKCS#3 DH Private-Key",uVar8);
        if (0 < iVar7) {
          indent = &pDVar4->version;
          iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)(b,"private-key:",iVar11,iVar5,indent);
          if (iVar7 != 0) {
            iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)(b,"public-key:",iVar12,iVar5,indent);
            if (iVar7 != 0) {
              iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                                (b,"prime:",*(undefined4 *)(iVar2 + 8),iVar5,indent);
              if (iVar7 != 0) {
                iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)
                                  (b,"generator:",*(undefined4 *)(iVar2 + 0xc),iVar5,indent);
                if (iVar7 != 0) {
                  if (*(int *)(iVar2 + 0x10) == 0) {
                    iVar2 = 1;
                    goto LAB_00519310;
                  }
                  BIO_indent(b,(int)indent,0x80);
                  iVar2 = BIO_printf(b,"recommended-private-length: %d bits\n",
                                     *(undefined4 *)(iVar2 + 0x10));
                  if (0 < iVar2) {
                    iVar2 = 1;
                    goto LAB_00519310;
                  }
                }
              }
            }
          }
        }
        iVar2 = 0;
        ERR_put_error(5,100,7,"dh_ameth.c",0x181);
LAB_00519310:
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
        return iVar2;
      }
      iVar2 = 0x41;
      goto LAB_00519168;
    }
  }
  iVar2 = 0x43;
LAB_00519168:
  ERR_put_error(5,100,iVar2,"dh_ameth.c",0x181);
  return 0;
}

