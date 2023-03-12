
int PKCS7_set_attributes(PKCS7_SIGNER_INFO *p7si,stack_st_X509_ATTRIBUTE *sk)

{
  _STACK *p_Var1;
  X509_ATTRIBUTE *pXVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  
  if ((_STACK *)p7si->unauth_attr != (_STACK *)0x0) {
    sk_pop_free((_STACK *)p7si->unauth_attr,X509_ATTRIBUTE_free + 1);
  }
  p_Var1 = sk_dup(&sk->stack);
  p7si->unauth_attr = (stack_st_X509_ATTRIBUTE *)p_Var1;
  if (p_Var1 != (_STACK *)0x0) {
    iVar5 = 0;
    do {
      iVar4 = sk_num(&sk->stack);
      if (iVar4 <= iVar5) {
        return 1;
      }
      p_Var1 = (_STACK *)p7si->unauth_attr;
      pXVar2 = (X509_ATTRIBUTE *)sk_value(&sk->stack,iVar5);
      pXVar2 = X509_ATTRIBUTE_dup(pXVar2);
      pvVar3 = sk_set(p_Var1,iVar5,pXVar2);
      iVar5 = iVar5 + 1;
    } while (pvVar3 != (void *)0x0);
  }
  return 0;
}

