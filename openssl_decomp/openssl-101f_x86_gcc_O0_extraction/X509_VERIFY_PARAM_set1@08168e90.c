
int X509_VERIFY_PARAM_set1(X509_VERIFY_PARAM *to,X509_VERIFY_PARAM *from)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = to->inh_flags;
  to->inh_flags = uVar1 | 1;
  iVar2 = X509_VERIFY_PARAM_inherit(to,from);
  to->inh_flags = uVar1;
  return iVar2;
}

