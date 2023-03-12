
int PKCS7_set_digest(PKCS7 *p7,EVP_MD *md)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_TYPE *pAVar3;
  X509_ALGOR *pXVar4;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x19) {
    pXVar4 = ((p7->d).digest)->md;
    pAVar3 = ASN1_TYPE_new();
    pXVar4->parameter = pAVar3;
    if (pAVar3 != (ASN1_TYPE *)0x0) {
      pXVar4 = ((p7->d).digest)->md;
      pXVar4->parameter->type = 5;
      iVar1 = EVP_MD_type(md);
      pAVar2 = OBJ_nid2obj(iVar1);
      pXVar4->algorithm = pAVar2;
      return 1;
    }
    ERR_put_error(0x21,0x7e,0x41,"pk7_lib.c",0x1b2);
  }
  else {
    ERR_put_error(0x21,0x7e,0x71,"pk7_lib.c",0x1ba);
    pAVar3 = (ASN1_TYPE *)0x1;
  }
  return (int)pAVar3;
}

