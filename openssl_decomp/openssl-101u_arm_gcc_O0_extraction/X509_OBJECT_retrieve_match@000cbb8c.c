
X509_OBJECT * X509_OBJECT_retrieve_match(stack_st_X509_OBJECT *h,X509_OBJECT *x)

{
  int iVar1;
  int iVar2;
  X509_OBJECT *pXVar3;
  
  iVar1 = sk_find(&h->stack,x);
  if (iVar1 != -1) {
    if (1 < x->type - 1U) {
      pXVar3 = (X509_OBJECT *)sk_value(&h->stack,iVar1);
      return pXVar3;
    }
    iVar2 = sk_num(&h->stack);
    if (iVar1 < iVar2) {
      do {
        pXVar3 = (X509_OBJECT *)sk_value(&h->stack,iVar1);
        iVar2 = pXVar3->type;
        if (iVar2 != x->type) {
          return (X509_OBJECT *)0x0;
        }
        if (iVar2 == 1) {
          iVar2 = X509_subject_name_cmp((pXVar3->data).x509,(x->data).x509);
LAB_000cbbd0:
          if (iVar2 != 0) {
            return (X509_OBJECT *)0x0;
          }
          iVar2 = x->type;
        }
        else if (iVar2 == 2) {
          iVar2 = X509_CRL_cmp((pXVar3->data).crl,(x->data).crl);
          goto LAB_000cbbd0;
        }
        if (iVar2 == 1) {
          iVar2 = X509_cmp((pXVar3->data).x509,(x->data).x509);
        }
        else {
          if (iVar2 != 2) {
            return pXVar3;
          }
          iVar2 = X509_CRL_match((pXVar3->data).crl,(x->data).crl);
        }
        if (iVar2 == 0) {
          return pXVar3;
        }
        iVar1 = iVar1 + 1;
        iVar2 = sk_num(&h->stack);
      } while (iVar1 < iVar2);
    }
  }
  return (X509_OBJECT *)0x0;
}

