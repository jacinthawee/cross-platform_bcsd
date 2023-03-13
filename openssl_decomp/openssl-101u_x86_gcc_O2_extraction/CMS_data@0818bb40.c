
int CMS_data(CMS_ContentInfo *cms,BIO *out,uint flags)

{
  ASN1_OBJECT *o;
  int iVar1;
  BIO *a;
  
  o = CMS_get0_type(cms);
  iVar1 = OBJ_obj2nid(o);
  if (iVar1 == 0x15) {
    a = CMS_dataInit(cms,(BIO *)0x0);
    if (a != (BIO *)0x0) {
      iVar1 = cms_copy_content();
      BIO_free_all(a);
      return iVar1;
    }
  }
  else {
    ERR_put_error(0x2e,0x6d,0x8f,"cms_smime.c",0x90);
  }
  return 0;
}

