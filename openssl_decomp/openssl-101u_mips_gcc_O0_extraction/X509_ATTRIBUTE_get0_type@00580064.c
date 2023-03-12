
ASN1_TYPE * X509_ATTRIBUTE_get0_type(X509_ATTRIBUTE *attr,int idx)

{
  int iVar1;
  ASN1_TYPE *pAVar2;
  
  if (attr != (X509_ATTRIBUTE *)0x0) {
    if (attr->single == 0) {
      iVar1 = (*(code *)PTR_sk_num_006a6e2c)((attr->value).ptr);
      if (idx < iVar1) {
        if (attr->single == 0) {
                    /* WARNING: Could not recover jumptable at 0x005800f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          pAVar2 = (ASN1_TYPE *)(*(code *)PTR_sk_value_006a6e24)((attr->value).ptr,idx);
          return pAVar2;
        }
        pAVar2 = (ASN1_TYPE *)(attr->value).ptr;
      }
      else {
        pAVar2 = (ASN1_TYPE *)0x0;
      }
      return pAVar2;
    }
    if (idx < (int)(uint)((ASN1_TYPE *)(attr->value).ptr != (ASN1_TYPE *)0x0)) {
      return (ASN1_TYPE *)(attr->value).ptr;
    }
  }
  return (ASN1_TYPE *)0x0;
}

