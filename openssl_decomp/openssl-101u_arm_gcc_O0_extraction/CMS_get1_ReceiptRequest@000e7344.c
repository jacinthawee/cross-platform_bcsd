
undefined4 CMS_get1_ReceiptRequest(CMS_SignerInfo *param_1,ASN1_VALUE **param_2)

{
  ASN1_OBJECT *oid;
  ASN1_STRING *oct;
  ASN1_VALUE *val;
  
  if (param_2 != (ASN1_VALUE **)0x0) {
    *param_2 = (ASN1_VALUE *)0x0;
  }
  oid = OBJ_nid2obj(0xd4);
  oct = (ASN1_STRING *)CMS_signed_get0_data_by_OBJ(param_1,oid,-3,0x10);
  if (oct == (ASN1_STRING *)0x0) {
    return 0;
  }
  val = (ASN1_VALUE *)ASN1_item_unpack(oct,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  if (val == (ASN1_VALUE *)0x0) {
    return 0xffffffff;
  }
  if (param_2 != (ASN1_VALUE **)0x0) {
    *param_2 = val;
    return 1;
  }
  ASN1_item_free(val,(ASN1_ITEM *)CMS_ReceiptRequest_it);
  return 1;
}

