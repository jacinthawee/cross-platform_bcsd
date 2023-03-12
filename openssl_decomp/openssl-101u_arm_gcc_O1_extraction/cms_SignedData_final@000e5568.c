
void cms_SignedData_final(ASN1_OBJECT **param_1,undefined4 param_2)

{
  int iVar1;
  CMS_SignerInfo *si;
  uchar *md;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  void *bytes;
  uint local_88;
  EVP_MD_CTX EStack_84;
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar1 = OBJ_obj2nid(*param_1);
  if (iVar1 == 0x16) {
    pAVar3 = param_1[1];
    if (pAVar3 != (ASN1_OBJECT *)0x0) {
      pAVar3 = (ASN1_OBJECT *)pAVar3->flags;
    }
  }
  else {
    pAVar3 = (ASN1_OBJECT *)0x0;
    ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  }
  iVar2 = 0;
  iVar1 = sk_num((_STACK *)pAVar3);
  if (0 < iVar1) {
    do {
      si = (CMS_SignerInfo *)sk_value((_STACK *)pAVar3,iVar2);
      EVP_MD_CTX_init(&EStack_84);
      iVar1 = *(int *)(si + 0x20);
      if (iVar1 == 0) {
        ERR_put_error(0x2e,0x96,0x85,"cms_sd.c",0x23c);
        goto LAB_000e55ca;
      }
      iVar1 = cms_DigestAlgorithm_find_ctx(&EStack_84,param_2,*(undefined4 *)(si + 8));
      if (iVar1 == 0) {
LAB_000e55c2:
        EVP_MD_CTX_cleanup(&EStack_84);
        iVar1 = 0;
        goto LAB_000e55ca;
      }
      iVar1 = CMS_signed_get_attr_count(si);
      if (iVar1 < 0) {
        iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(si + 0x20));
        md = (uchar *)CRYPTO_malloc(iVar1,"cms_sd.c",0x25a);
        if (md == (uchar *)0x0) {
          ERR_put_error(0x2e,0x96,0x41,"cms_sd.c",0x25c);
        }
        else {
          iVar1 = EVP_SignFinal(&EStack_84,md,&local_88,*(EVP_PKEY **)(si + 0x20));
          if (iVar1 != 0) {
            ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),md,local_88);
            goto LAB_000e5682;
          }
          ERR_put_error(0x2e,0x96,0x8b,"cms_sd.c",0x260);
          CRYPTO_free(md);
        }
        goto LAB_000e55c2;
      }
      bytes = *(void **)param_1[1]->nid;
      iVar1 = EVP_DigestFinal_ex(&EStack_84,auStack_6c,&local_88);
      if ((((iVar1 == 0) ||
           (iVar1 = CMS_signed_add1_attr_by_NID(si,0x33,4,auStack_6c,local_88), iVar1 == 0)) ||
          (iVar1 = CMS_signed_add1_attr_by_NID(si,0x32,6,bytes,-1), iVar1 < 1)) ||
         (iVar1 = CMS_SignerInfo_sign(si), iVar1 == 0)) goto LAB_000e55c2;
LAB_000e5682:
      iVar2 = iVar2 + 1;
      EVP_MD_CTX_cleanup(&EStack_84);
      iVar1 = sk_num((_STACK *)pAVar3);
    } while (iVar2 < iVar1);
  }
  iVar1 = 1;
  *(undefined4 *)(param_1[1]->nid + 8) = 0;
LAB_000e55ca:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}

