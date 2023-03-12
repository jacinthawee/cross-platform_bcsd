
int SMIME_write_PKCS7(BIO *bio,PKCS7 *p7,BIO *data,int flags)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  if (iVar1 == 0x16) {
    iVar2 = ((p7->d).data)->type;
  }
  else {
    iVar2 = 0;
  }
  iVar1 = (*(code *)PTR_SMIME_write_ASN1_006aa2dc)
                    (bio,p7,data,flags ^ 0x400,iVar1,0,iVar2,PTR_PKCS7_it_006aa0c0);
  return iVar1;
}

