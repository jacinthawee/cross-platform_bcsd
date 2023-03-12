
CMS_SignerInfo *
CMS_add1_signer(CMS_ContentInfo *cms,X509 *signer,EVP_PKEY *pk,EVP_MD *md,uint flags)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  _STACK *p_Var4;
  X509_ALGOR *pXVar5;
  undefined4 *si;
  void *bytes;
  char *name;
  uint uVar6;
  code *pcVar7;
  ASN1_OBJECT *pAVar8;
  int iVar9;
  int *piVar10;
  ASN1_OBJECT **ppAVar11;
  ASN1_OBJECT *local_30;
  ASN1_OBJECT *local_2c [2];
  
  iVar1 = X509_check_private_key(signer,pk);
  if (iVar1 == 0) {
    ERR_put_error(0x2e,0x66,0x88,"cms_sd.c",0x137);
    return (CMS_SignerInfo *)0x0;
  }
  if (*(int *)(cms + 4) == 0) {
    puVar2 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_SignedData_it);
    *(undefined4 **)(cms + 4) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      ERR_put_error(0x2e,0x95,0x41,"cms_sd.c",0x54);
      return (CMS_SignerInfo *)0x0;
    }
    *puVar2 = 1;
    ppAVar11 = (ASN1_OBJECT **)puVar2[2];
    pAVar8 = OBJ_nid2obj(0x15);
    *ppAVar11 = pAVar8;
    pAVar8 = *(ASN1_OBJECT **)cms;
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
    ASN1_OBJECT_free(pAVar8);
    pAVar8 = OBJ_nid2obj(0x16);
    piVar10 = *(int **)(cms + 4);
    *(ASN1_OBJECT **)cms = pAVar8;
  }
  else {
    iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar1 != 0x16) {
      ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
      return (CMS_SignerInfo *)0x0;
    }
    piVar10 = *(int **)(cms + 4);
  }
  if (piVar10 == (int *)0x0) {
    return (CMS_SignerInfo *)0x0;
  }
  puVar2 = (undefined4 *)ASN1_item_new((ASN1_ITEM *)CMS_SignerInfo_it);
  if (puVar2 == (undefined4 *)0x0) {
    ERR_put_error(0x2e,0x66,0x41,"cms_sd.c",0x1c6);
    return (CMS_SignerInfo *)0x0;
  }
  X509_check_purpose(signer,-1,-1);
  CRYPTO_add_lock(&pk->references,1,10,"cms_sd.c",0x142);
  CRYPTO_add_lock(&signer->references,1,3,"cms_sd.c",0x143);
  puVar2[8] = pk;
  uVar6 = flags & 0x10000;
  puVar2[7] = signer;
  if (uVar6 == 0) {
    *puVar2 = 1;
  }
  else {
    iVar1 = *piVar10;
    *puVar2 = 3;
    uVar6 = 1;
    if (iVar1 < 3) {
      *piVar10 = 3;
    }
  }
  iVar1 = cms_set1_SignerIdentifier(puVar2[1],signer,uVar6);
  if (iVar1 == 0) goto LAB_000e7eec;
  if (md == (EVP_MD *)0x0) {
    iVar1 = EVP_PKEY_get_default_digest_nid(pk,(int *)local_2c);
    if (iVar1 < 1) goto LAB_000e7eec;
    name = OBJ_nid2sn((int)local_2c[0]);
    md = EVP_get_digestbyname(name);
    if (md == (EVP_MD *)0x0) {
      ERR_put_error(0x2e,0x66,0x80,"cms_sd.c",0x160);
      goto LAB_000e7eec;
    }
  }
  cms_DigestAlgorithm_set(puVar2[2],md);
  for (iVar1 = 0; iVar3 = sk_num((_STACK *)piVar10[1]), iVar1 < iVar3; iVar1 = iVar1 + 1) {
    pXVar5 = (X509_ALGOR *)sk_value((_STACK *)piVar10[1],iVar1);
    X509_ALGOR_get0(local_2c,(int *)0x0,(void **)0x0,pXVar5);
    iVar3 = OBJ_obj2nid(local_2c[0]);
    iVar9 = EVP_MD_type(md);
    if (iVar3 == iVar9) break;
  }
  iVar3 = sk_num((_STACK *)piVar10[1]);
  if (iVar1 == iVar3) {
    pXVar5 = X509_ALGOR_new();
    if (pXVar5 != (X509_ALGOR *)0x0) {
      cms_DigestAlgorithm_set(pXVar5,md);
      iVar1 = sk_push((_STACK *)piVar10[1],pXVar5);
      if (iVar1 != 0) goto LAB_000e7e7c;
      X509_ALGOR_free(pXVar5);
    }
    goto LAB_000e7ed4;
  }
