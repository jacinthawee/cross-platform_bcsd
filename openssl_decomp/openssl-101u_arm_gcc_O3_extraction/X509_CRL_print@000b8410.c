
int X509_CRL_print(BIO *bp,X509_CRL *x)

{
  long lVar1;
  char *pcVar2;
  int iVar3;
  ASN1_INTEGER **ppAVar4;
  int iVar5;
  ASN1_TIME *a;
  _STACK *p_Var6;
  
  BIO_printf(bp,"Certificate Revocation List (CRL):\n");
  lVar1 = ASN1_INTEGER_get(x->crl->version);
  BIO_printf(bp,"%8sVersion %lu (0x%lx)\n","",lVar1 + 1,lVar1);
  OBJ_obj2nid(x->sig_alg->algorithm);
  X509_signature_print(bp,x->sig_alg,(ASN1_STRING *)0x0);
  pcVar2 = X509_NAME_oneline(x->crl->issuer,(char *)0x0,0);
  BIO_printf(bp,"%8sIssuer: %s\n","",pcVar2);
  CRYPTO_free(pcVar2);
  BIO_printf(bp,"%8sLast Update: ","");
  ASN1_TIME_print(bp,x->crl->lastUpdate);
  BIO_printf(bp,"\n%8sNext Update: ","");
  a = x->crl->nextUpdate;
  if (a == (ASN1_TIME *)0x0) {
    BIO_printf(bp,"NONE");
  }
  else {
    ASN1_TIME_print(bp,a);
  }
  BIO_printf(bp,"\n");
  X509V3_extensions_print(bp,"CRL extensions",x->crl->extensions,0,8);
  p_Var6 = (_STACK *)x->crl->revoked;
  iVar3 = sk_num(p_Var6);
  if (iVar3 < 1) {
    pcVar2 = "No Revoked Certificates.\n";
  }
  else {
    pcVar2 = "Revoked Certificates:\n";
  }
  BIO_printf(bp,pcVar2);
  iVar3 = 0;
  while( true ) {
    iVar5 = sk_num(p_Var6);
    if (iVar5 <= iVar3) break;
    ppAVar4 = (ASN1_INTEGER **)sk_value(p_Var6,iVar3);
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

