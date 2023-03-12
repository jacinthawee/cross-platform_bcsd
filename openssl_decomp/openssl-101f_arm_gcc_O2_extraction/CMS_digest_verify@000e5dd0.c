
int CMS_digest_verify(CMS_ContentInfo *cms,BIO *dcont,BIO *out,uint flags)

{
  ASN1_OBJECT *o;
  int iVar1;
  BIO *a;
  BIO *pBVar2;
  ASN1_OCTET_STRING **ppAVar3;
  
  o = CMS_get0_type(cms);
  iVar1 = OBJ_obj2nid(o);
  if (iVar1 == 0x19) {
    if ((dcont == (BIO *)0x0) &&
       ((ppAVar3 = CMS_get0_content(cms), ppAVar3 == (ASN1_OCTET_STRING **)0x0 ||
        (*ppAVar3 == (ASN1_OCTET_STRING *)0x0)))) {
      ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x7f);
      return 0;
    }
    a = CMS_dataInit(cms,dcont);
    if (a != (BIO *)0x0) {
      iVar1 = cms_copy_content(out,a,flags);
      if (iVar1 != 0) {
        iVar1 = cms_DigestedData_do_final(cms,a,1);
      }
      if (dcont == (BIO *)0x0) {
        BIO_free_all(a);
        return iVar1;
      }
      do {
        pBVar2 = BIO_pop(a);
        BIO_free(a);
        a = pBVar2;
      } while (dcont != pBVar2);
      return iVar1;
    }
  }
  else {
    ERR_put_error(0x2e,0x76,0x90,"cms_smime.c",0xbd);
  }
  return 0;
}

