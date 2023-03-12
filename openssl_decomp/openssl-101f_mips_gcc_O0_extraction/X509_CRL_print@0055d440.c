
int X509_CRL_print(BIO *bp,X509_CRL *x)

{
  long lVar1;
  char *pcVar2;
  int iVar3;
  ASN1_INTEGER **ppAVar4;
  int iVar5;
  ASN1_TIME *a;
  stack_st_X509_REVOKED *psVar6;
  
  (*(code *)PTR_BIO_printf_006a7f38)(bp,"Certificate Revocation List (CRL):\n");
  lVar1 = ASN1_INTEGER_get(x->crl->version);
  (*(code *)PTR_BIO_printf_006a7f38)(bp,"%8sVersion %lu (0x%lx)\n","",lVar1 + 1,lVar1);
  (*(code *)PTR_OBJ_obj2nid_006a822c)(x->sig_alg->algorithm);
  X509_signature_print(bp,x->sig_alg,(ASN1_STRING *)0x0);
  pcVar2 = X509_NAME_oneline(x->crl->issuer,(char *)0x0,0);
  (*(code *)PTR_BIO_printf_006a7f38)(bp,"%8sIssuer: %s\n","",pcVar2);
  (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar2);
  (*(code *)PTR_BIO_printf_006a7f38)(bp,"%8sLast Update: ","");
  ASN1_TIME_print(bp,x->crl->lastUpdate);
  (*(code *)PTR_BIO_printf_006a7f38)(bp,"\n%8sNext Update: ","");
  a = x->crl->nextUpdate;
  if (a == (ASN1_TIME *)0x0) {
    (*(code *)PTR_BIO_printf_006a7f38)(bp,&DAT_00637b4c);
  }
  else {
    ASN1_TIME_print(bp,a);
  }
  (*(code *)PTR_BIO_printf_006a7f38)(bp,"\n");
  (*(code *)PTR_X509V3_extensions_print_006a9e80)(bp,"CRL extensions",x->crl->extensions,0,8);
  psVar6 = x->crl->revoked;
  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(psVar6);
  if (iVar3 < 1) {
    (*(code *)PTR_BIO_printf_006a7f38)(bp,"No Revoked Certificates.\n");
  }
  else {
    (*(code *)PTR_BIO_printf_006a7f38)(bp,"Revoked Certificates:\n");
  }
  iVar3 = 0;
  while( true ) {
    iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar6);
    if (iVar5 <= iVar3) break;
    ppAVar4 = (ASN1_INTEGER **)(*(code *)PTR_sk_value_006a7f24)(psVar6,iVar3);
    (*(code *)PTR_BIO_printf_006a7f38)(bp,"    Serial Number: ");
    i2a_ASN1_INTEGER(bp,*ppAVar4);
    (*(code *)PTR_BIO_printf_006a7f38)(bp,"\n        Revocation Date: ");
    ASN1_TIME_print(bp,ppAVar4[1]);
    (*(code *)PTR_BIO_printf_006a7f38)(bp,"\n");
    (*(code *)PTR_X509V3_extensions_print_006a9e80)(bp,"CRL entry extensions",ppAVar4[2],0,8);
    iVar3 = iVar3 + 1;
  }
  X509_signature_print(bp,x->sig_alg,x->signature);
  return 1;
}

