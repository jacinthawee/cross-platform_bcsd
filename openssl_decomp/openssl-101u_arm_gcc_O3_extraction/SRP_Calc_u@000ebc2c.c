
void SRP_Calc_u(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  int iVar1;
  int iVar2;
  void *__s;
  EVP_MD *type;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  size_t __n;
  EVP_MD_CTX EStack_50;
  uchar auStack_38 [20];
  int local_24;
  
  pBVar3 = (BIGNUM *)(uint)(param_2 == (BIGNUM *)0x0 || param_1 == (BIGNUM *)0x0);
  local_24 = __stack_chk_guard;
  if ((((param_2 != (BIGNUM *)0x0 && param_1 != (BIGNUM *)0x0) && (param_3 != (BIGNUM *)0x0)) &&
      (iVar1 = BN_ucmp(param_1,param_3), iVar1 < 0)) &&
     (iVar1 = BN_ucmp(param_2,param_3), iVar1 < 0)) {
    iVar2 = BN_num_bits(param_3);
    iVar1 = iVar2 + 0xe;
    if (-1 < iVar2 + 7) {
      iVar1 = iVar2 + 7;
    }
    __n = iVar1 >> 3;
    __s = CRYPTO_malloc(__n << 1,"srp_lib.c",0x84);
    if (__s != (void *)0x0) {
      memset(__s,(int)pBVar3,__n);
      EVP_MD_CTX_init(&EStack_50);
      type = EVP_sha1();
      EVP_DigestInit_ex(&EStack_50,type,(ENGINE *)pBVar3);
      iVar1 = BN_bn2bin(param_1,(uchar *)((int)__s + __n));
      EVP_DigestUpdate(&EStack_50,(void *)((int)__s + iVar1),__n);
      iVar1 = BN_bn2bin(param_2,(uchar *)((int)__s + __n));
      EVP_DigestUpdate(&EStack_50,(void *)((int)__s + iVar1),__n);
      CRYPTO_free(__s);
      EVP_DigestFinal_ex(&EStack_50,auStack_38,(uint *)pBVar3);
      EVP_MD_CTX_cleanup(&EStack_50);
      pBVar3 = BN_bin2bn(auStack_38,0x14,pBVar3);
      if (pBVar3 != (BIGNUM *)0x0) {
        pBVar4 = (BIGNUM *)pBVar3->top;
        if (pBVar4 == (BIGNUM *)0x0) {
          BN_free(pBVar3);
          pBVar3 = pBVar4;
        }
        goto LAB_000ebd0a;
      }
    }
  }
  pBVar3 = (BIGNUM *)0x0;
LAB_000ebd0a:
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pBVar3);
  }
  return;
}

