
uchar * PKCS12_pbe_crypt(X509_ALGOR *algor,char *pass,int passlen,uchar *in,int inlen,uchar **data,
                        int *datalen,int en_de)

{
  uchar *out;
  int iVar1;
  uchar *puVar2;
  int local_bc;
  EVP_CIPHER_CTX EStack_b8;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  EVP_CIPHER_CTX_init(&EStack_b8);
  out = (uchar *)EVP_PBE_CipherInit(algor->algorithm,pass,passlen,algor->parameter,&EStack_b8,en_de)
  ;
  if (out == (uchar *)0x0) {
    ERR_put_error(0x23,0x77,0x73,"p12_decr.c",0x57);
  }
  else {
    iVar1 = EVP_CIPHER_CTX_block_size(&EStack_b8);
    out = (uchar *)CRYPTO_malloc(iVar1 + inlen,"p12_decr.c",0x5b);
    if (out == (uchar *)0x0) {
      ERR_put_error(0x23,0x77,0x41,"p12_decr.c",0x5c);
    }
    else {
      puVar2 = (uchar *)EVP_CipherUpdate(&EStack_b8,out,&local_bc,in,inlen);
      iVar1 = local_bc;
      if (puVar2 == (uchar *)0x0) {
        CRYPTO_free(out);
        ERR_put_error(0x23,0x77,6,"p12_decr.c",99);
        out = puVar2;
      }
      else {
        puVar2 = (uchar *)EVP_CipherFinal_ex(&EStack_b8,out + local_bc,&local_bc);
        if (puVar2 == (uchar *)0x0) {
          CRYPTO_free(out);
          ERR_put_error(0x23,0x77,0x74,"p12_decr.c",0x6c);
          out = puVar2;
        }
        else {
          if (datalen != (int *)0x0) {
            *datalen = iVar1 + local_bc;
          }
          if (data != (uchar **)0x0) {
            *data = out;
          }
        }
      }
    }
    EVP_CIPHER_CTX_cleanup(&EStack_b8);
  }
  if (local_2c == __stack_chk_guard) {
    return out;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

