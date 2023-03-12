
stack_st_CMS_SignerInfo * CMS_get0_SignerInfos(CMS_ContentInfo *cms)

{
  int iVar1;
  stack_st_CMS_SignerInfo *psVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
  if (iVar1 == 0x16) {
    if (*(int *)(cms + 4) == 0) {
      psVar2 = (stack_st_CMS_SignerInfo *)0x0;
    }
    else {
      psVar2 = *(stack_st_CMS_SignerInfo **)(*(int *)(cms + 4) + 0x14);
    }
    return psVar2;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  return (stack_st_CMS_SignerInfo *)0x0;
}

