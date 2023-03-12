
int SSL_CTX_use_RSAPrivateKey_ASN1(SSL_CTX *ctx,uchar *d,long len)

{
  RSA *r;
  int iVar1;
  EVP_PKEY *pkey;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = d;
  r = d2i_RSAPrivateKey((RSA **)0x0,&local_24,len);
  if (r == (RSA *)0x0) {
    iVar1 = 0;
    ERR_put_error(0x14,0xb2,0xd,"ssl_rsa.c",0x25f);
  }
  else {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xb1,0x41,"ssl_rsa.c",0x215);
    }
    else {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        iVar1 = 0;
        ERR_put_error(0x14,0xb1,6,"ssl_rsa.c",0x21a);
      }
      else {
        RSA_up_ref(r);
        EVP_PKEY_assign(pkey,6,r);
        iVar1 = ssl_set_pkey();
        EVP_PKEY_free(pkey);
      }
    }
    RSA_free(r);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

