
PKCS12_SAFEBAG *
PKCS12_MAKE_SHKEYBAG
          (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
          PKCS8_PRIV_KEY_INFO *p8)

{
  undefined *puVar1;
  PKCS12_SAFEBAG *pPVar2;
  ASN1_OBJECT *pAVar3;
  undefined4 uVar4;
  EVP_CIPHER *cipher;
  X509_SIG *pXVar5;
  int pbe_nid_00;
  
  pPVar2 = PKCS12_SAFEBAG_new();
  if (pPVar2 == (PKCS12_SAFEBAG *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x71,0x41,"p12_add.c",0x71);
    pPVar2 = (PKCS12_SAFEBAG *)0x0;
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0x97);
    puVar1 = PTR_OBJ_nid2sn_006a819c;
    pPVar2->type = pAVar3;
    uVar4 = (*(code *)puVar1)(pbe_nid);
    cipher = (EVP_CIPHER *)(*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar4);
    pbe_nid_00 = -1;
    if (cipher == (EVP_CIPHER *)0x0) {
      pbe_nid_00 = pbe_nid;
    }
    pXVar5 = PKCS8_encrypt(pbe_nid_00,cipher,pass,passlen,salt,saltlen,iter,p8);
    (pPVar2->value).shkeybag = pXVar5;
    if (pXVar5 == (X509_SIG *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x71,0x41,"p12_add.c",0x7f);
      pPVar2 = (PKCS12_SAFEBAG *)0x0;
    }
  }
  return pPVar2;
}

