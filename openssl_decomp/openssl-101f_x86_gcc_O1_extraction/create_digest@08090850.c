
EVP_MD * __regparm3 create_digest(BIO *param_1_00,char *param_2,EVP_MD *param_3,uchar **param_1)

{
  EVP_MD *num;
  uchar *puVar1;
  size_t cnt;
  EVP_MD *pEVar2;
  int in_GS_OFFSET;
  EVP_MD_CTX local_1038;
  undefined local_1020 [4096];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  num = (EVP_MD *)EVP_MD_size(param_3);
  if ((int)num < 0) {
    pEVar2 = (EVP_MD *)0x0;
  }
  else if (param_1_00 == (BIO *)0x0) {
    puVar1 = string_to_hex(param_2,(long *)&local_1038);
    *param_1 = puVar1;
    if ((puVar1 == (uchar *)0x0) || (pEVar2 = num, num != local_1038.digest)) {
      CRYPTO_free(puVar1);
      *param_1 = (uchar *)0x0;
      BIO_printf(bio_err,"bad digest, %d bytes must be specified\n",num);
      pEVar2 = (EVP_MD *)0x0;
    }
  }
  else {
    puVar1 = (uchar *)CRYPTO_malloc((int)num,"ts.c",0x265);
    *param_1 = puVar1;
    pEVar2 = (EVP_MD *)0x0;
    if (puVar1 != (uchar *)0x0) {
      EVP_DigestInit(&local_1038,param_3);
      while( true ) {
        cnt = BIO_read(param_1_00,local_1020,0x1000);
        if ((int)cnt < 1) break;
        EVP_DigestUpdate(&local_1038,local_1020,cnt);
      }
      EVP_DigestFinal(&local_1038,*param_1,(uint *)0x0);
      pEVar2 = num;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

