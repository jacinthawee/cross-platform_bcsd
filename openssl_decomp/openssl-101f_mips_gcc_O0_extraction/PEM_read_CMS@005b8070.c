
CMS_ContentInfo * PEM_read_CMS(FILE *fp,CMS_ContentInfo **x,undefined1 *cb,void *u)

{
  CMS_ContentInfo *pCVar1;
  
  pCVar1 = (CMS_ContentInfo *)
           (*(code *)PTR_PEM_ASN1_read_006a94c8)
                     (PTR_d2i_CMS_ContentInfo_006aa410,&DAT_00671e58,fp,x,cb,u,&_gp);
  return pCVar1;
}

