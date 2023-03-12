
int X509_ALGOR_set0(X509_ALGOR *alg,ASN1_OBJECT *aobj,int ptype,void *pval)

{
  ASN1_OBJECT *a;
  ASN1_TYPE *pAVar1;
  
  if (alg == (X509_ALGOR *)0x0) {
    return 0;
  }
  if (ptype == -1) {
    a = alg->algorithm;
    if (a == (ASN1_OBJECT *)0x0) {
      alg->algorithm = aobj;
      goto LAB_0813f57a;
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
      goto LAB_0813f5aa;
    }
  }
  ASN1_OBJECT_free(a);
  alg->algorithm = aobj;
  if (ptype == 0) {
    return 1;
  }
  if (ptype != -1) {
LAB_0813f5aa:
    ASN1_TYPE_set(alg->parameter,ptype,pval);
    return 1;
  }
LAB_0813f57a:
  if (alg->parameter != (ASN1_TYPE *)0x0) {
    ASN1_TYPE_free(alg->parameter);
    alg->parameter = (ASN1_TYPE *)0x0;
  }
  return 1;
}

