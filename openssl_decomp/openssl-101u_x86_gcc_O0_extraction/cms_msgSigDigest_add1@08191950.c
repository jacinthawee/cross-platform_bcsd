
int cms_msgSigDigest_add1(CMS_SignerInfo *param_1,int param_2)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  int in_GS_OFFSET;
  uint local_54;
  uchar local_50 [64];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(param_2 + 8));
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type != (EVP_MD *)0x0) {
    iVar1 = ASN1_item_digest((ASN1_ITEM *)CMS_Attributes_Verify_it,type,*(void **)(param_2 + 0xc),
                             local_50,&local_54);
    if (iVar1 != 0) {
      iVar1 = CMS_signed_add1_attr_by_NID(param_1,0xd8,4,local_50,local_54);
      if (iVar1 == 0) {
        ERR_put_error(0x2e,0xa2,0x41,"cms_ess.c",0xd6);
      }
      else {
        iVar1 = 1;
      }
      goto LAB_081919fb;
    }
  }
  ERR_put_error(0x2e,0xa2,0xac,"cms_ess.c",0xd1);
  iVar1 = 0;
LAB_081919fb:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
