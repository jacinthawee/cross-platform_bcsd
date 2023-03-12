
int i2d_POLICYQUALINFO(POLICYQUALINFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_POLICYQUALINFO_it_000d35fc);
  return iVar1;
}

