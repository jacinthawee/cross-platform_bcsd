
char def_crl_lookup(int *param_1,undefined4 *param_2,ASN1_INTEGER *param_3,X509_NAME *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ASN1_INTEGER **ppAVar4;
  _STACK *p_Var5;
  int iVar6;
  int *piVar7;
  int in_GS_OFFSET;
  X509_NAME *local_4c;
  ASN1_INTEGER *local_38 [6];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_38[0] = param_3;
  iVar2 = sk_is_sorted(*(_STACK **)(*param_1 + 0x14));
  if (iVar2 == 0) {
    CRYPTO_lock(0,9,(char *)0x6,(int)"x_crl.c");
    iVar2 = *param_1;
    sk_sort(*(_STACK **)(iVar2 + 0x14));
    CRYPTO_lock(iVar2,10,(char *)0x6,(int)"x_crl.c");
  }
  iVar2 = sk_find(*(_STACK **)(*param_1 + 0x14),local_38);
  if (-1 < iVar2) {
    for (; iVar3 = sk_num(*(_STACK **)(*param_1 + 0x14)), iVar2 < iVar3; iVar2 = iVar2 + 1) {
      ppAVar4 = (ASN1_INTEGER **)sk_value(*(_STACK **)(*param_1 + 0x14),iVar2);
      iVar3 = ASN1_INTEGER_cmp(*ppAVar4,param_3);
      if (iVar3 != 0) break;
      p_Var5 = (_STACK *)ppAVar4[3];
      if (p_Var5 == (_STACK *)0x0) {
        if ((param_4 == (X509_NAME *)0x0) ||
           (iVar3 = X509_NAME_cmp(param_4,*(X509_NAME **)(*param_1 + 8)), iVar3 == 0)) {
LAB_08140420:
          if (param_2 != (undefined4 *)0x0) {
            *param_2 = ppAVar4;
          }
          cVar1 = (ppAVar4[4] == (ASN1_INTEGER *)&DAT_00000008) + '\x01';
          goto LAB_08140472;
        }
      }
      else {
        local_4c = param_4;
        if (param_4 == (X509_NAME *)0x0) {
          local_4c = *(X509_NAME **)(*param_1 + 8);
        }
        for (iVar3 = 0; iVar6 = sk_num(p_Var5), iVar3 < iVar6; iVar3 = iVar3 + 1) {
          piVar7 = (int *)sk_value((_STACK *)ppAVar4[3],iVar3);
          if ((*piVar7 == 4) && (iVar6 = X509_NAME_cmp(local_4c,(X509_NAME *)piVar7[1]), iVar6 == 0)
             ) goto LAB_08140420;
          p_Var5 = (_STACK *)ppAVar4[3];
        }
      }
    }
  }
  cVar1 = '\0';
LAB_08140472:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return cVar1;
}

