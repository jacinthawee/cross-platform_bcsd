
int OCSP_RESPONSE_print(BIO *bp,OCSP_RESPONSE *o,ulong flags)

{
  int iVar1;
  long lVar2;
  OCSP_BASICRESP *a;
  void *pvVar3;
  undefined4 *puVar4;
  ASN1_ENUMERATED *a_00;
  X509 *pXVar5;
  OCSP_RESPID *pOVar6;
  char *pcVar7;
  undefined *puVar8;
  int *piVar9;
  OCSP_RESPBYTES *pOVar10;
  int iVar11;
  ASN1_GENERALIZEDTIME **ppAVar12;
  OCSP_RESPDATA *pOVar13;
  
  pOVar10 = o->responseBytes;
  iVar1 = BIO_puts(bp,"OCSP Response Data:\n");
  if (0 < iVar1) {
    lVar2 = ASN1_ENUMERATED_get(o->responseStatus);
    piVar9 = &rstat_tbl_16186;
    do {
      if (lVar2 == *piVar9) {
        pcVar7 = (char *)piVar9[1];
        goto LAB_000e2dae;
      }
      piVar9 = piVar9 + 2;
    } while (piVar9 < cstat_tbl_16190);
    pcVar7 = "(UNKNOWN)";
LAB_000e2dae:
    iVar1 = BIO_printf(bp,"    OCSP Response Status: %s (0x%lx)\n",pcVar7);
    if (0 < iVar1) {
      if (pOVar10 == (OCSP_RESPBYTES *)0x0) {
        return 1;
      }
      iVar1 = BIO_puts(bp,"    Response Type: ");
      if ((0 < iVar1) && (iVar1 = i2a_ASN1_OBJECT(bp,pOVar10->responseType), 0 < iVar1)) {
        iVar1 = OBJ_obj2nid(pOVar10->responseType);
        if (iVar1 != 0x16d) {
          BIO_puts(bp," (unknown response type)\n");
          return 1;
        }
        ASN1_STRING_length(pOVar10->response);
        a = OCSP_response_get1_basic(o);
        if (a != (OCSP_BASICRESP *)0x0) {
          pOVar13 = a->tbsResponseData;
          lVar2 = ASN1_INTEGER_get(pOVar13->version);
          iVar1 = BIO_printf(bp,"\n    Version: %lu (0x%lx)\n",lVar2 + 1);
          if ((0 < iVar1) && (iVar1 = BIO_puts(bp,"    Responder Id: "), 0 < iVar1)) {
            pOVar6 = pOVar13->responderId;
            if (pOVar6->type == 0) {
              X509_NAME_print_ex(bp,(pOVar6->value).byName,0,0x82031f);
            }
            else if (pOVar6->type == 1) {
              i2a_ASN1_STRING(bp,(ASN1_STRING *)(pOVar6->value).byName,4);
            }
            iVar1 = BIO_printf(bp,"\n    Produced At: ");
            if (((0 < iVar1) &&
                (iVar1 = ASN1_GENERALIZEDTIME_print(bp,pOVar13->producedAt), iVar1 != 0)) &&
               (iVar1 = BIO_printf(bp,"\n    Responses:\n"), 0 < iVar1)) {
              for (iVar1 = 0; iVar11 = sk_num((_STACK *)pOVar13->responses), iVar1 < iVar11;
                  iVar1 = iVar1 + 1) {
                pvVar3 = sk_value((_STACK *)pOVar13->responses,iVar1);
                if (pvVar3 != (void *)0x0) {
                  puVar4 = (undefined4 *)sk_value((_STACK *)pOVar13->responses,iVar1);
                  iVar11 = ocsp_certid_print(bp,*puVar4,4);
                  if (iVar11 < 1) goto LAB_000e2e8e;
                  piVar9 = (int *)puVar4[1];
                  iVar11 = BIO_printf(bp,"    Cert Status: %s");
                  if (iVar11 < 1) goto LAB_000e2e8e;
                  if (*piVar9 == 1) {
                    ppAVar12 = (ASN1_GENERALIZEDTIME **)piVar9[1];
                    iVar11 = BIO_printf(bp,"\n    Revocation Time: ");
                    if ((iVar11 < 1) ||
                       (iVar11 = ASN1_GENERALIZEDTIME_print(bp,*ppAVar12), iVar11 == 0))
                    goto LAB_000e2e8e;
                    a_00 = ppAVar12[1];
                    if (a_00 != (ASN1_ENUMERATED *)0x0) {
                      lVar2 = ASN1_ENUMERATED_get(a_00);
                      puVar8 = PTR_reason_tbl_16194_000e30d4;
                      if (((lVar2 == 0) || (puVar8 = DAT_000e30d0, lVar2 == 1)) ||
                         ((puVar8 = DAT_000e30cc, lVar2 == 2 ||
                          ((((puVar8 = DAT_000e30c8, lVar2 == 3 ||
                             (puVar8 = DAT_000e30c4, lVar2 == 4)) ||
                            (puVar8 = DAT_000e30c0, lVar2 == 5)) ||
                           ((puVar8 = DAT_000e30bc, lVar2 == 6 ||
                            (puVar8 = DAT_000e30b0, lVar2 == 8)))))))) {
                        pcVar7 = *(char **)(puVar8 + 4);
                      }
                      else {
                        pcVar7 = "(UNKNOWN)";
                      }
                      iVar11 = BIO_printf(bp,"\n    Revocation Reason: %s (0x%lx)",pcVar7,lVar2);
                      if (iVar11 < 1) goto LAB_000e2e8e;
                    }
                  }
                  iVar11 = BIO_printf(bp,"\n    This Update: ");
                  if ((((iVar11 < 1) ||
                       (iVar11 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)puVar4[2]),
                       iVar11 == 0)) ||
                      (((puVar4[3] != 0 &&
                        ((iVar11 = BIO_printf(bp,"\n    Next Update: "), iVar11 < 1 ||
                         (iVar11 = ASN1_GENERALIZEDTIME_print(bp,(ASN1_GENERALIZEDTIME *)puVar4[3]),
                         iVar11 == 0)))) || (iVar11 = BIO_write(bp,"\n",1), iVar11 < 1)))) ||
                     ((iVar11 = X509V3_extensions_print
                                          (bp,"Response Single Extensions",
                                           (stack_st_X509_EXTENSION *)puVar4[4],flags,8),
                      iVar11 == 0 || (iVar11 = BIO_write(bp,"\n",1), iVar11 < 1))))
                  goto LAB_000e2e8e;
                }
              }
              iVar1 = X509V3_extensions_print
                                (bp,"Response Extensions",pOVar13->responseExtensions,flags,4);
              if (iVar1 != 0) {
                iVar11 = 0;
                iVar1 = X509_signature_print(bp,a->signatureAlgorithm,a->signature);
                if (0 < iVar1) {
                  for (; iVar1 = sk_num((_STACK *)a->certs), iVar11 < iVar1; iVar11 = iVar11 + 1) {
                    pXVar5 = (X509 *)sk_value((_STACK *)a->certs,iVar11);
                    X509_print(bp,pXVar5);
                    pXVar5 = (X509 *)sk_value((_STACK *)a->certs,iVar11);
                    PEM_write_bio_X509(bp,pXVar5);
                  }
                  iVar11 = 1;
                }
                goto LAB_000e2e0a;
              }
            }
          }
LAB_000e2e8e:
          iVar11 = 0;
          goto LAB_000e2e0a;
        }
      }
    }
  }
  a = (OCSP_BASICRESP *)0x0;
  iVar11 = 0;
LAB_000e2e0a:
  OCSP_BASICRESP_free(a);
  return iVar11;
}

