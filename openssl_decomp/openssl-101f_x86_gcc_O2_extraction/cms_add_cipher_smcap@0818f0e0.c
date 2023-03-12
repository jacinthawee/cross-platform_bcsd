
undefined4 __regparm3 cms_add_cipher_smcap(_STACK **param_1,int param_2,int param_3)

{
  char *name;
  EVP_CIPHER *pEVar1;
  ASN1_INTEGER *a;
  int iVar2;
  X509_ALGOR *alg;
  ASN1_OBJECT *aobj;
  _STACK *st;
  int local_20;
  
  name = OBJ_nid2sn(param_2);
  pEVar1 = EVP_get_cipherbyname(name);
  if (pEVar1 != (EVP_CIPHER *)0x0) {
    if (param_3 < 1) {
      alg = X509_ALGOR_new();
      if (alg == (X509_ALGOR *)0x0) {
        return 0;
      }
      a = (ASN1_INTEGER *)0x0;
      local_20 = -1;
    }
    else {
      a = ASN1_INTEGER_new();
      if ((a == (ASN1_INTEGER *)0x0) || (iVar2 = ASN1_INTEGER_set(a,param_3), iVar2 == 0)) {
        return 0;
      }
      alg = X509_ALGOR_new();
      if (alg == (X509_ALGOR *)0x0) {
        ASN1_INTEGER_free(a);
        return 0;
      }
      local_20 = 2;
    }
    aobj = OBJ_nid2obj(param_2);
    X509_ALGOR_set0(alg,aobj,local_20,a);
    st = *param_1;
    if (st == (_STACK *)0x0) {
      st = sk_new_null();
      *param_1 = st;
      if (st == (_STACK *)0x0) goto LAB_0818f16d;
    }
    iVar2 = sk_push(st,alg);
    if (iVar2 == 0) {
LAB_0818f16d:
      X509_ALGOR_free(alg);
      return 0;
    }
  }
  return 1;
}

