
int OCSP_REQUEST_print(BIO *bp,OCSP_REQUEST *a,ulong flags)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  OCSP_REQINFO *pOVar5;
  OCSP_SIGNATURE *pOVar6;
  
  pOVar5 = a->tbsRequest;
  pOVar6 = a->optionalSignature;
  iVar1 = (*(code *)PTR_BIO_write_006a7f14)(bp,"OCSP Request Data:\n",0x13);
  if (0 < iVar1) {
    iVar1 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(pOVar5->version);
    iVar1 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"    Version: %lu (0x%lx)",iVar1 + 1,iVar1);
    if (0 < iVar1) {
      if (pOVar5->requestorName != (GENERAL_NAME *)0x0) {
        iVar1 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n    Requestor Name: ",0x15);
        if (iVar1 < 1) {
          return 0;
        }
        (*(code *)PTR_GENERAL_NAME_print_006a84a8)(bp,pOVar5->requestorName);
      }
      iVar1 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n    Requestor List:\n",0x15);
      if (0 < iVar1) {
        iVar1 = 0;
        do {
          iVar3 = (*(code *)PTR_sk_num_006a7f2c)(pOVar5->requestList);
          if (iVar3 <= iVar1) {
            iVar1 = (*(code *)PTR_X509V3_extensions_print_006a9e80)
                              (bp,"Request Extensions",pOVar5->requestExtensions,flags,4);
            if (iVar1 == 0) {
              return 0;
            }
            iVar1 = 0;
            if (pOVar6 != (OCSP_SIGNATURE *)0x0) {
              (*(code *)PTR_X509_signature_print_006a9e78)
                        (bp,pOVar6->signatureAlgorithm,pOVar6->signature);
              for (; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(pOVar6->certs), iVar1 < iVar3;
                  iVar1 = iVar1 + 1) {
                uVar4 = (*(code *)PTR_sk_value_006a7f24)(pOVar6->certs,iVar1);
                (*(code *)PTR_X509_print_006a81c0)(bp,uVar4);
                uVar4 = (*(code *)PTR_sk_value_006a7f24)(pOVar6->certs,iVar1);
                (*(code *)PTR_PEM_write_bio_X509_006a8020)(bp,uVar4);
              }
            }
            return 1;
          }
          puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(pOVar5->requestList,iVar1);
          ocsp_certid_print(bp,*puVar2,8);
          iVar3 = (*(code *)PTR_X509V3_extensions_print_006a9e80)
                            (bp,"Request Single Extensions",puVar2[1],flags,8);
          iVar1 = iVar1 + 1;
        } while (iVar3 != 0);
      }
    }
  }
  return 0;
}

