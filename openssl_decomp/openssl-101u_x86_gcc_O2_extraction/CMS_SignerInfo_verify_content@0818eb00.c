
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
      if (0 < iVar1) goto LAB_0818ebba;
      iVar3 = 0x334;
LAB_0818ebf0:
      iVar1 = 0;
      ERR_put_error(0x2e,0x9a,0x9e,"cms_sd.c",iVar3);
      goto LAB_0818ebba;
    }
  }
  else {
    oid = OBJ_nid2obj(0x33);
    psVar2 = (size_t *)CMS_signed_get0_data_by_OBJ(si,oid,-3,4);
    if (psVar2 == (size_t *)0x0) {
      iVar1 = -1;
      ERR_put_error(0x2e,0x9a,0x72,"cms_sd.c",0x311);
      goto LAB_0818ebba;
    }
    iVar1 = cms_DigestAlgorithm_find_ctx(&local_78,chain,*(undefined4 *)(si + 8));
    if (iVar1 != 0) {
      iVar1 = EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
      if (iVar1 < 1) {
        ERR_put_error(0x2e,0x9a,0x93,"cms_sd.c",800);
      }
      else {
        if (*psVar2 == local_7c) {
          iVar1 = 1;
          iVar3 = memcmp(local_60,(void *)psVar2[2],*psVar2);
          if (iVar3 == 0) goto LAB_0818ebba;
          iVar3 = 0x32b;
          goto LAB_0818ebf0;
        }
        ERR_put_error(0x2e,0x9a,0x78,"cms_sd.c",0x325);
      }
    }
  }
  iVar1 = -1;
LAB_0818ebba:
  EVP_MD_CTX_cleanup(&local_78);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

