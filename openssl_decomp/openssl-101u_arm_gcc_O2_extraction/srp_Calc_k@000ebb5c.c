
void srp_Calc_k(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  int iVar2;
  uchar *to;
  EVP_MD *type;
  size_t cnt;
  BIGNUM *pBVar3;
  size_t cnt_00;
  EVP_MD_CTX EStack_48;
  uchar auStack_30 [20];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = BN_num_bits(param_1);
  iVar2 = BN_ucmp(param_2,param_1);
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    cnt_00 = iVar2 >> 3;
    to = (uchar *)CRYPTO_malloc(cnt_00,"srp_lib.c",0x5f);
    if (to != (uchar *)0x0) {
      BN_bn2bin(param_1,to);
      EVP_MD_CTX_init(&EStack_48);
      type = EVP_sha1();
      EVP_DigestInit_ex(&EStack_48,type,(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_48,to,cnt_00);
      memset(to,0,cnt_00);
      cnt = BN_bn2bin(param_2,to);
      EVP_DigestUpdate(&EStack_48,to + cnt,cnt_00 - cnt);
      EVP_DigestUpdate(&EStack_48,to,cnt);
      CRYPTO_free(to);
      EVP_DigestFinal_ex(&EStack_48,auStack_30,(uint *)0x0);
      EVP_MD_CTX_cleanup(&EStack_48);
      pBVar3 = BN_bin2bn(auStack_30,0x14,(BIGNUM *)0x0);
      goto LAB_000ebc16;
    }
  }
  pBVar3 = (BIGNUM *)0x0;
LAB_000ebc16:
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pBVar3);
}

