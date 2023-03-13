
undefined4 print_attribs(BIO *param_1,_STACK *param_2,char *param_3)

{
  int iVar1;
  char **ppcVar2;
  int iVar3;
  ASN1_OBJECT **ppAVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if (param_2 == (_STACK *)0x0) {
    BIO_printf(param_1,"%s: <No Attributes>\n",param_3);
  }
  else {
    iVar1 = sk_num(param_2);
    if (iVar1 == 0) {
      BIO_printf(param_1,"%s: <Empty Attributes>\n",param_3);
      return 1;
    }
    BIO_printf(param_1,"%s\n",param_3);
    for (iVar1 = 0; iVar3 = sk_num(param_2), iVar1 < iVar3; iVar1 = iVar1 + 1) {
      ppAVar4 = (ASN1_OBJECT **)sk_value(param_2,iVar1);
      iVar3 = OBJ_obj2nid(*ppAVar4);
      BIO_printf(param_1,"    ");
      if (iVar3 == 0) {
        i2a_ASN1_OBJECT(param_1,*ppAVar4);
        BIO_printf(param_1,": ");
      }
      else {
        param_3 = OBJ_nid2ln(iVar3);
        BIO_printf(param_1,"%s: ",param_3);
      }
      iVar3 = sk_num((_STACK *)ppAVar4[2]);
      if (iVar3 == 0) {
        BIO_printf(param_1,"<No Values>\n",param_3);
      }
      else {
        ppcVar2 = (char **)sk_value((_STACK *)ppAVar4[2],0);
        pcVar5 = *ppcVar2;
        if (pcVar5 == &DAT_00000004) {
          iVar3 = *(int *)ppcVar2[1];
          pbVar6 = *(byte **)((int)ppcVar2[1] + 8);
          pbVar7 = pbVar6 + iVar3;
          if (0 < iVar3) {
            do {
              param_3 = (char *)(uint)*pbVar6;
              pbVar6 = pbVar6 + 1;
              BIO_printf(param_1,"%02X ",param_3);
            } while (pbVar6 != pbVar7);
          }
LAB_080813b7:
          BIO_printf(param_1,"\n",param_3);
        }
        else if (pcVar5 == (char *)0x1e) {
          pcVar5 = OPENSSL_uni2asc(*(uchar **)((int)ppcVar2[1] + 8),*(int *)ppcVar2[1]);
          param_3 = pcVar5;
          BIO_printf(param_1,"%s\n",pcVar5);
          CRYPTO_free(pcVar5);
        }
        else {
          if (pcVar5 == (char *)0x3) {
            iVar3 = *(int *)ppcVar2[1];
            pbVar7 = *(byte **)((int)ppcVar2[1] + 8);
            if (0 < iVar3) {
              pbVar6 = pbVar7 + iVar3;
              do {
                param_3 = (char *)(uint)*pbVar7;
                pbVar7 = pbVar7 + 1;
                BIO_printf(param_1,"%02X ",param_3);
              } while (pbVar6 != pbVar7);
            }
            goto LAB_080813b7;
          }
          BIO_printf(param_1,"<Unsupported tag %d>\n",pcVar5);
          param_3 = pcVar5;
        }
      }
    }
  }
  return 1;
}

