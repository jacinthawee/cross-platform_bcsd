
int DIST_POINT_set_dpname(DIST_POINT_NAME *dpn,X509_NAME *iname)

{
  _STACK *p_Var1;
  X509_NAME *pXVar2;
  X509_NAME_ENTRY *ne;
  int iVar3;
  int iVar4;
  
  if ((dpn != (DIST_POINT_NAME *)0x0) && (dpn->type == 1)) {
    p_Var1 = (_STACK *)(dpn->name).fullname;
    pXVar2 = X509_NAME_dup(iname);
    dpn->dpname = pXVar2;
    if (pXVar2 == (X509_NAME *)0x0) {
      return 0;
    }
    for (iVar4 = 0; iVar3 = sk_num(p_Var1), iVar4 < iVar3; iVar4 = iVar4 + 1) {
      ne = (X509_NAME_ENTRY *)sk_value(p_Var1,iVar4);
      iVar3 = X509_NAME_add_entry(dpn->dpname,ne,-1,(uint)(iVar4 == 0));
      if (iVar3 == 0) {
        X509_NAME_free(dpn->dpname);
        dpn->dpname = (X509_NAME *)0x0;
        return 0;
      }
    }
    iVar4 = i2d_X509_NAME(dpn->dpname,(uchar **)0x0);
    if (iVar4 < 0) {
      X509_NAME_free(dpn->dpname);
      dpn->dpname = (X509_NAME *)0x0;
      return 0;
    }
  }
  return 1;
}

