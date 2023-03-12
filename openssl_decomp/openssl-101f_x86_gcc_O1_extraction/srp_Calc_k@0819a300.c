
BIGNUM * __regparm3 srp_Calc_k(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  uchar *to;
  EVP_MD *type;
  size_t cnt;
  BIGNUM *pBVar2;
  size_t cnt_00;
  int in_GS_OFFSET;
  EVP_MD_CTX local_4c;
  uchar local_34 [20];
  int local_20;
  int iVar3;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = BN_num_bits(param_1);
  iVar3 = iVar1 + 0xe;
  if (-1 < iVar1 + 7) {
    iVar3 = iVar1 + 7;
  }
  cnt_00 = iVar3 >> 3;
  to = (uchar *)CRYPTO_malloc(cnt_00,"srp_lib.c",0x5c);
  if (to == (uchar *)0x0) {
    pBVar2 = (BIGNUM *)0x0;
  }
  else {
    BN_bn2bin(param_1,to);
    EVP_MD_CTX_init(&local_4c);
    type = EVP_sha1();
    EVP_DigestInit_ex(&local_4c,type,(ENGINE *)0x0);
    EVP_DigestUpdate(&local_4c,to,cnt_00);
    memset(to,0,cnt_00);
    cnt = BN_bn2bin(param_2,to);
    EVP_DigestUpdate(&local_4c,to + cnt,cnt_00 - cnt);
    EVP_DigestUpdate(&local_4c,to,cnt);
    CRYPTO_free(to);
    EVP_DigestFinal_ex(&local_4c,local_34,(uint *)0x0);
    EVP_MD_CTX_cleanup(&local_4c);
    pBVar2 = BN_bin2bn(local_34,0x14,(BIGNUM *)0x0);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pBVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

