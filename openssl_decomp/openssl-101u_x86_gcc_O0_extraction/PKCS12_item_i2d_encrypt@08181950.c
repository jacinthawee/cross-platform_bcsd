
ASN1_OCTET_STRING *
PKCS12_item_i2d_encrypt(X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,void *obj,int zbuf)

{
  uchar *in;
  ASN1_OCTET_STRING *pAVar1;
  size_t len;
  int iVar2;
  uchar *out;
  int iVar3;
  int in_GS_OFFSET;
  uchar *local_b4;
  int local_b0;
  EVP_CIPHER_CTX local_ac;
  int local_20;
  
  local_b4 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pAVar1 = ASN1_STRING_type_new(4);
  if (pAVar1 == (ASN1_STRING *)0x0) {
    iVar3 = 0xb2;
    iVar2 = 0x41;
  }
  else {
    len = ASN1_item_i2d((ASN1_VALUE *)obj,&local_b4,it);
    in = local_b4;
    if (local_b4 != (uchar *)0x0) {
      EVP_CIPHER_CTX_init(&local_ac);
      iVar2 = EVP_PBE_CipherInit(algor->algorithm,pass,passlen,algor->parameter,&local_ac,1);
      if (iVar2 == 0) {
        ERR_put_error(0x23,0x77,0x73,"p12_decr.c",0x57);
      }
      else {
        iVar2 = EVP_CIPHER_CTX_block_size(&local_ac);
        out = (uchar *)CRYPTO_malloc(iVar2 + len,"p12_decr.c",0x5b);
        if (out == (uchar *)0x0) {
          ERR_put_error(0x23,0x77,0x41,"p12_decr.c",0x5c);
        }
        else {
          iVar3 = EVP_CipherUpdate(&local_ac,out,&local_b0,in,len);
          iVar2 = local_b0;
          if (iVar3 == 0) {
            CRYPTO_free(out);
            ERR_put_error(0x23,0x77,6,"p12_decr.c",99);
          }
          else {
            iVar3 = EVP_CipherFinal_ex(&local_ac,out + local_b0,&local_b0);
            if (iVar3 != 0) {
              pAVar1->data = out;
              pAVar1->length = local_b0 + iVar2;
              EVP_CIPHER_CTX_cleanup(&local_ac);
              if (zbuf != 0) {
                OPENSSL_cleanse(local_b4,len);
              }
              CRYPTO_free(local_b4);
              goto LAB_08181a9a;
            }
            CRYPTO_free(out);
            ERR_put_error(0x23,0x77,0x74,"p12_decr.c",0x6c);
          }
        }
        EVP_CIPHER_CTX_cleanup(&local_ac);
      }
      ERR_put_error(0x23,0x6c,0x67,"p12_decr.c",0xbc);
      CRYPTO_free(local_b4);
      pAVar1 = (ASN1_OCTET_STRING *)0x0;
      goto LAB_08181a9a;
    }
    iVar3 = 0xb7;
    iVar2 = 0x66;
  }
  ERR_put_error(0x23,0x6c,iVar2,"p12_decr.c",iVar3);
  pAVar1 = (ASN1_OCTET_STRING *)0x0;
LAB_08181a9a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

