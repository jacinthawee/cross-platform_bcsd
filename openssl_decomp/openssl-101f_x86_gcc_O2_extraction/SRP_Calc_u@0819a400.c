
BIGNUM * SRP_Calc_u(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  int iVar1;
  void *__s;
  EVP_MD *type;
  int iVar2;
  BIGNUM *a;
  size_t __n;
  int in_GS_OFFSET;
  EVP_MD_CTX local_4c;
  uchar local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((param_2 != (BIGNUM *)0x0 && param_3 != (BIGNUM *)0x0) && (param_1 != (BIGNUM *)0x0)) {
    iVar1 = BN_num_bits(param_3);
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    __n = iVar2 >> 3;
    __s = CRYPTO_malloc(__n * 2,"srp_lib.c",0x7e);
    if (__s != (void *)0x0) {
      memset(__s,0,__n);
      EVP_MD_CTX_init(&local_4c);
      type = EVP_sha1();
      EVP_DigestInit_ex(&local_4c,type,(ENGINE *)0x0);
      iVar2 = BN_bn2bin(param_1,(uchar *)((int)__s + __n));
      EVP_DigestUpdate(&local_4c,(void *)(iVar2 + (int)__s),__n);
      iVar2 = BN_bn2bin(param_2,(uchar *)((int)__s + __n));
      EVP_DigestUpdate(&local_4c,(void *)(iVar2 + (int)__s),__n);
      CRYPTO_free(__s);
      EVP_DigestFinal_ex(&local_4c,local_34,(uint *)0x0);
      EVP_MD_CTX_cleanup(&local_4c);
      a = BN_bin2bn(local_34,0x14,(BIGNUM *)0x0);
      if (a != (BIGNUM *)0x0) {
        if (a->top != 0) goto LAB_0819a512;
        BN_free(a);
      }
    }
  }
  a = (BIGNUM *)0x0;
LAB_0819a512:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
