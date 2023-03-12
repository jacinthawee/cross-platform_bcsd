
PKCS12_SAFEBAG *
PKCS12_MAKE_SHKEYBAG
          (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
          PKCS8_PRIV_KEY_INFO *p8)

{
  undefined *puVar1;
  PKCS12_SAFEBAG *a;
  ASN1_OBJECT *pAVar2;
  undefined4 uVar3;
  EVP_CIPHER *cipher;
  X509_SIG *pXVar4;
  int pbe_nid_00;
  
  a = PKCS12_SAFEBAG_new();
  if (a == (PKCS12_SAFEBAG *)0x0) {
    a = (PKCS12_SAFEBAG *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x71,0x41,"p12_add.c",0x77);
  }
  else {
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0x97);
    puVar1 = PTR_OBJ_nid2sn_006a709c;
    a->type = pAVar2;
    uVar3 = (*(code *)puVar1)(pbe_nid);
    cipher = (EVP_CIPHER *)(*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar3);
    pbe_nid_00 = -1;
    if (cipher == (EVP_CIPHER *)0x0) {
      pbe_nid_00 = pbe_nid;
    }
    pXVar4 = PKCS8_encrypt(pbe_nid_00,cipher,pass,passlen,salt,saltlen,iter,p8);
    (a->value).shkeybag = pXVar4;
    if (pXVar4 == (X509_SIG *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x71,0x41,"p12_add.c",0x85);
      PKCS12_SAFEBAG_free(a);
      a = (PKCS12_SAFEBAG *)0x0;
    }
  }
  return a;
}

