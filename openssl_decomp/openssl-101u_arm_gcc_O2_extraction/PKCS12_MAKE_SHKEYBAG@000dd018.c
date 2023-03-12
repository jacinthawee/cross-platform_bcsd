
PKCS12_SAFEBAG *
PKCS12_MAKE_SHKEYBAG
          (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
          PKCS8_PRIV_KEY_INFO *p8)

{
  PKCS12_SAFEBAG *a;
  ASN1_OBJECT *pAVar1;
  char *name;
  EVP_CIPHER *cipher;
  PKCS12_SAFEBAG *pPVar2;
  
  a = PKCS12_SAFEBAG_new();
  if (a == (PKCS12_SAFEBAG *)0x0) {
    ERR_put_error(0x23,0x71,0x41,"p12_add.c",0x77);
  }
  else {
    pAVar1 = OBJ_nid2obj(0x97);
    a->type = pAVar1;
    name = OBJ_nid2sn(pbe_nid);
    cipher = EVP_get_cipherbyname(name);
    if (cipher != (EVP_CIPHER *)0x0) {
      pbe_nid = -1;
    }
    pPVar2 = (PKCS12_SAFEBAG *)PKCS8_encrypt(pbe_nid,cipher,pass,passlen,salt,saltlen,iter,p8);
    (a->value).shkeybag = (X509_SIG *)pPVar2;
    if (pPVar2 == (PKCS12_SAFEBAG *)0x0) {
      ERR_put_error(0x23,0x71,0x41,"p12_add.c",0x85);
      PKCS12_SAFEBAG_free(a);
      a = pPVar2;
    }
  }
  return a;
}

