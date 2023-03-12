
void create_digest(BIO *param_1,char *param_2,EVP_MD *param_3,EVP_MD **param_4)

{
  EVP_MD *num;
  EVP_MD *pEVar1;
  size_t cnt;
  EVP_MD *ptr;
  EVP_MD_CTX local_103c;
  undefined auStack_1024 [4096];
  int local_24;
  
  local_24 = __stack_chk_guard;
  num = (EVP_MD *)EVP_MD_size(param_3);
  if ((int)num < 0) {
    pEVar1 = (EVP_MD *)0x0;
  }
  else if (param_1 == (BIO *)0x0) {
    ptr = (EVP_MD *)string_to_hex(param_2,(long *)&local_103c);
    *param_4 = ptr;
    if ((ptr == (EVP_MD *)0x0) || (pEVar1 = num, num != local_103c.digest)) {
      CRYPTO_free(ptr);
      *param_4 = (EVP_MD *)0x0;
      BIO_printf(bio_err,"bad digest, %d bytes must be specified\n",num);
      pEVar1 = (EVP_MD *)0x0;
    }
  }
  else {
    pEVar1 = (EVP_MD *)CRYPTO_malloc((int)num,"ts.c",0x24a);
    *param_4 = pEVar1;
    if (pEVar1 != (EVP_MD *)0x0) {
      EVP_DigestInit(&local_103c,param_3);
      while (cnt = BIO_read(param_1,auStack_1024,0x1000), 0 < (int)cnt) {
        EVP_DigestUpdate(&local_103c,auStack_1024,cnt);
      }
      EVP_DigestFinal(&local_103c,(uchar *)*param_4,(uint *)0x0);
      pEVar1 = num;
    }
  }
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pEVar1);
}

