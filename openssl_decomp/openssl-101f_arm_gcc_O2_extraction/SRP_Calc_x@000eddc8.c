
void SRP_Calc_x(BIGNUM *param_1,char *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  uchar *to;
  EVP_MD *pEVar3;
  size_t sVar4;
  BIGNUM *pBVar5;
  EVP_MD_CTX EStack_50;
  uchar auStack_38 [20];
  int local_24;
  
  pBVar5 = (BIGNUM *)(uint)(param_2 == (char *)0x0 || param_1 == (BIGNUM *)0x0);
  local_24 = __TMC_END__;
  if ((param_2 != (char *)0x0 && param_1 != (BIGNUM *)0x0) && (param_3 != (char *)0x0)) {
    iVar1 = BN_num_bits(param_1);
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    to = (uchar *)CRYPTO_malloc(iVar2 >> 3,"srp_lib.c",0xda);
    if (to != (uchar *)0x0) {
      EVP_MD_CTX_init(&EStack_50);
      pEVar3 = EVP_sha1();
      EVP_DigestInit_ex(&EStack_50,pEVar3,(ENGINE *)pBVar5);
      sVar4 = strlen(param_2);
      EVP_DigestUpdate(&EStack_50,param_2,sVar4);
      EVP_DigestUpdate(&EStack_50,":",1);
      sVar4 = strlen(param_3);
      EVP_DigestUpdate(&EStack_50,param_3,sVar4);
      EVP_DigestFinal_ex(&EStack_50,auStack_38,(uint *)pBVar5);
      pEVar3 = EVP_sha1();
      EVP_DigestInit_ex(&EStack_50,pEVar3,(ENGINE *)pBVar5);
      BN_bn2bin(param_1,to);
      iVar1 = BN_num_bits(param_1);
      iVar2 = iVar1 + 0xe;
      if (-1 < iVar1 + 7) {
        iVar2 = iVar1 + 7;
      }
      EVP_DigestUpdate(&EStack_50,to,iVar2 >> 3);
      CRYPTO_free(to);
      EVP_DigestUpdate(&EStack_50,auStack_38,0x14);
      EVP_DigestFinal_ex(&EStack_50,auStack_38,(uint *)pBVar5);
      EVP_MD_CTX_cleanup(&EStack_50);
      pBVar5 = BN_bin2bn(auStack_38,0x14,pBVar5);
      goto LAB_000edec0;
    }
  }
  pBVar5 = (BIGNUM *)0x0;
LAB_000edec0:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pBVar5);
  }
  return;
}

