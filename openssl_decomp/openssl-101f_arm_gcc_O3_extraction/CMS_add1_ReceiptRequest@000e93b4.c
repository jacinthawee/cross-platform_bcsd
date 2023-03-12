
undefined4 CMS_add1_ReceiptRequest(CMS_SignerInfo *param_1,ASN1_VALUE *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uchar *local_14 [2];
  
  local_14[0] = (uchar *)0x0;
  iVar1 = ASN1_item_i2d(param_2,local_14,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  if (-1 < iVar1) {
    iVar1 = CMS_signed_add1_attr_by_NID(param_1,0xd4,0x10,local_14[0],iVar1);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_000e93fe;
    }
  }
  uVar2 = 0;
  ERR_put_error(0x2e,0x9e,0x41,"cms_ess.c",0x9d);
LAB_000e93fe:
  if (local_14[0] != (uchar *)0x0) {
    CRYPTO_free(local_14[0]);
  }
  return uVar2;
}

