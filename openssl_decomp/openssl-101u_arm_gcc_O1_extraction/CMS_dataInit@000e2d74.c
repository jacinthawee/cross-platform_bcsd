
BIO * CMS_dataInit(CMS_ContentInfo *cms,BIO *icont)

{
  int iVar1;
  BIO *b;
  BIO *pBVar2;
  
  pBVar2 = icont;
  if ((icont == (BIO *)0x0) && (pBVar2 = (BIO *)cms_content_bio(), pBVar2 == (BIO *)0x0)) {
    ERR_put_error(0x2e,0x6f,0x7f,"cms_lib.c",0x72);
    b = pBVar2;
  }
  else {
    iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    switch(iVar1) {
    case 0x15:
      return pBVar2;
    case 0x16:
      b = (BIO *)cms_SignedData_init_bio(cms);
      break;
    case 0x17:
      b = (BIO *)cms_EnvelopedData_init_bio(cms);
      break;
    default:
      ERR_put_error(0x2e,0x6f,0x9c,"cms_lib.c",0x90);
      return (BIO *)0x0;
    case 0x19:
      b = (BIO *)cms_DigestedData_init_bio(cms);
      break;
    case 0x1a:
      b = (BIO *)cms_EncryptedData_init_bio(cms);
    }
    if (b != (BIO *)0x0) {
      pBVar2 = BIO_push(b,pBVar2);
      return pBVar2;
    }
    if (icont == (BIO *)0x0) {
      BIO_free(pBVar2);
      b = icont;
    }
  }
  return b;
}

