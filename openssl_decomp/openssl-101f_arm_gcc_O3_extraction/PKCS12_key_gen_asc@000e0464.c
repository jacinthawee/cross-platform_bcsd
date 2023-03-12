
int PKCS12_key_gen_asc(char *pass,int passlen,uchar *salt,int saltlen,int id,int iter,int n,
                      uchar *out,EVP_MD *md_type)

{
  uchar *puVar1;
  char *pcVar2;
  uchar *puVar3;
  uchar *local_18;
  char *local_14;
  
  puVar1 = (uchar *)pass;
  pcVar2 = pass;
  if ((pass == (char *)0x0) ||
     (puVar3 = OPENSSL_asc2uni(pass,passlen,&local_18,(int *)&local_14), puVar1 = local_18,
     pcVar2 = local_14, puVar3 != (uchar *)0x0)) {
    local_14 = pcVar2;
    local_18 = puVar1;
    puVar3 = (uchar *)PKCS12_key_gen_uni(local_18,(int)local_14,salt,saltlen,id,iter,n,out,md_type);
    if ((int)puVar3 < 1) {
      puVar3 = (uchar *)0x0;
    }
    else {
      if (local_18 == (uchar *)0x0) {
        return (int)puVar3;
      }
      OPENSSL_cleanse(local_18,(size_t)local_14);
      CRYPTO_free(local_18);
    }
  }
  else {
    ERR_put_error(0x23,0x6e,0x41,"p12_key.c",0x59);
  }
  return (int)puVar3;
}

