
int CMS_EncryptedData_decrypt
              (CMS_ContentInfo *cms,uchar *key,size_t keylen,BIO *dcont,BIO *out,uint flags)

{
  ASN1_OBJECT *o;
  int iVar1;
  BIO *a;
  BIO *pBVar2;
  ASN1_OCTET_STRING **ppAVar3;
  
  o = CMS_get0_type(cms);
  iVar1 = OBJ_obj2nid(o);
  if (iVar1 != 0x1a) {
    ERR_put_error(0x2e,0x79,0x91,"cms_smime.c",0xdd);
    return 0;
  }
  if ((dcont == (BIO *)0x0) &&
     ((ppAVar3 = CMS_get0_content(cms), ppAVar3 == (ASN1_OCTET_STRING **)0x0 ||
      (*ppAVar3 == (ASN1_OCTET_STRING *)0x0)))) {
    ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x77);
    iVar1 = 0;
  }
  else {
    iVar1 = CMS_EncryptedData_set1_key(cms,(EVP_CIPHER *)0x0,key,keylen);
    if ((iVar1 < 1) || (a = CMS_dataInit(cms,dcont), a == (BIO *)0x0)) {
      return 0;
    }
    iVar1 = cms_copy_content(out,a,flags);
    if (dcont == (BIO *)0x0) {
      BIO_free_all(a);
    }
    else {
      do {
        pBVar2 = BIO_pop(a);
        BIO_free(a);
        a = pBVar2;
      } while (dcont != pBVar2 && pBVar2 != (BIO *)0x0);
    }
  }
  return iVar1;
}

