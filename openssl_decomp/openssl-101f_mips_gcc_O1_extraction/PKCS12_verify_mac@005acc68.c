
int PKCS12_verify_mac(PKCS12 *p12,char *pass,int passlen)

{
  undefined *puVar1;
  int iVar2;
  ASN1_OCTET_STRING *pAVar3;
  uint uVar4;
  int local_60;
  undefined auStack_5c [64];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (p12->mac == (PKCS12_MAC_DATA *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7e,0x6c,"p12_mutl.c",0x76);
    uVar4 = 0;
  }
  else {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p12->authsafes->type);
    if (iVar2 != 0x15) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6b,0x79,"p12_mutl.c",0x4e);
      goto LAB_005acd80;
    }
    iVar2 = PKCS12_gen_mac_part_0(p12,pass,passlen,auStack_5c,&local_60);
    if (iVar2 == 0) goto LAB_005acd80;
    pAVar3 = p12->mac->dinfo->digest;
    if (pAVar3->length == local_60) {
      iVar2 = (*(code *)PTR_memcmp_006aabd8)(auStack_5c,pAVar3->data);
      uVar4 = (uint)(iVar2 == 0);
    }
    else {
      uVar4 = 0;
    }
  }
  while (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005acd80:
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7e,0x6d,"p12_mutl.c",0x7a);
    uVar4 = 0;
  }
  return uVar4;
}

