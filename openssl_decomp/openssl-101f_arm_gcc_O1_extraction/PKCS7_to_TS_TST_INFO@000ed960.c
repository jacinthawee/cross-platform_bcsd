
ASN1_VALUE * PKCS7_to_TS_TST_INFO(PKCS7 *param_1)

{
  int iVar1;
  long lVar2;
  ASN1_VALUE *pAVar3;
  stack_st_X509_ALGOR *psVar4;
  PKCS7_SIGNED *pPVar5;
  pkcs7_st *ppVar6;
  uchar *local_14 [2];
  
  iVar1 = OBJ_obj2nid(param_1->type);
  if (iVar1 != 0x16) {
    iVar1 = 0x121;
LAB_000ed9c2:
    ERR_put_error(0x2f,0x94,0x84,"ts_asn1.c",iVar1);
    return (ASN1_VALUE *)0x0;
  }
  lVar2 = PKCS7_ctrl(param_1,2,0,(char *)0x0);
  if (lVar2 == 0) {
    ppVar6 = ((param_1->d).sign)->contents;
    iVar1 = OBJ_obj2nid(ppVar6->type);
    if (iVar1 != 0xcf) {
      iVar1 = 0x131;
      goto LAB_000ed9c2;
    }
    pPVar5 = (ppVar6->d).sign;
    if (pPVar5->version != (ASN1_INTEGER *)0x4) {
      ERR_put_error(0x2f,0x94,0x85,"ts_asn1.c",0x139);
      return (ASN1_VALUE *)0x0;
    }
    psVar4 = pPVar5->md_algs;
    local_14[0] = (uchar *)(psVar4->stack).sorted;
    pAVar3 = ASN1_item_d2i((ASN1_VALUE **)0x0,local_14,(psVar4->stack).num,
                           (ASN1_ITEM *)PTR_TS_TST_INFO_it_000eda14);
  }
  else {
    ERR_put_error(0x2f,0x94,0x86,"ts_asn1.c",0x128);
    pAVar3 = (ASN1_VALUE *)0x0;
  }
  return pAVar3;
}

