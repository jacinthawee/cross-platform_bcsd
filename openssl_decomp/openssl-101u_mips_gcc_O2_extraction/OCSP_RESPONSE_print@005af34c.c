
int OCSP_RESPONSE_print(BIO *bp,OCSP_RESPONSE *o,ulong flags)

{
  int iVar1;
  OCSP_BASICRESP *a;
  OCSP_RESPID *pOVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  OCSP_RESPDATA *pOVar7;
  OCSP_RESPBYTES *pOVar8;
  int *piVar9;
  undefined4 *puVar10;
  
  pOVar8 = o->responseBytes;
  iVar1 = (*(code *)PTR_BIO_puts_006a6f58)(bp,"OCSP Response Data:\n");
  if (0 < iVar1) {
    iVar1 = (*(code *)PTR_ASN1_ENUMERATED_get_006a8d2c)(o->responseStatus);
    pcVar6 = rstat_tbl_13567._4_4_;
    if (((((iVar1 != 0) && (pcVar6 = rstat_tbl_13567._12_4_, iVar1 != 1)) &&
         (pcVar6 = rstat_tbl_13567._20_4_, iVar1 != 2)) &&
        ((pcVar6 = rstat_tbl_13567._28_4_, iVar1 != 3 &&
         (pcVar6 = rstat_tbl_13567._36_4_, iVar1 != 5)))) &&
       (pcVar6 = rstat_tbl_13567._44_4_, iVar1 != 6)) {
      pcVar6 = "(UNKNOWN)";
    }
    iVar1 = (*(code *)PTR_BIO_printf_006a6e38)
                      (bp,"    OCSP Response Status: %s (0x%lx)\n",pcVar6,iVar1);
    if (0 < iVar1) {
      if (pOVar8 == (OCSP_RESPBYTES *)0x0) {
        return 1;
      }
      iVar1 = (*(code *)PTR_BIO_puts_006a6f58)(bp,"    Response Type: ");
      if ((0 < iVar1) &&
         (iVar1 = (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(bp,pOVar8->responseType), 0 < iVar1)) {
        iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pOVar8->responseType);
        if (iVar1 != 0x16d) {
          (*(code *)PTR_BIO_puts_006a6f58)(bp," (unknown response type)\n");
          return 1;
        }
        a = OCSP_response_get1_basic(o);
        if (a != (OCSP_BASICRESP *)0x0) {
          pOVar7 = a->tbsResponseData;
          iVar1 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(pOVar7->version);
          iVar1 = (*(code *)PTR_BIO_printf_006a6e38)
                            (bp,"\n    Version: %lu (0x%lx)\n",iVar1 + 1,iVar1);
          if ((0 < iVar1) &&
             (iVar1 = (*(code *)PTR_BIO_puts_006a6f58)(bp,"    Responder Id: "), 0 < iVar1)) {
            pOVar2 = pOVar7->responderId;
            if (pOVar2->type == 0) {
              (*(code *)PTR_X509_NAME_print_ex_006a7bc4)(bp,(pOVar2->value).byName,0,0x82031f);
            }
            else if (pOVar2->type == 1) {
              (*(code *)PTR_i2a_ASN1_STRING_006a9088)(bp,(pOVar2->value).byName,4);
            }
            iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"\n    Produced At: ");
            if (((0 < iVar1) &&
                (iVar1 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(bp,pOVar7->producedAt),
                iVar1 != 0)) &&
               (iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"\n    Responses:\n"), 0 < iVar1)) {
              for (iVar1 = 0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(pOVar7->responses),
                  iVar1 < iVar3; iVar1 = iVar1 + 1) {
                iVar3 = (*(code *)PTR_sk_value_006a6e24)(pOVar7->responses,iVar1);
                if (iVar3 != 0) {
                  puVar4 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(pOVar7->responses,iVar1);
                  iVar3 = ocsp_certid_print(bp,*puVar4,4);
                  if (iVar3 < 1) goto LAB_005af5cc;
                  piVar9 = (int *)puVar4[1];
                  iVar3 = *piVar9;
                  pcVar6 = cstat_tbl_13571._4_4_;
                  if (((iVar3 != 0) && (pcVar6 = cstat_tbl_13571._12_4_, iVar3 != 1)) &&
                     (pcVar6 = cstat_tbl_13571._20_4_, iVar3 != 2)) {
                    pcVar6 = "(UNKNOWN)";
                  }
                  iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"    Cert Status: %s",pcVar6);
                  if (iVar3 < 1) goto LAB_005af5cc;
                  if (*piVar9 == 1) {
                    puVar10 = (undefined4 *)piVar9[1];
                    iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"\n    Revocation Time: ");
                    if ((iVar3 < 1) ||
                       (iVar3 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(bp,*puVar10),
                       iVar3 == 0)) goto LAB_005af5cc;
                    if (puVar10[1] != 0) {
                      iVar3 = (*(code *)PTR_ASN1_ENUMERATED_get_006a8d2c)();
                      pcVar6 = reason_tbl_13575._4_4_;
                      if (((((iVar3 != 0) && (pcVar6 = reason_tbl_13575._12_4_, iVar3 != 1)) &&
                           (pcVar6 = reason_tbl_13575._20_4_, iVar3 != 2)) &&
                          ((pcVar6 = reason_tbl_13575._28_4_, iVar3 != 3 &&
                           (pcVar6 = reason_tbl_13575._36_4_, iVar3 != 4)))) &&
                         ((pcVar6 = reason_tbl_13575._44_4_, iVar3 != 5 &&
                          ((pcVar6 = reason_tbl_13575._52_4_, iVar3 != 6 &&
                           (pcVar6 = reason_tbl_13575._60_4_, iVar3 != 8)))))) {
                        pcVar6 = "(UNKNOWN)";
                      }
                      iVar3 = (*(code *)PTR_BIO_printf_006a6e38)
                                        (bp,"\n    Revocation Reason: %s (0x%lx)",pcVar6,iVar3);
                      if (iVar3 < 1) {
                        iVar1 = 0;
                        goto LAB_005af488;
                      }
                    }
                  }
                  iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"\n    This Update: ");
                  if (((((iVar3 < 1) ||
                        (iVar3 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(bp,puVar4[2]),
                        iVar3 == 0)) ||
                       ((puVar4[3] != 0 &&
                        ((iVar3 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"\n    Next Update: "),
                         iVar3 < 1 ||
                         (iVar3 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(bp,puVar4[3]),
                         iVar3 == 0)))))) ||
                      (iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1), iVar3 < 1)) ||
                     ((iVar3 = (*(code *)PTR_X509V3_extensions_print_006a8d60)
                                         (bp,"Response Single Extensions",puVar4[4],flags,8),
                      iVar3 == 0 ||
                      (iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1), iVar3 < 1))))
                  goto LAB_005af5cc;
                }
              }
              iVar1 = (*(code *)PTR_X509V3_extensions_print_006a8d60)
                                (bp,"Response Extensions",pOVar7->responseExtensions,flags,4);
              if ((iVar1 != 0) &&
                 (iVar1 = (*(code *)PTR_X509_signature_print_006a8d58)
                                    (bp,a->signatureAlgorithm,a->signature), 0 < iVar1)) {
                for (iVar1 = 0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(a->certs), iVar1 < iVar3;
                    iVar1 = iVar1 + 1) {
                  uVar5 = (*(code *)PTR_sk_value_006a6e24)(a->certs,iVar1);
                  (*(code *)PTR_X509_print_006a70c0)(bp,uVar5);
                  uVar5 = (*(code *)PTR_sk_value_006a6e24)(a->certs,iVar1);
                  (*(code *)PTR_PEM_write_bio_X509_006a6f20)(bp,uVar5);
                }
                iVar1 = 1;
                goto LAB_005af488;
              }
            }
          }
LAB_005af5cc:
          iVar1 = 0;
          goto LAB_005af488;
        }
      }
    }
  }
  a = (OCSP_BASICRESP *)0x0;
  iVar1 = 0;
LAB_005af488:
  OCSP_BASICRESP_free(a);
  return iVar1;
}

