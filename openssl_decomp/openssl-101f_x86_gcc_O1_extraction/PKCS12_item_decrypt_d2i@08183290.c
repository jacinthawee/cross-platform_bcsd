
void * PKCS12_item_decrypt_d2i
                 (X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,ASN1_OCTET_STRING *oct,
                 int zbuf)

{
  int iVar1;
  uchar *out;
  int iVar2;
  ASN1_VALUE *pAVar3;
  uchar *puVar4;
  int in_GS_OFFSET;
  uchar *local_b0;
  EVP_CIPHER_CTX local_ac;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = oct->length;
  puVar4 = oct->data;
  EVP_CIPHER_CTX_init(&local_ac);
  iVar1 = EVP_PBE_CipherInit(algor->algorithm,pass,passlen,algor->parameter,&local_ac,0);
  if (iVar1 == 0) {
    ERR_put_error(0x23,0x77,0x73,"p12_decr.c",0x53);
  }
  else {
    iVar1 = EVP_CIPHER_CTX_block_size(&local_ac);
    out = (uchar *)CRYPTO_malloc(iVar1 + iVar2,"p12_decr.c",0x57);
    if (out == (uchar *)0x0) {
      ERR_put_error(0x23,0x77,0x41,"p12_decr.c",0x58);
    }
    else {
      iVar2 = EVP_CipherUpdate(&local_ac,out,(int *)&local_b0,puVar4,iVar2);
      puVar4 = local_b0;
      if (iVar2 == 0) {
        CRYPTO_free(out);
        ERR_put_error(0x23,0x77,6,"p12_decr.c",0x60);
      }
      else {
        iVar2 = EVP_CipherFinal_ex(&local_ac,out + (int)local_b0,(int *)&local_b0);
        if (iVar2 != 0) {
          puVar4 = puVar4 + (int)local_b0;
          EVP_CIPHER_CTX_cleanup(&local_ac);
          local_b0 = out;
          pAVar3 = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_b0,(long)puVar4,it);
          if (zbuf != 0) {
            OPENSSL_cleanse(out,(size_t)puVar4);
          }
          if (pAVar3 == (ASN1_VALUE *)0x0) {
            ERR_put_error(0x23,0x6a,0x65,"p12_decr.c",0x94);
          }
          CRYPTO_free(out);
          goto LAB_081833ab;
        }
        CRYPTO_free(out);
        ERR_put_error(0x23,0x77,0x74,"p12_decr.c",0x68);
      }
    }
    EVP_CIPHER_CTX_cleanup(&local_ac);
  }
  ERR_put_error(0x23,0x6a,0x75,"p12_decr.c",0x82);
  pAVar3 = (ASN1_VALUE *)0x0;
LAB_081833ab:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

