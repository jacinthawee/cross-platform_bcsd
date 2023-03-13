
int CMS_digest_verify(CMS_ContentInfo *cms,BIO *dcont,BIO *out,uint flags)

{
  ASN1_OBJECT *o;
  int iVar1;
  BIO *b;
  BIO *pBVar2;
  ASN1_OCTET_STRING **ppAVar3;
  
  o = CMS_get0_type(cms);
  iVar1 = OBJ_obj2nid(o);
  if (iVar1 != 0x19) {
    ERR_put_error(0x2e,0x76,0x90,"cms_smime.c",0xb0);
    return 0;
  }
  if ((dcont == (BIO *)0x0) &&
     ((ppAVar3 = CMS_get0_content(cms), ppAVar3 == (ASN1_OCTET_STRING **)0x0 ||
      (*ppAVar3 == (ASN1_OCTET_STRING *)0x0)))) {
    ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x77);
    iVar1 = 0;
  }
  else {
    b = CMS_dataInit(cms,dcont);
    iVar1 = 0;
    if (b != (BIO *)0x0) {
      iVar1 = cms_copy_content();
      if (iVar1 != 0) {
        iVar1 = cms_DigestedData_do_final(cms,b,1);
      }
      if (dcont == (BIO *)0x0) {
        BIO_free_all(b);
      }
      else {
        do {
          pBVar2 = BIO_pop(b);
          BIO_free(b);
          if (pBVar2 == (BIO *)0x0) {
            return iVar1;
          }
          b = pBVar2;
        } while (dcont != pBVar2);
      }
    }
  }
  return iVar1;
}

