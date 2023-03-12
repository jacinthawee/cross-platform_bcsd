
ASN1_STRING * cms_encode_Receipt(CMS_SignerInfo *param_1)

{
  ASN1_OBJECT *pAVar1;
  ASN1_STRING *pAVar2;
  undefined4 *val;
  void *pvVar3;
  int in_GS_OFFSET;
  undefined4 local_20;
  void *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pAVar1 = OBJ_nid2obj(0xd4);
  pAVar2 = (ASN1_STRING *)CMS_signed_get0_data_by_OBJ(param_1,pAVar1,-3,0x10);
  if (pAVar2 != (ASN1_STRING *)0x0) {
    val = (undefined4 *)ASN1_item_unpack(pAVar2,(ASN1_ITEM *)CMS_ReceiptRequest_it);
    if (val != (undefined4 *)0x0) {
      pAVar1 = OBJ_nid2obj(0x32);
      pvVar3 = CMS_signed_get0_data_by_OBJ(param_1,pAVar1,-3,6);
      if (pvVar3 == (void *)0x0) {
        pAVar2 = (ASN1_STRING *)0x0;
        ERR_put_error(0x2e,0xa1,0xad,"cms_ess.c",0x191);
      }
      else {
        local_18 = *val;
        local_20 = 1;
        local_14 = *(undefined4 *)(param_1 + 0x14);
        local_1c = pvVar3;
        pAVar2 = ASN1_item_pack(&local_20,(ASN1_ITEM *)CMS_Receipt_it,(ASN1_OCTET_STRING **)0x0);
      }
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_ReceiptRequest_it);
      goto LAB_081936ef;
    }
  }
  pAVar2 = (ASN1_STRING *)0x0;
  ERR_put_error(0x2e,0xa1,0xa8,"cms_ess.c",0x186);
LAB_081936ef:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

