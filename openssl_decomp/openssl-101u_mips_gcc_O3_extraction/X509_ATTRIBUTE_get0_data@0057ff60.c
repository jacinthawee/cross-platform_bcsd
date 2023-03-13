
void * X509_ATTRIBUTE_get0_data(X509_ATTRIBUTE *attr,int idx,int atrtype,void *data)

{
  int iVar1;
  stack_st_ASN1_TYPE *psVar2;
  
  if (attr == (X509_ATTRIBUTE *)0x0) {
    return (void *)0x0;
  }
  if (attr->single == 0) {
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)((attr->value).ptr);
    if (iVar1 <= idx) {
      return (void *)0x0;
    }
    if (attr->single == 0) {
      psVar2 = (stack_st_ASN1_TYPE *)(*(code *)PTR_sk_value_006a6e24)((attr->value).ptr,idx);
    }
    else {
      psVar2 = (attr->value).set;
    }
  }
  else {
    psVar2 = (attr->value).set;
    if ((int)(uint)(psVar2 != (stack_st_ASN1_TYPE *)0x0) <= idx) {
      return (void *)0x0;
    }
  }
  if (psVar2 == (stack_st_ASN1_TYPE *)0x0) {
    return (void *)0x0;
  }
  iVar1 = (*(code *)PTR_ASN1_TYPE_get_006a74b0)(psVar2);
  if (iVar1 != atrtype) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x8b,0x7a,"x509_att.c",0x170);
    return (void *)0x0;
  }
  return (psVar2->stack).data;
}

