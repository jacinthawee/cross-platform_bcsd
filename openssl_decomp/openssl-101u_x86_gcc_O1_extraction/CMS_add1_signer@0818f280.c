
CMS_SignerInfo *
CMS_add1_signer(CMS_ContentInfo *cms,X509 *signer,EVP_PKEY *pk,EVP_MD *md,uint flags)

{
  code *pcVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  X509_ALGOR *pXVar8;
  undefined4 *si;
  ASN1_OBJECT *pAVar9;
  void *bytes;
  char *name;
  _STACK *p_Var10;
  int *piVar11;
  int in_GS_OFFSET;
  EVP_MD *local_34;
  _STACK *local_28;
  ASN1_OBJECT *local_24;
  int local_20;
  
  local_34 = md;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar3 = X509_check_private_key(signer,pk);
  if (iVar3 == 0) {
    ERR_put_error(0x2e,0x66,0x88,"cms_sd.c",0x11d);
    puVar4 = (undefined4 *)0x0;
    goto LAB_0818f4e7;
  }
  if (*(int *)(cms + 4) == 0) {
    puVar4 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_SignedData_it);
    *(undefined4 **)(cms + 4) = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      ppAVar2 = (ASN1_OBJECT **)puVar4[2];
      *puVar4 = 1;
      pAVar9 = OBJ_nid2obj(0x15);
      *ppAVar2 = pAVar9;
      *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
      ASN1_OBJECT_free(*(ASN1_OBJECT **)cms);
      pAVar9 = OBJ_nid2obj(0x16);
      *(ASN1_OBJECT **)cms = pAVar9;
      piVar11 = *(int **)(cms + 4);
      goto LAB_0818f2f6;
    }
    ERR_put_error(0x2e,0x95,0x41,"cms_sd.c",0x52);
  }
  else {
    iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar3 == 0x16) {
      piVar11 = *(int **)(cms + 4);
LAB_0818f2f6:
      if (piVar11 != (int *)0x0) {
        puVar4 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_SignerInfo_it);
        if (puVar4 == (undefined4 *)0x0) {
          ERR_put_error(0x2e,0x66,0x41,"cms_sd.c",0x198);
        }
        else {
          X509_check_purpose(signer,-1,-1);
          CRYPTO_add_lock(&pk->references,1,10,"cms_sd.c",0x128);
          CRYPTO_add_lock(&signer->references,1,3,"cms_sd.c",0x129);
          puVar4[8] = pk;
          puVar4[7] = signer;
          if ((flags & 0x10000) == 0) {
            *puVar4 = 1;
            uVar5 = 0;
          }
          else {
            iVar3 = *piVar11;
            *puVar4 = 3;
            uVar5 = 1;
            if (iVar3 < 3) {
              *piVar11 = 3;
            }
          }
          iVar3 = cms_set1_SignerIdentifier(puVar4[1],signer,uVar5);
          if (iVar3 != 0) {
            if (md == (EVP_MD *)0x0) {
              iVar3 = EVP_PKEY_get_default_digest_nid(pk,(int *)&local_24);
              if (0 < iVar3) {
                name = OBJ_nid2sn((int)local_24);
                local_34 = EVP_get_digestbyname(name);
                if (local_34 != (EVP_MD *)0x0) goto LAB_0818f3aa;
                ERR_put_error(0x2e,0x66,0x80,"cms_sd.c",0x141);
              }
            }
            else {
LAB_0818f3aa:
              cms_DigestAlgorithm_set(puVar4[2],local_34);
              for (iVar3 = 0; iVar7 = sk_num((_STACK *)piVar11[1]), iVar3 < iVar7; iVar3 = iVar3 + 1
                  ) {
                pXVar8 = (X509_ALGOR *)sk_value((_STACK *)piVar11[1],iVar3);
                X509_ALGOR_get0(&local_24,(int *)0x0,(void **)0x0,pXVar8);
                iVar7 = OBJ_obj2nid(local_24);
                iVar6 = EVP_MD_type(local_34);
                if (iVar7 == iVar6) break;
              }
              iVar7 = sk_num((_STACK *)piVar11[1]);
              if (iVar3 == iVar7) {
                pXVar8 = X509_ALGOR_new();
                if (pXVar8 != (X509_ALGOR *)0x0) {
                  cms_DigestAlgorithm_set(pXVar8,local_34);
                  iVar3 = sk_push((_STACK *)piVar11[1],pXVar8);
                  if (iVar3 != 0) goto LAB_0818f42f;
                  X509_ALGOR_free(pXVar8);
                }
              }
              else {
LAB_0818f42f:
                if ((pk->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
                   (pcVar1 = *(code **)(pk->ameth + 0x58), pcVar1 != (code *)0x0)) {
                  iVar3 = (*pcVar1)(pk,5,0,puVar4);
                  if (iVar3 == -2) {
                    ERR_put_error(0x2e,0x66,0x7d,"cms_sd.c",0x165);
                  }
                  else {
                    if (0 < iVar3) goto LAB_0818f45d;
                    ERR_put_error(0x2e,0x66,0x6f,"cms_sd.c",0x169);
                  }
                  goto LAB_0818f4d4;
                }
LAB_0818f45d:
                if ((flags & 0x100) == 0) {
                  if (puVar4[3] == 0) {
                    p_Var10 = sk_new_null();
                    puVar4[3] = p_Var10;
                    if (p_Var10 == (_STACK *)0x0) goto LAB_0818f4b9;
                  }
                  if ((flags & 0x200) == 0) {
                    local_28 = (_STACK *)0x0;
                    iVar3 = CMS_add_standard_smimecap((stack_st_X509_ALGOR **)&local_28);
                    if (iVar3 != 0) {
                      local_24 = (ASN1_OBJECT *)0x0;
                      iVar3 = i2d_X509_ALGORS((X509_ALGORS *)local_28,(uchar **)&local_24);
                      if (0 < iVar3) {
                        iVar3 = CMS_signed_add1_attr_by_NID
                                          ((CMS_SignerInfo *)puVar4,0xa7,0x10,local_24,iVar3);
                        CRYPTO_free(local_24);
                        sk_pop_free(local_28,X509_ALGOR_free);
                        if (iVar3 == 0) goto LAB_0818f4b9;
                        goto LAB_0818f480;
                      }
                    }
                    sk_pop_free(local_28,X509_ALGOR_free);
                    goto LAB_0818f4b9;
                  }
LAB_0818f480:
                  if ((flags & 0x8000) != 0) {
                    iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
                    if (iVar3 == 0x16) {
                      if (*(int *)(cms + 4) == 0) {
                        p_Var10 = (_STACK *)0x0;
                      }
                      else {
                        p_Var10 = *(_STACK **)(*(int *)(cms + 4) + 0x14);
                      }
                    }
                    else {
                      ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
                      p_Var10 = (_STACK *)0x0;
                    }
                    for (iVar3 = 0; iVar7 = sk_num(p_Var10), iVar3 < iVar7; iVar3 = iVar3 + 1) {
                      si = (undefined4 *)sk_value(p_Var10,iVar3);
                      if (((puVar4 != si) &&
                          (iVar7 = CMS_signed_get_attr_count((CMS_SignerInfo *)si), -1 < iVar7)) &&
                         (iVar7 = OBJ_cmp(*(ASN1_OBJECT **)puVar4[2],*(ASN1_OBJECT **)si[2]),
                         iVar7 == 0)) {
                        pAVar9 = OBJ_nid2obj(0x33);
                        bytes = CMS_signed_get0_data_by_OBJ((CMS_SignerInfo *)si,pAVar9,-3,4);
                        if (bytes == (void *)0x0) {
                          ERR_put_error(0x2e,0x6c,0x72,"cms_sd.c",0xb5);
                          goto LAB_0818f4d4;
                        }
                        iVar3 = CMS_signed_add1_attr_by_NID
                                          ((CMS_SignerInfo *)puVar4,0x33,4,bytes,-1);
                        if ((iVar3 == 0) ||
                           (((flags & 0x4000) == 0 &&
                            (iVar3 = CMS_SignerInfo_sign((CMS_SignerInfo *)puVar4), iVar3 == 0))))
                        goto LAB_0818f4d4;
                        goto LAB_0818f48e;
                      }
                    }
                    ERR_put_error(0x2e,0x6c,0x83,"cms_sd.c",0xc0);
                    goto LAB_0818f4d4;
                  }
                }
LAB_0818f48e:
                if (((flags & 2) != 0) || (iVar3 = CMS_add1_cert(cms,signer), iVar3 != 0)) {
                  p_Var10 = (_STACK *)piVar11[5];
                  if (p_Var10 == (_STACK *)0x0) {
                    p_Var10 = sk_new_null();
                    piVar11[5] = (int)p_Var10;
                    if (p_Var10 == (_STACK *)0x0) goto LAB_0818f4b9;
                  }
                  iVar3 = sk_push(p_Var10,puVar4);
                  if (iVar3 != 0) goto LAB_0818f4e7;
                }
              }
LAB_0818f4b9:
              ERR_put_error(0x2e,0x66,0x41,"cms_sd.c",0x198);
            }
          }
LAB_0818f4d4:
          ASN1_item_free((ASN1_VALUE *)puVar4,(ASN1_ITEM *)CMS_SignerInfo_it);
        }
      }
    }
    else {
      ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
    }
  }
  puVar4 = (undefined4 *)0x0;
LAB_0818f4e7:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (CMS_SignerInfo *)puVar4;
}

