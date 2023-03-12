
undefined4 i2r_crldp(undefined4 param_1,_STACK *param_2,BIO *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int **ppiVar3;
  GENERAL_NAME *pGVar4;
  int iVar5;
  ASN1_BIT_STRING *a;
  int *piVar6;
  _STACK *p_Var7;
  int iVar8;
  undefined *puVar9;
  X509_NAME local_3c;
  
  iVar2 = sk_num(param_2);
  iVar8 = 0;
  if (0 < iVar2) {
    do {
      BIO_puts(param_3,"\n");
      ppiVar3 = (int **)sk_value(param_2,iVar8);
      piVar6 = *ppiVar3;
      if (piVar6 != (int *)0x0) {
        iVar2 = *piVar6;
        if (iVar2 == 0) {
          BIO_printf(param_3,"%*sFull Name:\n",param_4,"");
          p_Var7 = (_STACK *)piVar6[1];
          for (; iVar5 = sk_num(p_Var7), iVar2 < iVar5; iVar2 = iVar2 + 1) {
            BIO_printf(param_3,"%*s",param_4 + 2,"");
            pGVar4 = (GENERAL_NAME *)sk_value(p_Var7,iVar2);
            GENERAL_NAME_print(param_3,pGVar4);
            BIO_puts(param_3,"\n");
          }
        }
        else {
          local_3c.entries = (stack_st_X509_NAME_ENTRY *)piVar6[1];
          BIO_printf(param_3,"%*sRelative Name:\n%*s",param_4,"",param_4 + 2,"");
          X509_NAME_print_ex(param_3,&local_3c,0,0x82031f);
          BIO_puts(param_3,"\n");
        }
      }
      a = (ASN1_BIT_STRING *)ppiVar3[1];
      if (a != (ASN1_BIT_STRING *)0x0) {
        BIO_printf(param_3,"%*s%s:\n%*s",param_4,"","Reasons",param_4 + 2,"");
        bVar1 = true;
        puVar9 = PTR_DAT_000d5e70;
        do {
          iVar2 = ASN1_BIT_STRING_get_bit(a,*(int *)(puVar9 + -0xc));
          if (iVar2 != 0) {
            if (!bVar1) {
              BIO_puts(param_3,", ");
            }
            BIO_puts(param_3,*(char **)(puVar9 + -8));
            bVar1 = false;
          }
          piVar6 = (int *)(puVar9 + 4);
          puVar9 = puVar9 + 0xc;
        } while (*piVar6 != 0);
        if (bVar1) {
          BIO_puts(param_3,"<EMPTY>\n");
        }
        else {
          BIO_puts(param_3,"\n");
        }
      }
      if (ppiVar3[2] != (int *)0x0) {
        BIO_printf(param_3,"%*sCRL Issuer:\n",param_4,"");
        p_Var7 = (_STACK *)ppiVar3[2];
        for (iVar2 = 0; iVar5 = sk_num(p_Var7), iVar2 < iVar5; iVar2 = iVar2 + 1) {
          BIO_printf(param_3,"%*s",param_4 + 2,"");
          pGVar4 = (GENERAL_NAME *)sk_value(p_Var7,iVar2);
          GENERAL_NAME_print(param_3,pGVar4);
          BIO_puts(param_3,"\n");
        }
      }
      iVar8 = iVar8 + 1;
      iVar2 = sk_num(param_2);
    } while (iVar8 < iVar2);
  }
  return 1;
}

