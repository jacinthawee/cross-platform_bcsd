
int PEM_X509_INFO_write_bio
              (BIO *bp,X509_INFO *xi,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cd,void *u)

{
  int iVar1;
  EVP_CIPHER *__s;
  int n;
  size_t sVar2;
  X509 *x;
  uchar *data;
  undefined auStack_4bc [140];
  char local_430 [1028];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (enc != (EVP_CIPHER *)0x0) {
    iVar1 = EVP_CIPHER_nid(enc);
    __s = (EVP_CIPHER *)OBJ_nid2sn(iVar1);
    if (__s == (EVP_CIPHER *)0x0) {
      ERR_put_error(9,0x75,0x71,"pem_info.c",0x149);
      goto LAB_000c3836;
    }
  }
  if (xi->x_pkey == (X509_PKEY *)0x0) {
LAB_000c387c:
    x = xi->x509;
  }
  else {
    data = (uchar *)xi->enc_data;
    if ((data == (uchar *)0x0) || (iVar1 = xi->enc_len, iVar1 < 1)) {
      iVar1 = PEM_write_bio_RSAPrivateKey(bp,(xi->x_pkey->dec_pkey->pkey).rsa,enc,kstr,klen,cd,u);
      if (iVar1 < 1) {
LAB_000c388c:
        __s = (EVP_CIPHER *)0x0;
        goto LAB_000c3836;
      }
      goto LAB_000c387c;
    }
    if (enc == (EVP_CIPHER *)0x0) {
      ERR_put_error(9,0x75,0x7f,"pem_info.c",0x159);
      __s = enc;
      goto LAB_000c3836;
    }
    n = EVP_CIPHER_nid((xi->enc_cipher).cipher);
    __s = (EVP_CIPHER *)OBJ_nid2sn(n);
    if (__s == (EVP_CIPHER *)0x0) {
      ERR_put_error(9,0x75,0x71,"pem_info.c",0x16b);
      goto LAB_000c3836;
    }
    sVar2 = strlen((char *)__s);
    if (0x400 < sVar2 + enc->iv_len * 2 + 0x24) {
      OpenSSLDie("pem_info.c",0x170,"strlen(objstr)+23+2*enc->iv_len+13 <= sizeof buf");
    }
    local_430[0] = '\0';
    PEM_proc_type(local_430,10);
    PEM_dek_info(local_430,(char *)__s,enc->iv_len,(char *)(xi->enc_cipher).iv);
    iVar1 = PEM_write_bio(bp,"RSA PRIVATE KEY",local_430,data,iVar1);
    if (iVar1 < 1) goto LAB_000c388c;
    x = xi->x509;
  }
  if (x == (X509 *)0x0) {
    __s = (EVP_CIPHER *)0x1;
  }
  else {
    iVar1 = PEM_write_bio_X509(bp,x);
    if (iVar1 < 1) {
      __s = (EVP_CIPHER *)0x0;
    }
    else {
      __s = (EVP_CIPHER *)0x1;
    }
  }
LAB_000c3836:
  OPENSSL_cleanse(auStack_4bc,0x8c);
  OPENSSL_cleanse(local_430,0x400);
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)__s;
}