LAB_000e7e7c:
  if ((pk->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pcVar7 = *(code **)(pk->ameth + 0x58), pcVar7 != (code *)0x0)) {
    iVar1 = (*pcVar7)(pk,5,0,puVar2);
    if (iVar1 == -2) {
      ERR_put_error(0x2e,0x66,0x7d,"cms_sd.c",0x18b);
      goto LAB_000e7eec;
    }
    if (iVar1 < 1) {
      ERR_put_error(0x2e,0x66,0x6f,"cms_sd.c",400);
      goto LAB_000e7eec;
    }
  }
  if ((int)(flags << 0x17) < 0) {
LAB_000e7ebc:
    if (((int)(flags << 0x1e) < 0) || (iVar1 = CMS_add1_cert(cms,signer), iVar1 != 0)) {
      p_Var4 = (_STACK *)piVar10[5];
      if (p_Var4 == (_STACK *)0x0) {
        p_Var4 = sk_new_null();
        piVar10[5] = (int)p_Var4;
        if (p_Var4 == (_STACK *)0x0) goto LAB_000e7ed4;
      }
      iVar1 = sk_push(p_Var4,puVar2);
      if (iVar1 != 0) {
        return (CMS_SignerInfo *)puVar2;
      }
    }
  }
  else {
    if (puVar2[3] == 0) {
      p_Var4 = sk_new_null();
      puVar2[3] = p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_000e7ed4;
    }
    pAVar8 = (ASN1_OBJECT *)(flags & 0x200);
    if (pAVar8 != (ASN1_OBJECT *)0x0) {
LAB_000e7eb4:
      if ((int)(flags << 0x10) < 0) {
        iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
        if (iVar1 == 0x16) {
          p_Var4 = *(_STACK **)(cms + 4);
          if (p_Var4 != (_STACK *)0x0) {
            p_Var4 = (_STACK *)p_Var4[1].num;
          }
        }
        else {
          p_Var4 = (_STACK *)0x0;
          ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
        }
        iVar1 = 0;
        do {
          iVar3 = sk_num(p_Var4);
          iVar9 = iVar1 + 1;
          if (iVar3 <= iVar1) {
            ERR_put_error(0x2e,0x6c,0x83,"cms_sd.c",0xce);
            goto LAB_000e7eec;
          }
          si = (undefined4 *)sk_value(p_Var4,iVar1);
          iVar1 = iVar9;
        } while (((puVar2 == si) ||
                 (iVar3 = CMS_signed_get_attr_count((CMS_SignerInfo *)si), iVar3 < 0)) ||
                (iVar3 = OBJ_cmp(*(ASN1_OBJECT **)puVar2[2],*(ASN1_OBJECT **)si[2]), iVar3 != 0));
        pAVar8 = OBJ_nid2obj(0x33);
        bytes = CMS_signed_get0_data_by_OBJ((CMS_SignerInfo *)si,pAVar8,-3,4);
        if (bytes == (void *)0x0) {
          ERR_put_error(0x2e,0x6c,0x72,"cms_sd.c",0xc3);
          goto LAB_000e7eec;
        }
        iVar1 = CMS_signed_add1_attr_by_NID((CMS_SignerInfo *)puVar2,0x33,4,bytes,-1);
        if ((iVar1 == 0) ||
           ((-1 < (int)(flags << 0x11) &&
            (iVar1 = CMS_SignerInfo_sign((CMS_SignerInfo *)puVar2), iVar1 == 0))))
        goto LAB_000e7eec;
      }
      goto LAB_000e7ebc;
    }
    local_30 = pAVar8;
    iVar1 = CMS_add_standard_smimecap((stack_st_X509_ALGOR **)&local_30);
    if ((iVar1 == 0) ||
       (local_2c[0] = pAVar8, iVar1 = i2d_X509_ALGORS((X509_ALGORS *)local_30,(uchar **)local_2c),
       iVar1 < 1)) {
      sk_pop_free((_STACK *)local_30,X509_ALGOR_free);
    }
    else {
      iVar1 = CMS_signed_add1_attr_by_NID((CMS_SignerInfo *)puVar2,0xa7,0x10,local_2c[0],iVar1);
      CRYPTO_free(local_2c[0]);
      sk_pop_free((_STACK *)local_30,X509_ALGOR_free);
      if (iVar1 != 0) goto LAB_000e7eb4;
    }
  }
LAB_000e7ed4:
  ERR_put_error(0x2e,0x66,0x41,"cms_sd.c",0x1c6);
LAB_000e7eec:
  ASN1_item_free((ASN1_VALUE *)puVar2,(ASN1_ITEM *)CMS_SignerInfo_it);
  return (CMS_SignerInfo *)0x0;
}

