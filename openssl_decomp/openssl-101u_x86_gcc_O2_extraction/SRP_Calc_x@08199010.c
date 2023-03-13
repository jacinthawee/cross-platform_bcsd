
BIGNUM * SRP_Calc_x(BIGNUM *param_1,char *param_2,char *param_3)

{
  int iVar1;
  uchar *to;
  EVP_MD *pEVar2;
  size_t sVar3;
  int iVar4;
  BIGNUM *pBVar5;
  int in_GS_OFFSET;
  EVP_MD_CTX local_4c;
  uchar local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((param_2 != (char *)0x0 && param_3 != (char *)0x0) && (param_1 != (BIGNUM *)0x0)) {
    iVar1 = BN_num_bits(param_1);
    iVar4 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar4 = iVar1 + 0xe;
    }
    to = (uchar *)CRYPTO_malloc(iVar4 >> 3,"srp_lib.c",0xdf);
    if (to != (uchar *)0x0) {
      EVP_MD_CTX_init(&local_4c);
      pEVar2 = EVP_sha1();
      EVP_DigestInit_ex(&local_4c,pEVar2,(ENGINE *)0x0);
      sVar3 = strlen(param_2);
      EVP_DigestUpdate(&local_4c,param_2,sVar3);
      EVP_DigestUpdate(&local_4c,":",1);
      sVar3 = strlen(param_3);
      EVP_DigestUpdate(&local_4c,param_3,sVar3);
      EVP_DigestFinal_ex(&local_4c,local_34,(uint *)0x0);
      pEVar2 = EVP_sha1();
      EVP_DigestInit_ex(&local_4c,pEVar2,(ENGINE *)0x0);
      BN_bn2bin(param_1,to);
      iVar1 = BN_num_bits(param_1);
      iVar4 = iVar1 + 7;
      if (iVar1 + 7 < 0) {
        iVar4 = iVar1 + 0xe;
      }
      EVP_DigestUpdate(&local_4c,to,iVar4 >> 3);
      CRYPTO_free(to);
      EVP_DigestUpdate(&local_4c,local_34,0x14);
      EVP_DigestFinal_ex(&local_4c,local_34,(uint *)0x0);
      EVP_MD_CTX_cleanup(&local_4c);
      pBVar5 = BN_bin2bn(local_34,0x14,(BIGNUM *)0x0);
      goto LAB_0819915c;
    }
  }
  pBVar5 = (BIGNUM *)0x0;
LAB_0819915c:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pBVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

