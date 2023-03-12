
int PKCS12_add_localkeyid(PKCS12_SAFEBAG *bag,uchar *name,int namelen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_NID_006a8c6c)(&bag->attrib,0x9d,4,name,namelen);
  return (uint)(iVar1 != 0);
}

