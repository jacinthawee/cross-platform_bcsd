
int DIST_POINT_set_dpname(DIST_POINT_NAME *dpn,X509_NAME *iname)

{
  X509_NAME_ENTRY *ne;
  int iVar1;
  uint uVar2;
  int iVar3;
  X509_NAME *pXVar4;
  _STACK *p_Var5;
  
  if ((dpn == (DIST_POINT_NAME *)0x0) || (dpn->type != 1)) {
LAB_000d43a0:
    pXVar4 = (X509_NAME *)0x1;
  }
  else {
    p_Var5 = (_STACK *)(dpn->name).fullname;
    pXVar4 = X509_NAME_dup(iname);
    dpn->dpname = pXVar4;
    if (pXVar4 != (X509_NAME *)0x0) {
      iVar3 = 0;
      do {
        iVar1 = sk_num(p_Var5);
        if (iVar1 <= iVar3) {
          iVar3 = i2d_X509_NAME(dpn->dpname,(uchar **)0x0);
          if (iVar3 < 0) {
            X509_NAME_free(dpn->dpname);
            dpn->dpname = (X509_NAME *)0x0;
            return 0;
          }
          goto LAB_000d43a0;
        }
        ne = (X509_NAME_ENTRY *)sk_value(p_Var5,iVar3);
        uVar2 = count_leading_zeroes(iVar3);
        iVar3 = iVar3 + 1;
        pXVar4 = (X509_NAME *)X509_NAME_add_entry(dpn->dpname,ne,-1,uVar2 >> 5);
      } while (pXVar4 != (X509_NAME *)0x0);
      X509_NAME_free(dpn->dpname);
      dpn->dpname = (X509_NAME *)0x0;
    }
  }
  return (int)pXVar4;
}

