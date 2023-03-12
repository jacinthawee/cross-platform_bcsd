
void * PKCS12_item_decrypt_d2i
                 (X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,ASN1_OCTET_STRING *oct,
                 int zbuf)

{
  int iVar1;
  uchar *out;
  ASN1_VALUE *pAVar2;
  int inl;
  uchar *puVar3;
  uchar *local_bc;
  EVP_CIPHER_CTX EStack_b8;
  int local_2c;
  
  puVar3 = oct->data;
  local_2c = __stack_chk_guard;
  inl = oct->length;
  EVP_CIPHER_CTX_init(&EStack_b8);
  iVar1 = EVP_PBE_CipherInit(algor->algorithm,pass,passlen,algor->parameter,&EStack_b8,0);
  if (iVar1 == 0) {
    ERR_put_error(0x23,0x77,0x73,"p12_decr.c",0x57);
  }
  else {
    iVar1 = EVP_CIPHER_CTX_block_size(&EStack_b8);
    out = (uchar *)CRYPTO_malloc(iVar1 + inl,"p12_decr.c",0x5b);
    if (out == (uchar *)0x0) {
      ERR_put_error(0x23,0x77,0x41,"p12_decr.c",0x5c);
    }
    else {
      iVar1 = EVP_CipherUpdate(&EStack_b8,out,(int *)&local_bc,puVar3,inl);
      puVar3 = local_bc;
      if (iVar1 == 0) {
        CRYPTO_free(out);
        ERR_put_error(0x23,0x77,6,"p12_decr.c",99);
      }
      else {
        iVar1 = EVP_CipherFinal_ex(&EStack_b8,out + (int)local_bc,(int *)&local_bc);
        if (iVar1 != 0) {
          puVar3 = puVar3 + (int)local_bc;
          EVP_CIPHER_CTX_cleanup(&EStack_b8);
          local_bc = out;
          pAVar2 = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_bc,(long)puVar3,it);
          if (zbuf != 0) {
            OPENSSL_cleanse(out,(size_t)puVar3);
          }
          if (pAVar2 == (ASN1_VALUE *)0x0) {
            ERR_put_error(0x23,0x6a,0x65,"p12_decr.c",0x9f);
          }
          CRYPTO_free(out);
          goto LAB_000dddd8;
        }
        CRYPTO_free(out);
        ERR_put_error(0x23,0x77,0x74,"p12_decr.c",0x6c);
      }
    }
    EVP_CIPHER_CTX_cleanup(&EStack_b8);
  }
  ERR_put_error(0x23,0x6a,0x75,"p12_decr.c",0x8b);
  pAVar2 = (ASN1_VALUE *)0x0;
LAB_000dddd8:
  if (local_2c == __stack_chk_guard) {
    return pAVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

