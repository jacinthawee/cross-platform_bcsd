
PKCS7 * PKCS12_pack_p7encdata
                  (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  stack_st_PKCS12_SAFEBAG *bags)

{
  PKCS7 *p7;
  PKCS7 *pPVar1;
  char *name;
  EVP_CIPHER *cipher;
  PKCS7_ENC_CONTENT *pPVar2;
  
  p7 = PKCS7_new();
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x23,0x73,0x41,"p12_add.c",0xb0);
  }
  else {
    pPVar1 = (PKCS7 *)PKCS7_set_type(p7,0x1a);
    if (pPVar1 == (PKCS7 *)0x0) {
      ERR_put_error(0x23,0x73,0x78,"p12_add.c",0xb5);
      p7 = pPVar1;
    }
    else {
      name = OBJ_nid2sn(pbe_nid);
      cipher = EVP_get_cipherbyname(name);
      if (cipher == (EVP_CIPHER *)0x0) {
        pPVar1 = (PKCS7 *)PKCS5_pbe_set(pbe_nid,iter,salt,saltlen);
      }
      else {
        pPVar1 = (PKCS7 *)PKCS5_pbe2_set(cipher,iter,salt,saltlen);
      }
      if (pPVar1 == (PKCS7 *)0x0) {
        ERR_put_error(0x23,0x73,0x41,"p12_add.c",0xc1);
        p7 = pPVar1;
      }
      else {
        X509_ALGOR_free(((p7->d).encrypted)->enc_data->algorithm);
        pPVar2 = ((p7->d).encrypted)->enc_data;
        pPVar2->algorithm = (X509_ALGOR *)pPVar1;
        ASN1_STRING_free(pPVar2->enc_data);
        pPVar2 = ((p7->d).encrypted)->enc_data;
        pPVar1 = (PKCS7 *)PKCS12_item_i2d_encrypt
                                    ((X509_ALGOR *)pPVar1,(ASN1_ITEM *)PKCS12_SAFEBAGS_it,pass,
                                     passlen,bags,1);
        pPVar2->enc_data = (ASN1_OCTET_STRING *)pPVar1;
        if (pPVar1 == (PKCS7 *)0x0) {
          ERR_put_error(0x23,0x73,0x67,"p12_add.c",0xca);
          p7 = pPVar1;
        }
      }
    }
  }
  return p7;
}

