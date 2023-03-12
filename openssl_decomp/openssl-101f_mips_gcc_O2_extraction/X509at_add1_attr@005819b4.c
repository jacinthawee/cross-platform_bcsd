
stack_st_X509_ATTRIBUTE * X509at_add1_attr(stack_st_X509_ATTRIBUTE **x,X509_ATTRIBUTE *attr)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  stack_st_X509_ATTRIBUTE *psVar5;
  
  if (x == (stack_st_X509_ATTRIBUTE **)0x0) {
    uVar4 = 0x43;
    uVar3 = 0x81;
  }
  else {
    psVar5 = *x;
    if ((psVar5 != (stack_st_X509_ATTRIBUTE *)0x0) ||
       (psVar5 = (stack_st_X509_ATTRIBUTE *)(*(code *)PTR_sk_new_null_006a80a4)(),
       psVar5 != (stack_st_X509_ATTRIBUTE *)0x0)) {
      iVar1 = (*(code *)PTR_X509_ATTRIBUTE_dup_006aa084)(attr);
      if (iVar1 != 0) {
        iVar2 = (*(code *)PTR_sk_push_006a80a8)(psVar5,iVar1);
        if (iVar2 != 0) {
          if (*x != (stack_st_X509_ATTRIBUTE *)0x0) {
            return psVar5;
          }
          *x = psVar5;
          return psVar5;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x87,0x41,"x509_att.c",0x95);
        (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(iVar1);
      }
      (*(code *)PTR_sk_free_006a7f80)(psVar5);
      return (stack_st_X509_ATTRIBUTE *)0x0;
    }
    uVar4 = 0x41;
    uVar3 = 0x95;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x87,uVar4,"x509_att.c",uVar3);
  return (stack_st_X509_ATTRIBUTE *)0x0;
}

