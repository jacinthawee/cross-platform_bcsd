
int PKCS7_set_digest(PKCS7 *p7,EVP_MD *md)

{
  X509_ALGOR *pXVar1;
  int iVar2;
  ASN1_TYPE *pAVar3;
  ASN1_OBJECT *pAVar4;
  
  iVar2 = OBJ_obj2nid(p7->type);
  if (iVar2 == 0x19) {
    pXVar1 = ((p7->d).digest)->md;
    pAVar3 = ASN1_TYPE_new();
    pXVar1->parameter = pAVar3;
    if (pAVar3 != (ASN1_TYPE *)0x0) {
      pXVar1 = ((p7->d).digest)->md;
      pXVar1->parameter->type = 5;
      iVar2 = EVP_MD_type(md);
      pAVar4 = OBJ_nid2obj(iVar2);
      pXVar1->algorithm = pAVar4;
      return 1;
    }
    ERR_put_error(0x21,0x7e,0x41,"pk7_lib.c",0x1b2);
    iVar2 = 0;
  }
  else {
    ERR_put_error(0x21,0x7e,0x71,"pk7_lib.c",0x1ba);
    iVar2 = 1;
  }
  return iVar2;
}

