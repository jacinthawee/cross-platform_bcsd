
int PKCS12_add_CSPName_asc(PKCS12_SAFEBAG *bag,char *name,int namelen)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr_by_NID(&bag->attrib,0x1a1,0x1001,(uchar *)name,namelen);
  return (uint)(psVar1 != (stack_st_X509_ATTRIBUTE *)0x0);
}

