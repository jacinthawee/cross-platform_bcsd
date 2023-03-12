
int PKCS7_set_signed_attributes(PKCS7_SIGNER_INFO *p7si,stack_st_X509_ATTRIBUTE *sk)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (p7si->auth_attr != (stack_st_X509_ATTRIBUTE *)0x0) {
    (*(code *)PTR_sk_pop_free_006a7058)(p7si->auth_attr,PTR_X509_ATTRIBUTE_free_006a8ae4);
  }
  psVar1 = (stack_st_X509_ATTRIBUTE *)(*(code *)PTR_sk_dup_006a7f54)(sk);
  p7si->auth_attr = psVar1;
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    iVar4 = 0;
    do {
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(sk);
      if (iVar3 <= iVar4) {
        return 1;
      }
      psVar1 = p7si->auth_attr;
      uVar2 = (*(code *)PTR_sk_value_006a6e24)(sk,iVar4);
      uVar2 = (*(code *)PTR_X509_ATTRIBUTE_dup_006a8f68)(uVar2);
      iVar3 = (*(code *)PTR_sk_set_006a8358)(psVar1,iVar4,uVar2);
      iVar4 = iVar4 + 1;
    } while (iVar3 != 0);
  }
  return 0;
}

