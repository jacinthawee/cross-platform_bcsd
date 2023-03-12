
ASN1_VALUE * PKCS7_to_TS_TST_INFO(PKCS7 *param_1)

{
  pkcs7_st *ppVar1;
  PKCS7_SIGNED *pPVar2;
  stack_st_X509_ALGOR *psVar3;
  int iVar4;
  long lVar5;
  ASN1_VALUE *pAVar6;
  int in_GS_OFFSET;
  int line;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = OBJ_obj2nid(param_1->type);
  if (iVar4 == 0x16) {
    lVar5 = PKCS7_ctrl(param_1,2,0,(char *)0x0);
    if (lVar5 == 0) {
      ppVar1 = ((param_1->d).sign)->contents;
      iVar4 = OBJ_obj2nid(ppVar1->type);
      if (iVar4 == 0xcf) {
        pPVar2 = (ppVar1->d).sign;
        if (pPVar2->version == (ASN1_INTEGER *)0x4) {
          psVar3 = pPVar2->md_algs;
          local_14 = (uchar *)(psVar3->stack).sorted;
          pAVar6 = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_14,(psVar3->stack).num,
                                 (ASN1_ITEM *)TS_TST_INFO_it);
          goto LAB_0819a122;
        }
        line = 0x139;
        iVar4 = 0x85;
      }
      else {
        line = 0x131;
        iVar4 = 0x84;
      }
    }
    else {
      line = 0x128;
      iVar4 = 0x86;
    }
  }
  else {
    line = 0x121;
    iVar4 = 0x84;
  }
  ERR_put_error(0x2f,0x94,iVar4,"ts_asn1.c",line);
  pAVar6 = (ASN1_VALUE *)0x0;
LAB_0819a122:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

