
int SMIME_write_PKCS7(BIO *bio,PKCS7 *p7,BIO *data,int flags)

{
  int iVar1;
  stack_st_X509_ALGOR *mdalgs;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x16) {
    mdalgs = ((p7->d).sign)->md_algs;
  }
  else {
    mdalgs = (stack_st_X509_ALGOR *)0x0;
  }
  iVar1 = SMIME_write_ASN1(bio,(ASN1_VALUE *)p7,data,flags ^ 0x400,iVar1,0,mdalgs,
                           (ASN1_ITEM *)&PKCS7_it);
  return iVar1;
}

