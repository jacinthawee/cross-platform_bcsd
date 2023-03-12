
X509_SIG *
PKCS8_encrypt(int pbe_nid,EVP_CIPHER *cipher,char *pass,int passlen,uchar *salt,int saltlen,int iter
             ,PKCS8_PRIV_KEY_INFO *p8)

{
  X509_SIG *a;
  X509_ALGOR *algor;
  ASN1_OCTET_STRING *pAVar1;
  
  a = X509_SIG_new();
  if (a == (X509_SIG *)0x0) {
    ERR_put_error(0x23,0x7d,0x41,"p12_p8e.c",0x48);
  }
  else {
    if (pbe_nid == -1) {
      algor = PKCS5_pbe2_set(cipher,iter,salt,saltlen);
    }
    else {
      algor = PKCS5_pbe_set(pbe_nid,iter,salt,saltlen);
    }
    if (algor == (X509_ALGOR *)0x0) {
      ERR_put_error(0x23,0x7d,0xd,"p12_p8e.c",0x4f);
    }
    else {
      X509_ALGOR_free(a->algor);
      a->algor = algor;
      ASN1_STRING_free(a->digest);
      pAVar1 = PKCS12_item_i2d_encrypt(algor,(ASN1_ITEM *)&PKCS8_PRIV_KEY_INFO_it,pass,passlen,p8,1)
      ;
      a->digest = pAVar1;
      if (pAVar1 != (ASN1_OCTET_STRING *)0x0) {
        return a;
      }
      ERR_put_error(0x23,0x7d,0x67,"p12_p8e.c",0x58);
    }
  }
  X509_SIG_free(a);
  return (X509_SIG *)0x0;
}

