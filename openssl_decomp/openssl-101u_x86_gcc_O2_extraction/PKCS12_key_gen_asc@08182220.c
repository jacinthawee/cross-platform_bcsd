
int PKCS12_key_gen_asc(char *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  uchar *puVar1;
  int iVar2;
  int in_GS_OFFSET;
  uchar *local_18;
  size_t local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pass == (char *)0x0) {
    local_18 = (uchar *)0x0;
    local_14 = 0;
  }
  else {
    puVar1 = OPENSSL_asc2uni(pass,passlen,&local_18,(int *)&local_14);
    pass = (char *)local_18;
    if (puVar1 == (uchar *)0x0) {
      iVar2 = 0;
      ERR_put_error(0x23,0x6e,0x41,"p12_key.c",0x5c);
      goto LAB_081822ba;
    }
  }
  iVar2 = PKCS12_key_gen_uni((uchar *)pass,local_14,salt,saltlen,id,iter,n,out,md_type);
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else if (local_18 != (uchar *)0x0) {
    OPENSSL_cleanse(local_18,local_14);
    CRYPTO_free(local_18);
  }
LAB_081822ba:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

