
undefined4 i2r_idp(undefined4 param_1,int **param_2,BIO *param_3,int param_4)

{
  bool bVar1;
  GENERAL_NAME *gen;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int *piVar5;
  _STACK *p_Var6;
  ASN1_BIT_STRING *a;
  X509_NAME local_34;
  
  piVar5 = *param_2;
  if (piVar5 != (int *)0x0) {
    iVar3 = *piVar5;
    if (iVar3 == 0) {
      BIO_printf(param_3,"%*sFull Name:\n",param_4,"");
      p_Var6 = (_STACK *)piVar5[1];
      for (; iVar2 = sk_num(p_Var6), iVar3 < iVar2; iVar3 = iVar3 + 1) {
        BIO_printf(param_3,"%*s",param_4 + 2,"");
        gen = (GENERAL_NAME *)sk_value(p_Var6,iVar3);
        GENERAL_NAME_print(param_3,gen);
        BIO_puts(param_3,"\n");
      }
    }
    else {
      local_34.entries = (stack_st_X509_NAME_ENTRY *)piVar5[1];
      BIO_printf(param_3,"%*sRelative Name:\n%*s",param_4,"",param_4 + 2,"");
      X509_NAME_print_ex(param_3,&local_34,0,0x82031f);
      BIO_puts(param_3,"\n");
    }
  }
  if (0 < (int)param_2[1]) {
    BIO_printf(param_3,"%*sOnly User Certificates\n",param_4,"");
  }
  if (0 < (int)param_2[2]) {
    BIO_printf(param_3,"%*sOnly CA Certificates\n",param_4,"");
  }
  if (0 < (int)param_2[4]) {
    BIO_printf(param_3,"%*sIndirect CRL\n",param_4,"");
  }
  puVar4 = PTR_DAT_000d39fc;
  a = (ASN1_BIT_STRING *)param_2[3];
  if (a != (ASN1_BIT_STRING *)0x0) {
    BIO_printf(param_3,"%*s%s:\n%*s",param_4,"","Only Some Reasons",param_4 + 2,"");
    bVar1 = true;
    do {
      iVar3 = ASN1_BIT_STRING_get_bit(a,*(int *)(puVar4 + -0xc));
      if (iVar3 != 0) {
        if (!bVar1) {
          BIO_puts(param_3,", ");
        }
        BIO_puts(param_3,*(char **)(puVar4 + -8));
        bVar1 = false;
      }
      piVar5 = (int *)(puVar4 + 4);
      puVar4 = puVar4 + 0xc;
    } while (*piVar5 != 0);
    if (bVar1) {
      BIO_puts(param_3,"<EMPTY>\n");
    }
    else {
      BIO_puts(param_3,"\n");
    }
  }
  if (0 < (int)param_2[5]) {
    BIO_printf(param_3,"%*sOnly Attribute Certificates\n",param_4,"");
  }
  if ((((*param_2 == (int *)0x0) && ((int)param_2[1] < 1)) && ((int)param_2[2] < 1)) &&
     ((((int)param_2[4] < 1 && (param_2[3] == (int *)0x0)) && ((int)param_2[5] < 1)))) {
    BIO_printf(param_3,"%*s<EMPTY>\n",param_4,"");
  }
  return 1;
}

