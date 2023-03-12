
undefined4 __regparm3 set_reasons(ASN1_BIT_STRING **param_1,char *param_2)

{
  int *piVar1;
  char *__s2;
  _STACK *st;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  ASN1_BIT_STRING *local_24;
  
  st = (_STACK *)X509V3_parse_list(param_2);
  if (st == (_STACK *)0x0) {
    return 0;
  }
  iVar6 = 0;
  if (*param_1 != (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  do {
    iVar2 = sk_num(st);
    if (iVar2 <= iVar6) {
      uVar4 = 1;
LAB_0817259a:
      sk_pop_free(st,X509V3_conf_free);
      return uVar4;
    }
    pvVar3 = sk_value(st,iVar6);
    __s2 = *(char **)((int)pvVar3 + 4);
    local_24 = *param_1;
    if (local_24 == (ASN1_BIT_STRING *)0x0) {
      local_24 = ASN1_BIT_STRING_new();
      *param_1 = local_24;
      if (local_24 != (ASN1_BIT_STRING *)0x0) goto LAB_08172550;
LAB_08172598:
      uVar4 = 0;
      goto LAB_0817259a;
    }
LAB_08172550:
    piVar5 = (int *)reason_flags;
    while (iVar2 = strcmp((char *)piVar5[2],__s2), iVar2 != 0) {
      piVar1 = piVar5 + 4;
      piVar5 = piVar5 + 3;
      if (*piVar1 == 0) goto LAB_08172598;
    }
    iVar2 = ASN1_BIT_STRING_set_bit(local_24,*piVar5,1);
    if ((iVar2 == 0) || (piVar5[1] == 0)) goto LAB_08172598;
    iVar6 = iVar6 + 1;
  } while( true );
}

