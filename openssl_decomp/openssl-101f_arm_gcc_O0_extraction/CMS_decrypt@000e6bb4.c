
int CMS_decrypt(CMS_ContentInfo *cms,EVP_PKEY *pkey,X509 *cert,BIO *dcont,BIO *out,uint flags)

{
  ASN1_OBJECT *o;
  int iVar1;
  BIO *a;
  BIO *pBVar2;
  ASN1_OCTET_STRING **ppAVar3;
  uint uVar4;
  bool bVar5;
  
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
    iVar1 = 0;
  }
  else {
    uVar4 = flags & 0x20000;
    bVar5 = uVar4 != 0;
    if (bVar5) {
      iVar1 = 1;
      uVar4 = *(uint *)(*(int *)(cms + 4) + 0xc);
    }
    else {
      iVar1 = *(int *)(*(int *)(cms + 4) + 0xc);
    }
    if (bVar5) {
      *(int *)(uVar4 + 0x18) = iVar1;
    }
    if (!bVar5) {
      *(uint *)(iVar1 + 0x18) = uVar4;
    }
    if (pkey == (EVP_PKEY *)0x0 && cert == (X509 *)0x0) {
      if (dcont == (BIO *)0x0 && out == (BIO *)0x0) {
        return 1;
      }
    }
    else if ((pkey != (EVP_PKEY *)0x0) && (iVar1 = CMS_decrypt_set1_pkey(cms,pkey,cert), iVar1 == 0)
            ) {
      return 0;
    }
    a = CMS_dataInit(cms,dcont);
    if (a == (BIO *)0x0) {
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
      } while (dcont != pBVar2);
    }
  }
  return iVar1;
}

