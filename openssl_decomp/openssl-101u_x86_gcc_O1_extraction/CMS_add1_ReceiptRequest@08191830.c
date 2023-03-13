
undefined4 CMS_add1_ReceiptRequest(CMS_SignerInfo *param_1,ASN1_VALUE *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (uchar *)0x0;
  iVar1 = ASN1_item_i2d(param_2,&local_14,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  if (-1 < iVar1) {
    iVar1 = CMS_signed_add1_attr_by_NID(param_1,0xd4,0x10,local_14,iVar1);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_081918a2;
    }
  }
  uVar2 = 0;
  ERR_put_error(0x2e,0x9e,0x41,"cms_ess.c",0x9b);
LAB_081918a2:
  if (local_14 != (uchar *)0x0) {
    CRYPTO_free(local_14);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

