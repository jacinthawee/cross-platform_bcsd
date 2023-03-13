
int CMS_set1_signers_certs(CMS_ContentInfo *cms,stack_st_X509 *certs,uint flags)

{
  _STACK *p_Var1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  X509 *pXVar6;
  X509_NAME *pXVar7;
  ASN1_INTEGER *pAVar8;
  EVP_PKEY *pEVar9;
  int *piVar10;
  int local_34;
  int local_28;
  
  iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar2 != 0x16) {
    ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
    return -1;
  }
  iVar2 = *(int *)(cms + 4);
  if (iVar2 == 0) {
    local_28 = -1;
  }
  else {
    p_Var1 = *(_STACK **)(iVar2 + 0xc);
    local_28 = 0;
    for (local_34 = 0; iVar3 = sk_num(*(_STACK **)(iVar2 + 0x14)), local_34 < iVar3;
        local_34 = local_34 + 1) {
      pvVar4 = sk_value(*(_STACK **)(iVar2 + 0x14),local_34);
      if (*(int *)((int)pvVar4 + 0x1c) == 0) {
        for (iVar3 = 0; iVar5 = sk_num(&certs->stack), iVar3 < iVar5; iVar3 = iVar3 + 1) {
          pXVar6 = (X509 *)sk_value(&certs->stack,iVar3);
          piVar10 = *(int **)((int)pvVar4 + 4);
          if (*piVar10 == 0) {
            pXVar7 = X509_get_issuer_name(pXVar6);
            iVar5 = X509_NAME_cmp(*(X509_NAME **)piVar10[1],pXVar7);
            if (iVar5 == 0) {
              pAVar8 = X509_get_serialNumber(pXVar6);
              iVar5 = ASN1_INTEGER_cmp(*(ASN1_INTEGER **)(piVar10[1] + 4),pAVar8);
joined_r0x0818df55:
              if (iVar5 == 0) {
                if (pXVar6 != (X509 *)0x0) {
                  CRYPTO_add_lock(&pXVar6->references,1,3,"cms_sd.c",0x1e2);
                  if (*(EVP_PKEY **)((int)pvVar4 + 0x20) != (EVP_PKEY *)0x0) {
                    EVP_PKEY_free(*(EVP_PKEY **)((int)pvVar4 + 0x20));
                  }
                  pEVar9 = X509_get_pubkey(pXVar6);
                  *(EVP_PKEY **)((int)pvVar4 + 0x20) = pEVar9;
                }
                if (*(X509 **)((int)pvVar4 + 0x1c) != (X509 *)0x0) {
                  X509_free(*(X509 **)((int)pvVar4 + 0x1c));
                }
                local_28 = local_28 + 1;
                *(X509 **)((int)pvVar4 + 0x1c) = pXVar6;
                if ((pXVar6 != (X509 *)0x0) || ((flags & 0x10) != 0)) goto LAB_0818ded8;
                goto LAB_0818e03e;
              }
            }
          }
          else if (*piVar10 == 1) {
            X509_check_purpose(pXVar6,-1,-1);
            if (pXVar6->skid != (ASN1_STRING *)0x0) {
              iVar5 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)piVar10[1],pXVar6->skid);
              goto joined_r0x0818df55;
            }
          }
        }
        if ((*(int *)((int)pvVar4 + 0x1c) == 0) && ((flags & 0x10) == 0)) {
LAB_0818e03e:
          for (iVar3 = 0; iVar5 = sk_num(p_Var1), iVar3 < iVar5; iVar3 = iVar3 + 1) {
            piVar10 = (int *)sk_value(p_Var1,iVar3);
            if (*piVar10 == 0) {
              pXVar6 = (X509 *)piVar10[1];
              piVar10 = *(int **)((int)pvVar4 + 4);
              if (*piVar10 == 0) {
                pXVar7 = X509_get_issuer_name(pXVar6);
                iVar5 = X509_NAME_cmp(*(X509_NAME **)piVar10[1],pXVar7);
                if (iVar5 == 0) {
                  pAVar8 = X509_get_serialNumber(pXVar6);
                  iVar5 = ASN1_INTEGER_cmp(*(ASN1_INTEGER **)(piVar10[1] + 4),pAVar8);
LAB_0818e0b9:
                  if (iVar5 == 0) {
                    if (pXVar6 != (X509 *)0x0) {
                      CRYPTO_add_lock(&pXVar6->references,1,3,"cms_sd.c",0x1e2);
                      if (*(EVP_PKEY **)((int)pvVar4 + 0x20) != (EVP_PKEY *)0x0) {
                        EVP_PKEY_free(*(EVP_PKEY **)((int)pvVar4 + 0x20));
                      }
                      pEVar9 = X509_get_pubkey(pXVar6);
                      *(EVP_PKEY **)((int)pvVar4 + 0x20) = pEVar9;
                    }
                    if (*(X509 **)((int)pvVar4 + 0x1c) != (X509 *)0x0) {
                      X509_free(*(X509 **)((int)pvVar4 + 0x1c));
                    }
                    *(X509 **)((int)pvVar4 + 0x1c) = pXVar6;
                    local_28 = local_28 + 1;
                    break;
                  }
                }
              }
              else if (*piVar10 == 1) {
                X509_check_purpose(pXVar6,-1,-1);
                if (pXVar6->skid != (ASN1_STRING *)0x0) {
                  iVar5 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)piVar10[1],pXVar6->skid);
                  goto LAB_0818e0b9;
                }
              }
            }
          }
        }
      }
LAB_0818ded8:
    }
  }
  return local_28;
}

