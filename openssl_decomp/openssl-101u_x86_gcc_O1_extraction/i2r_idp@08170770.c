
undefined4 i2r_idp(undefined4 param_1,int **param_2,BIO *param_3,int param_4)

{
  int *piVar1;
  ASN1_BIT_STRING *a;
  _STACK *p_Var2;
  bool bVar3;
  int iVar4;
  GENERAL_NAME *gen;
  int iVar5;
  int *piVar6;
  int in_GS_OFFSET;
  X509_NAME local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  piVar6 = *param_2;
  if (piVar6 != (int *)0x0) {
    if (*piVar6 == 0) {
      BIO_printf(param_3,"%*sFull Name:\n",param_4,&DAT_081eca46);
      p_Var2 = (_STACK *)piVar6[1];
      for (iVar4 = 0; iVar5 = sk_num(p_Var2), iVar4 < iVar5; iVar4 = iVar4 + 1) {
        BIO_printf(param_3,"%*s",param_4 + 2,&DAT_081eca46);
        gen = (GENERAL_NAME *)sk_value(p_Var2,iVar4);
        GENERAL_NAME_print(param_3,gen);
        BIO_puts(param_3,"\n");
      }
    }
    else {
      local_34.entries = (stack_st_X509_NAME_ENTRY *)piVar6[1];
      BIO_printf(param_3,"%*sRelative Name:\n%*s",param_4,&DAT_081eca46,param_4 + 2,&DAT_081eca46);
      X509_NAME_print_ex(param_3,&local_34,0,0x82031f);
      BIO_puts(param_3,"\n");
    }
  }
  if (0 < (int)param_2[1]) {
    BIO_printf(param_3,"%*sOnly User Certificates\n",param_4,&DAT_081eca46);
  }
  if (0 < (int)param_2[2]) {
    BIO_printf(param_3,"%*sOnly CA Certificates\n",param_4,&DAT_081eca46);
  }
  if (0 < (int)param_2[4]) {
    BIO_printf(param_3,"%*sIndirect CRL\n",param_4,&DAT_081eca46);
  }
  a = (ASN1_BIT_STRING *)param_2[3];
  if (a != (ASN1_BIT_STRING *)0x0) {
    bVar3 = true;
    BIO_printf(param_3,"%*s%s:\n%*s",param_4,&DAT_081eca46,"Only Some Reasons",param_4 + 2,
               &DAT_081eca46);
    piVar6 = (int *)reason_flags;
    do {
      iVar4 = ASN1_BIT_STRING_get_bit(a,*piVar6);
      if (iVar4 != 0) {
        if (!bVar3) {
          BIO_puts(param_3,", ");
        }
        bVar3 = false;
        BIO_puts(param_3,(char *)piVar6[1]);
      }
      piVar1 = piVar6 + 4;
      piVar6 = piVar6 + 3;
    } while (*piVar1 != 0);
    if (bVar3) {
      BIO_puts(param_3,"<EMPTY>\n");
    }
    else {
      BIO_puts(param_3,"\n");
    }
  }
  if (0 < (int)param_2[5]) {
    BIO_printf(param_3,"%*sOnly Attribute Certificates\n",param_4,&DAT_081eca46);
  }
  if ((((*param_2 == (int *)0x0) && ((int)param_2[1] < 1)) && ((int)param_2[2] < 1)) &&
     ((((int)param_2[4] < 1 && (param_2[3] == (int *)0x0)) && ((int)param_2[5] < 1)))) {
    BIO_printf(param_3,"%*s<EMPTY>\n",param_4,&DAT_081eca46);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

