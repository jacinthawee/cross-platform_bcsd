
void policies_print(BIO *param_1,X509_STORE_CTX *param_2)

{
  X509_POLICY_TREE *tree;
  int iVar1;
  _STACK *p_Var2;
  int iVar3;
  X509_POLICY_NODE *pXVar4;
  char *pcVar5;
  bool bVar6;
  
  bVar6 = param_1 == (BIO *)0x0;
  if (bVar6) {
    param_1 = BIO_new_fp(stderr,0);
  }
  tree = X509_STORE_CTX_get0_policy_tree(param_2);
  iVar1 = X509_STORE_CTX_get_explicit_policy(param_2);
  pcVar5 = "False";
  if (iVar1 != 0) {
    pcVar5 = "True";
  }
  BIO_printf(param_1,"Require explicit Policy: %s\n",pcVar5);
  p_Var2 = (_STACK *)X509_policy_tree_get0_policies(tree);
  BIO_printf(param_1,"%s Policies:","Authority");
  if (p_Var2 == (_STACK *)0x0) {
    BIO_puts(param_1," <empty>\n");
  }
  else {
    BIO_puts(param_1,"\n");
    iVar1 = 0;
    while( true ) {
      iVar3 = sk_num(p_Var2);
      if (iVar3 <= iVar1) break;
      pXVar4 = (X509_POLICY_NODE *)sk_value(p_Var2,iVar1);
      X509_POLICY_NODE_print(param_1,pXVar4,2);
      iVar1 = iVar1 + 1;
    }
  }
  p_Var2 = (_STACK *)X509_policy_tree_get0_user_policies(tree);
  BIO_printf(param_1,"%s Policies:",&DAT_0013336c);
  if (p_Var2 == (_STACK *)0x0) {
    BIO_puts(param_1," <empty>\n");
  }
  else {
    BIO_puts(param_1,"\n");
    iVar1 = 0;
    while( true ) {
      iVar3 = sk_num(p_Var2);
      if (iVar3 <= iVar1) break;
      pXVar4 = (X509_POLICY_NODE *)sk_value(p_Var2,iVar1);
      X509_POLICY_NODE_print(param_1,pXVar4,2);
      iVar1 = iVar1 + 1;
    }
  }
  if (!bVar6) {
    return;
  }
  BIO_free(param_1);
  return;
}

