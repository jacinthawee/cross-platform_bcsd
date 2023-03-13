
PKCS12_SAFEBAG *
PKCS12_MAKE_SHKEYBAG
          (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
          PKCS8_PRIV_KEY_INFO *p8)

{
  PKCS12_SAFEBAG *a;
  ASN1_OBJECT *pAVar1;
  char *name;
  EVP_CIPHER *cipher;
  X509_SIG *pXVar2;
  
  a = PKCS12_SAFEBAG_new();
  if (a == (PKCS12_SAFEBAG *)0x0) {
    ERR_put_error(0x23,0x71,0x41,"p12_add.c",0x77);
    a = (PKCS12_SAFEBAG *)0x0;
  }
  else {
    pAVar1 = OBJ_nid2obj(0x97);
    a->type = pAVar1;
    name = OBJ_nid2sn(pbe_nid);
    cipher = EVP_get_cipherbyname(name);
    if (cipher != (EVP_CIPHER *)0x0) {
      pbe_nid = -1;
    }
    pXVar2 = PKCS8_encrypt(pbe_nid,cipher,pass,passlen,salt,saltlen,iter,p8);
    (a->value).shkeybag = pXVar2;
    if (pXVar2 == (X509_SIG *)0x0) {
      ERR_put_error(0x23,0x71,0x41,"p12_add.c",0x85);
      PKCS12_SAFEBAG_free(a);
      a = (PKCS12_SAFEBAG *)0x0;
    }
  }
  return a;
}

