
int PKCS12_add_friendlyname_uni(PKCS12_SAFEBAG *bag,uchar *name,int namelen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_NID_006a9d88)(&bag->attrib,0x9c,0x1002,name,namelen);
  return (uint)(iVar1 != 0);
}
