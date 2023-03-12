
X509_OBJECT * X509_OBJECT_retrieve_by_subject(stack_st_X509_OBJECT *h,int type,X509_NAME *name)

{
  int iVar1;
  X509_OBJECT *pXVar2;
  
  iVar1 = x509_object_idx_cnt_constprop_1();
  if (iVar1 != -1) {
                    /* WARNING: Could not recover jumptable at 0x00583e50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar2 = (X509_OBJECT *)(*(code *)PTR_sk_value_006a7f24)(h,iVar1);
    return pXVar2;
  }
  return (X509_OBJECT *)0x0;
}

