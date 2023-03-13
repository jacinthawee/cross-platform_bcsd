
undefined4 dh_pub_decode(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  DH *dh;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  BIO *b;
  undefined *puVar7;
  DH *reason;
  uint uVar8;
  int *indent;
  int iVar9;
  int iVar10;
  undefined auStack_34 [4];
  uchar *local_30;
  int local_2c;
  int local_28;
  BIGNUM *local_24;
  BIGNUM *local_20;
  BIO *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  reason = (DH *)&local_2c;
  local_1c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  puVar7 = auStack_34;
  iVar2 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)(0,auStack_34,reason,&local_20,param_2);
  if (iVar2 == 0) {
LAB_00517020:
    uVar3 = 0;
  }
  else {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&local_28,&local_24,local_20);
    if (local_28 != 0x10) {
      reason = (DH *)&DAT_00000069;
      iVar2 = 0x59;
LAB_00517088:
      puVar7 = &DAT_0000006c;
      ERR_put_error(5,0x6c,(int)reason,"dh_ameth.c",iVar2);
      goto LAB_00517020;
    }
    local_30 = (uchar *)local_24->dmax;
    dh = d2i_DHparams((DH **)0x0,&local_30,(long)local_24->d);
    if (dh == (DH *)0x0) {
      reason = (DH *)&DAT_00000068;
      iVar2 = 0x62;
      goto LAB_00517088;
    }
    iVar2 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,auStack_34,local_2c);
    if (iVar2 == 0) {
      reason = (DH *)&DAT_00000068;
      puVar7 = &DAT_0000006c;
      ERR_put_error(5,0x6c,0x68,"dh_ameth.c",0x67);
LAB_00517170:
      DH_free(dh);
      uVar3 = 0;
    }
    else {
      pBVar4 = (BIGNUM *)(*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar2,0);
      dh->pub_key = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) {
        reason = (DH *)&DAT_0000006d;
        puVar7 = &DAT_0000006c;
        ERR_put_error(5,0x6c,0x6d,"dh_ameth.c",0x6d);
        (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar2);
        goto LAB_00517170;
      }
      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar2);
      puVar7 = (undefined *)0x1c;
      (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1);
      uVar3 = 1;
      reason = dh;
    }
  }
  if (local_1c == *(BIO **)puVar1) {
    return uVar3;
  }
  b = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = *(int *)(puVar7 + 0x14);
  if (*(int *)(iVar2 + 8) != 0) {
    iVar9 = *(int *)(iVar2 + 0x18);
    iVar10 = *(int *)(iVar2 + 0x14);
    iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar6 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar6 = iVar5 + 0xe;
    }
    uVar8 = iVar6 >> 3;
    if (uVar8 != 0) {
      if (*(int *)(iVar2 + 0xc) != 0) {
        iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)();
        iVar6 = iVar5 + 7;
        if (iVar5 + 7 < 0) {
          iVar6 = iVar5 + 0xe;
        }
        if (uVar8 < (uint)(iVar6 >> 3)) {
          uVar8 = iVar6 >> 3;
        }
      }
      if (iVar10 != 0) {
        iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar10);
        iVar6 = iVar5 + 7;
        if (iVar5 + 7 < 0) {
          iVar6 = iVar5 + 0xe;
        }
        if (uVar8 < (uint)(iVar6 >> 3)) {
          uVar8 = iVar6 >> 3;
        }
      }
      if (iVar9 != 0) {
        iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar9);
        iVar6 = iVar5 + 7;
        if (iVar5 + 7 < 0) {
          iVar6 = iVar5 + 0xe;
        }
        if (uVar8 < (uint)(iVar6 >> 3)) {
          uVar8 = iVar6 >> 3;
        }
      }
      iVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar8 + 10,"dh_ameth.c",0x15b);
      if (iVar6 != 0) {
        BIO_indent(b,(int)reason,0x80);
        uVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar2 + 8));
        iVar5 = BIO_printf(b,"%s: (%d bit)\n","PKCS#3 DH Private-Key",uVar3);
        if (0 < iVar5) {
          indent = &reason->version;
          iVar5 = (*(code *)PTR_ASN1_bn_print_006a86b8)(b,"private-key:",iVar9,iVar6,indent);
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_ASN1_bn_print_006a86b8)(b,"public-key:",iVar10,iVar6,indent);
            if (iVar5 != 0) {
              iVar5 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                (b,"prime:",*(undefined4 *)(iVar2 + 8),iVar6,indent);
              if (iVar5 != 0) {
                iVar5 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                  (b,"generator:",*(undefined4 *)(iVar2 + 0xc),iVar6,indent);
                if (iVar5 != 0) {
                  if (*(int *)(iVar2 + 0x10) == 0) {
                    uVar3 = 1;
                    goto LAB_005173f8;
                  }
                  BIO_indent(b,(int)indent,0x80);
                  iVar2 = BIO_printf(b,"recommended-private-length: %d bits\n",
                                     *(undefined4 *)(iVar2 + 0x10));
                  if (0 < iVar2) {
                    uVar3 = 1;
                    goto LAB_005173f8;
                  }
                }
              }
            }
          }
        }
        uVar3 = 0;
        ERR_put_error(5,100,7,"dh_ameth.c",0x179);
LAB_005173f8:
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar6);
        return uVar3;
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

