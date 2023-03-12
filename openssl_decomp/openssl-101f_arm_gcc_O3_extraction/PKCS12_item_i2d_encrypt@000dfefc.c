
ASN1_OCTET_STRING *
PKCS12_item_i2d_encrypt(X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,void *obj,int zbuf)

{
  ASN1_OCTET_STRING *in;
  ASN1_OCTET_STRING *pAVar1;
  size_t len;
  int iVar2;
  uchar *out;
  int iVar3;
  ASN1_OCTET_STRING *local_c0;
  int local_bc;
  EVP_CIPHER_CTX EStack_b8;
  int local_2c;
  
  local_2c = __TMC_END__;
  local_c0 = (ASN1_OCTET_STRING *)0x0;
  pAVar1 = ASN1_STRING_type_new(4);
  if (pAVar1 == (ASN1_STRING *)0x0) {
    ERR_put_error(0x23,0x6c,0x41,"p12_decr.c",0xa5);
  }
  else {
    len = ASN1_item_i2d((ASN1_VALUE *)obj,(uchar **)&local_c0,it);
    in = local_c0;
    if (local_c0 == (ASN1_OCTET_STRING *)0x0) {
      ERR_put_error(0x23,0x6c,0x66,"p12_decr.c",0xaa);
      pAVar1 = in;
    }
    else {
      EVP_CIPHER_CTX_init(&EStack_b8);
      iVar2 = EVP_PBE_CipherInit(algor->algorithm,pass,passlen,algor->parameter,&EStack_b8,1);
      if (iVar2 == 0) {
        ERR_put_error(0x23,0x77,0x73,"p12_decr.c",0x53);
      }
      else {
        iVar2 = EVP_CIPHER_CTX_block_size(&EStack_b8);
        out = (uchar *)CRYPTO_malloc(iVar2 + len,"p12_decr.c",0x57);
        if (out == (uchar *)0x0) {
          ERR_put_error(0x23,0x77,0x41,"p12_decr.c",0x58);
        }
        else {
          iVar3 = EVP_CipherUpdate(&EStack_b8,out,&local_bc,(uchar *)in,len);
          iVar2 = local_bc;
          if (iVar3 == 0) {
            CRYPTO_free(out);
            ERR_put_error(0x23,0x77,6,"p12_decr.c",0x60);
          }
          else {
            iVar3 = EVP_CipherFinal_ex(&EStack_b8,out + local_bc,&local_bc);
            if (iVar3 != 0) {
              pAVar1->data = out;
              pAVar1->length = local_bc + iVar2;
              EVP_CIPHER_CTX_cleanup(&EStack_b8);
              if (zbuf != 0) {
                OPENSSL_cleanse(local_c0,len);
              }
              CRYPTO_free(local_c0);
              goto LAB_000dfffc;
            }
            CRYPTO_free(out);
            ERR_put_error(0x23,0x77,0x74,"p12_decr.c",0x68);
          }
        }
        EVP_CIPHER_CTX_cleanup(&EStack_b8);
      }
      ERR_put_error(0x23,0x6c,0x67,"p12_decr.c",0xaf);
      CRYPTO_free(local_c0);
      pAVar1 = (ASN1_OCTET_STRING *)0x0;
    }
  }
LAB_000dfffc:
  if (local_2c == __TMC_END__) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

