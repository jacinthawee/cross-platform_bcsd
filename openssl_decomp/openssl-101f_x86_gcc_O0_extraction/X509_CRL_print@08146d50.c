
int X509_CRL_print(BIO *bp,X509_CRL *x)

{
  ASN1_TIME *a;
  _STACK *p_Var1;
  long lVar2;
  char *ptr;
  int iVar3;
  ASN1_INTEGER **ppAVar4;
  int iVar5;
  undefined1 *puVar6;
  
  BIO_printf(bp,"Certificate Revocation List (CRL):\n");
  lVar2 = ASN1_INTEGER_get(x->crl->version);
  BIO_printf(bp,"%8sVersion %lu (0x%lx)\n",&DAT_081ec74a,lVar2 + 1,lVar2);
  OBJ_obj2nid(x->sig_alg->algorithm);
  X509_signature_print(bp,x->sig_alg,(ASN1_STRING *)0x0);
  ptr = X509_NAME_oneline(x->crl->issuer,(char *)0x0,0);
  BIO_printf(bp,"%8sIssuer: %s\n",&DAT_081ec74a,ptr);
  CRYPTO_free(ptr);
  BIO_printf(bp,"%8sLast Update: ",&DAT_081ec74a);
  ASN1_TIME_print(bp,x->crl->lastUpdate);
  puVar6 = &DAT_081ec74a;
  BIO_printf(bp,"\n%8sNext Update: ",&DAT_081ec74a);
  a = x->crl->nextUpdate;
  if (a == (ASN1_TIME *)0x0) {
    BIO_printf(bp,"NONE",puVar6);
  }
  else {
    ASN1_TIME_print(bp,a);
  }
  BIO_printf(bp,"\n",puVar6);
  X509V3_extensions_print(bp,"CRL extensions",x->crl->extensions,0,8);
  p_Var1 = (_STACK *)x->crl->revoked;
  iVar3 = sk_num(p_Var1);
  if (iVar3 < 1) {
    BIO_printf(bp,"No Revoked Certificates.\n");
  }
  else {
    BIO_printf(bp,"Revoked Certificates:\n");
  }
  iVar3 = 0;
  while( true ) {
    iVar5 = sk_num(p_Var1);
    if (iVar5 <= iVar3) break;
    ppAVar4 = (ASN1_INTEGER **)sk_value(p_Var1,iVar3);
    BIO_printf(bp,"    Serial Number: ");
    i2a_ASN1_INTEGER(bp,*ppAVar4);
    BIO_printf(bp,"\n        Revocation Date: ");
    ASN1_TIME_print(bp,ppAVar4[1]);
    BIO_printf(bp,"\n");
    X509V3_extensions_print(bp,"CRL entry extensions",(stack_st_X509_EXTENSION *)ppAVar4[2],0,8);
    iVar3 = iVar3 + 1;
  }
  X509_signature_print(bp,x->sig_alg,x->signature);
  return 1;
}

