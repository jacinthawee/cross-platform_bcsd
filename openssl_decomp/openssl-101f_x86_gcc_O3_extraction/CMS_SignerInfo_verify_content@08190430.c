
int CMS_SignerInfo_verify_content(CMS_SignerInfo *si,BIO *chain)

{
  int iVar1;
  ASN1_OBJECT *oid;
  size_t *psVar2;
  int iVar3;
  int in_GS_OFFSET;
  size_t local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_78);
  iVar1 = CMS_signed_get_attr_count(si);
  if (iVar1 < 0) {
    iVar1 = cms_DigestAlgorithm_find_ctx(&local_78,chain,*(undefined4 *)(si + 8));
    if (iVar1 != 0) {
      iVar1 = EVP_VerifyFinal(&local_78,(uchar *)(*(uint **)(si + 0x14))[2],**(uint **)(si + 0x14),
                              *(EVP_PKEY **)(si + 0x20));
      if (0 < iVar1) goto LAB_081904ea;
      iVar3 = 900;
LAB_08190520:
      iVar1 = 0;
      ERR_put_error(0x2e,0x9a,0x9e,"cms_sd.c",iVar3);
      goto LAB_081904ea;
    }
  }
  else {
    oid = OBJ_nid2obj(0x33);
    psVar2 = (size_t *)CMS_signed_get0_data_by_OBJ(si,oid,-3,4);
    if (psVar2 == (size_t *)0x0) {
      iVar1 = -1;
      ERR_put_error(0x2e,0x9a,0x72,"cms_sd.c",0x359);
      goto LAB_081904ea;
    }
    iVar1 = cms_DigestAlgorithm_find_ctx(&local_78,chain,*(undefined4 *)(si + 8));
    if (iVar1 != 0) {
      iVar1 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
      if (iVar1 < 1) {
        ERR_put_error(0x2e,0x9a,0x93,"cms_sd.c",0x36a);
      }
      else {
        if (*psVar2 == local_7c) {
          iVar1 = 1;
          iVar3 = memcmp(local_60,(void *)psVar2[2],*psVar2);
          if (iVar3 == 0) goto LAB_081904ea;
          iVar3 = 0x377;
          goto LAB_08190520;
        }
        ERR_put_error(0x2e,0x9a,0x78,"cms_sd.c",0x370);
      }
    }
  }
  iVar1 = -1;
LAB_081904ea:
  EVP_MD_CTX_cleanup(&local_78);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

