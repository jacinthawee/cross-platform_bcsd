
ASN1_STRING **
CMS_ReceiptRequest_create0(void *param_1,int param_2,int param_3,int param_4,ASN1_STRING *param_5)

{
  ASN1_STRING *pAVar1;
  ASN1_STRING **val;
  int iVar2;
  
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)CMS_ReceiptRequest_it);
  if (val == (ASN1_STRING **)0x0) {
    ERR_put_error(0x2e,0x9f,0x41,"cms_ess.c",0x82);
  }
  else {
    if (param_1 == (void *)0x0) {
      iVar2 = ASN1_STRING_set(*val,(void *)0x0,0x20);
      if (iVar2 == 0) {
        ERR_put_error(0x2e,0x9f,0x41,"cms_ess.c",0x82);
LAB_08192fa3:
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_ReceiptRequest_it);
        return (ASN1_STRING **)0x0;
      }
      iVar2 = RAND_pseudo_bytes((*val)->data,0x20);
      if (iVar2 < 1) goto LAB_08192fa3;
    }
    else {
      ASN1_STRING_set0(*val,param_1,param_2);
    }
    sk_pop_free((_STACK *)val[2],GENERAL_NAMES_free);
    val[2] = param_5;
    pAVar1 = val[1];
    if (param_4 == 0) {
      pAVar1->length = 0;
      pAVar1->type = param_3;
      return val;
    }
    pAVar1->length = 1;
    pAVar1->type = param_4;
  }
  return val;
}
