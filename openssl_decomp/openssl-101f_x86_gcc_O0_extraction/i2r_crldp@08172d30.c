
undefined4 i2r_crldp(undefined4 param_1,_STACK *param_2,BIO *param_3,int param_4)

{
  int *piVar1;
  ASN1_BIT_STRING *a;
  _STACK *p_Var2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int **ppiVar6;
  GENERAL_NAME *pGVar7;
  int iVar8;
  int *piVar9;
  int in_GS_OFFSET;
  int local_48;
  X509_NAME local_34;
  int local_20;
  
  local_48 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = param_4 + 2;
  for (; iVar5 = sk_num(param_2), local_48 < iVar5; local_48 = local_48 + 1) {
    BIO_puts(param_3,"\n");
    ppiVar6 = (int **)sk_value(param_2,local_48);
    piVar9 = *ppiVar6;
    if (piVar9 != (int *)0x0) {
      if (*piVar9 == 0) {
        BIO_printf(param_3,"%*sFull Name:\n",param_4,&DAT_081ec74a);
        p_Var2 = (_STACK *)piVar9[1];
        for (iVar5 = 0; iVar8 = sk_num(p_Var2), iVar5 < iVar8; iVar5 = iVar5 + 1) {
          BIO_printf(param_3,"%*s",iVar4,&DAT_081ec74a);
          pGVar7 = (GENERAL_NAME *)sk_value(p_Var2,iVar5);
          GENERAL_NAME_print(param_3,pGVar7);
          BIO_puts(param_3,"\n");
        }
      }
      else {
        local_34.entries = (stack_st_X509_NAME_ENTRY *)piVar9[1];
        BIO_printf(param_3,"%*sRelative Name:\n%*s",param_4,&DAT_081ec74a,iVar4,&DAT_081ec74a);
        X509_NAME_print_ex(param_3,&local_34,0,0x82031f);
        BIO_puts(param_3,"\n");
      }
    }
    a = (ASN1_BIT_STRING *)ppiVar6[1];
    if (a != (ASN1_BIT_STRING *)0x0) {
      BIO_printf(param_3,"%*s%s:\n%*s",param_4,&DAT_081ec74a,"Reasons",iVar4,&DAT_081ec74a);
      bVar3 = true;
      piVar9 = (int *)reason_flags;
      do {
        iVar5 = ASN1_BIT_STRING_get_bit(a,*piVar9);
        if (iVar5 != 0) {
          if (!bVar3) {
            BIO_puts(param_3,", ");
          }
          bVar3 = false;
          BIO_puts(param_3,(char *)piVar9[1]);
        }
        piVar1 = piVar9 + 4;
        piVar9 = piVar9 + 3;
      } while (*piVar1 != 0);
      if (bVar3) {
        BIO_puts(param_3,"<EMPTY>\n");
      }
      else {
        BIO_puts(param_3,"\n");
      }
    }
    if (ppiVar6[2] != (int *)0x0) {
      BIO_printf(param_3,"%*sCRL Issuer:\n",param_4,&DAT_081ec74a);
      p_Var2 = (_STACK *)ppiVar6[2];
      for (iVar5 = 0; iVar8 = sk_num(p_Var2), iVar5 < iVar8; iVar5 = iVar5 + 1) {
        BIO_printf(param_3,"%*s",iVar4,&DAT_081ec74a);
        pGVar7 = (GENERAL_NAME *)sk_value(p_Var2,iVar5);
        GENERAL_NAME_print(param_3,pGVar7);
        BIO_puts(param_3,"\n");
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

