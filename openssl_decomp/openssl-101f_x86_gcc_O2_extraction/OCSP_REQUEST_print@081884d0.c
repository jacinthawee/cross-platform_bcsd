
int OCSP_REQUEST_print(BIO *bp,OCSP_REQUEST *a,ulong flags)

{
  OCSP_REQINFO *pOVar1;
  OCSP_SIGNATURE *pOVar2;
  int iVar3;
  long lVar4;
  void *pvVar5;
  int iVar6;
  X509 *pXVar7;
  
  pOVar1 = a->tbsRequest;
  pOVar2 = a->optionalSignature;
  iVar3 = BIO_write(bp,"OCSP Request Data:\n",0x13);
  if (0 < iVar3) {
    lVar4 = ASN1_INTEGER_get(pOVar1->version);
    iVar3 = BIO_printf(bp,"    Version: %lu (0x%lx)",lVar4 + 1,lVar4);
    if (0 < iVar3) {
      if (pOVar1->requestorName != (GENERAL_NAME *)0x0) {
        iVar3 = BIO_write(bp,"\n    Requestor Name: ",0x15);
        if (iVar3 < 1) {
          return 0;
        }
        GENERAL_NAME_print(bp,pOVar1->requestorName);
      }
      iVar3 = BIO_write(bp,"\n    Requestor List:\n",0x15);
      if (0 < iVar3) {
        for (iVar3 = 0; iVar6 = sk_num((_STACK *)pOVar1->requestList), iVar3 < iVar6;
            iVar3 = iVar3 + 1) {
          pvVar5 = sk_value((_STACK *)pOVar1->requestList,iVar3);
          ocsp_certid_print();
          iVar6 = X509V3_extensions_print
                            (bp,"Request Single Extensions",
                             *(stack_st_X509_EXTENSION **)((int)pvVar5 + 4),flags,8);
          if (iVar6 == 0) {
            return 0;
          }
        }
        iVar3 = X509V3_extensions_print(bp,"Request Extensions",pOVar1->requestExtensions,flags,4);
        if (iVar3 != 0) {
          if (pOVar2 != (OCSP_SIGNATURE *)0x0) {
            X509_signature_print(bp,pOVar2->signatureAlgorithm,pOVar2->signature);
            for (iVar3 = 0; iVar6 = sk_num((_STACK *)pOVar2->certs), iVar3 < iVar6;
                iVar3 = iVar3 + 1) {
              pXVar7 = (X509 *)sk_value((_STACK *)pOVar2->certs,iVar3);
              X509_print(bp,pXVar7);
              pXVar7 = (X509 *)sk_value((_STACK *)pOVar2->certs,iVar3);
              PEM_write_bio_X509(bp,pXVar7);
            }
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

