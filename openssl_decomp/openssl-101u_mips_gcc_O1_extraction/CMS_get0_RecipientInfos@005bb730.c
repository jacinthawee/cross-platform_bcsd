
stack_st_CMS_RecipientInfo * CMS_get0_RecipientInfos(CMS_ContentInfo *cms)

{
  int iVar1;
  stack_st_CMS_RecipientInfo *psVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar1 == 0x17) {
    if (*(int *)(cms + 4) == 0) {
      psVar2 = (stack_st_CMS_RecipientInfo *)0x0;
    }
    else {
      psVar2 = *(stack_st_CMS_RecipientInfo **)(*(int *)(cms + 4) + 8);
    }
    return psVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x83,0x6b,"cms_env.c",0x4f);
  return (stack_st_CMS_RecipientInfo *)0x0;
}

