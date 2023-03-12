
int X509_ALGOR_set0(X509_ALGOR *alg,ASN1_OBJECT *aobj,int ptype,void *pval)

{
  ASN1_TYPE *pAVar1;
  ASN1_OBJECT *a;
  
  if (alg == (X509_ALGOR *)0x0) {
    return 0;
  }
  if (ptype == -1) {
    a = alg->algorithm;
    if (a != (ASN1_OBJECT *)0x0) goto LAB_00553be4;
    alg->algorithm = aobj;
LAB_00553c04:
    if (alg->parameter != (ASN1_TYPE *)0x0) {
      ASN1_TYPE_free(alg->parameter);
      alg->parameter = (ASN1_TYPE *)0x0;
      return 1;
    }
  }
  else {
    if (alg->parameter == (ASN1_TYPE *)0x0) {
      pAVar1 = ASN1_TYPE_new();
      alg->parameter = pAVar1;
      if (pAVar1 == (ASN1_TYPE *)0x0) {
        return 0;
      }
    }
    a = alg->algorithm;
    if (a == (ASN1_OBJECT *)0x0) {
      alg->algorithm = aobj;
      if (ptype == 0) {
        return 1;
      }
    }
    else {
LAB_00553be4:
      ASN1_OBJECT_free(a);
      alg->algorithm = aobj;
      if (ptype == 0) {
        return 1;
      }
      if (ptype == -1) goto LAB_00553c04;
    }
    ASN1_TYPE_set(alg->parameter,ptype,pval);
  }
  return 1;
}

