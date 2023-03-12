
int RSA_eay_public_decrypt(int param_1,uchar *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  int iVar2;
  uchar *to;
  undefined4 uVar3;
  BIGNUM *pBVar4;
  BN_MONT_CTX *pBVar5;
  undefined4 uVar6;
  code *pcVar7;
  
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (0x4000 < iVar1) {
    uVar6 = 0x69;
    uVar3 = 0x273;
LAB_0050c0e8:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x67,uVar6,&DAT_00666c88,uVar3);
    return -1;
  }
  iVar1 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar1 < 1) {
    uVar6 = 0x65;
    uVar3 = 0x278;
    goto LAB_0050c0e8;
  }
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if ((0xc00 < iVar1) && (iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), 0x40 < iVar1)) {
    uVar6 = 0x65;
    uVar3 = 0x27f;
    goto LAB_0050c0e8;
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
  to = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1,&DAT_00666c88,0x28a);
  if (((ret == (BIGNUM *)0x0) || (a == (BIGNUM *)0x0)) || (to == (uchar *)0x0)) {
    iVar2 = -1;
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x67,0x41,&DAT_00666c88,0x28c);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return -1;
    }
    goto LAB_0050c068;
  }
  if (iVar1 < param_1) {
    uVar6 = 0x6c;
    uVar3 = 0x295;
LAB_0050c034:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x67,uVar6,&DAT_00666c88,uVar3);
LAB_0050c044:
    iVar2 = -1;
  }
  else {
    pBVar4 = BN_bin2bn(param_2,param_1,ret);
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_0050c044;
    iVar2 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
    if (-1 < iVar2) {
      uVar6 = 0x84;
      uVar3 = 0x29e;
      goto LAB_0050c034;
    }
    if ((((*(uint *)(param_4 + 0x3c) & 2) != 0) &&
        (pBVar5 = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),ctx),
        pBVar5 == (BN_MONT_CTX *)0x0)) ||
       (iVar2 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                          (a,ret,*(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x10),ctx
                           ,*(undefined4 *)(param_4 + 0x40)), iVar2 == 0)) goto LAB_0050c044;
    if (param_5 == 5) {
      if (((*a->d & 0xf) != 0xc) &&
         (iVar2 = (*(code *)PTR_BN_sub_006a85a8)(a,*(undefined4 *)(param_4 + 0x10),a), iVar2 == 0))
      goto LAB_0050c044;
      iVar2 = BN_bn2bin(a,to);
      pcVar7 = (code *)PTR_RSA_padding_check_X931_006a86e4;
    }
    else {
      iVar2 = BN_bn2bin(a,to);
      pcVar7 = (code *)PTR_RSA_padding_check_PKCS1_type_1_006a86ec;
      if ((param_5 != 1) && (pcVar7 = (code *)PTR_RSA_padding_check_none_006a86e8, param_5 != 3)) {
        uVar6 = 0x76;
        uVar3 = 0x2bd;
        goto LAB_0050c034;
      }
    }
    iVar2 = (*pcVar7)(param_3,iVar1,to,iVar2,iVar1);
    if (iVar2 < 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x67,0x72,&DAT_00666c88,0x2c1);
    }
  }
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_0050c068:
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(to,iVar1);
  (*(code *)PTR_CRYPTO_free_006a6e88)(to);
  return iVar2;
}
