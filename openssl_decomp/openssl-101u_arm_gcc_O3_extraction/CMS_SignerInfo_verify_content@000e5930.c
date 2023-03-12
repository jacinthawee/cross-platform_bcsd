
int CMS_SignerInfo_verify_content(CMS_SignerInfo *si,BIO *chain)

{
  int iVar1;
  ASN1_OBJECT *oid;
  size_t *psVar2;
  int iVar3;
  int line;
  size_t local_78;
  EVP_MD_CTX EStack_74;
  uchar auStack_5c [64];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_74);
  iVar1 = CMS_signed_get_attr_count(si);
  if (iVar1 < 0) {
    iVar1 = cms_DigestAlgorithm_find_ctx(&EStack_74,chain,*(undefined4 *)(si + 8));
    if (iVar1 != 0) {
      iVar1 = EVP_VerifyFinal(&EStack_74,(uchar *)(*(uint **)(si + 0x14))[2],**(uint **)(si + 0x14),
                              *(EVP_PKEY **)(si + 0x20));
      if (0 < iVar1) goto LAB_000e59a6;
      line = 0x334;
LAB_000e59e0:
      iVar1 = 0;
      ERR_put_error(0x2e,0x9a,0x9e,"cms_sd.c",line);
      goto LAB_000e59a6;
    }
  }
  else {
    oid = OBJ_nid2obj(0x33);
    psVar2 = (size_t *)CMS_signed_get0_data_by_OBJ(si,oid,-3,4);
    if (psVar2 == (size_t *)0x0) {
      iVar1 = -1;
      ERR_put_error(0x2e,0x9a,0x72,"cms_sd.c",0x311);
      goto LAB_000e59a6;
    }
    iVar1 = cms_DigestAlgorithm_find_ctx(&EStack_74,chain,*(undefined4 *)(si + 8));
    if (iVar1 != 0) {
      iVar1 = EVP_DigestFinal_ex(&EStack_74,auStack_5c,&local_78);
      if (iVar1 < 1) {
        ERR_put_error(0x2e,0x9a,0x93,"cms_sd.c",800);
      }
      else {
        if (*psVar2 == local_78) {
          iVar3 = memcmp(auStack_5c,(void *)psVar2[2],*psVar2);
          iVar1 = 1;
          line = 0x32b;
          if (iVar3 == 0) goto LAB_000e59a6;
          goto LAB_000e59e0;
        }
        ERR_put_error(0x2e,0x9a,0x78,"cms_sd.c",0x325);
      }
    }
  }
  iVar1 = -1;
LAB_000e59a6:
  EVP_MD_CTX_cleanup(&EStack_74);
  if (local_1c == __stack_chk_guard) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

