
int OCSP_RESPONSE_print(BIO *bp,OCSP_RESPONSE *o,ulong flags)

{
  OCSP_RESPBYTES *pOVar1;
  OCSP_RESPDATA *pOVar2;
  OCSP_RESPID *pOVar3;
  int *piVar4;
  ASN1_GENERALIZEDTIME **ppAVar5;
  ASN1_ENUMERATED *a;
  int iVar6;
  long lVar7;
  OCSP_BASICRESP *a_00;
  long lVar8;
  void *pvVar9;
  X509 *pXVar10;
  char *pcVar11;
  undefined1 *puVar12;
  int iVar13;
  
  pOVar1 = o->responseBytes;
  iVar6 = BIO_puts(bp,"OCSP Response Data:\n");
  if (0 < iVar6) {
    lVar7 = ASN1_ENUMERATED_get(o->responseStatus);
    if (lVar7 == 0) {
      puVar12 = rstat_tbl_13558;
LAB_08188a70:
      pcVar11 = *(char **)(puVar12 + 4);
    }
    else {
      if (lVar7 == 1) {
        puVar12 = (undefined1 *)0x82308e8;
        goto LAB_08188a70;
      }
      if (lVar7 == 2) {
        puVar12 = (undefined1 *)0x82308f0;
        goto LAB_08188a70;
      }
      if (lVar7 == 3) {
        puVar12 = (undefined1 *)0x82308f8;
        goto LAB_08188a70;
      }
      if (lVar7 == 5) {
        puVar12 = (undefined1 *)0x8230900;
        goto LAB_08188a70;
      }
      pcVar11 = "(UNKNOWN)";
      if (lVar7 == 6) {
        puVar12 = (undefined1 *)0x8230908;
        goto LAB_08188a70;
      }
    }
    iVar6 = BIO_printf(bp,"    OCSP Response Status: %s (0x%lx)\n",pcVar11,lVar7);
    if (0 < iVar6) {
      if (pOVar1 == (OCSP_RESPBYTES *)0x0) {
        return 1;
      }
      iVar6 = BIO_puts(bp,"    Response Type: ");
      if ((0 < iVar6) && (iVar6 = i2a_ASN1_OBJECT(bp,pOVar1->responseType), 0 < iVar6)) {
        iVar6 = OBJ_obj2nid(pOVar1->responseType);
        if (iVar6 != 0x16d) {
          BIO_puts(bp," (unknown response type)\n");
          return 1;
        }
        ASN1_STRING_length(pOVar1->response);
        a_00 = OCSP_response_get1_basic(o);
        if (a_00 != (OCSP_BASICRESP *)0x0) {
          pOVar2 = a_00->tbsResponseData;
          iVar13 = 0;
          lVar8 = ASN1_INTEGER_get(pOVar2->version);
          iVar6 = BIO_printf(bp,"\n    Version: %lu (0x%lx)\n",lVar8 + 1,lVar8);
          if ((0 < iVar6) && (iVar6 = BIO_puts(bp,"    Responder Id: "), 0 < iVar6)) {
            pOVar3 = pOVar2->responderId;
            if (pOVar3->type == 0) {
              lVar7 = 0x82031f;
              X509_NAME_print_ex(bp,(pOVar3->value).byName,0,0x82031f);
            }
            else if (pOVar3->type == 1) {
              i2a_ASN1_STRING(bp,(ASN1_STRING *)(pOVar3->value).byName,4);
            }
            iVar13 = 0;
            iVar6 = BIO_printf(bp,"\n    Produced At: ");
            if (((0 < iVar6) &&
                (iVar6 = ASN1_GENERALIZEDTIME_print(bp,pOVar2->producedAt), iVar6 != 0)) &&
               (iVar6 = BIO_printf(bp,"\n    Responses:\n"), 0 < iVar6)) {
              for (; iVar6 = sk_num((_STACK *)pOVar2->responses), iVar13 < iVar6;
                  iVar13 = iVar13 + 1) {
                pvVar9 = sk_value((_STACK *)pOVar2->responses,iVar13);
                if (pvVar9 != (void *)0x0) {
                  pvVar9 = sk_value((_STACK *)pOVar2->responses,iVar13);
                  iVar6 = ocsp_certid_print();
                  if (0 < iVar6) {
                    piVar4 = *(int **)((int)pvVar9 + 4);
                    iVar6 = *piVar4;
                    if (iVar6 == 0) {
                      puVar12 = cstat_tbl_13562;
LAB_08188ae4:
                      pcVar11 = *(char **)(puVar12 + 4);
                    }
                    else {
                      if (iVar6 == 1) {
                        puVar12 = (undefined1 *)0x82308c8;
                        goto LAB_08188ae4;
                      }
                      pcVar11 = "(UNKNOWN)";
                      if (iVar6 == 2) {
                        puVar12 = (undefined1 *)0x82308d0;
                        goto LAB_08188ae4;
                      }
                    }
                    iVar6 = BIO_printf(bp,"    Cert Status: %s",pcVar11);
                    if (0 < iVar6) {
                      if (*piVar4 == 1) {
                        ppAVar5 = (ASN1_GENERALIZEDTIME **)piVar4[1];
                        iVar6 = BIO_printf(bp,"\n    Revocation Time: ",pcVar11);
                        if ((iVar6 < 1) ||
                           (iVar6 = ASN1_GENERALIZEDTIME_print(bp,*ppAVar5), iVar6 == 0))
                        goto LAB_08188a57;
                        a = ppAVar5[1];
                        if (a == (ASN1_ENUMERATED *)0x0) goto LAB_08188845;
                        lVar7 = ASN1_ENUMERATED_get(a);
                        if (lVar7 == 0) {
                          puVar12 = reason_tbl_13566;
LAB_08188b8d:
                          pcVar11 = *(char **)(puVar12 + 4);
                        }
                        else {
                          if (lVar7 == 1) {
                            puVar12 = (undefined1 *)0x8230888;
                            goto LAB_08188b8d;
                          }
                          if (lVar7 == 2) {
                            puVar12 = (undefined1 *)0x8230890;
                            goto LAB_08188b8d;
                          }
                          if (lVar7 == 3) {
                            puVar12 = (undefined1 *)0x8230898;
                            goto LAB_08188b8d;
                          }
                          if (lVar7 == 4) {
                            puVar12 = (undefined1 *)0x82308a0;
                            goto LAB_08188b8d;
                          }
                          if (lVar7 == 5) {
                            puVar12 = (undefined1 *)0x82308a8;
                            goto LAB_08188b8d;
                          }
                          if (lVar7 == 6) {
                            puVar12 = (undefined1 *)0x82308b0;
                            goto LAB_08188b8d;
                          }
                          pcVar11 = "(UNKNOWN)";
                          if (lVar7 == 8) {
                            puVar12 = (undefined1 *)0x82308b8;
                            goto LAB_08188b8d;
                          }
                        }
                        iVar6 = BIO_printf(bp,"\n    Revocation Reason: %s (0x%lx)",pcVar11,lVar7);
                        if (iVar6 < 1) goto LAB_08188a57;
                      }
LAB_08188845:
                      iVar6 = BIO_printf(bp,"\n    This Update: ",pcVar11,lVar7);
                      if (((((0 < iVar6) &&
                            (iVar6 = ASN1_GENERALIZEDTIME_print
                                               (bp,*(ASN1_GENERALIZEDTIME **)((int)pvVar9 + 8)),
                            iVar6 != 0)) &&
                           ((*(int *)((int)pvVar9 + 0xc) == 0 ||
                            ((iVar6 = BIO_printf(bp,"\n    Next Update: ",pcVar11,lVar7), 0 < iVar6
                             && (iVar6 = ASN1_GENERALIZEDTIME_print
                                                   (bp,*(ASN1_GENERALIZEDTIME **)((int)pvVar9 + 0xc)
                                                   ), iVar6 != 0)))))) &&
                          (iVar6 = BIO_write(bp,&DAT_081f11d3,1), 0 < iVar6)) &&
                         ((iVar6 = X509V3_extensions_print
                                             (bp,"Response Single Extensions",
                                              *(stack_st_X509_EXTENSION **)((int)pvVar9 + 0x10),
                                              flags,8), iVar6 != 0 &&
                          (iVar6 = BIO_write(bp,&DAT_081f11d3,1), 0 < iVar6)))) goto LAB_08188910;
                    }
                  }
LAB_08188a57:
                  iVar13 = 0;
                  goto LAB_0818875c;
                }
LAB_08188910:
              }
              iVar13 = 0;
              iVar6 = X509V3_extensions_print
                                (bp,"Response Extensions",pOVar2->responseExtensions,flags,4);
              if ((iVar6 != 0) &&
                 (iVar6 = X509_signature_print(bp,a_00->signatureAlgorithm,a_00->signature),
                 0 < iVar6)) {
                for (iVar6 = 0; iVar13 = sk_num((_STACK *)a_00->certs), iVar6 < iVar13;
                    iVar6 = iVar6 + 1) {
                  pXVar10 = (X509 *)sk_value((_STACK *)a_00->certs,iVar6);
                  X509_print(bp,pXVar10);
                  pXVar10 = (X509 *)sk_value((_STACK *)a_00->certs,iVar6);
                  PEM_write_bio_X509(bp,pXVar10);
                }
                iVar13 = 1;
              }
            }
          }
          goto LAB_0818875c;
        }
      }
    }
  }
  a_00 = (OCSP_BASICRESP *)0x0;
  iVar13 = 0;
LAB_0818875c:
  OCSP_BASICRESP_free(a_00);
  return iVar13;
}

