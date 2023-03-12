
int CMS_add_simple_smimecap(stack_st_X509_ALGOR **algs,int algnid,int keysize)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  stack_st_X509_ALGOR *psVar4;
  undefined4 uVar5;
  
  if (keysize < 1) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = 0;
    uVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(algnid);
    uVar5 = 0xffffffff;
  }
  else {
    iVar1 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar1,keysize);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
    if (iVar2 == 0) {
      (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar1);
      return 0;
    }
    uVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(algnid);
    uVar5 = 2;
  }
  (*(code *)PTR_X509_ALGOR_set0_006a9e04)(iVar2,uVar3,uVar5,iVar1);
  psVar4 = *algs;
  if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
    psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a80a4)();
    *algs = psVar4;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005bceac;
  }
  iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar4,iVar2);
  if (iVar1 != 0) {
    return 1;
  }
LAB_005bceac:
  (*(code *)PTR_X509_ALGOR_free_006a8f94)(iVar2);
  return 0;
}

