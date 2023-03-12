
ASN1_STRING **
CMS_ReceiptRequest_create0(void *param_1,int param_2,int param_3,int param_4,ASN1_STRING *param_5)

{
  ASN1_STRING **val;
  int iVar1;
  ASN1_STRING *pAVar2;
  
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)CMS_ReceiptRequest_it);
  if (val == (ASN1_STRING **)0x0) {
    ERR_put_error(0x2e,0x9f,0x41,"cms_ess.c",0x80);
  }
  else {
    if (param_1 == (void *)0x0) {
      iVar1 = ASN1_STRING_set(*val,(void *)0x0,0x20);
      if (iVar1 == 0) {
        ERR_put_error(0x2e,0x9f,0x41,"cms_ess.c",0x80);
LAB_000e7404:
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)CMS_ReceiptRequest_it);
        return (ASN1_STRING **)0x0;
      }
      iVar1 = RAND_bytes((*val)->data,0x20);
      if (iVar1 < 1) goto LAB_000e7404;
    }
    else {
      ASN1_STRING_set0(*val,param_1,param_2);
    }
    sk_pop_free((_STACK *)val[2],GENERAL_NAMES_free + 1);
    val[2] = param_5;
    pAVar2 = val[1];
    if (param_4 == 0) {
      pAVar2->length = 0;
      pAVar2->type = param_3;
      return val;
    }
    pAVar2->length = 1;
    pAVar2->type = param_4;
  }
  return val;
}

