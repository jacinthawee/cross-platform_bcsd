
undefined4 TS_check_signer_name(GENERAL_NAME *param_1,X509 *param_2)

{
  _STACK *a;
  int iVar1;
  GENERAL_NAME *a_00;
  int iVar2;
  int iVar3;
  int local_1c [2];
  
  local_1c[0] = -1;
  if ((param_1->type != 4) ||
     (iVar1 = X509_NAME_cmp((param_1->d).directoryName,param_2->cert_info->subject), iVar1 != 0)) {
    while( true ) {
      a = (_STACK *)X509_get_ext_d2i(param_2,0x55,(int *)0x0,local_1c);
      if (a == (_STACK *)0x0) {
        return 0;
      }
      iVar1 = 0;
      do {
        iVar3 = iVar1;
        iVar1 = sk_num(a);
        if (iVar1 <= iVar3) goto LAB_000ebe50;
        a_00 = (GENERAL_NAME *)sk_value(a,iVar3);
        iVar2 = GENERAL_NAME_cmp(a_00,param_1);
        iVar1 = iVar3 + 1;
      } while (iVar2 != 0);
      if (-1 < iVar3) break;
LAB_000ebe50:
      GENERAL_NAMES_free((GENERAL_NAMES *)a);
    }
    GENERAL_NAMES_free((GENERAL_NAMES *)a);
  }
  return 1;
}

