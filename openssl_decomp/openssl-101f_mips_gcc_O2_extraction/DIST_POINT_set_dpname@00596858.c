
int DIST_POINT_set_dpname(DIST_POINT_NAME *dpn,X509_NAME *iname)

{
  bool bVar1;
  X509_NAME *pXVar2;
  X509_NAME_ENTRY *ne;
  int iVar3;
  int iVar4;
  GENERAL_NAMES *pGVar5;
  
  if ((dpn != (DIST_POINT_NAME *)0x0) && (dpn->type == 1)) {
    pGVar5 = (dpn->name).fullname;
    pXVar2 = (X509_NAME *)(*(code *)PTR_X509_NAME_dup_006a823c)(iname);
    dpn->dpname = pXVar2;
    if (pXVar2 == (X509_NAME *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar4 = 0;
      do {
        iVar3 = (*(code *)PTR_sk_num_006a7f2c)(pGVar5);
        if (iVar3 <= iVar4) {
          iVar3 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(dpn->dpname,0);
          if (-1 < iVar3) {
            return 1;
          }
          (*(code *)PTR_X509_NAME_free_006a80f8)(dpn->dpname);
          dpn->dpname = (X509_NAME *)0x0;
          return 0;
        }
        ne = (X509_NAME_ENTRY *)(*(code *)PTR_sk_value_006a7f24)(pGVar5,iVar4);
        bVar1 = iVar4 == 0;
        iVar4 = iVar4 + 1;
        iVar3 = X509_NAME_add_entry(dpn->dpname,ne,-1,(uint)bVar1);
      } while (iVar3 != 0);
      (*(code *)PTR_X509_NAME_free_006a80f8)(dpn->dpname);
      dpn->dpname = (X509_NAME *)0x0;
    }
    return iVar3;
  }
  return 1;
}

