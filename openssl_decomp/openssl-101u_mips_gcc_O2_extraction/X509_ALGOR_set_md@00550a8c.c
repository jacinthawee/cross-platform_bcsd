
void X509_ALGOR_set_md(X509_ALGOR *alg,EVP_MD *md)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_TYPE *pAVar3;
  ASN1_OBJECT *a;
  
  if ((md->flags & 8) == 0) {
    iVar1 = EVP_MD_type(md);
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar1);
    if (alg != (X509_ALGOR *)0x0) {
      if (alg->parameter == (ASN1_TYPE *)0x0) {
        pAVar3 = ASN1_TYPE_new();
        alg->parameter = pAVar3;
        if (pAVar3 == (ASN1_TYPE *)0x0) {
          return;
        }
        a = alg->algorithm;
      }
      else {
        a = alg->algorithm;
      }
      if (a != (ASN1_OBJECT *)0x0) {
        ASN1_OBJECT_free(a);
      }
      alg->algorithm = pAVar2;
      ASN1_TYPE_set(alg->parameter,5,(void *)0x0);
      return;
    }
  }
  else {
    iVar1 = EVP_MD_type(md);
    pAVar2 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar1);
    if (alg != (X509_ALGOR *)0x0) {
      if (alg->algorithm != (ASN1_OBJECT *)0x0) {
        ASN1_OBJECT_free(alg->algorithm);
      }
      alg->algorithm = pAVar2;
      if (alg->parameter != (ASN1_TYPE *)0x0) {
        ASN1_TYPE_free(alg->parameter);
        alg->parameter = (ASN1_TYPE *)0x0;
      }
    }
  }
  return;
}

