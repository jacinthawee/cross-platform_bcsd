
undefined4 print_attribs(BIO *param_1,_STACK *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  ASN1_OBJECT **ppAVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  if (param_2 == (_STACK *)0x0) {
    BIO_printf(param_1,"%s: <No Attributes>\n");
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
        iVar3 = sk_num((_STACK *)ppAVar4[2]);
        if (iVar3 == 0) goto LAB_000378c0;
LAB_0003784a:
        piVar2 = (int *)sk_value((_STACK *)ppAVar4[2],0);
        iVar3 = *piVar2;
        if (iVar3 == 4) {
          iVar3 = *(int *)piVar2[1];
          pbVar6 = (byte *)((int *)piVar2[1])[2];
          if (0 < iVar3) {
            pbVar8 = pbVar6;
            do {
              pbVar7 = pbVar8 + 1;
              BIO_printf(param_1,"%02X ",(uint)*pbVar8);
              pbVar8 = pbVar7;
            } while (pbVar7 != pbVar6 + iVar3);
          }
LAB_00037908:
          BIO_printf(param_1,"\n");
        }
        else if (iVar3 == 0x1e) {
          pcVar5 = OPENSSL_uni2asc((uchar *)((int *)piVar2[1])[2],*(int *)piVar2[1]);
          BIO_printf(param_1,"%s\n",pcVar5);
          CRYPTO_free(pcVar5);
        }
        else if (iVar3 == 3) {
          iVar3 = *(int *)piVar2[1];
          pbVar6 = (byte *)((int *)piVar2[1])[2];
          if (iVar3 < 1) goto LAB_00037908;
          pbVar8 = pbVar6;
          do {
            pbVar7 = pbVar8 + 1;
            BIO_printf(param_1,"%02X ",(uint)*pbVar8);
            pbVar8 = pbVar7;
          } while (pbVar7 != pbVar6 + iVar3);
          BIO_printf(param_1,"\n");
        }
        else {
          BIO_printf(param_1,"<Unsupported tag %d>\n");
        }
      }
      else {
        pcVar5 = OBJ_nid2ln(iVar3);
        BIO_printf(param_1,"%s: ",pcVar5);
        iVar3 = sk_num((_STACK *)ppAVar4[2]);
        if (iVar3 != 0) goto LAB_0003784a;
LAB_000378c0:
        BIO_printf(param_1,"<No Values>\n");
      }
    }
  }
  return 1;
}

