
int PEM_write_CMS(FILE *fp,CMS_ContentInfo *x)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_PEM_ASN1_write_006a94d0)
                    (PTR_i2d_CMS_ContentInfo_006aa414,&DAT_00671e78,fp,x,0,0,0,0,0);
  return iVar1;
}

