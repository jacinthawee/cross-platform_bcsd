
int CMS_decrypt(CMS_ContentInfo *cms,EVP_PKEY *pkey,X509 *cert,BIO *dcont,BIO *out,uint flags)

{
  ASN1_OBJECT *o;
  int iVar1;
  BIO *a;
  BIO *pBVar2;
  ASN1_OCTET_STRING **ppAVar3;
  
  o = CMS_get0_type(cms);
  iVar1 = OBJ_obj2nid(o);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x70,0x92,"cms_smime.c",0x2e4);
    return 0;
  }
  if ((dcont == (BIO *)0x0) &&
     ((ppAVar3 = CMS_get0_content(cms), ppAVar3 == (ASN1_OCTET_STRING **)0x0 ||
      (*ppAVar3 == (ASN1_OCTET_STRING *)0x0)))) {
    ERR_put_error(0x2e,99,0x7f,"cms_smime.c",0x7f);
    return 0;
  }
  if ((flags & 0x20000) == 0) {
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18) = 0;
  }
  else {
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18) = 1;
  }
  if ((pkey == (EVP_PKEY *)0x0) && (cert == (X509 *)0x0)) {
    if ((dcont == (BIO *)0x0) && (out == (BIO *)0x0)) {
      return 1;
    }
  }
  else if ((pkey != (EVP_PKEY *)0x0) && (iVar1 = CMS_decrypt_set1_pkey(cms,pkey,cert), iVar1 == 0))
  {
    return 0;
  }
  a = CMS_dataInit(cms,dcont);
  if (a != (BIO *)0x0) {
    iVar1 = cms_copy_content();
    if (dcont == (BIO *)0x0) {
      BIO_free_all(a);
    }
    else {
      do {
        pBVar2 = BIO_pop(a);
        BIO_free(a);
        a = pBVar2;
      } while (dcont != pBVar2);
    }
    return iVar1;
  }
  return 0;
}

