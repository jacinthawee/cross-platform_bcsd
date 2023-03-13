
uint __regparm3 TS_check_signer_name(GENERAL_NAME *param_1,X509 *param_2)

{
  _STACK *a;
  uint uVar1;
  int iVar2;
  GENERAL_NAME *a_00;
  uint uVar3;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = -1;
  if (param_1->type == 4) {
    iVar2 = X509_NAME_cmp((param_1->d).directoryName,param_2->cert_info->subject);
    uVar1 = 1;
    if (iVar2 == 0) goto LAB_08195c6a;
  }
  a = (_STACK *)X509_get_ext_d2i(param_2,0x55,(int *)0x0,&local_24);
  uVar1 = 0;
  while (a != (_STACK *)0x0) {
    uVar1 = 0;
    do {
      uVar3 = uVar1;
      iVar2 = sk_num(a);
      if (iVar2 <= (int)uVar3) {
        uVar1 = 0;
        goto LAB_08195c44;
      }
      a_00 = (GENERAL_NAME *)sk_value(a,uVar3);
      iVar2 = GENERAL_NAME_cmp(a_00,param_1);
      uVar1 = uVar3 + 1;
    } while (iVar2 != 0);
    uVar1 = ~uVar3 >> 0x1f;
    if (-1 < (int)uVar3) {
      GENERAL_NAMES_free((GENERAL_NAMES *)a);
      break;
    }
LAB_08195c44:
    GENERAL_NAMES_free((GENERAL_NAMES *)a);
    a = (_STACK *)X509_get_ext_d2i(param_2,0x55,(int *)0x0,&local_24);
  }
LAB_08195c6a:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

