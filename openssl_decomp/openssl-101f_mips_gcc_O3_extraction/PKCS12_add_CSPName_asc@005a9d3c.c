
int PKCS12_add_CSPName_asc(PKCS12_SAFEBAG *bag,char *name,int namelen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_NID_006a9d88)(&bag->attrib,0x1a1,0x1001,name,namelen);
  return (uint)(iVar1 != 0);
}
