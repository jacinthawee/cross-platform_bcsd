
int RSA_eay_public_encrypt(int param_1,uchar *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  int iVar2;
  uchar *to;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  BN_MONT_CTX *pBVar5;
  int iVar6;
  undefined4 uVar7;
  code *pcVar8;
  
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (0x4000 < iVar1) {
    uVar7 = 0x69;
    uVar4 = 0xa4;
LAB_0050c588:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x68,uVar7,&DAT_00666c88,uVar4);
    return -1;
  }
  iVar1 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar1 < 1) {
    uVar7 = 0x65;
    uVar4 = 0xa9;
    goto LAB_0050c588;
  }
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if ((0xc00 < iVar1) && (iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), 0x40 < iVar1)) {
    uVar7 = 0x65;
    uVar4 = 0xb0;
    goto LAB_0050c588;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return -1;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  a = BN_CTX_get(ctx);
  iVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  iVar1 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar1 = iVar2 + 0xe;
  }
  iVar1 = iVar1 >> 3;
  to = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1,&DAT_00666c88,0xbb);
  if (((ret == (BIGNUM *)0x0) || (a == (BIGNUM *)0x0)) || (to == (uchar *)0x0)) {
    iVar2 = -1;
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x68,0x41,&DAT_00666c88,0xbd);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return -1;
    }
    goto LAB_0050c618;
  }
  pcVar8 = (code *)PTR_RSA_padding_add_SSLv23_006a86f0;
  if (param_5 == 2) {
LAB_0050c66c:
    iVar2 = (*pcVar8)(to,iVar1,param_2,param_1);
LAB_0050c4d8:
    if ((iVar2 < 1) || (pBVar3 = BN_bin2bn(to,iVar1,ret), pBVar3 == (BIGNUM *)0x0))
    goto LAB_0050c534;
    iVar2 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
    if (-1 < iVar2) {
      uVar7 = 0x84;
      uVar4 = 0xdd;
      goto LAB_0050c524;
    }
    if ((((*(uint *)(param_4 + 0x3c) & 2) != 0) &&
        (pBVar5 = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),ctx),
        pBVar5 == (BN_MONT_CTX *)0x0)) ||
       (iVar2 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                          (a,ret,*(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x10),ctx
                           ,*(undefined4 *)(param_4 + 0x40)), iVar2 == 0)) goto LAB_0050c534;
    iVar6 = BN_num_bits(a);
    iVar2 = iVar6 + 7;
    if (iVar6 + 7 < 0) {
      iVar2 = iVar6 + 0xe;
    }
    iVar6 = BN_bn2bin(a,(uchar *)(param_3 + (iVar1 - (iVar2 >> 3))));
    iVar2 = iVar1;
    if (0 < iVar1 - iVar6) {
      (*(code *)PTR_memset_006a99f4)(param_3,0);
    }
  }
  else {
    if (2 < param_5) {
      pcVar8 = (code *)PTR_RSA_padding_add_none_006a86f4;
      if (param_5 == 3) goto LAB_0050c66c;
      if (param_5 != 4) goto LAB_0050c6a0;
      iVar2 = RSA_padding_add_PKCS1_OAEP(to,iVar1,param_2,param_1,(uchar *)0x0,0);
      goto LAB_0050c4d8;
    }
    pcVar8 = (code *)PTR_RSA_padding_add_PKCS1_type_2_006a86fc;
    if (param_5 == 1) goto LAB_0050c66c;
LAB_0050c6a0:
    uVar7 = 0x76;
    uVar4 = 0xd1;
LAB_0050c524:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x68,uVar7,&DAT_00666c88,uVar4);
LAB_0050c534:
    iVar2 = -1;
  }
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_0050c618:
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(to,iVar1);
  (*(code *)PTR_CRYPTO_free_006a6e88)(to);
  return iVar2;
}

