
undefined4 cms_SignedData_final(ASN1_OBJECT **param_1,undefined4 param_2)

{
  void *bytes;
  int iVar1;
  CMS_SignerInfo *si;
  int iVar2;
  undefined4 uVar3;
  uchar *md;
  _STACK *p_Var4;
  int in_GS_OFFSET;
  uint local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = OBJ_obj2nid(*param_1);
  if (iVar1 == 0x16) {
    if (param_1[1] == (ASN1_OBJECT *)0x0) {
      p_Var4 = (_STACK *)0x0;
    }
    else {
      p_Var4 = (_STACK *)param_1[1]->flags;
    }
  }
  else {
    p_Var4 = (_STACK *)0x0;
    ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  }
  iVar1 = sk_num(p_Var4);
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      si = (CMS_SignerInfo *)sk_value(p_Var4,iVar1);
      EVP_MD_CTX_init(&local_78);
      if (*(int *)(si + 0x20) == 0) {
        ERR_put_error(0x2e,0x96,0x85,"cms_sd.c",0x23c);
        uVar3 = 0;
        goto LAB_0818e537;
      }
      iVar2 = cms_DigestAlgorithm_find_ctx(&local_78,param_2,*(undefined4 *)(si + 8));
      if (iVar2 == 0) {
LAB_0818e529:
        EVP_MD_CTX_cleanup(&local_78);
        uVar3 = 0;
        goto LAB_0818e537;
      }
      iVar2 = CMS_signed_get_attr_count(si);
      if (iVar2 < 0) {
        iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(si + 0x20));
        md = (uchar *)CRYPTO_malloc(iVar2,"cms_sd.c",0x25a);
        if (md == (uchar *)0x0) {
          ERR_put_error(0x2e,0x96,0x41,"cms_sd.c",0x25c);
        }
        else {
          iVar2 = EVP_SignFinal(&local_78,md,&local_7c,*(EVP_PKEY **)(si + 0x20));
          if (iVar2 != 0) {
            ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),md,local_7c);
            goto LAB_0818e67c;
          }
          ERR_put_error(0x2e,0x96,0x8b,"cms_sd.c",0x260);
          CRYPTO_free(md);
        }
        goto LAB_0818e529;
      }
      bytes = *(void **)param_1[1]->nid;
      iVar2 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
      if ((((iVar2 == 0) ||
           (iVar2 = CMS_signed_add1_attr_by_NID(si,0x33,4,local_60,local_7c), iVar2 == 0)) ||
          (iVar2 = CMS_signed_add1_attr_by_NID(si,0x32,6,bytes,-1), iVar2 < 1)) ||
         (iVar2 = CMS_SignerInfo_sign(si), iVar2 == 0)) goto LAB_0818e529;
LAB_0818e67c:
      iVar1 = iVar1 + 1;
      EVP_MD_CTX_cleanup(&local_78);
      iVar2 = sk_num(p_Var4);
    } while (iVar1 < iVar2);
  }
  *(undefined4 *)(param_1[1]->nid + 8) = 0;
  uVar3 = 1;
LAB_0818e537:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

