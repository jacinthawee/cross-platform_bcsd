
void cms_msgSigDigest_add1(CMS_SignerInfo *param_1,int param_2)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  uint local_58;
  uchar auStack_54 [64];
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(param_2 + 8));
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type != (EVP_MD *)0x0) {
    iVar1 = ASN1_item_digest((ASN1_ITEM *)CMS_Attributes_Verify_it,type,*(void **)(param_2 + 0xc),
                             auStack_54,&local_58);
    if (iVar1 != 0) {
      iVar1 = CMS_signed_add1_attr_by_NID(param_1,0xd8,4,auStack_54,local_58);
      if (iVar1 == 0) {
        ERR_put_error(0x2e,0xa2,0x41,"cms_ess.c",0xd6);
      }
      else {
        iVar1 = 1;
      }
      goto LAB_000e7552;
    }
  }
  iVar1 = 0;
  ERR_put_error(0x2e,0xa2,0xac,"cms_ess.c",0xd1);
LAB_000e7552:
  if (local_14 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar1);
}

