
undefined4 TS_RESP_CTX_set_accuracy(int param_1,int param_2,int param_3,int param_4)

{
  ASN1_INTEGER *pAVar1;
  int iVar2;
  
  ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x18) = 0;
  ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (param_2 == 0) {
    if (param_3 == 0) goto LAB_081943f3;
LAB_081944c0:
    pAVar1 = ASN1_INTEGER_new();
    *(ASN1_INTEGER **)(param_1 + 0x1c) = pAVar1;
    if ((pAVar1 != (ASN1_INTEGER *)0x0) && (iVar2 = ASN1_INTEGER_set(pAVar1,param_3), iVar2 != 0))
    goto LAB_081943f3;
  }
  else {
    pAVar1 = ASN1_INTEGER_new();
    *(ASN1_INTEGER **)(param_1 + 0x18) = pAVar1;
    if (pAVar1 == (ASN1_INTEGER *)0x0) goto LAB_08194433;
    iVar2 = ASN1_INTEGER_set(pAVar1,param_2);
    if (iVar2 == 0) goto LAB_08194430;
    if (param_3 != 0) goto LAB_081944c0;
LAB_081943f3:
    if (param_4 == 0) {
      return 1;
    }
    pAVar1 = ASN1_INTEGER_new();
    *(ASN1_INTEGER **)(param_1 + 0x20) = pAVar1;
    if ((pAVar1 != (ASN1_INTEGER *)0x0) && (iVar2 = ASN1_INTEGER_set(pAVar1,param_4), iVar2 != 0)) {
      return 1;
    }
  }
LAB_08194430:
  pAVar1 = *(ASN1_INTEGER **)(param_1 + 0x18);
LAB_08194433:
  ASN1_INTEGER_free(pAVar1);
  *(undefined4 *)(param_1 + 0x18) = 0;
  ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = 0;
  ERR_put_error(0x2f,0x80,0x41,"ts_rsp_sign.c",0x141);
  return 0;
}

