
int PKCS12_verify_mac(PKCS12 *p12,char *pass,int passlen)

{
  undefined *puVar1;
  int iVar2;
  ASN1_OCTET_STRING *pAVar3;
  uint uVar4;
  int local_60;
  undefined auStack_5c [64];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (p12->mac == (PKCS12_MAC_DATA *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7e,0x6c,"p12_mutl.c",0x77);
    uVar4 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p12->authsafes->type);
    if (iVar2 != 0x15) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6b,0x79,"p12_mutl.c",0x4f);
      goto LAB_005aa288;
    }
    iVar2 = PKCS12_gen_mac_part_0(p12,pass,passlen,auStack_5c,&local_60);
    if (iVar2 == 0) goto LAB_005aa288;
    pAVar3 = p12->mac->dinfo->digest;
    if (pAVar3->length == local_60) {
      iVar2 = (*(code *)PTR_CRYPTO_memcmp_006a8128)(auStack_5c,pAVar3->data);
      uVar4 = (uint)(iVar2 == 0);
    }
    else {
      uVar4 = 0;
    }
  }
  while (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005aa288:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7e,0x6d,"p12_mutl.c",0x7b);
    uVar4 = 0;
  }
  return uVar4;
}

