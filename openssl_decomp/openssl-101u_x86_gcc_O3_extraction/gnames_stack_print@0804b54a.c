
void __regparm3 gnames_stack_print(BIO *param_1,_STACK *param_2)

{
  int iVar1;
  _STACK *p_Var2;
  int iVar3;
  GENERAL_NAME *gen;
  int iVar4;
  
  iVar4 = 0;
  while( true ) {
    iVar1 = sk_num(param_2);
    if (iVar1 <= iVar4) break;
    p_Var2 = (_STACK *)sk_value(param_2,iVar4);
    iVar1 = 0;
    while( true ) {
      iVar3 = sk_num(p_Var2);
      if (iVar3 <= iVar1) break;
      gen = (GENERAL_NAME *)sk_value(p_Var2,iVar1);
      BIO_puts(param_1,"    ");
      GENERAL_NAME_print(param_1,gen);
      BIO_puts(param_1,"\n");
      iVar1 = iVar1 + 1;
    }
    iVar4 = iVar4 + 1;
  }
  return;
}

