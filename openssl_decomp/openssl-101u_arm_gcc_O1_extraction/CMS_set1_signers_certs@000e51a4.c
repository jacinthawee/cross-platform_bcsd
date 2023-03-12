
int CMS_set1_signers_certs(CMS_ContentInfo *cms,stack_st_X509 *certs,uint flags)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  X509 *pXVar5;
  EVP_PKEY *pEVar6;
  X509_NAME *pXVar7;
  ASN1_INTEGER *pAVar8;
  _STACK *p_Var9;
  uint uVar10;
  int iVar11;
  X509_NAME *pXVar12;
  int *piVar13;
  int *piVar14;
  ASN1_INTEGER *pAVar15;
  int local_38;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    iVar1 = *(int *)(cms + 4);
    if (iVar1 != 0) {
      p_Var9 = *(_STACK **)(iVar1 + 0xc);
      local_38 = 0;
      iVar11 = 0;
      do {
        iVar2 = sk_num(*(_STACK **)(iVar1 + 0x14));
        if (iVar2 <= iVar11) {
          return local_38;
        }
        pvVar3 = sk_value(*(_STACK **)(iVar1 + 0x14),iVar11);
        iVar2 = *(int *)((int)pvVar3 + 0x1c);
        if (iVar2 == 0) {
          iVar4 = sk_num(&certs->stack);
          if (0 < iVar4) {
            do {
              pXVar5 = (X509 *)sk_value(&certs->stack,iVar2);
              piVar13 = *(int **)((int)pvVar3 + 4);
              if (*piVar13 == 0) {
                pXVar12 = *(X509_NAME **)piVar13[1];
                pXVar7 = X509_get_issuer_name(pXVar5);
                iVar4 = X509_NAME_cmp(pXVar12,pXVar7);
                if (iVar4 == 0) {
                  pAVar15 = *(ASN1_INTEGER **)(piVar13[1] + 4);
                  pAVar8 = X509_get_serialNumber(pXVar5);
                  iVar4 = ASN1_INTEGER_cmp(pAVar15,pAVar8);
joined_r0x000e532a:
                  if (iVar4 == 0) {
                    if (pXVar5 != (X509 *)0x0) {
                      CRYPTO_add_lock(&pXVar5->references,1,3,"cms_sd.c",0x1e2);
                      if (*(EVP_PKEY **)((int)pvVar3 + 0x20) != (EVP_PKEY *)0x0) {
                        EVP_PKEY_free(*(EVP_PKEY **)((int)pvVar3 + 0x20));
                      }
                      pEVar6 = X509_get_pubkey(pXVar5);
                      *(EVP_PKEY **)((int)pvVar3 + 0x20) = pEVar6;
                    }
                    if (*(X509 **)((int)pvVar3 + 0x1c) != (X509 *)0x0) {
                      X509_free(*(X509 **)((int)pvVar3 + 0x1c));
                    }
                    *(X509 **)((int)pvVar3 + 0x1c) = pXVar5;
                    local_38 = local_38 + 1;
                    if (pXVar5 != (X509 *)0x0) goto LAB_000e51e0;
                    goto LAB_000e5258;
                  }
                }
              }
              else if (*piVar13 == 1) {
                X509_check_purpose(pXVar5,-1,-1);
                if (pXVar5->skid != (ASN1_STRING *)0x0) {
                  iVar4 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)piVar13[1],pXVar5->skid);
                  goto joined_r0x000e532a;
                }
              }
              iVar2 = iVar2 + 1;
              iVar4 = sk_num(&certs->stack);
            } while (iVar2 < iVar4);
          }
          if (*(int *)((int)pvVar3 + 0x1c) == 0) {
LAB_000e5258:
            uVar10 = flags & 0x10;
            if ((flags & 0x10) == 0) {
              for (; iVar2 = sk_num(p_Var9), (int)uVar10 < iVar2; uVar10 = uVar10 + 1) {
                piVar13 = (int *)sk_value(p_Var9,uVar10);
                if (*piVar13 == 0) {
                  piVar14 = *(int **)((int)pvVar3 + 4);
                  pXVar5 = (X509 *)piVar13[1];
                  if (*piVar14 == 0) {
                    pXVar12 = *(X509_NAME **)piVar14[1];
                    pXVar7 = X509_get_issuer_name(pXVar5);
                    iVar2 = X509_NAME_cmp(pXVar12,pXVar7);
                    if (iVar2 == 0) {
                      pAVar15 = *(ASN1_INTEGER **)(piVar14[1] + 4);
                      pAVar8 = X509_get_serialNumber(pXVar5);
                      iVar2 = ASN1_INTEGER_cmp(pAVar15,pAVar8);
joined_r0x000e53d6:
                      if (iVar2 == 0) {
                        if (pXVar5 != (X509 *)0x0) {
                          CRYPTO_add_lock(&pXVar5->references,1,3,"cms_sd.c",0x1e2);
                          if (*(EVP_PKEY **)((int)pvVar3 + 0x20) != (EVP_PKEY *)0x0) {
                            EVP_PKEY_free(*(EVP_PKEY **)((int)pvVar3 + 0x20));
                          }
                          pEVar6 = X509_get_pubkey(pXVar5);
                          *(EVP_PKEY **)((int)pvVar3 + 0x20) = pEVar6;
                        }
                        if (*(X509 **)((int)pvVar3 + 0x1c) != (X509 *)0x0) {
                          X509_free(*(X509 **)((int)pvVar3 + 0x1c));
                        }
                        *(X509 **)((int)pvVar3 + 0x1c) = pXVar5;
                        local_38 = local_38 + 1;
                        break;
                      }
                    }
                  }
                  else if (*piVar14 == 1) {
                    X509_check_purpose(pXVar5,-1,-1);
                    if (pXVar5->skid != (ASN1_STRING *)0x0) {
                      iVar2 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)piVar14[1],pXVar5->skid);
                      goto joined_r0x000e53d6;
                    }
                  }
                }
              }
            }
          }
        }
LAB_000e51e0:
        iVar11 = iVar11 + 1;
      } while( true );
    }
  }
  else {
    ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  }
  return -1;
}

