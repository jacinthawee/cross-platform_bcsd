
void policies_print(BIO *param_1,X509_STORE_CTX *param_2)

{
  X509_POLICY_TREE *tree;
  int iVar1;
  char *pcVar2;
  _STACK *p_Var3;
  int iVar4;
  X509_POLICY_NODE *pXVar5;
  bool bVar6;
  
  bVar6 = param_1 == (BIO *)0x0;
  if (bVar6) {
    param_1 = BIO_new_fp(stderr,0);
  }
  tree = X509_STORE_CTX_get0_policy_tree(param_2);
  iVar1 = X509_STORE_CTX_get_explicit_policy(param_2);
  pcVar2 = "True";
  if (iVar1 == 0) {
    pcVar2 = "False";
  }
  BIO_printf(param_1,"Require explicit Policy: %s\n",pcVar2);
  p_Var3 = (_STACK *)X509_policy_tree_get0_policies(tree);
  BIO_printf(param_1,"%s Policies:","Authority");
  if (p_Var3 == (_STACK *)0x0) {
    BIO_puts(param_1," <empty>\n");
  }
  else {
    BIO_puts(param_1,"\n");
    iVar1 = 0;
    while( true ) {
      iVar4 = sk_num(p_Var3);
      if (iVar4 <= iVar1) break;
      pXVar5 = (X509_POLICY_NODE *)sk_value(p_Var3,iVar1);
      X509_POLICY_NODE_print(param_1,pXVar5,2);
      iVar1 = iVar1 + 1;
    }
  }
  p_Var3 = (_STACK *)X509_policy_tree_get0_user_policies(tree);
  BIO_printf(param_1,"%s Policies:","User");
  if (p_Var3 == (_STACK *)0x0) {
    BIO_puts(param_1," <empty>\n");
  }
  else {
    BIO_puts(param_1,"\n");
    iVar1 = 0;
    while( true ) {
      iVar4 = sk_num(p_Var3);
      if (iVar4 <= iVar1) break;
      pXVar5 = (X509_POLICY_NODE *)sk_value(p_Var3,iVar1);
      X509_POLICY_NODE_print(param_1,pXVar5,2);
      iVar1 = iVar1 + 1;
    }
  }
  if (!bVar6) {
    return;
  }
  BIO_free(param_1);
  return;
}

